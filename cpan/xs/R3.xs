/*
 * Marpa::R3 is Copyright (C) 2016, Jeffrey Kegler.
 *
 * This module is free software; you can redistribute it and/or modify it
 * under the same terms as Perl 5.10.1. For more details, see the full text
 * of the licenses in the directory LICENSES.
 *
 * This program is distributed in the hope that it will be
 * useful, but it is provided “as is” and without any express
 * or implied warranties. For details, see the full text of
 * of the licenses in the directory LICENSES.
 */

#include "marpa_xs.h"

#define PERL_NO_GET_CONTEXT
#include <EXTERN.h>
#include <perl.h>
#include <XSUB.h>
#include "ppport.h"

#undef IS_PERL_UNDEF
#define IS_PERL_UNDEF(x) (SvTYPE(x) == SVt_NULL)

#undef STRINGIFY_ARG
#undef STRINGIFY
#undef STRLOC
#define STRINGIFY_ARG(contents)       #contents
#define STRINGIFY(macro_or_string)        STRINGIFY_ARG (macro_or_string)
#define STRLOC        __FILE__ ":" STRINGIFY (__LINE__)

#undef MAX
#define MAX(a, b) ((a) > (b) ? (a) : (b))

/* utf8_to_uvchr is deprecated in 5.16, but
 * utf8_to_uvchr_buf is not available before 5.16
 * If I need to get fancier, I should look at Dumper.xs
 * in Data::Dumper
 */
#if PERL_VERSION <= 15 && ! defined(utf8_to_uvchr_buf)
#define utf8_to_uvchr_buf(s, send, p_length) (utf8_to_uvchr(s, p_length))
#endif

typedef SV* SVREF;

#undef Dim
#define Dim(x) (sizeof(x)/sizeof(*x))

typedef UV Marpa_Op;

struct op_data_s { const char *name; Marpa_Op op; };

#include "marpa_slifop.h"

static const char*
marpa_slif_op_name (Marpa_Op op_id)
{
  if (op_id >= (int)Dim(op_name_by_id_object)) return "unknown";
  return op_name_by_id_object[op_id];
}

static int
marpa_slif_op_id (const char *name)
{
  int lo = 0;
  int hi = Dim (op_by_name_object) - 1;
  while (hi >= lo)
    {
      const int trial = lo + (hi - lo) / 2;
      const char *trial_name = op_by_name_object[trial].name;
      int cmp = strcmp (name, trial_name);
      if (!cmp)
        return (int)op_by_name_object[trial].op;
      if (cmp < 0)
        {
          hi = trial - 1;
        }
      else
        {
          lo = trial + 1;
        }
    }
  return -1;
}

/* Assumes the marpa table is on the top of the stack,
 * and leaves it there.
 */
static void populate_ops(lua_State* L)
{
    int op_table;
    lua_Integer i;
    const int marpa_table = marpa_lua_gettop(L);

    marpa_lua_newtable(L);
    /* [ marpa_table, op_table ] */
    marpa_lua_pushvalue(L, -1);
    /* [ marpa_table, op_table, op_table ] */
    marpa_lua_setfield(L, marpa_table, "ops");
    /* [ marpa_table, op_table ] */
    op_table = marpa_lua_gettop(L);
    for (i = 0; i < (lua_Integer)Dim(op_by_name_object); i++) {
        /* [ marpa_table, op_table ] */
        marpa_lua_pushinteger(L, i);
        /* [ marpa_table, op_table, i ] */
        marpa_lua_setfield(L, op_table, op_by_name_object[i].name);
        /* [ marpa_table, op_table ] */
        marpa_lua_pushinteger(L, i);
        marpa_lua_pushstring(L, op_by_name_object[i].name);
        /* [ marpa_table, op_table, i, name ] */
        marpa_lua_settable(L, op_table);
        /* [ marpa_table, op_table ] */
    }
    marpa_lua_settop(L, marpa_table);
}

static void marpa_slr_event_clear( Scanless_R* slr )
{
  slr->t_event_count = 0;
  slr->t_count_of_deleted_events = 0;
}

static int marpa_slr_event_count( Scanless_R* slr )
{
  const int event_count = slr->t_event_count;
  return event_count - slr->t_count_of_deleted_events;
}

static union marpa_slr_event_s * marpa_slr_event_push( Scanless_R* slr )
{
  if (slr->t_event_count >= slr->t_event_capacity)
    {
      slr->t_event_capacity *= 2;
      Renew (slr->t_events, (unsigned int)slr->t_event_capacity, union marpa_slr_event_s);
    }
  return slr->t_events + (slr->t_event_count++);
}

static void marpa_slr_lexeme_clear( Scanless_R* slr )
{
  slr->t_lexeme_count = 0;
}

static union marpa_slr_event_s * marpa_slr_lexeme_push( Scanless_R* slr )
{
  if (slr->t_lexeme_count >= slr->t_lexeme_capacity)
    {
      slr->t_lexeme_capacity *= 2;
      Renew (slr->t_lexemes, (unsigned int)slr->t_lexeme_capacity, union marpa_slr_event_s);
    }
  return slr->t_lexemes + (slr->t_lexeme_count++);
}


typedef struct marpa_g Grammar;
/* The error_code member should usually be ignored in favor of
 * getting a fresh error code from Libmarpa.  Essentially it
 * acts as an optional return value for marpa_g_error()
 */

typedef struct marpa_r Recce;

#define TOKEN_VALUE_IS_UNDEF (1)
#define TOKEN_VALUE_IS_LITERAL (2)

typedef struct marpa_b Bocage;

typedef struct marpa_o Order;

typedef struct marpa_t Tree;

typedef struct marpa_v Value;

#define MARPA_XS_V_MODE_IS_INITIAL 0
#define MARPA_XS_V_MODE_IS_RAW 1
#define MARPA_XS_V_MODE_IS_STACK 2

static const char grammar_c_class_name[] = "Marpa::R3::Thin::G";
static const char recce_c_class_name[] = "Marpa::R3::Thin::R";
static const char bocage_c_class_name[] = "Marpa::R3::Thin::B";
static const char order_c_class_name[] = "Marpa::R3::Thin::O";
static const char tree_c_class_name[] = "Marpa::R3::Thin::T";
static const char value_c_class_name[] = "Marpa::R3::Thin::V";
static const char scanless_g_class_name[] = "Marpa::R3::Thin::SLG";
static const char scanless_r_class_name[] = "Marpa::R3::Thin::SLR";
static const char marpa_lua_class_name[] = "Marpa::R3::Lua";

static const char *
event_type_to_string (Marpa_Event_Type event_code)
{
  const char *event_name = NULL;
  if (event_code >= 0 && event_code < MARPA_ERROR_COUNT) {
      event_name = marpa_event_description[event_code].name;
  }
  return event_name;
}

static const char *
step_type_to_string (const lua_Integer step_type)
{
  const char *step_type_name = NULL;
  if (step_type >= 0 && step_type < MARPA_STEP_COUNT) {
      step_type_name = marpa_step_type_description[step_type].name;
  }
  return step_type_name;
}

/* This routine is for the handling exceptions
   from libmarpa.  It is used when in the general
   cases, for those exception which are not singled
   out for special handling by the XS logic.
   It returns a buffer which must be Safefree()'d.
*/
static char *
error_description_generate (G_Wrapper *g_wrapper)
{
  dTHX;
  const int error_code = g_wrapper->libmarpa_error_code;
  const char *error_string = g_wrapper->libmarpa_error_string;
  const char *suggested_description = NULL;
  /*
   * error_name should always be set when suggested_description is,
   * so this initialization should never be used.
   */
  const char *error_name = "not libmarpa error";
  const char *output_string;
  switch (error_code)
    {
    case MARPA_ERR_DEVELOPMENT:
      output_string = form ("(development) %s",
                              (error_string ? error_string : "(null)"));
                            goto COPY_STRING;
    case MARPA_ERR_INTERNAL:
      output_string = form ("Internal error (%s)",
                              (error_string ? error_string : "(null)"));
                            goto COPY_STRING;
    }
  if (error_code >= 0 && error_code < MARPA_ERROR_COUNT) {
      suggested_description = marpa_error_description[error_code].suggested;
      error_name = marpa_error_description[error_code].name;
  }
  if (!suggested_description)
    {
      if (error_string)
        {
          output_string = form ("libmarpa error %d %s: %s",
          error_code, error_name, error_string);
          goto COPY_STRING;
        }
      output_string = form ("libmarpa error %d %s", error_code, error_name);
          goto COPY_STRING;
    }
  if (error_string)
    {
      output_string = form ("%s%s%s", suggested_description, "; ", error_string);
          goto COPY_STRING;
    }
  output_string = suggested_description;
  COPY_STRING:
  {
      char* buffer = g_wrapper->message_buffer;
      if (buffer) Safefree(buffer);
      return g_wrapper->message_buffer = savepv(output_string);
    }
}

/* Argument must be something that can be Safefree()'d */
static const char *
set_error_from_string (G_Wrapper * g_wrapper, char *string)
{
  dTHX;
  Marpa_Grammar g = g_wrapper->g;
  char *buffer = g_wrapper->message_buffer;
  if (buffer) Safefree(buffer);
  g_wrapper->message_buffer = string;
  g_wrapper->message_is_marpa_thin_error = 1;
  marpa_g_error_clear(g);
  g_wrapper->libmarpa_error_code = MARPA_ERR_NONE;
  g_wrapper->libmarpa_error_string = NULL;
  return buffer;
}

/* Return value must be Safefree()'d */
static const char *
xs_g_error (G_Wrapper * g_wrapper)
{
  Marpa_Grammar g = g_wrapper->g;
  g_wrapper->libmarpa_error_code =
    marpa_g_error (g, &g_wrapper->libmarpa_error_string);
  g_wrapper->message_is_marpa_thin_error = 0;
  return error_description_generate (g_wrapper);
}

/* Wrapper to use vwarn with libmarpa */
static int marpa_r3_warn(const char* format, ...)
{
  dTHX;
   va_list args;
   va_start (args, format);
   vwarn (format, &args);
   va_end (args);
   return 1;
}

static void slr_es_to_span (Scanless_R * slr, Marpa_Earley_Set_ID earley_set,
                           int *p_start, int *p_length);
static void
slr_es_to_literal_span (Scanless_R * slr,
                        Marpa_Earley_Set_ID start_earley_set, int length,
                        int *p_start, int *p_length);
static SV*
slr_es_span_to_literal_sv (Scanless_R * slr,
                        Marpa_Earley_Set_ID start_earley_set, int length);

/* Xlua, that is, the eXtension of Lua for Marpa::XS.
 * Portions of this code adopted from Inline::Lua
 */

#define MT_NAME_SV "Marpa_sv"
#define MT_NAME_RECCE "Marpa_recce"
#define MT_NAME_GRAMMAR "Marpa_grammar"
#define MT_NAME_ARRAY "Marpa_array"

/* Make the Lua reference facility available from
 * Lua itself
 */
static int
xlua_ref(lua_State* L)
{
    marpa_luaL_checktype(L, 1, LUA_TTABLE);
    marpa_luaL_checkany(L, 2);
    marpa_lua_pushinteger(L, marpa_luaL_ref(L, 1));
    return 1;
}

static int
xlua_unref(lua_State* L)
{
    marpa_luaL_checktype(L, 1, LUA_TTABLE);
    marpa_luaL_checkinteger(L, 2);
    marpa_luaL_unref(L, 1, (int)marpa_lua_tointeger(L, 2));
    return 0;
}

/* Coerce a Lua value to a Perl SV, if necessary one that
 * is simply a string with an error message.
 * The call transfers ownership of one of the SV's reference
 * counts to the caller.
 * The Lua stack is left as is.
 */
static SV*
coerce_to_sv (lua_State * L, int idx)
{
  dTHX;
  SV *result;
  const int type = marpa_lua_type (L, idx);

  /* warn("%s %d\n", __FILE__, __LINE__); */
  switch (type)
    {
    case LUA_TNIL:
      /* warn("%s %d\n", __FILE__, __LINE__); */
      result = newSV (0);
      break;
    case LUA_TBOOLEAN:
      /* warn("%s %d\n", __FILE__, __LINE__); */
      result = marpa_lua_toboolean (L, idx) ?  newSViv(1) : newSV(0);
      break;
    case LUA_TNUMBER:
      /* warn("%s %d\n", __FILE__, __LINE__); */
      result = newSVnv (marpa_lua_tonumber (L, idx));
      break;
    case LUA_TSTRING:
      /* warn("%s %d: %s len=%d\n", __FILE__, __LINE__, marpa_lua_tostring (L, idx), marpa_lua_rawlen (L, idx)); */
      result =
        newSVpvn (marpa_lua_tostring (L, idx), marpa_lua_rawlen (L, idx));
      break;
    case LUA_TUSERDATA:
      {
        SV** p_result = marpa_luaL_testudata (L, idx, MT_NAME_SV);
        if (!p_result ) {
            result =
              newSVpvf
              ("Coercion not implemented for Lua userdata at index %d in coerce_to_sv",
               idx);
        } else {
          result = *p_result;
          SvREFCNT_inc_simple_void_NN (result);
        }
      };
      break;

    default:
      /* warn("%s %d\n", __FILE__, __LINE__); */
      result =
        newSVpvf
        ("Lua type %s at index %d in coerce_to_sv: coercion not implemented",
         marpa_luaL_typename (L, idx), idx);
      break;
    }
  /* warn("%s %d\n", __FILE__, __LINE__); */
  return result;
}

/* Push a Perl value onto the Lua stack. */
static void
push_val (lua_State * L, SV * val) PERL_UNUSED_DECL;
static void
push_val (lua_State * L, SV * val)
{
  dTHX;
  if (SvTYPE (val) == SVt_NULL)
    {
      /* warn("%s %d\n", __FILE__, __LINE__); */
      marpa_lua_pushnil (L);
      return;
    }
  if (SvPOK (val))
    {
      STRLEN n_a;
      /* warn("%s %d\n", __FILE__, __LINE__); */
      char *cval = SvPV (val, n_a);
      marpa_lua_pushlstring (L, cval, n_a);
      return;
    }
  if (SvNOK (val))
    {
      /* warn("%s %d\n", __FILE__, __LINE__); */
      marpa_lua_pushnumber (L, (lua_Number) SvNV (val));
      return;
    }
  if (SvIOK (val))
    {
      /* warn("%s %d\n", __FILE__, __LINE__); */
      marpa_lua_pushnumber (L, (lua_Number) SvIV (val));
      return;
    }
  if (SvROK (val))
    {
      /* warn("%s %d\n", __FILE__, __LINE__); */
      marpa_lua_pushfstring (L,
                             "[Perl ref to type %s]",
                             sv_reftype (SvRV (val), 0));
      return;
    }
      /* warn("%s %d\n", __FILE__, __LINE__); */
  marpa_lua_pushfstring (L, "[Perl type %d]",
                         SvTYPE (val));
  return;
}

/* Creates a userdata containing a Perl SV, and
 * leaves the new userdata on top of the stack.
 * The new Lua userdata takes ownership of one reference count.
 * The caller must have a reference count whose ownership
 * the caller is prepared to transfer to the Lua userdata.
 */
static void marpa_sv_sv_noinc (lua_State* L, SV* sv) {
    SV** p_sv = (SV**)marpa_lua_newuserdata(L, sizeof(SV*));
    *p_sv = sv;
    /* warn("new ud %p, SV %p %s %d\n", p_sv, sv, __FILE__, __LINE__); */
    marpa_luaL_getmetatable(L, MT_NAME_SV);
    marpa_lua_setmetatable(L, -2);
    /* [sv_userdata] */
}

#define MARPA_SV_SV(L, sv) \
    (marpa_sv_sv_noinc((L), (sv)), SvREFCNT_inc_simple_void_NN (sv))

/* Creates a userdata containing a reference to a Perl AV, and
 * leaves the new userdata on top of the stack.
 * The new Lua userdata takes ownership of one reference count.
 * The caller must have a reference count whose ownership
 * the caller is prepared to transfer to the Lua userdata.
 */
static void marpa_sv_av_noinc (lua_State* L, AV* av) {
    dTHX;
    SV* av_ref = newRV_noinc((SV*)av);
    SV** p_sv = (SV**)marpa_lua_newuserdata(L, sizeof(SV*));
    *p_sv = av_ref;
    /* warn("new ud %p, SV %p %s %d\n", p_sv, av_ref, __FILE__, __LINE__); */
    marpa_luaL_getmetatable(L, MT_NAME_SV);
    marpa_lua_setmetatable(L, -2);
    /* [sv_userdata] */
}

#define MARPA_SV_AV(L, av) \
    (SvREFCNT_inc_simple_void_NN (av), marpa_sv_av_noinc((L), (av)))

static int marpa_sv_undef (lua_State* L) {
    dTHX;
    /* [] */
    marpa_sv_sv_noinc( L, newSV(0) );
    /* [sv_userdata] */
    return 1;
}

static int marpa_sv_finalize_meth (lua_State* L) {
    dTHX;
    /* Is this check necessary after development? */
    SV** p_sv = (SV**)marpa_luaL_checkudata(L, 1, MT_NAME_SV);
    SV* sv = *p_sv;
    /* warn("decrementing ud %p, SV %p, %s %d\n", p_sv, sv, __FILE__, __LINE__); */
    SvREFCNT_dec (sv);
    return 0;
}

/* Convert Lua object to number, including our custom Marpa userdata's
 */
static lua_Number marpa_xlua_tonumber (lua_State* L, int idx, int* pisnum) {
    dTHX;
    void* ud;
    int pisnum2;
    lua_Number n;
    if (pisnum) *pisnum = 1;
    n = marpa_lua_tonumberx(L, idx, &pisnum2);
    if (pisnum2) return n;
    ud = marpa_luaL_testudata(L, idx, MT_NAME_SV);
    if (!ud) {
        if (pisnum) *pisnum = 0;
        return 0;
    }
    return (lua_Number) SvNV (*(SV**)ud);
}

static int marpa_sv_add_meth (lua_State* L) {
    lua_Number num1 = marpa_xlua_tonumber(L, 1, NULL);
    lua_Number num2 = marpa_xlua_tonumber(L, 2, NULL);
    marpa_lua_pushnumber(L, num1+num2);
    return 1;
}

/* Fetch from table at index key.
 * The reference count is not changed, the caller must use this
 * SV immediately, or increment the reference count.
 * Will return 0, if there is no SV at that index.
 */
static SV** marpa_av_fetch(SV* table, lua_Integer key) {
     dTHX;
     AV* av;
     if ( !SvROK(table) ) {
        croak ("Attempt to fetch from an SV which is not a ref");
     }
     if ( SvTYPE(SvRV(table)) != SVt_PVAV) {
        croak ("Attempt to fetch from an SV which is not an AV ref");
     }
     av = (AV*)SvRV(table);
     return av_fetch(av, (int)key, 0);
}

static int marpa_av_fetch_meth(lua_State* L) {
    SV** p_result_sv;
    SV** p_table_sv = (SV**)marpa_luaL_checkudata(L, 1, MT_NAME_SV);
    lua_Integer key = marpa_luaL_checkinteger(L, 2);

    p_result_sv = marpa_av_fetch(*p_table_sv, key);
    if (p_result_sv) {
        SV* const sv = *p_result_sv;
        /* Increment the reference count and put this SV on top of the stack */
        MARPA_SV_SV(L, sv);
    } else {
        /* Put a new nil SV on top of the stack */
        marpa_sv_undef(L);
    }
    return 1;
}

/* Basically a Lua wrapper for Perl's av_len()
 */
static int
marpa_av_len_meth (lua_State * L)
{
    dTHX;
    AV *av;
    SV **const p_table_sv = (SV **) marpa_luaL_checkudata (L, 1, MT_NAME_SV);
    SV* const table = *p_table_sv;

    if (!SvROK (table))
      {
          croak ("Attempt to fetch from an SV which is not a ref");
      }
    if (SvTYPE (SvRV (table)) != SVt_PVAV)
      {
          croak ("Attempt to fetch from an SV which is not an AV ref");
      }
    av = (AV *) SvRV (table);
    marpa_lua_pushinteger (L, av_len (av));
    return 1;
}

static void marpa_av_store(SV* table, lua_Integer key, SV*value) {
     dTHX;
     AV* av;
     if ( !SvROK(table) ) {
        croak ("Attempt to index an SV which is not ref");
     }
     if ( SvTYPE(SvRV(table)) != SVt_PVAV) {
        croak ("Attempt to index an SV which is not an AV ref");
     }
     av = (AV*)SvRV(table);
     av_store(av, (int)key, value);
}

static int marpa_av_store_meth(lua_State* L) {
    SV** p_table_sv = (SV**)marpa_luaL_checkudata(L, 1, MT_NAME_SV);
    lua_Integer key = marpa_luaL_checkinteger(L, 2);
    SV* value_sv = coerce_to_sv(L, 3);

    /* coerce_to_sv transfered a reference count to us, which we
     * pass on to the AV.
     */
    marpa_av_store(*p_table_sv, key, value_sv);
    return 0;
}

static void
marpa_av_fill (lua_State * L, SV * sv, int x)
{
  dTHX;
  AV *av;
  SV **p_sv = (SV **) marpa_lua_newuserdata (L, sizeof (SV *));
     /* warn("%s %d\n", __FILE__, __LINE__); */
  *p_sv = sv;
     /* warn("%s %d\n", __FILE__, __LINE__); */
  if (!SvROK (sv))
    {
      croak ("Attempt to fetch from an SV which is not a ref");
    }
     /* warn("%s %d\n", __FILE__, __LINE__); */
  if (SvTYPE (SvRV (sv)) != SVt_PVAV)
    {
      croak ("Attempt to fill an SV which is not an AV ref");
    }
     /* warn("%s %d\n", __FILE__, __LINE__); */
  av = (AV *) SvRV (sv);
     /* warn("%s %d about to call av_file(..., %d)\n", __FILE__, __LINE__, x); */
  av_fill (av, x);
     /* warn("%s %d\n", __FILE__, __LINE__); */
}

static int marpa_av_fill_meth (lua_State* L) {
    /* After development, check not needed */
    SV** p_table_sv = (SV**)marpa_luaL_checkudata(L, 1, MT_NAME_SV);
    /* warn("%s %d\n", __FILE__, __LINE__); */
    lua_Integer index = marpa_luaL_checkinteger(L, 2);
    /* warn("%s %d\n", __FILE__, __LINE__); */
    marpa_av_fill(L, *p_table_sv, (int)index);
    /* warn("%s %d\n", __FILE__, __LINE__); */
    return 0;
}

static int marpa_sv_tostring_meth(lua_State* L) {
    /* Lua stack: [ sv_userdata ] */
    /* After development, check not needed */
    SV** p_table_sv = (SV**)marpa_luaL_checkudata(L, 1, MT_NAME_SV);
    marpa_lua_getglobal(L, "tostring");
    /* Lua stack: [ sv_userdata, to_string_fn ] */
    push_val (L, *p_table_sv);
    /* Lua stack: [ sv_userdata, to_string_fn, lua_equiv_of_sv ] */
    marpa_lua_call(L, 1, 1);
    /* Lua stack: [ sv_userdata, string_equiv_of_sv ] */
    if (!marpa_lua_isstring(L, -1)) {
       croak("sv could not be converted to string");
    }
    return 1;
}

static const struct luaL_Reg marpa_sv_meths[] = {
    {"__add", marpa_sv_add_meth},
    {"__gc", marpa_sv_finalize_meth},
    {"__index", marpa_av_fetch_meth},
    {"__newindex", marpa_av_store_meth},
    {"__tostring", marpa_sv_tostring_meth},
    {NULL, NULL},
};

static const struct luaL_Reg marpa_sv_funcs[] = {
    {"fill", marpa_av_fill_meth},
    {"top_index", marpa_av_len_meth},
    {"undef", marpa_sv_undef},
    {NULL, NULL},
};

/* create SV metatable */
static void create_sv_mt (lua_State* L) {
    int base_of_stack = marpa_lua_gettop(L);
    marpa_luaL_newmetatable(L, MT_NAME_SV);
    /* Lua stack: [mt] */

    /* metatable.__index = metatable */
    marpa_lua_pushvalue(L, -1);
    marpa_lua_setfield(L, -2, "__index");
    /* Lua stack: [mt] */

    /* register methods */
    marpa_luaL_setfuncs(L, marpa_sv_meths, 0);
    /* Lua stack: [mt] */
    marpa_lua_settop(L, base_of_stack);
}

static int xlua_recce_stack_meth(lua_State* L) {
    Scanless_R* slr;
    V_Wrapper *v_wrapper;
    AV* stack;

    marpa_luaL_checktype(L, 1, LUA_TTABLE);
    /* Lua stack: [ recce_table ] */
    marpa_lua_getfield(L, -1, "lud");
    /* Lua stack: [ recce_table, lud ] */
    slr = (Scanless_R*)marpa_lua_touserdata(L, -1);
    /* the slr owns the recce table, so it doesn't */
    /* need to own its components. */
    v_wrapper = slr->v_wrapper;
    if (!v_wrapper) {
        /* A recoverable error?  Probably not */
        croak("recce.stack(): valuator is not yet active");
    }
    stack = v_wrapper->stack;
    if (!stack) {
        /* I think this is an internal error */
        croak("recce.stack(): valuator has no stack");
    }
    MARPA_SV_AV(L, stack);
    /* Lua stack: [ recce_table, recce_lud, stack_ud ] */
    return 1;
}

static int xlua_recce_step_meth(lua_State* L) {
    Scanless_R* slr;
    V_Wrapper *v_wrapper;
    Marpa_Value v;
    lua_Integer step_type;
    const int recce_table = marpa_lua_gettop(L);
    int step_table;
    int v_table;

    marpa_luaL_checktype(L, 1, LUA_TTABLE);
    /* Lua stack: [ recce_table ] */
    if (LUA_TLIGHTUSERDATA != marpa_lua_getfield(L, -1, "lud")) {
        croak("Internal error: recce.lud userdata not set");
    }
    /* Lua stack: [ recce_table, lud ] */
    slr = (Scanless_R*)marpa_lua_touserdata(L, -1);
    /* the slr owns the recce table, so it doesn't */
    /* need to own its components. */

    v_wrapper = slr->v_wrapper;
    if (!v_wrapper) {
        /* A recoverable error?  Probably not */
        croak("recce.stack(): valuator is not yet active");
    }
    v = v_wrapper->v;
    /* Lua stack: [ recce_table, lud, ] */
    if (LUA_TTABLE != marpa_lua_getfield(L, recce_table, "v")) {
        croak("Internal error: recce.v table not set");
    }
    v_table = marpa_lua_gettop(L);
    /* Lua stack: [ recce_table, lud, v_table ] */
    marpa_lua_newtable(L);
    /* Lua stack: [ recce_table, lud, v_table, step_table ] */
    step_table = marpa_lua_gettop(L);
    marpa_lua_pushvalue(L, -1);
    marpa_lua_setfield(L, v_table, "step");
    /* Lua stack: [ recce_table, lud, v_table, step_table ] */

    step_type = (lua_Integer)marpa_v_step (v);
    marpa_lua_pushstring(L, step_type_to_string (step_type));
    marpa_lua_setfield(L, step_table, "type");

    switch(step_type) {
    case MARPA_STEP_RULE:
        marpa_lua_pushinteger(L, marpa_v_result(v));
        marpa_lua_setfield(L, step_table, "result");
        marpa_lua_pushinteger(L, marpa_v_arg_n(v));
        marpa_lua_setfield(L, step_table, "arg_n");
        marpa_lua_pushinteger(L, marpa_v_rule(v));
        marpa_lua_setfield(L, step_table, "rule");
        marpa_lua_pushinteger(L, marpa_v_rule_start_es_id(v));
        marpa_lua_setfield(L, step_table, "start_es_id");
        marpa_lua_pushinteger(L, marpa_v_es_id(v));
        marpa_lua_setfield(L, step_table, "es_id");
        break;
    case MARPA_STEP_TOKEN:
        marpa_lua_pushinteger(L, marpa_v_result(v));
        marpa_lua_setfield(L, step_table, "result");
        marpa_lua_pushinteger(L, marpa_v_token(v));
        marpa_lua_setfield(L, step_table, "symbol");
        marpa_lua_pushinteger(L, marpa_v_token_value(v));
        marpa_lua_setfield(L, step_table, "value");
        marpa_lua_pushinteger(L, marpa_v_token_start_es_id(v));
        marpa_lua_setfield(L, step_table, "start_es_id");
        marpa_lua_pushinteger(L, marpa_v_es_id(v));
        marpa_lua_setfield(L, step_table, "es_id");
        break;
    case MARPA_STEP_NULLING_SYMBOL:
        marpa_lua_pushinteger(L, marpa_v_result(v));
        marpa_lua_setfield(L, step_table, "result");
        marpa_lua_pushinteger(L, marpa_v_token(v));
        marpa_lua_setfield(L, step_table, "symbol");
        marpa_lua_pushinteger(L, marpa_v_token_start_es_id(v));
        marpa_lua_setfield(L, step_table, "start_es_id");
        marpa_lua_pushinteger(L, marpa_v_es_id(v));
        marpa_lua_setfield(L, step_table, "es_id");
        break;
    }

    return 0;
}

static int
xlua_recce_literal_of_es_span_meth (lua_State * L)
{
    Scanless_R *slr;
    int lud_type;
    lua_Integer start_earley_set;
    lua_Integer length;
    SV *literal_sv;

    marpa_luaL_checktype (L, 1, LUA_TTABLE);
    /* Lua stack: [ recce_table ] */
    lud_type = marpa_lua_getfield (L, -1, "lud");
    /* Lua stack: [ recce_table, lud ] */
    marpa_luaL_argcheck (L, (lud_type == LUA_TUSERDATA), 1,
        "recce userdata not set");
    start_earley_set = marpa_luaL_checkinteger (L, 2);
    length = marpa_luaL_checkinteger (L, 3);

    slr = (Scanless_R *) marpa_lua_touserdata (L, -1);
    literal_sv =
        slr_es_span_to_literal_sv (slr,
        (Marpa_Earley_Set_ID) start_earley_set, (int)length);
    marpa_sv_sv_noinc (L, literal_sv);
    /* Lua stack: [ recce_table, recce_lud, stack_ud ] */
    return 1;
}

static const struct luaL_Reg marpa_recce_meths[] = {
    {"stack", xlua_recce_stack_meth},
    {"step", xlua_recce_step_meth},
    {"literal_of_es_span", xlua_recce_literal_of_es_span_meth},
    {"ref", xlua_ref},
    {"unref", xlua_unref},
    {NULL, NULL},
};

/* create SV metatable */
static void create_recce_mt (lua_State* L) {
    int base_of_stack = marpa_lua_gettop(L);
    marpa_luaL_newmetatable(L, MT_NAME_RECCE);
    /* Lua stack: [mt] */

    /* metatable.__index = metatable */
    marpa_lua_pushvalue(L, -1);
    marpa_lua_setfield(L, -2, "__index");
    /* Lua stack: [mt] */

    /* register methods */
    marpa_luaL_setfuncs(L, marpa_recce_meths, 0);
    /* Lua stack: [mt] */
    marpa_lua_settop(L, base_of_stack);
}

static const struct luaL_Reg marpa_grammar_meths[] = {
    {NULL, NULL},
};

/* create SV metatable */
static void create_grammar_mt (lua_State* L) {
    int base_of_stack = marpa_lua_gettop(L);
    marpa_luaL_newmetatable(L, MT_NAME_GRAMMAR);
    /* Lua stack: [mt] */

    /* metatable.__index = metatable */
    marpa_lua_pushvalue(L, -1);
    marpa_lua_setfield(L, -2, "__index");
    /* Lua stack: [mt] */

    /* register methods */
    marpa_luaL_setfuncs(L, marpa_grammar_meths, 0);
    /* Lua stack: [mt] */
    marpa_lua_settop(L, base_of_stack);
}

/* Manage the ref count of a Lua state, closing it
 * when it falls to zero.
 * 'inc' should be
 * one of
 *    -1   -- decrement
 *     1   -- increment
 *     0   -- query
 * The current value of the ref count is always returned.
 * If it has fallen to 0, the state is closed.
 */
static void xlua_refcount(lua_State* L, int inc)
{
    int base_of_stack = marpa_lua_gettop(L);
    lua_Integer new_refcount;
    /* Lua stack [] */
    marpa_lua_getfield(L, LUA_REGISTRYINDEX, "ref_count");
    /* Lua stack [ old_ref_count ] */
    new_refcount = marpa_lua_tointeger(L, -1);
    /* Lua stack [ ] */
    new_refcount += inc;
    /* warn("xlua_refcount(), new_refcount=%d", new_refcount); */
    if (new_refcount <= 0) {
       marpa_lua_close(L);
       return;
    }
    marpa_lua_pushinteger(L, new_refcount);
    /* Lua stack [ old_ref_count, new_ref_count ] */
    marpa_lua_setfield(L, LUA_REGISTRYINDEX, "ref_count");
    marpa_lua_settop(L, base_of_stack);
    /* Lua stack [ ] */
}

static int xlua_recce_func(lua_State* L)
{
  /* Lua stack [ recce_ref ] */
  lua_Integer recce_ref = marpa_luaL_checkinteger(L, 1);
  marpa_lua_rawgeti (L, LUA_REGISTRYINDEX, recce_ref);
  /* Lua stack [ recce_ref, recce_table ] */
  return 1;
}

static const struct luaL_Reg marpa_funcs[] = {
    {"recce", xlua_recce_func},
    {NULL, NULL},
};

/* === LUA ARRAY CLASS === */

typedef struct Xlua_Array {
    size_t size;
    unsigned int array[1];
} Xlua_Array;

/* Leaves new userdata on top of stack */
static void
xlua_array_new (lua_State * L, lua_Integer size)
{
    marpa_lua_newuserdata (L,
        sizeof (Xlua_Array) + ((size_t)size - 1) * sizeof (unsigned int));
    marpa_luaL_setmetatable (L, MT_NAME_ARRAY);
}

static int xlua_array_new_func(lua_State* L)
{
   const lua_Integer size = marpa_luaL_checkinteger(L, 1);
   xlua_array_new(L, size);
   return 1;
}

static int
xlua_array_from_list_func (lua_State * L)
{
    int ix;
    Xlua_Array *p_array;
    const int last_arg = marpa_lua_gettop (L);

    xlua_array_new(L, last_arg);
    /* [ array_ud ] */
    p_array = (Xlua_Array *) marpa_lua_touserdata (L, -1);
    for (ix = 1; ix <= last_arg; ix++) {
        const lua_Integer value = marpa_luaL_checkinteger (L, ix);
        p_array->array[ix - 1] = (unsigned int)value;
    }
    p_array->size = (size_t)last_arg;
    /* [ array_ud ] */
    return 1;
}

static int
xlua_array_index_meth (lua_State * L)
{
    Xlua_Array * const p_array =
        (Xlua_Array *) marpa_luaL_checkudata (L, 1, MT_NAME_ARRAY);
    const lua_Integer ix = marpa_luaL_checkinteger (L, 2);
    marpa_luaL_argcheck (L, (ix >= 0 && (size_t)ix < p_array->size), 2,
        "index out of bounds");
    marpa_lua_pushinteger(L, p_array->array[ix]);
    return 1;
}

static int
xlua_array_new_index_meth (lua_State * L)
{
    Xlua_Array * const p_array =
        (Xlua_Array *) marpa_luaL_checkudata (L, 1, MT_NAME_ARRAY);
    const lua_Integer ix = marpa_luaL_checkinteger (L, 2);
    const unsigned int value = (unsigned int)marpa_luaL_checkinteger (L, 3);
    marpa_luaL_argcheck (L, (ix < 0 || (size_t)ix >= p_array->size), 2,
        "index out of bounds");
    p_array->array[ix] = value;
    return 1;
}

static int
xlua_array_len_meth (lua_State * L)
{
    Xlua_Array * const p_array =
        (Xlua_Array *) marpa_luaL_checkudata (L, 1, MT_NAME_ARRAY);
    marpa_lua_pushinteger(L, p_array->size);
    return 1;
}

static const struct luaL_Reg marpa_array_meths[] = {
    {"__index", xlua_array_index_meth},
    {"__newindex", xlua_array_new_index_meth},
    {"__len", xlua_array_len_meth},
    {NULL, NULL},
};

static const struct luaL_Reg marpa_array_funcs[] = {
    {"from_list", xlua_array_from_list_func},
    {"new", xlua_array_new_func},
    {NULL, NULL},
};

/* create SV metatable */
static void create_array_mt (lua_State* L) {
    int base_of_stack = marpa_lua_gettop(L);
    marpa_luaL_newmetatable(L, MT_NAME_ARRAY);
    /* Lua stack: [mt] */

    /* metatable.__index = metatable */
    marpa_lua_pushvalue(L, -1);
    marpa_lua_setfield(L, -2, "__index");
    /* Lua stack: [mt] */

    /* register methods */
    marpa_luaL_setfuncs(L, marpa_array_meths, 0);
    /* Lua stack: [mt] */
    marpa_lua_settop(L, base_of_stack);
}

/* Returns a new Lua state, set up for Marpa, with
 * a reference count of 1.
 */
static lua_State* xlua_newstate(void)
{
    int marpa_table;
    lua_State *const L = marpa_luaL_newstate ();
    const int base_of_stack = marpa_lua_gettop(L);

    if (!L)
      {
          croak
              ("Marpa::R3 internal error: Lua interpreter failed to start");
      }
    /* warn("New lua state %p, slg = %p", L, slg); */
    xlua_refcount (L, 1);       /* increment the ref count of the Lua state */
    marpa_luaL_openlibs (L);    /* open libraries */
    /* Lua stack: [] */
    marpa_luaopen_kollos(L); /* Open kollos library */
    /* Lua stack: [ kollos_table ] */
    marpa_lua_setglobal(L, "kollos");
    /* Lua stack: [] */

    /* create metatables */
    create_sv_mt(L);
    create_grammar_mt(L);
    create_recce_mt(L);
    create_array_mt(L);

    marpa_luaL_newlib(L, marpa_funcs);
    /* Lua stack: [ marpa_table ] */
    marpa_table = marpa_lua_gettop (L);
    /* Lua stack: [ marpa_table ] */
    marpa_lua_pushvalue (L, -1);
    /* Lua stack: [ marpa_table, marpa_table ] */
    marpa_lua_setglobal (L, "marpa");
    /* Lua stack: [ marpa_table ] */

    marpa_luaL_newlib(L, marpa_sv_funcs);
    /* Lua stack: [ marpa_table, sv_table ] */
    marpa_lua_setfield (L, marpa_table, "sv");
    /* Lua stack: [ marpa_table ] */

    marpa_luaL_newlib(L, marpa_array_funcs);
    /* Lua stack: [ marpa_table, sv_table ] */
    marpa_lua_setfield (L, marpa_table, "array");
    /* Lua stack: [ marpa_table ] */

    marpa_lua_newtable (L);
    /* Lua stack: [ marpa_table, context_table ] */
    marpa_lua_setfield (L, marpa_table, "context");
    /* Lua stack: [ marpa_table ] */

    populate_ops(L);
    /* Lua stack: [ marpa_table ] */

    marpa_lua_settop (L, base_of_stack);
    /* Lua stack: [] */
    return L;
}

static void
xlua_sig_call (lua_State * L, const char *codestr, const char *sig, ...)
{
    va_list vl;
    int narg, nres;
    int status;
    const int base_of_stack = marpa_lua_gettop (L);

    va_start (vl, sig);

    /* warn("%s %d", __FILE__, __LINE__); */
    status = marpa_luaL_loadbuffer (L, codestr, strlen (codestr), codestr);
    /* warn("%s %d", __FILE__, __LINE__); */
    if (status != 0) {
        const char *error_string = marpa_lua_tostring (L, -1);
        marpa_lua_pop (L, 1);
        croak ("Marpa::R3 error in xlua_sig_call: %s", error_string);
    }
    /* warn("%s %d", __FILE__, __LINE__); */
    /* Lua stack: [ function ] */

    for (narg = 0; *sig; narg++) {
        const char this_sig = *sig++;
        /* warn("%s %d narg=%d", __FILE__, __LINE__, narg); */
        if (!marpa_lua_checkstack (L, LUA_MINSTACK + 1)) {
            /* This error is not considered recoverable */
            croak ("Marpa::R3 error: could not grow Lua stack");
        }
        /* warn("%s %d narg=%d *sig=%c", __FILE__, __LINE__, narg, *sig); */
        switch (this_sig) {
        case 'd':
            marpa_lua_pushnumber (L, va_arg (vl, double));
            break;
        case 'i':
            marpa_lua_pushnumber (L, va_arg (vl, int));
            break;
        case 's':
            marpa_lua_pushstring (L, va_arg (vl, char *));
            break;
        case 'S':              /* argument is SV -- ownership is taken of
                                 * a reference count, so caller is responsible
                                 * for making sure a reference count is
                                 * available for the taking.
                                 */
            /* warn("%s %d narg=%d", __FILE__, __LINE__, narg, *sig); */
            marpa_sv_sv_noinc (L, va_arg (vl, SV *));
            /* warn("%s %d narg=%d", __FILE__, __LINE__, narg, *sig); */
            break;
        case 'R':              /* argument is ref key of recce table */
            marpa_lua_rawgeti (L, LUA_REGISTRYINDEX, va_arg (vl, int));
            break;
        case '>':              /* end of arguments */
            goto endargs;
        default:
            croak
                ("Internal error: invalid sig option %c in xlua_sig_call", this_sig);
        }
        /* warn("%s %d narg=%d *sig=%c", __FILE__, __LINE__, narg, *sig); */
    }
  endargs:;

    nres = (int)strlen (sig);

    /* warn("%s %d", __FILE__, __LINE__); */
    status = marpa_lua_pcall (L, narg, nres, 0);
    if (status != 0) {
        const char *error_string = marpa_lua_tostring (L, -1);
        /* error_string must be copied before it is exposed to Lua GC */
        const char *croak_msg =
            form ("Internal error: xlua_sig_call code error: %s",
            error_string);
        marpa_lua_settop (L, base_of_stack);
        croak (croak_msg);
    }

    for (nres = -nres; *sig; nres++) {
        const char this_sig = *sig++;
        switch (this_sig) {
        case 'd':
            {
                int isnum;
                const double n = marpa_lua_tonumberx (L, nres, &isnum);
                if (!isnum)
                    croak
                        ("Internal error: xlua_sig_call: result type is not double");
                *va_arg (vl, double *) = n;
                break;
            }
        case 'i':
            {
                int isnum;
                const lua_Integer n = marpa_lua_tointegerx (L, nres, &isnum);
                if (!isnum)
                    croak
                        ("Internal error: xlua_sig_call: result type is not integer");
                *va_arg (vl, int *) = (int)n;
                break;
            }
        case 'S': /* SV -- caller becomes owner of 1 ref count. */
        {
            croak("not yet implemented");
        }
        default:
            croak
                ("Internal error: invalid sig option %c in xlua_sig_call", this_sig);
        }
    }

    /* Results *must* be copied at this point, because
     * now we expose them to Lua GC
     */
    marpa_lua_settop (L, base_of_stack);
    /* warn("%s %d", __FILE__, __LINE__); */
    va_end (vl);
}

/* Static grammar methods */

#define SET_G_WRAPPER_FROM_G_SV(g_wrapper, g_sv) { \
    IV tmp = SvIV ((SV *) SvRV (g_sv)); \
    (g_wrapper) = INT2PTR (G_Wrapper *, tmp); \
}

/* Static recognizer methods */

#define SET_R_WRAPPER_FROM_R_SV(r_wrapper, r_sv) { \
    IV tmp = SvIV ((SV *) SvRV (r_sv)); \
    (r_wrapper) = INT2PTR (R_Wrapper *, tmp); \
}

/* Maybe inline some of these */

/* Assumes caller has checked that g_sv is blessed into right type.
   Assumes caller holds a ref to the recce.
*/
static R_Wrapper*
r_wrap( Marpa_Recce r, SV* g_sv)
{
    dTHX;
    int highest_symbol_id;
    R_Wrapper *r_wrapper;
    G_Wrapper *g_wrapper;
    Marpa_Grammar g;

    SET_G_WRAPPER_FROM_G_SV (g_wrapper, g_sv);
    g = g_wrapper->g;

    highest_symbol_id = marpa_g_highest_symbol_id (g);
    if (highest_symbol_id < 0) {
        if (!g_wrapper->throw) {
            return 0;
        }
        croak ("failure in marpa_g_highest_symbol_id: %s",
            xs_g_error (g_wrapper));
    };
    Newx (r_wrapper, 1, R_Wrapper);
    r_wrapper->r = r;
    Newx (r_wrapper->terminals_buffer,
        (unsigned int) (highest_symbol_id + 1), Marpa_Symbol_ID);
    r_wrapper->ruby_slippers = 0;
    SvREFCNT_inc (g_sv);
    r_wrapper->base_sv = g_sv;
    r_wrapper->base = g_wrapper;
    r_wrapper->event_queue = newAV ();
    return r_wrapper;
}

/* It is up to the caller to deal with the Libmarpa recce's
 * reference count
 */
static Marpa_Recce
r_unwrap (R_Wrapper * r_wrapper)
{
  dTHX;
  Marpa_Recce r = r_wrapper->r;
  /* The wrapper should always have had a ref to its base grammar's SV */
  SvREFCNT_dec (r_wrapper->base_sv);
  SvREFCNT_dec ((SV *) r_wrapper->event_queue);
  Safefree (r_wrapper->terminals_buffer);
  Safefree (r_wrapper);
  /* The wrapper should always have had a ref to the Libmarpa recce */
  return r;
}

static void
u_r0_clear (Scanless_R * slr)
{
  dTHX;
  Marpa_Recce r0 = slr->r0;
  if (!r0)
    return;
  marpa_r_unref (r0);
  slr->r0 = NULL;
}

static Marpa_Recce
u_r0_new (Scanless_R * slr)
{
  dTHX;
  Marpa_Recce r0 = slr->r0;
  const IV trace_lexers = slr->trace_lexers;
  G_Wrapper *lexer_wrapper = slr->slg->l0_wrapper;
  const int too_many_earley_items = slr->too_many_earley_items;

  if (r0)
    {
      marpa_r_unref (r0);
    }
  slr->r0 = r0 = marpa_r_new (lexer_wrapper->g);
  if (!r0)
    {
      if (!lexer_wrapper->throw)
        return 0;
      croak ("failure in marpa_r_new(): %s", xs_g_error (lexer_wrapper));
    };
  if (too_many_earley_items >= 0)
    {
      marpa_r_earley_item_warning_threshold_set (r0, too_many_earley_items);
    }
  {
    int i;
    Marpa_Symbol_ID *terminals_buffer = slr->r1_wrapper->terminals_buffer;
    const int count = marpa_r_terminals_expected (slr->r1, terminals_buffer);
    if (count < 0)
      {
        croak ("Problem in u_r0_new() with terminals_expected: %s",
               xs_g_error (slr->g1_wrapper));
      }
    for (i = 0; i < count; i++)
      {
        const Marpa_Symbol_ID terminal = terminals_buffer[i];
        const Marpa_Assertion_ID assertion =
          slr->slg->g1_lexeme_to_assertion[terminal];
        if (assertion >= 0 && marpa_r_zwa_default_set (r0, assertion, 1) < 0)
          {
            croak
              ("Problem in u_r0_new() with assertion ID %ld and lexeme ID %ld: %s",
               (long) assertion, (long) terminal,
               xs_g_error (lexer_wrapper));
          }
        if (trace_lexers >= 1)
          {
            union marpa_slr_event_s *event =
              marpa_slr_event_push (slr);
            MARPA_SLREV_TYPE (event) = MARPA_SLRTR_LEXEME_EXPECTED;
            event->t_trace_lexeme_expected.t_perl_pos = slr->perl_pos;
            event->t_trace_lexeme_expected.t_lexeme = terminal;
            event->t_trace_lexeme_expected.t_assertion = assertion;
          }

      }
  }
  {
    int gp_result = marpa_r_start_input (r0);
    if (gp_result == -1)
      return 0;
    if (gp_result < 0)
      {
        if (lexer_wrapper->throw)
          {
            croak ("Problem in r->start_input(): %s",
                   xs_g_error (lexer_wrapper));
          }
        return 0;
      }
  }
  return r0;
}

/* Assumes it is called
 after a successful marpa_r_earleme_complete()
 */
static void
u_convert_events (Scanless_R * slr)
{
  dTHX;
  int event_ix;
  Marpa_Grammar g = slr->slg->l0_wrapper->g;
  const int event_count = marpa_g_event_count (g);
  for (event_ix = 0; event_ix < event_count; event_ix++)
    {
      Marpa_Event marpa_event;
      Marpa_Event_Type event_type =
        marpa_g_event (g, &marpa_event, event_ix);
      switch (event_type)
        {
          {
        case MARPA_EVENT_EXHAUSTED:
            /* Do nothing about exhaustion on success */
            break;
        case MARPA_EVENT_EARLEY_ITEM_THRESHOLD:
            /* All events are ignored on failure
             * On success, all except MARPA_EVENT_EARLEY_ITEM_THRESHOLD
             * are ignored.
             *
             * The warning raised for MARPA_EVENT_EARLEY_ITEM_THRESHOLD
             * can be turned off by raising
             * the Earley item warning threshold.
             */
            {
              const int yim_count = (long) marpa_g_event_value (&marpa_event);
              union marpa_slr_event_s *event = marpa_slr_event_push (slr);
              MARPA_SLREV_TYPE (event) = MARPA_SLREV_L0_YIM_THRESHOLD_EXCEEDED;
              event->t_l0_yim_threshold_exceeded.t_yim_count = yim_count;
              event->t_l0_yim_threshold_exceeded.t_perl_pos = slr->perl_pos;
            }
            break;
        default:
            {
              const char *result_string = event_type_to_string (event_type);
              if (result_string)
                {
                  croak ("unexpected lexer grammar event: %s",
                         result_string);
                }
              croak ("lexer grammar event with unknown event code, %d",
                     event_type);
            }
            break;
          }
        }
    }
}

#define U_READ_OK 0
#define U_READ_REJECTED_CHAR -1
#define U_READ_UNREGISTERED_CHAR -2
#define U_READ_EXHAUSTED_ON_FAILURE -3
#define U_READ_TRACING -4
#define U_READ_EXHAUSTED_ON_SUCCESS -5
#define U_READ_INVALID_CHAR -6

/* Return values:
 * 1 or greater: reserved for an event count, to deal with multiple events
 *   when and if necessary
 * 0: success: a full reading of the input, with nothing to report.
 * -1: a character was rejected
 * -2: an unregistered character was found
 * -3: earleme_complete() reported an exhausted parse on failure
 * -4: we are tracing, character by character
 * -5: earleme_complete() reported an exhausted parse on success
 */
static int
u_read (Scanless_R * slr)
{
  dTHX;
  U8 *input;
  STRLEN len;
  int input_is_utf8;

  const IV trace_lexers = slr->trace_lexers;
  Marpa_Recognizer r = slr->r0;

  if (!r)
    {
      r = u_r0_new (slr);
      if (!r)
        croak ("Problem in u_read(): %s",
               xs_g_error (slr->slg->l0_wrapper));
    }
  input_is_utf8 = SvUTF8 (slr->input);
  input = (U8 *) SvPV (slr->input, len);
  for (;;)
    {
      UV codepoint;
      STRLEN codepoint_length = 1;
      UV op_ix;
      UV op_count;
      UV *ops;
      int tokens_accepted = 0;
      if (slr->perl_pos >= slr->end_pos)
        break;

      if (input_is_utf8)
        {

          codepoint =
            utf8_to_uvchr_buf (input + OFFSET_IN_INPUT (slr),
                               input + len, &codepoint_length);

          /* Perl API documents that return value is 0 and length is -1 on error,
           * "if possible".  length can be, and is, in fact unsigned.
           * I deal with this by noting that 0 is a valid UTF8 char but should
           * have a length of 1, when valid.
           */
          if (codepoint == 0 && codepoint_length != 1)
            {
              croak ("Problem in r->read_string(): invalid UTF8 character");
            }
        }
      else
        {
          codepoint = (UV) input[OFFSET_IN_INPUT (slr)];
          codepoint_length = 1;
        }

      if (codepoint < Dim (slr->slg->per_codepoint_array))
        {
          ops = slr->slg->per_codepoint_array[codepoint];
          if (!ops)
            {
              slr->codepoint = codepoint;
              return U_READ_UNREGISTERED_CHAR;
            }
        }
      else
        {
          STRLEN dummy;
          SV **p_ops_sv =
            hv_fetch (slr->slg->per_codepoint_hash, (char *) &codepoint,
                      (I32) sizeof (codepoint), 0);
          if (!p_ops_sv)
            {
              slr->codepoint = codepoint;
              return U_READ_UNREGISTERED_CHAR;
            }
          ops = (UV *) SvPV (*p_ops_sv, dummy);
        }

if (trace_lexers >= 1)
  {
    union marpa_slr_event_s *event = marpa_slr_event_push(slr);
    MARPA_SLREV_TYPE(event) = MARPA_SLRTR_CODEPOINT_READ;
    event->t_trace_codepoint_read.t_codepoint = codepoint;
    event->t_trace_codepoint_read.t_perl_pos = slr->perl_pos;
  }

      /* ops[0] is codepoint */
      op_count = ops[1];
      for (op_ix = 2; op_ix < op_count; op_ix++)
        {
          const UV op_code = ops[op_ix];
          switch (op_code)
            {
            case MARPA_OP_ALTERNATIVE:
              {
                int result;
                int symbol_id;
                int length;
                int value;

                op_ix++;
                if (op_ix >= op_count)
                  {
                    croak
                      ("Missing operand for op code (0x%lx); codepoint=0x%lx, op_ix=0x%lx",
                       (unsigned long) op_code, (unsigned long) codepoint,
                       (unsigned long) op_ix);
                  }
                symbol_id = (int) ops[op_ix];
                if (op_ix + 2 >= op_count)
                  {
                    croak
                      ("Missing operand for op code (0x%lx); codepoint=0x%lx, op_ix=0x%lx",
                       (unsigned long) op_code, (unsigned long) codepoint,
                       (unsigned long) op_ix);
                  }
                value = (int) ops[++op_ix];
                length = (int) ops[++op_ix];
                result = marpa_r_alternative (r, symbol_id, value, length);
                switch (result)
                  {
                  case MARPA_ERR_UNEXPECTED_TOKEN_ID:
                    /* This guarantees that later, if we fall below
                     * the minimum number of tokens accepted,
                     * we have one of them as an example
                     */
                    slr->input_symbol_id = symbol_id;
                    if (trace_lexers >= 1)
                      {
                        union marpa_slr_event_s *slr_event = marpa_slr_event_push(slr);
                        MARPA_SLREV_TYPE(slr_event) = MARPA_SLRTR_CODEPOINT_REJECTED;
                        slr_event->t_trace_codepoint_rejected.t_codepoint = codepoint;
                        slr_event->t_trace_codepoint_rejected.t_perl_pos = slr->perl_pos;
                        slr_event->t_trace_codepoint_rejected.t_symbol_id = symbol_id;
                      }
                    break;
                  case MARPA_ERR_NONE:
                    if (trace_lexers >= 1)
                      {
                        union marpa_slr_event_s *slr_event = marpa_slr_event_push(slr);
                        MARPA_SLREV_TYPE(slr_event) = MARPA_SLRTR_CODEPOINT_ACCEPTED;
                        slr_event->t_trace_codepoint_accepted.t_codepoint = codepoint;
                        slr_event->t_trace_codepoint_accepted.t_perl_pos = slr->perl_pos;
                        slr_event->t_trace_codepoint_accepted.t_symbol_id = symbol_id;
                      }
                    tokens_accepted++;
                    break;
                  default:
                    slr->codepoint = codepoint;
                    slr->input_symbol_id = symbol_id;
                    croak
                      ("Problem alternative() failed at char ix %ld; symbol id %ld; codepoint 0x%lx value %ld\n"
                       "Problem in u_read(), alternative() failed: %s",
                       (long) slr->perl_pos, (long) symbol_id,
                       (unsigned long) codepoint,
                       (long) value,
                       xs_g_error (slr->slg->l0_wrapper));
                  }
              }
              break;

            case MARPA_OP_INVALID_CHAR:
              slr->codepoint = codepoint;
              return U_READ_INVALID_CHAR;

            case MARPA_OP_EARLEME_COMPLETE:
              {
                int result;
                if (tokens_accepted < 1)
                  {
                    slr->codepoint = codepoint;
                    return U_READ_REJECTED_CHAR;
                  }
                result = marpa_r_earleme_complete (r);
                if (result > 0)
                  {
                    u_convert_events (slr);
                    /* Advance one character before returning */
                    if (marpa_r_is_exhausted (r))
                      {
                        return U_READ_EXHAUSTED_ON_SUCCESS;
                      }
                    goto ADVANCE_ONE_CHAR;
                  }
                if (result == -2)
                  {
                    const int error =
                      marpa_g_error (slr->slg->l0_wrapper->g, NULL);
                    if (error == MARPA_ERR_PARSE_EXHAUSTED)
                      {
                        return U_READ_EXHAUSTED_ON_FAILURE;
                      }
                  }
                if (result < 0)
                  {
                    croak
                      ("Problem in r->u_read(), earleme_complete() failed: %s",
                       xs_g_error (slr->slg->l0_wrapper));
                  }
              }
              break;
            default:
              croak ("Unknown op code (0x%lx); codepoint=0x%lx, op_ix=0x%lx",
                     (unsigned long) op_code, (unsigned long) codepoint,
                     (unsigned long) op_ix);
            }
        }
    ADVANCE_ONE_CHAR:;
      slr->perl_pos++;
      if (trace_lexers)
        {
          return U_READ_TRACING;
        }
    }
  return U_READ_OK;
}

/* It is OK to set pos to last codepoint + 1 */
static void
u_pos_set (Scanless_R * slr, const char* name, int start_pos_arg, int length_arg)
{
  dTHX;
  const int input_length = slr->pos_db_logical_size;
  int new_perl_pos;
  int new_end_pos;

  if (start_pos_arg < 0) {
      new_perl_pos = input_length + start_pos_arg;
  } else {
      new_perl_pos = start_pos_arg;
  }
  if (new_perl_pos < 0 || new_perl_pos > slr->pos_db_logical_size)
  {
      croak ("Bad start position in %s(): %ld", name, (long)start_pos_arg);
  }

  if (length_arg < 0) {
      new_end_pos = input_length + length_arg + 1;
  } else {
    new_end_pos = new_perl_pos + length_arg;
  }
  if (new_end_pos < 0 || new_end_pos > slr->pos_db_logical_size)
  {
      croak ("Bad length in %s(): %ld", name, (long)length_arg);
  }

  /* Application level intervention resets |perl_pos| */
  slr->last_perl_pos = -1;
  new_perl_pos = new_perl_pos;
  slr->perl_pos = new_perl_pos;
  new_end_pos = new_end_pos;
  slr->end_pos = new_end_pos;
}

static SV *
u_pos_span_to_literal_sv (Scanless_R * slr,
                          int start_pos, int length_in_positions)
{
  dTHX;
  STRLEN dummy;
  char *input = SvPV (slr->input, dummy);
  SV* new_sv;
  size_t start_offset = POS_TO_OFFSET (slr, start_pos);
  const STRLEN length_in_bytes =
    POS_TO_OFFSET (slr,
                   start_pos + length_in_positions) - start_offset;
  new_sv = newSVpvn (input + start_offset, length_in_bytes);
  if (SvUTF8(slr->input)) {
     SvUTF8_on(new_sv);
  }
  return new_sv;
}

static SV*
u_substring (Scanless_R * slr, const char *name, int start_pos_arg,
             int length_arg)
{
  dTHX;
  int start_pos;
  int end_pos;
  const int input_length = slr->pos_db_logical_size;
  int substring_length;

  start_pos =
    start_pos_arg < 0 ? input_length + start_pos_arg : start_pos_arg;
  if (start_pos < 0 || start_pos > input_length)
    {
      croak ("Bad start position in %s: %ld", name, (long) start_pos_arg);
    }

  end_pos =
    length_arg < 0 ? input_length + length_arg + 1 : start_pos + length_arg;
  if (end_pos < 0 || end_pos > input_length)
    {
      croak ("Bad length in %s: %ld", name, (long) length_arg);
    }
  substring_length = end_pos - start_pos;
  return u_pos_span_to_literal_sv (slr, start_pos, substring_length);
}

/* Static valuator methods */

static int
v_do_stack_ops (V_Wrapper * v_wrapper, SV ** stack_results)
{
    dTHX;
    AV *stack = v_wrapper->stack;
    const Marpa_Value v = v_wrapper->v;
    Scanless_R *const slr = v_wrapper->slr;
    const Marpa_Step_Type step_type = marpa_v_step_type (v);
    UV result_ix = (UV)marpa_v_result (v);
    UV *ops = NULL;
    UV op_ix;
    UV blessing = 0;

    /* Initializations are to silence GCC warnings --
     * if these values appear to the user, there is
     * an internal error. Note that
     * zero is never an acceptable Lua index.
     */
    const char *semantics_table = "!no such semantics table!";
    const char *semantics_type = "!no such semantic type!";
    int semantics_ix = 0;

    lua_State *const L = slr->L;

    /* Create a new array, and a mortal reference to it.
     * The reference, and therefore the array will be garbage collected
     * automatically, unless we de-mortalize the reference.
     */
    AV *values_av = newAV ();
    SV *ref_to_values_av = sv_2mortal (newRV_noinc ((SV *) values_av));
    const char *const step_type_as_string =
        step_type_to_string (step_type);

    v_wrapper->result = (int)result_ix;
  /* warn("%s %d", __FILE__, __LINE__); */

switch (step_type) {
    STRLEN dummy;
case MARPA_STEP_RULE:
    {
        SV **p_ops_sv =
            av_fetch (v_wrapper->rule_semantics, marpa_v_rule (v), 0);
  /* warn("%s %d", __FILE__, __LINE__); */
        if (p_ops_sv) {
  /* warn("%s %d", __FILE__, __LINE__); */
            ops = (UV *) SvPV (*p_ops_sv, dummy);
        }
    }
    break;
case MARPA_STEP_TOKEN:
    {
        SV **p_ops_sv =
            av_fetch (v_wrapper->token_semantics, marpa_v_token (v),
            0);
  /* warn("%s %d", __FILE__, __LINE__); */
        if (p_ops_sv) {
  /* warn("%s %d", __FILE__, __LINE__); */
            ops = (UV *) SvPV (*p_ops_sv, dummy);
        }
    }
    break;
case MARPA_STEP_NULLING_SYMBOL:
    {
        SV **p_ops_sv =
            av_fetch (v_wrapper->nulling_semantics, marpa_v_token (v),
            0);
  /* warn("%s %d", __FILE__, __LINE__); */
        if (p_ops_sv) {
  /* warn("%s %d", __FILE__, __LINE__); */
            ops = (UV *) SvPV (*p_ops_sv, dummy);
        }
    }
    break;
default:
    croak ("Internal error: unknown step type %d", step_type);
}

    if (!ops) {
        int base_of_stack;
        Xlua_Array* ops_ud;
  /* warn("%s %d", __FILE__, __LINE__); */

        switch (step_type) {
        case MARPA_STEP_RULE:
  /* warn("%s %d", __FILE__, __LINE__); */
            semantics_table = "rule_semantics";
            semantics_type = "rule";
            semantics_ix = marpa_v_rule (v);
            break;
        case MARPA_STEP_TOKEN:
  /* warn("%s %d", __FILE__, __LINE__); */
            semantics_table = "token_semantics";
            semantics_type = "token";
            semantics_ix = marpa_v_token (v);
            break;
        case MARPA_STEP_NULLING_SYMBOL:
  /* warn("%s %d", __FILE__, __LINE__); */
            semantics_table = "nulling_semantics";
            semantics_type = "nulling symbol";
            semantics_ix = marpa_v_token (v);
            break;
        default:
  /* warn("%s %d", __FILE__, __LINE__); */
            /* Never reached -- turns off warning about uninitialized ops */
            ops = NULL;
        }

  /* warn("%s %d", __FILE__, __LINE__); */
        base_of_stack = marpa_lua_gettop(L);
        /* Lua stack: [] */
        marpa_lua_rawgeti (L, LUA_REGISTRYINDEX, slr->lua_ref);
        /* Lua stack: [ recce_table ] */
        /* warn("%s %d", __FILE__, __LINE__); */
        /* Lua stack: [ recce_table, ] */
        marpa_lua_getfield(L, -1, semantics_table);
        /* warn("%s %d", __FILE__, __LINE__); */
        /* Lua stack: [ recce_table, semantics_table ] */
         marpa_lua_geti (L, -1, semantics_ix);
        /* warn("%s %d", __FILE__, __LINE__); */
        /* Lua stack: [ recce_table, semantics_table, ops_ud ] */
        ops_ud = (struct Xlua_Array*)marpa_lua_touserdata(L, -1);
        /* warn("%s %d", __FILE__, __LINE__); */
        if (!ops_ud) {
          marpa_lua_pop(L, 1);
  /* warn("Default for %s semantics kicking in", semantics_type); */
          marpa_lua_getfield (L, -1, "default");
        /* warn("%s %d", __FILE__, __LINE__); */
          /* Lua stack: [ recce_table, semantics_table, ops_ud ] */
          ops_ud = (Xlua_Array*)marpa_lua_touserdata(L, -1);
        }
        if (!ops_ud) {
                croak
                    ("Problem in v->stack_step: %s %d is not registered",
                    semantics_type, semantics_ix);
        }
        /* warn("%s %d", __FILE__, __LINE__); */
        ops = (UV *) ops_ud->array;
        marpa_lua_settop(L, base_of_stack);
    }

    op_ix = 0;
    while (1) {
        UV op_code = ops[op_ix++];

        xlua_sig_call (slr->L,
            "local recce, tag, op_name = ...;\n"
            "if recce.trace_values >= 3 then\n"
            "  local top_of_queue = #recce.trace_values_queue;\n"
            "  recce.trace_values_queue[top_of_queue+1] = {tag, recce.v.step.type, op_name};\n"
            "  -- io.stderr:write('starting op: ', inspect(recce))\n"
            "end",
            "Rss",
            slr->lua_ref,
            "starting op", marpa_slif_op_name (op_code)
            );

        switch (op_code) {

        case 0:
            return -1;

        case MARPA_OP_LUA:
            {
                lua_Debug ar;
                int argc;
                int status;
                const int base_of_stack = marpa_lua_gettop (L);
                const UV fn_key = ops[op_ix++];

  /* warn ("Executing MARPA_OP_LUA, fn_key = %d", fn_key); */

                marpa_lua_rawgeti (L, LUA_REGISTRYINDEX, slr->lua_ref);
                /* Lua stack: [ recce_table ] */
                marpa_lua_rawgeti (L, -1, fn_key);
                /* [ recce_table, function ] */

  /* warn ("Executing MARPA_OP_LUA, fn_key = %d", fn_key); */

                marpa_lua_pushvalue(L, -1);
                marpa_lua_getinfo(L, ">S", &ar);
  /* warn("Executing Lua code: %s", ar.source); */

                /* The recce table itself is an argument */
                marpa_lua_pushvalue (L, -2);
                marpa_lua_pushstring (L, step_type_as_string);
                argc = 2;
                switch (step_type) {
                case MARPA_STEP_RULE:
                    marpa_lua_pushinteger (L, result_ix);
                    marpa_lua_pushinteger (L, marpa_v_rule (v));
                    marpa_lua_pushinteger (L, marpa_v_arg_n (v));
                    argc += 3;
                    break;
                case MARPA_STEP_TOKEN:
                    marpa_lua_pushinteger (L, result_ix);
                    marpa_lua_pushinteger (L, marpa_v_token (v));
                    marpa_lua_pushinteger (L, marpa_v_token_value (v));
                    argc += 3;
                    break;
                case MARPA_STEP_NULLING_SYMBOL:
                    marpa_lua_pushinteger (L, result_ix);
                    marpa_lua_pushinteger (L, marpa_v_symbol (v));
                    argc += 2;
                    break;
                default:
                    break;
                }
  /* warn ("%s %d\n", __FILE__, __LINE__); */

                status = marpa_lua_pcall (L, argc, LUA_MULTRET, 0);

  /* warn ("%s %d\n", __FILE__, __LINE__); */

                if (status != 0) {
                    const char *error_string = marpa_lua_tostring (L, -1);
                    /* error_string must be copied before it is exposed to Lua GC */
                    const char *croak_msg = form("Marpa::R3 Lua code error: %s", error_string);
                    marpa_lua_settop (L, base_of_stack);
                    croak (croak_msg);
                }

  /* warn ("%s %d\n", __FILE__, __LINE__); */

                marpa_lua_settop (L, base_of_stack);
                goto NEXT_OP_CODE;
            }

        case MARPA_OP_RESULT_IS_CONSTANT:
            {
                UV constant_ix = ops[op_ix++];
                SV **p_constant_sv;

                p_constant_sv =
                    av_fetch (v_wrapper->constants, (I32)constant_ix, 0);
       if (p_constant_sv) {
                    SV *constant_sv = newSVsv (*p_constant_sv);
                    SV **stored_sv =
                        av_store (stack, (I32)result_ix, constant_sv);
                    if (!stored_sv) {
                        SvREFCNT_dec (constant_sv);
                    }
                } else {
                    av_store (stack, (I32)result_ix, newSV (0));
                }

        xlua_sig_call (slr->L,
            "local recce, tag, token_sv = ...;\n"
            "if recce.trace_values > 0 and recce.v.step.type == 'MARPA_STEP_TYPE' then\n"
            "  local top_of_queue = #recce.trace_values_queue;\n"
            "  recce.trace_values_queue[top_of_queue+1] =\n"
            "     {tag, recce.v.step.type, recce.token, token_sv};\n"
            "  -- io.stderr:write('valuator unknown step: ', inspect(recce))\n"
            "end",
            "RsS",
            slr->lua_ref,
            "valuator unknown step",
            (p_constant_sv ? newSVsv(*p_constant_sv) : newSV(0))
            );

            }
            return -1;

        case MARPA_OP_RESULT_IS_RHS_N:
        case MARPA_OP_RESULT_IS_N_OF_SEQUENCE:
            {
                SV **stored_av;
                SV **p_sv;
                UV stack_offset = ops[op_ix++];
                UV fetch_ix;

                if (step_type != MARPA_STEP_RULE) {
                    av_fill (stack, (I32)result_ix - 1);
                    return -1;
                }
                if (stack_offset == 0) {
                    /* Special-cased for 4 reasons --
                     * it's common, it's reference count handling is
                     * a special case and it can be easily and highly optimized.
                     */
                    av_fill (stack, (I32)result_ix);
                    return -1;
                }

                /* Determine index of SV to fetch */
                if (op_code == MARPA_OP_RESULT_IS_RHS_N) {
                    fetch_ix = result_ix + stack_offset;
                } else {        /* sequence */
                    const UV item_ix = stack_offset;
                    fetch_ix = result_ix + item_ix * 2;
                }

                /* Bounds check fetch ix */
                if (fetch_ix > (UV)marpa_v_arg_n (v) || fetch_ix < result_ix) {
                    /* return an undef */
                    av_fill (stack, (I32)result_ix - 1);
                    return -1;
                }
                p_sv = av_fetch (stack, (I32)fetch_ix, 0);
                if (!p_sv) {
                    av_fill (stack, (I32)result_ix - 1);
                    return -1;
                }
                stored_av =
                    av_store (stack, (I32)result_ix, SvREFCNT_inc_NN (*p_sv));
                if (!stored_av) {
                    SvREFCNT_dec (*p_sv);
                    av_fill (stack, (I32)result_ix - 1);
                    return -1;
                }
                av_fill (stack, (I32)result_ix);
            }
            return -1;

        case MARPA_OP_RESULT_IS_ARRAY:
            {
                SV **stored_av;

                if (blessing) {
                    SV **p_blessing_sv =
                        av_fetch (v_wrapper->constants, (I32)blessing, 0);
                    if (p_blessing_sv && SvPOK (*p_blessing_sv)) {
                        STRLEN blessing_length;
                        char *classname =
                            SvPV (*p_blessing_sv, blessing_length);
                        sv_bless (ref_to_values_av, gv_stashpv (classname,
                                1));
                    }
                }
                /* De-mortalize the reference to values_av */
                SvREFCNT_inc_simple_void_NN (ref_to_values_av);
                stored_av = av_store (stack, (I32)result_ix, ref_to_values_av);

                /* If the new RV did not get stored properly,
                 * decrement its ref count to re-mortalize it.
                 */
                if (!stored_av) {
                    SvREFCNT_dec (ref_to_values_av);
                    av_fill (stack, (I32)result_ix - 1);
                    return -1;
                }
                av_fill (stack, (I32)result_ix);
            }
            return -1;

        case MARPA_OP_PUSH_VALUES:
        case MARPA_OP_PUSH_SEQUENCE:
            {
                switch (step_type) {
                case MARPA_STEP_TOKEN:
                    {
                        SV **p_token_value_sv;
                        int token_ix = marpa_v_token_value (v);
                        if (slr && token_ix == TOKEN_VALUE_IS_LITERAL) {
                            SV *sv;
                            Marpa_Earley_Set_ID start_earley_set =
                                marpa_v_token_start_es_id (v);
                            Marpa_Earley_Set_ID end_earley_set =
                                marpa_v_es_id (v);
                            sv = slr_es_span_to_literal_sv (slr,
                                start_earley_set,
                                end_earley_set - start_earley_set);
                            av_push (values_av, sv);
                            break;
                        }
                        /* If token value is NOT literal */
                        p_token_value_sv =
                            av_fetch (slr->token_values, (I32) token_ix,
                            0);
                        if (p_token_value_sv) {
                            av_push (values_av,
                                SvREFCNT_inc_NN (*p_token_value_sv));
                        } else {
                            av_push (values_av, newSV (0));
                        }
                    }
                    break;

                case MARPA_STEP_RULE:
                    {
                        UV stack_ix;
                        const int arg_n = marpa_v_arg_n (v);
                        UV increment =
                            op_code == MARPA_OP_PUSH_SEQUENCE ? 2 : 1;

                        for (stack_ix = result_ix; stack_ix <= (UV)arg_n;
                            stack_ix += increment) {
                            SV **p_sv = av_fetch (stack, (I32)stack_ix, 0);
                            if (!p_sv) {
                                av_push (values_av, newSV (0));
                            } else {
                                av_push (values_av,
                                    SvREFCNT_inc_simple_NN (*p_sv));
                            }
                        }
                    }
                    break;

                default:
                case MARPA_STEP_NULLING_SYMBOL:
                    /* A no-op : push nothing */
                    break;
                }
            }
            break;

        case MARPA_OP_PUSH_UNDEF:
            av_push (values_av, newSV (0));
            goto NEXT_OP_CODE;

        case MARPA_OP_PUSH_CONSTANT:
            {
                UV constant_ix = ops[op_ix++];
                SV **p_constant_sv;

                p_constant_sv =
                    av_fetch (v_wrapper->constants, (I32)constant_ix, 0);
                if (p_constant_sv) {
                    av_push (values_av,
                        SvREFCNT_inc_simple_NN (*p_constant_sv));
                } else {
                    av_push (values_av, newSV (0));
                }

            }
            goto NEXT_OP_CODE;

        case MARPA_OP_PUSH_ONE:
            {
                UV offset;
                SV **p_sv;

                offset = ops[op_ix++];
                if (step_type != MARPA_STEP_RULE) {
                    av_push (values_av, newSV (0));
                    goto NEXT_OP_CODE;
                }
                p_sv = av_fetch (stack, (I32)(result_ix + offset), 0);
                if (!p_sv) {
                    av_push (values_av, newSV (0));
                } else {
                    av_push (values_av, SvREFCNT_inc_simple_NN (*p_sv));
                }
            }
            goto NEXT_OP_CODE;

        case MARPA_OP_PUSH_START_LOCATION:
            {
                int start_location;
                Marpa_Earley_Set_ID start_earley_set;
                int dummy;

                switch (step_type) {
                case MARPA_STEP_RULE:
                    start_earley_set = marpa_v_rule_start_es_id (v);
                    break;
                case MARPA_STEP_NULLING_SYMBOL:
                case MARPA_STEP_TOKEN:
                    start_earley_set = marpa_v_token_start_es_id (v);
                    break;
                default:
                    croak
                        ("Problem in v->stack_step: Range requested for improper step type: %s",
                        step_type_to_string (step_type));
                }
                slr_es_to_literal_span (slr, start_earley_set, 0,
                    &start_location, &dummy);
                av_push (values_av, newSViv ((IV) start_location));
            }
            goto NEXT_OP_CODE;

        case MARPA_OP_PUSH_LENGTH:
            {
                int length;

                switch (step_type) {
                case MARPA_STEP_NULLING_SYMBOL:
                    length = 0;
                    break;
                case MARPA_STEP_RULE:
                    {
                        int dummy;
                        Marpa_Earley_Set_ID start_earley_set =
                            marpa_v_rule_start_es_id (v);
                        Marpa_Earley_Set_ID end_earley_set =
                            marpa_v_es_id (v);
                        slr_es_to_literal_span (slr, start_earley_set,
                            end_earley_set - start_earley_set, &dummy,
                            &length);
                    }
                    break;
                case MARPA_STEP_TOKEN:
                    {
                        int dummy;
                        Marpa_Earley_Set_ID start_earley_set =
                            marpa_v_token_start_es_id (v);
                        Marpa_Earley_Set_ID end_earley_set =
                            marpa_v_es_id (v);
                        slr_es_to_literal_span (slr, start_earley_set,
                            end_earley_set - start_earley_set, &dummy,
                            &length);
                    }
                    break;
                default:
                    croak
                        ("Problem in v->stack_step: Range requested for improper step type: %s",
                        step_type_to_string (step_type));
                }
                av_push (values_av, newSViv ((IV) length));
            }
            goto NEXT_OP_CODE;

        case MARPA_OP_PUSH_G1_START:
            {
                Marpa_Earley_Set_ID start_earley_set;

                switch (step_type) {
                case MARPA_STEP_RULE:
                    start_earley_set = marpa_v_rule_start_es_id (v);
                    break;
                case MARPA_STEP_NULLING_SYMBOL:
                case MARPA_STEP_TOKEN:
                    start_earley_set = marpa_v_token_start_es_id (v);
                    break;
                default:
                    croak
                        ("Problem in v->stack_step: Range requested for improper step type: %s",
                        step_type_as_string);
                }
                av_push (values_av, newSViv ((IV) start_earley_set));
            }
            goto NEXT_OP_CODE;

        case MARPA_OP_PUSH_G1_LENGTH:
            {
                int length;

                switch (step_type) {
                case MARPA_STEP_NULLING_SYMBOL:
                    length = 0;
                    break;
                case MARPA_STEP_RULE:
                    {
                        Marpa_Earley_Set_ID start_earley_set =
                            marpa_v_rule_start_es_id (v);
                        Marpa_Earley_Set_ID end_earley_set =
                            marpa_v_es_id (v);
                        length = end_earley_set - start_earley_set + 1;
                    }
                    break;
                case MARPA_STEP_TOKEN:
                    {
                        Marpa_Earley_Set_ID start_earley_set =
                            marpa_v_token_start_es_id (v);
                        Marpa_Earley_Set_ID end_earley_set =
                            marpa_v_es_id (v);
                        length = end_earley_set - start_earley_set + 1;
                    }
                    break;
                default:
                    croak
                        ("Problem in v->stack_step: Range requested for improper step type: %s",
                        step_type_as_string);
                }
                av_push (values_av, newSViv ((IV) length));
            }
            goto NEXT_OP_CODE;

        case MARPA_OP_BLESS:
            {
                blessing = ops[op_ix++];
            }
            goto NEXT_OP_CODE;

        case MARPA_OP_CALLBACK:
            {
                SV **p_stack_results = stack_results;

                switch (step_type) {
                case MARPA_STEP_RULE:
                case MARPA_STEP_NULLING_SYMBOL:
                    break;
                default:
                    goto BAD_OP;
                }

                *p_stack_results++ =
                    sv_2mortal (newSVpv (step_type_as_string, 0));
                *p_stack_results++ =
                    sv_2mortal (newSViv (step_type ==
                        MARPA_STEP_RULE ? marpa_v_rule (v) :
                        marpa_v_token (v)));

                if (blessing) {
                    SV **p_blessing_sv =
                        av_fetch (v_wrapper->constants, (I32)blessing, 0);
                    if (p_blessing_sv && SvPOK (*p_blessing_sv)) {
                        STRLEN blessing_length;
                        char *classname =
                            SvPV (*p_blessing_sv, blessing_length);
                        sv_bless (ref_to_values_av, gv_stashpv (classname,
                                1));
                    }
                }
                /* ref_to_values_av is already mortal -- leave it */
                *p_stack_results++ = ref_to_values_av;
                return p_stack_results - stack_results;
            }
            /* NOT REACHED */

        case MARPA_OP_RESULT_IS_TOKEN_VALUE:
            {
                int token_ix = marpa_v_token_value (v);

                if (step_type != MARPA_STEP_TOKEN) {
                    av_fill (stack, (I32)result_ix - 1);
                    return -1;
                }
                if (slr && token_ix == TOKEN_VALUE_IS_LITERAL) {
                    SV **stored_sv;
                    SV *token_literal_sv;
                    Marpa_Earley_Set_ID start_earley_set =
                        marpa_v_token_start_es_id (v);
                    Marpa_Earley_Set_ID end_earley_set = marpa_v_es_id (v);
                    token_literal_sv =
                        slr_es_span_to_literal_sv (slr, start_earley_set,
                        end_earley_set - start_earley_set);
                    stored_sv =
                        av_store (stack, (I32)result_ix, token_literal_sv);
                    if (!stored_sv) {
                        SvREFCNT_dec (token_literal_sv);
                    }
                    return -1;
                }

        xlua_sig_call (slr->L,
            "-- case MARPA_OP_RESULT_IS_TOKEN_VALUE:\n"
            "local recce = ...;\n"
            "local stack = recce:stack()\n"
            "local result_ix = recce.v.step.result\n"
            "stack[result_ix] = recce.token_values[recce.v.step.value]\n"
            "marpa.sv.fill(stack, result_ix)\n"
            "if recce.trace_values > 0 then\n"
            "  local top_of_queue = #recce.trace_values_queue;\n"
            "  recce.trace_values_queue[top_of_queue+1] =\n"
            "     {tag, recce.v.step.type, recce.v.step.token, recce.v.step.value, token_sv};\n"
            "  -- io.stderr:write('[step_type]: ', inspect(recce))\n"
            "end",
            "R",
            slr->lua_ref
            );


            }
            return -1;

        default:
          BAD_OP:
            {
                croak
                    ("Bad op code (%lu, '%s') in v->stack_step, step_type '%s'",
                    (unsigned long) op_code, marpa_slif_op_name (op_code),
                    step_type_as_string);
            }
        }

      NEXT_OP_CODE:;           /* continue while(1) loop */

    }

    /* Never reached */
    return -1;
}

/* Static SLG methods */

#define SET_SLG_FROM_SLG_SV(slg, slg_sv) { \
    IV tmp = SvIV ((SV *) SvRV (slg_sv)); \
    (slg) = INT2PTR (Scanless_G *, tmp); \
}

/* Static SLR methods */


/*
 * Try to discard lexemes.
 * It is assumed this is because R1 is exhausted and we
 * are checking for unconsumed text.
 * Return values:
 * 0 OK.
 * -4: Exhausted, but lexemes remain.
 */
static IV
slr_discard (Scanless_R * slr)
{
  dTHX;
  int lexemes_discarded = 0;
  int lexemes_found = 0;
  Marpa_Recce r0;
  Marpa_Earley_Set_ID earley_set;
  const Scanless_G *slg = slr->slg;

  r0 = slr->r0;
  if (!r0)
    {
      croak ("Problem in slr->read(): No R0 at %s %d", __FILE__, __LINE__);
    }
  earley_set = marpa_r_latest_earley_set (r0);
  /* Zero length lexemes are not of interest, so we do *not*
   * search the 0'th Earley set.
   */
  while (earley_set > 0)
    {
      int return_value;
      const int working_pos = slr->start_of_lexeme + earley_set;
      return_value = marpa_r_progress_report_start (r0, earley_set);
      if (return_value < 0)
        {
          croak ("Problem in marpa_r_progress_report_start(%p, %ld): %s",
                 (void *) r0, (unsigned long) earley_set,
                 xs_g_error (slg->l0_wrapper));
        }
      while (1)
        {
          Marpa_Symbol_ID g1_lexeme;
          int dot_position;
          Marpa_Earley_Set_ID origin;
          Marpa_Rule_ID rule_id =
            marpa_r_progress_item (r0, &dot_position, &origin);
          if (rule_id <= -2)
            {
              croak ("Problem in marpa_r_progress_item(): %s",
                     xs_g_error (slg->l0_wrapper));
            }
          if (rule_id == -1)
            goto NO_MORE_REPORT_ITEMS;
          if (origin != 0)
            goto NEXT_REPORT_ITEM;
          if (dot_position != -1)
            goto NEXT_REPORT_ITEM;
          g1_lexeme = slg->l0_rule_g_properties[rule_id].g1_lexeme;
          if (g1_lexeme == -1)
            goto NEXT_REPORT_ITEM;
          lexemes_found++;
          slr->end_of_lexeme = working_pos;

          /* -2 means a discarded item */
          if (g1_lexeme <= -2)
            {
              lexemes_discarded++;
              if (slr->trace_terminals)
                {
                  union marpa_slr_event_s *slr_event =
                    marpa_slr_event_push (slr);
                  MARPA_SLREV_TYPE (slr_event) = MARPA_SLRTR_LEXEME_DISCARDED;

                  /* We do not have the lexeme, but we have the
                   * lexer rule.
                   * The upper level will have to figure things out.
                   */
                  slr_event->t_trace_lexeme_discarded.t_rule_id = rule_id;
                  slr_event->t_trace_lexeme_discarded.t_start_of_lexeme =
                    slr->start_of_lexeme;
                  slr_event->t_trace_lexeme_discarded.t_end_of_lexeme =
                    slr->end_of_lexeme;

                }
              if (slr->l0_rule_r_properties[rule_id].
                  t_event_on_discard_active)
                {
                  union marpa_slr_event_s *new_event;
                  new_event = marpa_slr_event_push (slr);
                  MARPA_SLREV_TYPE (new_event) = MARPA_SLREV_LEXEME_DISCARDED;
                  new_event->t_lexeme_discarded.t_rule_id = rule_id;
                  new_event->t_lexeme_discarded.t_start_of_lexeme =
                    slr->start_of_lexeme;
                  new_event->t_lexeme_discarded.t_end_of_lexeme =
                    slr->end_of_lexeme;
                  new_event->t_lexeme_discarded.t_last_g1_location =
                    marpa_r_latest_earley_set (slr->r1);
                }
              /* If there is discarded item, we are fine,
               * and can return success.
               */
              slr->lexer_start_pos = slr->perl_pos = working_pos;
              return 0;
            }

          /*
           * Ignore everything else.
           * We don't try to read lexemes into an exhausted
           * R1 -- we only are looking for discardable tokens.
           */
          if (slr->trace_terminals)
            {
              union marpa_slr_event_s *slr_event =
                marpa_slr_event_push (slr);
              MARPA_SLREV_TYPE (slr_event) = MARPA_SLRTR_LEXEME_IGNORED;

              slr_event->t_trace_lexeme_ignored.t_lexeme = g1_lexeme;
              slr_event->t_trace_lexeme_ignored.t_start_of_lexeme =
                slr->start_of_lexeme;
              slr_event->t_trace_lexeme_ignored.t_end_of_lexeme =
                slr->end_of_lexeme;
            }
        NEXT_REPORT_ITEM:;
        }
    NO_MORE_REPORT_ITEMS:;
      if (lexemes_found)
        {
          /* We found a lexeme at this location and we are not allowed
           * to discard this input.
           * Return failure.
           */
          slr->perl_pos = slr->problem_pos = slr->lexer_start_pos =
            slr->start_of_lexeme;
          return -4;
        }
      earley_set--;
    }

  /* If we are here we found no lexemes anywhere in the input,
   * and therefore none which can be discarded.
   * Return failure.
   */
  slr->perl_pos = slr->problem_pos = slr->lexer_start_pos =
    slr->start_of_lexeme;
  return -4;
}

/* Assumes it is called
 after a successful marpa_r_earleme_complete().
 At some point it may need optional SLR information,
 at which point I will add a parameter
 */
static void
slr_convert_events (Scanless_R * slr)
{
  dTHX;
  int event_ix;
  Marpa_Grammar g = slr->r1_wrapper->base->g;
  const int event_count = marpa_g_event_count (g);
  for (event_ix = 0; event_ix < event_count; event_ix++)
    {
      Marpa_Event marpa_event;
      Marpa_Event_Type event_type = marpa_g_event (g, &marpa_event, event_ix);
      switch (event_type)
        {
          {
        case MARPA_EVENT_EXHAUSTED:
            /* Do nothing about exhaustion on success */
            break;
        case MARPA_EVENT_SYMBOL_COMPLETED:
            {
              union marpa_slr_event_s *slr_event = marpa_slr_event_push(slr);
                MARPA_SLREV_TYPE(slr_event) = MARPA_SLREV_SYMBOL_COMPLETED;
              slr_event->t_symbol_completed.t_symbol = marpa_g_event_value (&marpa_event);
            }
            break;
        case MARPA_EVENT_SYMBOL_NULLED:
            {
              union marpa_slr_event_s *slr_event = marpa_slr_event_push(slr);
MARPA_SLREV_TYPE(slr_event) =MARPA_SLREV_SYMBOL_NULLED;
              slr_event->t_symbol_nulled.t_symbol = marpa_g_event_value (&marpa_event);
            }
            break;
        case MARPA_EVENT_SYMBOL_PREDICTED:
            {
              union marpa_slr_event_s *slr_event = marpa_slr_event_push(slr);
MARPA_SLREV_TYPE(slr_event) = MARPA_SLREV_SYMBOL_PREDICTED;
              slr_event->t_symbol_predicted.t_symbol = marpa_g_event_value (&marpa_event);
            }
            break;
        case MARPA_EVENT_EARLEY_ITEM_THRESHOLD:
            /* All events are ignored on failure
             * On success, all except MARPA_EVENT_EARLEY_ITEM_THRESHOLD
             * are ignored.
             *
             * The warning raised for MARPA_EVENT_EARLEY_ITEM_THRESHOLD
             * can be turned off by raising
             * the Earley item warning threshold.
             */
            {
              const int yim_count = marpa_g_event_value (&marpa_event);
              union marpa_slr_event_s *event = marpa_slr_event_push (slr);
              MARPA_SLREV_TYPE (event) = MARPA_SLREV_G1_YIM_THRESHOLD_EXCEEDED;
              event->t_g1_yim_threshold_exceeded.t_yim_count = yim_count;
              event->t_g1_yim_threshold_exceeded.t_perl_pos = slr->perl_pos;
            }
            break;
        default:
            {
              union marpa_slr_event_s *slr_event = marpa_slr_event_push(slr);
MARPA_SLREV_TYPE(slr_event) = MARPA_SLREV_MARPA_R_UNKNOWN;
              slr_event->t_marpa_r_unknown.t_event = event_type;
            }
            break;
          }
        }
    }
}

/* Called after marpa_r_start_input() and
 * marpa_r_earleme_complete().
 */
static void
r_convert_events (R_Wrapper * r_wrapper)
{
  dTHX;
  int event_ix;
  Marpa_Grammar g = r_wrapper->base->g;
  const int event_count = marpa_g_event_count (g);
  for (event_ix = 0; event_ix < event_count; event_ix++)
    {
      Marpa_Event marpa_event;
      Marpa_Event_Type event_type =
        marpa_g_event (g, &marpa_event, event_ix);
      switch (event_type)
        {
          {
        case MARPA_EVENT_EXHAUSTED:
            /* Do nothing about exhaustion on success */
            break;
        case MARPA_EVENT_SYMBOL_COMPLETED:
            {
              AV *event;
              SV *event_data[2];
              Marpa_Symbol_ID completed_symbol =
                marpa_g_event_value (&marpa_event);
              event_data[0] = newSVpvs ("symbol completed");
              event_data[1] = newSViv (completed_symbol);
              event = av_make (Dim (event_data), event_data);
              av_push (r_wrapper->event_queue, newRV_noinc ((SV *) event));
            }
            break;
        case MARPA_EVENT_SYMBOL_NULLED:
            {
              AV *event;
              SV *event_data[2];
              Marpa_Symbol_ID nulled_symbol =
                marpa_g_event_value (&marpa_event);
              event_data[0] = newSVpvs ("symbol nulled");
              event_data[1] = newSViv (nulled_symbol);
              event = av_make (Dim (event_data), event_data);
              av_push (r_wrapper->event_queue, newRV_noinc ((SV *) event));
            }
            break;
        case MARPA_EVENT_SYMBOL_PREDICTED:
            {
              AV *event;
              SV *event_data[2];
              Marpa_Symbol_ID predicted_symbol =
                marpa_g_event_value (&marpa_event);
              event_data[0] = newSVpvs ("symbol predicted");
              event_data[1] = newSViv (predicted_symbol);
              event = av_make (Dim (event_data), event_data);
              av_push (r_wrapper->event_queue, newRV_noinc ((SV *) event));
            }
            break;
        case MARPA_EVENT_EARLEY_ITEM_THRESHOLD:
            /* All events are ignored on faiulre
             * On success, all except MARPA_EVENT_EARLEY_ITEM_THRESHOLD
             * are ignored.
             *
             * The warning raised for MARPA_EVENT_EARLEY_ITEM_THRESHOLD
             * can be turned off by raising
             * the Earley item warning threshold.
             */
            {
              warn
                ("Marpa: Scanless G1 Earley item count (%ld) exceeds warning threshold",
                 (long) marpa_g_event_value (&marpa_event));
            }
            break;
        default:
            {
              AV *event;
              const char *result_string = event_type_to_string (event_type);
              SV *event_data[2];
              event_data[0] = newSVpvs ("unknown event");
              if (!result_string)
                {
                  result_string =
                    form ("event(%d): unknown event code, %d", event_ix,
                          event_type);
                }
              event_data[1] = newSVpv (result_string, 0);
              event = av_make (Dim (event_data), event_data);
              av_push (r_wrapper->event_queue, newRV_noinc ((SV *) event));
            }
            break;
          }
        }
    }
}

/*
 * Return values:
 * NULL OK.
 * Otherwise, a string containing the error.
 * The string must be a constant in static space.
 */
static const char *
slr_alternatives (Scanless_R * slr)
{
  dTHX;
  Marpa_Recce r0;
  Marpa_Recce r1 = slr->r1;
  Marpa_Earley_Set_ID earley_set;
  const Scanless_G *slg = slr->slg;

  /* |high_lexeme_priority| is not valid unless |is_priority_set| is set. */
  int is_priority_set = 0;
  int high_lexeme_priority = 0;

  int discarded = 0;
  int rejected = 0;
  int working_pos = slr->start_of_lexeme;
  enum pass1_result_type { none, discard, no_lexeme, accept };
  enum pass1_result_type pass1_result = none;

  r0 = slr->r0;
  if (!r0)
    {
      croak ("Problem in slr->read(): No R0 at %s %d", __FILE__, __LINE__);
    }

  marpa_slr_lexeme_clear (slr);

  /* Zero length lexemes are not of interest, so we do NOT
   * search the 0'th Earley set.
   */
  for (earley_set = marpa_r_latest_earley_set (r0); earley_set > 0;
       earley_set--)
    {
      int return_value;
      int end_of_earley_items = 0;
      working_pos = slr->start_of_lexeme + earley_set;

      return_value = marpa_r_progress_report_start (r0, earley_set);
      if (return_value < 0)
        {
          croak ("Problem in marpa_r_progress_report_start(%p, %ld): %s",
                 (void *) r0, (unsigned long) earley_set,
                 xs_g_error (slr->slg->l0_wrapper));
        }

      while (!end_of_earley_items)
        {
          struct symbol_g_properties *symbol_g_properties;
          struct l0_rule_g_properties *l0_rule_g_properties;
          struct symbol_r_properties *symbol_r_properties;
          Marpa_Symbol_ID g1_lexeme;
          int this_lexeme_priority;
          int is_expected;
          int dot_position;
          Marpa_Earley_Set_ID origin;
          Marpa_Rule_ID rule_id =
            marpa_r_progress_item (r0, &dot_position, &origin);
          if (rule_id <= -2)
            {
              croak ("Problem in marpa_r_progress_item(): %s",
                     xs_g_error (slr->slg->l0_wrapper));
            }
          if (rule_id == -1)
            {
              end_of_earley_items = 1;
              goto NEXT_PASS1_REPORT_ITEM;
            }
          if (origin != 0)
            goto NEXT_PASS1_REPORT_ITEM;
          if (dot_position != -1)
            goto NEXT_PASS1_REPORT_ITEM;
          l0_rule_g_properties = slg->l0_rule_g_properties + rule_id;
          g1_lexeme = l0_rule_g_properties->g1_lexeme;
          if (g1_lexeme == -1)
            goto NEXT_PASS1_REPORT_ITEM;
          slr->end_of_lexeme = working_pos;
          /* -2 means a discarded item */
          if (g1_lexeme <= -2)
            {
              union marpa_slr_event_s *lexeme_entry =
                marpa_slr_lexeme_push (slr);
              MARPA_SLREV_TYPE (lexeme_entry) = MARPA_SLRTR_LEXEME_DISCARDED;
              lexeme_entry->t_trace_lexeme_discarded.t_rule_id = rule_id;
              lexeme_entry->t_trace_lexeme_discarded.t_start_of_lexeme =
                slr->start_of_lexeme;
              lexeme_entry->t_trace_lexeme_discarded.t_end_of_lexeme =
                slr->end_of_lexeme;
              discarded++;

              goto NEXT_PASS1_REPORT_ITEM;
            }
          symbol_g_properties = slg->symbol_g_properties + g1_lexeme;
          l0_rule_g_properties = slg->l0_rule_g_properties + rule_id;
          symbol_r_properties = slr->symbol_r_properties + g1_lexeme;
          is_expected = marpa_r_terminal_is_expected (r1, g1_lexeme);
          if (!is_expected)
            {
              union marpa_slr_event_s *lexeme_entry =
                marpa_slr_lexeme_push (slr);
              if (symbol_g_properties->latm)
                {
                  croak
                    ("Internal error: Marpa recognized unexpected token @%ld-%ld: lexeme=%ld",
                     (long) slr->start_of_lexeme, (long) slr->end_of_lexeme,
                     (long) g1_lexeme);
                }
              else
                {
                  MARPA_SLREV_TYPE (lexeme_entry) =
                    MARPA_SLRTR_LEXEME_REJECTED;
                  lexeme_entry->t_trace_lexeme_rejected.t_start_of_lexeme =
                    slr->start_of_lexeme;
                  lexeme_entry->t_trace_lexeme_rejected.t_end_of_lexeme =
                    slr->end_of_lexeme;
                  lexeme_entry->t_trace_lexeme_rejected.t_lexeme = g1_lexeme;
                  rejected++;
                }
              goto NEXT_PASS1_REPORT_ITEM;
            }

          /* If we are here, the lexeme will be accepted  by the grammar,
           * but we do not yet know about priority
           */

          this_lexeme_priority = symbol_r_properties->lexeme_priority;
          if (!is_priority_set || this_lexeme_priority > high_lexeme_priority)
            {
              high_lexeme_priority = this_lexeme_priority;
              is_priority_set = 1;
            }

          {
            union marpa_slr_event_s *lexeme_entry =
              marpa_slr_lexeme_push (slr);
            MARPA_SLREV_TYPE (lexeme_entry) = MARPA_SLRTR_LEXEME_ACCEPTABLE;
            lexeme_entry->t_lexeme_acceptable.t_start_of_lexeme =
              slr->start_of_lexeme;
            lexeme_entry->t_lexeme_acceptable.t_end_of_lexeme =
              slr->end_of_lexeme;
            lexeme_entry->t_lexeme_acceptable.t_lexeme = g1_lexeme;
            lexeme_entry->t_lexeme_acceptable.t_priority =
              this_lexeme_priority;
            /* Default to this symbol's priority, since we don't
               yet know what the required priority will be */
            lexeme_entry->t_lexeme_acceptable.t_required_priority =
              this_lexeme_priority;
          }

        NEXT_PASS1_REPORT_ITEM:        /* Clearer, I think, using this label than long distance
                                           break and continue */ ;
        }

      if (discarded || rejected || is_priority_set)
        break;

    }

  /* Figure out what the result of pass 1 was */
  if (is_priority_set)
  {
     pass1_result = accept;
  } else if (discarded) {
     pass1_result = discard;
  } else {
     pass1_result = no_lexeme;
  }

  {
    /* In pass 1, we used a stack of tentative
     * trace events to record which lexemes
     * are acceptable, to be discarded, etc.
     * At this point, if we are tracing,
     * we convert the tentative trace
     * events into real trace events.
     */
    int i;
    for (i = 0; i < slr->t_lexeme_count; i++)
      {
        union marpa_slr_event_s *const lexeme_stack_event = slr->t_lexemes + i;
        const int event_type = MARPA_SLREV_TYPE (lexeme_stack_event);
        switch (event_type)
          {
          case MARPA_SLRTR_LEXEME_ACCEPTABLE:
            if (lexeme_stack_event->t_lexeme_acceptable.t_priority <
                high_lexeme_priority)
              {
                MARPA_SLREV_TYPE (lexeme_stack_event) =
                  MARPA_SLRTR_LEXEME_OUTPRIORITIZED;
                lexeme_stack_event->t_lexeme_acceptable.t_required_priority =
                  high_lexeme_priority;
                if (slr->trace_terminals)
                  {
                    *(marpa_slr_event_push (slr)) =
                      *lexeme_stack_event;
                  }
              }
            goto NEXT_LEXEME_EVENT;
          case MARPA_SLRTR_LEXEME_REJECTED:
            if (slr->trace_terminals || !is_priority_set)
              {
                *(marpa_slr_event_push (slr)) = *lexeme_stack_event;
              }
            goto NEXT_LEXEME_EVENT;
          case MARPA_SLRTR_LEXEME_DISCARDED:
            if (slr->trace_terminals)
              {
                *(marpa_slr_event_push (slr)) = *lexeme_stack_event;
              }
            if (pass1_result == discard)
            {
              union marpa_slr_event_s *new_event;
              const Marpa_Rule_ID l0_rule_id =
                lexeme_stack_event->t_trace_lexeme_discarded.t_rule_id;
              struct l0_rule_r_properties *l0_rule_r_properties
                = slr->l0_rule_r_properties + l0_rule_id;
              if (!l0_rule_r_properties->t_event_on_discard_active)
                {
                  goto NEXT_LEXEME_EVENT;
                }
              new_event = marpa_slr_event_push (slr);
              MARPA_SLREV_TYPE (new_event) =
                  MARPA_SLREV_LEXEME_DISCARDED;
              new_event->t_lexeme_discarded.t_rule_id = l0_rule_id;
              new_event->t_lexeme_discarded.t_start_of_lexeme =
                lexeme_stack_event->t_trace_lexeme_discarded.t_start_of_lexeme;
              new_event->t_lexeme_discarded.t_end_of_lexeme =
                lexeme_stack_event->t_trace_lexeme_discarded.t_end_of_lexeme;
              new_event->t_lexeme_discarded.t_last_g1_location =
                marpa_r_latest_earley_set (slr->r1);
            }
            goto NEXT_LEXEME_EVENT;
          }
          NEXT_LEXEME_EVENT: ;
      }
  }

  if (pass1_result == discard) {
      slr->perl_pos = slr->lexer_start_pos = working_pos;
      return 0;
  }

  if (pass1_result != accept) {
      slr->perl_pos = slr->problem_pos = slr->lexer_start_pos =
        slr->start_of_lexeme;
      return "no lexeme";
    }

  /* If here, a lexeme has been accepted and priority is set
   */

  {                                /* Check for a "pause before" lexeme */
    /* A legacy implement allowed only one pause-before lexeme, and used elements of
       the SLR structure to hold the data.  The new mechanism uses events and allows
       multiple pause-before lexemes, but the legacy mechanism must be supported. */
    Marpa_Symbol_ID g1_lexeme = -1;
    int i;
    for (i = 0; i < slr->t_lexeme_count; i++)
      {
        union marpa_slr_event_s *const lexeme_entry = slr->t_lexemes + i;
        const int event_type = MARPA_SLREV_TYPE (lexeme_entry);
        if (event_type == MARPA_SLRTR_LEXEME_ACCEPTABLE)
          {
            const Marpa_Symbol_ID lexeme_id =
              lexeme_entry->t_lexeme_acceptable.t_lexeme;
            const struct symbol_r_properties *symbol_r_properties =
              slr->symbol_r_properties + lexeme_id;
            if (symbol_r_properties->t_pause_before_active)
              {
                g1_lexeme = lexeme_id;
                slr->start_of_pause_lexeme =
                  lexeme_entry->t_lexeme_acceptable.t_start_of_lexeme;
                slr->end_of_pause_lexeme =
                  lexeme_entry->t_lexeme_acceptable.t_end_of_lexeme;
                if (slr->trace_terminals > 2)
                  {
                    union marpa_slr_event_s *slr_event =
                      marpa_slr_event_push (slr);
                    MARPA_SLREV_TYPE (slr_event) = MARPA_SLRTR_BEFORE_LEXEME;
                    slr_event->t_trace_before_lexeme.t_start_of_pause_lexeme =
                      slr->start_of_pause_lexeme;
                    slr_event->t_trace_before_lexeme.t_end_of_pause_lexeme = slr->end_of_pause_lexeme;        /* end */
                    slr_event->t_trace_before_lexeme.t_pause_lexeme = g1_lexeme;        /* lexeme */
                  }
                {
                  union marpa_slr_event_s *slr_event =
                    marpa_slr_event_push (slr);
                  MARPA_SLREV_TYPE (slr_event) = MARPA_SLREV_BEFORE_LEXEME;
                  slr_event->t_before_lexeme.t_pause_lexeme =
                    g1_lexeme;
                }
              }
          }
      }

    if (g1_lexeme >= 0)
      {
        slr->lexer_start_pos = slr->perl_pos = slr->start_of_lexeme;
        return 0;
      }
  }

  {
    int return_value;
    int i;
    for (i = 0; i < slr->t_lexeme_count; i++)
      {
        union marpa_slr_event_s *const event = slr->t_lexemes + i;
        const int event_type = MARPA_SLREV_TYPE (event);
        if (event_type == MARPA_SLRTR_LEXEME_ACCEPTABLE)
          {
            const Marpa_Symbol_ID g1_lexeme =
              event->t_lexeme_acceptable.t_lexeme;
            const struct symbol_r_properties *symbol_r_properties =
              slr->symbol_r_properties + g1_lexeme;

            if (slr->trace_terminals > 2)
              {
                union marpa_slr_event_s *event =
                  marpa_slr_event_push (slr);
                MARPA_SLREV_TYPE (event) = MARPA_SLRTR_G1_ATTEMPTING_LEXEME;
                event->t_trace_attempting_lexeme.t_start_of_lexeme = slr->start_of_lexeme;        /* start */
                event->t_trace_attempting_lexeme.t_end_of_lexeme = slr->end_of_lexeme;        /* end */
                event->t_trace_attempting_lexeme.t_lexeme = g1_lexeme;
              }
            return_value =
              marpa_r_alternative (r1, g1_lexeme, TOKEN_VALUE_IS_LITERAL, 1);
            switch (return_value)
              {

              case MARPA_ERR_UNEXPECTED_TOKEN_ID:
                croak ("Internal error: Marpa rejected expected token");
                break;

              case MARPA_ERR_DUPLICATE_TOKEN:
                if (slr->trace_terminals)
                  {
                    union marpa_slr_event_s *event =
                      marpa_slr_event_push (slr);
                    MARPA_SLREV_TYPE (event) =
                      MARPA_SLRTR_G1_DUPLICATE_LEXEME;
                    event->t_trace_duplicate_lexeme.t_start_of_lexeme = slr->start_of_lexeme;        /* start */
                    event->t_trace_duplicate_lexeme.t_end_of_lexeme = slr->end_of_lexeme;        /* end */
                    event->t_trace_duplicate_lexeme.t_lexeme = g1_lexeme;        /* lexeme */
                  }
                break;

              case MARPA_ERR_NONE:
                if (slr->trace_terminals)
                  {
                    union marpa_slr_event_s *event =
                      marpa_slr_event_push (slr);
                    MARPA_SLREV_TYPE (event) = MARPA_SLRTR_G1_ACCEPTED_LEXEME;
                    event->t_trace_accepted_lexeme.t_start_of_lexeme = slr->start_of_lexeme;        /* start */
                    event->t_trace_accepted_lexeme.t_end_of_lexeme = slr->end_of_lexeme;        /* end */
                    event->t_trace_accepted_lexeme.t_lexeme = g1_lexeme;        /* lexeme */
                  }
                if (symbol_r_properties->t_pause_after_active)
                  {
                    slr->start_of_pause_lexeme =
                      event->t_lexeme_acceptable.t_start_of_lexeme;
                    slr->end_of_pause_lexeme =
                      event->t_lexeme_acceptable.t_end_of_lexeme;
                    if (slr->trace_terminals > 2)
                      {
                        union marpa_slr_event_s *event =
                          marpa_slr_event_push (slr);
                        MARPA_SLREV_TYPE (event) = MARPA_SLRTR_AFTER_LEXEME;
                        event->t_trace_after_lexeme.t_start_of_lexeme =
                          slr->start_of_pause_lexeme;
                        event->t_trace_after_lexeme.t_end_of_lexeme =
                          slr->end_of_pause_lexeme;
                        event->t_trace_after_lexeme.t_lexeme = g1_lexeme;
                      }
                    {
                      union marpa_slr_event_s *event =
                        marpa_slr_event_push (slr);
                      MARPA_SLREV_TYPE (event) = MARPA_SLREV_AFTER_LEXEME;
                      event->t_after_lexeme.t_lexeme = g1_lexeme;
                    }
                  }
                break;

              default:
                croak
                  ("Problem SLR->read() failed on symbol id %d at position %d: %s",
                   g1_lexeme, (int) slr->perl_pos,
                   xs_g_error (slr->g1_wrapper));
                /* NOTREACHED */

              }

          }
      }


    return_value = slr->r1_earleme_complete_result =
      marpa_r_earleme_complete (r1);
    if (return_value < 0)
      {
        croak ("Problem in marpa_r_earleme_complete(): %s",
               xs_g_error (slr->g1_wrapper));
      }
    slr->lexer_start_pos = slr->perl_pos = slr->end_of_lexeme;
    if (return_value > 0)
      {
        slr_convert_events (slr);
      }

    marpa_r_latest_earley_set_values_set (r1, slr->start_of_lexeme,
                                          INT2PTR (void *,
                                                   (slr->end_of_lexeme -
                                                    slr->start_of_lexeme)));
  }

  return 0;

}

static void
slr_es_to_span (Scanless_R * slr, Marpa_Earley_Set_ID earley_set, int *p_start,
               int *p_length)
{
  dTHX;
  int result = 0;
  /* We fake the values for Earley set 0,
   */
  if (earley_set <= 0)
    {
      *p_start = 0;
      *p_length = 0;
    }
  else
    {
      void *length_as_ptr;
      result =
        marpa_r_earley_set_values (slr->r1, earley_set, p_start,
                                   &length_as_ptr);
      *p_length = (int) PTR2IV (length_as_ptr);
    }
  if (result < 0)
    {
      croak ("failure in slr->span(%d): %s", earley_set,
             xs_g_error (slr->g1_wrapper));
    }
}

static void
slr_es_to_literal_span (Scanless_R * slr,
                        Marpa_Earley_Set_ID start_earley_set, int length,
                        int *p_start, int *p_length)
{
  dTHX;
  const Marpa_Recce r1 = slr->r1;
  const Marpa_Earley_Set_ID latest_earley_set =
    marpa_r_latest_earley_set (r1);
  if (start_earley_set >= latest_earley_set)
    {
      /* Should only happen if length == 0 */
      *p_start = slr->pos_db_logical_size;
      *p_length = 0;
      return;
    }
  slr_es_to_span (slr, start_earley_set + 1, p_start, p_length);
  if (length == 0)
    *p_length = 0;
  if (length > 1)
    {
      int last_lexeme_start_position;
      int last_lexeme_length;
      slr_es_to_span (slr, start_earley_set + length,
        &last_lexeme_start_position, &last_lexeme_length);
      *p_length = last_lexeme_start_position + last_lexeme_length - *p_start;
    }
}

static SV*
slr_es_span_to_literal_sv (Scanless_R * slr,
                        Marpa_Earley_Set_ID start_earley_set, int length)
{
  dTHX;
  if (length > 0)
    {
      int length_in_positions;
      int start_position;
      slr_es_to_literal_span (slr,
                              start_earley_set, length,
                              &start_position, &length_in_positions);
      return u_pos_span_to_literal_sv(slr, start_position, length_in_positions);
    }
  return newSVpvn ("", 0);
}

#define EXPECTED_LIBMARPA_MAJOR 8
#define EXPECTED_LIBMARPA_MINOR 4
#define EXPECTED_LIBMARPA_MICRO 0

/* get_mortalspace comes from "Extending and Embedding Perl"
   by Jenness and Cozens, p. 242 */
static void *
get_mortalspace (size_t nbytes) PERL_UNUSED_DECL;

static void *
get_mortalspace (size_t nbytes)
{
    dTHX;
    SV *mortal;
    mortal = sv_2mortal (NEWSV (0, nbytes));
    return (void *) SvPVX (mortal);
}

MODULE = Marpa::R3        PACKAGE = Marpa::R3::Thin

PROTOTYPES: DISABLE

void
debug_level_set(new_level)
    int new_level;
PPCODE:
{
  const int old_level = marpa_debug_level_set (new_level);
  if (old_level || new_level)
    marpa_r3_warn ("libmarpa debug level set to %d, was %d", new_level,
                   old_level);
  XSRETURN_YES;
}

void
error_names()
PPCODE:
{
  int error_code;
  for (error_code = 0; error_code < MARPA_ERROR_COUNT; error_code++)
    {
      const char *error_name = marpa_error_description[error_code].name;
      XPUSHs (sv_2mortal (newSVpv (error_name, 0)));
    }
}

 # This search is not optimized.  This list is short
 # and the data is constant, so that
 # and lookup is expected to be done once by an application
 # and memoized.
void
op( op_name )
     char *op_name;
PPCODE:
{
  const int op_id = marpa_slif_op_id (op_name);
  if (op_id >= 0)
    {
      XSRETURN_IV ((IV) op_id);
    }
  croak ("Problem with Marpa::R3::Thin->op('%s'): No such op", op_name);
}

 # This search is not optimized.  This list is short
 # and the data is constant.  It is expected this lookup
 # will be done mainly for error messages.
void
op_name( op )
     UV op;
PPCODE:
{
  XSRETURN_PV (marpa_slif_op_name(op));
}

void
version()
PPCODE:
{
    int version[3];
    int result = marpa_version(version);
    if (result < 0) { XSRETURN_UNDEF; }
    XPUSHs (sv_2mortal (newSViv (version[0])));
    XPUSHs (sv_2mortal (newSViv (version[1])));
    XPUSHs (sv_2mortal (newSViv (version[2])));
}

void
tag()
PPCODE:
{
   const char* tag = _marpa_tag();
   XSRETURN_PV(tag);
}

MODULE = Marpa::R3        PACKAGE = Marpa::R3::Thin::G

void
new( ... )
PPCODE:
{
  Marpa_Grammar g;
  G_Wrapper *g_wrapper;
  int throw = 1;
  IV interface = 0;
  Marpa_Config marpa_configuration;
  int error_code;

  switch (items)
    {
    case 1:
      {
        /* If we are using the (deprecated) interface 0,
         * get the throw setting from a (deprecated) global variable
         */
        SV *throw_sv = get_sv ("Marpa::R3::Thin::C::THROW", 0);
        throw = throw_sv && SvTRUE (throw_sv);
      }
      break;
    case 2:
      {
        I32 retlen;
        char *key;
        SV *arg_value;
        SV *arg = ST (1);
        HV *named_args;
        if (!SvROK (arg) || SvTYPE (SvRV (arg)) != SVt_PVHV)
          croak ("Problem in $g->new(): argument is not hash ref");
        named_args = (HV *) SvRV (arg);
        hv_iterinit (named_args);
        while ((arg_value = hv_iternextsv (named_args, &key, &retlen)))
          {
            if ((*key == 'i') && strnEQ (key, "if", (unsigned) retlen))
              {
                interface = SvIV (arg_value);
                if (interface != 1)
                  {
                    croak ("Problem in $g->new(): interface value must be 1");
                  }
                continue;
              }
            croak ("Problem in $g->new(): unknown named argument: %s", key);
          }
        if (interface != 1)
          {
            croak
              ("Problem in $g->new(): 'interface' named argument is required");
          }
      }
    }

  /* Make sure the header is from the version we want */
  if (MARPA_MAJOR_VERSION != EXPECTED_LIBMARPA_MAJOR
      || MARPA_MINOR_VERSION != EXPECTED_LIBMARPA_MINOR
      || MARPA_MICRO_VERSION != EXPECTED_LIBMARPA_MICRO)
    {
      croak
        ("Problem in $g->new(): want Libmarpa %d.%d.%d, header was from Libmarpa %d.%d.%d",
         EXPECTED_LIBMARPA_MAJOR, EXPECTED_LIBMARPA_MINOR,
         EXPECTED_LIBMARPA_MICRO,
         MARPA_MAJOR_VERSION, MARPA_MINOR_VERSION,
         MARPA_MICRO_VERSION);
    }

  {
    /* Now make sure the library is from the version we want */
    int version[3];
    error_code = marpa_version (version);
    if (error_code != MARPA_ERR_NONE
        || version[0] != EXPECTED_LIBMARPA_MAJOR
        || version[1] != EXPECTED_LIBMARPA_MINOR
        || version[2] != EXPECTED_LIBMARPA_MICRO)
      {
        croak
          ("Problem in $g->new(): want Libmarpa %d.%d.%d, using Libmarpa %d.%d.%d",
           EXPECTED_LIBMARPA_MAJOR, EXPECTED_LIBMARPA_MINOR,
           EXPECTED_LIBMARPA_MICRO, version[0], version[1], version[2]);
      }
  }

  marpa_c_init (&marpa_configuration);
  g = marpa_g_new (&marpa_configuration);
  if (g)
    {
      SV *sv;
      Newx (g_wrapper, 1, G_Wrapper);
      g_wrapper->throw = throw ? 1 : 0;
      g_wrapper->g = g;
      g_wrapper->message_buffer = NULL;
      g_wrapper->libmarpa_error_code = MARPA_ERR_NONE;
      g_wrapper->libmarpa_error_string = NULL;
      g_wrapper->message_is_marpa_thin_error = 0;
      sv = sv_newmortal ();
      sv_setref_pv (sv, grammar_c_class_name, (void *) g_wrapper);
      XPUSHs (sv);
    }
  else
    {
      error_code = marpa_c_error (&marpa_configuration, NULL);
    }

  if (error_code != MARPA_ERR_NONE)
    {
      const char *error_description = "Error code out of bounds";
      if (error_code >= 0 && error_code < MARPA_ERROR_COUNT)
        {
          error_description = marpa_error_description[error_code].name;
        }
      if (throw)
        croak ("Problem in Marpa::R3->new(): %s", error_description);
      if (GIMME != G_ARRAY)
        {
          XSRETURN_UNDEF;
        }
      XPUSHs (sv_2mortal (newSV (0)));
      XPUSHs (sv_2mortal (newSViv (error_code)));
    }
}

void
DESTROY( g_wrapper )
    G_Wrapper *g_wrapper;
PPCODE:
{
    Marpa_Grammar grammar;
    if (g_wrapper->message_buffer)
        Safefree(g_wrapper->message_buffer);
    grammar = g_wrapper->g;
    marpa_g_unref( grammar );
    Safefree( g_wrapper );
}


void
event( g_wrapper, ix )
    G_Wrapper *g_wrapper;
    int ix;
PPCODE:
{
  Marpa_Grammar g = g_wrapper->g;
  Marpa_Event event;
  const char *result_string = NULL;
  Marpa_Event_Type result = marpa_g_event (g, &event, ix);
  if (result < 0)
    {
      if (!g_wrapper->throw)
        {
          XSRETURN_UNDEF;
        }
      croak ("Problem in g->event(): %s", xs_g_error (g_wrapper));
    }
  result_string = event_type_to_string (result);
  if (!result_string)
    {
      char *error_message =
        form ("event(%d): unknown event code, %d", ix, result);
      set_error_from_string (g_wrapper, savepv(error_message));
      XSRETURN_UNDEF;
    }
  XPUSHs (sv_2mortal (newSVpv (result_string, 0)));
  XPUSHs (sv_2mortal (newSViv (marpa_g_event_value (&event))));
}

 # Actually returns Marpa_Rule_ID, void is here to eliminate RETVAL
 # that remains unused with PPCODE. The same applies to all void's below
 # when preceded with a return type commented out, e.g.
 #    # int
 #    void
void
rule_new( g_wrapper, lhs, rhs_av )
    G_Wrapper *g_wrapper;
    Marpa_Symbol_ID lhs;
    AV *rhs_av;
PPCODE:
{
  Marpa_Grammar g = g_wrapper->g;
    int length;
    Marpa_Symbol_ID* rhs;
    Marpa_Rule_ID new_rule_id;
    length = av_len(rhs_av)+1;
    if (length <= 0) {
        rhs = (Marpa_Symbol_ID*)NULL;
    } else {
        int i;
        Newx(rhs, (unsigned int)length, Marpa_Symbol_ID);
        for (i = 0; i < length; i++) {
            SV** elem = av_fetch(rhs_av, i, 0);
            if (elem == NULL) {
                Safefree(rhs);
                XSRETURN_UNDEF;
            } else {
                rhs[i] = (Marpa_Symbol_ID)SvIV(*elem);
            }
        }
    }
    new_rule_id = marpa_g_rule_new(g, lhs, rhs, length);
    Safefree(rhs);
    if (new_rule_id < 0 && g_wrapper->throw ) {
      croak ("Problem in g->rule_new(%d, ...): %s", lhs, xs_g_error (g_wrapper));
    }
    XPUSHs( sv_2mortal( newSViv(new_rule_id) ) );
}

 # This function invalidates any current iteration on
 # the hash args.  This seems to be the way things are
 # done in Perl -- in particular there seems to be no
 # easy way to  prevent that.
# Marpa_Rule_ID
void
sequence_new( g_wrapper, lhs, rhs, args )
    G_Wrapper *g_wrapper;
    Marpa_Symbol_ID lhs;
    Marpa_Symbol_ID rhs;
    HV *args;
PPCODE:
{
  Marpa_Grammar g = g_wrapper->g;
  Marpa_Rule_ID new_rule_id;
  Marpa_Symbol_ID separator = -1;
  int min = 1;
  int flags = 0;
  if (args)
    {
      I32 retlen;
      char *key;
      SV *arg_value;
      hv_iterinit (args);
      while ((arg_value = hv_iternextsv (args, &key, &retlen)))
        {
          if ((*key == 'k') && strnEQ (key, "keep", (unsigned) retlen))
            {
              if (SvTRUE (arg_value))
                flags |= MARPA_KEEP_SEPARATION;
              continue;
            }
          if ((*key == 'm') && strnEQ (key, "min", (unsigned) retlen))
            {
              IV raw_min = SvIV (arg_value);
              if (raw_min < 0)
                {
                  char *error_message =
                    form ("sequence_new(): min cannot be less than 0");
                  set_error_from_string (g_wrapper, savepv (error_message));
                  if (g_wrapper->throw)
                    {
                      croak ("%s", error_message);
                    }
                  else
                    {
                      XSRETURN_UNDEF;
                    }
                }
              if (raw_min > INT_MAX)
                {
                  /* IV can be larger than int */
                  char *error_message =
                    form ("sequence_new(): min cannot be greater than %d",
                          INT_MAX);
                  set_error_from_string (g_wrapper, savepv (error_message));
                  if (g_wrapper->throw)
                    {
                      croak ("%s", error_message);
                    }
                  else
                    {
                      XSRETURN_UNDEF;
                    }
                }
              min = (int) raw_min;
              continue;
            }
          if ((*key == 'p') && strnEQ (key, "proper", (unsigned) retlen))
            {
              if (SvTRUE (arg_value))
                flags |= MARPA_PROPER_SEPARATION;
              continue;
            }
          if ((*key == 's') && strnEQ (key, "separator", (unsigned) retlen))
            {
              separator = (Marpa_Symbol_ID) SvIV (arg_value);
              continue;
            }
          {
            char *error_message =
              form ("unknown argument to sequence_new(): %.*s", (int) retlen,
                    key);
            set_error_from_string (g_wrapper, savepv (error_message));
            if (g_wrapper->throw)
              {
                croak ("%s", error_message);
              }
            else
              {
                XSRETURN_UNDEF;
              }
          }
        }
    }
  new_rule_id = marpa_g_sequence_new (g, lhs, rhs, separator, min, flags);
  if (new_rule_id < 0 && g_wrapper->throw)
    {
      switch (marpa_g_error (g, NULL))
        {
        case MARPA_ERR_SEQUENCE_LHS_NOT_UNIQUE:
          croak ("Problem in g->sequence_new(): %s", xs_g_error (g_wrapper));
        default:
          croak ("Problem in g->sequence_new(%d, %d, ...): %s", lhs, rhs,
                 xs_g_error (g_wrapper));
        }
    }
  XPUSHs (sv_2mortal (newSViv (new_rule_id)));
}

void
default_rank( g_wrapper )
    G_Wrapper *g_wrapper;
PPCODE:
{
  Marpa_Grammar self = g_wrapper->g;
  int gp_result = marpa_g_default_rank (self);
  if (gp_result == -2 && g_wrapper->throw)
    {
      const int libmarpa_error_code = marpa_g_error (self, NULL);
      if (libmarpa_error_code != MARPA_ERR_NONE)
        {
          croak ("Problem in g->default_rank(): %s", xs_g_error (g_wrapper));
        }
    }
  XSRETURN_IV (gp_result);
}

void
default_rank_set( g_wrapper, rank )
    G_Wrapper *g_wrapper;
    Marpa_Rank rank;
PPCODE:
{
  Marpa_Grammar self = g_wrapper->g;
  int gp_result = marpa_g_default_rank_set (self, rank);
  if (gp_result == -2 && g_wrapper->throw)
    {
      const int libmarpa_error_code = marpa_g_error (self, NULL);
      if (libmarpa_error_code != MARPA_ERR_NONE)
        croak ("Problem in g->default_rank_set(%d): %s",
               rank, xs_g_error (g_wrapper));
    }
  XSRETURN_IV (gp_result);
}

void
rule_rank( g_wrapper, rule_id )
    G_Wrapper *g_wrapper;
    Marpa_Rule_ID rule_id;
PPCODE:
{
  Marpa_Grammar self = g_wrapper->g;
  int gp_result = marpa_g_rule_rank (self, rule_id);
  if (gp_result == -2 && g_wrapper->throw)
    {
      const int libmarpa_error_code = marpa_g_error (self, NULL);
      if (libmarpa_error_code != MARPA_ERR_NONE)
        {
          croak ("Problem in g->rule_rank(%d): %s",
                 rule_id, xs_g_error (g_wrapper));
        }
    }
  XSRETURN_IV (gp_result);
}

void
rule_rank_set( g_wrapper, rule_id, rank )
    G_Wrapper *g_wrapper;
    Marpa_Rule_ID rule_id;
    Marpa_Rank rank;
PPCODE:
{
  Marpa_Grammar self = g_wrapper->g;
  int gp_result = marpa_g_rule_rank_set(self, rule_id, rank);
  if (gp_result == -2 && g_wrapper->throw)
    {
      const int libmarpa_error_code = marpa_g_error (self, NULL);
      if (libmarpa_error_code != MARPA_ERR_NONE)
        croak ("Problem in g->rule_rank_set(%d, %d): %s",
               rule_id, rank, xs_g_error (g_wrapper));
    }
  XSRETURN_IV (gp_result);
}

void
symbol_rank( g_wrapper, symbol_id )
    G_Wrapper *g_wrapper;
    Marpa_Symbol_ID symbol_id;
PPCODE:
{
  Marpa_Grammar self = g_wrapper->g;
  int gp_result = marpa_g_symbol_rank (self, symbol_id);
  if (gp_result == -2 && g_wrapper->throw)
    {
      const int libmarpa_error_code = marpa_g_error (self, NULL);
      if (libmarpa_error_code != MARPA_ERR_NONE)
        {
          croak ("Problem in g->symbol_rank(%d): %s",
                 symbol_id, xs_g_error (g_wrapper));
        }
    }
  XSRETURN_IV (gp_result);
}

void
symbol_rank_set( g_wrapper, symbol_id, rank )
    G_Wrapper *g_wrapper;
    Marpa_Symbol_ID symbol_id;
    Marpa_Rank rank;
PPCODE:
{
  Marpa_Grammar self = g_wrapper->g;
  int gp_result = marpa_g_symbol_rank_set (self, symbol_id, rank);
  if (gp_result == -2 && g_wrapper->throw)
    {
      const int libmarpa_error_code = marpa_g_error (self, NULL);
      if (libmarpa_error_code != MARPA_ERR_NONE)
        croak ("Problem in g->symbol_rank_set(%d, %d): %s",
               symbol_id, rank, xs_g_error (g_wrapper));
    }
  XSRETURN_IV (gp_result);
}

void
throw_set( g_wrapper, boolean )
    G_Wrapper *g_wrapper;
    int boolean;
PPCODE:
{
  if (boolean < 0 || boolean > 1)
    {
      /* Always throws an exception if the arguments are bad */
      croak ("Problem in g->throw_set(%d): argument must be 0 or 1", boolean);
    }
  g_wrapper->throw = boolean ? 1 : 0;
  XPUSHs (sv_2mortal (newSViv (boolean)));
}

void
error( g_wrapper )
    G_Wrapper *g_wrapper;
PPCODE:
{
  Marpa_Grammar g = g_wrapper->g;
  const char *error_message =
    "Problem in $g->error(): Nothing in message buffer";
  SV *error_code_sv = 0;

  g_wrapper->libmarpa_error_code =
    marpa_g_error (g, &g_wrapper->libmarpa_error_string);
  /* A new Libmarpa error overrides any thin interface error */
  if (g_wrapper->libmarpa_error_code != MARPA_ERR_NONE)
    g_wrapper->message_is_marpa_thin_error = 0;
  if (g_wrapper->message_is_marpa_thin_error)
    {
      error_message = g_wrapper->message_buffer;
    }
  else
    {
      error_message = error_description_generate (g_wrapper);
      error_code_sv = sv_2mortal (newSViv (g_wrapper->libmarpa_error_code));
    }
  if (GIMME == G_ARRAY)
    {
      if (!error_code_sv) {
        error_code_sv = sv_2mortal (newSV (0));
      }
      XPUSHs (error_code_sv);
    }
  XPUSHs (sv_2mortal (newSVpv (error_message, 0)));
}

MODULE = Marpa::R3        PACKAGE = Marpa::R3::Thin::R

void
new( class, g_sv )
    char * class;
    SV* g_sv;
PPCODE:
{
  SV *sv_to_return;
  G_Wrapper *g_wrapper;
  Marpa_Recce r;
  Marpa_Grammar g;
  PERL_UNUSED_ARG(class);

  if (!sv_isa (g_sv, "Marpa::R3::Thin::G"))
    {
      croak
        ("Problem in Marpa::R3->new(): arg is not of type Marpa::R3::Thin::G");
    }
  SET_G_WRAPPER_FROM_G_SV (g_wrapper, g_sv);
  g = g_wrapper->g;
  r = marpa_r_new (g);
  if (!r)
    {
      if (!g_wrapper->throw)
        {
          XSRETURN_UNDEF;
        }
      croak ("failure in marpa_r_new(): %s", xs_g_error (g_wrapper));
    };

  {
    R_Wrapper *r_wrapper = r_wrap (r, g_sv);
    sv_to_return = sv_newmortal ();
    sv_setref_pv (sv_to_return, recce_c_class_name, (void *) r_wrapper);
  }
  XPUSHs (sv_to_return);
}

void
DESTROY( r_wrapper )
    R_Wrapper *r_wrapper;
PPCODE:
{
    Marpa_Recce r = r_unwrap(r_wrapper);
    marpa_r_unref (r);
}

void
ruby_slippers_set( r_wrapper, boolean )
    R_Wrapper *r_wrapper;
    int boolean;
PPCODE:
{
  if (boolean < 0 || boolean > 1)
    {
      /* Always thrown */
      croak ("Problem in g->ruby_slippers_set(%d): argument must be 0 or 1", boolean);
    }
  r_wrapper->ruby_slippers = boolean ? 1 : 0;
  XPUSHs (sv_2mortal (newSViv (boolean)));
}

void
start_input( r_wrapper )
    R_Wrapper *r_wrapper;
PPCODE:
{
  Marpa_Recognizer self = r_wrapper->r;
  int gp_result = marpa_r_start_input(self);
  if ( gp_result == -1 ) { XSRETURN_UNDEF; }
  if ( gp_result < 0 && r_wrapper->base->throw ) {
    croak( "Problem in r->start_input(): %s",
     xs_g_error( r_wrapper->base ));
  }
  r_convert_events(r_wrapper);
  XPUSHs (sv_2mortal (newSViv (gp_result)));
}

void
alternative( r_wrapper, symbol_id, value, length )
    R_Wrapper *r_wrapper;
    Marpa_Symbol_ID symbol_id;
    int value;
    int length;
PPCODE:
{
  struct marpa_r *r = r_wrapper->r;
  const G_Wrapper *base = r_wrapper->base;
  const int result = marpa_r_alternative (r, symbol_id, value, length);
  if (result == MARPA_ERR_NONE || r_wrapper->ruby_slippers || !base->throw)
    {
      XSRETURN_IV (result);
    }
  croak ("Problem in r->alternative(): %s", xs_g_error (r_wrapper->base));
}

void
terminals_expected( r_wrapper )
    R_Wrapper *r_wrapper;
PPCODE:
{
  int i;
  struct marpa_r *r = r_wrapper->r;
  const int count =
    marpa_r_terminals_expected (r, r_wrapper->terminals_buffer);
  if (count < 0)
    {
      G_Wrapper* base = r_wrapper->base;
      if (!base->throw) { XSRETURN_UNDEF; }
      croak ("Problem in r->terminals_expected(): %s",
             xs_g_error (base));
    }
  EXTEND (SP, count);
  for (i = 0; i < count; i++)
    {
      PUSHs (sv_2mortal (newSViv (r_wrapper->terminals_buffer[i])));
    }
}

void
progress_item( r_wrapper )
     R_Wrapper *r_wrapper;
PPCODE:
{
  struct marpa_r *const r = r_wrapper->r;
  int position = -1;
  Marpa_Earley_Set_ID origin = -1;
  Marpa_Rule_ID rule_id = marpa_r_progress_item (r, &position, &origin);
  if (rule_id == -1)
    {
      XSRETURN_UNDEF;
    }
  if (rule_id < 0 && r_wrapper->base->throw)
    {
      croak ("Problem in r->progress_item(): %s",
             xs_g_error (r_wrapper->base));
    }
  XPUSHs (sv_2mortal (newSViv (rule_id)));
  XPUSHs (sv_2mortal (newSViv (position)));
  XPUSHs (sv_2mortal (newSViv (origin)));
}

MODULE = Marpa::R3        PACKAGE = Marpa::R3::Thin::B

void
new( class, r_wrapper, ordinal )
    char * class;
    R_Wrapper *r_wrapper;
    Marpa_Earley_Set_ID ordinal;
PPCODE:
{
  SV *sv;
  Marpa_Recognizer r = r_wrapper->r;
  B_Wrapper *b_wrapper;
  Marpa_Bocage b = marpa_b_new (r, ordinal);
  PERL_UNUSED_ARG(class);

  if (!b)
    {
      if (!r_wrapper->base->throw) { XSRETURN_UNDEF; }
      croak ("Problem in b->new(): %s", xs_g_error(r_wrapper->base));
    }
  Newx (b_wrapper, 1, B_Wrapper);
  {
    SV* base_sv = r_wrapper->base_sv;
    SvREFCNT_inc (base_sv);
    b_wrapper->base_sv = base_sv;
  }
  b_wrapper->base = r_wrapper->base;
  b_wrapper->b = b;
  sv = sv_newmortal ();
  sv_setref_pv (sv, bocage_c_class_name, (void *) b_wrapper);
  XPUSHs (sv);
}

void
DESTROY( b_wrapper )
    B_Wrapper *b_wrapper;
PPCODE:
{
    const Marpa_Bocage b = b_wrapper->b;
    SvREFCNT_dec (b_wrapper->base_sv);
    marpa_b_unref(b);
    Safefree( b_wrapper );
}

MODULE = Marpa::R3        PACKAGE = Marpa::R3::Thin::O

void
new( class, b_wrapper )
    char * class;
    B_Wrapper *b_wrapper;
PPCODE:
{
  SV *sv;
  Marpa_Bocage b = b_wrapper->b;
  O_Wrapper *o_wrapper;
  Marpa_Order o = marpa_o_new (b);
  PERL_UNUSED_ARG(class);

  if (!o)
    {
      if (!b_wrapper->base->throw) { XSRETURN_UNDEF; }
      croak ("Problem in o->new(): %s", xs_g_error(b_wrapper->base));
    }
  Newx (o_wrapper, 1, O_Wrapper);
  {
    SV* base_sv = b_wrapper->base_sv;
    SvREFCNT_inc (base_sv);
    o_wrapper->base_sv = base_sv;
  }
  o_wrapper->base = b_wrapper->base;
  o_wrapper->o = o;
  sv = sv_newmortal ();
  sv_setref_pv (sv, order_c_class_name, (void *) o_wrapper);
  XPUSHs (sv);
}

void
DESTROY( o_wrapper )
    O_Wrapper *o_wrapper;
PPCODE:
{
    const Marpa_Order o = o_wrapper->o;
    SvREFCNT_dec (o_wrapper->base_sv);
    marpa_o_unref(o);
    Safefree( o_wrapper );
}

MODULE = Marpa::R3        PACKAGE = Marpa::R3::Thin::T

void
new( class, o_wrapper )
    char * class;
    O_Wrapper *o_wrapper;
PPCODE:
{
  SV *sv;
  Marpa_Order o = o_wrapper->o;
  T_Wrapper *t_wrapper;
  Marpa_Tree t = marpa_t_new (o);
  PERL_UNUSED_ARG(class);

  if (!t)
    {
      if (!o_wrapper->base->throw) { XSRETURN_UNDEF; }
      croak ("Problem in t->new(): %s", xs_g_error(o_wrapper->base));
    }
  Newx (t_wrapper, 1, T_Wrapper);
  {
    SV* base_sv = o_wrapper->base_sv;
    SvREFCNT_inc (base_sv);
    t_wrapper->base_sv = base_sv;
  }
  t_wrapper->base = o_wrapper->base;
  t_wrapper->t = t;
  sv = sv_newmortal ();
  sv_setref_pv (sv, tree_c_class_name, (void *) t_wrapper);
  XPUSHs (sv);
}

void
DESTROY( t_wrapper )
    T_Wrapper *t_wrapper;
PPCODE:
{
    const Marpa_Tree t = t_wrapper->t;
    SvREFCNT_dec (t_wrapper->base_sv);
    marpa_t_unref(t);
    Safefree( t_wrapper );
}

MODULE = Marpa::R3        PACKAGE = Marpa::R3::Thin::V

void
new( class, t_wrapper )
    char * class;
    T_Wrapper *t_wrapper;
PPCODE:
{
  SV *sv;
  Marpa_Tree t = t_wrapper->t;
  V_Wrapper *v_wrapper;
  Marpa_Value v = marpa_v_new (t);
  PERL_UNUSED_ARG(class);

  if (!v)
    {
      if (!t_wrapper->base->throw)
        {
          XSRETURN_UNDEF;
        }
      croak ("Problem in v->new(): %s", xs_g_error (t_wrapper->base));
    }
  Newx (v_wrapper, 1, V_Wrapper);
  {
    SV *base_sv = t_wrapper->base_sv;
    SvREFCNT_inc (base_sv);
    v_wrapper->base_sv = base_sv;
  }
  v_wrapper->base = t_wrapper->base;
  v_wrapper->v = v;
  v_wrapper->stack = NULL;
  v_wrapper->mode = MARPA_XS_V_MODE_IS_INITIAL;
  v_wrapper->result = 0;

  v_wrapper->constants = newAV ();
  /* Reserve position 0 */
  av_push (v_wrapper->constants, newSV(0));

  v_wrapper->rule_semantics = newAV ();
  v_wrapper->token_semantics = newAV ();
  v_wrapper->nulling_semantics = newAV ();
  v_wrapper->slr = NULL;
  sv = sv_newmortal ();
  sv_setref_pv (sv, value_c_class_name, (void *) v_wrapper);
  XPUSHs (sv);
}

void
DESTROY( v_wrapper )
    V_Wrapper *v_wrapper;
PPCODE:
{
  const Marpa_Value v = v_wrapper->v;
  SvREFCNT_dec (v_wrapper->base_sv);
  SvREFCNT_dec (v_wrapper->constants);
  SvREFCNT_dec (v_wrapper->rule_semantics);
  SvREFCNT_dec (v_wrapper->token_semantics);
  SvREFCNT_dec (v_wrapper->nulling_semantics);

  /* These are "weak" cross-references, weak
   * meaning that the reference counts are not
   * incremented.  The destructors set both pointers
   * to null, and callers must check that
   * for NULL before dereferencing.
   *
   * This is necessary because at startup, an SLR will
   * not yet have a valuator, and a valuator can be "thin"
   * and never have an SLR.  For the thin valuators to be
   * independent is useful for the tracing and debugging
   * methods.
   */
  if (v_wrapper->slr) {
      v_wrapper->slr->v_wrapper = NULL;
      v_wrapper->slr = NULL;
  }

  if (v_wrapper->stack)
    {
      SvREFCNT_dec (v_wrapper->stack);
    }
  marpa_v_unref (v);
  Safefree (v_wrapper);
}

void
step( v_wrapper )
    V_Wrapper *v_wrapper;
PPCODE:
{
  const Marpa_Value v = v_wrapper->v;
  Marpa_Symbol_ID token_id;
  Marpa_Rule_ID rule_id;
  const char *result_string;
  const Marpa_Step_Type step_type = marpa_v_step (v);

  if (v_wrapper->mode == MARPA_XS_V_MODE_IS_INITIAL) {
    v_wrapper->mode = MARPA_XS_V_MODE_IS_RAW;
  }
  if (v_wrapper->mode != MARPA_XS_V_MODE_IS_RAW) {
       if (v_wrapper->stack) {
          croak ("Problem in v->step(): Cannot call when valuator is in 'stack' mode");
       }
  }
  if (step_type == MARPA_STEP_INACTIVE)
    {
      XSRETURN_EMPTY;
    }
  if (step_type < 0)
    {
      const char *error_message = xs_g_error (v_wrapper->base);
      if (v_wrapper->base->throw)
        {
          croak ("Problem in v->step(): %s", error_message);
        }
      XPUSHs (sv_2mortal
              (newSVpvf ("Problem in v->step(): %s", error_message)));
      XSRETURN (1);
    }
  result_string = step_type_to_string (step_type);
  if (!result_string)
    {
      char *error_message =
        form ("Problem in v->step(): unknown step type %d", step_type);
      set_error_from_string (v_wrapper->base, savepv(error_message));
      if (v_wrapper->base->throw)
        {
          croak ("%s", error_message);
        }
      XPUSHs (sv_2mortal (newSVpv (error_message, 0)));
      XSRETURN (1);
    }
  XPUSHs (sv_2mortal (newSVpv (result_string, 0)));
  if (step_type == MARPA_STEP_TOKEN)
    {
      token_id = marpa_v_token (v);
      XPUSHs (sv_2mortal (newSViv (token_id)));
      XPUSHs (sv_2mortal (newSViv (marpa_v_token_value (v))));
      XPUSHs (sv_2mortal (newSViv (marpa_v_result (v))));
    }
  if (step_type == MARPA_STEP_NULLING_SYMBOL)
    {
      token_id = marpa_v_token (v);
      XPUSHs (sv_2mortal (newSViv (token_id)));
      XPUSHs (sv_2mortal (newSViv (marpa_v_result (v))));
    }
  if (step_type == MARPA_STEP_RULE)
    {
      rule_id = marpa_v_rule (v);
      XPUSHs (sv_2mortal (newSViv (rule_id)));
      XPUSHs (sv_2mortal (newSViv (marpa_v_arg_0 (v))));
      XPUSHs (sv_2mortal (newSViv (marpa_v_arg_n (v))));
    }
}

void
stack_mode_set( v_wrapper, slr )
    V_Wrapper *v_wrapper;
    Scanless_R *slr;
PPCODE:
{
  if (v_wrapper->mode != MARPA_XS_V_MODE_IS_INITIAL)
    {
        croak ("Problem in v->stack_mode_set(): Cannot re-set stack mode");
    }
  if (slr->v_wrapper) {
        croak ("SLR already has active valuator");
  }

  v_wrapper->slr = slr;
  slr->v_wrapper = v_wrapper;

  v_wrapper->stack = newAV ();
  av_extend (v_wrapper->stack, 1023);
  v_wrapper->mode = MARPA_XS_V_MODE_IS_STACK;

  XSRETURN_YES;
}

void
rule_register( v_wrapper, rule_id, ... )
     V_Wrapper *v_wrapper;
     Marpa_Rule_ID rule_id;
PPCODE:
{
  /* OP Count is args less two */
  const UV op_count = (UV)items - 2;
  UV op_ix;
  STRLEN dummy;
  UV *ops;
  SV *ops_sv;
  AV *rule_semantics = v_wrapper->rule_semantics;

  if (!rule_semantics)
    {
      croak ("Problem in v->rule_register(): valuator is not in stack mode");
    }

  /* Leave room for final 0 */
  ops_sv = newSV ((size_t)(op_count+1) * sizeof (ops[0]));

  SvPOK_on (ops_sv);
  ops = (UV *) SvPV (ops_sv, dummy);
  for (op_ix = 0; op_ix < op_count; op_ix++)
    {
      ops[op_ix] = SvUV (ST ((int)op_ix+2));
    }
  ops[op_ix] = 0;
  if (!av_store (rule_semantics, (I32) rule_id, ops_sv)) {
     SvREFCNT_dec(ops_sv);
  }
}

void
token_register( v_wrapper, token_id, ... )
     V_Wrapper *v_wrapper;
     Marpa_Symbol_ID token_id;
PPCODE:
{
  /* OP Count is args less two */
  const int op_count = items - 2;
  int op_ix;
  STRLEN dummy;
  UV *ops;
  SV *ops_sv;
  AV *token_semantics = v_wrapper->token_semantics;

  if (!token_semantics)
    {
      croak ("Problem in v->token_register(): valuator is not in stack mode");
    }

  /* Leave room for final 0 */
  ops_sv = newSV ((size_t)(op_count+1) * sizeof (ops[0]));

  SvPOK_on (ops_sv);
  ops = (UV *) SvPV (ops_sv, dummy);
  for (op_ix = 0; op_ix < op_count; op_ix++)
    {
      ops[op_ix] = SvUV (ST (op_ix+2));
    }
  ops[op_ix] = 0;
  if (!av_store (token_semantics, (I32) token_id, ops_sv)) {
     SvREFCNT_dec(ops_sv);
  }
}

void
nulling_symbol_register( v_wrapper, symbol_id, ... )
     V_Wrapper *v_wrapper;
     Marpa_Symbol_ID symbol_id;
PPCODE:
{
  /* OP Count is args less two */
  const int op_count = items - 2;
  int op_ix;
  STRLEN dummy;
  UV *ops;
  SV *ops_sv;
  AV *nulling_semantics = v_wrapper->nulling_semantics;

  if (!nulling_semantics)
    {
      croak ("Problem in v->nulling_symbol_register(): valuator is not in stack mode");
    }

  /* Leave room for final 0 */
  ops_sv = newSV ((size_t)(op_count+1) * sizeof (ops[0]));

  SvPOK_on (ops_sv);
  ops = (UV *) SvPV (ops_sv, dummy);
  for (op_ix = 0; op_ix < op_count; op_ix++)
    {
      ops[op_ix] = SvUV (ST (op_ix+2));
    }
  ops[op_ix] = 0;
  if (!av_store (nulling_semantics, (I32) symbol_id, ops_sv)) {
     SvREFCNT_dec(ops_sv);
  }
}

void
constant_register( v_wrapper, sv )
     V_Wrapper *v_wrapper;
     SV* sv;
PPCODE:
{
  AV *constants = v_wrapper->constants;

  if (!constants)
    {
      croak
        ("Problem in v->constant_register(): valuator is not in stack mode");
    }
  if (SvTAINTED(sv)) {
      croak
        ("Problem in v->constant_register(): Attempt to register a tainted constant with Marpa::R3\n"
        "Marpa::R3 is insecure for use with tainted data\n");
  }

  av_push (constants, SvREFCNT_inc_simple_NN (sv));
  XSRETURN_IV (av_len (constants));
}

void
highest_index( v_wrapper )
    V_Wrapper *v_wrapper;
PPCODE:
{
  AV* stack = v_wrapper->stack;
  IV length = stack ? av_len(stack) : -1;
  XSRETURN_IV(length);
}

void
absolute( v_wrapper, index )
    V_Wrapper *v_wrapper;
    IV index;
PPCODE:
{
  SV** p_sv;
  AV* stack = v_wrapper->stack;
  if (!stack) { XSRETURN_UNDEF; }
  p_sv = av_fetch(stack, index, 0);
  if (!p_sv) { XSRETURN_UNDEF; }
  XPUSHs (sv_mortalcopy(*p_sv));
}

void
relative( v_wrapper, index )
    V_Wrapper *v_wrapper;
    IV index;
PPCODE:
{
  SV** p_sv;
  AV* stack = v_wrapper->stack;
  if (!stack) { XSRETURN_UNDEF; }
  p_sv = av_fetch(stack, index+v_wrapper->result, 0);
  if (!p_sv) { XSRETURN_UNDEF; }
  XPUSHs (sv_mortalcopy(*p_sv));
}

void
result_set( v_wrapper, sv )
    V_Wrapper *v_wrapper;
    SV* sv;
PPCODE:
{
  IV result_ix;
  SV **p_stored_sv;
  AV *stack = v_wrapper->stack;
  if (!stack)
    {
      croak ("Problem in v->result_set(): valuator is not in stack mode");
    }
  result_ix = v_wrapper->result;
  av_fill(stack, result_ix);

  SvREFCNT_inc (sv);
  p_stored_sv = av_store (stack, result_ix, sv);
  if (!p_stored_sv)
    {
      SvREFCNT_dec (sv);
    }
}

void
stack_step( v_wrapper )
    V_Wrapper *v_wrapper;
PPCODE:
{
  Scanless_R *slr;

  if (v_wrapper->mode != MARPA_XS_V_MODE_IS_STACK)
    {
      croak
        ("Problem in v->stack_step(): Cannot call unless valuator is in 'stack' mode");
    }

  slr = v_wrapper->slr;
  xlua_sig_call (slr->L, "local recce = ...; recce.trace_values_queue = {}", "R",
      slr->lua_ref);

  while (1)
    {
      int step_type;
      xlua_sig_call (slr->L, "local recce = ...; recce:step()", "R",
          slr->lua_ref);
      step_type = marpa_v_step_type(v_wrapper->v);
      switch (step_type)
        {
        case MARPA_STEP_INACTIVE:
          XSRETURN_EMPTY;

          /* NOTREACHED */
        case MARPA_STEP_RULE:
        case MARPA_STEP_NULLING_SYMBOL:
        case MARPA_STEP_TOKEN:
          {
            int ix;
            SV *stack_results[3];
            int stack_offset = v_do_stack_ops (v_wrapper, stack_results);
            if (stack_offset < 0)
              {
                goto NEXT_STEP;
              }
            for (ix = 0; ix < stack_offset; ix++)
              {
                XPUSHs (stack_results[ix]);
              }
            XSRETURN (stack_offset);
          }
          /* NOTREACHED */

        default:
          /* Default is just return the step_type string and let the upper
           * layer deal with it.
           */
          {
            const char *step_type_string = step_type_to_string (step_type);
            if (!step_type_string)
              {
                step_type_string = "Unknown";
              }
            XPUSHs (sv_2mortal (newSVpv (step_type_string, 0)));
            XSRETURN (1);
          }
        }

    NEXT_STEP:;
      {
        int trace_queue_length;
        xlua_sig_call (slr->L, "local recce = ...; return #recce.trace_values_queue", "R>i",
            slr->lua_ref, &trace_queue_length);
      if (trace_queue_length)
        {
          XSRETURN_PV ("trace");
        }
      }
    }
}

void
step_type( v_wrapper )
    V_Wrapper *v_wrapper;
PPCODE:
{
  const Marpa_Value v = v_wrapper->v;
  const Marpa_Step_Type status = marpa_v_step_type (v);
  const char *result_string;
  result_string = step_type_to_string (status);
  if (!result_string)
    {
      result_string =
        form ("Problem in v->step(): unknown step type %d", status);
      set_error_from_string (v_wrapper->base, savepv (result_string));
      if (v_wrapper->base->throw)
        {
          croak ("%s", result_string);
        }
    }
  XPUSHs (sv_2mortal (newSVpv (result_string, 0)));
}

void
location( v_wrapper )
    V_Wrapper *v_wrapper;
PPCODE:
{
  const Marpa_Value v = v_wrapper->v;
  const Marpa_Step_Type status = marpa_v_step_type (v);
  if (status == MARPA_STEP_RULE)
    {
      XPUSHs (sv_2mortal (newSViv (marpa_v_rule_start_es_id (v))));
      XPUSHs (sv_2mortal (newSViv (marpa_v_es_id (v))));
      XSRETURN (2);
    }
  if (status == MARPA_STEP_NULLING_SYMBOL)
    {
      XPUSHs (sv_2mortal (newSViv (marpa_v_token_start_es_id (v))));
      XPUSHs (sv_2mortal (newSViv (marpa_v_es_id (v))));
      XSRETURN (2);
    }
  if (status == MARPA_STEP_TOKEN)
    {
      XPUSHs (sv_2mortal (newSViv (marpa_v_token_start_es_id (v))));
      XPUSHs (sv_2mortal (newSViv (marpa_v_es_id (v))));
      XSRETURN (2);
    }
  XSRETURN_EMPTY;
}

MODULE = Marpa::R3        PACKAGE = Marpa::R3::Thin::G

void
_marpa_g_nsy_is_nulling( g_wrapper, nsy_id )
    G_Wrapper *g_wrapper;
    Marpa_NSY_ID nsy_id;
PPCODE:
{
  Marpa_Grammar g = g_wrapper->g;
  int result = _marpa_g_nsy_is_nulling (g, nsy_id);
  if (result < 0)
    {
      croak ("Problem in g->_marpa_g_nsy_is_nulling(%d): %s", nsy_id,
             xs_g_error (g_wrapper));
    }
  if (result)
    XSRETURN_YES;
  XSRETURN_NO;
}

void
_marpa_g_nsy_is_start( g_wrapper, nsy_id )
    G_Wrapper *g_wrapper;
    Marpa_NSY_ID nsy_id;
PPCODE:
{
  Marpa_Grammar g = g_wrapper->g;
  int result = _marpa_g_nsy_is_start (g, nsy_id);
  if (result < 0)
    {
      croak ("Invalid nsy %d", nsy_id);
    }
  if (result)
    XSRETURN_YES;
  XSRETURN_NO;
}

# Marpa_Symbol_ID
void
_marpa_g_source_xsy( g_wrapper, symbol_id )
    G_Wrapper *g_wrapper;
    Marpa_Symbol_ID symbol_id;
PPCODE:
{
  Marpa_Grammar g = g_wrapper->g;
  Marpa_Symbol_ID source_xsy = _marpa_g_source_xsy (g, symbol_id);
  if (source_xsy < -1)
    {
      croak ("problem with g->_marpa_g_source_xsy: %s", xs_g_error (g_wrapper));
    }
  if (source_xsy < 0)
    {
      XSRETURN_UNDEF;
    }
  XPUSHs (sv_2mortal (newSViv (source_xsy)));
}

# Marpa_Rule_ID
void
_marpa_g_nsy_lhs_xrl( g_wrapper, nsy_id )
    G_Wrapper *g_wrapper;
    Marpa_NSY_ID nsy_id;
PPCODE:
{
  Marpa_Grammar g = g_wrapper->g;
  Marpa_Rule_ID rule_id = _marpa_g_nsy_lhs_xrl (g, nsy_id);
  if (rule_id < -1)
    {
      croak ("problem with g->_marpa_g_nsy_lhs_xrl: %s",
             xs_g_error (g_wrapper));
    }
  if (rule_id < 0)
    {
      XSRETURN_UNDEF;
    }
  XPUSHs (sv_2mortal (newSViv (rule_id)));
}

# Marpa_Rule_ID
void
_marpa_g_nsy_xrl_offset( g_wrapper, nsy_id )
    G_Wrapper *g_wrapper;
    Marpa_NSY_ID nsy_id;
PPCODE:
{
  Marpa_Grammar g = g_wrapper->g;
  int offset = _marpa_g_nsy_xrl_offset (g, nsy_id);
  if (offset == -1)
    {
      XSRETURN_UNDEF;
    }
  if (offset < 0)
    {
      croak ("problem with g->_marpa_g_nsy_xrl_offset: %s",
             xs_g_error (g_wrapper));
    }
  XPUSHs (sv_2mortal (newSViv (offset)));
}

# int
void
_marpa_g_virtual_start( g_wrapper, irl_id )
    G_Wrapper *g_wrapper;
    Marpa_IRL_ID irl_id;
PPCODE:
{
  Marpa_Grammar g = g_wrapper->g;
  int result = _marpa_g_virtual_start (g, irl_id);
  if (result == -1)
    {
      XSRETURN_UNDEF;
    }
  if (result < 0)
    {
      croak ("Problem in g->_marpa_g_virtual_start(%d): %s", irl_id,
             xs_g_error (g_wrapper));
    }
    XPUSHs( sv_2mortal( newSViv(result) ) );
}

# int
void
_marpa_g_virtual_end( g_wrapper, irl_id )
    G_Wrapper *g_wrapper;
    Marpa_IRL_ID irl_id;
PPCODE:
{
  Marpa_Grammar g = g_wrapper->g;
  int result = _marpa_g_virtual_end (g, irl_id);
  if (result <= -2)
    {
      croak ("Problem in g->_marpa_g_virtual_end(%d): %s", irl_id,
             xs_g_error (g_wrapper));
    }
  XPUSHs (sv_2mortal (newSViv (result)));
}

void
_marpa_g_rule_is_used( g_wrapper, rule_id )
    G_Wrapper *g_wrapper;
    Marpa_Rule_ID rule_id;
PPCODE:
{
  Marpa_Grammar g = g_wrapper->g;
  int result = _marpa_g_rule_is_used (g, rule_id);
  if (result < 0)
    {
      croak ("Problem in g->_marpa_g_rule_is_used(%d): %s", rule_id,
             xs_g_error (g_wrapper));
    }
  if (result)
    XSRETURN_YES;
  XSRETURN_NO;
}

void
_marpa_g_irl_is_virtual_lhs( g_wrapper, irl_id )
    G_Wrapper *g_wrapper;
    Marpa_IRL_ID irl_id;
PPCODE:
{
  Marpa_Grammar g = g_wrapper->g;
  int result = _marpa_g_irl_is_virtual_lhs (g, irl_id);
  if (result < 0)
    {
      croak ("Problem in g->_marpa_g_irl_is_virtual_lhs(%d): %s", irl_id,
             xs_g_error (g_wrapper));
    }
  if (result)
    XSRETURN_YES;
  XSRETURN_NO;
}

void
_marpa_g_irl_is_virtual_rhs( g_wrapper, irl_id )
    G_Wrapper *g_wrapper;
    Marpa_IRL_ID irl_id;
PPCODE:
{
  Marpa_Grammar g = g_wrapper->g;
  int result = _marpa_g_irl_is_virtual_rhs (g, irl_id);
  if (result < 0)
    {
      croak ("Problem in g->_marpa_g_irl_is_virtual_rhs(%d): %s", irl_id,
             xs_g_error (g_wrapper));
    }
  if (result)
    XSRETURN_YES;
  XSRETURN_NO;
}

# Marpa_Rule_ID
void
_marpa_g_real_symbol_count( g_wrapper, rule_id )
    G_Wrapper *g_wrapper;
    Marpa_Rule_ID rule_id;
PPCODE:
{
  Marpa_Grammar g = g_wrapper->g;
    int result = _marpa_g_real_symbol_count(g, rule_id);
  if (result <= -2)
    {
      croak ("Problem in g->_marpa_g_real_symbol_count(%d): %s", rule_id,
             xs_g_error (g_wrapper));
    }
  if (result == -1)
    {
      XSRETURN_UNDEF;
    }
  XPUSHs (sv_2mortal (newSViv (result)));
}

# Marpa_Rule_ID
void
_marpa_g_source_xrl ( g_wrapper, irl_id )
    G_Wrapper *g_wrapper;
    Marpa_IRL_ID irl_id;
PPCODE:
{
  Marpa_Grammar g = g_wrapper->g;
  int result = _marpa_g_source_xrl (g, irl_id);
  if (result <= -2)
    {
      croak ("Problem in g->_marpa_g_source_xrl (%d): %s", irl_id,
             xs_g_error (g_wrapper));
    }
  if (result == -1)
    {
      XSRETURN_UNDEF;
    }
  XPUSHs (sv_2mortal (newSViv (result)));
}

# Marpa_Rule_ID
void
_marpa_g_irl_semantic_equivalent( g_wrapper, irl_id )
    G_Wrapper *g_wrapper;
    Marpa_IRL_ID irl_id;
PPCODE:
{
  Marpa_Grammar g = g_wrapper->g;
  int result = _marpa_g_irl_semantic_equivalent (g, irl_id);
  if (result <= -2)
    {
      croak ("Problem in g->_marpa_g_irl_semantic_equivalent(%d): %s", irl_id,
             xs_g_error (g_wrapper));
    }
  if (result == -1)
    {
      XSRETURN_UNDEF;
    }
  XPUSHs (sv_2mortal (newSViv (result)));
}

# int
void
_marpa_g_ahm_count( g_wrapper )
    G_Wrapper *g_wrapper;
PPCODE:
{
  Marpa_Grammar g = g_wrapper->g;
  int result = _marpa_g_ahm_count (g);
  if (result <= -2)
    {
      croak ("Problem in g->_marpa_g_ahm_count(): %s", xs_g_error (g_wrapper));
    }
  if (result < 0)
    {
      XSRETURN_UNDEF;
    }
  XPUSHs (sv_2mortal (newSViv (result)));
}

# int
void
_marpa_g_irl_count( g_wrapper )
    G_Wrapper *g_wrapper;
PPCODE:
{
  Marpa_Grammar g = g_wrapper->g;
  int result = _marpa_g_irl_count (g);
  if (result < -1)
    {
      croak ("Problem in g->_marpa_g_irl_count(): %s", xs_g_error (g_wrapper));
    }
  if (result < 0)
    {
      XSRETURN_UNDEF;
    }
  XPUSHs (sv_2mortal (newSViv (result)));
}

# int
void
_marpa_g_nsy_count( g_wrapper )
    G_Wrapper *g_wrapper;
PPCODE:
{
  Marpa_Grammar g = g_wrapper->g;
  int result = _marpa_g_nsy_count (g);
  if (result < -1)
    {
      croak ("Problem in g->_marpa_g_nsy_count(): %s", xs_g_error (g_wrapper));
    }
  if (result < 0)
    {
      XSRETURN_UNDEF;
    }
  XPUSHs (sv_2mortal (newSViv (result)));
}

# Marpa_IRL_ID
void
_marpa_g_ahm_irl( g_wrapper, item_id )
    G_Wrapper *g_wrapper;
    Marpa_AHM_ID item_id;
PPCODE:
{
    Marpa_Grammar g = g_wrapper->g;
    int result = _marpa_g_ahm_irl(g, item_id);
    if (result < 0) { XSRETURN_UNDEF; }
      XPUSHs (sv_2mortal (newSViv (result)));
}

 # -1 is a valid return value, so -2 indicates an error
# int
void
_marpa_g_ahm_position( g_wrapper, item_id )
    G_Wrapper *g_wrapper;
    Marpa_AHM_ID item_id;
PPCODE:
{
    Marpa_Grammar g = g_wrapper->g;
    int result = _marpa_g_ahm_position(g, item_id);
    if (result <= -2) { XSRETURN_UNDEF; }
      XPUSHs (sv_2mortal (newSViv (result)));
}

 # -1 is a valid return value, and -2 indicates an error
# Marpa_Symbol_ID
void
_marpa_g_ahm_postdot( g_wrapper, item_id )
    G_Wrapper *g_wrapper;
    Marpa_AHM_ID item_id;
PPCODE:
{
    Marpa_Grammar g = g_wrapper->g;
    int result = _marpa_g_ahm_postdot(g, item_id);
    if (result <= -2) { XSRETURN_UNDEF; }
      XPUSHs (sv_2mortal (newSViv (result)));
}

MODULE = Marpa::R3        PACKAGE = Marpa::R3::Thin::R

void
_marpa_r_is_use_leo_set( r_wrapper, boolean )
    R_Wrapper *r_wrapper;
    int boolean;
PPCODE:
{
  struct marpa_r *r = r_wrapper->r;
  int result = _marpa_r_is_use_leo_set (r, (boolean ? TRUE : FALSE));
  if (result < 0)
    {
      croak ("Problem in _marpa_r_is_use_leo_set(): %s",
             xs_g_error(r_wrapper->base));
    }
  XSRETURN_YES;
}

void
_marpa_r_is_use_leo( r_wrapper )
    R_Wrapper *r_wrapper;
PPCODE:
{
  struct marpa_r *r = r_wrapper->r;
  int boolean = _marpa_r_is_use_leo (r);
  if (boolean < 0)
    {
      croak ("Problem in _marpa_r_is_use_leo(): %s", xs_g_error(r_wrapper->base));
    }
  if (boolean)
    XSRETURN_YES;
  XSRETURN_NO;
}

void
_marpa_r_earley_set_size( r_wrapper, set_ordinal )
    R_Wrapper *r_wrapper;
    Marpa_Earley_Set_ID set_ordinal;
PPCODE:
    {
      struct marpa_r *r = r_wrapper->r;
      int earley_set_size = _marpa_r_earley_set_size (r, set_ordinal);
      if (earley_set_size < 0) {
          croak ("Problem in r->_marpa_r_earley_set_size(): %s", xs_g_error(r_wrapper->base));
        }
      XPUSHs (sv_2mortal (newSViv (earley_set_size)));
    }

void
_marpa_r_earley_set_trace( r_wrapper, set_ordinal )
    R_Wrapper *r_wrapper;
    Marpa_Earley_Set_ID set_ordinal;
PPCODE:
    { struct marpa_r* r = r_wrapper->r;
    Marpa_AHM_ID result = _marpa_r_earley_set_trace(
        r, set_ordinal );
    if (result == -1) { XSRETURN_UNDEF; }
    if (result < 0) { croak("problem with r->_marpa_r_earley_set_trace: %s", xs_g_error(r_wrapper->base)); }
    XPUSHs( sv_2mortal( newSViv(result) ) );
    }

void
_marpa_r_earley_item_trace( r_wrapper, item_ordinal )
    R_Wrapper *r_wrapper;
    Marpa_Earley_Item_ID item_ordinal;
PPCODE:
    { struct marpa_r* r = r_wrapper->r;
    Marpa_AHM_ID result = _marpa_r_earley_item_trace(
        r, item_ordinal);
    if (result == -1) { XSRETURN_UNDEF; }
    if (result < 0) { croak("problem with r->_marpa_r_earley_item_trace: %s", xs_g_error(r_wrapper->base)); }
    XPUSHs( sv_2mortal( newSViv(result) ) );
    }

void
_marpa_r_earley_item_origin( r_wrapper )
    R_Wrapper *r_wrapper;
PPCODE:
    {
      struct marpa_r *r = r_wrapper->r;
      int origin_earleme = _marpa_r_earley_item_origin (r);
      if (origin_earleme < 0)
        {
      croak ("Problem with r->_marpa_r_earley_item_origin(): %s",
                 xs_g_error(r_wrapper->base));
        }
      XPUSHs (sv_2mortal (newSViv (origin_earleme)));
    }

void
_marpa_r_first_token_link_trace( r_wrapper )
    R_Wrapper *r_wrapper;
PPCODE:
    { struct marpa_r* r = r_wrapper->r;
    int token_id = _marpa_r_first_token_link_trace(r);
    if (token_id <= -2) { croak("Trace first token link problem: %s", xs_g_error(r_wrapper->base)); }
    if (token_id == -1) { XSRETURN_UNDEF; }
    XPUSHs( sv_2mortal( newSViv(token_id) ) );
    }

void
_marpa_r_next_token_link_trace( r_wrapper )
    R_Wrapper *r_wrapper;
PPCODE:
    { struct marpa_r* r = r_wrapper->r;
    int token_id = _marpa_r_next_token_link_trace(r);
    if (token_id <= -2) { croak("Trace next token link problem: %s", xs_g_error(r_wrapper->base)); }
    if (token_id == -1) { XSRETURN_UNDEF; }
    XPUSHs( sv_2mortal( newSViv(token_id) ) );
    }

void
_marpa_r_first_completion_link_trace( r_wrapper )
    R_Wrapper *r_wrapper;
PPCODE:
    { struct marpa_r* r = r_wrapper->r;
    int AHFA_state_id = _marpa_r_first_completion_link_trace(r);
    if (AHFA_state_id <= -2) { croak("Trace first completion link problem: %s", xs_g_error(r_wrapper->base)); }
    if (AHFA_state_id == -1) { XSRETURN_UNDEF; }
    XPUSHs( sv_2mortal( newSViv(AHFA_state_id) ) );
    }

void
_marpa_r_next_completion_link_trace( r_wrapper )
    R_Wrapper *r_wrapper;
PPCODE:
    { struct marpa_r* r = r_wrapper->r;
    int AHFA_state_id = _marpa_r_next_completion_link_trace(r);
    if (AHFA_state_id <= -2) { croak("Trace next completion link problem: %s", xs_g_error(r_wrapper->base)); }
    if (AHFA_state_id == -1) { XSRETURN_UNDEF; }
    XPUSHs( sv_2mortal( newSViv(AHFA_state_id) ) );
    }

void
_marpa_r_first_leo_link_trace( r_wrapper )
    R_Wrapper *r_wrapper;
PPCODE:
    { struct marpa_r* r = r_wrapper->r;
    int AHFA_state_id = _marpa_r_first_leo_link_trace(r);
    if (AHFA_state_id <= -2) { croak("Trace first completion link problem: %s", xs_g_error(r_wrapper->base)); }
    if (AHFA_state_id == -1) { XSRETURN_UNDEF; }
    XPUSHs( sv_2mortal( newSViv(AHFA_state_id) ) );
    }

void
_marpa_r_next_leo_link_trace( r_wrapper )
    R_Wrapper *r_wrapper;
PPCODE:
    { struct marpa_r* r = r_wrapper->r;
    int AHFA_state_id = _marpa_r_next_leo_link_trace(r);
    if (AHFA_state_id <= -2) { croak("Trace next completion link problem: %s", xs_g_error(r_wrapper->base)); }
    if (AHFA_state_id == -1) { XSRETURN_UNDEF; }
    XPUSHs( sv_2mortal( newSViv(AHFA_state_id) ) );
    }

void
_marpa_r_source_predecessor_state( r_wrapper )
    R_Wrapper *r_wrapper;
PPCODE:
    { struct marpa_r* r = r_wrapper->r;
    int state_id = _marpa_r_source_predecessor_state(r);
    if (state_id <= -2) { croak("Problem finding trace source predecessor state: %s", xs_g_error(r_wrapper->base)); }
    if (state_id == -1) { XSRETURN_UNDEF; }
    XPUSHs( sv_2mortal( newSViv(state_id) ) );
    }

void
_marpa_r_source_leo_transition_symbol( r_wrapper )
    R_Wrapper *r_wrapper;
PPCODE:
    { struct marpa_r* r = r_wrapper->r;
    int symbol_id = _marpa_r_source_leo_transition_symbol(r);
    if (symbol_id <= -2) { croak("Problem finding trace source leo transition symbol: %s", xs_g_error(r_wrapper->base)); }
    if (symbol_id == -1) { XSRETURN_UNDEF; }
    XPUSHs( sv_2mortal( newSViv(symbol_id) ) );
    }

void
_marpa_r_source_token( r_wrapper )
    R_Wrapper *r_wrapper;
PPCODE:
    { struct marpa_r* r = r_wrapper->r;
    int value;
    int symbol_id = _marpa_r_source_token(r, &value);
    if (symbol_id == -1) { XSRETURN_UNDEF; }
    if (symbol_id < 0) { croak("Problem with r->source_token(): %s", xs_g_error(r_wrapper->base)); }
        XPUSHs( sv_2mortal( newSViv(symbol_id) ) );
        XPUSHs( sv_2mortal( newSViv(value) ) );
    }

void
_marpa_r_source_middle( r_wrapper )
    R_Wrapper *r_wrapper;
PPCODE:
    { struct marpa_r* r = r_wrapper->r;
    int middle = _marpa_r_source_middle(r);
    if (middle <= -2) { croak("Problem with r->source_middle(): %s", xs_g_error(r_wrapper->base)); }
    if (middle == -1) { XSRETURN_UNDEF; }
    XPUSHs( sv_2mortal( newSViv(middle) ) );
    }

void
_marpa_r_first_postdot_item_trace( r_wrapper )
    R_Wrapper *r_wrapper;
PPCODE:
    { struct marpa_r* r = r_wrapper->r;
    int postdot_symbol_id = _marpa_r_first_postdot_item_trace(r);
    if (postdot_symbol_id <= -2) { croak("Trace first postdot item problem: %s", xs_g_error(r_wrapper->base)); }
    if (postdot_symbol_id == -1) { XSRETURN_UNDEF; }
    XPUSHs( sv_2mortal( newSViv(postdot_symbol_id) ) );
    }

void
_marpa_r_next_postdot_item_trace( r_wrapper )
    R_Wrapper *r_wrapper;
PPCODE:
    { struct marpa_r* r = r_wrapper->r;
    int postdot_symbol_id = _marpa_r_next_postdot_item_trace(r);
    if (postdot_symbol_id <= -2) { croak("Trace next postdot item problem: %s", xs_g_error(r_wrapper->base)); }
    if (postdot_symbol_id == -1) { XSRETURN_UNDEF; }
    XPUSHs( sv_2mortal( newSViv(postdot_symbol_id) ) );
    }

void
_marpa_r_postdot_symbol_trace( r_wrapper, symid )
    R_Wrapper *r_wrapper;
    Marpa_Symbol_ID symid;
PPCODE:
{
  struct marpa_r *r = r_wrapper->r;
  int postdot_symbol_id = _marpa_r_postdot_symbol_trace (r, symid);
  if (postdot_symbol_id == -1)
    {
      XSRETURN_UNDEF;
    }
  if (postdot_symbol_id <= 0)
    {
      croak ("Problem in r->postdot_symbol_trace: %s", xs_g_error(r_wrapper->base));
    }
  XPUSHs (sv_2mortal (newSViv (postdot_symbol_id)));
}

void
_marpa_r_leo_base_state( r_wrapper )
    R_Wrapper *r_wrapper;
PPCODE:
    {
      struct marpa_r *r = r_wrapper->r;
      int leo_base_state = _marpa_r_leo_base_state (r);
      if (leo_base_state == -1) { XSRETURN_UNDEF; }
      if (leo_base_state < 0) {
          croak ("Problem in r->leo_base_state(): %s", xs_g_error(r_wrapper->base));
        }
      XPUSHs (sv_2mortal (newSViv (leo_base_state)));
    }

void
_marpa_r_leo_base_origin( r_wrapper )
    R_Wrapper *r_wrapper;
PPCODE:
    {
      struct marpa_r *r = r_wrapper->r;
      int leo_base_origin = _marpa_r_leo_base_origin (r);
      if (leo_base_origin == -1) { XSRETURN_UNDEF; }
      if (leo_base_origin < 0) {
          croak ("Problem in r->leo_base_origin(): %s", xs_g_error(r_wrapper->base));
        }
      XPUSHs (sv_2mortal (newSViv (leo_base_origin)));
    }

void
_marpa_r_trace_earley_set( r_wrapper )
    R_Wrapper *r_wrapper;
PPCODE:
    {
      struct marpa_r *r = r_wrapper->r;
      int trace_earley_set = _marpa_r_trace_earley_set (r);
      if (trace_earley_set < 0) {
          croak ("Problem in r->trace_earley_set(): %s", xs_g_error(r_wrapper->base));
        }
      XPUSHs (sv_2mortal (newSViv (trace_earley_set)));
    }

void
_marpa_r_postdot_item_symbol( r_wrapper )
    R_Wrapper *r_wrapper;
PPCODE:
    {
      struct marpa_r *r = r_wrapper->r;
      int postdot_item_symbol = _marpa_r_postdot_item_symbol (r);
      if (postdot_item_symbol < 0) {
          croak ("Problem in r->postdot_item_symbol(): %s", xs_g_error(r_wrapper->base));
        }
      XPUSHs (sv_2mortal (newSViv (postdot_item_symbol)));
    }

void
_marpa_r_leo_predecessor_symbol( r_wrapper )
    R_Wrapper *r_wrapper;
PPCODE:
    {
      struct marpa_r *r = r_wrapper->r;
      int leo_predecessor_symbol = _marpa_r_leo_predecessor_symbol (r);
      if (leo_predecessor_symbol == -1) { XSRETURN_UNDEF; }
      if (leo_predecessor_symbol < 0) {
          croak ("Problem in r->leo_predecessor_symbol(): %s", xs_g_error(r_wrapper->base));
        }
      XPUSHs (sv_2mortal (newSViv (leo_predecessor_symbol)));
    }

MODULE = Marpa::R3        PACKAGE = Marpa::R3::Thin::B

void
_marpa_b_and_node_token( b_wrapper, and_node_id )
     B_Wrapper *b_wrapper;
     Marpa_And_Node_ID and_node_id;
PPCODE:
{
  Marpa_Bocage b = b_wrapper->b;
  int value = -1;
  int result = _marpa_b_and_node_token (b, and_node_id, &value);
  if (result == -1)
    {
      XSRETURN_UNDEF;
    }
  if (result < 0)
    {
      croak ("Problem in b->_marpa_b_and_node_symbol(): %s",
             xs_g_error(b_wrapper->base));
    }
  XPUSHs (sv_2mortal (newSViv (result)));
  XPUSHs (sv_2mortal (newSViv (value)));
}

MODULE = Marpa::R3        PACKAGE = Marpa::R3::Thin::O

# int
void
_marpa_o_and_node_order_get( o_wrapper, or_node_id, and_ix )
    O_Wrapper *o_wrapper;
    Marpa_Or_Node_ID or_node_id;
    int and_ix;
PPCODE:
{
    Marpa_Order o = o_wrapper->o;
    int result;
    result = _marpa_o_and_order_get(o, or_node_id, and_ix);
    if (result == -1) { XSRETURN_UNDEF; }
    if (result < 0) {
      croak ("Problem in o->_marpa_o_and_node_order_get(): %s", xs_g_error(o_wrapper->base));
    }
    XPUSHs( sv_2mortal( newSViv(result) ) );
}

void
_marpa_o_or_node_and_node_count( o_wrapper, or_node_id )
    O_Wrapper *o_wrapper;
    Marpa_Or_Node_ID or_node_id;
PPCODE:
{
    Marpa_Order o = o_wrapper->o;
    int count = _marpa_o_or_node_and_node_count(o, or_node_id);
    if (count < 0) { croak("Invalid or node ID %d", or_node_id); }
    XPUSHs( sv_2mortal( newSViv(count) ) );
}

void
_marpa_o_or_node_and_node_ids( o_wrapper, or_node_id )
    O_Wrapper *o_wrapper;
    Marpa_Or_Node_ID or_node_id;
PPCODE:
{
    Marpa_Order o = o_wrapper->o;
    int count = _marpa_o_or_node_and_node_count(o, or_node_id);
    if (count == -1) {
      if (GIMME != G_ARRAY) { XSRETURN_NO; }
      count = 0; /* will return an empty array */
    }
    if (count < 0) { croak("Invalid or node ID %d", or_node_id); }
    {
        int ix;
        EXTEND(SP, count);
        for (ix = 0; ix < count; ix++) {
            Marpa_And_Node_ID and_node_id
                = _marpa_o_or_node_and_node_id_by_ix(o, or_node_id, ix);
            PUSHs( sv_2mortal( newSViv(and_node_id) ) );
        }
    }
}

MODULE = Marpa::R3        PACKAGE = Marpa::R3::Thin::T

# int
void
_marpa_t_size( t_wrapper )
    T_Wrapper *t_wrapper;
PPCODE:
{
  Marpa_Tree t = t_wrapper->t;
  int result;
  result = _marpa_t_size (t);
  if (result == -1)
    {
      XSRETURN_UNDEF;
    }
  if (result < 0)
    {
      croak ("Problem in t->_marpa_t_size(): %s", xs_g_error(t_wrapper->base));
    }
  XPUSHs (sv_2mortal (newSViv (result)));
}

# int
void
_marpa_t_nook_or_node( t_wrapper, nook_id )
    T_Wrapper *t_wrapper;
    Marpa_Nook_ID nook_id;
PPCODE:
{
  Marpa_Tree t = t_wrapper->t;
  int result;
  result = _marpa_t_nook_or_node (t, nook_id);
  if (result == -1)
    {
      XSRETURN_UNDEF;
    }
  if (result < 0)
    {
      croak ("Problem in t->_marpa_t_nook_or_node(): %s", xs_g_error(t_wrapper->base));
    }
  XPUSHs (sv_2mortal (newSViv (result)));
}

# int
void
_marpa_t_nook_choice( t_wrapper, nook_id )
    T_Wrapper *t_wrapper;
    Marpa_Nook_ID nook_id;
PPCODE:
{
  Marpa_Tree t = t_wrapper->t;
  int result;
  result = _marpa_t_nook_choice (t, nook_id);
  if (result == -1)
    {
      XSRETURN_UNDEF;
    }
  if (result < 0)
    {
      croak ("Problem in t->_marpa_t_nook_choice(): %s", xs_g_error(t_wrapper->base));
    }
  XPUSHs (sv_2mortal (newSViv (result)));
}

# int
void
_marpa_t_nook_parent( t_wrapper, nook_id )
    T_Wrapper *t_wrapper;
    Marpa_Nook_ID nook_id;
PPCODE:
{
  Marpa_Tree t = t_wrapper->t;
  int result;
  result = _marpa_t_nook_parent (t, nook_id);
  if (result == -1)
    {
      XSRETURN_UNDEF;
    }
  if (result < 0)
    {
      croak ("Problem in t->_marpa_t_nook_parent(): %s", xs_g_error(t_wrapper->base));
    }
  XPUSHs (sv_2mortal (newSViv (result)));
}

# int
void
_marpa_t_nook_is_cause( t_wrapper, nook_id )
    T_Wrapper *t_wrapper;
    Marpa_Nook_ID nook_id;
PPCODE:
{
  Marpa_Tree t = t_wrapper->t;
  int result;
  result = _marpa_t_nook_is_cause (t, nook_id);
  if (result == -1)
    {
      XSRETURN_UNDEF;
    }
  if (result < 0)
    {
      croak ("Problem in t->_marpa_t_nook_is_cause(): %s", xs_g_error(t_wrapper->base));
    }
  XPUSHs (sv_2mortal (newSViv (result)));
}

# int
void
_marpa_t_nook_cause_is_ready( t_wrapper, nook_id )
    T_Wrapper *t_wrapper;
    Marpa_Nook_ID nook_id;
PPCODE:
{
  Marpa_Tree t = t_wrapper->t;
  int result;
  result = _marpa_t_nook_cause_is_ready (t, nook_id);
  if (result == -1)
    {
      XSRETURN_UNDEF;
    }
  if (result < 0)
    {
      croak ("Problem in t->_marpa_t_nook_cause_is_ready(): %s", xs_g_error(t_wrapper->base));
    }
  XPUSHs (sv_2mortal (newSViv (result)));
}


# int
void
_marpa_t_nook_is_predecessor( t_wrapper, nook_id )
    T_Wrapper *t_wrapper;
    Marpa_Nook_ID nook_id;
PPCODE:
{
  Marpa_Tree t = t_wrapper->t;
  int result;
  result = _marpa_t_nook_is_predecessor (t, nook_id);
  if (result == -1)
    {
      XSRETURN_UNDEF;
    }
  if (result < 0)
    {
      croak ("Problem in t->_marpa_t_nook_is_predecessor(): %s", xs_g_error(t_wrapper->base));
    }
  XPUSHs (sv_2mortal (newSViv (result)));
}

# int
void
_marpa_t_nook_predecessor_is_ready( t_wrapper, nook_id )
    T_Wrapper *t_wrapper;
    Marpa_Nook_ID nook_id;
PPCODE:
{
  Marpa_Tree t = t_wrapper->t;
  int result;
  result = _marpa_t_nook_predecessor_is_ready (t, nook_id);
  if (result == -1)
    {
      XSRETURN_UNDEF;
    }
  if (result < 0)
    {
      croak ("Problem in t->_marpa_t_nook_predecessor_is_ready(): %s",
             xs_g_error(t_wrapper->base));
    }
  XPUSHs (sv_2mortal (newSViv (result)));
}

MODULE = Marpa::R3        PACKAGE = Marpa::R3::Thin::V

void
_marpa_v_trace( v_wrapper, flag )
    V_Wrapper *v_wrapper;
    int flag;
PPCODE:
{
  const Marpa_Value v = v_wrapper->v;
  int status;
  status = _marpa_v_trace (v, flag);
  if (status == -1)
    {
      XSRETURN_UNDEF;
    }
  if (status < 0)
    {
      croak ("Problem in v->trace(): %s", xs_g_error(v_wrapper->base));
    }
  XPUSHs (sv_2mortal (newSViv (status)));
}

void
_marpa_v_nook( v_wrapper )
    V_Wrapper *v_wrapper;
PPCODE:
{
  const Marpa_Value v = v_wrapper->v;
  int status;
  status = _marpa_v_nook (v);
  if (status == -1)
    {
      XSRETURN_UNDEF;
    }
  if (status < 0)
    {
      croak ("Problem in v->_marpa_v_nook(): %s", xs_g_error(v_wrapper->base));
    }
  XPUSHs (sv_2mortal (newSViv (status)));
}

MODULE = Marpa::R3        PACKAGE = Marpa::R3::Thin::SLG

void
new( class, l0_sv, g1_sv )
    char * class;
    SV *l0_sv;
    SV *g1_sv;
PPCODE:
{
    SV *new_sv;
    Scanless_G *slg;
    PERL_UNUSED_ARG (class);

    if (!sv_isa (l0_sv, "Marpa::R3::Thin::G"))
      {
          croak
              ("Problem in u->new(): L0 arg is not of type Marpa::R3::Thin::G");
      }
    if (!sv_isa (g1_sv, "Marpa::R3::Thin::G"))
      {
          croak
              ("Problem in u->new(): G1 arg is not of type Marpa::R3::Thin::G");
      }
    Newx (slg, 1, Scanless_G);

    slg->g1_sv = g1_sv;
    SvREFCNT_inc (g1_sv);

    #These do not need references, because parent objects
    #hold references to them
    SET_G_WRAPPER_FROM_G_SV (slg->g1_wrapper, g1_sv)
        slg->g1 = slg->g1_wrapper->g;
    slg->precomputed = 0;

    slg->l0_sv = l0_sv;
    SvREFCNT_inc (l0_sv);

    #Wrapper does not need reference, because parent objects
    #holds references to it
    SET_G_WRAPPER_FROM_G_SV (slg->l0_wrapper, l0_sv);

    {
        int i;
        slg->per_codepoint_hash = newHV ();
        for (i = 0; i < (int) Dim (slg->per_codepoint_array); i++)
          {
              slg->per_codepoint_array[i] = NULL;
          }
    }

    {
        int symbol_ix;
        int g1_symbol_count = marpa_g_highest_symbol_id (slg->g1) + 1;
        Newx (slg->g1_lexeme_to_assertion, (unsigned int)g1_symbol_count,
              Marpa_Assertion_ID);
        for (symbol_ix = 0; symbol_ix < g1_symbol_count; symbol_ix++)
          {
              slg->g1_lexeme_to_assertion[symbol_ix] = -1;
          }
    }

    {
        Marpa_Symbol_ID symbol_id;
        int g1_symbol_count = marpa_g_highest_symbol_id (slg->g1) + 1;
        Newx (slg->symbol_g_properties, (unsigned int)g1_symbol_count,
              struct symbol_g_properties);
        for (symbol_id = 0; symbol_id < g1_symbol_count; symbol_id++)
          {
              slg->symbol_g_properties[symbol_id].priority = 0;
              slg->symbol_g_properties[symbol_id].latm = 0;
              slg->symbol_g_properties[symbol_id].is_lexeme = 0;
              slg->symbol_g_properties[symbol_id].t_pause_before = 0;
              slg->symbol_g_properties[symbol_id].t_pause_before_active =
                  0;
              slg->symbol_g_properties[symbol_id].t_pause_after = 0;
              slg->symbol_g_properties[symbol_id].t_pause_after_active = 0;
          }
    }

    {
        Marpa_Rule_ID rule_id;
        int g1_rule_count =
            marpa_g_highest_rule_id (slg->l0_wrapper->g) + 1;
        Newx (slg->l0_rule_g_properties, ((unsigned int)g1_rule_count),
              struct l0_rule_g_properties);
        for (rule_id = 0; rule_id < g1_rule_count; rule_id++)
          {
              slg->l0_rule_g_properties[rule_id].g1_lexeme = -1;
              slg->l0_rule_g_properties[rule_id].t_event_on_discard = 0;
              slg->l0_rule_g_properties[rule_id].
                  t_event_on_discard_active = 0;
          }
    }

    slg->L = xlua_newstate();

  {
    lua_State* L = slg->L;
    xlua_refcount(L, 1);
    /* Lua stack: [] */
    marpa_lua_newtable(L);
    /* Lua stack: [ grammar_table ] */
    /* No lock held -- SLG must delete grammar table in its */
    /*   destructor. */
    marpa_luaL_setmetatable(L, MT_NAME_GRAMMAR);
    /* Lua stack: [ grammar_table ] */
    marpa_lua_pushlightuserdata(L, slg);
    /* Lua stack: [ grammar_table, lud ] */
    marpa_lua_setfield(L, -2, "lud");
    /* Lua stack: [ grammar_table ] */
    slg->lua_ref =  marpa_luaL_ref(L, LUA_REGISTRYINDEX);
    /* Lua stack: [] */
  }

    new_sv = sv_newmortal ();
    sv_setref_pv (new_sv, scanless_g_class_name, (void *) slg);
    XPUSHs (new_sv);
}

void
DESTROY( slg )
    Scanless_G *slg;
PPCODE:
{
  unsigned int i = 0;
  SvREFCNT_dec (slg->g1_sv);
  SvREFCNT_dec (slg->l0_sv);
  Safefree (slg->symbol_g_properties);
  Safefree (slg->l0_rule_g_properties);
  Safefree (slg->g1_lexeme_to_assertion);
  SvREFCNT_dec (slg->per_codepoint_hash);
  for (i = 0; i < Dim(slg->per_codepoint_array); i++) {
    Safefree(slg->per_codepoint_array[i]);
  }

  /* This is unnecessary at the moment, so the next statement
   * will destroy the Lua state.  But someday grammars may share
   * Lua states, and then this will be necessary.
   */
  marpa_luaL_unref(slg->L, LUA_REGISTRYINDEX, slg->lua_ref);
  xlua_refcount(slg->L, -1);
  Safefree (slg);
}

 #  it does not create a new one
 #
void
g1( slg )
    Scanless_G *slg;
PPCODE:
{
  XPUSHs (sv_2mortal (SvREFCNT_inc_NN (slg->g1_sv)));
}

void
lexer_rule_to_g1_lexeme_set( slg, lexer_rule, g1_lexeme, assertion_id )
    Scanless_G *slg;
    Marpa_Rule_ID lexer_rule;
    Marpa_Symbol_ID g1_lexeme;
    Marpa_Assertion_ID assertion_id;
PPCODE:
{
  Marpa_Rule_ID highest_lexer_rule_id;
  Marpa_Symbol_ID highest_g1_symbol_id;
  Marpa_Assertion_ID highest_assertion_id;

  highest_lexer_rule_id = marpa_g_highest_rule_id (slg->l0_wrapper->g);
  highest_g1_symbol_id = marpa_g_highest_symbol_id (slg->g1);
  highest_assertion_id = marpa_g_highest_zwa_id (slg->l0_wrapper->g);
  if (slg->precomputed)
    {
      croak
        ("slg->lexer_rule_to_g1_lexeme_set(%ld, %ld) called after SLG is precomputed",
         (long) lexer_rule, (long) g1_lexeme);
    }
  if (lexer_rule > highest_lexer_rule_id)
    {
      croak
        ("Problem in slg->lexer_rule_to_g1_lexeme_set(%ld, %ld): rule ID was %ld, but highest lexer rule ID = %ld",
         (long) lexer_rule,
         (long) g1_lexeme, (long) lexer_rule, (long) highest_lexer_rule_id);
    }
  if (g1_lexeme > highest_g1_symbol_id)
    {
      croak
        ("Problem in slg->lexer_rule_to_g1_lexeme_set(%ld, %ld): symbol ID was %ld, but highest G1 symbol ID = %ld",
         (long) lexer_rule,
         (long) g1_lexeme, (long) lexer_rule, (long) highest_g1_symbol_id);
    }
  if (assertion_id > highest_assertion_id)
    {
      croak
        ("Problem in slg->lexer_rule_to_g1_lexeme_set(%ld, %ld, %ld):"
        "assertion ID was %ld, but highest assertion ID = %ld",
         (long) lexer_rule,
         (long) g1_lexeme, (long) lexer_rule,
         (long) assertion_id,
         (long) highest_assertion_id);
    }
  if (lexer_rule < -2)
    {
      croak
        ("Problem in slg->lexer_rule_to_g1_lexeme_set(%ld, %ld): rule ID was %ld, a disallowed value",
         (long) lexer_rule, (long) g1_lexeme,
         (long) lexer_rule);
    }
  if (g1_lexeme < -2)
    {
      croak
        ("Problem in slg->lexer_rule_to_g1_lexeme_set(%ld, %ld): symbol ID was %ld, a disallowed value",
         (long) lexer_rule, (long) g1_lexeme,
         (long) g1_lexeme);
    }
  if (assertion_id < -2)
    {
      croak
        ("Problem in slg->lexer_rule_to_g1_lexeme_set(%ld, %ld, %ld): assertion ID was %ld, a disallowed value",
         (long) lexer_rule, (long) g1_lexeme,
         (long) g1_lexeme, (long)assertion_id);
    }
  if (lexer_rule >= 0) {
      struct l0_rule_g_properties * const l0_rule_g_properties = slg->l0_rule_g_properties + lexer_rule;
      l0_rule_g_properties->g1_lexeme = g1_lexeme;
  }
  if (g1_lexeme >= 0) {
      slg->g1_lexeme_to_assertion[g1_lexeme] = assertion_id;
  }
  XSRETURN_YES;
}

 # Mark the symbol as a lexeme.
 # A priority is required.
 #
void
g1_lexeme_set( slg, g1_lexeme, priority )
    Scanless_G *slg;
    Marpa_Symbol_ID g1_lexeme;
    int priority;
PPCODE:
{
  Marpa_Symbol_ID highest_g1_symbol_id = marpa_g_highest_symbol_id (slg->g1);
    if (slg->precomputed)
      {
        croak
          ("slg->lexeme_priority_set(%ld, %ld) called after SLG is precomputed",
           (long) g1_lexeme, (long) priority);
      }
    if (g1_lexeme > highest_g1_symbol_id)
    {
      croak
        ("Problem in slg->g1_lexeme_priority_set(%ld, %ld): symbol ID was %ld, but highest G1 symbol ID = %ld",
         (long) g1_lexeme,
         (long) priority,
         (long) g1_lexeme,
         (long) highest_g1_symbol_id
         );
    }
    if (g1_lexeme < 0) {
      croak
        ("Problem in slg->g1_lexeme_priority(%ld, %ld): symbol ID was %ld, a disallowed value",
         (long) g1_lexeme,
         (long) priority,
         (long) g1_lexeme);
    }
  slg->symbol_g_properties[g1_lexeme].priority = priority;
  slg->symbol_g_properties[g1_lexeme].is_lexeme = 1;
  XSRETURN_YES;
}

void
g1_lexeme_priority( slg, g1_lexeme )
    Scanless_G *slg;
    Marpa_Symbol_ID g1_lexeme;
PPCODE:
{
  Marpa_Symbol_ID highest_g1_symbol_id = marpa_g_highest_symbol_id (slg->g1);
    if (g1_lexeme > highest_g1_symbol_id)
    {
      croak
        ("Problem in slg->g1_lexeme_priority(%ld): symbol ID was %ld, but highest G1 symbol ID = %ld",
         (long) g1_lexeme,
         (long) g1_lexeme,
         (long) highest_g1_symbol_id
         );
    }
    if (g1_lexeme < 0) {
      croak
        ("Problem in slg->g1_lexeme_priority(%ld): symbol ID was %ld, a disallowed value",
         (long) g1_lexeme,
         (long) g1_lexeme);
    }
  XSRETURN_IV( slg->symbol_g_properties[g1_lexeme].priority);
}

void
g1_lexeme_pause_set( slg, g1_lexeme, pause )
    Scanless_G *slg;
    Marpa_Symbol_ID g1_lexeme;
    int pause;
PPCODE:
{
  Marpa_Symbol_ID highest_g1_symbol_id = marpa_g_highest_symbol_id (slg->g1);
    struct symbol_g_properties * g_properties = slg->symbol_g_properties + g1_lexeme;
    if (slg->precomputed)
      {
        croak
          ("slg->lexeme_pause_set(%ld, %ld) called after SLG is precomputed",
           (long) g1_lexeme, (long) pause);
      }
    if (g1_lexeme > highest_g1_symbol_id)
    {
      croak
        ("Problem in slg->g1_lexeme_pause_set(%ld, %ld): symbol ID was %ld, but highest G1 symbol ID = %ld",
         (long) g1_lexeme,
         (long) pause,
         (long) g1_lexeme,
         (long) highest_g1_symbol_id
         );
    }
    if (g1_lexeme < 0) {
      croak
        ("Problem in slg->lexeme_pause_set(%ld, %ld): symbol ID was %ld, a disallowed value",
         (long) g1_lexeme,
         (long) pause,
         (long) g1_lexeme);
    }
    switch (pause) {
    case 0: /* No pause */
        g_properties->t_pause_after = 0;
        g_properties->t_pause_before = 0;
        break;
    case 1: /* Pause after */
        g_properties->t_pause_after = 1;
        g_properties->t_pause_before = 0;
        break;
    case -1: /* Pause before */
        g_properties->t_pause_after = 0;
        g_properties->t_pause_before = 1;
        break;
    default:
      croak
        ("Problem in slg->lexeme_pause_set(%ld, %ld): value of pause must be -1,0 or 1",
         (long) g1_lexeme,
         (long) pause);
    }
  XSRETURN_YES;
}

void
g1_lexeme_pause_activate( slg, g1_lexeme, activate )
    Scanless_G *slg;
    Marpa_Symbol_ID g1_lexeme;
    int activate;
PPCODE:
{
  Marpa_Symbol_ID highest_g1_symbol_id = marpa_g_highest_symbol_id (slg->g1);
  struct symbol_g_properties *g_properties =
    slg->symbol_g_properties + g1_lexeme;
  if (slg->precomputed)
    {
      croak
        ("slg->lexeme_pause_activate(%ld, %ld) called after SLG is precomputed",
         (long) g1_lexeme, (long) activate);
    }
  if (g1_lexeme > highest_g1_symbol_id)
    {
      croak
        ("Problem in slg->g1_lexeme_pause_activate(%ld, %ld): symbol ID was %ld, but highest G1 symbol ID = %ld",
         (long) g1_lexeme,
         (long) activate, (long) g1_lexeme, (long) highest_g1_symbol_id);
    }
  if (g1_lexeme < 0)
    {
      croak
        ("Problem in slg->lexeme_pause_activate(%ld, %ld): symbol ID was %ld, a disallowed value",
         (long) g1_lexeme, (long) activate, (long) g1_lexeme);
    }

  if (activate != 0 && activate != 1)
    {
      croak
        ("Problem in slg->lexeme_pause_activate(%ld, %ld): value of activate must be 0 or 1",
         (long) g1_lexeme, (long) activate);
    }

  if (g_properties->t_pause_before)
    {
      g_properties->t_pause_before_active = activate ? 1 : 0;
    }
  else if (g_properties->t_pause_after)
    {
      g_properties->t_pause_after_active = activate ? 1 : 0;
    }
  else
    {
      croak
        ("Problem in slg->lexeme_pause_activate(%ld, %ld): no pause event is enabled",
         (long) g1_lexeme, (long) activate);
    }
  XSRETURN_YES;
}

void
discard_event_set( slg, l0_rule_id, boolean )
    Scanless_G *slg;
    Marpa_Rule_ID l0_rule_id;
    int boolean;
PPCODE:
{
  Marpa_Rule_ID highest_l0_rule_id = marpa_g_highest_rule_id (slg->l0_wrapper->g);
    struct l0_rule_g_properties * g_properties = slg->l0_rule_g_properties + l0_rule_id;
    if (slg->precomputed)
      {
        croak
          ("slg->discard_event_set(%ld, %ld) called after SLG is precomputed",
           (long) l0_rule_id, (long) boolean);
      }
    if (l0_rule_id > highest_l0_rule_id)
    {
      croak
        ("Problem in slg->discard_event_set(%ld, %ld): rule ID was %ld, but highest L0 rule ID = %ld",
         (long) l0_rule_id,
         (long) boolean,
         (long) l0_rule_id,
         (long) highest_l0_rule_id
         );
    }
    if (l0_rule_id < 0) {
      croak
        ("Problem in slg->discard_event_set(%ld, %ld): rule ID was %ld, a disallowed value",
         (long) l0_rule_id,
         (long) boolean,
         (long) l0_rule_id);
    }
    switch (boolean) {
    case 0:
    case 1:
        g_properties->t_event_on_discard = boolean ? 1 : 0;
        break;
    default:
      croak
        ("Problem in slg->discard_event_set(%ld, %ld): value must be 0 or 1",
         (long) l0_rule_id,
         (long) boolean);
    }
  XSRETURN_YES;
}

void
discard_event_activate( slg, l0_rule_id, activate )
    Scanless_G *slg;
    Marpa_Rule_ID l0_rule_id;
    int activate;
PPCODE:
{
  Marpa_Rule_ID highest_l0_rule_id = marpa_g_highest_rule_id (slg->l0_wrapper->g);
  struct l0_rule_g_properties *g_properties =
    slg->l0_rule_g_properties + l0_rule_id;
  if (slg->precomputed)
    {
      croak
        ("slg->discard_event_activate(%ld, %ld) called after SLG is precomputed",
         (long) l0_rule_id, (long) activate);
    }
  if (l0_rule_id > highest_l0_rule_id)
    {
      croak
        ("Problem in slg->discard_event_activate(%ld, %ld): rule ID was %ld, but highest L0 rule ID = %ld",
         (long) l0_rule_id,
         (long) activate, (long) l0_rule_id, (long) highest_l0_rule_id);
    }
  if (l0_rule_id < 0)
    {
      croak
        ("Problem in slg->discard_event_activate(%ld, %ld): rule ID was %ld, a disallowed value",
         (long) l0_rule_id, (long) activate, (long) l0_rule_id);
    }

  if (activate != 0 && activate != 1)
    {
      croak
        ("Problem in slg->discard_event_activate(%ld, %ld): value of activate must be 0 or 1",
         (long) l0_rule_id, (long) activate);
    }

  if (g_properties->t_event_on_discard)
    {
      g_properties->t_event_on_discard_active = activate ? 1 : 0;
    }
  else
    {
      croak
        ("Problem in slg->discard_event_activate(%ld, %ld): discard event is not enabled",
         (long) l0_rule_id, (long) activate);
    }
  XSRETURN_YES;
}

void
g1_lexeme_latm_set( slg, g1_lexeme, latm )
    Scanless_G *slg;
    Marpa_Symbol_ID g1_lexeme;
    int latm;
PPCODE:
{
  Marpa_Symbol_ID highest_g1_symbol_id = marpa_g_highest_symbol_id (slg->g1);
    struct symbol_g_properties * g_properties = slg->symbol_g_properties + g1_lexeme;
    if (slg->precomputed)
      {
        croak
          ("slg->lexeme_latm_set(%ld, %ld) called after SLG is precomputed",
           (long) g1_lexeme, (long) latm);
      }
    if (g1_lexeme > highest_g1_symbol_id)
    {
      croak
        ("Problem in slg->g1_lexeme_latm(%ld, %ld): symbol ID was %ld, but highest G1 symbol ID = %ld",
         (long) g1_lexeme,
         (long) latm,
         (long) g1_lexeme,
         (long) highest_g1_symbol_id
         );
    }
    if (g1_lexeme < 0) {
      croak
        ("Problem in slg->lexeme_latm(%ld, %ld): symbol ID was %ld, a disallowed value",
         (long) g1_lexeme,
         (long) latm,
         (long) g1_lexeme);
    }
    switch (latm) {
    case 0: case 1:
        g_properties->latm = latm ? 1 : 0;
        break;
    default:
      croak
        ("Problem in slg->lexeme_latm(%ld, %ld): value of latm must be 0 or 1",
         (long) g1_lexeme,
         (long) latm);
    }
  XSRETURN_YES;
}

void
precompute( slg )
    Scanless_G *slg;
PPCODE:
{
  /* Currently this routine does nothing except set a flag to
   * enforce the * separation of the precomputation phase
   * from the main processing.
   */
  if (!slg->precomputed)
    {
      /*
       * Ensure that I can call this multiple times safely, even
       * if I do some real processing here.
       */
      slg->precomputed = 1;
    }
  XSRETURN_IV (1);
}

MODULE = Marpa::R3        PACKAGE = Marpa::R3::Thin::SLR

void
new( class, slg_sv, r1_sv )
    char * class;
    SV *slg_sv;
    SV *r1_sv;
PPCODE:
{
  SV *new_sv;
  Scanless_R *slr;
  Scanless_G *slg;
  PERL_UNUSED_ARG(class);

  if (!sv_isa (slg_sv, "Marpa::R3::Thin::SLG"))
    {
      croak
        ("Problem in u->new(): slg arg is not of type Marpa::R3::Thin::SLG");
    }
  if (!sv_isa (r1_sv, "Marpa::R3::Thin::R"))
    {
      croak ("Problem in u->new(): r1 arg is not of type Marpa::R3::Thin::R");
    }
  Newx (slr, 1, Scanless_R);

  slr->throw = 1;
  slr->trace_lexers = 0;
  slr->trace_terminals = 0;
  slr->r0 = NULL;

# Copy and take references to the "parent objects",
# the ones responsible for holding references.
  slr->slg_sv = slg_sv;
  SvREFCNT_inc (slg_sv);
  slr->r1_sv = r1_sv;
  SvREFCNT_inc (r1_sv);

# These do not need references, because parent objects
# hold references to them
  SET_R_WRAPPER_FROM_R_SV (slr->r1_wrapper, r1_sv);
  SET_SLG_FROM_SLG_SV (slg, slg_sv);
  if (!slg->precomputed)
    {
      croak
        ("Problem in u->new(): Attempted to create SLIF recce from unprecomputed SLIF grammar");
    }
  slr->slg = slg;
  slr->r1 = slr->r1_wrapper->r;
  SET_G_WRAPPER_FROM_G_SV (slr->g1_wrapper, slr->r1_wrapper->base_sv);

  slr->start_of_lexeme = 0;
  slr->end_of_lexeme = 0;
  slr->is_external_scanning = 0;

  slr->perl_pos = 0;
  slr->last_perl_pos = -1;
  slr->problem_pos = -1;

  slr->token_values = newAV ();
  av_fill (slr->token_values, TOKEN_VALUE_IS_LITERAL);

  {
    Marpa_Symbol_ID symbol_id;
    const Marpa_Symbol_ID g1_symbol_count =
      marpa_g_highest_symbol_id (slg->g1) + 1;
    Newx (slr->symbol_r_properties, ((unsigned int)g1_symbol_count),
          struct symbol_r_properties);
    for (symbol_id = 0; symbol_id < g1_symbol_count; symbol_id++)
      {
        const struct symbol_g_properties *g_properties =
          slg->symbol_g_properties + symbol_id;
        slr->symbol_r_properties[symbol_id].lexeme_priority =
          g_properties->priority;
        slr->symbol_r_properties[symbol_id].t_pause_before_active =
          g_properties->t_pause_before_active;
        slr->symbol_r_properties[symbol_id].t_pause_after_active =
          g_properties->t_pause_after_active;
      }
  }

  {
    Marpa_Rule_ID l0_rule_id;
    const Marpa_Rule_ID l0_rule_count =
      marpa_g_highest_rule_id (slg->l0_wrapper->g) + 1;
    Newx (slr->l0_rule_r_properties, (unsigned)l0_rule_count,
          struct l0_rule_r_properties);
    for (l0_rule_id = 0; l0_rule_id < l0_rule_count; l0_rule_id++)
      {
        const struct l0_rule_g_properties *g_properties =
          slg->l0_rule_g_properties + l0_rule_id;
        slr->l0_rule_r_properties[l0_rule_id].t_event_on_discard_active =
          g_properties->t_event_on_discard_active;
      }
  }

  slr->lexer_start_pos = slr->perl_pos;
  slr->lexer_read_result = 0;
  slr->r1_earleme_complete_result = 0;
  slr->start_of_pause_lexeme = -1;
  slr->end_of_pause_lexeme = -1;

  slr->pos_db = 0;
  slr->pos_db_logical_size = -1;
  slr->pos_db_physical_size = -1;

  slr->input_symbol_id = -1;
  slr->input = newSVpvn ("", 0);
  slr->end_pos = 0;
  slr->too_many_earley_items = -1;

  {
    lua_State* L = slr->slg->L;
    slr->L = L;
    xlua_refcount(L, 1);
    /* Lua stack: [] */
    marpa_lua_newtable(L);
    /* Lua stack: [ recce_table ] */
    /* No lock held -- SLR must delete recce table in its */
    /*   destructor. */
    marpa_luaL_setmetatable(L, MT_NAME_RECCE);
    /* Lua stack: [ recce_table ] */
    marpa_lua_pushlightuserdata(L, slr);
    /* Lua stack: [ recce_table, lud ] */
    marpa_lua_setfield(L, -2, "lud");
    /* Lua stack: [ recce_table ] */
    slr->lua_ref =  marpa_luaL_ref(L, LUA_REGISTRYINDEX);
    /* Lua stack: [] */
  }

  slr->v_wrapper = NULL;

  slr->t_count_of_deleted_events = 0;
  slr->t_event_count = 0;
  slr->t_event_capacity = (int)MAX (1024 / sizeof (union marpa_slr_event_s), 16);
  Newx (slr->t_events, (unsigned int)slr->t_event_capacity, union marpa_slr_event_s);

  slr->t_lexeme_count = 0;
  slr->t_lexeme_capacity = (int)MAX (1024 / sizeof (union marpa_slr_event_s), 16);
  Newx (slr->t_lexemes, (unsigned int)slr->t_lexeme_capacity, union marpa_slr_event_s);

  new_sv = sv_newmortal ();
  sv_setref_pv (new_sv, scanless_r_class_name, (void *) slr);
  XPUSHs (new_sv);
}

void
DESTROY( slr )
    Scanless_R *slr;
PPCODE:
{
  const Marpa_Recce r0 = slr->r0;

  marpa_luaL_unref(slr->L, LUA_REGISTRYINDEX, slr->lua_ref);
  xlua_refcount(slr->L, -1);

  if (r0)
    {
      marpa_r_unref (r0);
    }

   Safefree(slr->t_events);
   Safefree(slr->t_lexemes);

  Safefree(slr->pos_db);
  SvREFCNT_dec (slr->slg_sv);
  SvREFCNT_dec (slr->r1_sv);
  Safefree(slr->symbol_r_properties);
  Safefree(slr->l0_rule_r_properties);
  if (slr->token_values)
    {
      SvREFCNT_dec ((SV *) slr->token_values);
    }
  SvREFCNT_dec (slr->input);
  {
     /* "Weak" cross-references
      * See Thin::V destructor.
      */
     V_Wrapper* vw = slr->v_wrapper;
     if (vw) {
       vw->slr = NULL;
       slr->v_wrapper = NULL;
     }
  }
  Safefree (slr);
}

void throw_set(slr, throw_setting)
    Scanless_R *slr;
    int throw_setting;
PPCODE:
{
  slr->throw = throw_setting;
}

void
trace_lexers( slr, new_level )
    Scanless_R *slr;
    int new_level;
PPCODE:
{
  IV old_level = slr->trace_lexers;
  slr->trace_lexers = new_level;
  if (new_level)
    {
      warn
        ("Setting trace_lexers to %ld; was %ld",
         (long) new_level, (long) old_level);
    }
  XSRETURN_IV (old_level);
}

void
trace_terminals( slr, new_level )
    Scanless_R *slr;
    int new_level;
PPCODE:
{
  IV old_level = slr->trace_terminals;
  slr->trace_terminals = new_level;
  XSRETURN_IV(old_level);
}

void
earley_item_warning_threshold( slr )
    Scanless_R *slr;
PPCODE:
{
  XSRETURN_IV(slr->too_many_earley_items);
}

void
earley_item_warning_threshold_set( slr, too_many_earley_items )
    Scanless_R *slr;
    int too_many_earley_items;
PPCODE:
{
  slr->too_many_earley_items = too_many_earley_items;
}

 #  Always returns the same SV for a given Scanless recce object --
 #  it does not create a new one
 #
void
g1( slr )
    Scanless_R *slr;
PPCODE:
{
  XPUSHs (sv_2mortal (SvREFCNT_inc_NN ( slr->r1_wrapper->base_sv)));
}

void
pos( slr )
    Scanless_R *slr;
PPCODE:
{
  XSRETURN_IV(slr->perl_pos);
}

void
pos_set( slr, start_pos_sv, length_sv )
    Scanless_R *slr;
     SV* start_pos_sv;
     SV* length_sv;
PPCODE:
{
  int start_pos = SvIOK(start_pos_sv) ? SvIV(start_pos_sv) : slr->perl_pos;
  int length = SvIOK(length_sv) ? SvIV(length_sv) : -1;
  u_pos_set(slr, "slr->pos_set", start_pos, length);
  slr->lexer_start_pos = slr->perl_pos;
  XSRETURN_YES;
}

void
substring(slr, start_pos, length)
    Scanless_R *slr;
    int start_pos;
    int length;
PPCODE:
{
  SV* literal_sv = u_substring(slr, "slr->substring()", start_pos, length);
  XPUSHs (sv_2mortal (literal_sv));
}

 # An internal function for converting an Earley set span to
 # one in terms of the input locations.
 # This is only meaningful in the context of an SLR
void
_es_to_literal_span(slr, start_earley_set, length)
    Scanless_R *slr;
    Marpa_Earley_Set_ID start_earley_set;
    int length;
PPCODE:
{
  int literal_start;
  int literal_length;
  const Marpa_Recce r1 = slr->r1;
  const Marpa_Earley_Set_ID latest_earley_set =
    marpa_r_latest_earley_set (r1);
  if (start_earley_set < 0 || start_earley_set > latest_earley_set)
    {
      croak
        ("_es_to_literal_span: earley set is %d, must be between 0 and %d",
         start_earley_set, latest_earley_set);
    }
  if (length < 0)
    {
      croak ("_es_to_literal_span: length is %d, cannot be negative", length);
    }
  if (start_earley_set + length > latest_earley_set)
    {
      croak
        ("_es_to_literal_span: final earley set is %d, must be no greater than %d",
         start_earley_set + length, latest_earley_set);
    }
  slr_es_to_literal_span (slr,
                          start_earley_set, length,
                          &literal_start, &literal_length);
  XPUSHs (sv_2mortal (newSViv ((IV) literal_start)));
  XPUSHs (sv_2mortal (newSViv ((IV) literal_length)));
}

void
read(slr)
    Scanless_R *slr;
PPCODE:
{
  int lexer_read_result = 0;
  const int trace_lexers = slr->trace_lexers;

  if (slr->is_external_scanning)
    {
      XSRETURN_PV ("unpermitted mix of external and internal scanning");
    }

  slr->lexer_read_result = 0;
  slr->r1_earleme_complete_result = 0;
  slr->start_of_pause_lexeme = -1;
  slr->end_of_pause_lexeme = -1;

  /* Clear event queue */
  av_clear (slr->r1_wrapper->event_queue);
  marpa_slr_event_clear (slr);

  /* Application intervention resets perl_pos */
  slr->last_perl_pos = -1;

  while (1)
    {
      if (slr->lexer_start_pos >= 0)
        {
          if (slr->lexer_start_pos >= slr->end_pos)
            {
              XSRETURN_PV ("");
            }

          slr->start_of_lexeme = slr->perl_pos = slr->lexer_start_pos;
          slr->lexer_start_pos = -1;
          u_r0_clear (slr);
          if (trace_lexers >= 1)
            {
              union marpa_slr_event_s *event =
                marpa_slr_event_push (slr);
              MARPA_SLREV_TYPE (event) = MARPA_SLREV_LEXER_RESTARTED_RECCE;
              event->t_lexer_restarted_recce.t_perl_pos = slr->perl_pos;
            }
        }

      lexer_read_result = slr->lexer_read_result = u_read (slr);
      switch (lexer_read_result)
        {
        case U_READ_TRACING:
          XSRETURN_PV ("trace");
        case U_READ_UNREGISTERED_CHAR:
          XSRETURN_PV ("unregistered char");
        default:
          if (lexer_read_result < 0)
            {
              croak
                ("Internal Marpa SLIF error: u_read returned unknown code: %ld",
                 (long) lexer_read_result);
            }
          break;
        case U_READ_OK:
        case U_READ_INVALID_CHAR:
        case U_READ_REJECTED_CHAR:
        case U_READ_EXHAUSTED_ON_FAILURE:
        case U_READ_EXHAUSTED_ON_SUCCESS:
          break;
        }


      if (marpa_r_is_exhausted (slr->r1))
        {
          int discard_result = slr_discard (slr);
          if (discard_result < 0)
            {
              XSRETURN_PV ("R1 exhausted before end");
            }
        }
      else
        {
          const char *result_string = slr_alternatives (slr);
          if (result_string)
            {
              XSRETURN_PV (result_string);
            }
        }

      {
        int event_count = av_len (slr->r1_wrapper->event_queue) + 1;
        event_count += marpa_slr_event_count (slr);
        if (event_count)
          {
            XSRETURN_PV ("event");
          }
      }

      if (slr->trace_terminals || slr->trace_lexers)
        {
          XSRETURN_PV ("trace");
        }

    }

  /* Never reached */
  XSRETURN_PV ("");
}

void
lexer_read_result (slr)
     Scanless_R *slr;
PPCODE:
{
  XPUSHs (sv_2mortal (newSViv ((IV) slr->lexer_read_result)));
}

void
r1_earleme_complete_result (slr)
     Scanless_R *slr;
PPCODE:
{
  XPUSHs (sv_2mortal (newSViv ((IV) slr->r1_earleme_complete_result)));
}

void
pause_span (slr)
     Scanless_R *slr;
PPCODE:
{
  if (slr->end_of_pause_lexeme < 0)
    {
      XSRETURN_UNDEF;
    }
  XPUSHs (sv_2mortal (newSViv ((IV) slr->start_of_pause_lexeme)));
  XPUSHs (sv_2mortal
          (newSViv
           ((IV) slr->end_of_pause_lexeme - slr->start_of_pause_lexeme)));
}

void
events(slr)
    Scanless_R *slr;
PPCODE:
{
  int i;
  int queue_length;
  AV *const event_queue_av = slr->r1_wrapper->event_queue;

  for (i = 0; i < slr->t_event_count; i++)
    {
        union marpa_slr_event_s *const slr_event = slr->t_events + i;

      const int event_type = MARPA_SLREV_TYPE (slr_event);
      switch (event_type)
        {
        case MARPA_SLREV_DELETED:
          break;

        case MARPA_SLRTR_CODEPOINT_READ:
          {
            AV *event_av = newAV ();

            av_push (event_av, newSVpvs ("'trace"));
            av_push (event_av, newSVpvs ("lexer reading codepoint"));
            av_push (event_av, newSViv ((IV) slr_event->t_trace_codepoint_read.t_codepoint));
            av_push (event_av, newSViv ((IV) slr_event->t_trace_codepoint_read.t_perl_pos));
            XPUSHs (sv_2mortal (newRV_noinc ((SV *) event_av)));
            break;
          }

        case MARPA_SLRTR_CODEPOINT_REJECTED:
          {
            AV *event_av = newAV ();
            av_push (event_av, newSVpvs ("'trace"));
            av_push (event_av, newSVpvs ("lexer rejected codepoint"));
            av_push (event_av, newSViv ((IV) slr_event->t_trace_codepoint_rejected.t_codepoint));
            av_push (event_av, newSViv ((IV) slr_event->t_trace_codepoint_rejected.t_perl_pos));
            av_push (event_av, newSViv ((IV) slr_event->t_trace_codepoint_rejected.t_symbol_id));
            XPUSHs (sv_2mortal (newRV_noinc ((SV *) event_av)));
            break;
          }

        case MARPA_SLRTR_CODEPOINT_ACCEPTED:
          {
            AV *event_av = newAV ();
            av_push (event_av, newSVpvs ("'trace"));
            av_push (event_av, newSVpvs ("lexer accepted codepoint"));
            av_push (event_av, newSViv ((IV) slr_event->t_trace_codepoint_accepted.t_codepoint));
            av_push (event_av, newSViv ((IV) slr_event->t_trace_codepoint_accepted.t_perl_pos));
            av_push (event_av, newSViv ((IV) slr_event->t_trace_codepoint_accepted.t_symbol_id));
            XPUSHs (sv_2mortal (newRV_noinc ((SV *) event_av)));
            break;
          }

        case MARPA_SLRTR_LEXEME_DISCARDED:
          {
            AV *event_av = newAV ();
            av_push (event_av, newSVpvs ("'trace"));
            av_push (event_av, newSVpvs ("discarded lexeme"));
            /* We do not have the lexeme, but we have the
             * lexer rule.
             * The upper level will have to figure things out.
             */
            av_push (event_av, newSViv ((IV) slr_event->t_trace_lexeme_discarded.t_rule_id));
            av_push (event_av, newSViv ((IV) slr_event->t_trace_lexeme_discarded.t_start_of_lexeme));
            av_push (event_av, newSViv ((IV) slr_event->t_trace_lexeme_discarded.t_end_of_lexeme));
            XPUSHs (sv_2mortal (newRV_noinc ((SV *) event_av)));
            break;
          }

        case MARPA_SLRTR_LEXEME_IGNORED:
          {
            AV *event_av = newAV ();
            av_push (event_av, newSVpvs ("'trace"));
            av_push (event_av, newSVpvs ("ignored lexeme"));
            av_push (event_av, newSViv ((IV) slr_event->t_trace_lexeme_ignored.t_lexeme));
            av_push (event_av, newSViv ((IV) slr_event->t_trace_lexeme_ignored.t_start_of_lexeme));
            av_push (event_av, newSViv ((IV) slr_event->t_trace_lexeme_ignored.t_end_of_lexeme));
            XPUSHs (sv_2mortal (newRV_noinc ((SV *) event_av)));
            break;
          }

        case MARPA_SLREV_LEXEME_DISCARDED:
          {
            AV *event_av = newAV ();
            av_push (event_av, newSVpvs ("discarded lexeme"));
            av_push (event_av, newSViv ((IV) slr_event->t_lexeme_discarded.t_rule_id));
            av_push (event_av, newSViv ((IV) slr_event->t_lexeme_discarded.t_start_of_lexeme));
            av_push (event_av, newSViv ((IV) slr_event->t_lexeme_discarded.t_end_of_lexeme));
            av_push (event_av, newSViv ((IV) slr_event->t_lexeme_discarded.t_last_g1_location));
            XPUSHs (sv_2mortal (newRV_noinc ((SV *) event_av)));
            break;
          }

        case MARPA_SLREV_SYMBOL_COMPLETED:
          {
            AV *event_av = newAV ();
            av_push (event_av, newSVpvs ("symbol completed"));
            av_push (event_av, newSViv ((IV) slr_event->t_symbol_completed.t_symbol));
            XPUSHs (sv_2mortal (newRV_noinc ((SV *) event_av)));
            break;
          }

        case MARPA_SLREV_SYMBOL_NULLED:
          {
            AV *event_av = newAV ();
            av_push (event_av, newSVpvs ("symbol nulled"));
            av_push (event_av, newSViv ((IV) slr_event->t_symbol_nulled.t_symbol));
            XPUSHs (sv_2mortal (newRV_noinc ((SV *) event_av)));
            break;
          }

        case MARPA_SLREV_SYMBOL_PREDICTED:
          {
            AV *event_av = newAV ();
            av_push (event_av, newSVpvs ("symbol predicted"));
            av_push (event_av, newSViv ((IV) slr_event->t_symbol_predicted.t_symbol));
            XPUSHs (sv_2mortal (newRV_noinc ((SV *) event_av)));
            break;
          }

        case MARPA_SLREV_MARPA_R_UNKNOWN:
          {
            /* An unknown Marpa_Recce event */
            AV *event_av = newAV ();
            const int r_event_ix = slr_event->t_marpa_r_unknown.t_event;
            const char *result_string = event_type_to_string (r_event_ix);
            if (!result_string)
              {
                result_string =
                  form ("unknown marpa_r event code, %d", r_event_ix);
              }
            av_push (event_av, newSVpvs ("unknown marpa_r event"));
            av_push (event_av, newSVpv (result_string, 0));
            XPUSHs (sv_2mortal (newRV_noinc ((SV *) event_av)));
            break;
          }

        case MARPA_SLRTR_LEXEME_REJECTED:
          {
            AV *event_av = newAV ();
            av_push (event_av, newSVpvs ("'trace"));
            av_push (event_av, newSVpvs ("rejected lexeme"));
            av_push (event_av, newSViv ((IV) slr_event->t_trace_lexeme_rejected.t_start_of_lexeme));    /* start */
            av_push (event_av, newSViv ((IV) slr_event->t_trace_lexeme_rejected.t_end_of_lexeme));      /* end */
            av_push (event_av, newSViv ((IV) slr_event->t_trace_lexeme_rejected.t_lexeme));     /* lexeme */
            XPUSHs (sv_2mortal (newRV_noinc ((SV *) event_av)));
            break;
          }

        case MARPA_SLRTR_LEXEME_EXPECTED:
          {
            AV *event_av = newAV ();
            av_push (event_av, newSVpvs ("'trace"));
            av_push (event_av, newSVpvs ("expected lexeme"));
            av_push (event_av, newSViv ((IV) slr_event->t_trace_lexeme_expected.t_perl_pos));
            av_push (event_av, newSViv ((IV) slr_event->t_trace_lexeme_expected.t_lexeme));
            av_push (event_av, newSViv ((IV) slr_event->t_trace_lexeme_expected.t_assertion));
            XPUSHs (sv_2mortal (newRV_noinc ((SV *) event_av)));
            break;
          }

        case MARPA_SLRTR_LEXEME_OUTPRIORITIZED:
          {
            /* Uses same structure as "acceptable" lexeme */
            AV *event_av = newAV ();
            av_push (event_av, newSVpvs ("'trace"));
            av_push (event_av, newSVpvs ("outprioritized lexeme"));
            av_push (event_av, newSViv ((IV) slr_event->t_trace_lexeme_acceptable.t_start_of_lexeme));  /* start */
            av_push (event_av, newSViv ((IV) slr_event->t_trace_lexeme_acceptable.t_end_of_lexeme));    /* end */
            av_push (event_av, newSViv ((IV) slr_event->t_trace_lexeme_acceptable.t_lexeme));   /* lexeme */
            av_push (event_av, newSViv ((IV) slr_event->t_trace_lexeme_acceptable.t_priority));
            av_push (event_av, newSViv ((IV) slr_event->t_trace_lexeme_acceptable.t_required_priority));
            XPUSHs (sv_2mortal (newRV_noinc ((SV *) event_av)));
            break;
          }

        case MARPA_SLRTR_BEFORE_LEXEME:
          {
            AV *event_av = newAV ();
            av_push (event_av, newSVpvs ("'trace"));
            av_push (event_av, newSVpvs ("g1 before lexeme event"));
            av_push (event_av, newSViv ((IV) slr_event->t_trace_before_lexeme.t_start_of_pause_lexeme));        /* start */
            av_push (event_av, newSViv ((IV) slr_event->t_trace_before_lexeme.t_end_of_pause_lexeme));  /* end */
            av_push (event_av, newSViv ((IV) slr_event->t_trace_before_lexeme.t_pause_lexeme)); /* lexeme */
            XPUSHs (sv_2mortal (newRV_noinc ((SV *) event_av)));
            break;
          }

        case MARPA_SLREV_BEFORE_LEXEME:
          {
            AV *event_av = newAV ();
            av_push (event_av, newSVpvs ("before lexeme"));
            av_push (event_av, newSViv ((IV) slr_event->t_before_lexeme.t_pause_lexeme));       /* lexeme */
            XPUSHs (sv_2mortal (newRV_noinc ((SV *) event_av)));
            break;
          }

        case MARPA_SLRTR_G1_ATTEMPTING_LEXEME:
          {
            AV *event_av = newAV ();
            av_push (event_av, newSVpvs ("'trace"));
            av_push (event_av, newSVpvs ("g1 attempting lexeme"));
            av_push (event_av, newSViv ((IV) slr_event->t_trace_attempting_lexeme.t_start_of_lexeme));  /* start */
            av_push (event_av, newSViv ((IV) slr_event->t_trace_attempting_lexeme.t_end_of_lexeme));    /* end */
            av_push (event_av, newSViv ((IV) slr_event->t_trace_attempting_lexeme.t_lexeme));   /* lexeme */
            XPUSHs (sv_2mortal (newRV_noinc ((SV *) event_av)));
            break;
          }

        case MARPA_SLRTR_G1_DUPLICATE_LEXEME:
          {
            AV *event_av = newAV ();
            av_push (event_av, newSVpvs ("'trace"));
            av_push (event_av, newSVpvs ("g1 duplicate lexeme"));
            av_push (event_av, newSViv ((IV) slr_event->t_trace_duplicate_lexeme.t_start_of_lexeme));   /* start */
            av_push (event_av, newSViv ((IV) slr_event->t_trace_duplicate_lexeme.t_end_of_lexeme));     /* end */
            av_push (event_av, newSViv ((IV) slr_event->t_trace_duplicate_lexeme.t_lexeme));    /* lexeme */
            XPUSHs (sv_2mortal (newRV_noinc ((SV *) event_av)));
            break;
          }

        case MARPA_SLRTR_G1_ACCEPTED_LEXEME:
          {
            AV *event_av = newAV ();
            av_push (event_av, newSVpvs ("'trace"));
            av_push (event_av, newSVpvs ("g1 accepted lexeme"));
            av_push (event_av, newSViv ((IV) slr_event->t_trace_accepted_lexeme.t_start_of_lexeme));    /* start */
            av_push (event_av, newSViv ((IV) slr_event->t_trace_accepted_lexeme.t_end_of_lexeme));      /* end */
            av_push (event_av, newSViv ((IV) slr_event->t_trace_accepted_lexeme.t_lexeme));     /* lexeme */
            XPUSHs (sv_2mortal (newRV_noinc ((SV *) event_av)));
            break;
          }

        case MARPA_SLRTR_AFTER_LEXEME:
          {
            AV *event_av = newAV ();
            av_push (event_av, newSVpvs ("'trace"));
            av_push (event_av, newSVpvs ("g1 pausing after lexeme"));
            av_push (event_av, newSViv ((IV) slr_event->t_trace_after_lexeme.t_start_of_lexeme));       /* start */
            av_push (event_av, newSViv ((IV) slr_event->t_trace_after_lexeme.t_end_of_lexeme)); /* end */
            av_push (event_av, newSViv ((IV) slr_event->t_trace_after_lexeme.t_lexeme));        /* lexeme */
            XPUSHs (sv_2mortal (newRV_noinc ((SV *) event_av)));
            break;
          }

        case MARPA_SLREV_AFTER_LEXEME:
          {
            AV *event_av = newAV ();;
            av_push (event_av, newSVpvs ("after lexeme"));
            av_push (event_av, newSViv ((IV) slr_event->t_after_lexeme.t_lexeme));        /* lexeme */
            XPUSHs (sv_2mortal (newRV_noinc ((SV *) event_av)));
            break;
          }

        case MARPA_SLREV_LEXER_RESTARTED_RECCE:
          {
            AV *event_av = newAV ();
            av_push (event_av, newSVpvs ("'trace"));
            av_push (event_av, newSVpv ("lexer restarted recognizer", 0));
            av_push (event_av,
                     newSViv ((IV) slr_event->t_lexer_restarted_recce.
                              t_perl_pos));
            XPUSHs (sv_2mortal (newRV_noinc ((SV *) event_av)));
            break;
          }

        case MARPA_SLREV_NO_ACCEPTABLE_INPUT:
          {
            AV *event_av = newAV ();
            av_push (event_av, newSVpvs ("no acceptable input"));
            XPUSHs (sv_2mortal (newRV_noinc ((SV *) event_av)));
            break;
          }

        case MARPA_SLREV_L0_YIM_THRESHOLD_EXCEEDED:
        {
            /* YIM count updated from SLR field, which is cleared */
            AV *event_av = newAV ();
            av_push (event_av, newSVpvs ("l0 earley item threshold exceeded"));
            av_push (event_av, newSViv ((IV) slr_event->t_l0_yim_threshold_exceeded.t_perl_pos));
            av_push (event_av, newSViv ((IV) slr_event->t_l0_yim_threshold_exceeded.t_yim_count));
            XPUSHs (sv_2mortal (newRV_noinc ((SV *) event_av)));
            break;
        }

        case MARPA_SLREV_G1_YIM_THRESHOLD_EXCEEDED:
        {
            /* YIM count updated from SLR field, which is cleared */
            AV *event_av = newAV ();
            av_push (event_av, newSVpvs ("g1 earley item threshold exceeded"));
            av_push (event_av, newSViv ((IV) slr_event->t_g1_yim_threshold_exceeded.t_perl_pos));
            av_push (event_av, newSViv ((IV) slr_event->t_g1_yim_threshold_exceeded.t_yim_count));
            XPUSHs (sv_2mortal (newRV_noinc ((SV *) event_av)));
            break;
        }

        default:
          {
            AV *event_av = newAV ();
            av_push (event_av, newSVpvs ("unknown SLR event"));
            av_push (event_av, newSViv ((IV) event_type));
            XPUSHs (sv_2mortal (newRV_noinc ((SV *) event_av)));
            break;
          }
        }
    }

  queue_length = av_len (event_queue_av);
  for (i = 0; i <= queue_length; i++)
    {
      SV *event = av_shift (event_queue_av);
      XPUSHs (sv_2mortal (event));
    }
}

void
span(slr, earley_set)
    Scanless_R *slr;
    IV earley_set;
PPCODE:
{
  int start_position;
  int length;
  slr_es_to_span(slr, earley_set, &start_position, &length);
  XPUSHs (sv_2mortal (newSViv ((IV) start_position)));
  XPUSHs (sv_2mortal (newSViv ((IV) length)));
}

void
lexeme_span (slr)
     Scanless_R *slr;
PPCODE:
{
  int length = slr->end_of_lexeme - slr->start_of_lexeme;
  XPUSHs (sv_2mortal (newSViv ((IV) slr->start_of_lexeme)));
  XPUSHs (sv_2mortal (newSViv ((IV) length)));
}

 # Return values are 1-based, as is the tradition
 # EOF is reported as the last line, last column plus one.
void
line_column(slr, pos)
     Scanless_R *slr;
     IV pos;
PPCODE:
{
  int line = 1;
  int column = 1;
  int linecol;
  int at_eof = 0;
  const int logical_size = slr->pos_db_logical_size;

  if (pos < 0)
    {
      pos = slr->perl_pos;
    }
  if (pos > logical_size)
    {
      if (logical_size < 0) {
          croak ("Problem in slr->line_column(%ld): line/column information not available",
                 (long) pos);
      }
      croak ("Problem in slr->line_column(%ld): position out of range",
             (long) pos);
    }

  /* At EOF, find data for position - 1 */
  if (pos == logical_size) { at_eof = 1; pos--; }
  linecol = slr->pos_db[pos].linecol;
  if (linecol >= 0)
    {                           /* Zero should not happen */
      line = linecol;
    }
  else
    {
      line = slr->pos_db[pos + linecol].linecol;
      column = -linecol + 1;
    }
  if (at_eof) { column++; }
  XPUSHs (sv_2mortal (newSViv ((IV) line)));
  XPUSHs (sv_2mortal (newSViv ((IV) column)));
}

 # TODO: Currently end location is not known at this
 # point.  Once it is, add tracing:
 # Don't bother with lexeme events as unnecessary
 # and counter-productive for this call, which often
 # is used to override them
 # MARPA_SLRTR_AFTER_LEXEME
 # MARPA_SLRTR_BEFORE_LEXEME
 #
 # Yes, at trace level > 0
 # MARPA_SLRTR_LEXEME_REJECTED
 # MARPA_SLRTR_G1_DUPLICATE_LEXEME
 # MARPA_SLRTR_G1_ACCEPTED_LEXEME
 #
 # Yes, at trace level > 0
 # MARPA_SLRTR_G1_ATTEMPTING_LEXEME
 #
 # Irrelevant, cannot happen
 # MARPA_SLRTR_LEXEME_DISCARDED
 #
 # Irrelevant?  Need to investigate.
 # MARPA_SLRTR_LEXEME_IGNORED
 #
 # Irrelevant, because this call overrides priorities
 # MARPA_SLRTR_LEXEME_OUTPRIORITIZED
 #
 # These are about lexeme expectations, which are
 # regarded as known before this call (or alternatively non-
 # acceptance is caught here via rejection).  Ignore
 # MARPA_SLRTR_LEXEME_ACCEPTABLE
 # MARPA_SLRTR_LEXEME_EXPECTED

 # Variable arg as opposed to a ref,
 # because there seems to be no
 # easy, forward-compatible way
 # to determine whether the de-referenced value will cause
 # a "bizarre copy" error.
 #
 # All errors are returned, not thrown
void
g1_alternative (slr, symbol_id, ...)
    Scanless_R *slr;
    Marpa_Symbol_ID symbol_id;
PPCODE:
{
  int result;
  int token_ix;
  switch (items)
    {
    case 2:
      token_ix = TOKEN_VALUE_IS_LITERAL;        /* default */
      break;
    case 3:
      {
        SV *token_value = ST (2);
        if (IS_PERL_UNDEF (token_value))
          {
            token_ix = TOKEN_VALUE_IS_UNDEF;    /* default */
            break;
          }
        /* Fail fast with a tainted input token value */
        if (SvTAINTED(token_value)) {
            croak
              ("Problem in Marpa::R3: Attempt to use a tainted token value\n"
              "Marpa::R3 is insecure for use with tainted data\n");
        }
        av_push (slr->token_values, newSVsv (token_value));
        token_ix = av_len (slr->token_values);
        xlua_sig_call (slr->L,
            "local recce, token_sv = ...;\n"
            "local new_token_ix = #recce.token_values + 1\n"
            "recce.token_values[new_token_ix] = token_sv\n"
            "return new_token_ix\n",
            "RS>i",
            slr->lua_ref, newSVsv(token_value), &token_ix);
      }
      break;
    default:
      croak
        ("Usage: Marpa::R3::Thin::SLR::g1_alternative(slr, symbol_id, [value])");
    }

  result = marpa_r_alternative (slr->r1, symbol_id, token_ix, 1);
  if (result >= MARPA_ERR_NONE) {
    slr->is_external_scanning = 1;
  }
  XSRETURN_IV (result);
}

 # Returns current position on success, 0 on unthrown failure
void
g1_lexeme_complete (slr, start_pos_sv, length_sv)
    Scanless_R *slr;
     SV* start_pos_sv;
     SV* length_sv;
PPCODE:
{
  int result;
  const int input_length = slr->pos_db_logical_size;

  int start_pos = SvIOK (start_pos_sv) ? SvIV (start_pos_sv) : slr->perl_pos;

  int lexeme_length = SvIOK (length_sv) ? SvIV (length_sv)
    : slr->perl_pos ==
    slr->start_of_pause_lexeme ? (slr->end_of_pause_lexeme -
                                  slr->start_of_pause_lexeme) : -1;

  /* User intervention resets last |perl_pos| */
  slr->last_perl_pos = -1;

  start_pos = start_pos < 0 ? input_length + start_pos : start_pos;
  if (start_pos < 0 || start_pos > input_length)
    {
      /* Undef start_pos_sv should not cause error */
      croak ("Bad start position in slr->g1_lexeme_complete(): %ld",
             (long) (SvIOK (start_pos_sv) ? SvIV (start_pos_sv) : -1));
    }
  slr->perl_pos = start_pos;

  {
    const int end_pos =
      lexeme_length <
      0 ? input_length + lexeme_length + 1 : start_pos + lexeme_length;
    if (end_pos < 0 || end_pos > input_length)
      {
        /* Undef length_sv should not cause error */
        croak ("Bad length in slr->g1_lexeme_complete(): %ld",
               (long) (SvIOK (length_sv) ? SvIV (length_sv) : -1));
      }
    lexeme_length = end_pos - start_pos;
  }

  av_clear (slr->r1_wrapper->event_queue);
  marpa_slr_event_clear(slr);

  result = marpa_r_earleme_complete (slr->r1);
  slr->is_external_scanning = 0;
  if (result >= 0)
    {
      r_convert_events (slr->r1_wrapper);
      marpa_r_latest_earley_set_values_set (slr->r1, start_pos,
                                            INT2PTR (void *, lexeme_length));
      slr->perl_pos = start_pos + lexeme_length;
      XSRETURN_IV (slr->perl_pos);
    }
  if (result == -2)
    {
      const int error = marpa_g_error (slr->g1_wrapper->g, NULL);
      if (error == MARPA_ERR_PARSE_EXHAUSTED)
        {
          union marpa_slr_event_s *event = marpa_slr_event_push(slr);
          MARPA_SLREV_TYPE (event) = MARPA_SLREV_NO_ACCEPTABLE_INPUT;
        }
      XSRETURN_IV (0);
    }
  if (slr->throw)
    {
      croak ("Problem in slr->g1_lexeme_complete(): %s",
             xs_g_error (slr->g1_wrapper));
    }
  XSRETURN_IV (0);
}

void
discard_event_activate( slr, l0_rule_id, reactivate )
    Scanless_R *slr;
    Marpa_Rule_ID l0_rule_id;
    int reactivate;
PPCODE:
{
  struct l0_rule_r_properties *l0_rule_r_properties;
  const Scanless_G *slg = slr->slg;
  const Marpa_Rule_ID highest_l0_rule_id = marpa_g_highest_rule_id (slg->l0_wrapper->g);
  if (l0_rule_id > highest_l0_rule_id)
    {
      croak
        ("Problem in slr->discard_event_activate(..., %ld, %ld): rule ID was %ld, but highest L0 rule ID = %ld",
         (long) l0_rule_id, (long) reactivate,
         (long) l0_rule_id, (long) highest_l0_rule_id);
    }
  if (l0_rule_id < 0)
    {
      croak
        ("Problem in slr->discard_event_activate(..., %ld, %ld): rule ID was %ld, a disallowed value",
         (long) l0_rule_id, (long) reactivate, (long) l0_rule_id);
    }
  l0_rule_r_properties = slr->l0_rule_r_properties + l0_rule_id;
  switch (reactivate)
    {
    case 0:
      l0_rule_r_properties->t_event_on_discard_active = 0;
      break;
    case 1:
      {
        const struct l0_rule_g_properties* g_properties = slg->l0_rule_g_properties + l0_rule_id;
        /* Only activate events which are enabled */
        l0_rule_r_properties->t_event_on_discard_active = g_properties->t_event_on_discard;
      }
      break;
    default:
      croak
        ("Problem in slr->discard_event_activate(..., %ld, %ld): reactivate flag is %ld, a disallowed value",
         (long) l0_rule_id, (long) reactivate, (long) reactivate);
    }
  XPUSHs (sv_2mortal (newSViv (reactivate)));
}

void
lexeme_event_activate( slr, g1_lexeme_id, reactivate )
    Scanless_R *slr;
    Marpa_Symbol_ID g1_lexeme_id;
    int reactivate;
PPCODE:
{
  struct symbol_r_properties *symbol_r_properties;
  const Scanless_G *slg = slr->slg;
  const Marpa_Symbol_ID highest_g1_symbol_id = marpa_g_highest_symbol_id (slg->g1);
  if (g1_lexeme_id > highest_g1_symbol_id)
    {
      croak
        ("Problem in slr->lexeme_event_activate(..., %ld, %ld): symbol ID was %ld, but highest G1 symbol ID = %ld",
         (long) g1_lexeme_id, (long) reactivate,
         (long) g1_lexeme_id, (long) highest_g1_symbol_id);
    }
  if (g1_lexeme_id < 0)
    {
      croak
        ("Problem in slr->lexeme_event_activate(..., %ld, %ld): symbol ID was %ld, a disallowed value",
         (long) g1_lexeme_id, (long) reactivate, (long) g1_lexeme_id);
    }
  symbol_r_properties = slr->symbol_r_properties + g1_lexeme_id;
  switch (reactivate)
    {
    case 0:
      symbol_r_properties->t_pause_after_active = 0;
      symbol_r_properties->t_pause_before_active = 0;
      break;
    case 1:
      {
        const struct symbol_g_properties* g_properties = slg->symbol_g_properties + g1_lexeme_id;
        /* Only activate events which are enabled */
        symbol_r_properties->t_pause_after_active = g_properties->t_pause_after;
        symbol_r_properties->t_pause_before_active = g_properties->t_pause_before;
      }
      break;
    default:
      croak
        ("Problem in slr->lexeme_event_activate(..., %ld, %ld): reactivate flag is %ld, a disallowed value",
         (long) g1_lexeme_id, (long) reactivate, (long) reactivate);
    }
  XPUSHs (sv_2mortal (newSViv (reactivate)));
}

void
problem_pos( slr )
     Scanless_R *slr;
PPCODE:
{
  if (slr->problem_pos < 0) {
     XSRETURN_UNDEF;
  }
  XSRETURN_IV(slr->problem_pos);
}

void
lexer_latest_earley_set( slr )
     Scanless_R *slr;
PPCODE:
{
  const Marpa_Recce r0 = slr->r0;
  if (!r0)
    {
      XSRETURN_UNDEF;
    }
  XSRETURN_IV (marpa_r_latest_earley_set (r0));
}

void
lexer_progress_report_start( slr, ordinal )
    Scanless_R *slr;
    Marpa_Earley_Set_ID ordinal;
PPCODE:
{
  int gp_result;
  G_Wrapper* lexer_wrapper;
  const Marpa_Recognizer recce = slr->r0;
  if (!recce)
    {
      croak ("Problem in r->progress_item(): No lexer recognizer");
    }
  lexer_wrapper = slr->slg->l0_wrapper;
  gp_result = marpa_r_progress_report_start(recce, ordinal);
  if ( gp_result == -1 ) { XSRETURN_UNDEF; }
  if ( gp_result < 0 && lexer_wrapper->throw ) {
    croak( "Problem in r->progress_report_start(%d): %s",
     ordinal, xs_g_error( lexer_wrapper ));
  }
  XPUSHs (sv_2mortal (newSViv (gp_result)));
}

void
lexer_progress_report_finish( slr )
    Scanless_R *slr;
PPCODE:
{
  int gp_result;
  G_Wrapper* lexer_wrapper;
  const Marpa_Recognizer recce = slr->r0;
  if (!recce)
    {
      croak ("Problem in r->progress_item(): No lexer recognizer");
    }
  lexer_wrapper = slr->slg->l0_wrapper;
  gp_result = marpa_r_progress_report_finish(recce);
  if ( gp_result == -1 ) { XSRETURN_UNDEF; }
  if ( gp_result < 0 && lexer_wrapper->throw ) {
    croak( "Problem in r->progress_report_finish(): %s",
     xs_g_error( lexer_wrapper ));
  }
  XPUSHs (sv_2mortal (newSViv (gp_result)));
}

void
lexer_progress_item( slr )
    Scanless_R *slr;
PPCODE:
{
  Marpa_Rule_ID rule_id;
  Marpa_Earley_Set_ID origin = -1;
  int position = -1;
  G_Wrapper* lexer_wrapper;
  const Marpa_Recognizer recce = slr->r0;
  if (!recce)
    {
      croak ("Problem in r->progress_item(): No lexer recognizer");
    }
  lexer_wrapper = slr->slg->l0_wrapper;
  rule_id = marpa_r_progress_item (recce, &position, &origin);
  if (rule_id == -1)
    {
      XSRETURN_UNDEF;
    }
  if (rule_id < 0 && lexer_wrapper->throw)
    {
      croak ("Problem in r->progress_item(): %s",
             xs_g_error (lexer_wrapper));
    }
  XPUSHs (sv_2mortal (newSViv (rule_id)));
  XPUSHs (sv_2mortal (newSViv (position)));
  XPUSHs (sv_2mortal (newSViv (origin)));
}

void
string_set( slr, string )
     Scanless_R *slr;
     SVREF string;
PPCODE:
{
  U8 *p;
  U8 *start_of_string;
  U8 *end_of_string;
  int input_is_utf8;

  /* Initialized to a Unicode non-character.  In fact, anything
   * but a CR would work here.
   */
  UV previous_codepoint = 0xFDD0;
  /* Counts are 1-based */
  int this_line = 1;
  int this_column = 1;

  STRLEN pv_length;

  /* Fail fast with a tainted input string */
  if (SvTAINTED (string))
    {
      croak
        ("Problem in v->string_set(): Attempt to use a tainted input string with Marpa::R3\n"
         "Marpa::R3 is insecure for use with tainted data\n");
    }

  /* Get our own copy and coerce it to a PV.
   * Stealing is OK, magic is not.
   */
  SvSetSV (slr->input, string);
  start_of_string = (U8 *) SvPV_force_nomg (slr->input, pv_length);
  end_of_string = start_of_string + pv_length;
  input_is_utf8 = SvUTF8 (slr->input);

  slr->pos_db_logical_size = 0;
  /* This original buffer size my be too small.
   */
  slr->pos_db_physical_size = 1024;
  Newx (slr->pos_db, (unsigned int)slr->pos_db_physical_size, Pos_Entry);

  for (p = start_of_string; p < end_of_string;)
    {
      STRLEN codepoint_length;
      UV codepoint;
      if (input_is_utf8)
        {
          codepoint = utf8_to_uvchr_buf (p, end_of_string, &codepoint_length);
          /* Perl API documents that return value is 0 and length is -1 on error,
           * "if possible".  length can be, and is, in fact unsigned.
           * I deal with this by noting that 0 is a valid UTF8 char but should
           * have a length of 1, when valid.
           */
          if (codepoint == 0 && codepoint_length != 1)
            {
              croak ("Problem in slr->string_set(): invalid UTF8 character");
            }
        }
      else
        {
          codepoint = (UV) * p;
          codepoint_length = 1;
        }
      /* Ensure that there is enough space */
      if (slr->pos_db_logical_size >= slr->pos_db_physical_size)
        {
          slr->pos_db_physical_size *= 2;
          Renew (slr->pos_db, (unsigned int)slr->pos_db_physical_size, Pos_Entry);
        }
      p += codepoint_length;
      slr->pos_db[slr->pos_db_logical_size].next_offset = (size_t)(p - start_of_string);

      /* The definition of newline here follows the Unicode standard TR13 */
      if (codepoint == 0x0a && previous_codepoint == 0x0d)
        {
          /* Set the next column to one after the last column,
           * instead of using the next line and column.
           * Delay using those until the next pass through this
           * loop.
           */
          const int pos = slr->pos_db_logical_size - 1;
          const int previous_linecol = slr->pos_db[pos].linecol;
          if (previous_linecol < 0)
          {
            slr->pos_db[slr->pos_db_logical_size].linecol = previous_linecol-1;
          } else {
            slr->pos_db[slr->pos_db_logical_size].linecol = -1;
          }
        }
      else
        {
          slr->pos_db[slr->pos_db_logical_size].linecol =
            this_column > 1 ? 1-this_column : this_line;
          switch (codepoint)
            {
            case 0x0a:
            case 0x0b:
            case 0x0c:
            case 0x0d:
            case 0x85:
            case 0x2028:
            case 0x2029:
              this_line++;
              this_column = 1;
              break;
            default:
              this_column++;
            }
        }
      slr->pos_db_logical_size++;
      previous_codepoint = codepoint;
    }
  XSRETURN_YES;
}

void
input_length( slr )
     Scanless_R *slr;
PPCODE:
{
  XSRETURN_IV(slr->pos_db_logical_size);
}

void
codepoint( slr )
     Scanless_R *slr;
PPCODE:
{
  XSRETURN_UV(slr->codepoint);
}

void
symbol_id( slr )
     Scanless_R *slr;
PPCODE:
{
  XSRETURN_IV(slr->input_symbol_id);
}

void
char_register( slr, codepoint, ... )
    Scanless_R *slr;
    UV codepoint;
PPCODE:
{
  /* OP Count is args less two, then plus two for codepoint and length fields */
  const UV op_count = (UV)items;
  UV op_ix;
  UV *ops;
  SV *ops_sv = NULL;

  if ( codepoint < (int)Dim (slr->slg->per_codepoint_array))
    {
      ops = slr->slg->per_codepoint_array[codepoint];
      Renew (ops, (unsigned int)op_count, UV);
      slr->slg->per_codepoint_array[codepoint] = ops;
    }
  else
    {
      STRLEN dummy;
      ops_sv = newSV ((size_t)op_count * sizeof (ops[0]));
      SvPOK_on (ops_sv);
      ops = (UV *) SvPV (ops_sv, dummy);
    }
  ops[0] = codepoint;
  ops[1] = op_count;
  for (op_ix = 2; op_ix < op_count; op_ix++)
    {
      /* By coincidence, offset of individual ops is 2 both in the
       * method arguments and in the op_list, so that arg IX == op_ix
       */
      ops[op_ix] = SvUV (ST ((int)op_ix));
    }
  if (ops_sv)
    {
      (void)hv_store (slr->slg->per_codepoint_hash, (char *) &codepoint,
                sizeof (codepoint), ops_sv, 0);
    }
}

  # Untested
void
lexeme_priority( slr, g1_lexeme )
    Scanless_R *slr;
    Marpa_Symbol_ID g1_lexeme;
PPCODE:
{
  const Scanless_G *slg = slr->slg;
  Marpa_Symbol_ID highest_g1_symbol_id = marpa_g_highest_symbol_id (slg->g1);
    if (g1_lexeme > highest_g1_symbol_id)
    {
      croak
        ("Problem in slr->g1_lexeme_priority(%ld): symbol ID was %ld, but highest G1 symbol ID = %ld",
         (long) g1_lexeme,
         (long) g1_lexeme,
         (long) highest_g1_symbol_id
         );
    }
    if (g1_lexeme < 0) {
      croak
        ("Problem in slr->g1_lexeme_priority(%ld): symbol ID was %ld, a disallowed value",
         (long) g1_lexeme,
         (long) g1_lexeme);
    }
  if ( ! slg->symbol_g_properties[g1_lexeme].is_lexeme ) {
      croak
        ("Problem in slr->g1_lexeme_priority(%ld): symbol ID %ld is not a lexeme",
         (long) g1_lexeme,
         (long) g1_lexeme);
  }
  XSRETURN_IV( slr->symbol_r_properties[g1_lexeme].lexeme_priority);
}

void
lexeme_priority_set( slr, g1_lexeme, new_priority )
    Scanless_R *slr;
    Marpa_Symbol_ID g1_lexeme;
    int new_priority;
PPCODE:
{
  int old_priority;
  const Scanless_G *slg = slr->slg;
  Marpa_Symbol_ID highest_g1_symbol_id = marpa_g_highest_symbol_id (slg->g1);
    if (g1_lexeme > highest_g1_symbol_id)
    {
      croak
        ("Problem in slr->g1_lexeme_priority(%ld): symbol ID was %ld, but highest G1 symbol ID = %ld",
         (long) g1_lexeme,
         (long) g1_lexeme,
         (long) highest_g1_symbol_id
         );
    }
    if (g1_lexeme < 0) {
      croak
        ("Problem in slr->g1_lexeme_priority(%ld): symbol ID was %ld, a disallowed value",
         (long) g1_lexeme,
         (long) g1_lexeme);
    }
  if ( ! slg->symbol_g_properties[g1_lexeme].is_lexeme ) {
      croak
        ("Problem in slr->g1_lexeme_priority(%ld): symbol ID %ld is not a lexeme",
         (long) g1_lexeme,
         (long) g1_lexeme);
  }
  old_priority = slr->symbol_r_properties[g1_lexeme].lexeme_priority;
  slr->symbol_r_properties[g1_lexeme].lexeme_priority = new_priority;
  XSRETURN_IV( old_priority );
}


void
token_value(slr, token_ix)
    Scanless_R *slr;
    int token_ix;
PPCODE:
{
  SV **p_token_value_sv;
  p_token_value_sv = av_fetch (slr->token_values, (I32) token_ix, 0);
  if (!p_token_value_sv)
    {
      char *error_message =
        form ( "$slr->token_value(): No token value for index %lu",
         (unsigned long) token_ix);
      XSRETURN_PV(error_message);
    }
  XPUSHs (sv_2mortal (SvREFCNT_inc_simple_NN (*p_token_value_sv)));
}

void
register_fn(slr, codestr)
    Scanless_R *slr;
    char* codestr;
PPCODE:
{
  int status;
  int time_object_registry;
  int function_ref;
  lua_State* const L = slr->L;

  marpa_lua_rawgeti (L, LUA_REGISTRYINDEX, slr->lua_ref);
  /* Lua stack: [ recce_table ] */
  time_object_registry = marpa_lua_gettop (L);

  status = marpa_luaL_loadbuffer (L, codestr, strlen (codestr), codestr);
  if (status != 0)
    {
      const char *error_string = marpa_lua_tostring (L, -1);
      marpa_lua_pop (L, 1);
      croak ("Marpa::R3::SLR::register_fn -- error lua code: %s", error_string);
    }
  /* [ recce_table, function ] */

  function_ref = marpa_luaL_ref (L, time_object_registry);
  marpa_lua_pop(L, (marpa_lua_gettop(L) - time_object_registry) + 1);
  XPUSHs (sv_2mortal (newSViv (function_ref)));
}

void
unregister_fn(slr, fn_key)
    Scanless_R *slr;
    int fn_key;
PPCODE:
{
  lua_State* const L = slr->L;
  const int base_of_stack = marpa_lua_gettop(L);

  marpa_lua_rawgeti (L, LUA_REGISTRYINDEX, slr->lua_ref);
  /* Lua stack: [ recce_table ] */
  marpa_luaL_unref (L, -1, fn_key);
  marpa_lua_settop (L, base_of_stack);
}

MODULE = Marpa::R3            PACKAGE = Marpa::R3::Lua

void
new(class )
PPCODE:
{
    SV *new_sv;
    Marpa_Lua *lua_wrapper;

    Newx (lua_wrapper, 1, Marpa_Lua);
    lua_wrapper->L = xlua_newstate();
    new_sv = sv_newmortal ();
    sv_setref_pv (new_sv, marpa_lua_class_name, (void *) lua_wrapper);
    XPUSHs (new_sv);
}

void
DESTROY( lua_wrapper )
    Marpa_Lua *lua_wrapper;
PPCODE:
{
  xlua_refcount(lua_wrapper->L, -1);
  Safefree (lua_wrapper);
}

INCLUDE: exec_lua.xs

INCLUDE: auto.xs

BOOT:

    marpa_debug_handler_set(marpa_r3_warn);

    /* vim: set expandtab shiftwidth=2: */

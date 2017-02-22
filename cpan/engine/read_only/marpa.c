/*
 * Copyright 2015 Jeffrey Kegler
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */


/*
 * DO NOT EDIT DIRECTLY
 * This file is written by the Marpa build process
 * It is not intended to be modified directly
 */

/*1361:*/
#line 16498 "./marpa.w"


#include "config.h"

#ifndef MARPA_DEBUG
#define MARPA_DEBUG 0
#endif

#include "marpa.h"
#include "marpa_ami.h"
#define PRIVATE_NOT_INLINE static
#define PRIVATE static inline \

#define HEADER_VERSION_MISMATCH ( \
MARPA_LIB_MAJOR_VERSION!=MARPA_MAJOR_VERSION \
||MARPA_LIB_MINOR_VERSION!=MARPA_MINOR_VERSION \
||MARPA_LIB_MICRO_VERSION!=MARPA_MICRO_VERSION \
) 
#define XSY_Count_of_G(g) (MARPA_DSTACK_LENGTH((g) ->t_xsy_stack) ) 
#define XSY_by_ID(id) (*MARPA_DSTACK_INDEX(g->t_xsy_stack,XSY,(id) ) )  \

#define XSYID_is_Malformed(xsy_id) ((xsy_id) <0) 
#define XSYID_of_G_Exists(xsy_id) ((xsy_id) <XSY_Count_of_G(g) ) 
#define NSYID_is_Malformed(nsy_id) ((nsy_id) <0) 
#define NSYID_of_G_Exists(nsy_id) ((nsy_id) <NSY_Count_of_G(g) ) 
#define XRL_Count_of_G(g) (MARPA_DSTACK_LENGTH((g) ->t_xrl_stack) ) 
#define IRL_Count_of_G(g) (MARPA_DSTACK_LENGTH((g) ->t_irl_stack) ) 
#define XRL_by_ID(id) (*MARPA_DSTACK_INDEX((g) ->t_xrl_stack,XRL,(id) ) ) 
#define IRL_by_ID(id) (*MARPA_DSTACK_INDEX((g) ->t_irl_stack,IRL,(id) ) )  \

#define XRLID_is_Malformed(rule_id) ((rule_id) <0) 
#define XRLID_of_G_Exists(rule_id) ((rule_id) <XRL_Count_of_G(g) ) 
#define IRLID_of_G_is_Valid(irl_id)  \
((irl_id) >=0&&(irl_id) <IRL_Count_of_G(g) )  \

#define G_is_Trivial(g) (!(g) ->t_start_irl) 
#define External_Size_of_G(g) ((g) ->t_external_size) 
#define MAXIMUM_RANK (INT_MAX/4) 
#define MINIMUM_RANK (INT_MIN/4+(INT_MIN%4> 0?1:0) ) 
#define Default_Rank_of_G(g) ((g) ->t_default_rank) 
#define G_is_Precomputed(g) ((g) ->t_is_precomputed) 
#define G_EVENT_COUNT(g) MARPA_DSTACK_LENGTH((g) ->t_events) 
#define INITIAL_G_EVENTS_CAPACITY (1024/sizeof(int) ) 
#define G_EVENTS_CLEAR(g) MARPA_DSTACK_CLEAR((g) ->t_events) 
#define G_EVENT_PUSH(g) MARPA_DSTACK_PUSH((g) ->t_events,GEV_Object) 
#define I_AM_OK 0x69734f4b
#define IS_G_OK(g) ((g) ->t_is_ok==I_AM_OK) 
#define ID_of_XSY(xsy) ((xsy) ->t_symbol_id) 
#define Rank_of_XSY(symbol) ((symbol) ->t_rank) 
#define XSY_is_LHS(xsy) ((xsy) ->t_is_lhs) 
#define XSY_is_Sequence_LHS(xsy) ((xsy) ->t_is_sequence_lhs) 
#define XSY_is_Valued(symbol) ((symbol) ->t_is_valued) 
#define XSY_is_Valued_Locked(symbol) ((symbol) ->t_is_valued_locked) 
#define XSY_is_Accessible(xsy) ((xsy) ->t_is_accessible) 
#define XSY_is_Nulling(sym) ((sym) ->t_is_nulling) 
#define XSY_is_Nullable(xsy) ((xsy) ->t_is_nullable) 
#define XSYID_is_Nullable(xsyid) XSY_is_Nullable(XSY_by_ID(xsyid) ) 
#define XSY_is_Terminal(xsy) ((xsy) ->t_is_terminal) 
#define XSY_is_Locked_Terminal(xsy) ((xsy) ->t_is_locked_terminal) 
#define XSYID_is_Terminal(id) (XSY_is_Terminal(XSY_by_ID(id) ) ) 
#define XSY_is_Productive(xsy) ((xsy) ->t_is_productive) 
#define XSY_is_Completion_Event(xsy) ((xsy) ->t_is_completion_event) 
#define XSYID_is_Completion_Event(xsyid) XSY_is_Completion_Event(XSY_by_ID(xsyid) ) 
#define XSY_Completion_Event_Starts_Active(xsy) ((xsy) ->t_completion_event_starts_active) 
#define XSYID_Completion_Event_Starts_Active(xsyid) XSY_Completion_Event_Starts_Active(XSY_by_ID(xsyid) ) 
#define XSY_is_Nulled_Event(xsy) ((xsy) ->t_is_nulled_event) 
#define XSYID_is_Nulled_Event(xsyid) XSY_is_Nulled_Event(XSY_by_ID(xsyid) ) 
#define XSY_Nulled_Event_Starts_Active(xsy) ((xsy) ->t_nulled_event_starts_active) 
#define XSYID_Nulled_Event_Starts_Active(xsyid) XSY_Nulled_Event_Starts_Active(XSY_by_ID(xsyid) ) 
#define XSY_is_Prediction_Event(xsy) ((xsy) ->t_is_prediction_event) 
#define XSYID_is_Prediction_Event(xsyid) XSY_is_Prediction_Event(XSY_by_ID(xsyid) ) 
#define XSY_Prediction_Event_Starts_Active(xsy) ((xsy) ->t_prediction_event_starts_active) 
#define XSYID_Prediction_Event_Starts_Active(xsyid) XSY_Prediction_Event_Starts_Active(XSY_by_ID(xsyid) ) 
#define Nulled_XSYIDs_of_XSY(xsy) ((xsy) ->t_nulled_event_xsyids) 
#define Nulled_XSYIDs_of_XSYID(xsyid)  \
Nulled_XSYIDs_of_XSY(XSY_by_ID(xsyid) ) 
#define NSY_of_XSY(xsy) ((xsy) ->t_nsy_equivalent) 
#define NSYID_of_XSY(xsy) ID_of_NSY(NSY_of_XSY(xsy) ) 
#define NSY_by_XSYID(xsy_id) (XSY_by_ID(xsy_id) ->t_nsy_equivalent) 
#define NSYID_by_XSYID(xsy_id) ID_of_NSY(NSY_of_XSY(XSY_by_ID(xsy_id) ) ) 
#define Nulling_NSY_of_XSY(xsy) ((xsy) ->t_nulling_nsy) 
#define Nulling_NSY_by_XSYID(xsy) (XSY_by_ID(xsy) ->t_nulling_nsy) 
#define Nulling_NSYID_by_XSYID(xsy) ID_of_NSY(XSY_by_ID(xsy) ->t_nulling_nsy) 
#define Nulling_OR_by_NSYID(nsyid) ((OR) &NSY_by_ID(nsyid) ->t_nulling_or_node) 
#define Unvalued_OR_by_NSYID(nsyid) ((OR) &NSY_by_ID(nsyid) ->t_unvalued_or_node) 
#define NSY_by_ID(id) (*MARPA_DSTACK_INDEX(g->t_nsy_stack,NSY,(id) ) ) 
#define ID_of_NSY(nsy) ((nsy) ->t_nulling_or_node.t_nsyid)  \

#define NSY_Count_of_G(g) (MARPA_DSTACK_LENGTH((g) ->t_nsy_stack) ) 
#define NSY_is_Start(nsy) ((nsy) ->t_is_start) 
#define NSY_is_LHS(nsy) ((nsy) ->t_is_lhs) 
#define NSY_is_Nulling(nsy) ((nsy) ->t_nsy_is_nulling) 
#define LHS_CIL_of_NSY(nsy) ((nsy) ->t_lhs_cil) 
#define LHS_CIL_of_NSYID(nsyid) LHS_CIL_of_NSY(NSY_by_ID(nsyid) ) 
#define NSY_is_Semantic(nsy) ((nsy) ->t_is_semantic) 
#define NSYID_is_Semantic(nsyid) (NSY_is_Semantic(NSY_by_ID(nsyid) ) ) 
#define Source_XSY_of_NSY(nsy) ((nsy) ->t_source_xsy) 
#define Source_XSY_of_NSYID(nsyid) (Source_XSY_of_NSY(NSY_by_ID(nsyid) ) ) 
#define Source_XSYID_of_NSYID(nsyid)  \
ID_of_XSY(Source_XSY_of_NSYID(nsyid) ) 
#define LHS_XRL_of_NSY(nsy) ((nsy) ->t_lhs_xrl) 
#define XRL_Offset_of_NSY(nsy) ((nsy) ->t_xrl_offset) 
#define NSY_Rank_by_XSY(xsy)  \
((xsy) ->t_rank*EXTERNAL_RANK_FACTOR+MAXIMUM_CHAF_RANK) 
#define Rank_of_NSY(nsy) ((nsy) ->t_rank) 
#define MAX_RHS_LENGTH (INT_MAX>>(2) ) 
#define Length_of_XRL(xrl) ((xrl) ->t_rhs_length) 
#define LHS_ID_of_RULE(rule) ((rule) ->t_symbols[0]) 
#define LHS_ID_of_XRL(xrl) ((xrl) ->t_symbols[0]) 
#define RHS_ID_of_RULE(rule,position)  \
((rule) ->t_symbols[(position) +1]) 
#define RHS_ID_of_XRL(xrl,position)  \
((xrl) ->t_symbols[(position) +1])  \

#define ID_of_XRL(xrl) ((xrl) ->t_id) 
#define ID_of_RULE(rule) ID_of_XRL(rule) 
#define Rank_of_XRL(rule) ((rule) ->t_rank) 
#define Null_Ranks_High_of_RULE(rule) ((rule) ->t_null_ranks_high) 
#define XRL_is_BNF(rule) ((rule) ->t_is_bnf) 
#define XRL_is_Sequence(rule) ((rule) ->t_is_sequence) 
#define Minimum_of_XRL(rule) ((rule) ->t_minimum) 
#define Separator_of_XRL(rule) ((rule) ->t_separator_id) 
#define XRL_is_Proper_Separation(rule) ((rule) ->t_is_proper_separation) 
#define XRL_is_Nulling(rule) ((rule) ->t_is_nulling) 
#define XRL_is_Nullable(rule) ((rule) ->t_is_nullable) 
#define XRL_is_Accessible(rule) ((rule) ->t_is_accessible) 
#define XRL_is_Productive(rule) ((rule) ->t_is_productive) 
#define XRL_is_Used(rule) ((rule) ->t_is_used) 
#define ID_of_IRL(irl) ((irl) ->t_irl_id) 
#define LHSID_of_IRL(irlid) ((irlid) ->t_nsyid_array[0]) 
#define LHS_of_IRL(irl) (NSY_by_ID(LHSID_of_IRL(irl) ) )  \

#define RHSID_of_IRL(irl,position) ((irl) ->t_nsyid_array[(position) +1]) 
#define RHS_of_IRL(irl,position) NSY_by_ID(RHSID_of_IRL((irl) ,(position) ) ) 
#define Length_of_IRL(irl) ((irl) ->t_length) 
#define IRL_is_Unit_Rule(irl) ((irl) ->t_ahm_count==2) 
#define AHM_Count_of_IRL(irl) ((irl) ->t_ahm_count) 
#define IRL_has_Virtual_LHS(irl) ((irl) ->t_is_virtual_lhs) 
#define IRL_has_Virtual_RHS(irl) ((irl) ->t_is_virtual_rhs) 
#define IRL_is_Right_Recursive(irl) ((irl) ->t_is_right_recursive) 
#define IRL_is_Leo(irl) IRL_is_Right_Recursive(irl) 
#define Real_SYM_Count_of_IRL(irl) ((irl) ->t_real_symbol_count) 
#define Virtual_Start_of_IRL(irl) ((irl) ->t_virtual_start) 
#define Virtual_End_of_IRL(irl) ((irl) ->t_virtual_end) 
#define Source_XRL_of_IRL(irl) ((irl) ->t_source_xrl) 
#define EXTERNAL_RANK_FACTOR 4
#define MAXIMUM_CHAF_RANK 3
#define IRL_CHAF_Rank_by_XRL(xrl,chaf_rank) ( \
((xrl) ->t_rank*EXTERNAL_RANK_FACTOR) + \
(((xrl) ->t_null_ranks_high) ?(MAXIMUM_CHAF_RANK- \
(chaf_rank) ) :(chaf_rank) )  \
) 
#define IRL_Rank_by_XRL(xrl) IRL_CHAF_Rank_by_XRL((xrl) ,MAXIMUM_CHAF_RANK) 
#define Rank_of_IRL(irl) ((irl) ->t_rank) 
#define First_AHM_of_IRL(irl) ((irl) ->t_first_ahm) 
#define First_AHM_of_IRLID(irlid) (IRL_by_ID(irlid) ->t_first_ahm) 
#define IRL_is_CHAF(irl) ((irl) ->t_is_chaf) 
#define AHM_by_ID(id) (g->t_ahms+(id) ) 
#define ID_of_AHM(ahm) (AHMID) ((ahm) -g->t_ahms) 
#define Next_AHM_of_AHM(ahm) ((ahm) +1) 
#define Prev_AHM_of_AHM(ahm) ((ahm) -1)  \

#define AHM_Count_of_G(g) ((g) ->t_ahm_count) 
#define IRL_of_AHM(ahm) ((ahm) ->t_irl) 
#define IRLID_of_AHM(item) ID_of_IRL(IRL_of_AHM(item) ) 
#define LHS_NSYID_of_AHM(item) LHSID_of_IRL(IRL_of_AHM(item) ) 
#define LHSID_of_AHM(item) LHS_NSYID_of_AHM(item) 
#define Postdot_NSYID_of_AHM(item) ((item) ->t_postdot_nsyid) 
#define AHM_is_Completion(ahm) (Postdot_NSYID_of_AHM(ahm) <0) 
#define AHM_is_Leo(ahm) (IRL_is_Leo(IRL_of_AHM(ahm) ) ) 
#define AHM_is_Leo_Completion(ahm)  \
(AHM_is_Completion(ahm) &&AHM_is_Leo(ahm) ) 
#define Null_Count_of_AHM(ahm) ((ahm) ->t_leading_nulls) 
#define Position_of_AHM(ahm) ((ahm) ->t_position) 
#define Raw_Position_of_AHM(ahm)  \
(Position_of_AHM(ahm) <0 \
?((Length_of_IRL(IRL_of_AHM(ahm) ) ) +Position_of_AHM(ahm) +1)  \
:Position_of_AHM(ahm) ) 
#define AHM_is_Prediction(ahm) (Quasi_Position_of_AHM(ahm) ==0)  \

#define Quasi_Position_of_AHM(ahm) ((ahm) ->t_quasi_position) 
#define SYMI_of_AHM(ahm) ((ahm) ->t_symbol_instance) 
#define SYMI_Count_of_G(g) ((g) ->t_symbol_instance_count) 
#define SYMI_of_IRL(irl) ((irl) ->t_symbol_instance_base) 
#define Last_Proper_SYMI_of_IRL(irl) ((irl) ->t_last_proper_symi) 
#define SYMI_of_Completed_IRL(irl)  \
(SYMI_of_IRL(irl) +Length_of_IRL(irl) -1) 
#define Predicted_IRL_CIL_of_AHM(ahm) ((ahm) ->t_predicted_irl_cil) 
#define LHS_CIL_of_AHM(ahm) ((ahm) ->t_lhs_cil) 
#define ZWA_CIL_of_AHM(ahm) ((ahm) ->t_zwa_cil) 
#define AHM_predicts_ZWA(ahm) ((ahm) ->t_predicts_zwa) 
#define Completion_XSYIDs_of_AHM(ahm) ((ahm) ->t_completion_xsyids) 
#define Nulled_XSYIDs_of_AHM(ahm) ((ahm) ->t_nulled_xsyids) 
#define Prediction_XSYIDs_of_AHM(ahm) ((ahm) ->t_prediction_xsyids) 
#define AHM_was_Predicted(ahm) ((ahm) ->t_was_predicted) 
#define YIM_was_Predicted(yim) AHM_was_Predicted(AHM_of_YIM(yim) ) 
#define AHM_is_Initial(ahm) ((ahm) ->t_is_initial) 
#define YIM_is_Initial(yim) AHM_is_Initial(AHM_of_YIM(yim) ) 
#define XRL_of_AHM(ahm) ((ahm) ->t_xrl) 
#define XRL_Position_of_AHM(ahm) ((ahm) ->t_xrl_position) 
#define Raw_XRL_Position_of_AHM(ahm) ( \
XRL_Position_of_AHM(ahm) <0 \
?Length_of_XRL(XRL_of_AHM(ahm) )  \
:XRL_Position_of_AHM(ahm)  \
) 
#define Event_Group_Size_of_AHM(ahm) ((ahm) ->t_event_group_size) 
#define Event_AHMIDs_of_AHM(ahm) ((ahm) ->t_event_ahmids) 
#define AHM_has_Event(ahm) (Count_of_CIL(Event_AHMIDs_of_AHM(ahm) ) !=0) 
#define ZWAID_is_Malformed(zwaid) ((zwaid) <0) 
#define ZWAID_of_G_Exists(zwaid) ((zwaid) <ZWA_Count_of_G(g) ) 
#define ZWA_Count_of_G(g) (MARPA_DSTACK_LENGTH((g) ->t_gzwa_stack) ) 
#define GZWA_by_ID(id) (*MARPA_DSTACK_INDEX((g) ->t_gzwa_stack,GZWA,(id) ) ) 
#define ID_of_GZWA(zwa) ((zwa) ->t_id) 
#define Default_Value_of_GZWA(zwa) ((zwa) ->t_default_value) 
#define XRLID_of_ZWP(zwp) ((zwp) ->t_xrl_id) 
#define Dot_of_ZWP(zwp) ((zwp) ->t_dot) 
#define ZWAID_of_ZWP(zwp) ((zwp) ->t_zwaid) 
#define G_of_R(r) ((r) ->t_grammar) 
#define R_BEFORE_INPUT 0x1
#define R_DURING_INPUT 0x2
#define R_AFTER_INPUT 0x3
#define Input_Phase_of_R(r) ((r) ->t_input_phase) 
#define First_YS_of_R(r) ((r) ->t_first_earley_set) 
#define Latest_YS_of_R(r) ((r) ->t_latest_earley_set) 
#define Current_Earleme_of_R(r) ((r) ->t_current_earleme) 
#define YS_at_Current_Earleme_of_R(r) ys_at_current_earleme(r) 
#define DEFAULT_YIM_WARNING_THRESHOLD (100) 
#define Furthest_Earleme_of_R(r) ((r) ->t_furthest_earleme) 
#define R_is_Exhausted(r) ((r) ->t_is_exhausted) 
#define First_Inconsistent_YS_of_R(r) ((r) ->t_first_inconsistent_ys) 
#define R_is_Consistent(r) ((r) ->t_first_inconsistent_ys<0) 
#define ID_of_ZWA(zwa) ((zwa) ->t_id) 
#define Memo_YSID_of_ZWA(zwa) ((zwa) ->t_memoized_ysid) 
#define Memo_Value_of_ZWA(zwa) ((zwa) ->t_memoized_value) 
#define Default_Value_of_ZWA(zwa) ((zwa) ->t_default_value) 
#define ZWA_Count_of_R(r) (ZWA_Count_of_G(G_of_R(r) ) ) 
#define RZWA_by_ID(id) (&(r) ->t_zwas[(zwaid) ]) 
#define JEARLEME_THRESHOLD (INT_MAX/4) 
#define Next_YS_of_YS(set) ((set) ->t_next_earley_set) 
#define Postdot_SYM_Count_of_YS(set) ((set) ->t_postdot_sym_count) 
#define First_PIM_of_YS_by_NSYID(set,nsyid) (first_pim_of_ys_by_nsyid((set) ,(nsyid) ) ) 
#define PIM_NSY_P_of_YS_by_NSYID(set,nsyid) (pim_nsy_p_find((set) ,(nsyid) ) ) 
#define YIM_Count_of_YS(set) ((set) ->t_yim_count) 
#define YIMs_of_YS(set) ((set) ->t_earley_items) 
#define YS_Count_of_R(r) ((r) ->t_earley_set_count) 
#define Ord_of_YS(set) ((set) ->t_ordinal) 
#define YS_Ord_is_Valid(r,ordinal)  \
((ordinal) >=0&&(ordinal) <YS_Count_of_R(r) ) 
#define Earleme_of_YS(set) ((set) ->t_key.t_earleme)  \

#define Value_of_YS(set) ((set) ->t_value) 
#define PValue_of_YS(set) ((set) ->t_pvalue) 
#define LHS_NSYID_of_YIM(yim)  \
LHS_NSYID_of_AHM(AHM_of_YIM(yim) ) 
#define YIM_is_Completion(item)  \
(AHM_is_Completion(AHM_of_YIM(item) ) ) 
#define YS_of_YIM(yim) ((yim) ->t_key.t_set) 
#define YS_Ord_of_YIM(yim) (Ord_of_YS(YS_of_YIM(yim) ) ) 
#define Ord_of_YIM(yim) ((yim) ->t_ordinal) 
#define Earleme_of_YIM(yim) Earleme_of_YS(YS_of_YIM(yim) ) 
#define AHM_of_YIM(yim) ((yim) ->t_key.t_ahm) 
#define AHMID_of_YIM(yim) ID_of_AHM(AHM_of_YIM(yim) ) 
#define Postdot_NSYID_of_YIM(yim) Postdot_NSYID_of_AHM(AHM_of_YIM(yim) ) 
#define IRL_of_YIM(yim) IRL_of_AHM(AHM_of_YIM(yim) ) 
#define IRLID_of_YIM(yim) ID_of_IRL(IRL_of_YIM(yim) ) 
#define Origin_Earleme_of_YIM(yim) (Earleme_of_YS(Origin_of_YIM(yim) ) ) 
#define Origin_Ord_of_YIM(yim) (Ord_of_YS(Origin_of_YIM(yim) ) ) 
#define Origin_of_YIM(yim) ((yim) ->t_key.t_origin) 
#define YIM_ORDINAL_WIDTH 16
#define YIM_ORDINAL_CLAMP(x) (((1<<(YIM_ORDINAL_WIDTH) ) -1) &(x) ) 
#define YIM_FATAL_THRESHOLD ((1<<(YIM_ORDINAL_WIDTH) ) -2) 
#define YIM_is_Rejected(yim) ((yim) ->t_is_rejected) 
#define YIM_is_Active(yim) ((yim) ->t_is_active) 
#define YIM_was_Scanned(yim) ((yim) ->t_was_scanned) 
#define YIM_was_Fusion(yim) ((yim) ->t_was_fusion) 
#define NO_SOURCE (0U) 
#define SOURCE_IS_TOKEN (1U) 
#define SOURCE_IS_COMPLETION (2U) 
#define SOURCE_IS_LEO (3U) 
#define SOURCE_IS_AMBIGUOUS (4U) 
#define Source_Type_of_YIM(item) ((item) ->t_source_type) 
#define Earley_Item_has_No_Source(item) ((item) ->t_source_type==NO_SOURCE) 
#define Earley_Item_has_Token_Source(item) ((item) ->t_source_type==SOURCE_IS_TOKEN) 
#define Earley_Item_has_Complete_Source(item) ((item) ->t_source_type==SOURCE_IS_COMPLETION) 
#define Earley_Item_has_Leo_Source(item) ((item) ->t_source_type==SOURCE_IS_LEO) 
#define Earley_Item_is_Ambiguous(item) ((item) ->t_source_type==SOURCE_IS_AMBIGUOUS)  \

#define Next_PIM_of_YIX(yix) ((yix) ->t_next) 
#define YIM_of_YIX(yix) ((yix) ->t_earley_item) 
#define Postdot_NSYID_of_YIX(yix) ((yix) ->t_postdot_nsyid) 
#define YIX_of_LIM(lim) ((YIX) (lim) ) 
#define Postdot_NSYID_of_LIM(leo) (Postdot_NSYID_of_YIX(YIX_of_LIM(leo) ) ) 
#define Next_PIM_of_LIM(leo) (Next_PIM_of_YIX(YIX_of_LIM(leo) ) ) 
#define Origin_of_LIM(leo) ((leo) ->t_origin) 
#define Top_AHM_of_LIM(leo) ((leo) ->t_top_ahm) 
#define Trailhead_AHM_of_LIM(leo) ((leo) ->t_trailhead_ahm) 
#define Predecessor_LIM_of_LIM(leo) ((leo) ->t_predecessor) 
#define Trailhead_YIM_of_LIM(leo) ((leo) ->t_base) 
#define YS_of_LIM(leo) ((leo) ->t_set) 
#define Earleme_of_LIM(lim) Earleme_of_YS(YS_of_LIM(lim) ) 
#define LIM_is_Rejected(lim) ((lim) ->t_is_rejected) 
#define LIM_is_Active(lim) ((lim) ->t_is_active) 
#define CIL_of_LIM(lim) ((lim) ->t_cil) 
#define LIM_of_PIM(pim) ((LIM) (pim) ) 
#define YIX_of_PIM(pim) ((YIX) (pim) ) 
#define Postdot_NSYID_of_PIM(pim) (Postdot_NSYID_of_YIX(YIX_of_PIM(pim) ) ) 
#define YIM_of_PIM(pim) (YIM_of_YIX(YIX_of_PIM(pim) ) ) 
#define Next_PIM_of_PIM(pim) (Next_PIM_of_YIX(YIX_of_PIM(pim) ) )  \

#define PIM_of_LIM(pim) ((PIM) (pim) ) 
#define PIM_is_LIM(pim) (YIM_of_PIM(pim) ==NULL) 
#define Next_SRCL_of_SRCL(link) ((link) ->t_next) 
#define Source_of_SRCL(link) ((link) ->t_source) 
#define SRC_of_SRCL(link) (&Source_of_SRCL(link) ) 
#define SRCL_of_YIM(yim) (&(yim) ->t_container.t_unique) 
#define Source_of_YIM(yim) ((yim) ->t_container.t_unique.t_source) 
#define SRC_of_YIM(yim) (&Source_of_YIM(yim) ) 
#define Predecessor_of_Source(srcd) ((srcd) .t_predecessor) 
#define Predecessor_of_SRC(source) Predecessor_of_Source(*(source) ) 
#define Predecessor_of_YIM(item) Predecessor_of_Source(Source_of_YIM(item) ) 
#define Predecessor_of_SRCL(link) Predecessor_of_Source(Source_of_SRCL(link) ) 
#define LIM_of_SRCL(link) ((LIM) Predecessor_of_SRCL(link) ) 
#define Cause_of_Source(srcd) ((srcd) .t_cause.t_completion) 
#define Cause_of_SRC(source) Cause_of_Source(*(source) ) 
#define Cause_of_YIM(item) Cause_of_Source(Source_of_YIM(item) ) 
#define Cause_of_SRCL(link) Cause_of_Source(Source_of_SRCL(link) ) 
#define TOK_of_Source(srcd) ((srcd) .t_cause.t_token) 
#define TOK_of_SRC(source) TOK_of_Source(*(source) ) 
#define TOK_of_YIM(yim) TOK_of_Source(Source_of_YIM(yim) ) 
#define TOK_of_SRCL(link) TOK_of_Source(Source_of_SRCL(link) ) 
#define NSYID_of_Source(srcd) ((srcd) .t_cause.t_token.t_nsyid) 
#define NSYID_of_SRC(source) NSYID_of_Source(*(source) ) 
#define NSYID_of_YIM(yim) NSYID_of_Source(Source_of_YIM(yim) ) 
#define NSYID_of_SRCL(link) NSYID_of_Source(Source_of_SRCL(link) ) 
#define Value_of_Source(srcd) ((srcd) .t_cause.t_token.t_value) 
#define Value_of_SRC(source) Value_of_Source(*(source) ) 
#define Value_of_SRCL(link) Value_of_Source(Source_of_SRCL(link) )  \

#define SRC_is_Active(src) ((src) ->t_is_active) 
#define SRC_is_Rejected(src) ((src) ->t_is_rejected) 
#define SRCL_is_Active(link) ((link) ->t_source.t_is_active) 
#define SRCL_is_Rejected(link) ((link) ->t_source.t_is_rejected)  \

#define Cause_AHMID_of_SRCL(srcl)  \
AHMID_of_YIM((YIM) Cause_of_SRCL(srcl) ) 
#define Leo_Transition_NSYID_of_SRCL(leo_source_link)  \
Postdot_NSYID_of_LIM(LIM_of_SRCL(leo_source_link) )  \

#define LV_First_Completion_SRCL_of_YIM(item) ((item) ->t_container.t_ambiguous.t_completion) 
#define First_Completion_SRCL_of_YIM(item)  \
(Source_Type_of_YIM(item) ==SOURCE_IS_COMPLETION?(SRCL) SRCL_of_YIM(item) : \
Source_Type_of_YIM(item) ==SOURCE_IS_AMBIGUOUS? \
LV_First_Completion_SRCL_of_YIM(item) :NULL)  \

#define LV_First_Token_SRCL_of_YIM(item) ((item) ->t_container.t_ambiguous.t_token) 
#define First_Token_SRCL_of_YIM(item)  \
(Source_Type_of_YIM(item) ==SOURCE_IS_TOKEN?(SRCL) SRCL_of_YIM(item) : \
Source_Type_of_YIM(item) ==SOURCE_IS_AMBIGUOUS? \
LV_First_Token_SRCL_of_YIM(item) :NULL)  \

#define LV_First_Leo_SRCL_of_YIM(item) ((item) ->t_container.t_ambiguous.t_leo) 
#define First_Leo_SRCL_of_YIM(item)  \
(Source_Type_of_YIM(item) ==SOURCE_IS_LEO?(SRCL) SRCL_of_YIM(item) : \
Source_Type_of_YIM(item) ==SOURCE_IS_AMBIGUOUS? \
LV_First_Leo_SRCL_of_YIM(item) :NULL)  \

#define NSYID_of_ALT(alt) ((alt) ->t_nsyid) 
#define Value_of_ALT(alt) ((alt) ->t_value) 
#define ALT_is_Valued(alt) ((alt) ->t_is_valued) 
#define Start_YS_of_ALT(alt) ((alt) ->t_start_earley_set) 
#define Start_Earleme_of_ALT(alt) Earleme_of_YS(Start_YS_of_ALT(alt) ) 
#define End_Earleme_of_ALT(alt) ((alt) ->t_end_earleme) 
#define Work_YIMs_of_R(r) MARPA_DSTACK_BASE((r) ->t_yim_work_stack,YIM) 
#define Work_YIM_Count_of_R(r) MARPA_DSTACK_LENGTH((r) ->t_yim_work_stack) 
#define WORK_YIMS_CLEAR(r) MARPA_DSTACK_CLEAR((r) ->t_yim_work_stack) 
#define WORK_YIM_PUSH(r) MARPA_DSTACK_PUSH((r) ->t_yim_work_stack,YIM) 
#define WORK_YIM_ITEM(r,ix) (*MARPA_DSTACK_INDEX((r) ->t_yim_work_stack,YIM,ix) ) 
#define P_YS_of_R_by_Ord(r,ord) MARPA_DSTACK_INDEX((r) ->t_earley_set_stack,YS,(ord) ) 
#define YS_of_R_by_Ord(r,ord) (*P_YS_of_R_by_Ord((r) ,(ord) ) ) 
#define LIM_is_Populated(leo) (Origin_of_LIM(leo) !=NULL) 
#define RULEID_of_PROGRESS(report) ((report) ->t_rule_id) 
#define Position_of_PROGRESS(report) ((report) ->t_position) 
#define Origin_of_PROGRESS(report) ((report) ->t_origin)  \

#define Prev_UR_of_UR(ur) ((ur) ->t_prev) 
#define Next_UR_of_UR(ur) ((ur) ->t_next) 
#define YIM_of_UR(ur) ((ur) ->t_earley_item)  \

#define URS_of_R(r) (&(r) ->t_ur_node_stack) 
#define DUMMY_OR_NODE -1
#define MAX_TOKEN_OR_NODE -2
#define VALUED_TOKEN_OR_NODE -2
#define NULLING_TOKEN_OR_NODE -3
#define UNVALUED_TOKEN_OR_NODE -4
#define OR_is_Token(or) (Type_of_OR(or) <=MAX_TOKEN_OR_NODE) 
#define Position_of_OR(or) ((or) ->t_final.t_position) 
#define Type_of_OR(or) ((or) ->t_final.t_position) 
#define IRL_of_OR(or) ((or) ->t_final.t_irl) 
#define IRLID_of_OR(or) ID_of_IRL(IRL_of_OR(or) ) 
#define Origin_Ord_of_OR(or) ((or) ->t_final.t_start_set_ordinal) 
#define ID_of_OR(or) ((or) ->t_final.t_id) 
#define YS_Ord_of_OR(or) ((or) ->t_draft.t_end_set_ordinal) 
#define DANDs_of_OR(or) ((or) ->t_draft.t_draft_and_node) 
#define First_ANDID_of_OR(or) ((or) ->t_final.t_first_and_node_id) 
#define AND_Count_of_OR(or) ((or) ->t_final.t_and_node_count) 
#define NSYID_of_OR(or) ((or) ->t_token.t_nsyid) 
#define Value_of_OR(or) ((or) ->t_token.t_value) 
#define ORs_of_B(b) ((b) ->t_or_nodes) 
#define OR_of_B_by_ID(b,id) (ORs_of_B(b) [(id) ]) 
#define OR_Count_of_B(b) ((b) ->t_or_node_count) 
#define OR_Capacity_of_B(b) ((b) ->t_or_node_capacity) 
#define ANDs_of_B(b) ((b) ->t_and_nodes) 
#define AND_Count_of_B(b) ((b) ->t_and_node_count) 
#define Top_ORID_of_B(b) ((b) ->t_top_or_node_id) 
#define G_of_B(b) ((b) ->t_grammar) 
#define WHEID_of_NSYID(nsyid) (irl_count+(nsyid) ) 
#define WHEID_of_IRLID(irlid) (irlid) 
#define WHEID_of_IRL(irl) WHEID_of_IRLID(ID_of_IRL(irl) ) 
#define WHEID_of_OR(or) ( \
wheid= OR_is_Token(or) ? \
WHEID_of_NSYID(NSYID_of_OR(or) ) : \
WHEID_of_IRL(IRL_of_OR(or) )  \
)  \

#define Next_DAND_of_DAND(dand) ((dand) ->t_next) 
#define Predecessor_OR_of_DAND(dand) ((dand) ->t_predecessor) 
#define Cause_OR_of_DAND(dand) ((dand) ->t_cause) 
#define OR_of_AND(and) ((and) ->t_current) 
#define Predecessor_OR_of_AND(and) ((and) ->t_predecessor) 
#define Cause_OR_of_AND(and) ((and) ->t_cause) 
#define OBS_of_B(b) ((b) ->t_obs) 
#define Valued_BV_of_B(b) ((b) ->t_valued_bv) 
#define Valued_Locked_BV_of_B(b) ((b) ->t_valued_locked_bv) 
#define XSYID_is_Valued_in_B(b,xsyid)  \
(lbv_bit_test(Valued_BV_of_B(b) ,(xsyid) ) ) 
#define NSYID_is_Valued_in_B(b,nsyid)  \
XSYID_is_Valued_in_B((b) ,Source_XSYID_of_NSYID(nsyid) ) 
#define OR_by_PSI(psi_data,set_ordinal,item_ordinal)  \
(((psi_data) [(set_ordinal) ].t_or_node_by_item) [(item_ordinal) ]) 
#define Ambiguity_Metric_of_B(b) ((b) ->t_ambiguity_metric) 
#define B_is_Nulling(b) ((b) ->t_is_nulling) 
#define OBS_of_O(order) ((order) ->t_ordering_obs) 
#define O_is_Default(order) (!OBS_of_O(order) ) 
#define O_is_Frozen(o) ((o) ->t_is_frozen) 
#define B_of_O(b) ((b) ->t_bocage) 
#define Ambiguity_Metric_of_O(o) ((o) ->t_ambiguity_metric) 
#define O_is_Nulling(o) ((o) ->t_is_nulling) 
#define High_Rank_Count_of_O(order) ((order) ->t_high_rank_count) 
#define Size_of_TREE(tree) FSTACK_LENGTH((tree) ->t_nook_stack) 
#define NOOK_of_TREE_by_IX(tree,nook_id)  \
FSTACK_INDEX((tree) ->t_nook_stack,NOOK_Object,nook_id) 
#define O_of_T(t) ((t) ->t_order) 
#define T_is_Paused(t) ((t) ->t_pause_counter> 0) 
#define T_is_Exhausted(t) ((t) ->t_is_exhausted) 
#define T_is_Nulling(t) ((t) ->t_is_nulling) 
#define Size_of_T(t) FSTACK_LENGTH((t) ->t_nook_stack) 
#define OR_of_NOOK(nook) ((nook) ->t_or_node) 
#define Choice_of_NOOK(nook) ((nook) ->t_choice) 
#define Parent_of_NOOK(nook) ((nook) ->t_parent) 
#define NOOK_Cause_is_Expanded(nook) ((nook) ->t_is_cause_ready) 
#define NOOK_is_Cause(nook) ((nook) ->t_is_cause_of_parent) 
#define NOOK_Predecessor_is_Expanded(nook) ((nook) ->t_is_predecessor_ready) 
#define NOOK_is_Predecessor(nook) ((nook) ->t_is_predecessor_of_parent) 
#define Next_Value_Type_of_V(val) ((val) ->t_next_value_type) 
#define V_is_Active(val) (Next_Value_Type_of_V(val) !=MARPA_STEP_INACTIVE) 
#define T_of_V(v) ((v) ->t_tree) 
#define Step_Type_of_V(val) ((val) ->public.t_step_type) 
#define XSYID_of_V(val) ((val) ->public.t_token_id) 
#define RULEID_of_V(val) ((val) ->public.t_rule_id) 
#define Token_Value_of_V(val) ((val) ->public.t_token_value) 
#define Token_Type_of_V(val) ((val) ->t_token_type) 
#define Arg_0_of_V(val) ((val) ->public.t_arg_0) 
#define Arg_N_of_V(val) ((val) ->public.t_arg_n) 
#define Result_of_V(val) ((val) ->public.t_result) 
#define Rule_Start_of_V(val) ((val) ->public.t_rule_start_ys_id) 
#define Token_Start_of_V(val) ((val) ->public.t_token_start_ys_id) 
#define YS_ID_of_V(val) ((val) ->public.t_ys_id) 
#define VStack_of_V(val) ((val) ->t_virtual_stack) 
#define V_is_Nulling(v) ((v) ->t_is_nulling) 
#define V_is_Trace(val) ((val) ->t_trace) 
#define NOOK_of_V(val) ((val) ->t_nook) 
#define XSY_is_Valued_BV_of_V(v) ((v) ->t_xsy_is_valued) 
#define XRL_is_Valued_BV_of_V(v) ((v) ->t_xrl_is_valued) 
#define Valued_Locked_BV_of_V(v) ((v) ->t_valued_locked) 
#define STEP_GET_DATA MARPA_STEP_INTERNAL2 \

#define lbv_wordbits (sizeof(LBW) *8u) 
#define lbv_lsb (1u) 
#define lbv_msb (1u<<(lbv_wordbits-1u) ) 
#define lbv_w(lbv,bit) ((lbv) +((bit) /lbv_wordbits) ) 
#define lbv_b(bit) (lbv_lsb<<((bit) %bv_wordbits) ) 
#define lbv_bit_set(lbv,bit)  \
(*lbv_w((lbv) ,(LBW) (bit) ) |= lbv_b((LBW) (bit) ) ) 
#define lbv_bit_clear(lbv,bit)  \
(*lbv_w((lbv) ,((LBW) (bit) ) ) &= ~lbv_b((LBW) (bit) ) ) 
#define lbv_bit_test(lbv,bit)  \
((*lbv_w((lbv) ,((LBW) (bit) ) ) &lbv_b((LBW) (bit) ) ) !=0U)  \

#define BV_BITS(bv) *(bv-3) 
#define BV_SIZE(bv) *(bv-2) 
#define BV_MASK(bv) *(bv-1) 
#define FSTACK_DECLARE(stack,type) struct{int t_count;type*t_base;}stack;
#define FSTACK_CLEAR(stack) ((stack) .t_count= 0) 
#define FSTACK_INIT(stack,type,n) (FSTACK_CLEAR(stack) , \
((stack) .t_base= marpa_new(type,n) ) ) 
#define FSTACK_SAFE(stack) ((stack) .t_base= NULL) 
#define FSTACK_BASE(stack,type) ((type*) (stack) .t_base) 
#define FSTACK_INDEX(this,type,ix) (FSTACK_BASE((this) ,type) +(ix) ) 
#define FSTACK_TOP(this,type) (FSTACK_LENGTH(this) <=0 \
?NULL \
:FSTACK_INDEX((this) ,type,FSTACK_LENGTH(this) -1) ) 
#define FSTACK_LENGTH(stack) ((stack) .t_count) 
#define FSTACK_PUSH(stack) ((stack) .t_base+stack.t_count++) 
#define FSTACK_POP(stack) ((stack) .t_count<=0?NULL:(stack) .t_base+(--(stack) .t_count) ) 
#define FSTACK_IS_INITIALIZED(stack) ((stack) .t_base) 
#define FSTACK_DESTROY(stack) (my_free((stack) .t_base) )  \

#define DQUEUE_DECLARE(this) struct s_dqueue this
#define DQUEUE_INIT(this,type,initial_size)  \
((this.t_current= 0) ,MARPA_DSTACK_INIT(this.t_stack,type,initial_size) ) 
#define DQUEUE_PUSH(this,type) MARPA_DSTACK_PUSH(this.t_stack,type) 
#define DQUEUE_POP(this,type) MARPA_DSTACK_POP(this.t_stack,type) 
#define DQUEUE_NEXT(this,type) (this.t_current>=MARPA_DSTACK_LENGTH(this.t_stack)  \
?NULL \
:(MARPA_DSTACK_BASE(this.t_stack,type) ) +this.t_current++) 
#define DQUEUE_BASE(this,type) MARPA_DSTACK_BASE(this.t_stack,type) 
#define DQUEUE_END(this) MARPA_DSTACK_LENGTH(this.t_stack) 
#define STOLEN_DQUEUE_DATA_FREE(data) MARPA_STOLEN_DSTACK_DATA_FREE(data)  \

#define Count_of_CIL(cil) (cil[0]) 
#define Item_of_CIL(cil,ix) (cil[1+(ix) ]) 
#define Sizeof_CIL(ix) (sizeof(int) *(1+(ix) ) ) 
#define CAPACITY_OF_CILAR(cilar) (CAPACITY_OF_DSTACK(cilar->t_buffer) -1) 
#define Sizeof_PSL(psar)  \
(sizeof(PSL_Object) +((size_t) psar->t_psl_length-1) *sizeof(void*) ) 
#define PSL_Datum(psl,i) ((psl) ->t_data[(i) ]) 
#define Dot_PSAR_of_R(r) (&(r) ->t_dot_psar_object) 
#define Dot_PSL_of_YS(ys) ((ys) ->t_dot_psl) 
#define FATAL_FLAG (0x1u) 
#define MARPA_DEV_ERROR(message) (set_error(g,MARPA_ERR_DEVELOPMENT,(message) ,0u) ) 
#define MARPA_INTERNAL_ERROR(message) (set_error(g,MARPA_ERR_INTERNAL,(message) ,0u) ) 
#define MARPA_ERROR(code) (set_error(g,(code) ,NULL,0u) ) 
#define MARPA_FATAL(code) (set_error(g,(code) ,NULL,FATAL_FLAG) ) 

#line 16508 "./marpa.w"

#include "marpa_obs.h"
#include "marpa_avl.h"
/*107:*/
#line 1022 "./marpa.w"

struct s_g_event;
typedef struct s_g_event*GEV;
/*:107*//*143:*/
#line 1251 "./marpa.w"

struct s_xsy;
typedef struct s_xsy*XSY;
typedef const struct s_xsy*XSY_Const;

/*:143*//*454:*/
#line 4848 "./marpa.w"

struct s_ahm;
typedef struct s_ahm*AHM;
typedef Marpa_AHM_ID AHMID;

/*:454*//*528:*/
#line 5751 "./marpa.w"

struct s_g_zwa;
struct s_r_zwa;
/*:528*//*535:*/
#line 5788 "./marpa.w"

struct s_zwp;
/*:535*//*628:*/
#line 6682 "./marpa.w"

struct s_earley_set;
typedef struct s_earley_set*YS;
typedef const struct s_earley_set*YS_Const;
struct s_earley_set_key;
typedef struct s_earley_set_key*YSK;
/*:628*//*650:*/
#line 6897 "./marpa.w"

struct s_earley_item;
typedef struct s_earley_item*YIM;
typedef const struct s_earley_item*YIM_Const;
struct s_earley_item_key;
typedef struct s_earley_item_key*YIK;

/*:650*//*660:*/
#line 7071 "./marpa.w"

struct s_earley_ix;
typedef struct s_earley_ix*YIX;
/*:660*//*663:*/
#line 7107 "./marpa.w"

struct s_leo_item;
typedef struct s_leo_item*LIM;
/*:663*//*698:*/
#line 7502 "./marpa.w"

struct s_alternative;
typedef struct s_alternative*ALT;
typedef const struct s_alternative*ALT_Const;
/*:698*//*855:*/
#line 9938 "./marpa.w"

struct s_ur_node_stack;
struct s_ur_node;
typedef struct s_ur_node_stack*URS;
typedef struct s_ur_node*UR;
typedef const struct s_ur_node*UR_Const;
/*:855*//*876:*/
#line 10200 "./marpa.w"

union u_or_node;
typedef union u_or_node*OR;
/*:876*//*904:*/
#line 10610 "./marpa.w"

struct s_draft_and_node;
typedef struct s_draft_and_node*DAND;
/*:904*//*930:*/
#line 11009 "./marpa.w"

struct s_and_node;
typedef struct s_and_node*AND;
/*:930*//*936:*/
#line 11071 "./marpa.w"

typedef struct marpa_bocage*BOCAGE;
/*:936*//*946:*/
#line 11176 "./marpa.w"

struct s_bocage_setup_per_ys;
/*:946*//*1010:*/
#line 11931 "./marpa.w"

typedef Marpa_Tree TREE;
/*:1010*//*1045:*/
#line 12379 "./marpa.w"

struct s_nook;
typedef struct s_nook*NOOK;
/*:1045*//*1049:*/
#line 12424 "./marpa.w"

typedef struct s_value*VALUE;
/*:1049*//*1159:*/
#line 13969 "./marpa.w"

struct s_dqueue;
typedef struct s_dqueue*DQUEUE;
/*:1159*//*1165:*/
#line 14023 "./marpa.w"

struct s_cil_arena;
/*:1165*//*1185:*/
#line 14358 "./marpa.w"

struct s_per_earley_set_list;
typedef struct s_per_earley_set_list*PSL;
/*:1185*//*1187:*/
#line 14373 "./marpa.w"

struct s_per_earley_set_arena;
typedef struct s_per_earley_set_arena*PSAR;
/*:1187*/
#line 16511 "./marpa.w"

/*49:*/
#line 660 "./marpa.w"

typedef struct marpa_g*GRAMMAR;

/*:49*//*142:*/
#line 1249 "./marpa.w"

typedef Marpa_Symbol_ID XSYID;
/*:142*//*216:*/
#line 1892 "./marpa.w"

struct s_nsy;
typedef struct s_nsy*NSY;
typedef Marpa_NSY_ID NSYID;

/*:216*//*255:*/
#line 2177 "./marpa.w"

struct s_xrl;
typedef struct s_xrl*XRL;
typedef XRL RULE;
typedef Marpa_Rule_ID RULEID;
typedef Marpa_Rule_ID XRLID;

/*:255*//*328:*/
#line 2908 "./marpa.w"

struct s_irl;
typedef struct s_irl*IRL;
typedef Marpa_IRL_ID IRLID;

/*:328*//*470:*/
#line 4962 "./marpa.w"
typedef int SYMI;
/*:470*//*529:*/
#line 5760 "./marpa.w"

typedef Marpa_Assertion_ID ZWAID;
typedef struct s_g_zwa*GZWA;
typedef struct s_r_zwa*ZWA;

/*:529*//*536:*/
#line 5791 "./marpa.w"

typedef struct s_zwp*ZWP;
typedef const struct s_zwp*ZWP_Const;
/*:536*//*549:*/
#line 5987 "./marpa.w"

typedef struct marpa_r*RECCE;
/*:549*//*625:*/
#line 6672 "./marpa.w"
typedef Marpa_Earleme JEARLEME;

/*:625*//*627:*/
#line 6676 "./marpa.w"
typedef Marpa_Earley_Set_ID YSID;
/*:627*//*652:*/
#line 6938 "./marpa.w"

typedef int YIMID;

/*:652*//*670:*/
#line 7153 "./marpa.w"

typedef union _Marpa_PIM_Object PIM_Object;
typedef union _Marpa_PIM_Object*PIM;

/*:670*//*679:*/
#line 7233 "./marpa.w"

struct s_source;
typedef struct s_source*SRC;
typedef const struct s_source*SRC_Const;
/*:679*//*682:*/
#line 7258 "./marpa.w"

struct s_source_link;
typedef struct s_source_link*SRCL;
/*:682*//*823:*/
#line 9578 "./marpa.w"

typedef struct marpa_progress_item*PROGRESS;
/*:823*//*875:*/
#line 10197 "./marpa.w"

typedef Marpa_Or_Node_ID ORID;

/*:875*//*903:*/
#line 10599 "./marpa.w"

typedef int WHEID;

/*:903*//*929:*/
#line 11005 "./marpa.w"

typedef Marpa_And_Node_ID ANDID;

/*:929*//*1044:*/
#line 12375 "./marpa.w"

typedef Marpa_Nook_ID NOOKID;
/*:1044*//*1096:*/
#line 13139 "./marpa.w"

typedef unsigned int LBW;
typedef LBW*LBV;

/*:1096*//*1104:*/
#line 13231 "./marpa.w"

typedef LBW Bit_Vector_Word;
typedef Bit_Vector_Word*Bit_Vector;
/*:1104*//*1162:*/
#line 13990 "./marpa.w"

typedef int*CIL;

/*:1162*//*1166:*/
#line 14026 "./marpa.w"

typedef struct s_cil_arena*CILAR;
/*:1166*/
#line 16512 "./marpa.w"

/*1164:*/
#line 14015 "./marpa.w"

struct s_cil_arena{
struct marpa_obstack*t_obs;
MARPA_AVL_TREE t_avl;
MARPA_DSTACK_DECLARE(t_buffer);
};
typedef struct s_cil_arena CILAR_Object;

/*:1164*/
#line 16513 "./marpa.w"

/*48:*/
#line 654 "./marpa.w"
struct marpa_g{
/*133:*/
#line 1196 "./marpa.w"

int t_is_ok;

/*:133*/
#line 655 "./marpa.w"

/*59:*/
#line 737 "./marpa.w"

MARPA_DSTACK_DECLARE(t_xsy_stack);
MARPA_DSTACK_DECLARE(t_nsy_stack);

/*:59*//*68:*/
#line 796 "./marpa.w"

MARPA_DSTACK_DECLARE(t_xrl_stack);
MARPA_DSTACK_DECLARE(t_irl_stack);
/*:68*//*103:*/
#line 991 "./marpa.w"
Bit_Vector t_bv_nsyid_is_terminal;
/*:103*//*105:*/
#line 1000 "./marpa.w"

Bit_Vector t_lbv_xsyid_is_completion_event;
Bit_Vector t_lbv_xsyid_completion_event_starts_active;
Bit_Vector t_lbv_xsyid_is_nulled_event;
Bit_Vector t_lbv_xsyid_nulled_event_starts_active;
Bit_Vector t_lbv_xsyid_is_prediction_event;
Bit_Vector t_lbv_xsyid_prediction_event_starts_active;
/*:105*//*112:*/
#line 1044 "./marpa.w"

MARPA_DSTACK_DECLARE(t_events);
/*:112*//*120:*/
#line 1118 "./marpa.w"

MARPA_AVL_TREE t_xrl_tree;
/*:120*//*124:*/
#line 1148 "./marpa.w"

struct marpa_obstack*t_obs;
struct marpa_obstack*t_xrl_obs;
/*:124*//*127:*/
#line 1165 "./marpa.w"

CILAR_Object t_cilar;
/*:127*//*135:*/
#line 1211 "./marpa.w"

const char*t_error_string;
/*:135*//*456:*/
#line 4865 "./marpa.w"

AHM t_ahms;
/*:456*//*530:*/
#line 5767 "./marpa.w"

MARPA_DSTACK_DECLARE(t_gzwa_stack);
/*:530*//*538:*/
#line 5806 "./marpa.w"

MARPA_AVL_TREE t_zwp_tree;
/*:538*/
#line 656 "./marpa.w"

/*53:*/
#line 684 "./marpa.w"
int t_ref_count;
/*:53*//*78:*/
#line 846 "./marpa.w"
XSYID t_start_xsy_id;
/*:78*//*82:*/
#line 883 "./marpa.w"

IRL t_start_irl;
/*:82*//*85:*/
#line 897 "./marpa.w"

int t_external_size;
/*:85*//*88:*/
#line 911 "./marpa.w"
int t_max_rule_length;
/*:88*//*92:*/
#line 924 "./marpa.w"
Marpa_Rank t_default_rank;
/*:92*//*136:*/
#line 1213 "./marpa.w"

Marpa_Error_Code t_error;
/*:136*//*161:*/
#line 1377 "./marpa.w"
int t_force_valued;
/*:161*//*457:*/
#line 4869 "./marpa.w"

int t_ahm_count;
/*:457*//*471:*/
#line 4964 "./marpa.w"

int t_symbol_instance_count;
/*:471*/
#line 657 "./marpa.w"

/*97:*/
#line 959 "./marpa.w"
BITFIELD t_is_precomputed:1;
/*:97*//*100:*/
#line 971 "./marpa.w"
BITFIELD t_has_cycle:1;
/*:100*/
#line 658 "./marpa.w"

};
/*:48*//*111:*/
#line 1037 "./marpa.w"

struct s_g_event{
int t_type;
int t_value;
};
typedef struct s_g_event GEV_Object;
/*:111*//*144:*/
#line 1256 "./marpa.w"

struct s_xsy{
/*202:*/
#line 1792 "./marpa.w"

CIL t_nulled_event_xsyids;
/*:202*//*205:*/
#line 1819 "./marpa.w"
NSY t_nsy_equivalent;
/*:205*//*209:*/
#line 1851 "./marpa.w"
NSY t_nulling_nsy;
/*:209*/
#line 1258 "./marpa.w"

/*145:*/
#line 1265 "./marpa.w"
XSYID t_symbol_id;

/*:145*//*150:*/
#line 1298 "./marpa.w"

Marpa_Rank t_rank;
/*:150*/
#line 1259 "./marpa.w"

/*154:*/
#line 1345 "./marpa.w"
BITFIELD t_is_lhs:1;
/*:154*//*156:*/
#line 1352 "./marpa.w"
BITFIELD t_is_sequence_lhs:1;
/*:156*//*158:*/
#line 1366 "./marpa.w"

BITFIELD t_is_valued:1;
BITFIELD t_is_valued_locked:1;
/*:158*//*166:*/
#line 1436 "./marpa.w"
BITFIELD t_is_accessible:1;
/*:166*//*169:*/
#line 1457 "./marpa.w"
BITFIELD t_is_counted:1;
/*:169*//*172:*/
#line 1473 "./marpa.w"
BITFIELD t_is_nulling:1;
/*:172*//*175:*/
#line 1490 "./marpa.w"
BITFIELD t_is_nullable:1;
/*:175*//*178:*/
#line 1511 "./marpa.w"

BITFIELD t_is_terminal:1;
BITFIELD t_is_locked_terminal:1;
/*:178*//*183:*/
#line 1558 "./marpa.w"
BITFIELD t_is_productive:1;
/*:183*//*186:*/
#line 1579 "./marpa.w"

BITFIELD t_is_completion_event:1;
BITFIELD t_completion_event_starts_active:1;
/*:186*//*191:*/
#line 1649 "./marpa.w"

BITFIELD t_is_nulled_event:1;
BITFIELD t_nulled_event_starts_active:1;
/*:191*//*196:*/
#line 1722 "./marpa.w"

BITFIELD t_is_prediction_event:1;
BITFIELD t_prediction_event_starts_active:1;
/*:196*/
#line 1260 "./marpa.w"

};

/*:144*//*217:*/
#line 1907 "./marpa.w"

struct s_unvalued_token_or_node{
int t_or_node_type;
NSYID t_nsyid;
};

struct s_nsy{
/*236:*/
#line 2044 "./marpa.w"
CIL t_lhs_cil;
/*:236*//*241:*/
#line 2075 "./marpa.w"
XSY t_source_xsy;
/*:241*//*245:*/
#line 2098 "./marpa.w"

XRL t_lhs_xrl;
int t_xrl_offset;
/*:245*/
#line 1914 "./marpa.w"

/*250:*/
#line 2151 "./marpa.w"
Marpa_Rank t_rank;
/*:250*/
#line 1915 "./marpa.w"

/*227:*/
#line 1999 "./marpa.w"
BITFIELD t_is_start:1;
/*:227*//*230:*/
#line 2013 "./marpa.w"
BITFIELD t_is_lhs:1;
/*:230*//*233:*/
#line 2027 "./marpa.w"
BITFIELD t_nsy_is_nulling:1;
/*:233*//*238:*/
#line 2052 "./marpa.w"
BITFIELD t_is_semantic:1;
/*:238*/
#line 1916 "./marpa.w"

struct s_unvalued_token_or_node t_nulling_or_node;
struct s_unvalued_token_or_node t_unvalued_or_node;
};
/*:217*//*254:*/
#line 2168 "./marpa.w"

struct s_xrl{
/*267:*/
#line 2471 "./marpa.w"
int t_rhs_length;
/*:267*//*275:*/
#line 2536 "./marpa.w"
Marpa_Rule_ID t_id;

/*:275*//*276:*/
#line 2539 "./marpa.w"

Marpa_Rank t_rank;
/*:276*/
#line 2170 "./marpa.w"

/*280:*/
#line 2588 "./marpa.w"

BITFIELD t_null_ranks_high:1;
/*:280*//*284:*/
#line 2629 "./marpa.w"
BITFIELD t_is_bnf:1;
/*:284*//*286:*/
#line 2635 "./marpa.w"
BITFIELD t_is_sequence:1;
/*:286*//*288:*/
#line 2649 "./marpa.w"
int t_minimum;
/*:288*//*291:*/
#line 2675 "./marpa.w"
XSYID t_separator_id;
/*:291*//*296:*/
#line 2712 "./marpa.w"
BITFIELD t_is_discard:1;
/*:296*//*300:*/
#line 2752 "./marpa.w"
BITFIELD t_is_proper_separation:1;
/*:300*//*304:*/
#line 2773 "./marpa.w"
BITFIELD t_is_loop:1;
/*:304*//*307:*/
#line 2791 "./marpa.w"
BITFIELD t_is_nulling:1;
/*:307*//*310:*/
#line 2810 "./marpa.w"
BITFIELD t_is_nullable:1;
/*:310*//*314:*/
#line 2829 "./marpa.w"
BITFIELD t_is_accessible:1;
/*:314*//*317:*/
#line 2848 "./marpa.w"
BITFIELD t_is_productive:1;
/*:317*//*320:*/
#line 2866 "./marpa.w"
BITFIELD t_is_used:1;
/*:320*/
#line 2171 "./marpa.w"

/*268:*/
#line 2474 "./marpa.w"
Marpa_Symbol_ID t_symbols[1];


/*:268*/
#line 2172 "./marpa.w"

};
/*:254*//*326:*/
#line 2897 "./marpa.w"

struct s_irl{
/*359:*/
#line 3110 "./marpa.w"
XRL t_source_xrl;
/*:359*//*365:*/
#line 3159 "./marpa.w"
AHM t_first_ahm;
/*:365*/
#line 2899 "./marpa.w"

/*329:*/
#line 2919 "./marpa.w"
IRLID t_irl_id;

/*:329*//*336:*/
#line 2956 "./marpa.w"
int t_length;
/*:336*//*338:*/
#line 2971 "./marpa.w"
int t_ahm_count;

/*:338*//*350:*/
#line 3050 "./marpa.w"
int t_real_symbol_count;
/*:350*//*353:*/
#line 3068 "./marpa.w"
int t_virtual_start;
/*:353*//*356:*/
#line 3088 "./marpa.w"
int t_virtual_end;
/*:356*//*362:*/
#line 3137 "./marpa.w"
Marpa_Rank t_rank;
/*:362*//*472:*/
#line 4970 "./marpa.w"

int t_symbol_instance_base;
int t_last_proper_symi;
/*:472*/
#line 2900 "./marpa.w"

/*341:*/
#line 3004 "./marpa.w"
BITFIELD t_is_virtual_lhs:1;
/*:341*//*344:*/
#line 3020 "./marpa.w"
BITFIELD t_is_virtual_rhs:1;
/*:344*//*347:*/
#line 3039 "./marpa.w"
BITFIELD t_is_right_recursive:1;
/*:347*//*409:*/
#line 4057 "./marpa.w"
BITFIELD t_is_chaf:1;
/*:409*/
#line 2901 "./marpa.w"

/*331:*/
#line 2924 "./marpa.w"

NSYID t_nsyid_array[1];

/*:331*/
#line 2902 "./marpa.w"

};
typedef struct s_irl IRL_Object;

/*:326*//*378:*/
#line 3345 "./marpa.w"

struct sym_rule_pair
{
XSYID t_symid;
RULEID t_ruleid;
};

/*:378*//*453:*/
#line 4842 "./marpa.w"

struct s_ahm{
/*462:*/
#line 4892 "./marpa.w"

IRL t_irl;

/*:462*//*475:*/
#line 4985 "./marpa.w"

CIL t_predicted_irl_cil;
CIL t_lhs_cil;

/*:475*//*476:*/
#line 4993 "./marpa.w"

CIL t_zwa_cil;

/*:476*//*496:*/
#line 5204 "./marpa.w"

CIL t_completion_xsyids;
CIL t_nulled_xsyids;
CIL t_prediction_xsyids;

/*:496*//*500:*/
#line 5234 "./marpa.w"

XRL t_xrl;
/*:500*//*503:*/
#line 5263 "./marpa.w"

CIL t_event_ahmids;
/*:503*/
#line 4844 "./marpa.w"

/*463:*/
#line 4902 "./marpa.w"
NSYID t_postdot_nsyid;

/*:463*//*464:*/
#line 4911 "./marpa.w"

int t_leading_nulls;

/*:464*//*465:*/
#line 4924 "./marpa.w"

int t_position;

/*:465*//*467:*/
#line 4940 "./marpa.w"

int t_quasi_position;

/*:467*//*469:*/
#line 4960 "./marpa.w"

int t_symbol_instance;
/*:469*//*501:*/
#line 5242 "./marpa.w"

int t_xrl_position;

/*:501*//*504:*/
#line 5267 "./marpa.w"

int t_event_group_size;
/*:504*/
#line 4845 "./marpa.w"

/*477:*/
#line 5002 "./marpa.w"

BITFIELD t_predicts_zwa:1;

/*:477*//*499:*/
#line 5225 "./marpa.w"

BITFIELD t_was_predicted:1;
BITFIELD t_is_initial:1;

/*:499*/
#line 4846 "./marpa.w"

};
/*:453*//*534:*/
#line 5781 "./marpa.w"

struct s_g_zwa{
ZWAID t_id;
BITFIELD t_default_value:1;
};
typedef struct s_g_zwa GZWA_Object;

/*:534*//*537:*/
#line 5798 "./marpa.w"

struct s_zwp{
XRLID t_xrl_id;
int t_dot;
ZWAID t_zwaid;
};
typedef struct s_zwp ZWP_Object;

/*:537*//*618:*/
#line 6618 "./marpa.w"

struct s_r_zwa{
ZWAID t_id;
YSID t_memoized_ysid;
BITFIELD t_default_value:1;
BITFIELD t_memoized_value:1;
};
typedef struct s_r_zwa ZWA_Object;

/*:618*//*629:*/
#line 6688 "./marpa.w"

struct s_earley_set_key{
JEARLEME t_earleme;
};
typedef struct s_earley_set_key YSK_Object;
/*:629*//*630:*/
#line 6693 "./marpa.w"

struct s_earley_set{
YSK_Object t_key;
PIM*t_postdot_ary;
YS t_next_earley_set;
/*632:*/
#line 6709 "./marpa.w"

YIM*t_earley_items;

/*:632*//*1196:*/
#line 14461 "./marpa.w"

PSL t_dot_psl;
/*:1196*/
#line 6698 "./marpa.w"

int t_postdot_sym_count;
/*631:*/
#line 6706 "./marpa.w"

int t_yim_count;
/*:631*//*633:*/
#line 6720 "./marpa.w"

int t_ordinal;
/*:633*//*637:*/
#line 6738 "./marpa.w"

int t_value;
void*t_pvalue;
/*:637*/
#line 6700 "./marpa.w"

};
typedef struct s_earley_set YS_Object;

/*:630*//*661:*/
#line 7074 "./marpa.w"

struct s_earley_ix{
PIM t_next;
NSYID t_postdot_nsyid;
YIM t_earley_item;
};
typedef struct s_earley_ix YIX_Object;

/*:661*//*664:*/
#line 7110 "./marpa.w"

struct s_leo_item{
YIX_Object t_earley_ix;
/*665:*/
#line 7126 "./marpa.w"

CIL t_cil;

/*:665*/
#line 7113 "./marpa.w"

YS t_origin;
AHM t_top_ahm;
AHM t_trailhead_ahm;
LIM t_predecessor;
YIM t_base;
YS t_set;
BITFIELD t_is_rejected:1;
BITFIELD t_is_active:1;
};
typedef struct s_leo_item LIM_Object;

/*:664*//*699:*/
#line 7513 "./marpa.w"

struct s_alternative{
YS t_start_earley_set;
JEARLEME t_end_earleme;
NSYID t_nsyid;
int t_value;
BITFIELD t_is_valued:1;
};
typedef struct s_alternative ALT_Object;

/*:699*//*856:*/
#line 9954 "./marpa.w"

struct s_ur_node_stack{
struct marpa_obstack*t_obs;
UR t_base;
UR t_top;
};

/*:856*//*857:*/
#line 9961 "./marpa.w"

struct s_ur_node{
UR t_prev;
UR t_next;
YIM t_earley_item;
};
typedef struct s_ur_node UR_Object;

/*:857*//*880:*/
#line 10243 "./marpa.w"

struct s_draft_or_node
{
/*879:*/
#line 10236 "./marpa.w"

/*878:*/
#line 10233 "./marpa.w"

int t_position;

/*:878*/
#line 10237 "./marpa.w"

int t_end_set_ordinal;
int t_start_set_ordinal;
ORID t_id;
IRL t_irl;

/*:879*/
#line 10246 "./marpa.w"

DAND t_draft_and_node;
};

/*:880*//*881:*/
#line 10250 "./marpa.w"

struct s_final_or_node
{
/*879:*/
#line 10236 "./marpa.w"

/*878:*/
#line 10233 "./marpa.w"

int t_position;

/*:878*/
#line 10237 "./marpa.w"

int t_end_set_ordinal;
int t_start_set_ordinal;
ORID t_id;
IRL t_irl;

/*:879*/
#line 10253 "./marpa.w"

int t_first_and_node_id;
int t_and_node_count;
};

/*:881*//*882:*/
#line 10258 "./marpa.w"

struct s_valued_token_or_node
{
/*878:*/
#line 10233 "./marpa.w"

int t_position;

/*:878*/
#line 10261 "./marpa.w"

NSYID t_nsyid;
int t_value;
};

/*:882*//*883:*/
#line 10269 "./marpa.w"

union u_or_node{
struct s_draft_or_node t_draft;
struct s_final_or_node t_final;
struct s_valued_token_or_node t_token;
};
typedef union u_or_node OR_Object;

/*:883*//*905:*/
#line 10617 "./marpa.w"

struct s_draft_and_node{
DAND t_next;
OR t_predecessor;
OR t_cause;
};
typedef struct s_draft_and_node DAND_Object;

/*:905*//*931:*/
#line 11016 "./marpa.w"

struct s_and_node{
OR t_current;
OR t_predecessor;
OR t_cause;
};
typedef struct s_and_node AND_Object;

/*:931*//*947:*/
#line 11182 "./marpa.w"

struct s_bocage_setup_per_ys{
OR*t_or_node_by_item;
PSL t_or_psl;
PSL t_and_psl;
};
/*:947*//*973:*/
#line 11404 "./marpa.w"

struct marpa_order{
struct marpa_obstack*t_ordering_obs;
ANDID**t_and_node_orderings;
/*976:*/
#line 11422 "./marpa.w"

BOCAGE t_bocage;

/*:976*/
#line 11408 "./marpa.w"

/*979:*/
#line 11442 "./marpa.w"
int t_ref_count;
/*:979*//*986:*/
#line 11498 "./marpa.w"
int t_ambiguity_metric;

/*:986*//*992:*/
#line 11610 "./marpa.w"
int t_high_rank_count;
/*:992*/
#line 11409 "./marpa.w"

/*990:*/
#line 11592 "./marpa.w"

BITFIELD t_is_nulling:1;
/*:990*/
#line 11410 "./marpa.w"

BITFIELD t_is_frozen:1;
};
/*:973*//*1011:*/
#line 11943 "./marpa.w"

/*1046:*/
#line 12390 "./marpa.w"

struct s_nook{
OR t_or_node;
int t_choice;
NOOKID t_parent;
BITFIELD t_is_cause_ready:1;
BITFIELD t_is_predecessor_ready:1;
BITFIELD t_is_cause_of_parent:1;
BITFIELD t_is_predecessor_of_parent:1;
};
typedef struct s_nook NOOK_Object;

/*:1046*/
#line 11944 "./marpa.w"

/*1051:*/
#line 12438 "./marpa.w"

struct s_value{
struct marpa_value public;
Marpa_Tree t_tree;
/*1055:*/
#line 12516 "./marpa.w"

struct marpa_obstack*t_obs;
/*:1055*//*1060:*/
#line 12563 "./marpa.w"

MARPA_DSTACK_DECLARE(t_virtual_stack);
/*:1060*//*1082:*/
#line 12716 "./marpa.w"

LBV t_xsy_is_valued;
LBV t_xrl_is_valued;
LBV t_valued_locked;

/*:1082*/
#line 12442 "./marpa.w"

/*1065:*/
#line 12611 "./marpa.w"

int t_ref_count;
/*:1065*//*1077:*/
#line 12692 "./marpa.w"

NOOKID t_nook;
/*:1077*/
#line 12443 "./marpa.w"

int t_token_type;
int t_next_value_type;
/*1072:*/
#line 12664 "./marpa.w"

BITFIELD t_is_nulling:1;
/*:1072*//*1074:*/
#line 12671 "./marpa.w"

BITFIELD t_trace:1;
/*:1074*/
#line 12446 "./marpa.w"

};

/*:1051*/
#line 11945 "./marpa.w"

struct marpa_tree{
FSTACK_DECLARE(t_nook_stack,NOOK_Object)
FSTACK_DECLARE(t_nook_worklist,int)
Bit_Vector t_or_node_in_use;
Marpa_Order t_order;
/*1017:*/
#line 12016 "./marpa.w"

int t_ref_count;
/*:1017*//*1024:*/
#line 12096 "./marpa.w"
int t_pause_counter;
/*:1024*/
#line 11951 "./marpa.w"

/*1030:*/
#line 12168 "./marpa.w"

BITFIELD t_is_exhausted:1;
/*:1030*//*1033:*/
#line 12176 "./marpa.w"

BITFIELD t_is_nulling:1;

/*:1033*/
#line 11952 "./marpa.w"

int t_parse_count;
};

/*:1011*//*1139:*/
#line 13753 "./marpa.w"

struct s_bit_matrix{
int t_row_count;
Bit_Vector_Word t_row_data[1];
};
typedef struct s_bit_matrix*Bit_Matrix;
typedef struct s_bit_matrix Bit_Matrix_Object;

/*:1139*//*1160:*/
#line 13972 "./marpa.w"

struct s_dqueue{int t_current;struct marpa_dstack_s t_stack;};

/*:1160*//*1186:*/
#line 14364 "./marpa.w"

struct s_per_earley_set_list{
PSL t_prev;
PSL t_next;
PSL*t_owner;
void*t_data[1];
};
typedef struct s_per_earley_set_list PSL_Object;
/*:1186*//*1188:*/
#line 14389 "./marpa.w"

struct s_per_earley_set_arena{
int t_psl_length;
PSL t_first_psl;
PSL t_first_free_psl;
};
typedef struct s_per_earley_set_arena PSAR_Object;
/*:1188*/
#line 16514 "./marpa.w"

/*669:*/
#line 7148 "./marpa.w"

union _Marpa_PIM_Object{
LIM_Object t_leo;
YIX_Object t_earley;
};
/*:669*/
#line 16515 "./marpa.w"


/*:1361*//*1362:*/
#line 16520 "./marpa.w"

/*40:*/
#line 570 "./marpa.w"

const int marpa_major_version= MARPA_LIB_MAJOR_VERSION;
const int marpa_minor_version= MARPA_LIB_MINOR_VERSION;
const int marpa_micro_version= MARPA_LIB_MICRO_VERSION;

/*:40*//*829:*/
#line 9604 "./marpa.w"

static const struct marpa_progress_item progress_report_not_ready= {-2,-2,-2};

/*:829*//*884:*/
#line 10277 "./marpa.w"

static const int dummy_or_node_type= DUMMY_OR_NODE;
static const OR dummy_or_node= (OR)&dummy_or_node_type;

/*:884*//*1105:*/
#line 13238 "./marpa.w"

static const unsigned int bv_wordbits= lbv_wordbits;
static const unsigned int bv_modmask= lbv_wordbits-1u;
static const unsigned int bv_hiddenwords= 3;
static const unsigned int bv_lsb= lbv_lsb;
static const unsigned int bv_msb= lbv_msb;

/*:1105*/
#line 16521 "./marpa.w"


/*:1362*//*1363:*/
#line 16523 "./marpa.w"

/*550:*/
#line 5989 "./marpa.w"

struct marpa_r{
/*558:*/
#line 6069 "./marpa.w"

GRAMMAR t_grammar;
/*:558*//*565:*/
#line 6096 "./marpa.w"

YS t_first_earley_set;
YS t_latest_earley_set;
JEARLEME t_current_earleme;
/*:565*//*577:*/
#line 6179 "./marpa.w"

Bit_Vector t_lbv_xsyid_completion_event_is_active;
Bit_Vector t_lbv_xsyid_nulled_event_is_active;
Bit_Vector t_lbv_xsyid_prediction_event_is_active;
/*:577*//*580:*/
#line 6204 "./marpa.w"
Bit_Vector t_bv_nsyid_is_expected;
/*:580*//*584:*/
#line 6281 "./marpa.w"
LBV t_nsy_expected_is_event;
/*:584*//*606:*/
#line 6555 "./marpa.w"

Bit_Vector t_bv_irl_seen;
MARPA_DSTACK_DECLARE(t_irl_cil_stack);
/*:606*//*615:*/
#line 6609 "./marpa.w"
struct marpa_obstack*t_obs;
/*:615*//*619:*/
#line 6630 "./marpa.w"

ZWA t_zwas;
/*:619*//*700:*/
#line 7523 "./marpa.w"

MARPA_DSTACK_DECLARE(t_alternatives);
/*:700*//*717:*/
#line 7810 "./marpa.w"

LBV t_valued_terminal;
LBV t_unvalued_terminal;
LBV t_valued;
LBV t_unvalued;
LBV t_valued_locked;

/*:717*//*725:*/
#line 8023 "./marpa.w"
MARPA_DSTACK_DECLARE(t_yim_work_stack);
/*:725*//*729:*/
#line 8038 "./marpa.w"
MARPA_DSTACK_DECLARE(t_completion_stack);
/*:729*//*733:*/
#line 8049 "./marpa.w"
MARPA_DSTACK_DECLARE(t_earley_set_stack);
/*:733*//*770:*/
#line 8679 "./marpa.w"

Bit_Vector t_bv_lim_symbols;
Bit_Vector t_bv_pim_symbols;
void**t_pim_workarea;
/*:770*//*789:*/
#line 8963 "./marpa.w"

void**t_lim_chain;
/*:789*//*824:*/
#line 9580 "./marpa.w"

const struct marpa_progress_item*t_current_report_item;
MARPA_AVL_TRAV t_progress_report_traverser;
/*:824*//*858:*/
#line 9970 "./marpa.w"

struct s_ur_node_stack t_ur_node_stack;
/*:858*//*1189:*/
#line 14397 "./marpa.w"

PSAR_Object t_dot_psar_object;
/*:1189*//*1240:*/
#line 14865 "./marpa.w"

struct s_earley_set*t_trace_earley_set;
/*:1240*//*1247:*/
#line 14941 "./marpa.w"

YIM t_trace_earley_item;
/*:1247*//*1261:*/
#line 15140 "./marpa.w"

PIM*t_trace_pim_nsy_p;
PIM t_trace_postdot_item;
/*:1261*//*1268:*/
#line 15289 "./marpa.w"

SRCL t_trace_source_link;
/*:1268*/
#line 5991 "./marpa.w"

/*553:*/
#line 6019 "./marpa.w"
int t_ref_count;
/*:553*//*569:*/
#line 6133 "./marpa.w"
int t_earley_item_warning_threshold;
/*:569*//*573:*/
#line 6162 "./marpa.w"
JEARLEME t_furthest_earleme;
/*:573*//*578:*/
#line 6183 "./marpa.w"

int t_active_event_count;
/*:578*//*613:*/
#line 6602 "./marpa.w"
YSID t_first_inconsistent_ys;
/*:613*//*634:*/
#line 6724 "./marpa.w"

int t_earley_set_count;
/*:634*/
#line 5992 "./marpa.w"

/*562:*/
#line 6087 "./marpa.w"

BITFIELD t_input_phase:2;
/*:562*//*602:*/
#line 6522 "./marpa.w"

BITFIELD t_use_leo_flag:1;
BITFIELD t_is_using_leo:1;
/*:602*//*609:*/
#line 6574 "./marpa.w"
BITFIELD t_is_exhausted:1;
/*:609*//*1269:*/
#line 15291 "./marpa.w"

BITFIELD t_trace_source_type:3;
/*:1269*/
#line 5993 "./marpa.w"

};

/*:550*/
#line 16524 "./marpa.w"

/*680:*/
#line 7237 "./marpa.w"

struct s_token_source{
NSYID t_nsyid;
int t_value;
};

/*:680*//*681:*/
#line 7246 "./marpa.w"

struct s_source{
void*t_predecessor;
union{
void*t_completion;
struct s_token_source t_token;
}t_cause;
BITFIELD t_is_rejected:1;
BITFIELD t_is_active:1;

};

/*:681*//*683:*/
#line 7261 "./marpa.w"

struct s_source_link{
SRCL t_next;
struct s_source t_source;
};
typedef struct s_source_link SRCL_Object;

/*:683*//*684:*/
#line 7268 "./marpa.w"

struct s_ambiguous_source{
SRCL t_leo;
SRCL t_token;
SRCL t_completion;
};

/*:684*//*685:*/
#line 7275 "./marpa.w"

union u_source_container{
struct s_ambiguous_source t_ambiguous;
struct s_source_link t_unique;
};

/*:685*/
#line 16525 "./marpa.w"

/*651:*/
#line 6917 "./marpa.w"

struct s_earley_item_key{
AHM t_ahm;
YS t_origin;
YS t_set;
};
typedef struct s_earley_item_key YIK_Object;
struct s_earley_item{
YIK_Object t_key;
union u_source_container t_container;
BITFIELD t_ordinal:YIM_ORDINAL_WIDTH;
BITFIELD t_source_type:3;
BITFIELD t_is_rejected:1;
BITFIELD t_is_active:1;
BITFIELD t_was_scanned:1;
BITFIELD t_was_fusion:1;
};
typedef struct s_earley_item YIM_Object;

/*:651*/
#line 16526 "./marpa.w"

/*937:*/
#line 11073 "./marpa.w"

struct marpa_bocage{
/*885:*/
#line 10288 "./marpa.w"

OR*t_or_nodes;
AND t_and_nodes;
/*:885*//*889:*/
#line 10317 "./marpa.w"

GRAMMAR t_grammar;

/*:889*//*940:*/
#line 11088 "./marpa.w"

struct marpa_obstack*t_obs;
/*:940*//*943:*/
#line 11156 "./marpa.w"

LBV t_valued_bv;
LBV t_valued_locked_bv;

/*:943*/
#line 11075 "./marpa.w"

/*886:*/
#line 10291 "./marpa.w"

int t_or_node_capacity;
int t_or_node_count;
int t_and_node_count;
ORID t_top_or_node_id;

/*:886*//*957:*/
#line 11304 "./marpa.w"
int t_ambiguity_metric;
/*:957*//*961:*/
#line 11318 "./marpa.w"
int t_ref_count;
/*:961*/
#line 11076 "./marpa.w"

/*968:*/
#line 11376 "./marpa.w"

BITFIELD t_is_nulling:1;
/*:968*/
#line 11077 "./marpa.w"

};

/*:937*/
#line 16527 "./marpa.w"


/*:1363*/

#line 1 "./marpa.c.p40"
static RULE rule_new(GRAMMAR g,
const XSYID lhs, const XSYID *rhs, int length);
static int
duplicate_rule_cmp (const void *ap, const void *bp, void *param  UNUSED);
static int sym_rule_cmp(
    const void* ap,
    const void* bp,
    void *param  UNUSED);
static int zwp_cmp (
    const void* ap,
    const void* bp,
    void *param  UNUSED);
static Marpa_Error_Code invalid_source_type_code(unsigned int type);
static void earley_item_ambiguate (struct marpa_r * r, YIM item);
static void
postdot_items_create (RECCE r,
  Bit_Vector bv_ok_for_chain,
  const YS current_earley_set);
static int report_item_cmp (
    const void* ap,
    const void* bp,
    void *param  UNUSED);
static int bv_scan(Bit_Vector bv, int raw_start, int* raw_min, int* raw_max);
static void transitive_closure(Bit_Matrix matrix);
static int
cil_cmp (const void *ap, const void *bp, void *param  UNUSED);
static void
set_error (GRAMMAR g, Marpa_Error_Code code, const char* message, unsigned int flags);
static void*
marpa__default_out_of_memory(void);
static inline void
grammar_unref (GRAMMAR g);
static inline GRAMMAR
grammar_ref (GRAMMAR g);
static inline void grammar_free(GRAMMAR g);
static inline void symbol_add( GRAMMAR g, XSY symbol);
static inline int xsy_id_is_valid(GRAMMAR g, XSYID xsy_id);
static inline int nsy_is_valid(GRAMMAR g, NSYID nsyid);
static inline void
rule_add (GRAMMAR g, RULE rule);
static inline void event_new(GRAMMAR g, int type);
static inline void int_event_new(GRAMMAR g, int type, int value);
static inline XSY
symbol_new (GRAMMAR g);
static inline NSY symbol_alias_create(GRAMMAR g, XSY symbol);
static inline NSY
nsy_start(GRAMMAR g);
static inline NSY
nsy_new(GRAMMAR g, XSY source);
static inline NSY
semantic_nsy_new(GRAMMAR g, XSY source);
static inline NSY
nsy_clone(GRAMMAR g, XSY xsy);
static inline   XRL xrl_start (GRAMMAR g, const XSYID lhs, const XSYID * rhs, int length);
static inline XRL xrl_finish(GRAMMAR g, XRL rule);
static inline IRL
irl_start(GRAMMAR g, int length);
static inline void
irl_finish( GRAMMAR g, IRL irl);
static inline Marpa_Symbol_ID rule_lhs_get(RULE rule);
static inline Marpa_Symbol_ID* rule_rhs_get(RULE rule);
static inline int ahm_is_valid(
GRAMMAR g, AHMID item_id);
static inline void
recce_unref (RECCE r);
static inline RECCE recce_ref (RECCE r);
static inline void recce_free(struct marpa_r *r);
static inline YS ys_at_current_earleme(RECCE r);
static inline YS
earley_set_new( RECCE r, JEARLEME id);
static inline YIM earley_item_create(const RECCE r,
    const YIK_Object key);
static inline YIM
earley_item_assign (const RECCE r, const YS set, const YS origin,
                    const AHM ahm);
static inline PIM*
pim_nsy_p_find (YS set, NSYID nsyid);
static inline PIM first_pim_of_ys_by_nsyid(YS set, NSYID nsyid);
static inline SRCL unique_srcl_new( struct marpa_obstack* t_obs);
static inline void
completion_link_add (RECCE r,
                YIM item,
                YIM predecessor,
                YIM cause);
static inline void
leo_link_add (RECCE r,
                YIM item,
                LIM predecessor,
                YIM cause);
static inline int
alternative_insertion_point (RECCE r, ALT new_alternative);
static inline int alternative_cmp(const ALT_Const a, const ALT_Const b);
static inline ALT alternative_pop(RECCE r, JEARLEME earleme);
static inline int alternative_insert(RECCE r, ALT new_alternative);
static inline int evaluate_zwas(RECCE r, YSID ysid, AHM ahm);
static inline void trigger_events(RECCE r);
static inline int trigger_trivial_events(RECCE r);
static inline void earley_set_update_items(RECCE r, YS set);
static inline void r_update_earley_sets(RECCE r);
static inline int alternative_is_acceptable(ALT alternative);
static inline void
progress_report_item_insert(MARPA_AVL_TREE report_tree,
  AHM report_ahm,
    YSID report_origin);
static inline void ur_node_stack_init(URS stack);
static inline void ur_node_stack_reset(URS stack);
static inline void ur_node_stack_destroy(URS stack);
static inline UR ur_node_new(URS stack, UR prev);
static inline void
ur_node_push (URS stack, YIM earley_item);
static inline UR
ur_node_pop (URS stack);
static inline void push_ur_if_new(
    struct s_bocage_setup_per_ys* per_ys_data,
    URS ur_node_stack, YIM yim);
static inline int psi_test_and_set(
    struct s_bocage_setup_per_ys* per_ys_data,
    YIM earley_item
    );
static inline void
Set_boolean_in_PSI_for_initial_nulls (struct s_bocage_setup_per_ys *per_ys_data,
  YIM yim);
static inline OR or_node_new(BOCAGE b);
static inline DAND draft_and_node_new(struct marpa_obstack *obs, OR predecessor, OR cause);
static inline void draft_and_node_add(struct marpa_obstack *obs, OR parent, OR predecessor, OR cause);
static inline OR or_by_origin_and_symi ( struct s_bocage_setup_per_ys *per_ys_data,
    YSID origin,
    SYMI symbol_instance);
static inline int dands_are_equal(OR predecessor_a, OR cause_a,
  OR predecessor_b, OR cause_b);
static inline int dand_is_duplicate(OR parent, OR predecessor, OR cause);
static inline OR set_or_from_yim ( struct s_bocage_setup_per_ys *per_ys_data,
  YIM psi_yim);
static inline OR safe_or_from_yim(
  struct s_bocage_setup_per_ys* per_ys_data,
  YIM yim);
static inline void
bocage_unref (BOCAGE b);
static inline BOCAGE
bocage_ref (BOCAGE b);
static inline void
bocage_free (BOCAGE b);
static inline void
order_unref (ORDER o);
static inline ORDER
order_ref (ORDER o);
static inline void order_free(ORDER o);
static inline ANDID and_order_ix_is_valid(ORDER o, OR or_node, int ix);
static inline ANDID and_order_get(ORDER o, OR or_node, int ix);
static inline void tree_exhaust(TREE t);
static inline void
tree_unref (TREE t);
static inline TREE
tree_ref (TREE t);
static inline void tree_free(TREE t);
static inline void
tree_pause (TREE t);
static inline void
tree_unpause (TREE t);
static inline int tree_or_node_try(TREE tree, ORID or_node_id);
static inline void tree_or_node_release(TREE tree, ORID or_node_id);
static inline void
value_unref (VALUE v);
static inline VALUE
value_ref (VALUE v);
static inline void value_free(VALUE v);
static inline int symbol_is_valued(
    VALUE v,
    Marpa_Symbol_ID xsy_id);
static inline int symbol_is_valued_set (
    VALUE v, XSYID xsy_id, int value);
static inline int lbv_bits_to_size(int bits);
static inline Bit_Vector
lbv_obs_new (struct marpa_obstack *obs, int bits);
static inline Bit_Vector
lbv_zero (Bit_Vector lbv, int bits);
static inline Bit_Vector
lbv_obs_new0 (struct marpa_obstack *obs, int bits);
static inline LBV lbv_clone(
  struct marpa_obstack* obs, LBV old_lbv, int bits);
static inline LBV lbv_fill(
  LBV lbv, int bits);
static inline unsigned int bv_bits_to_size(int bits);
static inline unsigned int bv_bits_to_unused_mask(int bits);
static inline Bit_Vector bv_create(int bits);
static inline Bit_Vector
bv_obs_create (struct marpa_obstack *obs, int bits);
static inline Bit_Vector bv_shadow(Bit_Vector bv);
static inline Bit_Vector bv_obs_shadow(struct marpa_obstack * obs, Bit_Vector bv);
static inline Bit_Vector bv_copy(Bit_Vector bv_to, Bit_Vector bv_from);
static inline Bit_Vector bv_clone(Bit_Vector bv);
static inline Bit_Vector bv_obs_clone(struct marpa_obstack *obs, Bit_Vector bv);
static inline void bv_free(Bit_Vector vector);
static inline void bv_fill(Bit_Vector bv);
static inline void bv_clear(Bit_Vector bv);
static inline void bv_over_clear(Bit_Vector bv, int raw_bit);
static inline void bv_bit_set(Bit_Vector vector, int raw_bit);
static inline void bv_bit_clear(Bit_Vector vector, int raw_bit);
static inline int bv_bit_test(Bit_Vector vector, int raw_bit);
static inline int
bv_bit_test_then_set (Bit_Vector vector, int raw_bit);
static inline int bv_is_empty(Bit_Vector addr);
static inline void bv_not(Bit_Vector X, Bit_Vector Y);
static inline void bv_and(Bit_Vector X, Bit_Vector Y, Bit_Vector Z);
static inline void bv_or(Bit_Vector X, Bit_Vector Y, Bit_Vector Z);
static inline void bv_or_assign(Bit_Vector X, Bit_Vector Y);
static inline int
bv_count (Bit_Vector v);
static inline void
rhs_closure (GRAMMAR g, Bit_Vector bv, XRLID ** xrl_list_x_rh_sym);
static inline Bit_Matrix
matrix_buffer_create (void *buffer, int rows, int columns);
static inline size_t matrix_sizeof(int rows, int columns);
static inline Bit_Matrix matrix_obs_create(
  struct marpa_obstack *obs,
  int rows,
  int columns);
static inline void matrix_clear(Bit_Matrix matrix);
static inline int matrix_columns(Bit_Matrix matrix);
static inline Bit_Vector matrix_row(Bit_Matrix matrix, int row);
static inline void matrix_bit_set(Bit_Matrix matrix, int row, int column);
static inline void matrix_bit_clear(Bit_Matrix matrix, int row, int column);
static inline int matrix_bit_test(Bit_Matrix matrix, int row, int column);
static inline void
cilar_init (const CILAR cilar);
static inline void
cilar_buffer_reinit (const CILAR cilar);
static inline void cilar_destroy(const CILAR cilar);
static inline CIL cil_empty(CILAR cilar);
static inline CIL cil_singleton(CILAR cilar, int element);
static inline CIL cil_buffer_add(CILAR cilar);
static inline CIL cil_bv_add(CILAR cilar, Bit_Vector bv);
static inline void cil_buffer_clear(CILAR cilar);
static inline CIL cil_buffer_push(CILAR cilar, int new_item);
static inline CIL cil_buffer_reserve(CILAR cilar, int element_count);
static inline CIL cil_merge(CILAR cilar, CIL cil1, CIL cil2);
static inline CIL cil_merge_one(CILAR cilar, CIL cil, int new_element);
static inline void
psar_safe (const PSAR psar);
static inline void
psar_init (const PSAR psar, int length);
static inline void psar_destroy(const PSAR psar);
static inline PSL psl_new(const PSAR psar);
static inline void psar_reset(const PSAR psar);
static inline void psar_dealloc(const PSAR psar);
static inline void psl_claim(
    PSL* const psl_owner, const PSAR psar);
static inline PSL psl_claim_by_es(
    PSAR or_psar,
    struct s_bocage_setup_per_ys* per_ys_data,
    YSID ysid);
static inline PSL psl_alloc(const PSAR psar);
static inline Marpa_Error_Code
clear_error (GRAMMAR g);
static inline void trace_earley_item_clear(RECCE r);
static inline void trace_source_link_clear(RECCE r);
static inline int look_yim(Marpa_Earley_Item_Look* look,
  YS earley_set, Marpa_Earley_Item_ID eim_id);

/*1364:*/
#line 16529 "./marpa.w"

/*1238:*/
#line 14841 "./marpa.w"

extern void*(*const marpa__out_of_memory)(void);

/*:1238*//*1344:*/
#line 16344 "./marpa.w"

extern int marpa__default_debug_handler(const char*format,...);
extern int(*marpa__debug_handler)(const char*,...);
extern int marpa__debug_level;

/*:1344*/
#line 16530 "./marpa.w"

#if MARPA_DEBUG
/*1349:*/
#line 16376 "./marpa.w"

static const char*yim_tag_safe(
char*buffer,GRAMMAR g,YIM yim)UNUSED;
static const char*yim_tag(GRAMMAR g,YIM yim)UNUSED;
/*:1349*//*1351:*/
#line 16402 "./marpa.w"

static char*lim_tag_safe(char*buffer,LIM lim)UNUSED;
static char*lim_tag(LIM lim)UNUSED;
/*:1351*//*1353:*/
#line 16428 "./marpa.w"

static const char*or_tag_safe(char*buffer,OR or)UNUSED;
static const char*or_tag(OR or)UNUSED;
/*:1353*//*1355:*/
#line 16460 "./marpa.w"

static const char*ahm_tag_safe(char*buffer,AHM ahm)UNUSED;
static const char*ahm_tag(AHM ahm)UNUSED;
/*:1355*/
#line 16532 "./marpa.w"

/*1350:*/
#line 16381 "./marpa.w"

static const char*
yim_tag_safe(char*buffer,GRAMMAR g,YIM yim)
{
if(!yim)return"NULL";
sprintf(buffer,"S%d@%d-%d",
AHMID_of_YIM(yim),Origin_Earleme_of_YIM(yim),
Earleme_of_YIM(yim));
return buffer;
}

static char DEBUG_yim_tag_buffer[1000];
static const char*
yim_tag(GRAMMAR g,YIM yim)
{
return yim_tag_safe(DEBUG_yim_tag_buffer,g,yim);
}

/*:1350*//*1352:*/
#line 16407 "./marpa.w"

static char*
lim_tag_safe(char*buffer,LIM lim)
{
sprintf(buffer,"L%d@%d",
Postdot_NSYID_of_LIM(lim),Earleme_of_LIM(lim));
return buffer;
}

static char DEBUG_lim_tag_buffer[1000];
static char*
lim_tag(LIM lim)
{
return lim_tag_safe(DEBUG_lim_tag_buffer,lim);
}

/*:1352*//*1354:*/
#line 16432 "./marpa.w"

static const char*
or_tag_safe(char*buffer,OR or)
{
if(!or)return"NULL";
if(OR_is_Token(or))return"TOKEN";
if(Type_of_OR(or)==DUMMY_OR_NODE)return"DUMMY";
sprintf(buffer,"R%d:%d@%d-%d",
IRLID_of_OR(or),Position_of_OR(or),
Origin_Ord_of_OR(or),
YS_Ord_of_OR(or));
return buffer;
}

static char DEBUG_or_tag_buffer[1000];
static const char*
or_tag(OR or)
{
return or_tag_safe(DEBUG_or_tag_buffer,or);
}

/*:1354*//*1356:*/
#line 16463 "./marpa.w"

static const char*
ahm_tag_safe(char*buffer,AHM ahm)
{
if(!ahm)return"NULL";
const int ahm_position= Position_of_AHM(ahm);
if(ahm_position>=0){
sprintf(buffer,"R%d@%d",IRLID_of_AHM(ahm),Position_of_AHM(ahm));
}else{
sprintf(buffer,"R%d@end",IRLID_of_AHM(ahm));
}
return buffer;
}

static char DEBUG_ahm_tag_buffer[1000];
static const char*
ahm_tag(AHM ahm)
{
return ahm_tag_safe(DEBUG_ahm_tag_buffer,ahm);
}

/*:1356*/
#line 16533 "./marpa.w"

#endif
/*1348:*/
#line 16368 "./marpa.w"

int(*marpa__debug_handler)(const char*,...)= 
marpa__default_debug_handler;
int marpa__debug_level= 0;

/*:1348*/
#line 16535 "./marpa.w"

/*41:*/
#line 581 "./marpa.w"

Marpa_Error_Code
marpa_check_version(int required_major,
int required_minor,
int required_micro)
{
if(required_major!=marpa_major_version)
return MARPA_ERR_MAJOR_VERSION_MISMATCH;
if(required_minor!=marpa_minor_version)
return MARPA_ERR_MINOR_VERSION_MISMATCH;
if(required_micro!=marpa_micro_version)
return MARPA_ERR_MICRO_VERSION_MISMATCH;
return MARPA_ERR_NONE;
}

/*:41*//*42:*/
#line 599 "./marpa.w"

Marpa_Error_Code
marpa_version(int*version)
{
*version++= marpa_major_version;
*version++= marpa_minor_version;
*version= marpa_micro_version;
return 0;
}

/*:42*//*45:*/
#line 618 "./marpa.w"

int marpa_c_init(Marpa_Config*config)
{
config->t_is_ok= I_AM_OK;
config->t_error= MARPA_ERR_NONE;
config->t_error_string= NULL;
return 0;
}

/*:45*//*46:*/
#line 627 "./marpa.w"

Marpa_Error_Code marpa_c_error(Marpa_Config*config,const char**p_error_string)
{
const Marpa_Error_Code error_code= config->t_error;
const char*error_string= config->t_error_string;
if(p_error_string){
*p_error_string= error_string;
}
return error_code;
}

const char*_marpa_tag(void)
{
#if defined(MARPA_TAG)
return STRINGIFY(MARPA_TAG);
#elif defined(__GNUC__)
return __DATE__" "__TIME__;
#else
return"[no tag]";
#endif
}

/*:46*//*51:*/
#line 664 "./marpa.w"

Marpa_Grammar marpa_g_new(Marpa_Config*configuration)
{
GRAMMAR g;
if(configuration&&configuration->t_is_ok!=I_AM_OK){
configuration->t_error= MARPA_ERR_I_AM_NOT_OK;
return NULL;
}
g= my_malloc(sizeof(struct marpa_g));


g->t_is_ok= 0;
/*54:*/
#line 685 "./marpa.w"

g->t_ref_count= 1;

/*:54*//*60:*/
#line 741 "./marpa.w"

MARPA_DSTACK_INIT2(g->t_xsy_stack,XSY);
MARPA_DSTACK_SAFE(g->t_nsy_stack);

/*:60*//*69:*/
#line 799 "./marpa.w"

MARPA_DSTACK_INIT2(g->t_xrl_stack,RULE);
MARPA_DSTACK_SAFE(g->t_irl_stack);

/*:69*//*79:*/
#line 847 "./marpa.w"

g->t_start_xsy_id= -1;
/*:79*//*83:*/
#line 885 "./marpa.w"

g->t_start_irl= NULL;

/*:83*//*86:*/
#line 899 "./marpa.w"

External_Size_of_G(g)= 0;

/*:86*//*89:*/
#line 912 "./marpa.w"

g->t_max_rule_length= 0;

/*:89*//*93:*/
#line 925 "./marpa.w"

g->t_default_rank= 0;
/*:93*//*98:*/
#line 960 "./marpa.w"

g->t_is_precomputed= 0;
/*:98*//*101:*/
#line 972 "./marpa.w"

g->t_has_cycle= 0;
/*:101*//*104:*/
#line 992 "./marpa.w"
g->t_bv_nsyid_is_terminal= NULL;

/*:104*//*106:*/
#line 1007 "./marpa.w"

g->t_lbv_xsyid_is_completion_event= NULL;
g->t_lbv_xsyid_completion_event_starts_active= NULL;
g->t_lbv_xsyid_is_nulled_event= NULL;
g->t_lbv_xsyid_nulled_event_starts_active= NULL;
g->t_lbv_xsyid_is_prediction_event= NULL;
g->t_lbv_xsyid_prediction_event_starts_active= NULL;

/*:106*//*113:*/
#line 1048 "./marpa.w"

MARPA_DSTACK_INIT(g->t_events,GEV_Object,INITIAL_G_EVENTS_CAPACITY);
/*:113*//*121:*/
#line 1120 "./marpa.w"

(g)->t_xrl_tree= _marpa_avl_create(duplicate_rule_cmp,NULL);
/*:121*//*125:*/
#line 1151 "./marpa.w"

g->t_obs= marpa_obs_init;
g->t_xrl_obs= marpa_obs_init;
/*:125*//*128:*/
#line 1167 "./marpa.w"

cilar_init(&(g)->t_cilar);
/*:128*//*137:*/
#line 1215 "./marpa.w"

g->t_error= MARPA_ERR_NONE;
g->t_error_string= NULL;
/*:137*//*162:*/
#line 1378 "./marpa.w"

g->t_force_valued= 0;
/*:162*//*459:*/
#line 4874 "./marpa.w"

g->t_ahms= NULL;
/*:459*//*531:*/
#line 5769 "./marpa.w"

MARPA_DSTACK_INIT2(g->t_gzwa_stack,GZWA);
/*:531*//*539:*/
#line 5808 "./marpa.w"

(g)->t_zwp_tree= _marpa_avl_create(zwp_cmp,NULL);
/*:539*/
#line 676 "./marpa.w"



g->t_is_ok= I_AM_OK;
return g;
}

/*:51*//*55:*/
#line 695 "./marpa.w"

PRIVATE
void
grammar_unref(GRAMMAR g)
{
MARPA_ASSERT(g->t_ref_count> 0)
g->t_ref_count--;
if(g->t_ref_count<=0)
{
grammar_free(g);
}
}
void
marpa_g_unref(Marpa_Grammar g)
{grammar_unref(g);}

/*:55*//*57:*/
#line 712 "./marpa.w"

PRIVATE GRAMMAR
grammar_ref(GRAMMAR g)
{
MARPA_ASSERT(g->t_ref_count> 0)
g->t_ref_count++;
return g;
}
Marpa_Grammar
marpa_g_ref(Marpa_Grammar g)
{return grammar_ref(g);}

/*:57*//*58:*/
#line 724 "./marpa.w"

PRIVATE
void grammar_free(GRAMMAR g)
{
/*61:*/
#line 745 "./marpa.w"

{
MARPA_DSTACK_DESTROY(g->t_xsy_stack);
MARPA_DSTACK_DESTROY(g->t_nsy_stack);
}

/*:61*//*70:*/
#line 803 "./marpa.w"

MARPA_DSTACK_DESTROY(g->t_irl_stack);
MARPA_DSTACK_DESTROY(g->t_xrl_stack);

/*:70*//*114:*/
#line 1050 "./marpa.w"
MARPA_DSTACK_DESTROY(g->t_events);

/*:114*//*123:*/
#line 1127 "./marpa.w"

/*122:*/
#line 1122 "./marpa.w"

{
_marpa_avl_destroy((g)->t_xrl_tree);
(g)->t_xrl_tree= NULL;
}
/*:122*/
#line 1128 "./marpa.w"


/*:123*//*126:*/
#line 1154 "./marpa.w"

marpa_obs_free(g->t_obs);
marpa_obs_free(g->t_xrl_obs);

/*:126*//*129:*/
#line 1169 "./marpa.w"

cilar_destroy(&(g)->t_cilar);

/*:129*//*460:*/
#line 4876 "./marpa.w"

my_free(g->t_ahms);

/*:460*//*532:*/
#line 5771 "./marpa.w"

MARPA_DSTACK_DESTROY(g->t_gzwa_stack);

/*:532*//*540:*/
#line 5810 "./marpa.w"

{
_marpa_avl_destroy((g)->t_zwp_tree);
(g)->t_zwp_tree= NULL;
}

/*:540*//*541:*/
#line 5816 "./marpa.w"

/*122:*/
#line 1122 "./marpa.w"

{
_marpa_avl_destroy((g)->t_xrl_tree);
(g)->t_xrl_tree= NULL;
}
/*:122*/
#line 5817 "./marpa.w"


/*:541*/
#line 728 "./marpa.w"

my_free(g);
}

/*:58*//*63:*/
#line 753 "./marpa.w"

int marpa_g_highest_symbol_id(Marpa_Grammar g){
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 755 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 756 "./marpa.w"

return XSY_Count_of_G(g)-1;
}

/*:63*//*65:*/
#line 765 "./marpa.w"

PRIVATE
void symbol_add(GRAMMAR g,XSY symbol)
{
const XSYID new_id= MARPA_DSTACK_LENGTH((g)->t_xsy_stack);
*MARPA_DSTACK_PUSH((g)->t_xsy_stack,XSY)= symbol;
symbol->t_symbol_id= new_id;
}

/*:65*//*66:*/
#line 777 "./marpa.w"

PRIVATE int xsy_id_is_valid(GRAMMAR g,XSYID xsy_id)
{
return!XSYID_is_Malformed(xsy_id)&&XSYID_of_G_Exists(xsy_id);
}

/*:66*//*67:*/
#line 786 "./marpa.w"

PRIVATE int nsy_is_valid(GRAMMAR g,NSYID nsyid)
{
return nsyid>=0&&nsyid<NSY_Count_of_G(g);
}

/*:67*//*74:*/
#line 810 "./marpa.w"

int marpa_g_highest_rule_id(Marpa_Grammar g){
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 812 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 813 "./marpa.w"

return XRL_Count_of_G(g)-1;
}
int _marpa_g_irl_count(Marpa_Grammar g){
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 817 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 818 "./marpa.w"

return IRL_Count_of_G(g);
}

/*:74*//*76:*/
#line 828 "./marpa.w"

PRIVATE void
rule_add(GRAMMAR g,RULE rule)
{
const RULEID new_id= MARPA_DSTACK_LENGTH((g)->t_xrl_stack);
*MARPA_DSTACK_PUSH((g)->t_xrl_stack,RULE)= rule;
rule->t_id= new_id;
External_Size_of_G(g)+= 1+Length_of_XRL(rule);
g->t_max_rule_length= MAX(Length_of_XRL(rule),g->t_max_rule_length);
}

/*:76*//*80:*/
#line 849 "./marpa.w"

Marpa_Symbol_ID marpa_g_start_symbol(Marpa_Grammar g)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 852 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 853 "./marpa.w"

if(g->t_start_xsy_id<0){
MARPA_ERROR(MARPA_ERR_NO_START_SYMBOL);
return-1;
}
return g->t_start_xsy_id;
}
/*:80*//*81:*/
#line 866 "./marpa.w"

Marpa_Symbol_ID marpa_g_start_symbol_set(Marpa_Grammar g,Marpa_Symbol_ID xsy_id)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 869 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 870 "./marpa.w"

/*1210:*/
#line 14594 "./marpa.w"

if(_MARPA_UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1210*/
#line 871 "./marpa.w"

/*1212:*/
#line 14605 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1212*/
#line 872 "./marpa.w"

/*1213:*/
#line 14612 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1213*/
#line 873 "./marpa.w"

return g->t_start_xsy_id= xsy_id;
}

/*:81*//*94:*/
#line 927 "./marpa.w"

Marpa_Rank marpa_g_default_rank(Marpa_Grammar g)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 930 "./marpa.w"

clear_error(g);
/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 932 "./marpa.w"

return Default_Rank_of_G(g);
}
/*:94*//*95:*/
#line 937 "./marpa.w"

Marpa_Rank marpa_g_default_rank_set(Marpa_Grammar g,Marpa_Rank rank)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 940 "./marpa.w"

clear_error(g);
/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 942 "./marpa.w"

/*1210:*/
#line 14594 "./marpa.w"

if(_MARPA_UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1210*/
#line 943 "./marpa.w"

if(_MARPA_UNLIKELY(rank<MINIMUM_RANK))
{
MARPA_ERROR(MARPA_ERR_RANK_TOO_LOW);
return failure_indicator;
}
if(_MARPA_UNLIKELY(rank> MAXIMUM_RANK))
{
MARPA_ERROR(MARPA_ERR_RANK_TOO_HIGH);
return failure_indicator;
}
return Default_Rank_of_G(g)= rank;
}

/*:95*//*99:*/
#line 962 "./marpa.w"

int marpa_g_is_precomputed(Marpa_Grammar g)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 965 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 966 "./marpa.w"

return G_is_Precomputed(g);
}

/*:99*//*102:*/
#line 974 "./marpa.w"

int marpa_g_has_cycle(Marpa_Grammar g)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 977 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 978 "./marpa.w"

return g->t_has_cycle;
}

/*:102*//*116:*/
#line 1060 "./marpa.w"

PRIVATE
void event_new(GRAMMAR g,int type)
{


GEV end_of_stack= G_EVENT_PUSH(g);
end_of_stack->t_type= type;
end_of_stack->t_value= 0;
}
/*:116*//*117:*/
#line 1070 "./marpa.w"

PRIVATE
void int_event_new(GRAMMAR g,int type,int value)
{


GEV end_of_stack= G_EVENT_PUSH(g);
end_of_stack->t_type= type;
end_of_stack->t_value= value;
}

/*:117*//*118:*/
#line 1081 "./marpa.w"

Marpa_Event_Type
marpa_g_event(Marpa_Grammar g,Marpa_Event*public_event,
int ix)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 1086 "./marpa.w"

MARPA_DSTACK events= &g->t_events;
GEV internal_event;
int type;

if(ix<0){
MARPA_ERROR(MARPA_ERR_EVENT_IX_NEGATIVE);
return failure_indicator;
}
if(ix>=MARPA_DSTACK_LENGTH(*events)){
MARPA_ERROR(MARPA_ERR_EVENT_IX_OOB);
return failure_indicator;
}
internal_event= MARPA_DSTACK_INDEX(*events,GEV_Object,ix);
type= internal_event->t_type;
public_event->t_type= type;
public_event->t_value= internal_event->t_value;
return type;
}

/*:118*//*119:*/
#line 1106 "./marpa.w"

Marpa_Event_Type
marpa_g_event_count(Marpa_Grammar g)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 1110 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 1111 "./marpa.w"

return MARPA_DSTACK_LENGTH(g->t_events);
}

/*:119*//*139:*/
#line 1226 "./marpa.w"

Marpa_Error_Code marpa_g_error(Marpa_Grammar g,const char**p_error_string)
{
const Marpa_Error_Code error_code= g->t_error;
const char*error_string= g->t_error_string;
if(p_error_string){
*p_error_string= error_string;
}
return error_code;
}

/*:139*//*140:*/
#line 1237 "./marpa.w"

Marpa_Error_Code
marpa_g_error_clear(Marpa_Grammar g)
{
clear_error(g);
return g->t_error;
}

/*:140*//*146:*/
#line 1267 "./marpa.w"

PRIVATE XSY
symbol_new(GRAMMAR g)
{
XSY xsy= marpa_obs_new(g->t_obs,struct s_xsy,1);
/*151:*/
#line 1300 "./marpa.w"

xsy->t_rank= Default_Rank_of_G(g);
/*:151*//*155:*/
#line 1346 "./marpa.w"

XSY_is_LHS(xsy)= 0;

/*:155*//*157:*/
#line 1353 "./marpa.w"

XSY_is_Sequence_LHS(xsy)= 0;

/*:157*//*159:*/
#line 1369 "./marpa.w"

XSY_is_Valued(xsy)= g->t_force_valued?1:0;
XSY_is_Valued_Locked(xsy)= g->t_force_valued?1:0;

/*:159*//*167:*/
#line 1437 "./marpa.w"

xsy->t_is_accessible= 0;
/*:167*//*170:*/
#line 1458 "./marpa.w"

xsy->t_is_counted= 0;
/*:170*//*173:*/
#line 1474 "./marpa.w"

xsy->t_is_nulling= 0;
/*:173*//*176:*/
#line 1491 "./marpa.w"

xsy->t_is_nullable= 0;
/*:176*//*179:*/
#line 1514 "./marpa.w"

xsy->t_is_terminal= 0;
xsy->t_is_locked_terminal= 0;
/*:179*//*184:*/
#line 1559 "./marpa.w"

xsy->t_is_productive= 0;
/*:184*//*187:*/
#line 1582 "./marpa.w"

xsy->t_is_completion_event= 0;
xsy->t_completion_event_starts_active= 0;
/*:187*//*192:*/
#line 1652 "./marpa.w"

xsy->t_is_nulled_event= 0;
xsy->t_nulled_event_starts_active= 0;
/*:192*//*197:*/
#line 1725 "./marpa.w"

xsy->t_is_prediction_event= 0;
xsy->t_prediction_event_starts_active= 0;
/*:197*//*203:*/
#line 1804 "./marpa.w"

Nulled_XSYIDs_of_XSY(xsy)= NULL;

/*:203*//*206:*/
#line 1820 "./marpa.w"
NSY_of_XSY(xsy)= NULL;
/*:206*//*210:*/
#line 1852 "./marpa.w"
Nulling_NSY_of_XSY(xsy)= NULL;
/*:210*/
#line 1272 "./marpa.w"

symbol_add(g,xsy);
return xsy;
}

/*:146*//*147:*/
#line 1277 "./marpa.w"

Marpa_Symbol_ID
marpa_g_symbol_new(Marpa_Grammar g)
{
const XSY symbol= symbol_new(g);
return ID_of_XSY(symbol);
}

/*:147*//*149:*/
#line 1286 "./marpa.w"

int marpa_g_symbol_is_start(Marpa_Grammar g,Marpa_Symbol_ID xsy_id)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 1289 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 1290 "./marpa.w"

/*1212:*/
#line 14605 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1212*/
#line 1291 "./marpa.w"

/*1213:*/
#line 14612 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1213*/
#line 1292 "./marpa.w"

if(g->t_start_xsy_id<0)return 0;
return xsy_id==g->t_start_xsy_id?1:0;
}

/*:149*//*152:*/
#line 1303 "./marpa.w"

int marpa_g_symbol_rank(Marpa_Grammar g,
Marpa_Symbol_ID xsy_id)
{
XSY xsy;
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 1308 "./marpa.w"

clear_error(g);
/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 1310 "./marpa.w"

/*1212:*/
#line 14605 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1212*/
#line 1311 "./marpa.w"

/*1214:*/
#line 14617 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return failure_indicator;
}

/*:1214*/
#line 1312 "./marpa.w"

xsy= XSY_by_ID(xsy_id);
return Rank_of_XSY(xsy);
}
/*:152*//*153:*/
#line 1316 "./marpa.w"

int marpa_g_symbol_rank_set(
Marpa_Grammar g,Marpa_Symbol_ID xsy_id,Marpa_Rank rank)
{
XSY xsy;
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 1321 "./marpa.w"

clear_error(g);
/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 1323 "./marpa.w"

/*1210:*/
#line 14594 "./marpa.w"

if(_MARPA_UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1210*/
#line 1324 "./marpa.w"

/*1212:*/
#line 14605 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1212*/
#line 1325 "./marpa.w"

/*1214:*/
#line 14617 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return failure_indicator;
}

/*:1214*/
#line 1326 "./marpa.w"

xsy= XSY_by_ID(xsy_id);
if(_MARPA_UNLIKELY(rank<MINIMUM_RANK))
{
MARPA_ERROR(MARPA_ERR_RANK_TOO_LOW);
return failure_indicator;
}
if(_MARPA_UNLIKELY(rank> MAXIMUM_RANK))
{
MARPA_ERROR(MARPA_ERR_RANK_TOO_HIGH);
return failure_indicator;
}
return Rank_of_XSY(xsy)= rank;
}

/*:153*//*163:*/
#line 1380 "./marpa.w"

int marpa_g_force_valued(Marpa_Grammar g)
{
XSYID xsyid;
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 1384 "./marpa.w"

for(xsyid= 0;xsyid<XSY_Count_of_G(g);xsyid++){
const XSY xsy= XSY_by_ID(xsyid);
if(!XSY_is_Valued(xsy)&&XSY_is_Valued_Locked(xsy))
{
MARPA_ERROR(MARPA_ERR_VALUED_IS_LOCKED);
return failure_indicator;
}
XSY_is_Valued(xsy)= 1;
XSY_is_Valued_Locked(xsy)= 1;
}
g->t_force_valued= 1;
return 0;
}

/*:163*//*164:*/
#line 1399 "./marpa.w"

int marpa_g_symbol_is_valued(
Marpa_Grammar g,
Marpa_Symbol_ID xsy_id)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 1404 "./marpa.w"

/*1212:*/
#line 14605 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1212*/
#line 1405 "./marpa.w"

/*1213:*/
#line 14612 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1213*/
#line 1406 "./marpa.w"

return XSY_is_Valued(XSY_by_ID(xsy_id));
}

/*:164*//*165:*/
#line 1410 "./marpa.w"

int marpa_g_symbol_is_valued_set(
Marpa_Grammar g,Marpa_Symbol_ID xsy_id,int value)
{
XSY symbol;
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 1415 "./marpa.w"

/*1212:*/
#line 14605 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1212*/
#line 1416 "./marpa.w"

/*1213:*/
#line 14612 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1213*/
#line 1417 "./marpa.w"

symbol= XSY_by_ID(xsy_id);
if(_MARPA_UNLIKELY(value<0||value> 1))
{
MARPA_ERROR(MARPA_ERR_INVALID_BOOLEAN);
return failure_indicator;
}
if(_MARPA_UNLIKELY(XSY_is_Valued_Locked(symbol)
&&value!=XSY_is_Valued(symbol)))
{
MARPA_ERROR(MARPA_ERR_VALUED_IS_LOCKED);
return failure_indicator;
}
XSY_is_Valued(symbol)= Boolean(value);
return value;
}

/*:165*//*168:*/
#line 1445 "./marpa.w"

int marpa_g_symbol_is_accessible(Marpa_Grammar g,Marpa_Symbol_ID xsy_id)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 1448 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 1449 "./marpa.w"

/*1211:*/
#line 14600 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1211*/
#line 1450 "./marpa.w"

/*1212:*/
#line 14605 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1212*/
#line 1451 "./marpa.w"

/*1213:*/
#line 14612 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1213*/
#line 1452 "./marpa.w"

return XSY_is_Accessible(XSY_by_ID(xsy_id));
}

/*:168*//*171:*/
#line 1460 "./marpa.w"

int marpa_g_symbol_is_counted(Marpa_Grammar g,
Marpa_Symbol_ID xsy_id)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 1464 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 1465 "./marpa.w"

/*1212:*/
#line 14605 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1212*/
#line 1466 "./marpa.w"

/*1213:*/
#line 14612 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1213*/
#line 1467 "./marpa.w"

return XSY_by_ID(xsy_id)->t_is_counted;
}

/*:171*//*174:*/
#line 1476 "./marpa.w"

int marpa_g_symbol_is_nulling(Marpa_Grammar g,Marpa_Symbol_ID xsy_id)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 1479 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 1480 "./marpa.w"

/*1211:*/
#line 14600 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1211*/
#line 1481 "./marpa.w"

/*1212:*/
#line 14605 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1212*/
#line 1482 "./marpa.w"

/*1213:*/
#line 14612 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1213*/
#line 1483 "./marpa.w"

return XSY_is_Nulling(XSY_by_ID(xsy_id));
}

/*:174*//*177:*/
#line 1493 "./marpa.w"

int marpa_g_symbol_is_nullable(Marpa_Grammar g,Marpa_Symbol_ID xsy_id)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 1496 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 1497 "./marpa.w"

/*1211:*/
#line 14600 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1211*/
#line 1498 "./marpa.w"

/*1212:*/
#line 14605 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1212*/
#line 1499 "./marpa.w"

/*1213:*/
#line 14612 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1213*/
#line 1500 "./marpa.w"

return XSYID_is_Nullable(xsy_id);
}

/*:177*//*181:*/
#line 1520 "./marpa.w"

int marpa_g_symbol_is_terminal(Marpa_Grammar g,
Marpa_Symbol_ID xsy_id)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 1524 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 1525 "./marpa.w"

/*1212:*/
#line 14605 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1212*/
#line 1526 "./marpa.w"

/*1213:*/
#line 14612 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1213*/
#line 1527 "./marpa.w"

return XSYID_is_Terminal(xsy_id);
}
/*:181*//*182:*/
#line 1530 "./marpa.w"

int marpa_g_symbol_is_terminal_set(
Marpa_Grammar g,Marpa_Symbol_ID xsy_id,int value)
{
XSY symbol;
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 1535 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 1536 "./marpa.w"

/*1210:*/
#line 14594 "./marpa.w"

if(_MARPA_UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1210*/
#line 1537 "./marpa.w"

/*1212:*/
#line 14605 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1212*/
#line 1538 "./marpa.w"

/*1213:*/
#line 14612 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1213*/
#line 1539 "./marpa.w"

symbol= XSY_by_ID(xsy_id);
if(_MARPA_UNLIKELY(value<0||value> 1))
{
MARPA_ERROR(MARPA_ERR_INVALID_BOOLEAN);
return failure_indicator;
}
if(_MARPA_UNLIKELY(XSY_is_Locked_Terminal(symbol))
&&XSY_is_Terminal(symbol)!=value)
{
MARPA_ERROR(MARPA_ERR_TERMINAL_IS_LOCKED);
return failure_indicator;
}
XSY_is_Locked_Terminal(symbol)= 1;
return XSY_is_Terminal(symbol)= Boolean(value);
}

/*:182*//*185:*/
#line 1561 "./marpa.w"

int marpa_g_symbol_is_productive(
Marpa_Grammar g,
Marpa_Symbol_ID xsy_id)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 1566 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 1567 "./marpa.w"

/*1211:*/
#line 14600 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1211*/
#line 1568 "./marpa.w"

/*1212:*/
#line 14605 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1212*/
#line 1569 "./marpa.w"

/*1213:*/
#line 14612 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1213*/
#line 1570 "./marpa.w"

return XSY_is_Productive(XSY_by_ID(xsy_id));
}

/*:185*//*188:*/
#line 1585 "./marpa.w"

int marpa_g_symbol_is_completion_event(Marpa_Grammar g,
Marpa_Symbol_ID xsy_id)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 1589 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 1590 "./marpa.w"

/*1212:*/
#line 14605 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1212*/
#line 1591 "./marpa.w"

/*1213:*/
#line 14612 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1213*/
#line 1592 "./marpa.w"

return XSYID_is_Completion_Event(xsy_id);
}
/*:188*//*189:*/
#line 1595 "./marpa.w"

int marpa_g_symbol_is_completion_event_set(
Marpa_Grammar g,Marpa_Symbol_ID xsy_id,int value)
{
XSY xsy;
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 1600 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 1601 "./marpa.w"

/*1210:*/
#line 14594 "./marpa.w"

if(_MARPA_UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1210*/
#line 1602 "./marpa.w"

/*1212:*/
#line 14605 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1212*/
#line 1603 "./marpa.w"

/*1213:*/
#line 14612 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1213*/
#line 1604 "./marpa.w"

xsy= XSY_by_ID(xsy_id);
switch(value){
case 0:case 1:
XSY_Completion_Event_Starts_Active(xsy)= Boolean(value);
return XSY_is_Completion_Event(xsy)= Boolean(value);
}
MARPA_ERROR(MARPA_ERR_INVALID_BOOLEAN);
return failure_indicator;
}
/*:189*//*190:*/
#line 1614 "./marpa.w"

int
marpa_g_completion_symbol_activate(Marpa_Grammar g,
Marpa_Symbol_ID xsy_id,
int reactivate)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 1620 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 1621 "./marpa.w"

/*1210:*/
#line 14594 "./marpa.w"

if(_MARPA_UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1210*/
#line 1622 "./marpa.w"

/*1212:*/
#line 14605 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1212*/
#line 1623 "./marpa.w"

/*1213:*/
#line 14612 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1213*/
#line 1624 "./marpa.w"

switch(reactivate){
case 0:
XSYID_Completion_Event_Starts_Active(xsy_id)
= Boolean(reactivate);
return 0;
case 1:
if(!XSYID_is_Completion_Event(xsy_id)){


MARPA_ERROR(MARPA_ERR_SYMBOL_IS_NOT_COMPLETION_EVENT);
}
XSYID_Completion_Event_Starts_Active(xsy_id)
= Boolean(reactivate);
return 1;
}
MARPA_ERROR(MARPA_ERR_INVALID_BOOLEAN);
return failure_indicator;
}

/*:190*//*193:*/
#line 1655 "./marpa.w"

int marpa_g_symbol_is_nulled_event(Marpa_Grammar g,
Marpa_Symbol_ID xsy_id)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 1659 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 1660 "./marpa.w"

/*1212:*/
#line 14605 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1212*/
#line 1661 "./marpa.w"

/*1213:*/
#line 14612 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1213*/
#line 1662 "./marpa.w"

return XSYID_is_Nulled_Event(xsy_id);
}

/*:193*//*194:*/
#line 1668 "./marpa.w"

int marpa_g_symbol_is_nulled_event_set(
Marpa_Grammar g,Marpa_Symbol_ID xsy_id,int value)
{
XSY xsy;
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 1673 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 1674 "./marpa.w"

/*1210:*/
#line 14594 "./marpa.w"

if(_MARPA_UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1210*/
#line 1675 "./marpa.w"

/*1212:*/
#line 14605 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1212*/
#line 1676 "./marpa.w"

/*1213:*/
#line 14612 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1213*/
#line 1677 "./marpa.w"

xsy= XSY_by_ID(xsy_id);
switch(value){
case 0:case 1:
XSY_Nulled_Event_Starts_Active(xsy)= Boolean(value);
return XSY_is_Nulled_Event(xsy)= Boolean(value);
}
MARPA_ERROR(MARPA_ERR_INVALID_BOOLEAN);
return failure_indicator;
}
/*:194*//*195:*/
#line 1687 "./marpa.w"

int
marpa_g_nulled_symbol_activate(Marpa_Grammar g,
Marpa_Symbol_ID xsy_id,
int reactivate)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 1693 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 1694 "./marpa.w"

/*1210:*/
#line 14594 "./marpa.w"

if(_MARPA_UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1210*/
#line 1695 "./marpa.w"

/*1212:*/
#line 14605 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1212*/
#line 1696 "./marpa.w"

/*1213:*/
#line 14612 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1213*/
#line 1697 "./marpa.w"

switch(reactivate){
case 0:
XSYID_Nulled_Event_Starts_Active(xsy_id)
= Boolean(reactivate);
return 0;
case 1:
if(!XSYID_is_Nulled_Event(xsy_id)){


MARPA_ERROR(MARPA_ERR_SYMBOL_IS_NOT_COMPLETION_EVENT);
}
XSYID_Nulled_Event_Starts_Active(xsy_id)
= Boolean(reactivate);
return 1;
}
MARPA_ERROR(MARPA_ERR_INVALID_BOOLEAN);
return failure_indicator;
}

/*:195*//*198:*/
#line 1728 "./marpa.w"

int marpa_g_symbol_is_prediction_event(Marpa_Grammar g,
Marpa_Symbol_ID xsy_id)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 1732 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 1733 "./marpa.w"

/*1212:*/
#line 14605 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1212*/
#line 1734 "./marpa.w"

/*1213:*/
#line 14612 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1213*/
#line 1735 "./marpa.w"

return XSYID_is_Prediction_Event(xsy_id);
}
/*:198*//*199:*/
#line 1738 "./marpa.w"

int marpa_g_symbol_is_prediction_event_set(
Marpa_Grammar g,Marpa_Symbol_ID xsy_id,int value)
{
XSY xsy;
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 1743 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 1744 "./marpa.w"

/*1210:*/
#line 14594 "./marpa.w"

if(_MARPA_UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1210*/
#line 1745 "./marpa.w"

/*1212:*/
#line 14605 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1212*/
#line 1746 "./marpa.w"

/*1213:*/
#line 14612 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1213*/
#line 1747 "./marpa.w"

xsy= XSY_by_ID(xsy_id);
switch(value){
case 0:case 1:
XSY_Prediction_Event_Starts_Active(xsy)= Boolean(value);
return XSY_is_Prediction_Event(xsy)= Boolean(value);
}
MARPA_ERROR(MARPA_ERR_INVALID_BOOLEAN);
return failure_indicator;
}
/*:199*//*200:*/
#line 1757 "./marpa.w"

int
marpa_g_prediction_symbol_activate(Marpa_Grammar g,
Marpa_Symbol_ID xsy_id,
int reactivate)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 1763 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 1764 "./marpa.w"

/*1210:*/
#line 14594 "./marpa.w"

if(_MARPA_UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1210*/
#line 1765 "./marpa.w"

/*1212:*/
#line 14605 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1212*/
#line 1766 "./marpa.w"

/*1213:*/
#line 14612 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1213*/
#line 1767 "./marpa.w"

switch(reactivate){
case 0:
XSYID_Prediction_Event_Starts_Active(xsy_id)
= Boolean(reactivate);
return 0;
case 1:
if(!XSYID_is_Prediction_Event(xsy_id)){


MARPA_ERROR(MARPA_ERR_SYMBOL_IS_NOT_COMPLETION_EVENT);
}
XSYID_Prediction_Event_Starts_Active(xsy_id)
= Boolean(reactivate);
return 1;
}
MARPA_ERROR(MARPA_ERR_INVALID_BOOLEAN);
return failure_indicator;
}

/*:200*//*201:*/
#line 1787 "./marpa.w"

/*:201*//*207:*/
#line 1821 "./marpa.w"

Marpa_NSY_ID _marpa_g_xsy_nsy(
Marpa_Grammar g,
Marpa_Symbol_ID xsy_id)
{
XSY xsy;
NSY nsy;
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 1828 "./marpa.w"

/*1212:*/
#line 14605 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1212*/
#line 1829 "./marpa.w"

/*1213:*/
#line 14612 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1213*/
#line 1830 "./marpa.w"

xsy= XSY_by_ID(xsy_id);
nsy= NSY_of_XSY(xsy);
return nsy?ID_of_NSY(nsy):-1;
}

/*:207*//*211:*/
#line 1853 "./marpa.w"

Marpa_NSY_ID _marpa_g_xsy_nulling_nsy(
Marpa_Grammar g,
Marpa_Symbol_ID xsy_id)
{
XSY xsy;
NSY nsy;
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 1860 "./marpa.w"

/*1212:*/
#line 14605 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1212*/
#line 1861 "./marpa.w"

/*1213:*/
#line 14612 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1213*/
#line 1862 "./marpa.w"

xsy= XSY_by_ID(xsy_id);
nsy= Nulling_NSY_of_XSY(xsy);
return nsy?ID_of_NSY(nsy):-1;
}

/*:211*//*213:*/
#line 1874 "./marpa.w"

PRIVATE
NSY symbol_alias_create(GRAMMAR g,XSY symbol)
{
NSY alias_nsy= semantic_nsy_new(g,symbol);
XSY_is_Nulling(symbol)= 0;
XSY_is_Nullable(symbol)= 1;
NSY_is_Nulling(alias_nsy)= 1;
return alias_nsy;
}

/*:213*//*220:*/
#line 1932 "./marpa.w"

PRIVATE NSY
nsy_start(GRAMMAR g)
{
const NSY nsy= marpa_obs_new(g->t_obs,struct s_nsy,1);
ID_of_NSY(nsy)= MARPA_DSTACK_LENGTH((g)->t_nsy_stack);
*MARPA_DSTACK_PUSH((g)->t_nsy_stack,NSY)= nsy;
/*218:*/
#line 1924 "./marpa.w"

nsy->t_nulling_or_node.t_or_node_type= NULLING_TOKEN_OR_NODE;

nsy->t_unvalued_or_node.t_or_node_type= UNVALUED_TOKEN_OR_NODE;
nsy->t_unvalued_or_node.t_nsyid= ID_of_NSY(nsy);

/*:218*//*228:*/
#line 2000 "./marpa.w"
NSY_is_Start(nsy)= 0;
/*:228*//*231:*/
#line 2014 "./marpa.w"
NSY_is_LHS(nsy)= 0;
/*:231*//*234:*/
#line 2028 "./marpa.w"
NSY_is_Nulling(nsy)= 0;
/*:234*//*237:*/
#line 2045 "./marpa.w"
LHS_CIL_of_NSY(nsy)= NULL;

/*:237*//*239:*/
#line 2053 "./marpa.w"
NSY_is_Semantic(nsy)= 0;
/*:239*//*242:*/
#line 2076 "./marpa.w"
Source_XSY_of_NSY(nsy)= NULL;
/*:242*//*246:*/
#line 2101 "./marpa.w"

LHS_XRL_of_NSY(nsy)= NULL;
XRL_Offset_of_NSY(nsy)= -1;

/*:246*//*251:*/
#line 2152 "./marpa.w"

Rank_of_NSY(nsy)= Default_Rank_of_G(g)*EXTERNAL_RANK_FACTOR+MAXIMUM_CHAF_RANK;
/*:251*/
#line 1939 "./marpa.w"

return nsy;
}

/*:220*//*221:*/
#line 1945 "./marpa.w"

PRIVATE NSY
nsy_new(GRAMMAR g,XSY source)
{
const NSY new_nsy= nsy_start(g);
Source_XSY_of_NSY(new_nsy)= source;
Rank_of_NSY(new_nsy)= NSY_Rank_by_XSY(source);
return new_nsy;
}

/*:221*//*222:*/
#line 1957 "./marpa.w"

PRIVATE NSY
semantic_nsy_new(GRAMMAR g,XSY source)
{
const NSY new_nsy= nsy_new(g,source);
NSY_is_Semantic(new_nsy)= 1;
return new_nsy;
}

/*:222*//*223:*/
#line 1968 "./marpa.w"

PRIVATE NSY
nsy_clone(GRAMMAR g,XSY xsy)
{
const NSY new_nsy= nsy_start(g);
Source_XSY_of_NSY(new_nsy)= xsy;
NSY_is_Semantic(new_nsy)= 1;
Rank_of_NSY(new_nsy)= NSY_Rank_by_XSY(xsy);
NSY_is_Nulling(new_nsy)= XSY_is_Nulling(xsy);
return new_nsy;
}

/*:223*//*226:*/
#line 1990 "./marpa.w"

int _marpa_g_nsy_count(Marpa_Grammar g){
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 1992 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 1993 "./marpa.w"

return NSY_Count_of_G(g);
}

/*:226*//*229:*/
#line 2001 "./marpa.w"

int _marpa_g_nsy_is_start(Marpa_Grammar g,Marpa_NSY_ID nsy_id)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 2004 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 2005 "./marpa.w"

/*1211:*/
#line 14600 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1211*/
#line 2006 "./marpa.w"

/*1215:*/
#line 14623 "./marpa.w"

if(_MARPA_UNLIKELY(!nsy_is_valid(g,nsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_NSYID);
return failure_indicator;
}
/*:1215*/
#line 2007 "./marpa.w"

return NSY_is_Start(NSY_by_ID(nsy_id));
}

/*:229*//*232:*/
#line 2015 "./marpa.w"

int _marpa_g_nsy_is_lhs(Marpa_Grammar g,Marpa_NSY_ID nsy_id)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 2018 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 2019 "./marpa.w"

/*1211:*/
#line 14600 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1211*/
#line 2020 "./marpa.w"

/*1215:*/
#line 14623 "./marpa.w"

if(_MARPA_UNLIKELY(!nsy_is_valid(g,nsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_NSYID);
return failure_indicator;
}
/*:1215*/
#line 2021 "./marpa.w"

return NSY_is_LHS(NSY_by_ID(nsy_id));
}

/*:232*//*235:*/
#line 2029 "./marpa.w"

int _marpa_g_nsy_is_nulling(Marpa_Grammar g,Marpa_NSY_ID nsy_id)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 2032 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 2033 "./marpa.w"

/*1211:*/
#line 14600 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1211*/
#line 2034 "./marpa.w"

/*1215:*/
#line 14623 "./marpa.w"

if(_MARPA_UNLIKELY(!nsy_is_valid(g,nsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_NSYID);
return failure_indicator;
}
/*:1215*/
#line 2035 "./marpa.w"

return NSY_is_Nulling(NSY_by_ID(nsy_id));
}

/*:235*//*240:*/
#line 2054 "./marpa.w"

int _marpa_g_nsy_is_semantic(
Marpa_Grammar g,
Marpa_IRL_ID nsy_id)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 2059 "./marpa.w"

/*1215:*/
#line 14623 "./marpa.w"

if(_MARPA_UNLIKELY(!nsy_is_valid(g,nsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_NSYID);
return failure_indicator;
}
/*:1215*/
#line 2060 "./marpa.w"

return NSYID_is_Semantic(nsy_id);
}

/*:240*//*243:*/
#line 2077 "./marpa.w"

Marpa_Rule_ID _marpa_g_source_xsy(
Marpa_Grammar g,
Marpa_IRL_ID nsy_id)
{
XSY source_xsy;
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 2083 "./marpa.w"

/*1215:*/
#line 14623 "./marpa.w"

if(_MARPA_UNLIKELY(!nsy_is_valid(g,nsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_NSYID);
return failure_indicator;
}
/*:1215*/
#line 2084 "./marpa.w"

source_xsy= Source_XSY_of_NSYID(nsy_id);
return ID_of_XSY(source_xsy);
}

/*:243*//*248:*/
#line 2112 "./marpa.w"

Marpa_Rule_ID _marpa_g_nsy_lhs_xrl(Marpa_Grammar g,Marpa_NSY_ID nsy_id)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 2115 "./marpa.w"

/*1215:*/
#line 14623 "./marpa.w"

if(_MARPA_UNLIKELY(!nsy_is_valid(g,nsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_NSYID);
return failure_indicator;
}
/*:1215*/
#line 2116 "./marpa.w"

{
const NSY nsy= NSY_by_ID(nsy_id);
const XRL lhs_xrl= LHS_XRL_of_NSY(nsy);
if(lhs_xrl)
return ID_of_XRL(lhs_xrl);
}
return-1;
}

/*:248*//*249:*/
#line 2136 "./marpa.w"

int _marpa_g_nsy_xrl_offset(Marpa_Grammar g,Marpa_NSY_ID nsy_id)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 2139 "./marpa.w"

NSY nsy;
/*1215:*/
#line 14623 "./marpa.w"

if(_MARPA_UNLIKELY(!nsy_is_valid(g,nsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_NSYID);
return failure_indicator;
}
/*:1215*/
#line 2141 "./marpa.w"

nsy= NSY_by_ID(nsy_id);
return XRL_Offset_of_NSY(nsy);
}

/*:249*//*252:*/
#line 2154 "./marpa.w"

Marpa_Rank _marpa_g_nsy_rank(
Marpa_Grammar g,
Marpa_NSY_ID nsy_id)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 2159 "./marpa.w"

/*1215:*/
#line 14623 "./marpa.w"

if(_MARPA_UNLIKELY(!nsy_is_valid(g,nsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_NSYID);
return failure_indicator;
}
/*:1215*/
#line 2160 "./marpa.w"

return Rank_of_NSY(NSY_by_ID(nsy_id));
}

/*:252*//*258:*/
#line 2195 "./marpa.w"

PRIVATE
XRL xrl_start(GRAMMAR g,const XSYID lhs,const XSYID*rhs,int length)
{
XRL xrl;
const size_t sizeof_xrl= offsetof(struct s_xrl,t_symbols)+
((size_t)length+1)*sizeof(xrl->t_symbols[0]);
xrl= marpa_obs_start(g->t_xrl_obs,sizeof_xrl,ALIGNOF(XRL));
Length_of_XRL(xrl)= length;
xrl->t_symbols[0]= lhs;
XSY_is_LHS(XSY_by_ID(lhs))= 1;
{
int i;
for(i= 0;i<length;i++)
{
xrl->t_symbols[i+1]= rhs[i];
}
}
return xrl;
}

PRIVATE
XRL xrl_finish(GRAMMAR g,XRL rule)
{
/*277:*/
#line 2541 "./marpa.w"

rule->t_rank= Default_Rank_of_G(g);
/*:277*//*281:*/
#line 2590 "./marpa.w"

rule->t_null_ranks_high= 0;
/*:281*//*285:*/
#line 2630 "./marpa.w"

rule->t_is_bnf= 0;

/*:285*//*287:*/
#line 2636 "./marpa.w"

rule->t_is_sequence= 0;

/*:287*//*289:*/
#line 2650 "./marpa.w"

rule->t_minimum= -1;
/*:289*//*292:*/
#line 2676 "./marpa.w"

Separator_of_XRL(rule)= -1;
/*:292*//*297:*/
#line 2713 "./marpa.w"

rule->t_is_discard= 0;
/*:297*//*301:*/
#line 2753 "./marpa.w"

rule->t_is_proper_separation= 0;
/*:301*//*305:*/
#line 2774 "./marpa.w"

rule->t_is_loop= 0;
/*:305*//*308:*/
#line 2792 "./marpa.w"

XRL_is_Nulling(rule)= 0;
/*:308*//*311:*/
#line 2811 "./marpa.w"

XRL_is_Nullable(rule)= 0;
/*:311*//*315:*/
#line 2830 "./marpa.w"

XRL_is_Accessible(rule)= 1;
/*:315*//*318:*/
#line 2849 "./marpa.w"

XRL_is_Productive(rule)= 1;
/*:318*//*321:*/
#line 2868 "./marpa.w"

XRL_is_Used(rule)= 0;
/*:321*/
#line 2219 "./marpa.w"

rule_add(g,rule);
return rule;
}

PRIVATE_NOT_INLINE
RULE rule_new(GRAMMAR g,
const XSYID lhs,const XSYID*rhs,int length)
{
RULE rule= xrl_start(g,lhs,rhs,length);
xrl_finish(g,rule);
rule= marpa_obs_finish(g->t_xrl_obs);
return rule;
}

/*:258*//*259:*/
#line 2235 "./marpa.w"

PRIVATE IRL
irl_start(GRAMMAR g,int length)
{
IRL irl;
const size_t sizeof_irl= offsetof(struct s_irl,t_nsyid_array)+
((size_t)length+1)*sizeof(irl->t_nsyid_array[0]);


irl= marpa__obs_alloc(g->t_obs,sizeof_irl,ALIGNOF(IRL_Object));

ID_of_IRL(irl)= MARPA_DSTACK_LENGTH((g)->t_irl_stack);
Length_of_IRL(irl)= length;
/*342:*/
#line 3005 "./marpa.w"

IRL_has_Virtual_LHS(irl)= 0;
/*:342*//*345:*/
#line 3021 "./marpa.w"

IRL_has_Virtual_RHS(irl)= 0;
/*:345*//*348:*/
#line 3040 "./marpa.w"

IRL_is_Right_Recursive(irl)= 0;

/*:348*//*351:*/
#line 3051 "./marpa.w"
Real_SYM_Count_of_IRL(irl)= 0;
/*:351*//*354:*/
#line 3069 "./marpa.w"
irl->t_virtual_start= -1;
/*:354*//*357:*/
#line 3089 "./marpa.w"
irl->t_virtual_end= -1;
/*:357*//*360:*/
#line 3111 "./marpa.w"
Source_XRL_of_IRL(irl)= NULL;
/*:360*//*363:*/
#line 3138 "./marpa.w"

Rank_of_IRL(irl)= Default_Rank_of_G(g)*EXTERNAL_RANK_FACTOR+MAXIMUM_CHAF_RANK;
/*:363*//*366:*/
#line 3160 "./marpa.w"

First_AHM_of_IRL(irl)= NULL;

/*:366*//*410:*/
#line 4058 "./marpa.w"

IRL_is_CHAF(irl)= 0;
/*:410*//*473:*/
#line 4973 "./marpa.w"

Last_Proper_SYMI_of_IRL(irl)= -1;

/*:473*/
#line 2248 "./marpa.w"

*MARPA_DSTACK_PUSH((g)->t_irl_stack,IRL)= irl;
return irl;
}

PRIVATE void
irl_finish(GRAMMAR g,IRL irl)
{
const NSY lhs_nsy= LHS_of_IRL(irl);
NSY_is_LHS(lhs_nsy)= 1;
}

/*:259*//*261:*/
#line 2274 "./marpa.w"

Marpa_Rule_ID
marpa_g_rule_new(Marpa_Grammar g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID*rhs_ids,int length)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 2279 "./marpa.w"

Marpa_Rule_ID rule_id;
RULE rule;
/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 2282 "./marpa.w"

/*1210:*/
#line 14594 "./marpa.w"

if(_MARPA_UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1210*/
#line 2283 "./marpa.w"

if(_MARPA_UNLIKELY(length> MAX_RHS_LENGTH))
{
MARPA_ERROR(MARPA_ERR_RHS_TOO_LONG);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!xsy_id_is_valid(g,lhs_id)))
{
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
{
int rh_index;
for(rh_index= 0;rh_index<length;rh_index++)
{
const XSYID rhs_id= rhs_ids[rh_index];
if(_MARPA_UNLIKELY(!xsy_id_is_valid(g,rhs_id)))
{
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
}
}
{
const XSY lhs= XSY_by_ID(lhs_id);
if(_MARPA_UNLIKELY(XSY_is_Sequence_LHS(lhs)))
{
MARPA_ERROR(MARPA_ERR_SEQUENCE_LHS_NOT_UNIQUE);
return failure_indicator;
}
}
rule= xrl_start(g,lhs_id,rhs_ids,length);
if(_MARPA_UNLIKELY(_marpa_avl_insert(g->t_xrl_tree,rule)!=NULL))
{
MARPA_ERROR(MARPA_ERR_DUPLICATE_RULE);
marpa_obs_reject(g->t_xrl_obs);
return failure_indicator;
}
rule= xrl_finish(g,rule);
rule= marpa_obs_finish(g->t_xrl_obs);
XRL_is_BNF(rule)= 1;
rule_id= rule->t_id;
return rule_id;
}

/*:261*//*262:*/
#line 2328 "./marpa.w"

Marpa_Rule_ID marpa_g_sequence_new(Marpa_Grammar g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID rhs_id,Marpa_Symbol_ID separator_id,
int min,int flags)
{
RULE original_rule;
RULEID original_rule_id= -2;
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 2335 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 2336 "./marpa.w"

/*1210:*/
#line 14594 "./marpa.w"

if(_MARPA_UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1210*/
#line 2337 "./marpa.w"

/*264:*/
#line 2368 "./marpa.w"

{
if(separator_id!=-1)
{
if(_MARPA_UNLIKELY(!xsy_id_is_valid(g,separator_id)))
{
MARPA_ERROR(MARPA_ERR_BAD_SEPARATOR);
goto FAILURE;
}
}
if(_MARPA_UNLIKELY(!xsy_id_is_valid(g,lhs_id)))
{
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
goto FAILURE;
}
{
const XSY lhs= XSY_by_ID(lhs_id);
if(_MARPA_UNLIKELY(XSY_is_LHS(lhs)))
{
MARPA_ERROR(MARPA_ERR_SEQUENCE_LHS_NOT_UNIQUE);
goto FAILURE;
}
}
if(_MARPA_UNLIKELY(!xsy_id_is_valid(g,rhs_id)))
{
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
goto FAILURE;
}
}

/*:264*/
#line 2338 "./marpa.w"

/*263:*/
#line 2346 "./marpa.w"

{
original_rule= rule_new(g,lhs_id,&rhs_id,1);
original_rule_id= original_rule->t_id;
if(separator_id>=0)
Separator_of_XRL(original_rule)= separator_id;
Minimum_of_XRL(original_rule)= min;
XRL_is_Sequence(original_rule)= 1;
original_rule->t_is_discard= !(flags&MARPA_KEEP_SEPARATION)
&&separator_id>=0;
if(flags&MARPA_PROPER_SEPARATION)
{
XRL_is_Proper_Separation(original_rule)= 1;
}
XSY_is_Sequence_LHS(XSY_by_ID(lhs_id))= 1;
XSY_by_ID(rhs_id)->t_is_counted= 1;
if(separator_id>=0)
{
XSY_by_ID(separator_id)->t_is_counted= 1;
}
}

/*:263*/
#line 2339 "./marpa.w"

return original_rule_id;
FAILURE:
return failure_indicator;
}

/*:262*//*266:*/
#line 2421 "./marpa.w"

PRIVATE_NOT_INLINE int
duplicate_rule_cmp(const void*ap,const void*bp,void*param UNUSED)
{
XRL xrl1= (XRL)ap;
XRL xrl2= (XRL)bp;
int diff= LHS_ID_of_XRL(xrl2)-LHS_ID_of_XRL(xrl1);
if(diff)
return diff;
{




int ix;
const int length= Length_of_XRL(xrl1);
diff= Length_of_XRL(xrl2)-length;
if(diff)
return diff;
for(ix= 0;ix<length;ix++)
{
diff= RHS_ID_of_XRL(xrl2,ix)-RHS_ID_of_XRL(xrl1,ix);
if(diff)
return diff;
}
}
return 0;
}

/*:266*//*269:*/
#line 2477 "./marpa.w"

PRIVATE Marpa_Symbol_ID rule_lhs_get(RULE rule)
{
return rule->t_symbols[0];}
/*:269*//*270:*/
#line 2481 "./marpa.w"

Marpa_Symbol_ID marpa_g_rule_lhs(Marpa_Grammar g,Marpa_Rule_ID xrl_id){
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 2483 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 2484 "./marpa.w"

/*1221:*/
#line 14661 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}

/*:1221*/
#line 2485 "./marpa.w"

/*1219:*/
#line 14649 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}

/*:1219*/
#line 2486 "./marpa.w"

return rule_lhs_get(XRL_by_ID(xrl_id));
}
/*:270*//*271:*/
#line 2489 "./marpa.w"

PRIVATE Marpa_Symbol_ID*rule_rhs_get(RULE rule)
{
return rule->t_symbols+1;}
/*:271*//*272:*/
#line 2493 "./marpa.w"

Marpa_Symbol_ID marpa_g_rule_rhs(Marpa_Grammar g,Marpa_Rule_ID xrl_id,int ix){
RULE rule;
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 2496 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 2497 "./marpa.w"

/*1221:*/
#line 14661 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}

/*:1221*/
#line 2498 "./marpa.w"

/*1219:*/
#line 14649 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}

/*:1219*/
#line 2499 "./marpa.w"

rule= XRL_by_ID(xrl_id);
if(ix<0){
MARPA_ERROR(MARPA_ERR_RHS_IX_NEGATIVE);
return failure_indicator;
}
if(Length_of_XRL(rule)<=ix){
MARPA_ERROR(MARPA_ERR_RHS_IX_OOB);
return failure_indicator;
}
return RHS_ID_of_RULE(rule,ix);
}

/*:272*//*273:*/
#line 2512 "./marpa.w"

int marpa_g_rule_length(Marpa_Grammar g,Marpa_Rule_ID xrl_id){
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 2514 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 2515 "./marpa.w"

/*1221:*/
#line 14661 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}

/*:1221*/
#line 2516 "./marpa.w"

/*1219:*/
#line 14649 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}

/*:1219*/
#line 2517 "./marpa.w"

return Length_of_XRL(XRL_by_ID(xrl_id));
}

/*:273*//*278:*/
#line 2544 "./marpa.w"

int marpa_g_rule_rank(Marpa_Grammar g,
Marpa_Rule_ID xrl_id)
{
XRL xrl;
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 2549 "./marpa.w"

clear_error(g);
/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 2551 "./marpa.w"

/*1221:*/
#line 14661 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}

/*:1221*/
#line 2552 "./marpa.w"

/*1220:*/
#line 14655 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return failure_indicator;
}
/*:1220*/
#line 2553 "./marpa.w"

clear_error(g);
xrl= XRL_by_ID(xrl_id);
return Rank_of_XRL(xrl);
}
/*:278*//*279:*/
#line 2558 "./marpa.w"

int marpa_g_rule_rank_set(
Marpa_Grammar g,Marpa_Rule_ID xrl_id,Marpa_Rank rank)
{
XRL xrl;
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 2563 "./marpa.w"

clear_error(g);
/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 2565 "./marpa.w"

/*1210:*/
#line 14594 "./marpa.w"

if(_MARPA_UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1210*/
#line 2566 "./marpa.w"

/*1221:*/
#line 14661 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}

/*:1221*/
#line 2567 "./marpa.w"

/*1220:*/
#line 14655 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return failure_indicator;
}
/*:1220*/
#line 2568 "./marpa.w"

xrl= XRL_by_ID(xrl_id);
if(_MARPA_UNLIKELY(rank<MINIMUM_RANK))
{
MARPA_ERROR(MARPA_ERR_RANK_TOO_LOW);
return failure_indicator;
}
if(_MARPA_UNLIKELY(rank> MAXIMUM_RANK))
{
MARPA_ERROR(MARPA_ERR_RANK_TOO_HIGH);
return failure_indicator;
}
return Rank_of_XRL(xrl)= rank;
}

/*:279*//*282:*/
#line 2594 "./marpa.w"

int marpa_g_rule_null_high(Marpa_Grammar g,
Marpa_Rule_ID xrl_id)
{
XRL xrl;
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 2599 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 2600 "./marpa.w"

/*1221:*/
#line 14661 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}

/*:1221*/
#line 2601 "./marpa.w"

/*1219:*/
#line 14649 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}

/*:1219*/
#line 2602 "./marpa.w"

xrl= XRL_by_ID(xrl_id);
return Null_Ranks_High_of_RULE(xrl);
}
/*:282*//*283:*/
#line 2606 "./marpa.w"

int marpa_g_rule_null_high_set(
Marpa_Grammar g,Marpa_Rule_ID xrl_id,int flag)
{
XRL xrl;
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 2611 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 2612 "./marpa.w"

/*1210:*/
#line 14594 "./marpa.w"

if(_MARPA_UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1210*/
#line 2613 "./marpa.w"

/*1221:*/
#line 14661 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}

/*:1221*/
#line 2614 "./marpa.w"

/*1219:*/
#line 14649 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}

/*:1219*/
#line 2615 "./marpa.w"

xrl= XRL_by_ID(xrl_id);
if(_MARPA_UNLIKELY(flag<0||flag> 1))
{
MARPA_ERROR(MARPA_ERR_INVALID_BOOLEAN);
return failure_indicator;
}
return Null_Ranks_High_of_RULE(xrl)= Boolean(flag);
}

/*:283*//*290:*/
#line 2652 "./marpa.w"

int marpa_g_sequence_min(
Marpa_Grammar g,
Marpa_Rule_ID xrl_id)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 2657 "./marpa.w"

XRL xrl;
/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 2659 "./marpa.w"

/*1221:*/
#line 14661 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}

/*:1221*/
#line 2660 "./marpa.w"

/*1220:*/
#line 14655 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return failure_indicator;
}
/*:1220*/
#line 2661 "./marpa.w"

xrl= XRL_by_ID(xrl_id);
if(!XRL_is_Sequence(xrl))
{
MARPA_ERROR(MARPA_ERR_NOT_A_SEQUENCE);
return-1;
}
return Minimum_of_XRL(xrl);
}

/*:290*//*293:*/
#line 2678 "./marpa.w"

Marpa_Symbol_ID marpa_g_sequence_separator(
Marpa_Grammar g,
Marpa_Rule_ID xrl_id)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 2683 "./marpa.w"

XRL xrl;
/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 2685 "./marpa.w"

/*1221:*/
#line 14661 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}

/*:1221*/
#line 2686 "./marpa.w"

/*1220:*/
#line 14655 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return failure_indicator;
}
/*:1220*/
#line 2687 "./marpa.w"

xrl= XRL_by_ID(xrl_id);
if(!XRL_is_Sequence(xrl))
{
MARPA_ERROR(MARPA_ERR_NOT_A_SEQUENCE);
return failure_indicator;
}
return Separator_of_XRL(xrl);
}

/*:293*//*298:*/
#line 2715 "./marpa.w"

int _marpa_g_rule_is_keep_separation(
Marpa_Grammar g,
Marpa_Rule_ID xrl_id)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 2720 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 2721 "./marpa.w"

/*1221:*/
#line 14661 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}

/*:1221*/
#line 2722 "./marpa.w"

/*1219:*/
#line 14649 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}

/*:1219*/
#line 2723 "./marpa.w"

return!XRL_by_ID(xrl_id)->t_is_discard;
}

/*:298*//*302:*/
#line 2755 "./marpa.w"

int marpa_g_rule_is_proper_separation(
Marpa_Grammar g,
Marpa_Rule_ID xrl_id)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 2760 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 2761 "./marpa.w"

/*1221:*/
#line 14661 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}

/*:1221*/
#line 2762 "./marpa.w"

/*1219:*/
#line 14649 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}

/*:1219*/
#line 2763 "./marpa.w"

return XRL_is_Proper_Separation(XRL_by_ID(xrl_id));
}

/*:302*//*306:*/
#line 2776 "./marpa.w"

int marpa_g_rule_is_loop(Marpa_Grammar g,Marpa_Rule_ID xrl_id)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 2779 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 2780 "./marpa.w"

/*1211:*/
#line 14600 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1211*/
#line 2781 "./marpa.w"

/*1221:*/
#line 14661 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}

/*:1221*/
#line 2782 "./marpa.w"

/*1219:*/
#line 14649 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}

/*:1219*/
#line 2783 "./marpa.w"

/*1211:*/
#line 14600 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1211*/
#line 2784 "./marpa.w"

return XRL_by_ID(xrl_id)->t_is_loop;
}

/*:306*//*309:*/
#line 2794 "./marpa.w"

int marpa_g_rule_is_nulling(Marpa_Grammar g,Marpa_Rule_ID xrl_id)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 2797 "./marpa.w"

XRL xrl;
/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 2799 "./marpa.w"

/*1211:*/
#line 14600 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1211*/
#line 2800 "./marpa.w"

/*1221:*/
#line 14661 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}

/*:1221*/
#line 2801 "./marpa.w"

/*1219:*/
#line 14649 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}

/*:1219*/
#line 2802 "./marpa.w"

xrl= XRL_by_ID(xrl_id);
return XRL_is_Nulling(xrl);
}

/*:309*//*312:*/
#line 2813 "./marpa.w"

int marpa_g_rule_is_nullable(Marpa_Grammar g,Marpa_Rule_ID xrl_id)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 2816 "./marpa.w"

XRL xrl;
/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 2818 "./marpa.w"

/*1211:*/
#line 14600 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1211*/
#line 2819 "./marpa.w"

/*1221:*/
#line 14661 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}

/*:1221*/
#line 2820 "./marpa.w"

/*1219:*/
#line 14649 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}

/*:1219*/
#line 2821 "./marpa.w"

xrl= XRL_by_ID(xrl_id);
return XRL_is_Nullable(xrl);
}

/*:312*//*316:*/
#line 2832 "./marpa.w"

int marpa_g_rule_is_accessible(Marpa_Grammar g,Marpa_Rule_ID xrl_id)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 2835 "./marpa.w"

XRL xrl;
/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 2837 "./marpa.w"

/*1211:*/
#line 14600 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1211*/
#line 2838 "./marpa.w"

/*1221:*/
#line 14661 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}

/*:1221*/
#line 2839 "./marpa.w"

/*1219:*/
#line 14649 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}

/*:1219*/
#line 2840 "./marpa.w"

xrl= XRL_by_ID(xrl_id);
return XRL_is_Accessible(xrl);
}

/*:316*//*319:*/
#line 2851 "./marpa.w"

int marpa_g_rule_is_productive(Marpa_Grammar g,Marpa_Rule_ID xrl_id)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 2854 "./marpa.w"

XRL xrl;
/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 2856 "./marpa.w"

/*1211:*/
#line 14600 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1211*/
#line 2857 "./marpa.w"

/*1221:*/
#line 14661 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}

/*:1221*/
#line 2858 "./marpa.w"

/*1219:*/
#line 14649 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}

/*:1219*/
#line 2859 "./marpa.w"

xrl= XRL_by_ID(xrl_id);
return XRL_is_Productive(xrl);
}

/*:319*//*322:*/
#line 2870 "./marpa.w"

int
_marpa_g_rule_is_used(Marpa_Grammar g,Marpa_Rule_ID xrl_id)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 2874 "./marpa.w"

/*1221:*/
#line 14661 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}

/*:1221*/
#line 2875 "./marpa.w"

/*1219:*/
#line 14649 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}

/*:1219*/
#line 2876 "./marpa.w"

return XRL_is_Used(XRL_by_ID(xrl_id));
}

/*:322*//*324:*/
#line 2883 "./marpa.w"

Marpa_Rule_ID
_marpa_g_irl_semantic_equivalent(Marpa_Grammar g,Marpa_IRL_ID irl_id)
{
IRL irl;
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 2888 "./marpa.w"

/*1218:*/
#line 14641 "./marpa.w"

if(_MARPA_UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1218*/
#line 2889 "./marpa.w"

irl= IRL_by_ID(irl_id);
if(IRL_has_Virtual_LHS(irl))return-1;
return ID_of_XRL(Source_XRL_of_IRL(irl));
}

/*:324*//*333:*/
#line 2930 "./marpa.w"

Marpa_NSY_ID _marpa_g_irl_lhs(Marpa_Grammar g,Marpa_IRL_ID irl_id){
IRL irl;
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 2933 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 2934 "./marpa.w"

/*1211:*/
#line 14600 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1211*/
#line 2935 "./marpa.w"

/*1218:*/
#line 14641 "./marpa.w"

if(_MARPA_UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1218*/
#line 2936 "./marpa.w"

irl= IRL_by_ID(irl_id);
return LHSID_of_IRL(irl);
}

/*:333*//*335:*/
#line 2943 "./marpa.w"

Marpa_NSY_ID _marpa_g_irl_rhs(Marpa_Grammar g,Marpa_IRL_ID irl_id,int ix){
IRL irl;
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 2946 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 2947 "./marpa.w"

/*1211:*/
#line 14600 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1211*/
#line 2948 "./marpa.w"

/*1218:*/
#line 14641 "./marpa.w"

if(_MARPA_UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1218*/
#line 2949 "./marpa.w"

irl= IRL_by_ID(irl_id);
if(Length_of_IRL(irl)<=ix)return-1;
return RHSID_of_IRL(irl,ix);
}

/*:335*//*337:*/
#line 2957 "./marpa.w"

int _marpa_g_irl_length(Marpa_Grammar g,Marpa_IRL_ID irl_id){
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 2959 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 2960 "./marpa.w"

/*1211:*/
#line 14600 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1211*/
#line 2961 "./marpa.w"

/*1218:*/
#line 14641 "./marpa.w"

if(_MARPA_UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1218*/
#line 2962 "./marpa.w"

return Length_of_IRL(IRL_by_ID(irl_id));
}

/*:337*//*343:*/
#line 3007 "./marpa.w"

int _marpa_g_irl_is_virtual_lhs(
Marpa_Grammar g,
Marpa_IRL_ID irl_id)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 3012 "./marpa.w"

/*1211:*/
#line 14600 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1211*/
#line 3013 "./marpa.w"

/*1218:*/
#line 14641 "./marpa.w"

if(_MARPA_UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1218*/
#line 3014 "./marpa.w"

return IRL_has_Virtual_LHS(IRL_by_ID(irl_id));
}

/*:343*//*346:*/
#line 3023 "./marpa.w"

int _marpa_g_irl_is_virtual_rhs(
Marpa_Grammar g,
Marpa_IRL_ID irl_id)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 3028 "./marpa.w"

/*1211:*/
#line 14600 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1211*/
#line 3029 "./marpa.w"

/*1218:*/
#line 14641 "./marpa.w"

if(_MARPA_UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1218*/
#line 3030 "./marpa.w"

return IRL_has_Virtual_RHS(IRL_by_ID(irl_id));
}

/*:346*//*352:*/
#line 3052 "./marpa.w"

int _marpa_g_real_symbol_count(
Marpa_Grammar g,
Marpa_IRL_ID irl_id)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 3057 "./marpa.w"

/*1211:*/
#line 14600 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1211*/
#line 3058 "./marpa.w"

/*1218:*/
#line 14641 "./marpa.w"

if(_MARPA_UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1218*/
#line 3059 "./marpa.w"

return Real_SYM_Count_of_IRL(IRL_by_ID(irl_id));
}

/*:352*//*355:*/
#line 3070 "./marpa.w"

int _marpa_g_virtual_start(
Marpa_Grammar g,
Marpa_IRL_ID irl_id)
{
IRL irl;
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 3076 "./marpa.w"

/*1211:*/
#line 14600 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1211*/
#line 3077 "./marpa.w"

/*1218:*/
#line 14641 "./marpa.w"

if(_MARPA_UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1218*/
#line 3078 "./marpa.w"

irl= IRL_by_ID(irl_id);
return Virtual_Start_of_IRL(irl);
}

/*:355*//*358:*/
#line 3090 "./marpa.w"

int _marpa_g_virtual_end(
Marpa_Grammar g,
Marpa_IRL_ID irl_id)
{
IRL irl;
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 3096 "./marpa.w"

/*1211:*/
#line 14600 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1211*/
#line 3097 "./marpa.w"

/*1218:*/
#line 14641 "./marpa.w"

if(_MARPA_UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1218*/
#line 3098 "./marpa.w"

irl= IRL_by_ID(irl_id);
return Virtual_End_of_IRL(irl);
}

/*:358*//*361:*/
#line 3112 "./marpa.w"

Marpa_Rule_ID _marpa_g_source_xrl(
Marpa_Grammar g,
Marpa_IRL_ID irl_id)
{
XRL source_xrl;
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 3118 "./marpa.w"

/*1218:*/
#line 14641 "./marpa.w"

if(_MARPA_UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1218*/
#line 3119 "./marpa.w"

source_xrl= Source_XRL_of_IRL(IRL_by_ID(irl_id));
return source_xrl?ID_of_XRL(source_xrl):-1;
}

/*:361*//*364:*/
#line 3140 "./marpa.w"

Marpa_Rank _marpa_g_irl_rank(
Marpa_Grammar g,
Marpa_IRL_ID irl_id)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 3145 "./marpa.w"

/*1218:*/
#line 14641 "./marpa.w"

if(_MARPA_UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1218*/
#line 3146 "./marpa.w"

return Rank_of_IRL(IRL_by_ID(irl_id));
}

/*:364*//*368:*/
#line 3180 "./marpa.w"

int marpa_g_precompute(Marpa_Grammar g)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 3183 "./marpa.w"

int return_value= failure_indicator;
struct marpa_obstack*obs_precompute= marpa_obs_init;
/*373:*/
#line 3307 "./marpa.w"

XRLID xrl_count= XRL_Count_of_G(g);
XSYID pre_census_xsy_count= XSY_Count_of_G(g);
XSYID post_census_xsy_count= -1;

/*:373*//*377:*/
#line 3341 "./marpa.w"

XSYID start_xsy_id= g->t_start_xsy_id;

/*:377*//*390:*/
#line 3644 "./marpa.w"

Bit_Matrix reach_matrix= NULL;

/*:390*/
#line 3186 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 3187 "./marpa.w"

G_EVENTS_CLEAR(g);
/*374:*/
#line 3312 "./marpa.w"

if(_MARPA_UNLIKELY(xrl_count<=0)){
MARPA_ERROR(MARPA_ERR_NO_RULES);
goto FAILURE;
}

/*:374*/
#line 3189 "./marpa.w"

/*1210:*/
#line 14594 "./marpa.w"

if(_MARPA_UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1210*/
#line 3190 "./marpa.w"

/*376:*/
#line 3322 "./marpa.w"

{
if(_MARPA_UNLIKELY(start_xsy_id<0))
{
MARPA_ERROR(MARPA_ERR_NO_START_SYMBOL);
goto FAILURE;
}
if(_MARPA_UNLIKELY(!xsy_id_is_valid(g,start_xsy_id)))
{
MARPA_ERROR(MARPA_ERR_INVALID_START_SYMBOL);
goto FAILURE;
}
if(_MARPA_UNLIKELY(!XSY_is_LHS(XSY_by_ID(start_xsy_id))))
{
MARPA_ERROR(MARPA_ERR_START_NOT_LHS);
goto FAILURE;
}
}

/*:376*/
#line 3191 "./marpa.w"





/*122:*/
#line 1122 "./marpa.w"

{
_marpa_avl_destroy((g)->t_xrl_tree);
(g)->t_xrl_tree= NULL;
}
/*:122*/
#line 3196 "./marpa.w"




{
/*382:*/
#line 3523 "./marpa.w"

Bit_Vector terminal_v= NULL;

/*:382*//*383:*/
#line 3526 "./marpa.w"

Bit_Vector lhs_v= NULL;
Bit_Vector empty_lhs_v= NULL;

/*:383*//*384:*/
#line 3531 "./marpa.w"

RULEID**xrl_list_x_rh_sym= NULL;
RULEID**xrl_list_x_lh_sym= NULL;

/*:384*//*388:*/
#line 3590 "./marpa.w"

Bit_Vector productive_v= NULL;
Bit_Vector nullable_v= NULL;

/*:388*/
#line 3201 "./marpa.w"

/*372:*/
#line 3292 "./marpa.w"

{
/*380:*/
#line 3365 "./marpa.w"

{
Marpa_Rule_ID rule_id;



const MARPA_AVL_TREE rhs_avl_tree= _marpa_avl_create(sym_rule_cmp,NULL);


struct sym_rule_pair*const p_rh_sym_rule_pair_base= 
marpa_obs_new(MARPA_AVL_OBSTACK(rhs_avl_tree),struct sym_rule_pair,
(size_t)External_Size_of_G(g));
struct sym_rule_pair*p_rh_sym_rule_pairs= p_rh_sym_rule_pair_base;



const MARPA_AVL_TREE lhs_avl_tree= _marpa_avl_create(sym_rule_cmp,NULL);
struct sym_rule_pair*const p_lh_sym_rule_pair_base= 
marpa_obs_new(MARPA_AVL_OBSTACK(lhs_avl_tree),struct sym_rule_pair,
(size_t)xrl_count);
struct sym_rule_pair*p_lh_sym_rule_pairs= p_lh_sym_rule_pair_base;

lhs_v= bv_obs_create(obs_precompute,pre_census_xsy_count);
empty_lhs_v= bv_obs_shadow(obs_precompute,lhs_v);
for(rule_id= 0;rule_id<xrl_count;rule_id++)
{
const XRL rule= XRL_by_ID(rule_id);
const Marpa_Symbol_ID lhs_id= LHS_ID_of_RULE(rule);
const int rule_length= Length_of_XRL(rule);
const int is_sequence= XRL_is_Sequence(rule);

bv_bit_set(lhs_v,lhs_id);



p_lh_sym_rule_pairs->t_symid= lhs_id;
p_lh_sym_rule_pairs->t_ruleid= rule_id;
_marpa_avl_insert(lhs_avl_tree,p_lh_sym_rule_pairs);
p_lh_sym_rule_pairs++;

if(is_sequence)
{
const XSYID separator_id= Separator_of_XRL(rule);
if(Minimum_of_XRL(rule)<=0)
{
bv_bit_set(empty_lhs_v,lhs_id);
}
if(separator_id>=0){
p_rh_sym_rule_pairs->t_symid= separator_id;
p_rh_sym_rule_pairs->t_ruleid= rule_id;
_marpa_avl_insert(rhs_avl_tree,p_rh_sym_rule_pairs);
p_rh_sym_rule_pairs++;
}
}

if(rule_length<=0)
{
bv_bit_set(empty_lhs_v,lhs_id);
}
else
{
int rhs_ix;
for(rhs_ix= 0;rhs_ix<rule_length;rhs_ix++)
{
p_rh_sym_rule_pairs->t_symid= RHS_ID_of_RULE(rule,rhs_ix);
p_rh_sym_rule_pairs->t_ruleid= rule_id;
_marpa_avl_insert(rhs_avl_tree,p_rh_sym_rule_pairs);
p_rh_sym_rule_pairs++;
}
}
}
{
MARPA_AVL_TRAV traverser;
struct sym_rule_pair*pair;
XSYID seen_symid= -1;
RULEID*const rule_data_base= 
marpa_obs_new(obs_precompute,RULEID,(size_t)External_Size_of_G(g));
RULEID*p_rule_data= rule_data_base;
traverser= _marpa_avl_t_init(rhs_avl_tree);



xrl_list_x_rh_sym= 
marpa_obs_new(obs_precompute,RULEID*,(size_t)pre_census_xsy_count+1);
for(pair= _marpa_avl_t_first(traverser);pair;
pair= (struct sym_rule_pair*)_marpa_avl_t_next(traverser))
{
const XSYID current_symid= pair->t_symid;
while(seen_symid<current_symid)
xrl_list_x_rh_sym[++seen_symid]= p_rule_data;
*p_rule_data++= pair->t_ruleid;
}
while(++seen_symid<=pre_census_xsy_count)
xrl_list_x_rh_sym[seen_symid]= p_rule_data;
_marpa_avl_destroy(rhs_avl_tree);
}

{
MARPA_AVL_TRAV traverser;
struct sym_rule_pair*pair;
XSYID seen_symid= -1;
RULEID*const rule_data_base= 
marpa_obs_new(obs_precompute,RULEID,(size_t)xrl_count);
RULEID*p_rule_data= rule_data_base;
traverser= _marpa_avl_t_init(lhs_avl_tree);


xrl_list_x_lh_sym= 
marpa_obs_new(obs_precompute,RULEID*,(size_t)pre_census_xsy_count+1);
for(pair= _marpa_avl_t_first(traverser);pair;
pair= (struct sym_rule_pair*)_marpa_avl_t_next(traverser))
{
const XSYID current_symid= pair->t_symid;
while(seen_symid<current_symid)
xrl_list_x_lh_sym[++seen_symid]= p_rule_data;
*p_rule_data++= pair->t_ruleid;
}
while(++seen_symid<=pre_census_xsy_count)
xrl_list_x_lh_sym[seen_symid]= p_rule_data;
_marpa_avl_destroy(lhs_avl_tree);
}

}

/*:380*/
#line 3294 "./marpa.w"

/*381:*/
#line 3492 "./marpa.w"

{
XSYID symid;
terminal_v= bv_obs_create(obs_precompute,pre_census_xsy_count);
bv_not(terminal_v,lhs_v);
for(symid= 0;symid<pre_census_xsy_count;symid++)
{
XSY symbol= XSY_by_ID(symid);



if(XSY_is_Locked_Terminal(symbol))
{
if(XSY_is_Terminal(symbol))
{
bv_bit_set(terminal_v,symid);
continue;
}
bv_bit_clear(terminal_v,symid);
continue;
}




if(bv_bit_test(terminal_v,symid))
XSY_is_Terminal(symbol)= 1;
}
}

/*:381*/
#line 3295 "./marpa.w"

/*389:*/
#line 3612 "./marpa.w"

{
XRLID rule_id;
reach_matrix= 
matrix_obs_create(obs_precompute,pre_census_xsy_count,
pre_census_xsy_count);
for(rule_id= 0;rule_id<xrl_count;rule_id++)
{
XRL rule= XRL_by_ID(rule_id);
XSYID lhs_id= LHS_ID_of_RULE(rule);
int rhs_ix;
int rule_length= Length_of_XRL(rule);
for(rhs_ix= 0;rhs_ix<rule_length;rhs_ix++)
{
matrix_bit_set(reach_matrix,
lhs_id,
RHS_ID_of_RULE(rule,rhs_ix));
}
if(XRL_is_Sequence(rule))
{
const XSYID separator_id= Separator_of_XRL(rule);
if(separator_id>=0)
{
matrix_bit_set(reach_matrix,
lhs_id,
separator_id);
}
}
}
transitive_closure(reach_matrix);
}

/*:389*/
#line 3296 "./marpa.w"

/*385:*/
#line 3535 "./marpa.w"

{
int min,max,start;
XSYID xsy_id;
int counted_nullables= 0;
nullable_v= bv_obs_clone(obs_precompute,empty_lhs_v);
rhs_closure(g,nullable_v,xrl_list_x_rh_sym);
for(start= 0;bv_scan(nullable_v,start,&min,&max);start= max+2)
{
for(xsy_id= min;xsy_id<=max;
xsy_id++)
{
XSY xsy= XSY_by_ID(xsy_id);
XSY_is_Nullable(xsy)= 1;
if(_MARPA_UNLIKELY(xsy->t_is_counted))
{
counted_nullables++;
int_event_new(g,MARPA_EVENT_COUNTED_NULLABLE,xsy_id);
}
}
}
if(_MARPA_UNLIKELY(counted_nullables))
{
MARPA_ERROR(MARPA_ERR_COUNTED_NULLABLE);
goto FAILURE;
}
}

/*:385*/
#line 3297 "./marpa.w"

/*386:*/
#line 3563 "./marpa.w"

{
productive_v= bv_obs_shadow(obs_precompute,nullable_v);
bv_or(productive_v,nullable_v,terminal_v);
rhs_closure(g,productive_v,xrl_list_x_rh_sym);
{
int min,max,start;
XSYID symid;
for(start= 0;bv_scan(productive_v,start,&min,&max);
start= max+2)
{
for(symid= min;
symid<=max;symid++)
{
XSY symbol= XSY_by_ID(symid);
symbol->t_is_productive= 1;
}
}
}
}

/*:386*/
#line 3298 "./marpa.w"

/*387:*/
#line 3584 "./marpa.w"

if(_MARPA_UNLIKELY(!bv_bit_test(productive_v,start_xsy_id)))
{
MARPA_ERROR(MARPA_ERR_UNPRODUCTIVE_START);
goto FAILURE;
}
/*:387*/
#line 3299 "./marpa.w"

/*391:*/
#line 3649 "./marpa.w"

{
Bit_Vector accessible_v= 
matrix_row(reach_matrix,start_xsy_id);
int min,max,start;
XSYID symid;
for(start= 0;bv_scan(accessible_v,start,&min,&max);start= max+2)
{
for(symid= min;
symid<=max;symid++)
{
XSY symbol= XSY_by_ID(symid);
symbol->t_is_accessible= 1;
}
}
XSY_by_ID(start_xsy_id)->t_is_accessible= 1;
}

/*:391*/
#line 3300 "./marpa.w"

/*392:*/
#line 3669 "./marpa.w"

{
Bit_Vector reaches_terminal_v= bv_shadow(terminal_v);
int nulling_terminal_found= 0;
int min,max,start;
for(start= 0;bv_scan(lhs_v,start,&min,&max);start= max+2)
{
XSYID productive_id;
for(productive_id= min;
productive_id<=max;productive_id++)
{
bv_and(reaches_terminal_v,terminal_v,
matrix_row(reach_matrix,productive_id));
if(bv_is_empty(reaches_terminal_v))
{
const XSY symbol= XSY_by_ID(productive_id);
XSY_is_Nulling(symbol)= 1;
if(_MARPA_UNLIKELY(XSY_is_Terminal(symbol)))
{
nulling_terminal_found= 1;
int_event_new(g,MARPA_EVENT_NULLING_TERMINAL,
productive_id);
}
}
}
}
bv_free(reaches_terminal_v);
if(_MARPA_UNLIKELY(nulling_terminal_found))
{
MARPA_ERROR(MARPA_ERR_NULLING_TERMINAL);
goto FAILURE;
}
}

/*:392*/
#line 3301 "./marpa.w"

/*393:*/
#line 3708 "./marpa.w"

{
XRLID xrl_id;
for(xrl_id= 0;xrl_id<xrl_count;xrl_id++)
{
const XRL xrl= XRL_by_ID(xrl_id);
const XSYID lhs_id= LHS_ID_of_XRL(xrl);
const XSY lhs= XSY_by_ID(lhs_id);
XRL_is_Accessible(xrl)= XSY_is_Accessible(lhs);
if(XRL_is_Sequence(xrl))
{
/*395:*/
#line 3759 "./marpa.w"

{
const XSYID rhs_id= RHS_ID_of_XRL(xrl,0);
const XSY rh_xsy= XSY_by_ID(rhs_id);
const XSYID separator_id= Separator_of_XRL(xrl);




XRL_is_Nullable(xrl)= Minimum_of_XRL(xrl)<=0
||XSY_is_Nullable(rh_xsy);



XRL_is_Nulling(xrl)= XSY_is_Nulling(rh_xsy);




XRL_is_Productive(xrl)= XRL_is_Nullable(xrl)||XSY_is_Productive(rh_xsy);



XRL_is_Used(xrl)= XRL_is_Accessible(xrl)&&XSY_is_Productive(rh_xsy);



if(separator_id>=0)
{
const XSY separator_xsy= XSY_by_ID(separator_id);



if(!XSY_is_Nulling(separator_xsy))
{
XRL_is_Nulling(xrl)= 0;
}




if(_MARPA_UNLIKELY(!XSY_is_Productive(separator_xsy)))
{
XRL_is_Productive(xrl)= XRL_is_Nullable(xrl);



XRL_is_Used(xrl)= 0;
}
}



if(XRL_is_Nulling(xrl))XRL_is_Used(xrl)= 0;
}

/*:395*/
#line 3719 "./marpa.w"

continue;
}
/*394:*/
#line 3728 "./marpa.w"

{
int rh_ix;
int is_nulling= 1;
int is_nullable= 1;
int is_productive= 1;
for(rh_ix= 0;rh_ix<Length_of_XRL(xrl);rh_ix++)
{
const XSYID rhs_id= RHS_ID_of_XRL(xrl,rh_ix);
const XSY rh_xsy= XSY_by_ID(rhs_id);
if(_MARPA_LIKELY(!XSY_is_Nulling(rh_xsy)))
is_nulling= 0;
if(_MARPA_LIKELY(!XSY_is_Nullable(rh_xsy)))
is_nullable= 0;
if(_MARPA_UNLIKELY(!XSY_is_Productive(rh_xsy)))
is_productive= 0;
}
XRL_is_Nulling(xrl)= Boolean(is_nulling);
XRL_is_Nullable(xrl)= Boolean(is_nullable);
XRL_is_Productive(xrl)= Boolean(is_productive);
XRL_is_Used(xrl)= XRL_is_Accessible(xrl)&&XRL_is_Productive(xrl)
&&!XRL_is_Nulling(xrl);
}

/*:394*/
#line 3722 "./marpa.w"

}
}

/*:393*/
#line 3302 "./marpa.w"

/*396:*/
#line 3824 "./marpa.w"

if(0)
{




XSYID xsy_id;
for(xsy_id= 0;xsy_id<pre_census_xsy_count;xsy_id++)
{
if(bv_bit_test(terminal_v,xsy_id)&&bv_bit_test(lhs_v,xsy_id))
{
const XSY xsy= XSY_by_ID(xsy_id);
if(XSY_is_Valued_Locked(xsy))
continue;
XSY_is_Valued(xsy)= 1;
XSY_is_Valued_Locked(xsy)= 1;
}
}
}

/*:396*/
#line 3303 "./marpa.w"

/*397:*/
#line 3853 "./marpa.w"

{
XSYID xsyid;
XRLID xrlid;


int nullable_xsy_count= 0;




void*matrix_buffer= my_malloc(matrix_sizeof(
pre_census_xsy_count,
pre_census_xsy_count));
Bit_Matrix nullification_matrix= 
matrix_buffer_create(matrix_buffer,pre_census_xsy_count,
pre_census_xsy_count);

for(xsyid= 0;xsyid<pre_census_xsy_count;xsyid++)
{
if(!XSYID_is_Nullable(xsyid))
continue;
nullable_xsy_count++;
matrix_bit_set(nullification_matrix,xsyid,
xsyid);
}
for(xrlid= 0;xrlid<xrl_count;xrlid++)
{
int rh_ix;
XRL xrl= XRL_by_ID(xrlid);
const XSYID lhs_id= LHS_ID_of_XRL(xrl);
if(XRL_is_Nullable(xrl))
{
for(rh_ix= 0;rh_ix<Length_of_XRL(xrl);rh_ix++)
{
const XSYID rhs_id= RHS_ID_of_XRL(xrl,rh_ix);
matrix_bit_set(nullification_matrix,lhs_id,
rhs_id);
}
}
}
transitive_closure(nullification_matrix);
for(xsyid= 0;xsyid<pre_census_xsy_count;xsyid++)
{
Bit_Vector bv_nullifications_by_to_xsy= 
matrix_row(nullification_matrix,xsyid);
Nulled_XSYIDs_of_XSYID(xsyid)= 
cil_bv_add(&g->t_cilar,bv_nullifications_by_to_xsy);
}
my_free(matrix_buffer);
}

/*:397*/
#line 3304 "./marpa.w"

}

/*:372*/
#line 3202 "./marpa.w"

/*448:*/
#line 4728 "./marpa.w"

{
int loop_rule_count= 0;
Bit_Matrix unit_transition_matrix= 
matrix_obs_create(obs_precompute,xrl_count,
xrl_count);
/*449:*/
#line 4749 "./marpa.w"

{
Marpa_Rule_ID rule_id;
for(rule_id= 0;rule_id<xrl_count;rule_id++)
{
XRL rule= XRL_by_ID(rule_id);
XSYID nonnullable_id= -1;
int nonnullable_count= 0;
int rhs_ix,rule_length;
rule_length= Length_of_XRL(rule);



for(rhs_ix= 0;rhs_ix<rule_length;rhs_ix++)
{
XSYID xsy_id= RHS_ID_of_RULE(rule,rhs_ix);
if(bv_bit_test(nullable_v,xsy_id))
continue;
nonnullable_id= xsy_id;
nonnullable_count++;
}

if(nonnullable_count==1)
{



/*450:*/
#line 4804 "./marpa.w"

{
RULEID*p_xrl= xrl_list_x_lh_sym[nonnullable_id];
const RULEID*p_one_past_rules= xrl_list_x_lh_sym[nonnullable_id+1];
for(;p_xrl<p_one_past_rules;p_xrl++)
{


const RULEID to_rule_id= *p_xrl;
matrix_bit_set(unit_transition_matrix,rule_id,
to_rule_id);
}
}

/*:450*/
#line 4777 "./marpa.w"

}
else if(nonnullable_count==0)
{
for(rhs_ix= 0;rhs_ix<rule_length;rhs_ix++)
{




nonnullable_id= RHS_ID_of_RULE(rule,rhs_ix);

if(XSY_is_Nulling(XSY_by_ID(nonnullable_id)))
continue;



/*450:*/
#line 4804 "./marpa.w"

{
RULEID*p_xrl= xrl_list_x_lh_sym[nonnullable_id];
const RULEID*p_one_past_rules= xrl_list_x_lh_sym[nonnullable_id+1];
for(;p_xrl<p_one_past_rules;p_xrl++)
{


const RULEID to_rule_id= *p_xrl;
matrix_bit_set(unit_transition_matrix,rule_id,
to_rule_id);
}
}

/*:450*/
#line 4795 "./marpa.w"

}
}
}
}

/*:449*/
#line 4734 "./marpa.w"

transitive_closure(unit_transition_matrix);
/*451:*/
#line 4818 "./marpa.w"

{
XRLID rule_id;
for(rule_id= 0;rule_id<xrl_count;rule_id++)
{
XRL rule;
if(!matrix_bit_test
(unit_transition_matrix,rule_id,
rule_id))
continue;
loop_rule_count++;
rule= XRL_by_ID(rule_id);
rule->t_is_loop= 1;
}
}

/*:451*/
#line 4736 "./marpa.w"

if(loop_rule_count)
{
g->t_has_cycle= 1;
int_event_new(g,MARPA_EVENT_LOOP_RULES,loop_rule_count);
}
}

/*:448*/
#line 3203 "./marpa.w"

}



/*512:*/
#line 5381 "./marpa.w"

MARPA_DSTACK_INIT(g->t_irl_stack,IRL,2*MARPA_DSTACK_CAPACITY(g->t_xrl_stack));

/*:512*/
#line 3208 "./marpa.w"

/*513:*/
#line 5389 "./marpa.w"

{
MARPA_DSTACK_INIT(g->t_nsy_stack,NSY,2*MARPA_DSTACK_CAPACITY(g->t_xsy_stack));
}

/*:513*/
#line 3209 "./marpa.w"

/*413:*/
#line 4075 "./marpa.w"

{
/*414:*/
#line 4106 "./marpa.w"

Marpa_Rule_ID rule_id;
int pre_chaf_rule_count;

/*:414*//*417:*/
#line 4164 "./marpa.w"

int factor_count;
int*factor_positions;
/*:417*/
#line 4077 "./marpa.w"

/*418:*/
#line 4167 "./marpa.w"

factor_positions= marpa_obs_new(obs_precompute,int,g->t_max_rule_length);

/*:418*/
#line 4078 "./marpa.w"

/*415:*/
#line 4112 "./marpa.w"

{
XSYID xsy_id;
for(xsy_id= 0;xsy_id<pre_census_xsy_count;xsy_id++)
{
const XSY xsy_to_clone= XSY_by_ID(xsy_id);
if(_MARPA_UNLIKELY(!xsy_to_clone->t_is_accessible))
continue;
if(_MARPA_UNLIKELY(!xsy_to_clone->t_is_productive))
continue;
NSY_of_XSY(xsy_to_clone)= nsy_clone(g,xsy_to_clone);
if(XSY_is_Nulling(xsy_to_clone))
{
Nulling_NSY_of_XSY(xsy_to_clone)= NSY_of_XSY(xsy_to_clone);
continue;
}
if(XSY_is_Nullable(xsy_to_clone))
{
Nulling_NSY_of_XSY(xsy_to_clone)= symbol_alias_create(g,xsy_to_clone);
}
}
}

/*:415*/
#line 4079 "./marpa.w"

pre_chaf_rule_count= XRL_Count_of_G(g);
for(rule_id= 0;rule_id<pre_chaf_rule_count;rule_id++)
{

XRL rule= XRL_by_ID(rule_id);
XRL rewrite_xrl= rule;
const int rewrite_xrl_length= Length_of_XRL(rewrite_xrl);
int nullable_suffix_ix= 0;
if(!XRL_is_Used(rule))
continue;
if(XRL_is_Sequence(rule))
{
/*398:*/
#line 3906 "./marpa.w"

{
const XSYID lhs_id= LHS_ID_of_RULE(rule);
const NSY lhs_nsy= NSY_by_XSYID(lhs_id);
const NSYID lhs_nsyid= ID_of_NSY(lhs_nsy);

const NSY internal_lhs_nsy= nsy_new(g,XSY_by_ID(lhs_id));
const NSYID internal_lhs_nsyid= ID_of_NSY(internal_lhs_nsy);

const XSYID rhs_id= RHS_ID_of_RULE(rule,0);
const NSY rhs_nsy= NSY_by_XSYID(rhs_id);
const NSYID rhs_nsyid= ID_of_NSY(rhs_nsy);

const XSYID separator_id= Separator_of_XRL(rule);
NSYID separator_nsyid= -1;
if(separator_id>=0){
const NSY separator_nsy= NSY_by_XSYID(separator_id);
separator_nsyid= ID_of_NSY(separator_nsy);
}

LHS_XRL_of_NSY(internal_lhs_nsy)= rule;
/*399:*/
#line 3935 "./marpa.w"

{
IRL rewrite_irl= irl_start(g,1);
LHSID_of_IRL(rewrite_irl)= lhs_nsyid;
RHSID_of_IRL(rewrite_irl,0)= internal_lhs_nsyid;
irl_finish(g,rewrite_irl);
Source_XRL_of_IRL(rewrite_irl)= rule;
Rank_of_IRL(rewrite_irl)= IRL_Rank_by_XRL(rule);

IRL_has_Virtual_RHS(rewrite_irl)= 1;
}

/*:399*/
#line 3927 "./marpa.w"

if(separator_nsyid>=0&&!XRL_is_Proper_Separation(rule)){
/*400:*/
#line 3948 "./marpa.w"

{
IRL rewrite_irl;
rewrite_irl= irl_start(g,2);
LHSID_of_IRL(rewrite_irl)= lhs_nsyid;
RHSID_of_IRL(rewrite_irl,0)= internal_lhs_nsyid;
RHSID_of_IRL(rewrite_irl,1)= separator_nsyid;
irl_finish(g,rewrite_irl);
Source_XRL_of_IRL(rewrite_irl)= rule;
Rank_of_IRL(rewrite_irl)= IRL_Rank_by_XRL(rule);
IRL_has_Virtual_RHS(rewrite_irl)= 1;
Real_SYM_Count_of_IRL(rewrite_irl)= 1;
}

/*:400*/
#line 3929 "./marpa.w"

}
/*401:*/
#line 3965 "./marpa.w"

{
const IRL rewrite_irl= irl_start(g,1);
LHSID_of_IRL(rewrite_irl)= internal_lhs_nsyid;
RHSID_of_IRL(rewrite_irl,0)= rhs_nsyid;
irl_finish(g,rewrite_irl);
Source_XRL_of_IRL(rewrite_irl)= rule;
Rank_of_IRL(rewrite_irl)= IRL_Rank_by_XRL(rule);
IRL_has_Virtual_LHS(rewrite_irl)= 1;
Real_SYM_Count_of_IRL(rewrite_irl)= 1;
}
/*:401*/
#line 3931 "./marpa.w"

/*402:*/
#line 3976 "./marpa.w"

{
IRL rewrite_irl;
int rhs_ix= 0;
const int length= separator_nsyid>=0?3:2;
rewrite_irl= irl_start(g,length);
LHSID_of_IRL(rewrite_irl)= internal_lhs_nsyid;
RHSID_of_IRL(rewrite_irl,rhs_ix++)= internal_lhs_nsyid;
if(separator_nsyid>=0)
RHSID_of_IRL(rewrite_irl,rhs_ix++)= separator_nsyid;
RHSID_of_IRL(rewrite_irl,rhs_ix)= rhs_nsyid;
irl_finish(g,rewrite_irl);
Source_XRL_of_IRL(rewrite_irl)= rule;
Rank_of_IRL(rewrite_irl)= IRL_Rank_by_XRL(rule);
IRL_has_Virtual_LHS(rewrite_irl)= 1;
IRL_has_Virtual_RHS(rewrite_irl)= 1;
Real_SYM_Count_of_IRL(rewrite_irl)= length-1;
}

/*:402*/
#line 3932 "./marpa.w"

}

/*:398*/
#line 4092 "./marpa.w"

continue;
}
/*416:*/
#line 4143 "./marpa.w"

{
int rhs_ix;
factor_count= 0;
for(rhs_ix= 0;rhs_ix<rewrite_xrl_length;rhs_ix++)
{
Marpa_Symbol_ID symid= RHS_ID_of_RULE(rule,rhs_ix);
XSY symbol= XSY_by_ID(symid);
if(XSY_is_Nulling(symbol))
continue;
if(XSY_is_Nullable(symbol))
{

factor_positions[factor_count++]= rhs_ix;
continue;
}
nullable_suffix_ix= rhs_ix+1;


}
}
/*:416*/
#line 4095 "./marpa.w"


if(factor_count> 0)
{
/*419:*/
#line 4171 "./marpa.w"

{
const XRL chaf_xrl= rule;


int unprocessed_factor_count;

int factor_position_ix= 0;
NSY current_lhs_nsy= NSY_by_XSYID(LHS_ID_of_RULE(rule));
NSYID current_lhs_nsyid= ID_of_NSY(current_lhs_nsy);


int piece_end,piece_start= 0;

for(unprocessed_factor_count= factor_count-factor_position_ix;
unprocessed_factor_count>=3;
unprocessed_factor_count= factor_count-factor_position_ix){
/*422:*/
#line 4207 "./marpa.w"

NSY chaf_virtual_nsy;
NSYID chaf_virtual_nsyid;
int first_factor_position= factor_positions[factor_position_ix];
int second_factor_position= factor_positions[factor_position_ix+1];
if(second_factor_position>=nullable_suffix_ix){
piece_end= second_factor_position-1;



/*420:*/
#line 4197 "./marpa.w"

{
const XSYID chaf_xrl_lhs_id= LHS_ID_of_XRL(chaf_xrl);
chaf_virtual_nsy= nsy_new(g,XSY_by_ID(chaf_xrl_lhs_id));
chaf_virtual_nsyid= ID_of_NSY(chaf_virtual_nsy);
}

/*:420*/
#line 4217 "./marpa.w"

/*423:*/
#line 4236 "./marpa.w"

{
{
const int real_symbol_count= piece_end-piece_start+1;
/*428:*/
#line 4334 "./marpa.w"

{
int piece_ix;
const int chaf_irl_length= (piece_end-piece_start)+2;
IRL chaf_irl= irl_start(g,chaf_irl_length);
LHSID_of_IRL(chaf_irl)= current_lhs_nsyid;
for(piece_ix= 0;piece_ix<chaf_irl_length-1;piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
NSYID_by_XSYID(RHS_ID_of_RULE(rule,piece_start+piece_ix));
}
RHSID_of_IRL(chaf_irl,chaf_irl_length-1)= chaf_virtual_nsyid;
irl_finish(g,chaf_irl);
Rank_of_IRL(chaf_irl)= IRL_CHAF_Rank_by_XRL(rule,3);
/*440:*/
#line 4637 "./marpa.w"

{
const int is_virtual_lhs= (piece_start> 0);
IRL_is_CHAF(chaf_irl)= 1;
Source_XRL_of_IRL(chaf_irl)= rule;
IRL_has_Virtual_LHS(chaf_irl)= Boolean(is_virtual_lhs);
IRL_has_Virtual_RHS(chaf_irl)= 
Length_of_IRL(chaf_irl)> real_symbol_count;
Virtual_Start_of_IRL(chaf_irl)= piece_start;
Virtual_End_of_IRL(chaf_irl)= piece_start+real_symbol_count-1;
Real_SYM_Count_of_IRL(chaf_irl)= real_symbol_count;
LHS_XRL_of_NSY(current_lhs_nsy)= chaf_xrl;
XRL_Offset_of_NSY(current_lhs_nsy)= piece_start;
}

/*:440*/
#line 4348 "./marpa.w"

}

/*:428*/
#line 4240 "./marpa.w"
;
}
/*424:*/
#line 4250 "./marpa.w"

{
int piece_ix;
const int second_nulling_piece_ix= second_factor_position-piece_start;
const int chaf_irl_length= rewrite_xrl_length-piece_start;
const int real_symbol_count= chaf_irl_length;

IRL chaf_irl= irl_start(g,chaf_irl_length);
LHSID_of_IRL(chaf_irl)= current_lhs_nsyid;
for(piece_ix= 0;piece_ix<second_nulling_piece_ix;piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
NSYID_by_XSYID(RHS_ID_of_RULE(rule,piece_start+piece_ix));
}
for(piece_ix= second_nulling_piece_ix;piece_ix<chaf_irl_length;
piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
Nulling_NSYID_by_XSYID(RHS_ID_of_RULE(rule,piece_start+piece_ix));
}
irl_finish(g,chaf_irl);
Rank_of_IRL(chaf_irl)= IRL_CHAF_Rank_by_XRL(rule,2);
/*440:*/
#line 4637 "./marpa.w"

{
const int is_virtual_lhs= (piece_start> 0);
IRL_is_CHAF(chaf_irl)= 1;
Source_XRL_of_IRL(chaf_irl)= rule;
IRL_has_Virtual_LHS(chaf_irl)= Boolean(is_virtual_lhs);
IRL_has_Virtual_RHS(chaf_irl)= 
Length_of_IRL(chaf_irl)> real_symbol_count;
Virtual_Start_of_IRL(chaf_irl)= piece_start;
Virtual_End_of_IRL(chaf_irl)= piece_start+real_symbol_count-1;
Real_SYM_Count_of_IRL(chaf_irl)= real_symbol_count;
LHS_XRL_of_NSY(current_lhs_nsy)= chaf_xrl;
XRL_Offset_of_NSY(current_lhs_nsy)= piece_start;
}

/*:440*/
#line 4272 "./marpa.w"

}

/*:424*/
#line 4242 "./marpa.w"
;
{
const int real_symbol_count= piece_end-piece_start+1;
/*430:*/
#line 4380 "./marpa.w"

{
int piece_ix;
const int first_nulling_piece_ix= first_factor_position-piece_start;
const int chaf_irl_length= (piece_end-piece_start)+2;
IRL chaf_irl= irl_start(g,chaf_irl_length);
LHSID_of_IRL(chaf_irl)= current_lhs_nsyid;
for(piece_ix= 0;piece_ix<first_nulling_piece_ix;piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
NSYID_by_XSYID(RHS_ID_of_RULE(rule,piece_start+piece_ix));
}
RHSID_of_IRL(chaf_irl,first_nulling_piece_ix)= 
Nulling_NSYID_by_XSYID(RHS_ID_of_RULE
(rule,piece_start+first_nulling_piece_ix));
for(piece_ix= first_nulling_piece_ix+1;
piece_ix<chaf_irl_length-1;piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
NSYID_by_XSYID(RHS_ID_of_RULE(rule,piece_start+piece_ix));
}
RHSID_of_IRL(chaf_irl,chaf_irl_length-1)= chaf_virtual_nsyid;
irl_finish(g,chaf_irl);
Rank_of_IRL(chaf_irl)= IRL_CHAF_Rank_by_XRL(rule,1);
/*440:*/
#line 4637 "./marpa.w"

{
const int is_virtual_lhs= (piece_start> 0);
IRL_is_CHAF(chaf_irl)= 1;
Source_XRL_of_IRL(chaf_irl)= rule;
IRL_has_Virtual_LHS(chaf_irl)= Boolean(is_virtual_lhs);
IRL_has_Virtual_RHS(chaf_irl)= 
Length_of_IRL(chaf_irl)> real_symbol_count;
Virtual_Start_of_IRL(chaf_irl)= piece_start;
Virtual_End_of_IRL(chaf_irl)= piece_start+real_symbol_count-1;
Real_SYM_Count_of_IRL(chaf_irl)= real_symbol_count;
LHS_XRL_of_NSY(current_lhs_nsy)= chaf_xrl;
XRL_Offset_of_NSY(current_lhs_nsy)= piece_start;
}

/*:440*/
#line 4404 "./marpa.w"

}

/*:430*/
#line 4245 "./marpa.w"
;
}
/*425:*/
#line 4280 "./marpa.w"

{
if(piece_start<nullable_suffix_ix)
{
int piece_ix;
const int first_nulling_piece_ix= first_factor_position-piece_start;
const int second_nulling_piece_ix= 
second_factor_position-piece_start;
const int chaf_irl_length= rewrite_xrl_length-piece_start;
const int real_symbol_count= chaf_irl_length;

IRL chaf_irl= irl_start(g,chaf_irl_length);
LHSID_of_IRL(chaf_irl)= current_lhs_nsyid;
for(piece_ix= 0;piece_ix<first_nulling_piece_ix;piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
NSYID_by_XSYID(RHS_ID_of_RULE
(rule,piece_start+piece_ix));
}
RHSID_of_IRL(chaf_irl,first_nulling_piece_ix)= 
Nulling_NSYID_by_XSYID(RHS_ID_of_RULE
(rule,piece_start+first_nulling_piece_ix));
for(piece_ix= first_nulling_piece_ix+1;
piece_ix<second_nulling_piece_ix;piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
NSYID_by_XSYID(RHS_ID_of_RULE
(rule,piece_start+piece_ix));
}
for(piece_ix= second_nulling_piece_ix;piece_ix<chaf_irl_length;
piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
Nulling_NSYID_by_XSYID(RHS_ID_of_RULE
(rule,piece_start+piece_ix));
}
irl_finish(g,chaf_irl);
Rank_of_IRL(chaf_irl)= IRL_CHAF_Rank_by_XRL(rule,0);
/*440:*/
#line 4637 "./marpa.w"

{
const int is_virtual_lhs= (piece_start> 0);
IRL_is_CHAF(chaf_irl)= 1;
Source_XRL_of_IRL(chaf_irl)= rule;
IRL_has_Virtual_LHS(chaf_irl)= Boolean(is_virtual_lhs);
IRL_has_Virtual_RHS(chaf_irl)= 
Length_of_IRL(chaf_irl)> real_symbol_count;
Virtual_Start_of_IRL(chaf_irl)= piece_start;
Virtual_End_of_IRL(chaf_irl)= piece_start+real_symbol_count-1;
Real_SYM_Count_of_IRL(chaf_irl)= real_symbol_count;
LHS_XRL_of_NSY(current_lhs_nsy)= chaf_xrl;
XRL_Offset_of_NSY(current_lhs_nsy)= piece_start;
}

/*:440*/
#line 4318 "./marpa.w"

}
}

/*:425*/
#line 4247 "./marpa.w"
;
}

/*:423*/
#line 4218 "./marpa.w"

factor_position_ix++;
}else{
piece_end= second_factor_position;
/*420:*/
#line 4197 "./marpa.w"

{
const XSYID chaf_xrl_lhs_id= LHS_ID_of_XRL(chaf_xrl);
chaf_virtual_nsy= nsy_new(g,XSY_by_ID(chaf_xrl_lhs_id));
chaf_virtual_nsyid= ID_of_NSY(chaf_virtual_nsy);
}

/*:420*/
#line 4222 "./marpa.w"

/*427:*/
#line 4324 "./marpa.w"

{
const int real_symbol_count= piece_end-piece_start+1;
/*428:*/
#line 4334 "./marpa.w"

{
int piece_ix;
const int chaf_irl_length= (piece_end-piece_start)+2;
IRL chaf_irl= irl_start(g,chaf_irl_length);
LHSID_of_IRL(chaf_irl)= current_lhs_nsyid;
for(piece_ix= 0;piece_ix<chaf_irl_length-1;piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
NSYID_by_XSYID(RHS_ID_of_RULE(rule,piece_start+piece_ix));
}
RHSID_of_IRL(chaf_irl,chaf_irl_length-1)= chaf_virtual_nsyid;
irl_finish(g,chaf_irl);
Rank_of_IRL(chaf_irl)= IRL_CHAF_Rank_by_XRL(rule,3);
/*440:*/
#line 4637 "./marpa.w"

{
const int is_virtual_lhs= (piece_start> 0);
IRL_is_CHAF(chaf_irl)= 1;
Source_XRL_of_IRL(chaf_irl)= rule;
IRL_has_Virtual_LHS(chaf_irl)= Boolean(is_virtual_lhs);
IRL_has_Virtual_RHS(chaf_irl)= 
Length_of_IRL(chaf_irl)> real_symbol_count;
Virtual_Start_of_IRL(chaf_irl)= piece_start;
Virtual_End_of_IRL(chaf_irl)= piece_start+real_symbol_count-1;
Real_SYM_Count_of_IRL(chaf_irl)= real_symbol_count;
LHS_XRL_of_NSY(current_lhs_nsy)= chaf_xrl;
XRL_Offset_of_NSY(current_lhs_nsy)= piece_start;
}

/*:440*/
#line 4348 "./marpa.w"

}

/*:428*/
#line 4327 "./marpa.w"

/*429:*/
#line 4352 "./marpa.w"

{
int piece_ix;
const int second_nulling_piece_ix= second_factor_position-piece_start;
const int chaf_irl_length= (piece_end-piece_start)+2;
IRL chaf_irl= irl_start(g,chaf_irl_length);
LHSID_of_IRL(chaf_irl)= current_lhs_nsyid;
for(piece_ix= 0;piece_ix<second_nulling_piece_ix;piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
NSYID_by_XSYID(RHS_ID_of_RULE(rule,piece_start+piece_ix));
}
RHSID_of_IRL(chaf_irl,second_nulling_piece_ix)= 
Nulling_NSYID_by_XSYID(RHS_ID_of_RULE
(rule,piece_start+second_nulling_piece_ix));
for(piece_ix= second_nulling_piece_ix+1;
piece_ix<chaf_irl_length-1;piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
NSYID_by_XSYID(RHS_ID_of_RULE(rule,piece_start+piece_ix));
}
RHSID_of_IRL(chaf_irl,chaf_irl_length-1)= chaf_virtual_nsyid;
irl_finish(g,chaf_irl);
Rank_of_IRL(chaf_irl)= IRL_CHAF_Rank_by_XRL(rule,2);
/*440:*/
#line 4637 "./marpa.w"

{
const int is_virtual_lhs= (piece_start> 0);
IRL_is_CHAF(chaf_irl)= 1;
Source_XRL_of_IRL(chaf_irl)= rule;
IRL_has_Virtual_LHS(chaf_irl)= Boolean(is_virtual_lhs);
IRL_has_Virtual_RHS(chaf_irl)= 
Length_of_IRL(chaf_irl)> real_symbol_count;
Virtual_Start_of_IRL(chaf_irl)= piece_start;
Virtual_End_of_IRL(chaf_irl)= piece_start+real_symbol_count-1;
Real_SYM_Count_of_IRL(chaf_irl)= real_symbol_count;
LHS_XRL_of_NSY(current_lhs_nsy)= chaf_xrl;
XRL_Offset_of_NSY(current_lhs_nsy)= piece_start;
}

/*:440*/
#line 4376 "./marpa.w"

}

/*:429*/
#line 4328 "./marpa.w"

/*430:*/
#line 4380 "./marpa.w"

{
int piece_ix;
const int first_nulling_piece_ix= first_factor_position-piece_start;
const int chaf_irl_length= (piece_end-piece_start)+2;
IRL chaf_irl= irl_start(g,chaf_irl_length);
LHSID_of_IRL(chaf_irl)= current_lhs_nsyid;
for(piece_ix= 0;piece_ix<first_nulling_piece_ix;piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
NSYID_by_XSYID(RHS_ID_of_RULE(rule,piece_start+piece_ix));
}
RHSID_of_IRL(chaf_irl,first_nulling_piece_ix)= 
Nulling_NSYID_by_XSYID(RHS_ID_of_RULE
(rule,piece_start+first_nulling_piece_ix));
for(piece_ix= first_nulling_piece_ix+1;
piece_ix<chaf_irl_length-1;piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
NSYID_by_XSYID(RHS_ID_of_RULE(rule,piece_start+piece_ix));
}
RHSID_of_IRL(chaf_irl,chaf_irl_length-1)= chaf_virtual_nsyid;
irl_finish(g,chaf_irl);
Rank_of_IRL(chaf_irl)= IRL_CHAF_Rank_by_XRL(rule,1);
/*440:*/
#line 4637 "./marpa.w"

{
const int is_virtual_lhs= (piece_start> 0);
IRL_is_CHAF(chaf_irl)= 1;
Source_XRL_of_IRL(chaf_irl)= rule;
IRL_has_Virtual_LHS(chaf_irl)= Boolean(is_virtual_lhs);
IRL_has_Virtual_RHS(chaf_irl)= 
Length_of_IRL(chaf_irl)> real_symbol_count;
Virtual_Start_of_IRL(chaf_irl)= piece_start;
Virtual_End_of_IRL(chaf_irl)= piece_start+real_symbol_count-1;
Real_SYM_Count_of_IRL(chaf_irl)= real_symbol_count;
LHS_XRL_of_NSY(current_lhs_nsy)= chaf_xrl;
XRL_Offset_of_NSY(current_lhs_nsy)= piece_start;
}

/*:440*/
#line 4404 "./marpa.w"

}

/*:430*/
#line 4329 "./marpa.w"

/*431:*/
#line 4408 "./marpa.w"

{
int piece_ix;
const int first_nulling_piece_ix= first_factor_position-piece_start;
const int second_nulling_piece_ix= second_factor_position-piece_start;
const int chaf_irl_length= (piece_end-piece_start)+2;
IRL chaf_irl= irl_start(g,chaf_irl_length);
LHSID_of_IRL(chaf_irl)= current_lhs_nsyid;
for(piece_ix= 0;piece_ix<first_nulling_piece_ix;piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
NSYID_by_XSYID(RHS_ID_of_RULE(rule,piece_start+piece_ix));
}
RHSID_of_IRL(chaf_irl,first_nulling_piece_ix)= 
Nulling_NSYID_by_XSYID(RHS_ID_of_RULE
(rule,piece_start+first_nulling_piece_ix));
for(piece_ix= first_nulling_piece_ix+1;
piece_ix<second_nulling_piece_ix;piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
NSYID_by_XSYID(RHS_ID_of_RULE(rule,piece_start+piece_ix));
}
RHSID_of_IRL(chaf_irl,second_nulling_piece_ix)= 
Nulling_NSYID_by_XSYID(RHS_ID_of_RULE
(rule,piece_start+second_nulling_piece_ix));
for(piece_ix= second_nulling_piece_ix+1;piece_ix<chaf_irl_length-1;
piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
NSYID_by_XSYID(RHS_ID_of_RULE(rule,piece_start+piece_ix));
}
RHSID_of_IRL(chaf_irl,chaf_irl_length-1)= chaf_virtual_nsyid;
irl_finish(g,chaf_irl);
Rank_of_IRL(chaf_irl)= IRL_CHAF_Rank_by_XRL(rule,0);
/*440:*/
#line 4637 "./marpa.w"

{
const int is_virtual_lhs= (piece_start> 0);
IRL_is_CHAF(chaf_irl)= 1;
Source_XRL_of_IRL(chaf_irl)= rule;
IRL_has_Virtual_LHS(chaf_irl)= Boolean(is_virtual_lhs);
IRL_has_Virtual_RHS(chaf_irl)= 
Length_of_IRL(chaf_irl)> real_symbol_count;
Virtual_Start_of_IRL(chaf_irl)= piece_start;
Virtual_End_of_IRL(chaf_irl)= piece_start+real_symbol_count-1;
Real_SYM_Count_of_IRL(chaf_irl)= real_symbol_count;
LHS_XRL_of_NSY(current_lhs_nsy)= chaf_xrl;
XRL_Offset_of_NSY(current_lhs_nsy)= piece_start;
}

/*:440*/
#line 4442 "./marpa.w"

}

/*:431*/
#line 4330 "./marpa.w"

}

/*:427*/
#line 4223 "./marpa.w"

factor_position_ix+= 2;
}
current_lhs_nsy= chaf_virtual_nsy;
current_lhs_nsyid= chaf_virtual_nsyid;
piece_start= piece_end+1;

/*:422*/
#line 4188 "./marpa.w"

}
if(unprocessed_factor_count==2){
/*432:*/
#line 4447 "./marpa.w"

{
const int first_factor_position= factor_positions[factor_position_ix];
const int second_factor_position= factor_positions[factor_position_ix+1];
const int real_symbol_count= Length_of_XRL(rule)-piece_start;
piece_end= Length_of_XRL(rule)-1;
/*433:*/
#line 4460 "./marpa.w"

{
int piece_ix;
const int chaf_irl_length= (piece_end-piece_start)+1;
IRL chaf_irl= irl_start(g,chaf_irl_length);
LHSID_of_IRL(chaf_irl)= current_lhs_nsyid;
for(piece_ix= 0;piece_ix<chaf_irl_length;piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
NSYID_by_XSYID(RHS_ID_of_RULE(rule,piece_start+piece_ix));
}
irl_finish(g,chaf_irl);
Rank_of_IRL(chaf_irl)= IRL_CHAF_Rank_by_XRL(rule,3);
/*440:*/
#line 4637 "./marpa.w"

{
const int is_virtual_lhs= (piece_start> 0);
IRL_is_CHAF(chaf_irl)= 1;
Source_XRL_of_IRL(chaf_irl)= rule;
IRL_has_Virtual_LHS(chaf_irl)= Boolean(is_virtual_lhs);
IRL_has_Virtual_RHS(chaf_irl)= 
Length_of_IRL(chaf_irl)> real_symbol_count;
Virtual_Start_of_IRL(chaf_irl)= piece_start;
Virtual_End_of_IRL(chaf_irl)= piece_start+real_symbol_count-1;
Real_SYM_Count_of_IRL(chaf_irl)= real_symbol_count;
LHS_XRL_of_NSY(current_lhs_nsy)= chaf_xrl;
XRL_Offset_of_NSY(current_lhs_nsy)= piece_start;
}

/*:440*/
#line 4473 "./marpa.w"

}

/*:433*/
#line 4453 "./marpa.w"

/*434:*/
#line 4477 "./marpa.w"

{
int piece_ix;
const int second_nulling_piece_ix= second_factor_position-piece_start;
const int chaf_irl_length= (piece_end-piece_start)+1;
IRL chaf_irl= irl_start(g,chaf_irl_length);
LHSID_of_IRL(chaf_irl)= current_lhs_nsyid;
for(piece_ix= 0;piece_ix<second_nulling_piece_ix;piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
NSYID_by_XSYID(RHS_ID_of_RULE(rule,piece_start+piece_ix));
}
RHSID_of_IRL(chaf_irl,second_nulling_piece_ix)= 
Nulling_NSYID_by_XSYID(RHS_ID_of_RULE
(rule,piece_start+second_nulling_piece_ix));
for(piece_ix= second_nulling_piece_ix+1;piece_ix<chaf_irl_length;
piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
NSYID_by_XSYID(RHS_ID_of_RULE(rule,piece_start+piece_ix));
}
irl_finish(g,chaf_irl);
Rank_of_IRL(chaf_irl)= IRL_CHAF_Rank_by_XRL(rule,2);
/*440:*/
#line 4637 "./marpa.w"

{
const int is_virtual_lhs= (piece_start> 0);
IRL_is_CHAF(chaf_irl)= 1;
Source_XRL_of_IRL(chaf_irl)= rule;
IRL_has_Virtual_LHS(chaf_irl)= Boolean(is_virtual_lhs);
IRL_has_Virtual_RHS(chaf_irl)= 
Length_of_IRL(chaf_irl)> real_symbol_count;
Virtual_Start_of_IRL(chaf_irl)= piece_start;
Virtual_End_of_IRL(chaf_irl)= piece_start+real_symbol_count-1;
Real_SYM_Count_of_IRL(chaf_irl)= real_symbol_count;
LHS_XRL_of_NSY(current_lhs_nsy)= chaf_xrl;
XRL_Offset_of_NSY(current_lhs_nsy)= piece_start;
}

/*:440*/
#line 4500 "./marpa.w"

}

/*:434*/
#line 4454 "./marpa.w"

/*435:*/
#line 4504 "./marpa.w"

{
int piece_ix;
const int first_nulling_piece_ix= first_factor_position-piece_start;
const int chaf_irl_length= (piece_end-piece_start)+1;
IRL chaf_irl= irl_start(g,chaf_irl_length);
LHSID_of_IRL(chaf_irl)= current_lhs_nsyid;
for(piece_ix= 0;piece_ix<first_nulling_piece_ix;piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
NSYID_by_XSYID(RHS_ID_of_RULE(rule,piece_start+piece_ix));
}
RHSID_of_IRL(chaf_irl,first_nulling_piece_ix)= 
Nulling_NSYID_by_XSYID(RHS_ID_of_RULE
(rule,piece_start+first_nulling_piece_ix));
for(piece_ix= first_nulling_piece_ix+1;piece_ix<chaf_irl_length;
piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
NSYID_by_XSYID(RHS_ID_of_RULE(rule,piece_start+piece_ix));
}
irl_finish(g,chaf_irl);
Rank_of_IRL(chaf_irl)= IRL_CHAF_Rank_by_XRL(rule,1);
/*440:*/
#line 4637 "./marpa.w"

{
const int is_virtual_lhs= (piece_start> 0);
IRL_is_CHAF(chaf_irl)= 1;
Source_XRL_of_IRL(chaf_irl)= rule;
IRL_has_Virtual_LHS(chaf_irl)= Boolean(is_virtual_lhs);
IRL_has_Virtual_RHS(chaf_irl)= 
Length_of_IRL(chaf_irl)> real_symbol_count;
Virtual_Start_of_IRL(chaf_irl)= piece_start;
Virtual_End_of_IRL(chaf_irl)= piece_start+real_symbol_count-1;
Real_SYM_Count_of_IRL(chaf_irl)= real_symbol_count;
LHS_XRL_of_NSY(current_lhs_nsy)= chaf_xrl;
XRL_Offset_of_NSY(current_lhs_nsy)= piece_start;
}

/*:440*/
#line 4527 "./marpa.w"

}

/*:435*/
#line 4455 "./marpa.w"

/*436:*/
#line 4532 "./marpa.w"

{
if(piece_start<nullable_suffix_ix){
int piece_ix;
const int first_nulling_piece_ix= first_factor_position-piece_start;
const int second_nulling_piece_ix= second_factor_position-piece_start;
const int chaf_irl_length= (piece_end-piece_start)+1;
IRL chaf_irl= irl_start(g,chaf_irl_length);
LHSID_of_IRL(chaf_irl)= current_lhs_nsyid;
for(piece_ix= 0;piece_ix<first_nulling_piece_ix;piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
NSYID_by_XSYID(RHS_ID_of_RULE(rule,piece_start+piece_ix));
}

RHSID_of_IRL(chaf_irl,first_nulling_piece_ix)= 
Nulling_NSYID_by_XSYID(RHS_ID_of_RULE
(rule,piece_start+first_nulling_piece_ix));
for(piece_ix= first_nulling_piece_ix+1;
piece_ix<second_nulling_piece_ix;piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
NSYID_by_XSYID(RHS_ID_of_RULE(rule,piece_start+piece_ix));
}

RHSID_of_IRL(chaf_irl,second_nulling_piece_ix)= 
Nulling_NSYID_by_XSYID(RHS_ID_of_RULE
(rule,piece_start+second_nulling_piece_ix));
for(piece_ix= second_nulling_piece_ix+1;piece_ix<chaf_irl_length;
piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
NSYID_by_XSYID(RHS_ID_of_RULE(rule,piece_start+piece_ix));
}

irl_finish(g,chaf_irl);
Rank_of_IRL(chaf_irl)= IRL_CHAF_Rank_by_XRL(rule,0);
/*440:*/
#line 4637 "./marpa.w"

{
const int is_virtual_lhs= (piece_start> 0);
IRL_is_CHAF(chaf_irl)= 1;
Source_XRL_of_IRL(chaf_irl)= rule;
IRL_has_Virtual_LHS(chaf_irl)= Boolean(is_virtual_lhs);
IRL_has_Virtual_RHS(chaf_irl)= 
Length_of_IRL(chaf_irl)> real_symbol_count;
Virtual_Start_of_IRL(chaf_irl)= piece_start;
Virtual_End_of_IRL(chaf_irl)= piece_start+real_symbol_count-1;
Real_SYM_Count_of_IRL(chaf_irl)= real_symbol_count;
LHS_XRL_of_NSY(current_lhs_nsy)= chaf_xrl;
XRL_Offset_of_NSY(current_lhs_nsy)= piece_start;
}

/*:440*/
#line 4569 "./marpa.w"

}
}

/*:436*/
#line 4456 "./marpa.w"

}

/*:432*/
#line 4191 "./marpa.w"

}else{
/*437:*/
#line 4574 "./marpa.w"

{
int real_symbol_count;
const int first_factor_position= factor_positions[factor_position_ix];
piece_end= Length_of_XRL(rule)-1;
real_symbol_count= piece_end-piece_start+1;
/*438:*/
#line 4585 "./marpa.w"

{
int piece_ix;
const int chaf_irl_length= (piece_end-piece_start)+1;
IRL chaf_irl= irl_start(g,chaf_irl_length);
LHSID_of_IRL(chaf_irl)= current_lhs_nsyid;
for(piece_ix= 0;piece_ix<chaf_irl_length;piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
NSYID_by_XSYID(RHS_ID_of_RULE(rule,piece_start+piece_ix));
}
irl_finish(g,chaf_irl);
Rank_of_IRL(chaf_irl)= IRL_CHAF_Rank_by_XRL(rule,3);
/*440:*/
#line 4637 "./marpa.w"

{
const int is_virtual_lhs= (piece_start> 0);
IRL_is_CHAF(chaf_irl)= 1;
Source_XRL_of_IRL(chaf_irl)= rule;
IRL_has_Virtual_LHS(chaf_irl)= Boolean(is_virtual_lhs);
IRL_has_Virtual_RHS(chaf_irl)= 
Length_of_IRL(chaf_irl)> real_symbol_count;
Virtual_Start_of_IRL(chaf_irl)= piece_start;
Virtual_End_of_IRL(chaf_irl)= piece_start+real_symbol_count-1;
Real_SYM_Count_of_IRL(chaf_irl)= real_symbol_count;
LHS_XRL_of_NSY(current_lhs_nsy)= chaf_xrl;
XRL_Offset_of_NSY(current_lhs_nsy)= piece_start;
}

/*:440*/
#line 4598 "./marpa.w"

}

/*:438*/
#line 4580 "./marpa.w"

/*439:*/
#line 4603 "./marpa.w"

{
if(piece_start<nullable_suffix_ix)
{
int piece_ix;
const int nulling_piece_ix= first_factor_position-piece_start;
const int chaf_irl_length= (piece_end-piece_start)+1;
IRL chaf_irl= irl_start(g,chaf_irl_length);
LHSID_of_IRL(chaf_irl)= current_lhs_nsyid;
for(piece_ix= 0;piece_ix<nulling_piece_ix;piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
NSYID_by_XSYID(RHS_ID_of_RULE
(rule,piece_start+piece_ix));
}
RHSID_of_IRL(chaf_irl,nulling_piece_ix)= 
Nulling_NSYID_by_XSYID(RHS_ID_of_RULE(rule,piece_start+nulling_piece_ix));
for(piece_ix= nulling_piece_ix+1;piece_ix<chaf_irl_length;
piece_ix++)
{
RHSID_of_IRL(chaf_irl,piece_ix)= 
NSYID_by_XSYID(RHS_ID_of_RULE
(rule,piece_start+piece_ix));
}
irl_finish(g,chaf_irl);
Rank_of_IRL(chaf_irl)= IRL_CHAF_Rank_by_XRL(rule,0);
/*440:*/
#line 4637 "./marpa.w"

{
const int is_virtual_lhs= (piece_start> 0);
IRL_is_CHAF(chaf_irl)= 1;
Source_XRL_of_IRL(chaf_irl)= rule;
IRL_has_Virtual_LHS(chaf_irl)= Boolean(is_virtual_lhs);
IRL_has_Virtual_RHS(chaf_irl)= 
Length_of_IRL(chaf_irl)> real_symbol_count;
Virtual_Start_of_IRL(chaf_irl)= piece_start;
Virtual_End_of_IRL(chaf_irl)= piece_start+real_symbol_count-1;
Real_SYM_Count_of_IRL(chaf_irl)= real_symbol_count;
LHS_XRL_of_NSY(current_lhs_nsy)= chaf_xrl;
XRL_Offset_of_NSY(current_lhs_nsy)= piece_start;
}

/*:440*/
#line 4629 "./marpa.w"

}
}

/*:439*/
#line 4581 "./marpa.w"

}

/*:437*/
#line 4193 "./marpa.w"

}
}

/*:419*/
#line 4099 "./marpa.w"

continue;
}
/*260:*/
#line 2260 "./marpa.w"

{
int symbol_ix;
const IRL new_irl= irl_start(g,rewrite_xrl_length);
Source_XRL_of_IRL(new_irl)= rule;
Rank_of_IRL(new_irl)= IRL_Rank_by_XRL(rule);
for(symbol_ix= 0;symbol_ix<=rewrite_xrl_length;symbol_ix++)
{
new_irl->t_nsyid_array[symbol_ix]= 
NSYID_by_XSYID(rule->t_symbols[symbol_ix]);
}
irl_finish(g,new_irl);
}

/*:260*/
#line 4102 "./marpa.w"

}
}

/*:413*/
#line 3210 "./marpa.w"

/*442:*/
#line 4655 "./marpa.w"

{
const XSY start_xsy= XSY_by_ID(start_xsy_id);
if(_MARPA_LIKELY(!XSY_is_Nulling(start_xsy))){
/*443:*/
#line 4663 "./marpa.w"
{
IRL new_start_irl;

const NSY new_start_nsy= nsy_new(g,start_xsy);
NSY_is_Start(new_start_nsy)= 1;

new_start_irl= irl_start(g,1);
LHSID_of_IRL(new_start_irl)= ID_of_NSY(new_start_nsy);
RHSID_of_IRL(new_start_irl,0)= NSYID_of_XSY(start_xsy);
irl_finish(g,new_start_irl);
IRL_has_Virtual_LHS(new_start_irl)= 1;
Real_SYM_Count_of_IRL(new_start_irl)= 1;
g->t_start_irl= new_start_irl;

}

/*:443*/
#line 4659 "./marpa.w"

}
}

/*:442*/
#line 3211 "./marpa.w"

post_census_xsy_count= XSY_Count_of_G(g);
/*524:*/
#line 5578 "./marpa.w"

{
int xsyid;
g->t_lbv_xsyid_is_completion_event= 
bv_obs_create(g->t_obs,post_census_xsy_count);
g->t_lbv_xsyid_completion_event_starts_active= 
bv_obs_create(g->t_obs,post_census_xsy_count);
g->t_lbv_xsyid_is_nulled_event= 
bv_obs_create(g->t_obs,post_census_xsy_count);
g->t_lbv_xsyid_nulled_event_starts_active= 
bv_obs_create(g->t_obs,post_census_xsy_count);
g->t_lbv_xsyid_is_prediction_event= 
bv_obs_create(g->t_obs,post_census_xsy_count);
g->t_lbv_xsyid_prediction_event_starts_active= 
bv_obs_create(g->t_obs,post_census_xsy_count);
for(xsyid= 0;xsyid<post_census_xsy_count;xsyid++)
{
if(XSYID_is_Completion_Event(xsyid))
{
lbv_bit_set(g->t_lbv_xsyid_is_completion_event,xsyid);
}
if(XSYID_Completion_Event_Starts_Active(xsyid))
{
lbv_bit_set(g->t_lbv_xsyid_completion_event_starts_active,xsyid);
}
if(XSYID_is_Nulled_Event(xsyid))
{
lbv_bit_set(g->t_lbv_xsyid_is_nulled_event,xsyid);
}
if(XSYID_Nulled_Event_Starts_Active(xsyid))
{
lbv_bit_set(g->t_lbv_xsyid_nulled_event_starts_active,xsyid);
}
if(XSYID_is_Prediction_Event(xsyid))
{
lbv_bit_set(g->t_lbv_xsyid_is_prediction_event,xsyid);
}
if(XSYID_Prediction_Event_Starts_Active(xsyid))
{
lbv_bit_set(g->t_lbv_xsyid_prediction_event_starts_active,xsyid);
}
}
}

/*:524*/
#line 3213 "./marpa.w"




if(!G_is_Trivial(g)){
/*511:*/
#line 5372 "./marpa.w"

const RULEID irl_count= IRL_Count_of_G(g);
const NSYID nsy_count= NSY_Count_of_G(g);
Bit_Matrix nsy_by_right_nsy_matrix;
Bit_Matrix prediction_nsy_by_irl_matrix;

/*:511*/
#line 3219 "./marpa.w"

/*514:*/
#line 5394 "./marpa.w"

{
NSYID lhsid;




void*matrix_buffer= my_malloc(matrix_sizeof(
nsy_count,irl_count));
Bit_Matrix irl_by_lhs_matrix= 
matrix_buffer_create(matrix_buffer,nsy_count,irl_count);

IRLID irl_id;
for(irl_id= 0;irl_id<irl_count;irl_id++)
{
const IRL irl= IRL_by_ID(irl_id);
const NSYID lhs_nsyid= LHSID_of_IRL(irl);
matrix_bit_set(irl_by_lhs_matrix,lhs_nsyid,irl_id);
}




for(lhsid= 0;lhsid<nsy_count;lhsid++)
{
IRLID irlid;
int min,max,start;
cil_buffer_clear(&g->t_cilar);
for(start= 0;
bv_scan(matrix_row
(irl_by_lhs_matrix,lhsid),
start,&min,&max);start= max+2)
{
for(irlid= min;irlid<=max;irlid++)
{
cil_buffer_push(&g->t_cilar,irlid);
}
}
LHS_CIL_of_NSYID(lhsid)= cil_buffer_add(&g->t_cilar);
}

my_free(matrix_buffer);

}

/*:514*/
#line 3220 "./marpa.w"

/*485:*/
#line 5043 "./marpa.w"

{
IRLID irl_id;
int ahm_count= 0;
AHM base_item;
AHM current_item;
int symbol_instance_of_next_rule= 0;
for(irl_id= 0;irl_id<irl_count;irl_id++){
const IRL irl= IRL_by_ID(irl_id);
/*487:*/
#line 5095 "./marpa.w"

{
int rhs_ix;
for(rhs_ix= 0;rhs_ix<Length_of_IRL(irl);rhs_ix++)
{
const NSYID rh_nsyid= RHSID_of_IRL(irl,rhs_ix);
const NSY nsy= NSY_by_ID(rh_nsyid);
if(!NSY_is_Nulling(nsy))ahm_count++;
}
ahm_count++;
}

/*:487*/
#line 5052 "./marpa.w"

}
current_item= base_item= marpa_new(struct s_ahm,ahm_count);
for(irl_id= 0;irl_id<irl_count;irl_id++){
const IRL irl= IRL_by_ID(irl_id);
SYMI_of_IRL(irl)= symbol_instance_of_next_rule;
/*486:*/
#line 5070 "./marpa.w"

{
int leading_nulls= 0;
int rhs_ix;
const AHM first_ahm_of_irl= current_item;
for(rhs_ix= 0;rhs_ix<Length_of_IRL(irl);rhs_ix++)
{
NSYID rh_nsyid= RHSID_of_IRL(irl,rhs_ix);
if(!NSY_is_Nulling(NSY_by_ID(rh_nsyid)))
{
Last_Proper_SYMI_of_IRL(irl)= symbol_instance_of_next_rule+rhs_ix;
/*488:*/
#line 5107 "./marpa.w"

{
/*490:*/
#line 5130 "./marpa.w"

{
IRL_of_AHM(current_item)= irl;
Null_Count_of_AHM(current_item)= leading_nulls;
Quasi_Position_of_AHM(current_item)= (int)(current_item-first_ahm_of_irl);
if(Quasi_Position_of_AHM(current_item)==0){
if(ID_of_IRL(irl)==ID_of_IRL(g->t_start_irl))
{
AHM_was_Predicted(current_item)= 0;
AHM_is_Initial(current_item)= 1;
}else{
AHM_was_Predicted(current_item)= 1;
AHM_is_Initial(current_item)= 0;
}
}else{
AHM_was_Predicted(current_item)= 0;
AHM_is_Initial(current_item)= 0;
}
/*505:*/
#line 5269 "./marpa.w"

Event_AHMIDs_of_AHM(current_item)= NULL;
Event_Group_Size_of_AHM(current_item)= 0;

/*:505*/
#line 5148 "./marpa.w"

}

/*:490*/
#line 5109 "./marpa.w"

AHM_predicts_ZWA(current_item)= 0;

Postdot_NSYID_of_AHM(current_item)= rh_nsyid;
Position_of_AHM(current_item)= rhs_ix;
SYMI_of_AHM(current_item)
= AHM_is_Prediction(current_item)
?-1
:SYMI_of_IRL(irl)+Position_of_AHM(current_item-1);
/*491:*/
#line 5151 "./marpa.w"

{
XRL source_xrl= Source_XRL_of_IRL(irl);
XRL_of_AHM(current_item)= source_xrl;
if(!source_xrl){


XRL_Position_of_AHM(current_item)= -2;
}else{
const int virtual_start= Virtual_Start_of_IRL(irl);
const int irl_position= Position_of_AHM(current_item);
int xrl_position= irl_position;
if(virtual_start>=0)
{
xrl_position+= virtual_start;
}
if(XRL_is_Sequence(source_xrl))
{




xrl_position= irl_position> 0?-1:0;
}
XRL_Position_of_AHM(current_item)= xrl_position;
}
}

/*:491*/
#line 5118 "./marpa.w"

}

/*:488*/
#line 5081 "./marpa.w"

current_item++;
leading_nulls= 0;
}
else
{
leading_nulls++;
}
}
/*489:*/
#line 5121 "./marpa.w"

{
/*490:*/
#line 5130 "./marpa.w"

{
IRL_of_AHM(current_item)= irl;
Null_Count_of_AHM(current_item)= leading_nulls;
Quasi_Position_of_AHM(current_item)= (int)(current_item-first_ahm_of_irl);
if(Quasi_Position_of_AHM(current_item)==0){
if(ID_of_IRL(irl)==ID_of_IRL(g->t_start_irl))
{
AHM_was_Predicted(current_item)= 0;
AHM_is_Initial(current_item)= 1;
}else{
AHM_was_Predicted(current_item)= 1;
AHM_is_Initial(current_item)= 0;
}
}else{
AHM_was_Predicted(current_item)= 0;
AHM_is_Initial(current_item)= 0;
}
/*505:*/
#line 5269 "./marpa.w"

Event_AHMIDs_of_AHM(current_item)= NULL;
Event_Group_Size_of_AHM(current_item)= 0;

/*:505*/
#line 5148 "./marpa.w"

}

/*:490*/
#line 5123 "./marpa.w"

Postdot_NSYID_of_AHM(current_item)= -1;
Position_of_AHM(current_item)= -1;
SYMI_of_AHM(current_item)= SYMI_of_IRL(irl)+Position_of_AHM(current_item-1);
/*491:*/
#line 5151 "./marpa.w"

{
XRL source_xrl= Source_XRL_of_IRL(irl);
XRL_of_AHM(current_item)= source_xrl;
if(!source_xrl){


XRL_Position_of_AHM(current_item)= -2;
}else{
const int virtual_start= Virtual_Start_of_IRL(irl);
const int irl_position= Position_of_AHM(current_item);
int xrl_position= irl_position;
if(virtual_start>=0)
{
xrl_position+= virtual_start;
}
if(XRL_is_Sequence(source_xrl))
{




xrl_position= irl_position> 0?-1:0;
}
XRL_Position_of_AHM(current_item)= xrl_position;
}
}

/*:491*/
#line 5127 "./marpa.w"

}

/*:489*/
#line 5090 "./marpa.w"

current_item++;
AHM_Count_of_IRL(irl)= (int)(current_item-first_ahm_of_irl);
}

/*:486*/
#line 5058 "./marpa.w"

{
symbol_instance_of_next_rule+= Length_of_IRL(irl);
}
}
SYMI_Count_of_G(g)= symbol_instance_of_next_rule;
MARPA_ASSERT(ahm_count==current_item-base_item);
AHM_Count_of_G(g)= ahm_count;
g->t_ahms= marpa_renew(struct s_ahm,base_item,ahm_count);
/*493:*/
#line 5187 "./marpa.w"

{
AHM items= g->t_ahms;
AHMID item_id= (AHMID)ahm_count;
for(item_id--;item_id>=0;item_id--)
{
AHM item= items+item_id;
IRL irl= IRL_of_AHM(item);
First_AHM_of_IRL(irl)= item;
}
}

/*:493*/
#line 5067 "./marpa.w"

}

/*:485*/
#line 3221 "./marpa.w"

/*517:*/
#line 5447 "./marpa.w"
{
Bit_Matrix prediction_nsy_by_nsy_matrix= 
matrix_obs_create(obs_precompute,nsy_count,nsy_count);
/*518:*/
#line 5455 "./marpa.w"

{
IRLID irl_id;
NSYID nsyid;
for(nsyid= 0;nsyid<nsy_count;nsyid++)
{

NSY nsy= NSY_by_ID(nsyid);
if(!NSY_is_LHS(nsy))continue;
matrix_bit_set(prediction_nsy_by_nsy_matrix,nsyid,
nsyid);
}
for(irl_id= 0;irl_id<irl_count;irl_id++)
{
NSYID from_nsyid,to_nsyid;
const IRL irl= IRL_by_ID(irl_id);

const AHM item= First_AHM_of_IRL(irl);
to_nsyid= Postdot_NSYID_of_AHM(item);

if(to_nsyid<0)
continue;

from_nsyid= LHS_NSYID_of_AHM(item);
matrix_bit_set(prediction_nsy_by_nsy_matrix,
from_nsyid,
to_nsyid);
}
}

/*:518*/
#line 5450 "./marpa.w"

transitive_closure(prediction_nsy_by_nsy_matrix);
/*519:*/
#line 5492 "./marpa.w"
{
/*520:*/
#line 5496 "./marpa.w"

{
NSYID from_nsyid;
prediction_nsy_by_irl_matrix= 
matrix_obs_create(obs_precompute,nsy_count,
irl_count);
for(from_nsyid= 0;from_nsyid<nsy_count;from_nsyid++)
{


int min,max,start;
for(start= 0;
bv_scan(matrix_row
(prediction_nsy_by_nsy_matrix,from_nsyid),
start,&min,&max);start= max+2)
{
NSYID to_nsyid;



for(to_nsyid= min;to_nsyid<=max;to_nsyid++)
{
int cil_ix;
const CIL lhs_cil= LHS_CIL_of_NSYID(to_nsyid);
const int cil_count= Count_of_CIL(lhs_cil);
for(cil_ix= 0;cil_ix<cil_count;cil_ix++)
{
const IRLID irlid= Item_of_CIL(lhs_cil,cil_ix);
matrix_bit_set(prediction_nsy_by_irl_matrix,
from_nsyid,irlid);
}
}
}
}
}

/*:520*/
#line 5493 "./marpa.w"

}

/*:519*/
#line 5452 "./marpa.w"

}

/*:517*/
#line 3222 "./marpa.w"

/*507:*/
#line 5282 "./marpa.w"
{
nsy_by_right_nsy_matrix= 
matrix_obs_create(obs_precompute,nsy_count,nsy_count);
/*508:*/
#line 5293 "./marpa.w"

{
IRLID irl_id;
for(irl_id= 0;irl_id<irl_count;irl_id++)
{
const IRL irl= IRL_by_ID(irl_id);
int rhs_ix;
for(rhs_ix= Length_of_IRL(irl)-1;
rhs_ix>=0;
rhs_ix--)
{


const NSYID rh_nsyid= RHSID_of_IRL(irl,rhs_ix);
if(!NSY_is_Nulling(NSY_by_ID(rh_nsyid)))
{
matrix_bit_set(nsy_by_right_nsy_matrix,
LHSID_of_IRL(irl),
rh_nsyid);
break;
}
}
}
}

/*:508*/
#line 5285 "./marpa.w"

transitive_closure(nsy_by_right_nsy_matrix);
/*509:*/
#line 5318 "./marpa.w"

{
IRLID irl_id;
for(irl_id= 0;irl_id<irl_count;irl_id++)
{
const IRL irl= IRL_by_ID(irl_id);
int rhs_ix;
for(rhs_ix= Length_of_IRL(irl)-1;rhs_ix>=0;rhs_ix--)
{
const NSYID rh_nsyid= RHSID_of_IRL(irl,rhs_ix);
if(!NSY_is_Nulling(NSY_by_ID(rh_nsyid)))
{



if(matrix_bit_test(nsy_by_right_nsy_matrix,
rh_nsyid,
LHSID_of_IRL(irl)))
{
IRL_is_Right_Recursive(irl)= 1;
}
break;
}
}
}
}

/*:509*/
#line 5287 "./marpa.w"

matrix_clear(nsy_by_right_nsy_matrix);
/*510:*/
#line 5345 "./marpa.w"

{
IRLID irl_id;
for(irl_id= 0;irl_id<irl_count;irl_id++)
{
int rhs_ix;
const IRL irl= IRL_by_ID(irl_id);
if(!IRL_is_Right_Recursive(irl)){continue;}
for(rhs_ix= Length_of_IRL(irl)-1;
rhs_ix>=0;
rhs_ix--)
{


const NSYID rh_nsyid= RHSID_of_IRL(irl,rhs_ix);
if(!NSY_is_Nulling(NSY_by_ID(rh_nsyid)))
{
matrix_bit_set(nsy_by_right_nsy_matrix,
LHSID_of_IRL(irl),
rh_nsyid);
break;
}
}
}
}

/*:510*/
#line 5289 "./marpa.w"

transitive_closure(nsy_by_right_nsy_matrix);
}

/*:507*/
#line 3223 "./marpa.w"

/*522:*/
#line 5533 "./marpa.w"

{
AHMID ahm_id;
const int ahm_count= AHM_Count_of_G(g);
for(ahm_id= 0;ahm_id<ahm_count;ahm_id++)
{
const AHM ahm= AHM_by_ID(ahm_id);
const NSYID postdot_nsyid= Postdot_NSYID_of_AHM(ahm);
if(postdot_nsyid<0)
{
Predicted_IRL_CIL_of_AHM(ahm)= cil_empty(&g->t_cilar);
LHS_CIL_of_AHM(ahm)= cil_empty(&g->t_cilar);
}
else
{
Predicted_IRL_CIL_of_AHM(ahm)= 
cil_bv_add(&g->t_cilar,
matrix_row(prediction_nsy_by_irl_matrix,postdot_nsyid));
LHS_CIL_of_AHM(ahm)= LHS_CIL_of_NSYID(postdot_nsyid);
}
}
}

/*:522*/
#line 3224 "./marpa.w"

/*523:*/
#line 5557 "./marpa.w"

{
int xsy_id;
g->t_bv_nsyid_is_terminal= bv_obs_create(g->t_obs,nsy_count);
for(xsy_id= 0;xsy_id<post_census_xsy_count;xsy_id++)
{
if(XSYID_is_Terminal(xsy_id))
{


const NSY nsy= NSY_of_XSY(XSY_by_ID(xsy_id));
if(nsy)
{
bv_bit_set(g->t_bv_nsyid_is_terminal,
ID_of_NSY(nsy));
}
}
}
}

/*:523*/
#line 3225 "./marpa.w"

/*525:*/
#line 5622 "./marpa.w"

{
AHMID ahm_id;
const int ahm_count_of_g= AHM_Count_of_G(g);
const LBV bv_completion_xsyid= bv_create(post_census_xsy_count);
const LBV bv_prediction_xsyid= bv_create(post_census_xsy_count);
const LBV bv_nulled_xsyid= bv_create(post_census_xsy_count);
const CILAR cilar= &g->t_cilar;
for(ahm_id= 0;ahm_id<ahm_count_of_g;ahm_id++)
{
const AHM ahm= AHM_by_ID(ahm_id);
const NSYID postdot_nsyid= Postdot_NSYID_of_AHM(ahm);
const IRL irl= IRL_of_AHM(ahm);
bv_clear(bv_completion_xsyid);
bv_clear(bv_prediction_xsyid);
bv_clear(bv_nulled_xsyid);
{
int rhs_ix;
int raw_position= Position_of_AHM(ahm);
if(raw_position<0)
{
raw_position= Length_of_IRL(irl);
if(!IRL_has_Virtual_LHS(irl))
{
const NSY lhs= LHS_of_IRL(irl);
const XSY xsy= Source_XSY_of_NSY(lhs);
if(XSY_is_Completion_Event(xsy))
{
const XSYID xsyid= ID_of_XSY(xsy);
bv_bit_set(bv_completion_xsyid,xsyid);
}
}
}
if(postdot_nsyid>=0)
{
const XSY xsy= Source_XSY_of_NSYID(postdot_nsyid);
const XSYID xsyid= ID_of_XSY(xsy);
bv_bit_set(bv_prediction_xsyid,xsyid);
}
for(rhs_ix= raw_position-Null_Count_of_AHM(ahm);
rhs_ix<raw_position;rhs_ix++)
{
int cil_ix;
const NSYID rhs_nsyid= RHSID_of_IRL(irl,rhs_ix);
const XSY xsy= Source_XSY_of_NSYID(rhs_nsyid);
const CIL nulled_xsyids= Nulled_XSYIDs_of_XSY(xsy);
const int cil_count= Count_of_CIL(nulled_xsyids);
for(cil_ix= 0;cil_ix<cil_count;cil_ix++)
{
const XSYID nulled_xsyid= 
Item_of_CIL(nulled_xsyids,cil_ix);
bv_bit_set(bv_nulled_xsyid,nulled_xsyid);
}
}
}
Completion_XSYIDs_of_AHM(ahm)= 
cil_bv_add(cilar,bv_completion_xsyid);
Nulled_XSYIDs_of_AHM(ahm)= cil_bv_add(cilar,bv_nulled_xsyid);
Prediction_XSYIDs_of_AHM(ahm)= 
cil_bv_add(cilar,bv_prediction_xsyid);
}
bv_free(bv_completion_xsyid);
bv_free(bv_prediction_xsyid);
bv_free(bv_nulled_xsyid);
}

/*:525*/
#line 3227 "./marpa.w"

/*526:*/
#line 5688 "./marpa.w"

{
AHMID ahm_id;
for(ahm_id= 0;ahm_id<AHM_Count_of_G(g);ahm_id++)
{
const CILAR cilar= &g->t_cilar;
const AHM ahm= AHM_by_ID(ahm_id);
const int ahm_is_event= 
Count_of_CIL(Completion_XSYIDs_of_AHM(ahm))
||Count_of_CIL(Nulled_XSYIDs_of_AHM(ahm))
||Count_of_CIL(Prediction_XSYIDs_of_AHM(ahm));
Event_AHMIDs_of_AHM(ahm)= 
ahm_is_event?cil_singleton(cilar,ahm_id):cil_empty(cilar);
}
}

/*:526*/
#line 3228 "./marpa.w"

/*527:*/
#line 5704 "./marpa.w"

{
const int ahm_count_of_g= AHM_Count_of_G(g);
AHMID outer_ahm_id;
for(outer_ahm_id= 0;outer_ahm_id<ahm_count_of_g;outer_ahm_id++)
{
AHMID inner_ahm_id;
const AHM outer_ahm= AHM_by_ID(outer_ahm_id);




NSYID outer_nsyid;
if(!AHM_is_Leo_Completion(outer_ahm)){
if(AHM_has_Event(outer_ahm)){
Event_Group_Size_of_AHM(outer_ahm)= 1;
}
continue;

}
outer_nsyid= LHSID_of_AHM(outer_ahm);
for(inner_ahm_id= 0;inner_ahm_id<ahm_count_of_g;
inner_ahm_id++)
{
NSYID inner_nsyid;
const AHM inner_ahm= AHM_by_ID(inner_ahm_id);
if(!AHM_has_Event(inner_ahm))
continue;

if(!AHM_is_Leo_Completion(inner_ahm))
continue;

inner_nsyid= LHSID_of_AHM(inner_ahm);
if(matrix_bit_test(nsy_by_right_nsy_matrix,
outer_nsyid,
inner_nsyid))
{



Event_Group_Size_of_AHM(outer_ahm)++;
}
}
}
}

/*:527*/
#line 3229 "./marpa.w"

/*546:*/
#line 5909 "./marpa.w"

{
AHMID ahm_id;
const int ahm_count_of_g= AHM_Count_of_G(g);
for(ahm_id= 0;ahm_id<ahm_count_of_g;ahm_id++)
{
ZWP_Object sought_zwp_object;
ZWP sought_zwp= &sought_zwp_object;
ZWP found_zwp;
MARPA_AVL_TRAV traverser;
const AHM ahm= AHM_by_ID(ahm_id);
const XRL ahm_xrl= XRL_of_AHM(ahm);
cil_buffer_clear(&g->t_cilar);
if(ahm_xrl)
{
const int xrl_dot_end= Raw_XRL_Position_of_AHM(ahm);
const int xrl_dot_start= xrl_dot_end-Null_Count_of_AHM(ahm);


const XRLID sought_xrlid= ID_of_XRL(ahm_xrl);
XRLID_of_ZWP(sought_zwp)= sought_xrlid;
Dot_of_ZWP(sought_zwp)= xrl_dot_start;
ZWAID_of_ZWP(sought_zwp)= 0;
traverser= _marpa_avl_t_init((g)->t_zwp_tree);
found_zwp= _marpa_avl_t_at_or_after(traverser,sought_zwp);



while(
found_zwp
&&XRLID_of_ZWP(found_zwp)==sought_xrlid
&&Dot_of_ZWP(found_zwp)<=xrl_dot_end)
{
cil_buffer_push(&g->t_cilar,ZWAID_of_ZWP(found_zwp));
found_zwp= _marpa_avl_t_next(traverser);
}
}
ZWA_CIL_of_AHM(ahm)= cil_buffer_add(&g->t_cilar);
}
}

/*:546*/
#line 3230 "./marpa.w"

/*547:*/
#line 5954 "./marpa.w"

{
AHMID ahm_id;
const int ahm_count_of_g= AHM_Count_of_G(g);
for(ahm_id= 0;ahm_id<ahm_count_of_g;ahm_id++)
{
const AHM ahm_to_populate= AHM_by_ID(ahm_id);




const CIL prediction_cil= Predicted_IRL_CIL_of_AHM(ahm_to_populate);
const int prediction_count= Count_of_CIL(prediction_cil);

int cil_ix;
for(cil_ix= 0;cil_ix<prediction_count;cil_ix++)
{
const IRLID prediction_irlid= Item_of_CIL(prediction_cil,cil_ix);
const AHM prediction_ahm_of_irl= First_AHM_of_IRLID(prediction_irlid);
const CIL zwaids_of_prediction= ZWA_CIL_of_AHM(prediction_ahm_of_irl);
if(Count_of_CIL(zwaids_of_prediction)> 0){
AHM_predicts_ZWA(ahm_to_populate)= 1;
break;
}
}
}
}

/*:547*/
#line 3231 "./marpa.w"

}
g->t_is_precomputed= 1;
if(g->t_has_cycle)
{
MARPA_ERROR(MARPA_ERR_GRAMMAR_HAS_CYCLE);
goto FAILURE;
}
/*369:*/
#line 3253 "./marpa.w"

{cilar_buffer_reinit(&g->t_cilar);}
/*:369*/
#line 3239 "./marpa.w"

return_value= 0;
goto CLEANUP;
FAILURE:;
goto CLEANUP;
CLEANUP:;
marpa_obs_free(obs_precompute);
return return_value;
}

/*:368*//*379:*/
#line 3352 "./marpa.w"

PRIVATE_NOT_INLINE int sym_rule_cmp(
const void*ap,
const void*bp,
void*param UNUSED)
{
const struct sym_rule_pair*pair_a= (struct sym_rule_pair*)ap;
const struct sym_rule_pair*pair_b= (struct sym_rule_pair*)bp;
int result= pair_a->t_symid-pair_b->t_symid;
if(result)return result;
return pair_a->t_ruleid-pair_b->t_ruleid;
}

/*:379*//*412:*/
#line 4064 "./marpa.w"

int _marpa_g_irl_is_chaf(
Marpa_Grammar g,
Marpa_IRL_ID irl_id)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 4069 "./marpa.w"

/*1211:*/
#line 14600 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1211*/
#line 4070 "./marpa.w"

/*1218:*/
#line 14641 "./marpa.w"

if(_MARPA_UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1218*/
#line 4071 "./marpa.w"

return IRL_is_CHAF(IRL_by_ID(irl_id));
}

/*:412*//*461:*/
#line 4880 "./marpa.w"

PRIVATE int ahm_is_valid(
GRAMMAR g,AHMID item_id)
{
return item_id<(AHMID)AHM_Count_of_G(g)&&item_id>=0;
}

/*:461*//*478:*/
#line 5006 "./marpa.w"

int _marpa_g_ahm_count(Marpa_Grammar g){
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 5008 "./marpa.w"

/*1211:*/
#line 14600 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1211*/
#line 5009 "./marpa.w"

return AHM_Count_of_G(g);
}

/*:478*//*479:*/
#line 5013 "./marpa.w"

Marpa_IRL_ID _marpa_g_ahm_irl(Marpa_Grammar g,
Marpa_AHM_ID item_id){
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 5016 "./marpa.w"

/*1211:*/
#line 14600 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1211*/
#line 5017 "./marpa.w"

/*1224:*/
#line 14684 "./marpa.w"

if(_MARPA_UNLIKELY(!ahm_is_valid(g,item_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AIMID);
return failure_indicator;
}

/*:1224*/
#line 5018 "./marpa.w"

return IRLID_of_AHM(AHM_by_ID(item_id));
}

/*:479*//*481:*/
#line 5023 "./marpa.w"

int _marpa_g_ahm_position(Marpa_Grammar g,
Marpa_AHM_ID item_id){
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 5026 "./marpa.w"

/*1211:*/
#line 14600 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1211*/
#line 5027 "./marpa.w"

/*1224:*/
#line 14684 "./marpa.w"

if(_MARPA_UNLIKELY(!ahm_is_valid(g,item_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AIMID);
return failure_indicator;
}

/*:1224*/
#line 5028 "./marpa.w"

return Position_of_AHM(AHM_by_ID(item_id));
}

/*:481*//*483:*/
#line 5033 "./marpa.w"

Marpa_Symbol_ID _marpa_g_ahm_postdot(Marpa_Grammar g,
Marpa_AHM_ID item_id){
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 5036 "./marpa.w"

/*1211:*/
#line 14600 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1211*/
#line 5037 "./marpa.w"

/*1224:*/
#line 14684 "./marpa.w"

if(_MARPA_UNLIKELY(!ahm_is_valid(g,item_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AIMID);
return failure_indicator;
}

/*:1224*/
#line 5038 "./marpa.w"

return Postdot_NSYID_of_AHM(AHM_by_ID(item_id));
}

/*:483*//*542:*/
#line 5819 "./marpa.w"

PRIVATE_NOT_INLINE int zwp_cmp(
const void*ap,
const void*bp,
void*param UNUSED)
{
const ZWP_Const zwp_a= ap;
const ZWP_Const zwp_b= bp;
int subkey= XRLID_of_ZWP(zwp_a)-XRLID_of_ZWP(zwp_b);
if(subkey)return subkey;
subkey= Dot_of_ZWP(zwp_a)-Dot_of_ZWP(zwp_b);
if(subkey)return subkey;
return ZWAID_of_ZWP(zwp_a)-ZWAID_of_ZWP(zwp_b);
}

/*:542*//*543:*/
#line 5834 "./marpa.w"

Marpa_Assertion_ID
marpa_g_zwa_new(Marpa_Grammar g,int default_value)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 5838 "./marpa.w"

ZWAID zwa_id;
GZWA gzwa;
/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 5841 "./marpa.w"

/*1210:*/
#line 14594 "./marpa.w"

if(_MARPA_UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1210*/
#line 5842 "./marpa.w"

if(_MARPA_UNLIKELY(default_value<0||default_value> 1))
{
MARPA_ERROR(MARPA_ERR_INVALID_BOOLEAN);
return failure_indicator;
}
gzwa= marpa_obs_new(g->t_obs,GZWA_Object,1);
zwa_id= MARPA_DSTACK_LENGTH((g)->t_gzwa_stack);
*MARPA_DSTACK_PUSH((g)->t_gzwa_stack,GZWA)= gzwa;
gzwa->t_id= zwa_id;
gzwa->t_default_value= default_value?1:0;
return zwa_id;
}

/*:543*//*544:*/
#line 5856 "./marpa.w"

Marpa_Assertion_ID
marpa_g_highest_zwa_id(Marpa_Grammar g)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 5860 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 5861 "./marpa.w"

return ZWA_Count_of_G(g)-1;
}

/*:544*//*545:*/
#line 5868 "./marpa.w"

int
marpa_g_zwa_place(Marpa_Grammar g,
Marpa_Assertion_ID zwaid,
Marpa_Rule_ID xrl_id,int rhs_ix)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 5874 "./marpa.w"

void*avl_insert_result;
ZWP zwp;
XRL xrl;
int xrl_length;
/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 5879 "./marpa.w"

/*1210:*/
#line 14594 "./marpa.w"

if(_MARPA_UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1210*/
#line 5880 "./marpa.w"

/*1221:*/
#line 14661 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}

/*:1221*/
#line 5881 "./marpa.w"

/*1219:*/
#line 14649 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}

/*:1219*/
#line 5882 "./marpa.w"

/*1223:*/
#line 14673 "./marpa.w"

if(_MARPA_UNLIKELY(ZWAID_is_Malformed(zwaid))){
MARPA_ERROR(MARPA_ERR_INVALID_ASSERTION_ID);
return failure_indicator;
}

/*:1223*/
#line 5883 "./marpa.w"

/*1222:*/
#line 14667 "./marpa.w"

if(_MARPA_UNLIKELY(!ZWAID_of_G_Exists(zwaid))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_ASSERTION_ID);
return failure_indicator;
}
/*:1222*/
#line 5884 "./marpa.w"

xrl= XRL_by_ID(xrl_id);
if(rhs_ix<-1){
MARPA_ERROR(MARPA_ERR_RHS_IX_NEGATIVE);
return failure_indicator;
}
xrl_length= Length_of_XRL(xrl);
if(xrl_length<=rhs_ix){
MARPA_ERROR(MARPA_ERR_RHS_IX_OOB);
return failure_indicator;
}
if(rhs_ix==-1){
rhs_ix= XRL_is_Sequence(xrl)?1:xrl_length;
}
zwp= marpa_obs_new(g->t_obs,ZWP_Object,1);
XRLID_of_ZWP(zwp)= xrl_id;
Dot_of_ZWP(zwp)= rhs_ix;
ZWAID_of_ZWP(zwp)= zwaid;
avl_insert_result= _marpa_avl_insert(g->t_zwp_tree,zwp);
return avl_insert_result?-1:0;
}

/*:545*//*551:*/
#line 6000 "./marpa.w"

Marpa_Recognizer marpa_r_new(Marpa_Grammar g)
{
RECCE r;
int nsy_count;
int irl_count;
/*1208:*/
#line 14586 "./marpa.w"
void*const failure_indicator= NULL;
/*:1208*/
#line 6006 "./marpa.w"

/*1211:*/
#line 14600 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1211*/
#line 6007 "./marpa.w"

nsy_count= NSY_Count_of_G(g);
irl_count= IRL_Count_of_G(g);
r= my_malloc(sizeof(struct marpa_r));
/*616:*/
#line 6610 "./marpa.w"
r->t_obs= marpa_obs_init;
/*:616*/
#line 6011 "./marpa.w"

/*554:*/
#line 6020 "./marpa.w"

r->t_ref_count= 1;

/*:554*//*559:*/
#line 6071 "./marpa.w"

{
G_of_R(r)= g;
grammar_ref(g);
}
/*:559*//*564:*/
#line 6090 "./marpa.w"

Input_Phase_of_R(r)= R_BEFORE_INPUT;

/*:564*//*566:*/
#line 6100 "./marpa.w"

r->t_first_earley_set= NULL;
r->t_latest_earley_set= NULL;
r->t_current_earleme= -1;

/*:566*//*570:*/
#line 6134 "./marpa.w"

r->t_earley_item_warning_threshold= 
MAX(DEFAULT_YIM_WARNING_THRESHOLD,AHM_Count_of_G(g)*3);
/*:570*//*574:*/
#line 6163 "./marpa.w"
r->t_furthest_earleme= 0;
/*:574*//*581:*/
#line 6205 "./marpa.w"

r->t_bv_nsyid_is_expected= bv_obs_create(r->t_obs,nsy_count);
/*:581*//*585:*/
#line 6282 "./marpa.w"

r->t_nsy_expected_is_event= lbv_obs_new0(r->t_obs,nsy_count);
/*:585*//*603:*/
#line 6525 "./marpa.w"

r->t_use_leo_flag= 1;
r->t_is_using_leo= 0;
/*:603*//*607:*/
#line 6558 "./marpa.w"

r->t_bv_irl_seen= bv_obs_create(r->t_obs,irl_count);
MARPA_DSTACK_INIT2(r->t_irl_cil_stack,CIL);
/*:607*//*610:*/
#line 6575 "./marpa.w"
r->t_is_exhausted= 0;
/*:610*//*614:*/
#line 6603 "./marpa.w"
r->t_first_inconsistent_ys= -1;

/*:614*//*620:*/
#line 6632 "./marpa.w"

{
ZWAID zwaid;
const int zwa_count= ZWA_Count_of_R(r);
(r)->t_zwas= marpa_obs_new(r->t_obs,ZWA_Object,ZWA_Count_of_R(r));
for(zwaid= 0;zwaid<zwa_count;zwaid++){
const GZWA gzwa= GZWA_by_ID(zwaid);
const ZWA zwa= RZWA_by_ID(zwaid);
ID_of_ZWA(zwa)= ID_of_GZWA(gzwa);
Default_Value_of_ZWA(zwa)= Default_Value_of_GZWA(gzwa);
Memo_Value_of_ZWA(zwa)= Default_Value_of_GZWA(gzwa);
Memo_YSID_of_ZWA(zwa)= -1;
}
}

/*:620*//*635:*/
#line 6726 "./marpa.w"

r->t_earley_set_count= 0;

/*:635*//*701:*/
#line 7526 "./marpa.w"

MARPA_DSTACK_INIT2(r->t_alternatives,ALT_Object);
/*:701*//*726:*/
#line 8024 "./marpa.w"
MARPA_DSTACK_SAFE(r->t_yim_work_stack);
/*:726*//*730:*/
#line 8039 "./marpa.w"
MARPA_DSTACK_SAFE(r->t_completion_stack);
/*:730*//*734:*/
#line 8050 "./marpa.w"
MARPA_DSTACK_SAFE(r->t_earley_set_stack);
/*:734*//*825:*/
#line 9583 "./marpa.w"

r->t_current_report_item= &progress_report_not_ready;
r->t_progress_report_traverser= NULL;
/*:825*//*859:*/
#line 9976 "./marpa.w"

ur_node_stack_init(URS_of_R(r));
/*:859*//*1241:*/
#line 14867 "./marpa.w"

r->t_trace_earley_set= NULL;

/*:1241*//*1248:*/
#line 14943 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:1248*//*1262:*/
#line 15143 "./marpa.w"

r->t_trace_pim_nsy_p= NULL;
r->t_trace_postdot_item= NULL;
/*:1262*//*1270:*/
#line 15293 "./marpa.w"

r->t_trace_source_link= NULL;
r->t_trace_source_type= NO_SOURCE;

/*:1270*/
#line 6012 "./marpa.w"

/*1190:*/
#line 14399 "./marpa.w"

{
if(G_is_Trivial(g)){
psar_safe(Dot_PSAR_of_R(r));
}else{
psar_init(Dot_PSAR_of_R(r),AHM_Count_of_G(g));
}
}
/*:1190*/
#line 6013 "./marpa.w"

/*579:*/
#line 6185 "./marpa.w"

{
NSYID xsy_count= XSY_Count_of_G(g);
r->t_lbv_xsyid_completion_event_is_active= 
lbv_clone(r->t_obs,g->t_lbv_xsyid_completion_event_starts_active,xsy_count);
r->t_lbv_xsyid_nulled_event_is_active= 
lbv_clone(r->t_obs,g->t_lbv_xsyid_nulled_event_starts_active,xsy_count);
r->t_lbv_xsyid_prediction_event_is_active= 
lbv_clone(r->t_obs,g->t_lbv_xsyid_prediction_event_starts_active,xsy_count);
r->t_active_event_count= 
bv_count(g->t_lbv_xsyid_is_completion_event)
+bv_count(g->t_lbv_xsyid_is_nulled_event)
+bv_count(g->t_lbv_xsyid_is_prediction_event);
}

/*:579*/
#line 6014 "./marpa.w"

return r;
}

/*:551*//*555:*/
#line 6024 "./marpa.w"

PRIVATE void
recce_unref(RECCE r)
{
MARPA_ASSERT(r->t_ref_count> 0)
r->t_ref_count--;
if(r->t_ref_count<=0)
{
recce_free(r);
}
}
void
marpa_r_unref(Marpa_Recognizer r)
{
recce_unref(r);
}

/*:555*//*556:*/
#line 6042 "./marpa.w"

PRIVATE
RECCE recce_ref(RECCE r)
{
MARPA_ASSERT(r->t_ref_count> 0)
r->t_ref_count++;
return r;
}
Marpa_Recognizer
marpa_r_ref(Marpa_Recognizer r)
{
return recce_ref(r);
}

/*:556*//*557:*/
#line 6056 "./marpa.w"

PRIVATE
void recce_free(struct marpa_r*r)
{
/*560:*/
#line 6076 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:560*/
#line 6060 "./marpa.w"

/*561:*/
#line 6078 "./marpa.w"
grammar_unref(g);

/*:561*//*608:*/
#line 6561 "./marpa.w"

MARPA_DSTACK_DESTROY(r->t_irl_cil_stack);

/*:608*//*702:*/
#line 7528 "./marpa.w"
MARPA_DSTACK_DESTROY(r->t_alternatives);

/*:702*//*728:*/
#line 8032 "./marpa.w"
MARPA_DSTACK_DESTROY(r->t_yim_work_stack);

/*:728*//*732:*/
#line 8047 "./marpa.w"
MARPA_DSTACK_DESTROY(r->t_completion_stack);

/*:732*//*735:*/
#line 8051 "./marpa.w"
MARPA_DSTACK_DESTROY(r->t_earley_set_stack);

/*:735*//*827:*/
#line 9592 "./marpa.w"

/*826:*/
#line 9586 "./marpa.w"

r->t_current_report_item= &progress_report_not_ready;
if(r->t_progress_report_traverser){
_marpa_avl_destroy(MARPA_TREE_OF_AVL_TRAV(r->t_progress_report_traverser));
}
r->t_progress_report_traverser= NULL;
/*:826*/
#line 9593 "./marpa.w"
;
/*:827*//*860:*/
#line 9978 "./marpa.w"

ur_node_stack_destroy(URS_of_R(r));

/*:860*//*1191:*/
#line 14407 "./marpa.w"

psar_destroy(Dot_PSAR_of_R(r));
/*:1191*/
#line 6061 "./marpa.w"

/*617:*/
#line 6611 "./marpa.w"
marpa_obs_free(r->t_obs);

/*:617*/
#line 6062 "./marpa.w"

my_free(r);
}

/*:557*//*567:*/
#line 6108 "./marpa.w"

Marpa_Earleme marpa_r_current_earleme(Marpa_Recognizer r)
{
/*560:*/
#line 6076 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:560*/
#line 6111 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return-1;
}
return Current_Earleme_of_R(r);
}

/*:567*//*568:*/
#line 6123 "./marpa.w"

PRIVATE YS ys_at_current_earleme(RECCE r)
{
const YS latest= Latest_YS_of_R(r);
if(Earleme_of_YS(latest)==Current_Earleme_of_R(r))return latest;
return NULL;
}

/*:568*//*571:*/
#line 6137 "./marpa.w"

int
marpa_r_earley_item_warning_threshold(Marpa_Recognizer r)
{
return r->t_earley_item_warning_threshold;
}

/*:571*//*572:*/
#line 6146 "./marpa.w"

int
marpa_r_earley_item_warning_threshold_set(Marpa_Recognizer r,int threshold)
{
const int new_threshold= threshold<=0?YIM_FATAL_THRESHOLD:threshold;
r->t_earley_item_warning_threshold= new_threshold;
return new_threshold;
}

/*:572*//*575:*/
#line 6164 "./marpa.w"

unsigned int marpa_r_furthest_earleme(Marpa_Recognizer r)
{return(unsigned int)Furthest_Earleme_of_R(r);}

/*:575*//*582:*/
#line 6213 "./marpa.w"

int marpa_r_terminals_expected(Marpa_Recognizer r,Marpa_Symbol_ID*buffer)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 6216 "./marpa.w"

/*560:*/
#line 6076 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:560*/
#line 6217 "./marpa.w"

NSYID xsy_count;
Bit_Vector bv_terminals;
int min,max,start;
int next_buffer_ix= 0;

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 6223 "./marpa.w"

/*1226:*/
#line 14698 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1226*/
#line 6224 "./marpa.w"


xsy_count= XSY_Count_of_G(g);
bv_terminals= bv_create(xsy_count);
for(start= 0;bv_scan(r->t_bv_nsyid_is_expected,start,&min,&max);
start= max+2)
{
NSYID nsyid;
for(nsyid= min;nsyid<=max;nsyid++)
{
const XSY xsy= Source_XSY_of_NSYID(nsyid);
bv_bit_set(bv_terminals,ID_of_XSY(xsy));
}
}

for(start= 0;bv_scan(bv_terminals,start,&min,&max);start= max+2)
{
XSYID xsyid;
for(xsyid= min;xsyid<=max;xsyid++)
{
buffer[next_buffer_ix++]= xsyid;
}
}
bv_free(bv_terminals);
return next_buffer_ix;
}

/*:582*//*583:*/
#line 6251 "./marpa.w"

int marpa_r_terminal_is_expected(Marpa_Recognizer r,
Marpa_Symbol_ID xsy_id)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 6255 "./marpa.w"

/*560:*/
#line 6076 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:560*/
#line 6256 "./marpa.w"

XSY xsy;
NSY nsy;
/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 6259 "./marpa.w"

/*1226:*/
#line 14698 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1226*/
#line 6260 "./marpa.w"

/*1212:*/
#line 14605 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1212*/
#line 6261 "./marpa.w"

/*1214:*/
#line 14617 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return failure_indicator;
}

/*:1214*/
#line 6262 "./marpa.w"

xsy= XSY_by_ID(xsy_id);
if(_MARPA_UNLIKELY(!XSY_is_Terminal(xsy))){
return 0;
}
nsy= NSY_of_XSY(xsy);
if(_MARPA_UNLIKELY(!nsy))return 0;
return bv_bit_test(r->t_bv_nsyid_is_expected,ID_of_NSY(nsy));
}

/*:583*//*586:*/
#line 6285 "./marpa.w"

int
marpa_r_expected_symbol_event_set(Marpa_Recognizer r,Marpa_Symbol_ID xsy_id,
int value)
{
XSY xsy;
NSY nsy;
NSYID nsyid;
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 6293 "./marpa.w"

/*560:*/
#line 6076 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:560*/
#line 6294 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 6295 "./marpa.w"

/*1212:*/
#line 14605 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1212*/
#line 6296 "./marpa.w"

/*1213:*/
#line 14612 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1213*/
#line 6297 "./marpa.w"

if(_MARPA_UNLIKELY(value<0||value> 1))
{
MARPA_ERROR(MARPA_ERR_INVALID_BOOLEAN);
return failure_indicator;
}
xsy= XSY_by_ID(xsy_id);
if(_MARPA_UNLIKELY(XSY_is_Nulling(xsy))){
MARPA_ERROR(MARPA_ERR_SYMBOL_IS_NULLING);
return-2;
}
nsy= NSY_of_XSY(xsy);
if(_MARPA_UNLIKELY(!nsy)){
MARPA_ERROR(MARPA_ERR_SYMBOL_IS_UNUSED);
return-2;
}
nsyid= ID_of_NSY(nsy);
if(value){
lbv_bit_set(r->t_nsy_expected_is_event,nsyid);
}else{
lbv_bit_clear(r->t_nsy_expected_is_event,nsyid);
}
return value;
}

/*:586*//*588:*/
#line 6336 "./marpa.w"

int
marpa_r_completion_symbol_activate(Marpa_Recognizer r,
Marpa_Symbol_ID xsy_id,int reactivate)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 6341 "./marpa.w"

/*560:*/
#line 6076 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:560*/
#line 6342 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 6343 "./marpa.w"

/*1212:*/
#line 14605 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1212*/
#line 6344 "./marpa.w"

/*1213:*/
#line 14612 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1213*/
#line 6345 "./marpa.w"

switch(reactivate){
case 0:
if(lbv_bit_test(r->t_lbv_xsyid_completion_event_is_active,xsy_id)){
lbv_bit_clear(r->t_lbv_xsyid_completion_event_is_active,xsy_id);
r->t_active_event_count--;
}
return 0;
case 1:
if(!lbv_bit_test(g->t_lbv_xsyid_is_completion_event,xsy_id)){


MARPA_ERROR(MARPA_ERR_SYMBOL_IS_NOT_COMPLETION_EVENT);
}
if(!lbv_bit_test(r->t_lbv_xsyid_completion_event_is_active,xsy_id)){
lbv_bit_set(r->t_lbv_xsyid_completion_event_is_active,xsy_id);
r->t_active_event_count++;
}
return 1;
}
MARPA_ERROR(MARPA_ERR_INVALID_BOOLEAN);
return failure_indicator;
}

/*:588*//*590:*/
#line 6383 "./marpa.w"

int
marpa_r_nulled_symbol_activate(Marpa_Recognizer r,Marpa_Symbol_ID xsy_id,
int reactivate)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 6388 "./marpa.w"

/*560:*/
#line 6076 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:560*/
#line 6389 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 6390 "./marpa.w"

/*1212:*/
#line 14605 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1212*/
#line 6391 "./marpa.w"

/*1213:*/
#line 14612 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1213*/
#line 6392 "./marpa.w"

switch(reactivate){
case 0:
if(lbv_bit_test(r->t_lbv_xsyid_nulled_event_is_active,xsy_id)){
lbv_bit_clear(r->t_lbv_xsyid_nulled_event_is_active,xsy_id);
r->t_active_event_count--;
}
return 0;
case 1:
if(!lbv_bit_test(g->t_lbv_xsyid_is_nulled_event,xsy_id)){


MARPA_ERROR(MARPA_ERR_SYMBOL_IS_NOT_NULLED_EVENT);
}
if(!lbv_bit_test(r->t_lbv_xsyid_nulled_event_is_active,xsy_id)){
lbv_bit_set(r->t_lbv_xsyid_nulled_event_is_active,xsy_id);
r->t_active_event_count++;
}
return 1;
}
MARPA_ERROR(MARPA_ERR_INVALID_BOOLEAN);
return failure_indicator;
}

/*:590*//*592:*/
#line 6430 "./marpa.w"

int
marpa_r_prediction_symbol_activate(Marpa_Recognizer r,
Marpa_Symbol_ID xsy_id,int reactivate)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 6435 "./marpa.w"

/*560:*/
#line 6076 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:560*/
#line 6436 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 6437 "./marpa.w"

/*1212:*/
#line 14605 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1212*/
#line 6438 "./marpa.w"

/*1213:*/
#line 14612 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1213*/
#line 6439 "./marpa.w"

switch(reactivate){
case 0:
if(lbv_bit_test(r->t_lbv_xsyid_prediction_event_is_active,xsy_id)){
lbv_bit_clear(r->t_lbv_xsyid_prediction_event_is_active,xsy_id);
r->t_active_event_count--;
}
return 0;
case 1:
if(!lbv_bit_test(g->t_lbv_xsyid_is_prediction_event,xsy_id)){


MARPA_ERROR(MARPA_ERR_SYMBOL_IS_NOT_PREDICTION_EVENT);
}
if(!lbv_bit_test(r->t_lbv_xsyid_prediction_event_is_active,xsy_id)){
lbv_bit_set(r->t_lbv_xsyid_prediction_event_is_active,xsy_id);
r->t_active_event_count++;
}
return 1;
}
MARPA_ERROR(MARPA_ERR_INVALID_BOOLEAN);
return failure_indicator;
}

/*:592*//*604:*/
#line 6531 "./marpa.w"

int _marpa_r_is_use_leo(Marpa_Recognizer r)
{
/*560:*/
#line 6076 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:560*/
#line 6534 "./marpa.w"

/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 6535 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 6536 "./marpa.w"

return r->t_use_leo_flag;
}
/*:604*//*605:*/
#line 6539 "./marpa.w"

int _marpa_r_is_use_leo_set(
Marpa_Recognizer r,int value)
{
/*560:*/
#line 6076 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:560*/
#line 6543 "./marpa.w"

/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 6544 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 6545 "./marpa.w"

/*1225:*/
#line 14693 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)!=R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_STARTED);
return failure_indicator;
}
/*:1225*/
#line 6546 "./marpa.w"

return r->t_use_leo_flag= value?1:0;
}

/*:605*//*612:*/
#line 6586 "./marpa.w"

int marpa_r_is_exhausted(Marpa_Recognizer r)
{
/*560:*/
#line 6076 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:560*/
#line 6589 "./marpa.w"

/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 6590 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 6591 "./marpa.w"

return R_is_Exhausted(r);
}

/*:612*//*639:*/
#line 6745 "./marpa.w"

int marpa_r_earley_set_value(Marpa_Recognizer r,Marpa_Earley_Set_ID set_id)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 6748 "./marpa.w"

YS earley_set;
/*560:*/
#line 6076 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:560*/
#line 6750 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 6751 "./marpa.w"

/*1226:*/
#line 14698 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1226*/
#line 6752 "./marpa.w"

if(set_id<0)
{
MARPA_ERROR(MARPA_ERR_INVALID_LOCATION);
return failure_indicator;
}
r_update_earley_sets(r);
if(!YS_Ord_is_Valid(r,set_id))
{
MARPA_ERROR(MARPA_ERR_NO_EARLEY_SET_AT_LOCATION);
return failure_indicator;
}
earley_set= YS_of_R_by_Ord(r,set_id);
return Value_of_YS(earley_set);
}

/*:639*//*640:*/
#line 6768 "./marpa.w"

int
marpa_r_earley_set_values(Marpa_Recognizer r,Marpa_Earley_Set_ID set_id,
int*p_value,void**p_pvalue)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 6773 "./marpa.w"

YS earley_set;
/*560:*/
#line 6076 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:560*/
#line 6775 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 6776 "./marpa.w"

/*1226:*/
#line 14698 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1226*/
#line 6777 "./marpa.w"

if(set_id<0)
{
MARPA_ERROR(MARPA_ERR_INVALID_LOCATION);
return failure_indicator;
}
r_update_earley_sets(r);
if(!YS_Ord_is_Valid(r,set_id))
{
MARPA_ERROR(MARPA_ERR_NO_EARLEY_SET_AT_LOCATION);
return failure_indicator;
}
earley_set= YS_of_R_by_Ord(r,set_id);
if(p_value)*p_value= Value_of_YS(earley_set);
if(p_pvalue)*p_pvalue= PValue_of_YS(earley_set);
return 1;
}

/*:640*//*641:*/
#line 6795 "./marpa.w"

int marpa_r_latest_earley_set_value_set(Marpa_Recognizer r,int value)
{
YS earley_set;
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 6799 "./marpa.w"

/*560:*/
#line 6076 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:560*/
#line 6800 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 6801 "./marpa.w"

/*1226:*/
#line 14698 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1226*/
#line 6802 "./marpa.w"

earley_set= Latest_YS_of_R(r);
return Value_of_YS(earley_set)= value;
}

/*:641*//*642:*/
#line 6807 "./marpa.w"

int marpa_r_latest_earley_set_values_set(Marpa_Recognizer r,int value,
void*pvalue)
{
YS earley_set;
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 6812 "./marpa.w"

/*560:*/
#line 6076 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:560*/
#line 6813 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 6814 "./marpa.w"

/*1226:*/
#line 14698 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1226*/
#line 6815 "./marpa.w"

earley_set= Latest_YS_of_R(r);
Value_of_YS(earley_set)= value;
PValue_of_YS(earley_set)= pvalue;
return 1;
}

/*:642*//*643:*/
#line 6823 "./marpa.w"

PRIVATE YS
earley_set_new(RECCE r,JEARLEME id)
{
YSK_Object key;
YS set;
set= marpa_obs_new(r->t_obs,YS_Object,1);
key.t_earleme= id;
set->t_key= key;
set->t_postdot_ary= NULL;
set->t_postdot_sym_count= 0;
YIM_Count_of_YS(set)= 0;
set->t_ordinal= r->t_earley_set_count++;
YIMs_of_YS(set)= NULL;
Next_YS_of_YS(set)= NULL;
/*638:*/
#line 6741 "./marpa.w"

Value_of_YS(set)= -1;
PValue_of_YS(set)= NULL;

/*:638*//*1197:*/
#line 14463 "./marpa.w"

{set->t_dot_psl= NULL;}

/*:1197*/
#line 6838 "./marpa.w"

return set;
}

/*:643*//*653:*/
#line 6947 "./marpa.w"

PRIVATE YIM earley_item_create(const RECCE r,
const YIK_Object key)
{
/*1208:*/
#line 14586 "./marpa.w"
void*const failure_indicator= NULL;
/*:1208*/
#line 6951 "./marpa.w"

/*560:*/
#line 6076 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:560*/
#line 6952 "./marpa.w"

YIM new_item;
YIM*end_of_work_stack;
const YS set= key.t_set;
const int count= ++YIM_Count_of_YS(set);
/*655:*/
#line 7006 "./marpa.w"

if(_MARPA_UNLIKELY(count>=YIM_FATAL_THRESHOLD))
{
MARPA_FATAL(MARPA_ERR_YIM_COUNT);
return failure_indicator;
}

/*:655*/
#line 6957 "./marpa.w"

new_item= marpa_obs_new(r->t_obs,struct s_earley_item,1);
new_item->t_key= key;
new_item->t_source_type= NO_SOURCE;
YIM_is_Rejected(new_item)= 0;
YIM_is_Active(new_item)= 1;
{
SRC unique_yim_src= SRC_of_YIM(new_item);
SRC_is_Rejected(unique_yim_src)= 0;
SRC_is_Active(unique_yim_src)= 1;
}
Ord_of_YIM(new_item)= YIM_ORDINAL_CLAMP((unsigned int)count-1);
end_of_work_stack= WORK_YIM_PUSH(r);
*end_of_work_stack= new_item;
return new_item;
}

/*:653*//*654:*/
#line 6974 "./marpa.w"

PRIVATE YIM
earley_item_assign(const RECCE r,const YS set,const YS origin,
const AHM ahm)
{
const GRAMMAR g= G_of_R(r);
YIK_Object key;
YIM yim;
PSL psl;
AHMID ahm_id= ID_of_AHM(ahm);
PSL*psl_owner= &Dot_PSL_of_YS(origin);
if(!*psl_owner)
{
psl_claim(psl_owner,Dot_PSAR_of_R(r));
}
psl= *psl_owner;
yim= PSL_Datum(psl,ahm_id);
if(yim
&&Earleme_of_YIM(yim)==Earleme_of_YS(set)
&&Earleme_of_YS(Origin_of_YIM(yim))==Earleme_of_YS(origin))
{
return yim;
}
key.t_origin= origin;
key.t_ahm= ahm;
key.t_set= set;
yim= earley_item_create(r,key);
PSL_Datum(psl,ahm_id)= yim;
return yim;
}

/*:654*//*659:*/
#line 7042 "./marpa.w"

PRIVATE_NOT_INLINE Marpa_Error_Code invalid_source_type_code(unsigned int type)
{
switch(type){
case NO_SOURCE:
return MARPA_ERR_SOURCE_TYPE_IS_NONE;
case SOURCE_IS_TOKEN:
return MARPA_ERR_SOURCE_TYPE_IS_TOKEN;
case SOURCE_IS_COMPLETION:
return MARPA_ERR_SOURCE_TYPE_IS_COMPLETION;
case SOURCE_IS_LEO:
return MARPA_ERR_SOURCE_TYPE_IS_LEO;
case SOURCE_IS_AMBIGUOUS:
return MARPA_ERR_SOURCE_TYPE_IS_AMBIGUOUS;
}
return MARPA_ERR_SOURCE_TYPE_IS_UNKNOWN;
}

/*:659*//*671:*/
#line 7163 "./marpa.w"

PRIVATE PIM*
pim_nsy_p_find(YS set,NSYID nsyid)
{
int lo= 0;
int hi= Postdot_SYM_Count_of_YS(set)-1;
PIM*postdot_array= set->t_postdot_ary;
while(hi>=lo){
int trial= lo+(hi-lo)/2;
PIM trial_pim= postdot_array[trial];
NSYID trial_nsyid= Postdot_NSYID_of_PIM(trial_pim);
if(trial_nsyid==nsyid)return postdot_array+trial;
if(trial_nsyid<nsyid){
lo= trial+1;
}else{
hi= trial-1;
}
}
return NULL;
}
/*:671*//*672:*/
#line 7183 "./marpa.w"

PRIVATE PIM first_pim_of_ys_by_nsyid(YS set,NSYID nsyid)
{
PIM*pim_nsy_p= pim_nsy_p_find(set,nsyid);
return pim_nsy_p?*pim_nsy_p:NULL;
}

/*:672*//*689:*/
#line 7338 "./marpa.w"

PRIVATE
SRCL unique_srcl_new(struct marpa_obstack*t_obs)
{
const SRCL new_srcl= marpa_obs_new(t_obs,SRCL_Object,1);
SRCL_is_Rejected(new_srcl)= 0;
SRCL_is_Active(new_srcl)= 1;
return new_srcl;
}

/*:689*//*690:*/
#line 7348 "./marpa.w"
PRIVATE
void
tkn_link_add(RECCE r,
YIM item,
YIM predecessor,
ALT alternative)
{
SRCL new_link;
unsigned int previous_source_type= Source_Type_of_YIM(item);
if(previous_source_type==NO_SOURCE)
{
const SRCL source_link= SRCL_of_YIM(item);
Source_Type_of_YIM(item)= SOURCE_IS_TOKEN;
Predecessor_of_SRCL(source_link)= predecessor;
NSYID_of_SRCL(source_link)= NSYID_of_ALT(alternative);
Value_of_SRCL(source_link)= Value_of_ALT(alternative);
Next_SRCL_of_SRCL(source_link)= NULL;
return;
}
if(previous_source_type!=SOURCE_IS_AMBIGUOUS)
{
earley_item_ambiguate(r,item);
}
new_link= unique_srcl_new(r->t_obs);
new_link->t_next= LV_First_Token_SRCL_of_YIM(item);
new_link->t_source.t_predecessor= predecessor;
NSYID_of_Source(new_link->t_source)= NSYID_of_ALT(alternative);
Value_of_Source(new_link->t_source)= Value_of_ALT(alternative);
LV_First_Token_SRCL_of_YIM(item)= new_link;
}

/*:690*//*691:*/
#line 7379 "./marpa.w"

PRIVATE
void
completion_link_add(RECCE r,
YIM item,
YIM predecessor,
YIM cause)
{
SRCL new_link;
unsigned int previous_source_type= Source_Type_of_YIM(item);
if(previous_source_type==NO_SOURCE)
{
const SRCL source_link= SRCL_of_YIM(item);
Source_Type_of_YIM(item)= SOURCE_IS_COMPLETION;
Predecessor_of_SRCL(source_link)= predecessor;
Cause_of_SRCL(source_link)= cause;
Next_SRCL_of_SRCL(source_link)= NULL;
return;
}
if(previous_source_type!=SOURCE_IS_AMBIGUOUS)
{
earley_item_ambiguate(r,item);
}
new_link= unique_srcl_new(r->t_obs);
new_link->t_next= LV_First_Completion_SRCL_of_YIM(item);
new_link->t_source.t_predecessor= predecessor;
Cause_of_Source(new_link->t_source)= cause;
LV_First_Completion_SRCL_of_YIM(item)= new_link;
}

/*:691*//*692:*/
#line 7409 "./marpa.w"

PRIVATE void
leo_link_add(RECCE r,
YIM item,
LIM predecessor,
YIM cause)
{
SRCL new_link;
unsigned int previous_source_type= Source_Type_of_YIM(item);
if(previous_source_type==NO_SOURCE)
{
const SRCL source_link= SRCL_of_YIM(item);
Source_Type_of_YIM(item)= SOURCE_IS_LEO;
Predecessor_of_SRCL(source_link)= predecessor;
Cause_of_SRCL(source_link)= cause;
Next_SRCL_of_SRCL(source_link)= NULL;
return;
}
if(previous_source_type!=SOURCE_IS_AMBIGUOUS)
{
earley_item_ambiguate(r,item);
}
new_link= unique_srcl_new(r->t_obs);
new_link->t_next= LV_First_Leo_SRCL_of_YIM(item);
new_link->t_source.t_predecessor= predecessor;
Cause_of_Source(new_link->t_source)= cause;
LV_First_Leo_SRCL_of_YIM(item)= new_link;
}

/*:692*//*694:*/
#line 7458 "./marpa.w"

PRIVATE_NOT_INLINE
void earley_item_ambiguate(struct marpa_r*r,YIM item)
{
unsigned int previous_source_type= Source_Type_of_YIM(item);
Source_Type_of_YIM(item)= SOURCE_IS_AMBIGUOUS;
switch(previous_source_type)
{
case SOURCE_IS_TOKEN:/*695:*/
#line 7475 "./marpa.w"
{
SRCL new_link= marpa_obs_new(r->t_obs,SRCL_Object,1);
*new_link= *SRCL_of_YIM(item);
LV_First_Leo_SRCL_of_YIM(item)= NULL;
LV_First_Completion_SRCL_of_YIM(item)= NULL;
LV_First_Token_SRCL_of_YIM(item)= new_link;
}

/*:695*/
#line 7466 "./marpa.w"

return;
case SOURCE_IS_COMPLETION:/*696:*/
#line 7483 "./marpa.w"
{
SRCL new_link= marpa_obs_new(r->t_obs,SRCL_Object,1);
*new_link= *SRCL_of_YIM(item);
LV_First_Leo_SRCL_of_YIM(item)= NULL;
LV_First_Completion_SRCL_of_YIM(item)= new_link;
LV_First_Token_SRCL_of_YIM(item)= NULL;
}

/*:696*/
#line 7468 "./marpa.w"

return;
case SOURCE_IS_LEO:/*697:*/
#line 7491 "./marpa.w"
{
SRCL new_link= marpa_obs_new(r->t_obs,SRCL_Object,1);
*new_link= *SRCL_of_YIM(item);
LV_First_Leo_SRCL_of_YIM(item)= new_link;
LV_First_Completion_SRCL_of_YIM(item)= NULL;
LV_First_Token_SRCL_of_YIM(item)= NULL;
}

/*:697*/
#line 7470 "./marpa.w"

return;
}
}

/*:694*//*704:*/
#line 7534 "./marpa.w"

PRIVATE int
alternative_insertion_point(RECCE r,ALT new_alternative)
{
MARPA_DSTACK alternatives= &r->t_alternatives;
ALT alternative;
int hi= MARPA_DSTACK_LENGTH(*alternatives)-1;
int lo= 0;
int trial;

if(hi<0)
return 0;
alternative= MARPA_DSTACK_BASE(*alternatives,ALT_Object);
for(;;)
{
int outcome;
trial= lo+(hi-lo)/2;
outcome= alternative_cmp(new_alternative,alternative+trial);
if(outcome==0)
return-1;
if(outcome> 0)
{
lo= trial+1;
}
else
{
hi= trial-1;
}
if(hi<lo)
return outcome> 0?trial+1:trial;
}
}

/*:704*//*706:*/
#line 7578 "./marpa.w"

PRIVATE int alternative_cmp(const ALT_Const a,const ALT_Const b)
{
int subkey= End_Earleme_of_ALT(b)-End_Earleme_of_ALT(a);
if(subkey)return subkey;
subkey= NSYID_of_ALT(a)-NSYID_of_ALT(b);
if(subkey)return subkey;
return Start_Earleme_of_ALT(a)-Start_Earleme_of_ALT(b);
}

/*:706*//*707:*/
#line 7595 "./marpa.w"

PRIVATE ALT alternative_pop(RECCE r,JEARLEME earleme)
{
MARPA_DSTACK alternatives= &r->t_alternatives;
ALT end_of_stack= MARPA_DSTACK_TOP(*alternatives,ALT_Object);

if(!end_of_stack)return NULL;






if(earleme<End_Earleme_of_ALT(end_of_stack))
return NULL;

return MARPA_DSTACK_POP(*alternatives,ALT_Object);
}

/*:707*//*709:*/
#line 7622 "./marpa.w"

PRIVATE int alternative_insert(RECCE r,ALT new_alternative)
{
ALT end_of_stack,base_of_stack;
MARPA_DSTACK alternatives= &r->t_alternatives;
int ix;
int insertion_point= alternative_insertion_point(r,new_alternative);
if(insertion_point<0)
return insertion_point;


end_of_stack= MARPA_DSTACK_PUSH(*alternatives,ALT_Object);


base_of_stack= MARPA_DSTACK_BASE(*alternatives,ALT_Object);
for(ix= (int)(end_of_stack-base_of_stack);ix> insertion_point;ix--){
base_of_stack[ix]= base_of_stack[ix-1];
}
base_of_stack[insertion_point]= *new_alternative;
return insertion_point;
}

/*:709*//*710:*/
#line 7645 "./marpa.w"
int marpa_r_start_input(Marpa_Recognizer r)
{
int return_value= 1;
YS set0;
YIK_Object key;

IRL start_irl;
AHM start_ahm;

/*560:*/
#line 6076 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:560*/
#line 7654 "./marpa.w"

/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 7655 "./marpa.w"


/*1225:*/
#line 14693 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)!=R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_STARTED);
return failure_indicator;
}
/*:1225*/
#line 7657 "./marpa.w"

{
/*712:*/
#line 7775 "./marpa.w"

const NSYID nsy_count= NSY_Count_of_G(g);
const NSYID xsy_count= XSY_Count_of_G(g);
Bit_Vector bv_ok_for_chain= bv_create(nsy_count);
/*:712*/
#line 7659 "./marpa.w"

Current_Earleme_of_R(r)= 0;
/*718:*/
#line 7817 "./marpa.w"

{
XSYID xsy_id;
r->t_valued_terminal= lbv_obs_new0(r->t_obs,xsy_count);
r->t_unvalued_terminal= lbv_obs_new0(r->t_obs,xsy_count);
r->t_valued= lbv_obs_new0(r->t_obs,xsy_count);
r->t_unvalued= lbv_obs_new0(r->t_obs,xsy_count);
r->t_valued_locked= lbv_obs_new0(r->t_obs,xsy_count);
for(xsy_id= 0;xsy_id<xsy_count;xsy_id++)
{
const XSY xsy= XSY_by_ID(xsy_id);
if(XSY_is_Valued_Locked(xsy))
{
lbv_bit_set(r->t_valued_locked,xsy_id);
}
if(XSY_is_Valued(xsy))
{
lbv_bit_set(r->t_valued,xsy_id);
if(XSY_is_Terminal(xsy))
{
lbv_bit_set(r->t_valued_terminal,xsy_id);
}
}
else
{
lbv_bit_set(r->t_unvalued,xsy_id);
if(XSY_is_Terminal(xsy))
{
lbv_bit_set(r->t_unvalued_terminal,xsy_id);
}
}
}
}

/*:718*/
#line 7661 "./marpa.w"

G_EVENTS_CLEAR(g);

set0= earley_set_new(r,0);
Latest_YS_of_R(r)= set0;
First_YS_of_R(r)= set0;

if(G_is_Trivial(g)){
return_value+= trigger_trivial_events(r);
/*611:*/
#line 6576 "./marpa.w"

{
R_is_Exhausted(r)= 1;
Input_Phase_of_R(r)= R_AFTER_INPUT;
event_new(g,MARPA_EVENT_EXHAUSTED);
}

/*:611*/
#line 7670 "./marpa.w"

goto CLEANUP;
}
Input_Phase_of_R(r)= R_DURING_INPUT;
psar_reset(Dot_PSAR_of_R(r));
/*771:*/
#line 8683 "./marpa.w"

r->t_bv_lim_symbols= bv_obs_create(r->t_obs,nsy_count);
r->t_bv_pim_symbols= bv_obs_create(r->t_obs,nsy_count);
r->t_pim_workarea= marpa_obs_new(r->t_obs,void*,nsy_count);
/*:771*//*790:*/
#line 8965 "./marpa.w"

r->t_lim_chain= marpa_obs_new(r->t_obs,void*,2*nsy_count);
/*:790*/
#line 7675 "./marpa.w"

/*727:*/
#line 8025 "./marpa.w"

{
if(!MARPA_DSTACK_IS_INITIALIZED(r->t_yim_work_stack))
{
MARPA_DSTACK_INIT2(r->t_yim_work_stack,YIM);
}
}
/*:727*//*731:*/
#line 8040 "./marpa.w"

{
if(!MARPA_DSTACK_IS_INITIALIZED(r->t_completion_stack))
{
MARPA_DSTACK_INIT2(r->t_completion_stack,YIM);
}
}
/*:731*/
#line 7676 "./marpa.w"


start_irl= g->t_start_irl;
start_ahm= First_AHM_of_IRL(start_irl);



key.t_origin= set0;
key.t_set= set0;

key.t_ahm= start_ahm;
earley_item_create(r,key);

bv_clear(r->t_bv_irl_seen);
bv_bit_set(r->t_bv_irl_seen,ID_of_IRL(start_irl));
MARPA_DSTACK_CLEAR(r->t_irl_cil_stack);
*MARPA_DSTACK_PUSH(r->t_irl_cil_stack,CIL)= LHS_CIL_of_AHM(start_ahm);

while(1)
{
const CIL*const p_cil= MARPA_DSTACK_POP(r->t_irl_cil_stack,CIL);
if(!p_cil)
break;
{
int cil_ix;
const CIL this_cil= *p_cil;
const int prediction_count= Count_of_CIL(this_cil);
for(cil_ix= 0;cil_ix<prediction_count;cil_ix++)
{
const IRLID prediction_irlid= Item_of_CIL(this_cil,cil_ix);
if(!bv_bit_test_then_set(r->t_bv_irl_seen,prediction_irlid))
{
const IRL prediction_irl= IRL_by_ID(prediction_irlid);
const AHM prediction_ahm= First_AHM_of_IRL(prediction_irl);



if(!evaluate_zwas(r,0,prediction_ahm))continue;
key.t_ahm= prediction_ahm;
earley_item_create(r,key);
*MARPA_DSTACK_PUSH(r->t_irl_cil_stack,CIL)
= LHS_CIL_of_AHM(prediction_ahm);
}
}
}
}

postdot_items_create(r,bv_ok_for_chain,set0);
earley_set_update_items(r,set0);
r->t_is_using_leo= r->t_use_leo_flag;
trigger_events(r);
CLEANUP:;
/*713:*/
#line 7779 "./marpa.w"

bv_free(bv_ok_for_chain);

/*:713*/
#line 7728 "./marpa.w"

}
return return_value;
}

/*:710*//*711:*/
#line 7733 "./marpa.w"

PRIVATE
int evaluate_zwas(RECCE r,YSID ysid,AHM ahm)
{
int cil_ix;
const CIL zwa_cil= ZWA_CIL_of_AHM(ahm);
const int cil_count= Count_of_CIL(zwa_cil);
for(cil_ix= 0;cil_ix<cil_count;cil_ix++)
{
int value;
const ZWAID zwaid= Item_of_CIL(zwa_cil,cil_ix);
const ZWA zwa= RZWA_by_ID(zwaid);


MARPA_OFF_DEBUG3("At %s, evaluating assertion %ld",STRLOC,(long)zwaid);
if(Memo_YSID_of_ZWA(zwa)==ysid){
if(Memo_Value_of_ZWA(zwa))continue;
MARPA_OFF_DEBUG3("At %s: returning 0 for assertion %ld",STRLOC,(long)zwaid);
return 0;
}




value= Memo_Value_of_ZWA(zwa)= Default_Value_of_ZWA(zwa);
Memo_YSID_of_ZWA(zwa)= ysid;





if(!value){
MARPA_OFF_DEBUG3("At %s: returning 0 for assertion %ld",STRLOC,(long)zwaid);
return 0;
}

MARPA_OFF_DEBUG3("At %s: value is 1 for assertion %ld",STRLOC,(long)zwaid);
}
return 1;
}


/*:711*//*719:*/
#line 7857 "./marpa.w"

Marpa_Earleme marpa_r_alternative(
Marpa_Recognizer r,
Marpa_Symbol_ID tkn_xsy_id,
int value,
int length)
{
/*560:*/
#line 6076 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:560*/
#line 7864 "./marpa.w"

YS current_earley_set;
const JEARLEME current_earleme= Current_Earleme_of_R(r);
JEARLEME target_earleme;
NSYID tkn_nsyid;
if(_MARPA_UNLIKELY(!R_is_Consistent(r)))
{
MARPA_ERROR(MARPA_ERR_RECCE_IS_INCONSISTENT);
return MARPA_ERR_RECCE_IS_INCONSISTENT;
}
if(_MARPA_UNLIKELY(Input_Phase_of_R(r)!=R_DURING_INPUT))
{
MARPA_ERROR(MARPA_ERR_RECCE_NOT_ACCEPTING_INPUT);
return MARPA_ERR_RECCE_NOT_ACCEPTING_INPUT;
}
if(_MARPA_UNLIKELY(XSYID_is_Malformed(tkn_xsy_id)))
{
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return MARPA_ERR_INVALID_SYMBOL_ID;
}
if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(tkn_xsy_id)))
{
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return MARPA_ERR_NO_SUCH_SYMBOL_ID;
}
/*720:*/
#line 7896 "./marpa.w"
{
const XSY_Const tkn= XSY_by_ID(tkn_xsy_id);
if(length<=0){
MARPA_ERROR(MARPA_ERR_TOKEN_LENGTH_LE_ZERO);
return MARPA_ERR_TOKEN_LENGTH_LE_ZERO;
}
if(length>=JEARLEME_THRESHOLD){
MARPA_ERROR(MARPA_ERR_TOKEN_TOO_LONG);
return MARPA_ERR_TOKEN_TOO_LONG;
}
if(value&&_MARPA_UNLIKELY(!lbv_bit_test(r->t_valued_terminal,tkn_xsy_id)))
{
if(!XSY_is_Terminal(tkn)){
MARPA_ERROR(MARPA_ERR_TOKEN_IS_NOT_TERMINAL);
return MARPA_ERR_TOKEN_IS_NOT_TERMINAL;
}
if(lbv_bit_test(r->t_valued_locked,tkn_xsy_id)){
MARPA_ERROR(MARPA_ERR_SYMBOL_VALUED_CONFLICT);
return MARPA_ERR_SYMBOL_VALUED_CONFLICT;
}
lbv_bit_set(r->t_valued_locked,tkn_xsy_id);
lbv_bit_set(r->t_valued_terminal,tkn_xsy_id);
lbv_bit_set(r->t_valued,tkn_xsy_id);
}
if(!value&&_MARPA_UNLIKELY(!lbv_bit_test(r->t_unvalued_terminal,tkn_xsy_id)))
{
if(!XSY_is_Terminal(tkn)){
MARPA_ERROR(MARPA_ERR_TOKEN_IS_NOT_TERMINAL);
return MARPA_ERR_TOKEN_IS_NOT_TERMINAL;
}
if(lbv_bit_test(r->t_valued_locked,tkn_xsy_id)){
MARPA_ERROR(MARPA_ERR_SYMBOL_VALUED_CONFLICT);
return MARPA_ERR_SYMBOL_VALUED_CONFLICT;
}
lbv_bit_set(r->t_valued_locked,tkn_xsy_id);
lbv_bit_set(r->t_unvalued_terminal,tkn_xsy_id);
lbv_bit_set(r->t_unvalued,tkn_xsy_id);
}
}

/*:720*/
#line 7889 "./marpa.w"

/*723:*/
#line 7956 "./marpa.w"

{
NSY tkn_nsy= NSY_by_XSYID(tkn_xsy_id);
if(_MARPA_UNLIKELY(!tkn_nsy))
{
MARPA_ERROR(MARPA_ERR_INACCESSIBLE_TOKEN);
return MARPA_ERR_INACCESSIBLE_TOKEN;
}
tkn_nsyid= ID_of_NSY(tkn_nsy);
current_earley_set= YS_at_Current_Earleme_of_R(r);
if(!current_earley_set)
{
MARPA_ERROR(MARPA_ERR_NO_TOKEN_EXPECTED_HERE);
return MARPA_ERR_NO_TOKEN_EXPECTED_HERE;
}
if(!First_PIM_of_YS_by_NSYID(current_earley_set,tkn_nsyid))
{
MARPA_ERROR(MARPA_ERR_UNEXPECTED_TOKEN_ID);
return MARPA_ERR_UNEXPECTED_TOKEN_ID;
}
}

/*:723*/
#line 7890 "./marpa.w"

/*721:*/
#line 7936 "./marpa.w"
{
target_earleme= current_earleme+length;
if(target_earleme>=JEARLEME_THRESHOLD){
MARPA_ERROR(MARPA_ERR_PARSE_TOO_LONG);
return MARPA_ERR_PARSE_TOO_LONG;
}
}

/*:721*/
#line 7891 "./marpa.w"

/*724:*/
#line 7994 "./marpa.w"

{
ALT_Object alternative_object;


const ALT alternative= &alternative_object;
NSYID_of_ALT(alternative)= tkn_nsyid;
Value_of_ALT(alternative)= value;
ALT_is_Valued(alternative)= value?1:0;
if(Furthest_Earleme_of_R(r)<target_earleme)
Furthest_Earleme_of_R(r)= target_earleme;
alternative->t_start_earley_set= current_earley_set;
End_Earleme_of_ALT(alternative)= target_earleme;
if(alternative_insert(r,alternative)<0)
{
MARPA_ERROR(MARPA_ERR_DUPLICATE_TOKEN);
return MARPA_ERR_DUPLICATE_TOKEN;
}
}

/*:724*/
#line 7892 "./marpa.w"

return MARPA_ERR_NONE;
}

/*:719*//*737:*/
#line 8071 "./marpa.w"

int
marpa_r_earleme_complete(Marpa_Recognizer r)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 8075 "./marpa.w"

/*560:*/
#line 6076 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:560*/
#line 8076 "./marpa.w"

YIM*cause_p;
YS current_earley_set;
JEARLEME current_earleme;





JEARLEME return_value= -2;

/*1227:*/
#line 14703 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)!=R_DURING_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_ACCEPTING_INPUT);
return failure_indicator;
}

if(_MARPA_UNLIKELY(!R_is_Consistent(r))){
MARPA_ERROR(MARPA_ERR_RECCE_IS_INCONSISTENT);
return failure_indicator;
}

/*:1227*/
#line 8087 "./marpa.w"

if(_MARPA_UNLIKELY(!R_is_Consistent(r))){
MARPA_ERROR(MARPA_ERR_RECCE_IS_INCONSISTENT);
return failure_indicator;
}

{
int count_of_expected_terminals;
/*738:*/
#line 8137 "./marpa.w"

const NSYID nsy_count= NSY_Count_of_G(g);
Bit_Vector bv_ok_for_chain= bv_create(nsy_count);
struct marpa_obstack*const earleme_complete_obs= marpa_obs_init;
/*:738*/
#line 8095 "./marpa.w"

G_EVENTS_CLEAR(g);
psar_dealloc(Dot_PSAR_of_R(r));
bv_clear(r->t_bv_nsyid_is_expected);
bv_clear(r->t_bv_irl_seen);
/*740:*/
#line 8145 "./marpa.w"
{
current_earleme= ++(Current_Earleme_of_R(r));
if(current_earleme> Furthest_Earleme_of_R(r))
{
/*611:*/
#line 6576 "./marpa.w"

{
R_is_Exhausted(r)= 1;
Input_Phase_of_R(r)= R_AFTER_INPUT;
event_new(g,MARPA_EVENT_EXHAUSTED);
}

/*:611*/
#line 8149 "./marpa.w"

MARPA_ERROR(MARPA_ERR_PARSE_EXHAUSTED);
return_value= failure_indicator;
goto CLEANUP;
}
}

/*:740*/
#line 8100 "./marpa.w"

/*742:*/
#line 8168 "./marpa.w"
{
ALT end_of_stack= MARPA_DSTACK_TOP(r->t_alternatives,ALT_Object);
if(!end_of_stack||current_earleme!=End_Earleme_of_ALT(end_of_stack))
{
return_value= 0;
goto CLEANUP;
}
}

/*:742*/
#line 8101 "./marpa.w"

/*741:*/
#line 8158 "./marpa.w"
{
current_earley_set= earley_set_new(r,current_earleme);
Next_YS_of_YS(Latest_YS_of_R(r))= current_earley_set;
Latest_YS_of_R(r)= current_earley_set;
}

/*:741*/
#line 8102 "./marpa.w"

/*743:*/
#line 8177 "./marpa.w"

{
ALT alternative;


while((alternative= alternative_pop(r,current_earleme)))
/*745:*/
#line 8196 "./marpa.w"

{
YS start_earley_set= Start_YS_of_ALT(alternative);
PIM pim= First_PIM_of_YS_by_NSYID(start_earley_set,
NSYID_of_ALT(alternative));
for(;pim;pim= Next_PIM_of_PIM(pim))
{


const YIM predecessor= YIM_of_PIM(pim);
if(predecessor&&YIM_is_Active(predecessor))
{
const AHM predecessor_ahm= AHM_of_YIM(predecessor);
const AHM scanned_ahm= Next_AHM_of_AHM(predecessor_ahm);
/*746:*/
#line 8215 "./marpa.w"

{
const YIM scanned_earley_item= earley_item_assign(r,
current_earley_set,
Origin_of_YIM
(predecessor),
scanned_ahm);
YIM_was_Scanned(scanned_earley_item)= 1;
tkn_link_add(r,scanned_earley_item,predecessor,alternative);
}

/*:746*/
#line 8210 "./marpa.w"

}
}
}

/*:745*/
#line 8183 "./marpa.w"

}

/*:743*/
#line 8103 "./marpa.w"

/*747:*/
#line 8231 "./marpa.w"
{


YIM*work_earley_items= MARPA_DSTACK_BASE(r->t_yim_work_stack,YIM);
int no_of_work_earley_items= MARPA_DSTACK_LENGTH(r->t_yim_work_stack);
int ix;
MARPA_DSTACK_CLEAR(r->t_completion_stack);
for(ix= 0;
ix<no_of_work_earley_items;
ix++){
YIM earley_item= work_earley_items[ix];
YIM*end_of_stack;
if(!YIM_is_Completion(earley_item))
continue;
end_of_stack= MARPA_DSTACK_PUSH(r->t_completion_stack,YIM);
*end_of_stack= earley_item;
}
}

/*:747*/
#line 8104 "./marpa.w"

while((cause_p= MARPA_DSTACK_POP(r->t_completion_stack,YIM))){
YIM cause= *cause_p;
/*748:*/
#line 8252 "./marpa.w"

{
if(YIM_is_Active(cause)&&YIM_is_Completion(cause))
{
NSYID complete_nsyid= LHS_NSYID_of_YIM(cause);
const YS middle= Origin_of_YIM(cause);
/*749:*/
#line 8262 "./marpa.w"

{
PIM postdot_item;
for(postdot_item= First_PIM_of_YS_by_NSYID(middle,complete_nsyid);
postdot_item;postdot_item= Next_PIM_of_PIM(postdot_item))
{
const YIM predecessor= YIM_of_PIM(postdot_item);
if(!predecessor){


const LIM leo_item= LIM_of_PIM(postdot_item);








if(!LIM_is_Active(leo_item))goto NEXT_PIM;

/*752:*/
#line 8329 "./marpa.w"
{
const YS origin= Origin_of_LIM(leo_item);
const AHM effect_ahm= Top_AHM_of_LIM(leo_item);
const YIM effect= earley_item_assign(r,current_earley_set,
origin,effect_ahm);
YIM_was_Fusion(effect)= 1;
if(Earley_Item_has_No_Source(effect))
{


/*751:*/
#line 8323 "./marpa.w"
{
YIM*end_of_stack= MARPA_DSTACK_PUSH(r->t_completion_stack,YIM);
*end_of_stack= effect;
}

/*:751*/
#line 8339 "./marpa.w"

}
leo_link_add(r,effect,leo_item,cause);
}

/*:752*/
#line 8283 "./marpa.w"





goto LAST_PIM;
}else{


if(!YIM_is_Active(predecessor))continue;



/*750:*/
#line 8303 "./marpa.w"

{
const AHM predecessor_ahm= AHM_of_YIM(predecessor);
const AHM effect_ahm= Next_AHM_of_AHM(predecessor_ahm);
const YS origin= Origin_of_YIM(predecessor);
const YIM effect= earley_item_assign(r,current_earley_set,
origin,effect_ahm);
YIM_was_Fusion(effect)= 1;
if(Earley_Item_has_No_Source(effect)){


if(YIM_is_Completion(effect)){
/*751:*/
#line 8323 "./marpa.w"
{
YIM*end_of_stack= MARPA_DSTACK_PUSH(r->t_completion_stack,YIM);
*end_of_stack= effect;
}

/*:751*/
#line 8315 "./marpa.w"

}
}
completion_link_add(r,effect,predecessor,cause);
}

/*:750*/
#line 8296 "./marpa.w"

}
NEXT_PIM:;
}
LAST_PIM:;
}

/*:749*/
#line 8258 "./marpa.w"

}
}

/*:748*/
#line 8107 "./marpa.w"

}
/*753:*/
#line 8344 "./marpa.w"

{
int ix;
const int no_of_work_earley_items= 
MARPA_DSTACK_LENGTH(r->t_yim_work_stack);
for(ix= 0;ix<no_of_work_earley_items;ix++)
{
YIM earley_item= WORK_YIM_ITEM(r,ix);

int cil_ix;
const AHM ahm= AHM_of_YIM(earley_item);
const CIL prediction_cil= Predicted_IRL_CIL_of_AHM(ahm);
const int prediction_count= Count_of_CIL(prediction_cil);
for(cil_ix= 0;cil_ix<prediction_count;cil_ix++)
{
const IRLID prediction_irlid= Item_of_CIL(prediction_cil,cil_ix);
const IRL prediction_irl= IRL_by_ID(prediction_irlid);
const AHM prediction_ahm= First_AHM_of_IRL(prediction_irl);
earley_item_assign(r,current_earley_set,current_earley_set,
prediction_ahm);
}

}
}

/*:753*/
#line 8109 "./marpa.w"

postdot_items_create(r,bv_ok_for_chain,current_earley_set);





count_of_expected_terminals= bv_count(r->t_bv_nsyid_is_expected);
if(count_of_expected_terminals<=0
&&MARPA_DSTACK_LENGTH(r->t_alternatives)<=0)
{
/*611:*/
#line 6576 "./marpa.w"

{
R_is_Exhausted(r)= 1;
Input_Phase_of_R(r)= R_AFTER_INPUT;
event_new(g,MARPA_EVENT_EXHAUSTED);
}

/*:611*/
#line 8120 "./marpa.w"

}
earley_set_update_items(r,current_earley_set);
/*656:*/
#line 7014 "./marpa.w"

{
const int yim_count= YIM_Count_of_YS(current_earley_set);
if(yim_count>=r->t_earley_item_warning_threshold)
{
int_event_new(g,MARPA_EVENT_EARLEY_ITEM_THRESHOLD,yim_count);
}
}

/*:656*/
#line 8123 "./marpa.w"

if(r->t_active_event_count> 0){
trigger_events(r);
}
return_value= G_EVENT_COUNT(g);
CLEANUP:;
/*739:*/
#line 8141 "./marpa.w"

bv_free(bv_ok_for_chain);
marpa_obs_free(earleme_complete_obs);

/*:739*/
#line 8129 "./marpa.w"

}
return return_value;
}

/*:737*//*754:*/
#line 8369 "./marpa.w"

PRIVATE void trigger_events(RECCE r)
{
const GRAMMAR g= G_of_R(r);
const YS current_earley_set= Latest_YS_of_R(r);
int min,max,start;
int yim_ix;
struct marpa_obstack*const trigger_events_obs= marpa_obs_init;
const YIM*yims= YIMs_of_YS(current_earley_set);
const XSYID xsy_count= XSY_Count_of_G(g);
const int ahm_count= AHM_Count_of_G(g);
Bit_Vector bv_completion_event_trigger= 
bv_obs_create(trigger_events_obs,xsy_count);
Bit_Vector bv_nulled_event_trigger= 
bv_obs_create(trigger_events_obs,xsy_count);
Bit_Vector bv_prediction_event_trigger= 
bv_obs_create(trigger_events_obs,xsy_count);
Bit_Vector bv_ahm_event_trigger= 
bv_obs_create(trigger_events_obs,ahm_count);
const int working_earley_item_count= YIM_Count_of_YS(current_earley_set);
for(yim_ix= 0;yim_ix<working_earley_item_count;yim_ix++)
{
const YIM yim= yims[yim_ix];
const AHM root_ahm= AHM_of_YIM(yim);
if(AHM_has_Event(root_ahm))
{

bv_bit_set(bv_ahm_event_trigger,ID_of_AHM(root_ahm));
}
{

const SRCL first_leo_source_link= First_Leo_SRCL_of_YIM(yim);
SRCL setup_source_link;
for(setup_source_link= first_leo_source_link;setup_source_link;
setup_source_link= Next_SRCL_of_SRCL(setup_source_link))
{
int cil_ix;
const LIM lim= LIM_of_SRCL(setup_source_link);
const CIL event_ahmids= CIL_of_LIM(lim);
const int event_ahm_count= Count_of_CIL(event_ahmids);
for(cil_ix= 0;cil_ix<event_ahm_count;cil_ix++)
{
const NSYID leo_path_ahmid= 
Item_of_CIL(event_ahmids,cil_ix);
bv_bit_set(bv_ahm_event_trigger,leo_path_ahmid);


}
}
}
}

for(start= 0;bv_scan(bv_ahm_event_trigger,start,&min,&max);
start= max+2)
{
XSYID event_ahmid;
for(event_ahmid= (NSYID)min;event_ahmid<=(NSYID)max;
event_ahmid++)
{
int cil_ix;
const AHM event_ahm= AHM_by_ID(event_ahmid);
{
const CIL completion_xsyids= 
Completion_XSYIDs_of_AHM(event_ahm);
const int event_xsy_count= Count_of_CIL(completion_xsyids);
for(cil_ix= 0;cil_ix<event_xsy_count;cil_ix++)
{
XSYID event_xsyid= Item_of_CIL(completion_xsyids,cil_ix);
bv_bit_set(bv_completion_event_trigger,event_xsyid);
}
}
{
const CIL nulled_xsyids= Nulled_XSYIDs_of_AHM(event_ahm);
const int event_xsy_count= Count_of_CIL(nulled_xsyids);
for(cil_ix= 0;cil_ix<event_xsy_count;cil_ix++)
{
XSYID event_xsyid= Item_of_CIL(nulled_xsyids,cil_ix);
bv_bit_set(bv_nulled_event_trigger,event_xsyid);
}
}
{
const CIL prediction_xsyids= 
Prediction_XSYIDs_of_AHM(event_ahm);
const int event_xsy_count= Count_of_CIL(prediction_xsyids);
for(cil_ix= 0;cil_ix<event_xsy_count;cil_ix++)
{
XSYID event_xsyid= Item_of_CIL(prediction_xsyids,cil_ix);
bv_bit_set(bv_prediction_event_trigger,event_xsyid);
}
}
}
}

if(Ord_of_YS(current_earley_set)<=0)
{








int cil_ix;
const XSY start_xsy= XSY_by_ID(g->t_start_xsy_id);
const CIL nulled_xsyids= Nulled_XSYIDs_of_XSY(start_xsy);
const int cil_count= Count_of_CIL(nulled_xsyids);
for(cil_ix= 0;cil_ix<cil_count;cil_ix++)
{
const XSYID nulled_xsyid= Item_of_CIL(nulled_xsyids,cil_ix);
bv_bit_set(bv_nulled_event_trigger,nulled_xsyid);
}
}

for(start= 0;bv_scan(bv_completion_event_trigger,start,&min,&max);
start= max+2)
{
XSYID event_xsyid;
for(event_xsyid= min;event_xsyid<=max;
event_xsyid++)
{
if(lbv_bit_test
(r->t_lbv_xsyid_completion_event_is_active,event_xsyid))
{
int_event_new(g,MARPA_EVENT_SYMBOL_COMPLETED,event_xsyid);
}
}
}
for(start= 0;bv_scan(bv_nulled_event_trigger,start,&min,&max);
start= max+2)
{
XSYID event_xsyid;
for(event_xsyid= min;event_xsyid<=max;
event_xsyid++)
{
if(lbv_bit_test
(r->t_lbv_xsyid_nulled_event_is_active,event_xsyid))
{
int_event_new(g,MARPA_EVENT_SYMBOL_NULLED,event_xsyid);
}

}
}
for(start= 0;bv_scan(bv_prediction_event_trigger,start,&min,&max);
start= max+2)
{
XSYID event_xsyid;
for(event_xsyid= (NSYID)min;event_xsyid<=(NSYID)max;
event_xsyid++)
{
if(lbv_bit_test
(r->t_lbv_xsyid_prediction_event_is_active,event_xsyid))
{
int_event_new(g,MARPA_EVENT_SYMBOL_PREDICTED,event_xsyid);
}
}
}
marpa_obs_free(trigger_events_obs);
}

/*:754*//*755:*/
#line 8537 "./marpa.w"

PRIVATE int trigger_trivial_events(RECCE r)
{
int cil_ix;
int event_count= 0;
GRAMMAR g= G_of_R(r);
const XSY start_xsy= XSY_by_ID(g->t_start_xsy_id);
const CIL nulled_xsyids= Nulled_XSYIDs_of_XSY(start_xsy);
const int cil_count= Count_of_CIL(nulled_xsyids);
for(cil_ix= 0;cil_ix<cil_count;cil_ix++)
{
const XSYID nulled_xsyid= Item_of_CIL(nulled_xsyids,cil_ix);
if(lbv_bit_test(r->t_lbv_xsyid_nulled_event_is_active,nulled_xsyid)){
int_event_new(g,MARPA_EVENT_SYMBOL_NULLED,nulled_xsyid);
event_count++;
}
}
return event_count;
}

/*:755*//*756:*/
#line 8557 "./marpa.w"

PRIVATE void earley_set_update_items(RECCE r,YS set)
{
YIM*working_earley_items;
YIM*finished_earley_items;
int working_earley_item_count;
int i;
YIMs_of_YS(set)= marpa_obs_new(r->t_obs,YIM,YIM_Count_of_YS(set));
finished_earley_items= YIMs_of_YS(set);

working_earley_items= Work_YIMs_of_R(r);
working_earley_item_count= Work_YIM_Count_of_R(r);
for(i= 0;i<working_earley_item_count;i++){
YIM earley_item= working_earley_items[i];
int ordinal= Ord_of_YIM(earley_item);
finished_earley_items[ordinal]= earley_item;
}
WORK_YIMS_CLEAR(r);
}

/*:756*//*757:*/
#line 8586 "./marpa.w"

PRIVATE void r_update_earley_sets(RECCE r)
{
YS set;
YS first_unstacked_earley_set;
if(!MARPA_DSTACK_IS_INITIALIZED(r->t_earley_set_stack)){
first_unstacked_earley_set= First_YS_of_R(r);
MARPA_DSTACK_INIT(r->t_earley_set_stack,YS,
MAX(1024,YS_Count_of_R(r)));
}else{
YS*end_of_stack= MARPA_DSTACK_TOP(r->t_earley_set_stack,YS);
first_unstacked_earley_set= Next_YS_of_YS(*end_of_stack);
}
for(set= first_unstacked_earley_set;set;set= Next_YS_of_YS(set)){
YS*end_of_stack= MARPA_DSTACK_PUSH(r->t_earley_set_stack,YS);
(*end_of_stack)= set;
}
}

/*:757*//*773:*/
#line 8690 "./marpa.w"

PRIVATE_NOT_INLINE void
postdot_items_create(RECCE r,
Bit_Vector bv_ok_for_chain,
const YS current_earley_set)
{
/*560:*/
#line 6076 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:560*/
#line 8696 "./marpa.w"

/*772:*/
#line 8687 "./marpa.w"

bv_clear(r->t_bv_lim_symbols);
bv_clear(r->t_bv_pim_symbols);
/*:772*/
#line 8697 "./marpa.w"

/*774:*/
#line 8709 "./marpa.w"
{

YIM*work_earley_items= MARPA_DSTACK_BASE(r->t_yim_work_stack,YIM);
int no_of_work_earley_items= MARPA_DSTACK_LENGTH(r->t_yim_work_stack);
int ix;
for(ix= 0;
ix<no_of_work_earley_items;
ix++)
{
YIM earley_item= work_earley_items[ix];
AHM ahm= AHM_of_YIM(earley_item);
const NSYID postdot_nsyid= Postdot_NSYID_of_AHM(ahm);
if(postdot_nsyid<0)continue;
{
PIM old_pim= NULL;
PIM new_pim;


new_pim= marpa__obs_alloc(r->t_obs,
sizeof(YIX_Object),ALIGNOF(PIM_Object));

Postdot_NSYID_of_PIM(new_pim)= postdot_nsyid;
YIM_of_PIM(new_pim)= earley_item;
if(bv_bit_test(r->t_bv_pim_symbols,postdot_nsyid))
old_pim= r->t_pim_workarea[postdot_nsyid];
Next_PIM_of_PIM(new_pim)= old_pim;
if(!old_pim)current_earley_set->t_postdot_sym_count++;
r->t_pim_workarea[postdot_nsyid]= new_pim;
bv_bit_set(r->t_bv_pim_symbols,postdot_nsyid);
}
}
}

/*:774*/
#line 8698 "./marpa.w"

if(r->t_is_using_leo){
/*776:*/
#line 8752 "./marpa.w"

{
int min,max,start;
for(start= 0;bv_scan(r->t_bv_pim_symbols,start,&min,&max);
start= max+2)
{
NSYID nsyid;
for(nsyid= (NSYID)min;nsyid<=(NSYID)max;nsyid++)
{
const PIM this_pim= r->t_pim_workarea[nsyid];
if(Next_PIM_of_PIM(this_pim))
goto NEXT_NSYID;


{
const YIM leo_base= YIM_of_PIM(this_pim);
AHM potential_leo_penult_ahm= NULL;
const AHM leo_base_ahm= AHM_of_YIM(leo_base);
const IRL leo_base_irl= IRL_of_AHM(leo_base_ahm);

if(!IRL_is_Leo(leo_base_irl))
goto NEXT_NSYID;
potential_leo_penult_ahm= leo_base_ahm;
MARPA_ASSERT((int)potential_leo_penult_ahm);
{
const AHM trailhead_ahm= 
Next_AHM_of_AHM(potential_leo_penult_ahm);
if(AHM_is_Leo_Completion(trailhead_ahm))
{
/*777:*/
#line 8796 "./marpa.w"
{
LIM new_lim;
new_lim= marpa_obs_new(r->t_obs,LIM_Object,1);
LIM_is_Active(new_lim)= 1;
LIM_is_Rejected(new_lim)= 1;
Postdot_NSYID_of_LIM(new_lim)= nsyid;
YIM_of_PIM(new_lim)= NULL;
Predecessor_LIM_of_LIM(new_lim)= NULL;
Origin_of_LIM(new_lim)= NULL;
CIL_of_LIM(new_lim)= NULL;
Top_AHM_of_LIM(new_lim)= trailhead_ahm;
Trailhead_AHM_of_LIM(new_lim)= trailhead_ahm;
Trailhead_YIM_of_LIM(new_lim)= leo_base;
YS_of_LIM(new_lim)= current_earley_set;
Next_PIM_of_LIM(new_lim)= this_pim;
r->t_pim_workarea[nsyid]= new_lim;
bv_bit_set(r->t_bv_lim_symbols,nsyid);
}

/*:777*/
#line 8781 "./marpa.w"

}
}
}
NEXT_NSYID:;
}
}
}

/*:776*/
#line 8700 "./marpa.w"

/*786:*/
#line 8884 "./marpa.w"
{
int min,max,start;

bv_copy(bv_ok_for_chain,r->t_bv_lim_symbols);
for(start= 0;bv_scan(r->t_bv_lim_symbols,start,&min,&max);
start= max+2)
{

NSYID main_loop_nsyid;
for(main_loop_nsyid= (NSYID)min;
main_loop_nsyid<=(NSYID)max;
main_loop_nsyid++)
{
LIM predecessor_lim;
LIM lim_to_process= r->t_pim_workarea[main_loop_nsyid];
if(LIM_is_Populated(lim_to_process))continue;

/*788:*/
#line 8940 "./marpa.w"

{
const YIM base_yim= Trailhead_YIM_of_LIM(lim_to_process);
const YS predecessor_set= Origin_of_YIM(base_yim);
const AHM trailhead_ahm= Trailhead_AHM_of_LIM(lim_to_process);
const NSYID predecessor_transition_nsyid= 
LHSID_of_AHM(trailhead_ahm);
PIM predecessor_pim;
if(Ord_of_YS(predecessor_set)<Ord_of_YS(current_earley_set))
{
predecessor_pim
= 
First_PIM_of_YS_by_NSYID(predecessor_set,
predecessor_transition_nsyid);
}
else
{
predecessor_pim= r->t_pim_workarea[predecessor_transition_nsyid];
}
predecessor_lim= 
PIM_is_LIM(predecessor_pim)?LIM_of_PIM(predecessor_pim):NULL;
}

/*:788*/
#line 8901 "./marpa.w"

if(predecessor_lim&&LIM_is_Populated(predecessor_lim)){
/*796:*/
#line 9059 "./marpa.w"

{
const AHM new_top_ahm= Top_AHM_of_LIM(predecessor_lim);
const CIL predecessor_cil= CIL_of_LIM(predecessor_lim);



CIL_of_LIM(lim_to_process)= predecessor_cil;
Predecessor_LIM_of_LIM(lim_to_process)= predecessor_lim;
Origin_of_LIM(lim_to_process)= Origin_of_LIM(predecessor_lim);
if(Event_Group_Size_of_AHM(new_top_ahm)> Count_of_CIL(predecessor_cil))
{
const AHM trailhead_ahm= Trailhead_AHM_of_LIM(lim_to_process);
const CIL trailhead_ahm_event_ahmids= 
Event_AHMIDs_of_AHM(trailhead_ahm);
if(Count_of_CIL(trailhead_ahm_event_ahmids))
{
CIL new_cil= cil_merge_one(&g->t_cilar,predecessor_cil,
Item_of_CIL
(trailhead_ahm_event_ahmids,0));
if(new_cil)
{
CIL_of_LIM(lim_to_process)= new_cil;
}
}
}
Top_AHM_of_LIM(lim_to_process)= new_top_ahm;
}

/*:796*/
#line 8903 "./marpa.w"

continue;
}
if(!predecessor_lim){


/*798:*/
#line 9100 "./marpa.w"
{
const AHM trailhead_ahm= Trailhead_AHM_of_LIM(lim_to_process);
const YIM base_yim= Trailhead_YIM_of_LIM(lim_to_process);
Origin_of_LIM(lim_to_process)= Origin_of_YIM(base_yim);
CIL_of_LIM(lim_to_process)= Event_AHMIDs_of_AHM(trailhead_ahm);
}

/*:798*/
#line 8909 "./marpa.w"

continue;
}
/*791:*/
#line 8967 "./marpa.w"
{
int lim_chain_ix;
/*794:*/
#line 8987 "./marpa.w"

{
NSYID postdot_nsyid_of_lim_to_process
= Postdot_NSYID_of_LIM(lim_to_process);
lim_chain_ix= 0;
r->t_lim_chain[lim_chain_ix++]= LIM_of_PIM(lim_to_process);
bv_bit_clear(bv_ok_for_chain,
postdot_nsyid_of_lim_to_process);


while(1)
{








lim_to_process= predecessor_lim;
postdot_nsyid_of_lim_to_process= Postdot_NSYID_of_LIM(lim_to_process);
if(!bv_bit_test
(bv_ok_for_chain,postdot_nsyid_of_lim_to_process))
{





break;
}

/*788:*/
#line 8940 "./marpa.w"

{
const YIM base_yim= Trailhead_YIM_of_LIM(lim_to_process);
const YS predecessor_set= Origin_of_YIM(base_yim);
const AHM trailhead_ahm= Trailhead_AHM_of_LIM(lim_to_process);
const NSYID predecessor_transition_nsyid= 
LHSID_of_AHM(trailhead_ahm);
PIM predecessor_pim;
if(Ord_of_YS(predecessor_set)<Ord_of_YS(current_earley_set))
{
predecessor_pim
= 
First_PIM_of_YS_by_NSYID(predecessor_set,
predecessor_transition_nsyid);
}
else
{
predecessor_pim= r->t_pim_workarea[predecessor_transition_nsyid];
}
predecessor_lim= 
PIM_is_LIM(predecessor_pim)?LIM_of_PIM(predecessor_pim):NULL;
}

/*:788*/
#line 9020 "./marpa.w"


r->t_lim_chain[lim_chain_ix++]= LIM_of_PIM(lim_to_process);


bv_bit_clear(bv_ok_for_chain,
postdot_nsyid_of_lim_to_process);





if(!predecessor_lim)
break;
if(LIM_is_Populated(predecessor_lim))
break;



}
}

/*:794*/
#line 8969 "./marpa.w"

/*795:*/
#line 9042 "./marpa.w"

for(lim_chain_ix--;lim_chain_ix>=0;lim_chain_ix--){
lim_to_process= r->t_lim_chain[lim_chain_ix];
if(predecessor_lim&&LIM_is_Populated(predecessor_lim)){
/*796:*/
#line 9059 "./marpa.w"

{
const AHM new_top_ahm= Top_AHM_of_LIM(predecessor_lim);
const CIL predecessor_cil= CIL_of_LIM(predecessor_lim);



CIL_of_LIM(lim_to_process)= predecessor_cil;
Predecessor_LIM_of_LIM(lim_to_process)= predecessor_lim;
Origin_of_LIM(lim_to_process)= Origin_of_LIM(predecessor_lim);
if(Event_Group_Size_of_AHM(new_top_ahm)> Count_of_CIL(predecessor_cil))
{
const AHM trailhead_ahm= Trailhead_AHM_of_LIM(lim_to_process);
const CIL trailhead_ahm_event_ahmids= 
Event_AHMIDs_of_AHM(trailhead_ahm);
if(Count_of_CIL(trailhead_ahm_event_ahmids))
{
CIL new_cil= cil_merge_one(&g->t_cilar,predecessor_cil,
Item_of_CIL
(trailhead_ahm_event_ahmids,0));
if(new_cil)
{
CIL_of_LIM(lim_to_process)= new_cil;
}
}
}
Top_AHM_of_LIM(lim_to_process)= new_top_ahm;
}

/*:796*/
#line 9046 "./marpa.w"

}else{
/*798:*/
#line 9100 "./marpa.w"
{
const AHM trailhead_ahm= Trailhead_AHM_of_LIM(lim_to_process);
const YIM base_yim= Trailhead_YIM_of_LIM(lim_to_process);
Origin_of_LIM(lim_to_process)= Origin_of_YIM(base_yim);
CIL_of_LIM(lim_to_process)= Event_AHMIDs_of_AHM(trailhead_ahm);
}

/*:798*/
#line 9048 "./marpa.w"

}
predecessor_lim= lim_to_process;
}

/*:795*/
#line 8970 "./marpa.w"

}

/*:791*/
#line 8912 "./marpa.w"

}
}
}

/*:786*/
#line 8701 "./marpa.w"

}
/*799:*/
#line 9107 "./marpa.w"
{
PIM*postdot_array
= current_earley_set->t_postdot_ary
= marpa_obs_new(r->t_obs,PIM,current_earley_set->t_postdot_sym_count);
int min,max,start;
int postdot_array_ix= 0;
for(start= 0;bv_scan(r->t_bv_pim_symbols,start,&min,&max);start= max+2){
NSYID nsyid;
for(nsyid= min;nsyid<=max;nsyid++){
PIM this_pim= r->t_pim_workarea[nsyid];
if(lbv_bit_test(r->t_nsy_expected_is_event,nsyid)){
XSY xsy= Source_XSY_of_NSYID(nsyid);
int_event_new(g,MARPA_EVENT_SYMBOL_EXPECTED,ID_of_XSY(xsy));
}
if(this_pim)postdot_array[postdot_array_ix++]= this_pim;
}
}
}


/*:799*/
#line 8703 "./marpa.w"

bv_and(r->t_bv_nsyid_is_expected,r->t_bv_pim_symbols,g->t_bv_nsyid_is_terminal);
}

/*:773*//*802:*/
#line 9143 "./marpa.w"

Marpa_Earleme
marpa_r_clean(Marpa_Recognizer r)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 9147 "./marpa.w"

/*560:*/
#line 6076 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:560*/
#line 9148 "./marpa.w"

YSID ysid_to_clean;


const YS current_ys= Latest_YS_of_R(r);
const YSID current_ys_id= Ord_of_YS(current_ys);

int count_of_expected_terminals;
/*803:*/
#line 9204 "./marpa.w"




struct marpa_obstack*const method_obstack= marpa_obs_init;

YIMID*prediction_by_irl= 
marpa_obs_new(method_obstack,YIMID,IRL_Count_of_G(g));

/*:803*/
#line 9156 "./marpa.w"






const JEARLEME return_value= -2;

/*1227:*/
#line 14703 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)!=R_DURING_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_ACCEPTING_INPUT);
return failure_indicator;
}

if(_MARPA_UNLIKELY(!R_is_Consistent(r))){
MARPA_ERROR(MARPA_ERR_RECCE_IS_INCONSISTENT);
return failure_indicator;
}

/*:1227*/
#line 9164 "./marpa.w"


G_EVENTS_CLEAR(g);



if(R_is_Consistent(r))return 0;





earley_set_update_items(r,current_ys);

for(ysid_to_clean= First_Inconsistent_YS_of_R(r);
ysid_to_clean<=current_ys_id;
ysid_to_clean++){
/*805:*/
#line 9218 "./marpa.w"

{
const YS ys_to_clean= YS_of_R_by_Ord(r,ysid_to_clean);
const YIM*yims_to_clean= YIMs_of_YS(ys_to_clean);
const int yim_to_clean_count= YIM_Count_of_YS(ys_to_clean);
Bit_Matrix acceptance_matrix= matrix_obs_create(method_obstack,
yim_to_clean_count,
yim_to_clean_count);
/*806:*/
#line 9238 "./marpa.w"

{
int yim_ix= yim_to_clean_count-1;
YIM yim= yims_to_clean[yim_ix];






while(YIM_was_Predicted(yim)){
prediction_by_irl[IRLID_of_YIM(yim)]= yim_ix;
yim= yims_to_clean[--yim_ix];
}
}

/*:806*/
#line 9226 "./marpa.w"

/*807:*/
#line 9254 "./marpa.w"
{
int yim_to_clean_ix;
for(yim_to_clean_ix= 0;
yim_to_clean_ix<yim_to_clean_count;
yim_to_clean_ix++)
{
const YIM yim_to_clean= yims_to_clean[yim_to_clean_ix];




MARPA_ASSERT(!YIM_is_Initial(yim_to_clean)||
(YIM_is_Active(yim_to_clean)&&!YIM_is_Rejected(yim_to_clean)));



if(!YIM_is_Initial(yim_to_clean))YIM_is_Active(yim_to_clean)= 0;






if(YIM_is_Rejected(yim_to_clean))continue;



/*808:*/
#line 9291 "./marpa.w"

{
const NSYID postdot_nsyid= Postdot_NSYID_of_YIM(yim_to_clean);
if(postdot_nsyid>=0)
{
int cil_ix;
const CIL lhs_cil= LHS_CIL_of_NSYID(postdot_nsyid);
const int cil_count= Count_of_CIL(lhs_cil);
for(cil_ix= 0;cil_ix<cil_count;cil_ix++)
{
const IRLID irlid= Item_of_CIL(lhs_cil,cil_ix);
const int predicted_yim_ix= prediction_by_irl[irlid];
const YIM predicted_yim= yims_to_clean[predicted_yim_ix];
if(YIM_is_Rejected(predicted_yim))continue;
matrix_bit_set(acceptance_matrix,yim_to_clean_ix,
predicted_yim_ix);
}
}
}

/*:808*/
#line 9281 "./marpa.w"







}
}

/*:807*/
#line 9227 "./marpa.w"

transitive_closure(acceptance_matrix);
/*813:*/
#line 9351 "./marpa.w"
{
int cause_yim_ix;
for(cause_yim_ix= 0;cause_yim_ix<yim_to_clean_count;cause_yim_ix++){
const YIM cause_yim= yims_to_clean[cause_yim_ix];





if(!YIM_is_Initial(cause_yim)&&
!YIM_was_Scanned(cause_yim))break;





if(YIM_is_Rejected(cause_yim))continue;

{
const Bit_Vector bv_yims_to_accept
= matrix_row(acceptance_matrix,cause_yim_ix);
int min,max,start;
for(start= 0;bv_scan(bv_yims_to_accept,start,&min,&max);
start= max+2)
{
int yim_to_accept_ix;
for(yim_to_accept_ix= min;
yim_to_accept_ix<=max;yim_to_accept_ix++)
{
const YIM yim_to_accept= yims_to_clean[yim_to_accept_ix];
YIM_is_Active(yim_to_accept)= 1;
}
}
}
}
}

/*:813*/
#line 9229 "./marpa.w"

/*814:*/
#line 9392 "./marpa.w"
{
int yim_ix;
for(yim_ix= 0;yim_ix<yim_to_clean_count;yim_ix++){
const YIM yim= yims_to_clean[yim_ix];
if(!YIM_is_Active(yim))continue;
YIM_is_Rejected(yim)= 1;
}
}

/*:814*/
#line 9230 "./marpa.w"

/*816:*/
#line 9406 "./marpa.w"
{}

/*:816*/
#line 9231 "./marpa.w"

/*817:*/
#line 9410 "./marpa.w"

{
int postdot_sym_ix;
const int postdot_sym_count= Postdot_SYM_Count_of_YS(ys_to_clean);
const PIM*postdot_array= ys_to_clean->t_postdot_ary;



for(postdot_sym_ix= 0;postdot_sym_ix<postdot_sym_count;postdot_sym_ix++){



const PIM first_pim= postdot_array[postdot_sym_ix];
if(PIM_is_LIM(first_pim)){
const LIM lim= LIM_of_PIM(first_pim);



LIM_is_Rejected(lim)= 1;
LIM_is_Active(lim)= 0;



if(!YIM_is_Active(Trailhead_YIM_of_LIM(lim)))continue;
{
const LIM predecessor_lim= Predecessor_LIM_of_LIM(lim);


if(predecessor_lim&&!LIM_is_Active(predecessor_lim))continue;
}



LIM_is_Rejected(lim)= 0;
LIM_is_Active(lim)= 1;
}
}
}

/*:817*/
#line 9232 "./marpa.w"

}

/*:805*/
#line 9181 "./marpa.w"

}




/*818:*/
#line 9455 "./marpa.w"
{
int old_alt_ix;
int no_of_alternatives= MARPA_DSTACK_LENGTH(r->t_alternatives);






for(old_alt_ix= 0;
old_alt_ix<no_of_alternatives;
old_alt_ix++)
{
const ALT alternative= MARPA_DSTACK_INDEX(
r->t_alternatives,ALT_Object,old_alt_ix);
if(!alternative_is_acceptable(alternative))break;
}





if(old_alt_ix<no_of_alternatives){



int empty_alt_ix= old_alt_ix;
for(old_alt_ix++;old_alt_ix<no_of_alternatives;old_alt_ix++)
{
const ALT alternative= MARPA_DSTACK_INDEX(
r->t_alternatives,ALT_Object,old_alt_ix);
if(!alternative_is_acceptable(alternative))continue;
*MARPA_DSTACK_INDEX(r->t_alternatives,ALT_Object,empty_alt_ix)
= *alternative;
empty_alt_ix++;
}




MARPA_DSTACK_COUNT_SET(r->t_alternatives,empty_alt_ix);

if(empty_alt_ix){
Furthest_Earleme_of_R(r)= Earleme_of_YS(current_ys);
}else{
const ALT furthest_alternative
= MARPA_DSTACK_INDEX(r->t_alternatives,ALT_Object,0);
Furthest_Earleme_of_R(r)= End_Earleme_of_ALT(furthest_alternative);
}

}

}

/*:818*/
#line 9187 "./marpa.w"


bv_clear(r->t_bv_nsyid_is_expected);
/*820:*/
#line 9535 "./marpa.w"
{}

/*:820*/
#line 9190 "./marpa.w"

count_of_expected_terminals= bv_count(r->t_bv_nsyid_is_expected);
if(count_of_expected_terminals<=0
&&MARPA_DSTACK_LENGTH(r->t_alternatives)<=0)
{
/*611:*/
#line 6576 "./marpa.w"

{
R_is_Exhausted(r)= 1;
Input_Phase_of_R(r)= R_AFTER_INPUT;
event_new(g,MARPA_EVENT_EXHAUSTED);
}

/*:611*/
#line 9195 "./marpa.w"

}

First_Inconsistent_YS_of_R(r)= -1;

/*804:*/
#line 9213 "./marpa.w"

{
marpa_obs_free(method_obstack);
}

/*:804*/
#line 9200 "./marpa.w"

return return_value;
}

/*:802*//*819:*/
#line 9509 "./marpa.w"

PRIVATE int alternative_is_acceptable(ALT alternative)
{
PIM pim;
const NSYID token_symbol_id= NSYID_of_ALT(alternative);
const YS start_ys= Start_YS_of_ALT(alternative);
for(pim= First_PIM_of_YS_by_NSYID(start_ys,token_symbol_id);
pim;
pim= Next_PIM_of_PIM(pim))
{
YIM predecessor_yim= YIM_of_PIM(pim);






if(!predecessor_yim)continue;



if(YIM_is_Active(predecessor_yim))return 1;
}
return 0;
}

/*:819*//*821:*/
#line 9538 "./marpa.w"

int
marpa_r_zwa_default_set(Marpa_Recognizer r,
Marpa_Assertion_ID zwaid,
int default_value)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 9544 "./marpa.w"

/*560:*/
#line 6076 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:560*/
#line 9545 "./marpa.w"

ZWA zwa;
int old_default_value;
/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 9548 "./marpa.w"

/*1223:*/
#line 14673 "./marpa.w"

if(_MARPA_UNLIKELY(ZWAID_is_Malformed(zwaid))){
MARPA_ERROR(MARPA_ERR_INVALID_ASSERTION_ID);
return failure_indicator;
}

/*:1223*/
#line 9549 "./marpa.w"

/*1222:*/
#line 14667 "./marpa.w"

if(_MARPA_UNLIKELY(!ZWAID_of_G_Exists(zwaid))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_ASSERTION_ID);
return failure_indicator;
}
/*:1222*/
#line 9550 "./marpa.w"

if(_MARPA_UNLIKELY(default_value<0||default_value> 1))
{
MARPA_ERROR(MARPA_ERR_INVALID_BOOLEAN);
return failure_indicator;
}
zwa= RZWA_by_ID(zwaid);
old_default_value= Default_Value_of_ZWA(zwa);
Default_Value_of_ZWA(zwa)= default_value?1:0;
return old_default_value;
}

/*:821*//*822:*/
#line 9562 "./marpa.w"

int
marpa_r_zwa_default(Marpa_Recognizer r,
Marpa_Assertion_ID zwaid)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 9567 "./marpa.w"

/*560:*/
#line 6076 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:560*/
#line 9568 "./marpa.w"

ZWA zwa;
/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 9570 "./marpa.w"

/*1223:*/
#line 14673 "./marpa.w"

if(_MARPA_UNLIKELY(ZWAID_is_Malformed(zwaid))){
MARPA_ERROR(MARPA_ERR_INVALID_ASSERTION_ID);
return failure_indicator;
}

/*:1223*/
#line 9571 "./marpa.w"

/*1222:*/
#line 14667 "./marpa.w"

if(_MARPA_UNLIKELY(!ZWAID_of_G_Exists(zwaid))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_ASSERTION_ID);
return failure_indicator;
}
/*:1222*/
#line 9572 "./marpa.w"

zwa= RZWA_by_ID(zwaid);
return Default_Value_of_ZWA(zwa);
}

/*:822*//*831:*/
#line 9612 "./marpa.w"

PRIVATE_NOT_INLINE int report_item_cmp(
const void*ap,
const void*bp,
void*param UNUSED)
{
const struct marpa_progress_item*const report_a= ap;
const struct marpa_progress_item*const report_b= bp;
if(Position_of_PROGRESS(report_a)> Position_of_PROGRESS(report_b))return 1;
if(Position_of_PROGRESS(report_a)<Position_of_PROGRESS(report_b))return-1;
if(RULEID_of_PROGRESS(report_a)> RULEID_of_PROGRESS(report_b))return 1;
if(RULEID_of_PROGRESS(report_a)<RULEID_of_PROGRESS(report_b))return-1;
if(Origin_of_PROGRESS(report_a)> Origin_of_PROGRESS(report_b))return 1;
if(Origin_of_PROGRESS(report_a)<Origin_of_PROGRESS(report_b))return-1;
return 0;
}

/*:831*//*832:*/
#line 9629 "./marpa.w"

int marpa_r_progress_report_start(
Marpa_Recognizer r,
Marpa_Earley_Set_ID set_id)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 9634 "./marpa.w"

YS earley_set;
/*560:*/
#line 6076 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:560*/
#line 9636 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 9637 "./marpa.w"

/*1226:*/
#line 14698 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1226*/
#line 9638 "./marpa.w"

if(set_id<0)
{
MARPA_ERROR(MARPA_ERR_INVALID_LOCATION);
return failure_indicator;
}
r_update_earley_sets(r);
if(!YS_Ord_is_Valid(r,set_id))
{
MARPA_ERROR(MARPA_ERR_NO_EARLEY_SET_AT_LOCATION);
return failure_indicator;
}
earley_set= YS_of_R_by_Ord(r,set_id);

MARPA_OFF_DEBUG3("At %s, starting progress report Earley set %ld",
STRLOC,(long)set_id);

/*826:*/
#line 9586 "./marpa.w"

r->t_current_report_item= &progress_report_not_ready;
if(r->t_progress_report_traverser){
_marpa_avl_destroy(MARPA_TREE_OF_AVL_TRAV(r->t_progress_report_traverser));
}
r->t_progress_report_traverser= NULL;
/*:826*/
#line 9655 "./marpa.w"

{
const MARPA_AVL_TREE report_tree= 
_marpa_avl_create(report_item_cmp,NULL);
const YIM*const earley_items= YIMs_of_YS(earley_set);
const int earley_item_count= YIM_Count_of_YS(earley_set);
int earley_item_id;
for(earley_item_id= 0;earley_item_id<earley_item_count;
earley_item_id++)
{
const YIM earley_item= earley_items[earley_item_id];
if(!YIM_is_Active(earley_item))continue;
/*834:*/
#line 9688 "./marpa.w"

{
SRCL leo_source_link= NULL;

MARPA_OFF_DEBUG2("At %s, Do the progress report",STRLOC);

progress_report_item_insert(report_tree,AHM_of_YIM(earley_item),
Origin_Ord_of_YIM(earley_item));
for(leo_source_link= First_Leo_SRCL_of_YIM(earley_item);
leo_source_link;leo_source_link= Next_SRCL_of_SRCL(leo_source_link))
{
LIM leo_item;
MARPA_OFF_DEBUG3("At %s, Leo source link %p",STRLOC,leo_source_link);

if(!SRCL_is_Active(leo_source_link))continue;

MARPA_OFF_DEBUG3("At %s, active Leo source link %p",STRLOC,leo_source_link);




for(leo_item= LIM_of_SRCL(leo_source_link);
leo_item;leo_item= Predecessor_LIM_of_LIM(leo_item))
{
const YIM trailhead_yim= Trailhead_YIM_of_LIM(leo_item);
const YSID trailhead_origin= Ord_of_YS(Origin_of_YIM(trailhead_yim));
const AHM trailhead_ahm= Trailhead_AHM_of_LIM(leo_item);
progress_report_item_insert(report_tree,trailhead_ahm,
trailhead_origin);
}

MARPA_OFF_DEBUG3("At %s, finished Leo source link %p",STRLOC,leo_source_link);
}
}

/*:834*/
#line 9667 "./marpa.w"

}
r->t_progress_report_traverser= _marpa_avl_t_init(report_tree);
return(int)marpa_avl_count(report_tree);
}
}
/*:832*//*833:*/
#line 9674 "./marpa.w"

int marpa_r_progress_report_reset(Marpa_Recognizer r)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 9677 "./marpa.w"

MARPA_AVL_TRAV traverser= r->t_progress_report_traverser;
/*560:*/
#line 6076 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:560*/
#line 9679 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 9680 "./marpa.w"

/*1226:*/
#line 14698 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1226*/
#line 9681 "./marpa.w"

/*838:*/
#line 9796 "./marpa.w"

{
if(!traverser)
{
MARPA_ERROR(MARPA_ERR_PROGRESS_REPORT_NOT_STARTED);
return failure_indicator;
}
}

/*:838*/
#line 9682 "./marpa.w"

_marpa_avl_t_reset(traverser);
return 1;
}

/*:833*//*835:*/
#line 9723 "./marpa.w"

PRIVATE void
progress_report_item_insert(MARPA_AVL_TREE report_tree,
AHM report_ahm,
YSID report_origin)
{
PROGRESS new_report_item;
const XRL source_xrl= XRL_of_AHM(report_ahm);
const int xrl_position= XRL_Position_of_AHM(report_ahm);
if(!source_xrl)
return;

MARPA_OFF_DEBUG5(
"At %s, report item insert rule=%ld pos=%ld origin=%ld",
STRLOC,(long)ID_of_XRL(source_xrl),
(long)xrl_position,(long)report_origin);




if(XRL_is_Sequence(source_xrl)
&&Position_of_AHM(report_ahm)<=0
&&IRL_has_Virtual_LHS(IRL_of_AHM(report_ahm)))
return;

new_report_item= 
marpa_obs_new(MARPA_AVL_OBSTACK(report_tree),
struct marpa_progress_item,1);
Position_of_PROGRESS(new_report_item)= xrl_position;
Origin_of_PROGRESS(new_report_item)= report_origin;
RULEID_of_PROGRESS(new_report_item)= ID_of_XRL(source_xrl);
_marpa_avl_insert(report_tree,new_report_item);
return;
}

/*:835*//*836:*/
#line 9758 "./marpa.w"

int marpa_r_progress_report_finish(Marpa_Recognizer r){
const int success= 1;
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 9761 "./marpa.w"

/*560:*/
#line 6076 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:560*/
#line 9762 "./marpa.w"

const MARPA_AVL_TRAV traverser= r->t_progress_report_traverser;
/*1226:*/
#line 14698 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1226*/
#line 9764 "./marpa.w"

/*838:*/
#line 9796 "./marpa.w"

{
if(!traverser)
{
MARPA_ERROR(MARPA_ERR_PROGRESS_REPORT_NOT_STARTED);
return failure_indicator;
}
}

/*:838*/
#line 9765 "./marpa.w"

/*826:*/
#line 9586 "./marpa.w"

r->t_current_report_item= &progress_report_not_ready;
if(r->t_progress_report_traverser){
_marpa_avl_destroy(MARPA_TREE_OF_AVL_TRAV(r->t_progress_report_traverser));
}
r->t_progress_report_traverser= NULL;
/*:826*/
#line 9766 "./marpa.w"

return success;
}

/*:836*//*837:*/
#line 9770 "./marpa.w"

Marpa_Rule_ID marpa_r_progress_item(
Marpa_Recognizer r,int*position,Marpa_Earley_Set_ID*origin
){
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 9774 "./marpa.w"

PROGRESS report_item;
MARPA_AVL_TRAV traverser;
/*560:*/
#line 6076 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:560*/
#line 9777 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 9778 "./marpa.w"

/*1226:*/
#line 14698 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1226*/
#line 9779 "./marpa.w"

traverser= r->t_progress_report_traverser;
if(_MARPA_UNLIKELY(!position||!origin)){
MARPA_ERROR(MARPA_ERR_POINTER_ARG_NULL);
return failure_indicator;
}
/*838:*/
#line 9796 "./marpa.w"

{
if(!traverser)
{
MARPA_ERROR(MARPA_ERR_PROGRESS_REPORT_NOT_STARTED);
return failure_indicator;
}
}

/*:838*/
#line 9785 "./marpa.w"

report_item= _marpa_avl_t_next(traverser);
if(!report_item){
MARPA_ERROR(MARPA_ERR_PROGRESS_REPORT_EXHAUSTED);
return-1;
}
*position= Position_of_PROGRESS(report_item);
*origin= Origin_of_PROGRESS(report_item);
return RULEID_of_PROGRESS(report_item);
}

/*:837*//*861:*/
#line 9981 "./marpa.w"

PRIVATE void ur_node_stack_init(URS stack)
{
stack->t_obs= marpa_obs_init;
stack->t_base= ur_node_new(stack,0);
ur_node_stack_reset(stack);
}

/*:861*//*862:*/
#line 9989 "./marpa.w"

PRIVATE void ur_node_stack_reset(URS stack)
{
stack->t_top= stack->t_base;
}

/*:862*//*863:*/
#line 9995 "./marpa.w"

PRIVATE void ur_node_stack_destroy(URS stack)
{
if(stack->t_base)marpa_obs_free(stack->t_obs);
stack->t_base= NULL;
}

/*:863*//*864:*/
#line 10002 "./marpa.w"

PRIVATE UR ur_node_new(URS stack,UR prev)
{
UR new_ur_node;
new_ur_node= marpa_obs_new(stack->t_obs,UR_Object,1);
Next_UR_of_UR(new_ur_node)= 0;
Prev_UR_of_UR(new_ur_node)= prev;
return new_ur_node;
}

/*:864*//*865:*/
#line 10012 "./marpa.w"

PRIVATE void
ur_node_push(URS stack,YIM earley_item)
{
UR old_top= stack->t_top;
UR new_top= Next_UR_of_UR(old_top);
YIM_of_UR(old_top)= earley_item;
if(!new_top)
{
new_top= ur_node_new(stack,old_top);
Next_UR_of_UR(old_top)= new_top;
}
stack->t_top= new_top;
}

/*:865*//*866:*/
#line 10027 "./marpa.w"

PRIVATE UR
ur_node_pop(URS stack)
{
UR new_top= Prev_UR_of_UR(stack->t_top);
if(!new_top)return NULL;
stack->t_top= new_top;
return new_top;
}

/*:866*//*868:*/
#line 10064 "./marpa.w"

PRIVATE void push_ur_if_new(
struct s_bocage_setup_per_ys*per_ys_data,
URS ur_node_stack,YIM yim)
{
if(!psi_test_and_set(per_ys_data,yim))
{
ur_node_push(ur_node_stack,yim);
}
}

/*:868*//*869:*/
#line 10080 "./marpa.w"

PRIVATE int psi_test_and_set(
struct s_bocage_setup_per_ys*per_ys_data,
YIM earley_item
)
{
const YSID set_ordinal= YS_Ord_of_YIM(earley_item);
const int item_ordinal= Ord_of_YIM(earley_item);
const OR previous_or_node= 
OR_by_PSI(per_ys_data,set_ordinal,item_ordinal);
if(!previous_or_node)
{
OR_by_PSI(per_ys_data,set_ordinal,item_ordinal)= dummy_or_node;
return 0;
}
return 1;
}

/*:869*//*871:*/
#line 10122 "./marpa.w"

PRIVATE void
Set_boolean_in_PSI_for_initial_nulls(struct s_bocage_setup_per_ys*per_ys_data,
YIM yim)
{
const AHM ahm= AHM_of_YIM(yim);
if(Null_Count_of_AHM(ahm))
psi_test_and_set(per_ys_data,(yim));
}

/*:871*//*896:*/
#line 10425 "./marpa.w"

PRIVATE OR or_node_new(BOCAGE b)
{
const int or_node_id= OR_Count_of_B(b)++;
const OR new_or_node= (OR)marpa_obs_new(OBS_of_B(b),OR_Object,1);
ID_of_OR(new_or_node)= or_node_id;
DANDs_of_OR(new_or_node)= NULL;
if(_MARPA_UNLIKELY(or_node_id>=OR_Capacity_of_B(b)))
{
OR_Capacity_of_B(b)*= 2;
ORs_of_B(b)= 
marpa_renew(OR,ORs_of_B(b),OR_Capacity_of_B(b));
}
OR_of_B_by_ID(b,or_node_id)= new_or_node;
return new_or_node;
}

/*:896*//*906:*/
#line 10625 "./marpa.w"

PRIVATE
DAND draft_and_node_new(struct marpa_obstack*obs,OR predecessor,OR cause)
{
DAND draft_and_node= marpa_obs_new(obs,DAND_Object,1);
Predecessor_OR_of_DAND(draft_and_node)= predecessor;
Cause_OR_of_DAND(draft_and_node)= cause;
MARPA_ASSERT(cause!=NULL);
return draft_and_node;
}

/*:906*//*907:*/
#line 10636 "./marpa.w"

PRIVATE
void draft_and_node_add(struct marpa_obstack*obs,OR parent,OR predecessor,OR cause)
{
MARPA_OFF_ASSERT(Position_of_OR(parent)<=1||predecessor)
const DAND new= draft_and_node_new(obs,predecessor,cause);
Next_DAND_of_DAND(new)= DANDs_of_OR(parent);
DANDs_of_OR(parent)= new;
}

/*:907*//*915:*/
#line 10776 "./marpa.w"

PRIVATE
OR or_by_origin_and_symi(struct s_bocage_setup_per_ys*per_ys_data,
YSID origin,
SYMI symbol_instance)
{
const PSL or_psl_at_origin= per_ys_data[(origin)].t_or_psl;
return PSL_Datum(or_psl_at_origin,(symbol_instance));
}

/*:915*//*920:*/
#line 10835 "./marpa.w"

PRIVATE
int dands_are_equal(OR predecessor_a,OR cause_a,
OR predecessor_b,OR cause_b)
{
const int a_is_token= OR_is_Token(cause_a);
const int b_is_token= OR_is_Token(cause_b);
if(a_is_token!=b_is_token)return 0;
{


const int middle_of_a= predecessor_a?YS_Ord_of_OR(predecessor_a):-1;
const int middle_of_b= predecessor_b?YS_Ord_of_OR(predecessor_b):-1;
if(middle_of_a!=middle_of_b)
return 0;
}
if(a_is_token)
{
const NSYID nsyid_of_a= NSYID_of_OR(cause_a);
const NSYID nsyid_of_b= NSYID_of_OR(cause_b);
return nsyid_of_a==nsyid_of_b;
}
{

const IRLID irlid_of_a= IRLID_of_OR(cause_a);
const IRLID irlid_of_b= IRLID_of_OR(cause_b);
return irlid_of_a==irlid_of_b;
}

}

/*:920*//*921:*/
#line 10869 "./marpa.w"

PRIVATE
int dand_is_duplicate(OR parent,OR predecessor,OR cause)
{
DAND dand;
for(dand= DANDs_of_OR(parent);dand;dand= Next_DAND_of_DAND(dand)){
if(dands_are_equal(predecessor,cause,
Predecessor_OR_of_DAND(dand),Cause_OR_of_DAND(dand)))
{
return 1;
}
}
return 0;
}

/*:921*//*922:*/
#line 10884 "./marpa.w"

PRIVATE
OR set_or_from_yim(struct s_bocage_setup_per_ys*per_ys_data,
YIM psi_yim)
{
const YIM psi_earley_item= psi_yim;
const int psi_earley_set_ordinal= YS_Ord_of_YIM(psi_earley_item);
const int psi_item_ordinal= Ord_of_YIM(psi_earley_item);
return OR_by_PSI(per_ys_data,psi_earley_set_ordinal,psi_item_ordinal);
}

/*:922*//*925:*/
#line 10942 "./marpa.w"

PRIVATE
OR safe_or_from_yim(
struct s_bocage_setup_per_ys*per_ys_data,
YIM yim)
{
if(Position_of_AHM(AHM_of_YIM(yim))<1)return NULL;
return set_or_from_yim(per_ys_data,yim);
}

/*:925*//*942:*/
#line 11094 "./marpa.w"

Marpa_Bocage marpa_b_new(Marpa_Recognizer r,
Marpa_Earley_Set_ID ordinal_arg)
{
/*1208:*/
#line 14586 "./marpa.w"
void*const failure_indicator= NULL;
/*:1208*/
#line 11098 "./marpa.w"

/*945:*/
#line 11165 "./marpa.w"

const GRAMMAR g= G_of_R(r);
const int xsy_count= XSY_Count_of_G(g);
BOCAGE b= NULL;
YS end_of_parse_earley_set;
JEARLEME end_of_parse_earleme;
YIM start_yim= NULL;
struct marpa_obstack*bocage_setup_obs= NULL;
int count_of_earley_items_in_parse;
const int earley_set_count_of_r= YS_Count_of_R(r);

/*:945*//*948:*/
#line 11188 "./marpa.w"

struct s_bocage_setup_per_ys*per_ys_data= NULL;

/*:948*/
#line 11099 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 11100 "./marpa.w"

if(_MARPA_UNLIKELY(ordinal_arg<=-2))
{
MARPA_ERROR(MARPA_ERR_INVALID_LOCATION);
return failure_indicator;
}

/*1226:*/
#line 14698 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1226*/
#line 11107 "./marpa.w"

{
struct marpa_obstack*const obstack= marpa_obs_init;
b= marpa_obs_new(obstack,struct marpa_bocage,1);
OBS_of_B(b)= obstack;
}
/*887:*/
#line 10297 "./marpa.w"

ORs_of_B(b)= NULL;
OR_Count_of_B(b)= 0;
ANDs_of_B(b)= NULL;
AND_Count_of_B(b)= 0;
Top_ORID_of_B(b)= -1;

/*:887*//*890:*/
#line 10320 "./marpa.w"

{
G_of_B(b)= G_of_R(r);
grammar_ref(g);
}

/*:890*//*944:*/
#line 11160 "./marpa.w"

Valued_BV_of_B(b)= lbv_clone(b->t_obs,r->t_valued,xsy_count);
Valued_Locked_BV_of_B(b)= 
lbv_clone(b->t_obs,r->t_valued_locked,xsy_count);

/*:944*//*958:*/
#line 11305 "./marpa.w"

Ambiguity_Metric_of_B(b)= 1;

/*:958*//*962:*/
#line 11319 "./marpa.w"

b->t_ref_count= 1;
/*:962*//*969:*/
#line 11378 "./marpa.w"

B_is_Nulling(b)= 0;
/*:969*/
#line 11113 "./marpa.w"


if(G_is_Trivial(g)){
switch(ordinal_arg){
default:goto NO_PARSE;
case 0:case-1:break;
}
B_is_Nulling(b)= 1;
return b;
}
r_update_earley_sets(r);
/*949:*/
#line 11191 "./marpa.w"

{
if(ordinal_arg==-1)
{
end_of_parse_earley_set= YS_at_Current_Earleme_of_R(r);
}
else
{
if(!YS_Ord_is_Valid(r,ordinal_arg))
{
MARPA_ERROR(MARPA_ERR_INVALID_LOCATION);
return failure_indicator;
}
end_of_parse_earley_set= YS_of_R_by_Ord(r,ordinal_arg);
}

if(!end_of_parse_earley_set)
goto NO_PARSE;
end_of_parse_earleme= Earleme_of_YS(end_of_parse_earley_set);
}

/*:949*/
#line 11124 "./marpa.w"

if(end_of_parse_earleme==0)
{
if(!XSY_is_Nullable(XSY_by_ID(g->t_start_xsy_id)))
goto NO_PARSE;
B_is_Nulling(b)= 1;
return b;
}
/*952:*/
#line 11257 "./marpa.w"

{
int yim_ix;
YIM*const earley_items= YIMs_of_YS(end_of_parse_earley_set);
const IRL start_irl= g->t_start_irl;
const IRLID sought_irl_id= ID_of_IRL(start_irl);
const int earley_item_count= YIM_Count_of_YS(end_of_parse_earley_set);
for(yim_ix= 0;yim_ix<earley_item_count;yim_ix++){
const YIM earley_item= earley_items[yim_ix];
if(Origin_Earleme_of_YIM(earley_item)> 0)continue;
if(YIM_was_Predicted(earley_item))continue;
{
const AHM ahm= AHM_of_YIM(earley_item);
if(IRLID_of_AHM(ahm)==sought_irl_id){
start_yim= earley_item;
break;
}
}
}
}

/*:952*/
#line 11132 "./marpa.w"

if(!start_yim)goto NO_PARSE;
bocage_setup_obs= marpa_obs_init;
/*950:*/
#line 11213 "./marpa.w"

{
int earley_set_ordinal;
int earley_set_count= YS_Count_of_R(r);
count_of_earley_items_in_parse= 0;
per_ys_data= marpa_obs_new(
bocage_setup_obs,struct s_bocage_setup_per_ys,earley_set_count);
for(earley_set_ordinal= 0;earley_set_ordinal<earley_set_count;
earley_set_ordinal++)
{
const YS_Const earley_set= YS_of_R_by_Ord(r,earley_set_ordinal);
const int item_count= YIM_Count_of_YS(earley_set);
count_of_earley_items_in_parse+= item_count;
{
int item_ordinal;
struct s_bocage_setup_per_ys*per_ys= per_ys_data+earley_set_ordinal;
per_ys->t_or_node_by_item= 
marpa_obs_new(bocage_setup_obs,OR,item_count);
per_ys->t_or_psl= NULL;
per_ys->t_and_psl= NULL;
for(item_ordinal= 0;item_ordinal<item_count;item_ordinal++)
{
OR_by_PSI(per_ys_data,earley_set_ordinal,item_ordinal)= NULL;
}
}
}
}

/*:950*/
#line 11135 "./marpa.w"

/*867:*/
#line 10045 "./marpa.w"

{
UR_Const ur_node;
const URS ur_node_stack= URS_of_R(r);
ur_node_stack_reset(ur_node_stack);


push_ur_if_new(per_ys_data,ur_node_stack,start_yim);
while((ur_node= ur_node_pop(ur_node_stack)))
{

const YIM parent_earley_item= YIM_of_UR(ur_node);
MARPA_ASSERT(!YIM_was_Predicted(parent_earley_item))
/*870:*/
#line 10098 "./marpa.w"

{
SRCL source_link;
for(source_link= First_Token_SRCL_of_YIM(parent_earley_item);
source_link;source_link= Next_SRCL_of_SRCL(source_link))
{
YIM predecessor_earley_item;
if(!SRCL_is_Active(source_link))continue;
predecessor_earley_item= Predecessor_of_SRCL(source_link);
if(!predecessor_earley_item)continue;
if(YIM_was_Predicted(predecessor_earley_item))
{
Set_boolean_in_PSI_for_initial_nulls(per_ys_data,
predecessor_earley_item);
continue;
}
push_ur_if_new(per_ys_data,ur_node_stack,predecessor_earley_item);
}
}

/*:870*/
#line 10058 "./marpa.w"

/*872:*/
#line 10132 "./marpa.w"

{
SRCL source_link;
for(source_link= First_Completion_SRCL_of_YIM(parent_earley_item);
source_link;source_link= Next_SRCL_of_SRCL(source_link))
{
YIM predecessor_earley_item;
YIM cause_earley_item;
if(!SRCL_is_Active(source_link))continue;
cause_earley_item= Cause_of_SRCL(source_link);
push_ur_if_new(per_ys_data,ur_node_stack,cause_earley_item);
predecessor_earley_item= Predecessor_of_SRCL(source_link);
if(!predecessor_earley_item)continue;
if(YIM_was_Predicted(predecessor_earley_item))
{
Set_boolean_in_PSI_for_initial_nulls(per_ys_data,
predecessor_earley_item);
continue;
}
push_ur_if_new(per_ys_data,ur_node_stack,predecessor_earley_item);
}
}

/*:872*/
#line 10059 "./marpa.w"

/*873:*/
#line 10155 "./marpa.w"

{
SRCL source_link;

for(source_link= First_Leo_SRCL_of_YIM(parent_earley_item);
source_link;source_link= Next_SRCL_of_SRCL(source_link))
{
LIM leo_predecessor;
YIM cause_earley_item;



if(!SRCL_is_Active(source_link))
continue;
cause_earley_item= Cause_of_SRCL(source_link);
push_ur_if_new(per_ys_data,ur_node_stack,cause_earley_item);
for(leo_predecessor= LIM_of_SRCL(source_link);leo_predecessor;

leo_predecessor= Predecessor_LIM_of_LIM(leo_predecessor))
{
const YIM leo_base_yim= Trailhead_YIM_of_LIM(leo_predecessor);
if(YIM_was_Predicted(leo_base_yim))
{
Set_boolean_in_PSI_for_initial_nulls(per_ys_data,
leo_base_yim);
}
else
{
push_ur_if_new(per_ys_data,ur_node_stack,leo_base_yim);
}
}
}
}

/*:873*/
#line 10060 "./marpa.w"

}
}

/*:867*/
#line 11136 "./marpa.w"

/*891:*/
#line 10327 "./marpa.w"

{
PSAR_Object or_per_ys_arena;
const PSAR or_psar= &or_per_ys_arena;
int work_earley_set_ordinal;
OR_Capacity_of_B(b)= count_of_earley_items_in_parse;
ORs_of_B(b)= marpa_new(OR,OR_Capacity_of_B(b));
psar_init(or_psar,SYMI_Count_of_G(g));
for(work_earley_set_ordinal= 0;
work_earley_set_ordinal<earley_set_count_of_r;
work_earley_set_ordinal++)
{
const YS_Const earley_set= YS_of_R_by_Ord(r,work_earley_set_ordinal);
YIM*const yims_of_ys= YIMs_of_YS(earley_set);
const int item_count= YIM_Count_of_YS(earley_set);
PSL this_earley_set_psl;
psar_dealloc(or_psar);
this_earley_set_psl
= psl_claim_by_es(or_psar,per_ys_data,work_earley_set_ordinal);
/*892:*/
#line 10353 "./marpa.w"

{
int item_ordinal;
for(item_ordinal= 0;item_ordinal<item_count;
item_ordinal++)
{
if(OR_by_PSI(per_ys_data,work_earley_set_ordinal,item_ordinal))
{
const YIM work_earley_item= yims_of_ys[item_ordinal];
{
/*893:*/
#line 10369 "./marpa.w"

{
AHM ahm= AHM_of_YIM(work_earley_item);
const int working_ys_ordinal= YS_Ord_of_YIM(work_earley_item);
const int working_yim_ordinal= Ord_of_YIM(work_earley_item);
const int work_origin_ordinal= 
Ord_of_YS(Origin_of_YIM(work_earley_item));
SYMI ahm_symbol_instance;
OR psi_or_node= NULL;
ahm_symbol_instance= SYMI_of_AHM(ahm);
{
PSL or_psl= psl_claim_by_es(or_psar,per_ys_data,work_origin_ordinal);
OR last_or_node= NULL;
/*895:*/
#line 10403 "./marpa.w"

{
if(ahm_symbol_instance>=0)
{
OR or_node;
MARPA_ASSERT(ahm_symbol_instance<SYMI_Count_of_G(g))
or_node= PSL_Datum(or_psl,ahm_symbol_instance);
if(!or_node||YS_Ord_of_OR(or_node)!=work_earley_set_ordinal)
{
const IRL irl= IRL_of_AHM(ahm);
or_node= last_or_node= or_node_new(b);
PSL_Datum(or_psl,ahm_symbol_instance)= last_or_node;
Origin_Ord_of_OR(or_node)= Origin_Ord_of_YIM(work_earley_item);
YS_Ord_of_OR(or_node)= work_earley_set_ordinal;
IRL_of_OR(or_node)= irl;
Position_of_OR(or_node)= 
ahm_symbol_instance-SYMI_of_IRL(irl)+1;
}
psi_or_node= or_node;
}
}

/*:895*/
#line 10382 "./marpa.w"

/*898:*/
#line 10451 "./marpa.w"

{
const int null_count= Null_Count_of_AHM(ahm);
if(null_count> 0)
{
const IRL irl= IRL_of_AHM(ahm);
const int symbol_instance_of_rule= SYMI_of_IRL(irl);
const int first_null_symbol_instance= 
ahm_symbol_instance<
0?symbol_instance_of_rule:ahm_symbol_instance+1;
int i;
for(i= 0;i<null_count;i++)
{
const int symbol_instance= first_null_symbol_instance+i;
OR or_node= PSL_Datum(or_psl,symbol_instance);
if(!or_node||YS_Ord_of_OR(or_node)!=work_earley_set_ordinal){
const int rhs_ix= symbol_instance-symbol_instance_of_rule;
const OR predecessor= rhs_ix?last_or_node:NULL;
const OR cause= Nulling_OR_by_NSYID(RHSID_of_IRL(irl,rhs_ix));
or_node= PSL_Datum(or_psl,symbol_instance)
= last_or_node= or_node_new(b);
Origin_Ord_of_OR(or_node)= work_origin_ordinal;
YS_Ord_of_OR(or_node)= work_earley_set_ordinal;
IRL_of_OR(or_node)= irl;
Position_of_OR(or_node)= rhs_ix+1;
MARPA_ASSERT(Position_of_OR(or_node)<=1||predecessor);
draft_and_node_add(bocage_setup_obs,or_node,predecessor,
cause);
}
psi_or_node= or_node;
}
}
}

/*:898*/
#line 10383 "./marpa.w"

}



MARPA_OFF_ASSERT(psi_or_node)




OR_by_PSI(per_ys_data,working_ys_ordinal,working_yim_ordinal)
= psi_or_node;
/*899:*/
#line 10486 "./marpa.w"

{
SRCL source_link;
for(source_link= First_Leo_SRCL_of_YIM(work_earley_item);
source_link;source_link= Next_SRCL_of_SRCL(source_link))
{
LIM leo_predecessor= LIM_of_SRCL(source_link);
if(leo_predecessor){
/*900:*/
#line 10503 "./marpa.w"

{
LIM this_leo_item= leo_predecessor;
LIM previous_leo_item= this_leo_item;
while((this_leo_item= Predecessor_LIM_of_LIM(this_leo_item)))
{
const int ordinal_of_set_of_this_leo_item= Ord_of_YS(YS_of_LIM(this_leo_item));
const AHM path_ahm= Trailhead_AHM_of_LIM(previous_leo_item);
const IRL path_irl= IRL_of_AHM(path_ahm);
const int symbol_instance_of_path_ahm= SYMI_of_AHM(path_ahm);
{
OR last_or_node= NULL;
/*901:*/
#line 10525 "./marpa.w"

{
{
OR or_node;
PSL leo_psl
= psl_claim_by_es(or_psar,per_ys_data,ordinal_of_set_of_this_leo_item);
or_node= PSL_Datum(leo_psl,symbol_instance_of_path_ahm);
if(!or_node||YS_Ord_of_OR(or_node)!=work_earley_set_ordinal)
{
last_or_node= or_node_new(b);
PSL_Datum(leo_psl,symbol_instance_of_path_ahm)= or_node= 
last_or_node;
Origin_Ord_of_OR(or_node)= ordinal_of_set_of_this_leo_item;
YS_Ord_of_OR(or_node)= work_earley_set_ordinal;
IRL_of_OR(or_node)= path_irl;
Position_of_OR(or_node)= 
symbol_instance_of_path_ahm-SYMI_of_IRL(path_irl)+1;
}
}
}

/*:901*/
#line 10515 "./marpa.w"

/*902:*/
#line 10550 "./marpa.w"

{
int i;
const int null_count= Null_Count_of_AHM(path_ahm);
for(i= 1;i<=null_count;i++)
{
const int symbol_instance= symbol_instance_of_path_ahm+i;
OR or_node= PSL_Datum(this_earley_set_psl,symbol_instance);
MARPA_ASSERT(symbol_instance<SYMI_Count_of_G(g))
if(!or_node||YS_Ord_of_OR(or_node)!=work_earley_set_ordinal)
{
const int rhs_ix= symbol_instance-SYMI_of_IRL(path_irl);
MARPA_ASSERT(rhs_ix<Length_of_IRL(path_irl))
const OR predecessor= rhs_ix?last_or_node:NULL;
const OR cause= Nulling_OR_by_NSYID(RHSID_of_IRL(path_irl,rhs_ix));
MARPA_ASSERT(symbol_instance<Length_of_IRL(path_irl))
MARPA_ASSERT(symbol_instance>=0)
or_node= last_or_node= or_node_new(b);
PSL_Datum(this_earley_set_psl,symbol_instance)= or_node;
Origin_Ord_of_OR(or_node)= ordinal_of_set_of_this_leo_item;
YS_Ord_of_OR(or_node)= work_earley_set_ordinal;
IRL_of_OR(or_node)= path_irl;
Position_of_OR(or_node)= rhs_ix+1;
MARPA_ASSERT(Position_of_OR(or_node)<=1||predecessor);
draft_and_node_add(bocage_setup_obs,or_node,predecessor,cause);
}
MARPA_ASSERT(Position_of_OR(or_node)<=
SYMI_of_IRL(path_irl)+Length_of_IRL(path_irl))
MARPA_ASSERT(Position_of_OR(or_node)>=SYMI_of_IRL(path_irl))
}
}

/*:902*/
#line 10516 "./marpa.w"

}
previous_leo_item= this_leo_item;
}
}

/*:900*/
#line 10494 "./marpa.w"

}
}
}

/*:899*/
#line 10395 "./marpa.w"

}

/*:893*/
#line 10363 "./marpa.w"

}
}
}
}

/*:892*/
#line 10346 "./marpa.w"

/*908:*/
#line 10646 "./marpa.w"

{
int item_ordinal;
for(item_ordinal= 0;item_ordinal<item_count;item_ordinal++)
{
OR or_node= OR_by_PSI(per_ys_data,work_earley_set_ordinal,item_ordinal);
const YIM work_earley_item= yims_of_ys[item_ordinal];
const int work_origin_ordinal= Ord_of_YS(Origin_of_YIM(work_earley_item));
/*909:*/
#line 10663 "./marpa.w"

{
while(or_node){
DAND draft_and_node= DANDs_of_OR(or_node);
OR predecessor_or;
if(!draft_and_node)break;
predecessor_or= Predecessor_OR_of_DAND(draft_and_node);
if(predecessor_or&&
YS_Ord_of_OR(predecessor_or)!=work_earley_set_ordinal)
break;
or_node= predecessor_or;
}
}

/*:909*/
#line 10654 "./marpa.w"

if(or_node){
/*910:*/
#line 10677 "./marpa.w"

{
const AHM work_ahm= AHM_of_YIM(work_earley_item);
MARPA_ASSERT(work_ahm>=AHM_by_ID(1))
const int work_symbol_instance= SYMI_of_AHM(work_ahm);
const OR work_proper_or_node= or_by_origin_and_symi(per_ys_data,
work_origin_ordinal,work_symbol_instance);
/*912:*/
#line 10719 "./marpa.w"

{
SRCL source_link;
for(source_link= First_Leo_SRCL_of_YIM(work_earley_item);
source_link;source_link= Next_SRCL_of_SRCL(source_link))
{
YIM cause_earley_item;
LIM leo_predecessor;



if(!SRCL_is_Active(source_link))continue;
cause_earley_item= Cause_of_SRCL(source_link);
leo_predecessor= LIM_of_SRCL(source_link);
if(leo_predecessor){
/*913:*/
#line 10740 "./marpa.w"

{

IRL path_irl= NULL;

IRL previous_path_irl;
LIM path_leo_item= leo_predecessor;
LIM higher_path_leo_item= Predecessor_LIM_of_LIM(path_leo_item);
OR dand_predecessor;
OR path_or_node;
YIM base_earley_item= Trailhead_YIM_of_LIM(path_leo_item);
dand_predecessor= set_or_from_yim(per_ys_data,base_earley_item);
/*914:*/
#line 10767 "./marpa.w"

{
if(higher_path_leo_item){
/*923:*/
#line 10895 "./marpa.w"

{
int symbol_instance;
const int origin_ordinal= Origin_Ord_of_YIM(base_earley_item);
const AHM ahm= AHM_of_YIM(base_earley_item);
path_irl= IRL_of_AHM(ahm);
symbol_instance= Last_Proper_SYMI_of_IRL(path_irl);
path_or_node= or_by_origin_and_symi(per_ys_data,origin_ordinal,symbol_instance);
}


/*:923*/
#line 10770 "./marpa.w"

}else{
path_or_node= work_proper_or_node;
}
}

/*:914*/
#line 10752 "./marpa.w"

/*916:*/
#line 10786 "./marpa.w"

{
const OR dand_cause
= set_or_from_yim(per_ys_data,cause_earley_item);
if(!dand_is_duplicate(path_or_node,dand_predecessor,dand_cause)){
draft_and_node_add(bocage_setup_obs,path_or_node,
dand_predecessor,dand_cause);
}
}

/*:916*/
#line 10753 "./marpa.w"

previous_path_irl= path_irl;
while(higher_path_leo_item){
path_leo_item= higher_path_leo_item;
higher_path_leo_item= Predecessor_LIM_of_LIM(path_leo_item);
base_earley_item= Trailhead_YIM_of_LIM(path_leo_item);
dand_predecessor
= set_or_from_yim(per_ys_data,base_earley_item);
/*914:*/
#line 10767 "./marpa.w"

{
if(higher_path_leo_item){
/*923:*/
#line 10895 "./marpa.w"

{
int symbol_instance;
const int origin_ordinal= Origin_Ord_of_YIM(base_earley_item);
const AHM ahm= AHM_of_YIM(base_earley_item);
path_irl= IRL_of_AHM(ahm);
symbol_instance= Last_Proper_SYMI_of_IRL(path_irl);
path_or_node= or_by_origin_and_symi(per_ys_data,origin_ordinal,symbol_instance);
}


/*:923*/
#line 10770 "./marpa.w"

}else{
path_or_node= work_proper_or_node;
}
}

/*:914*/
#line 10761 "./marpa.w"

/*919:*/
#line 10812 "./marpa.w"

{
const SYMI symbol_instance= SYMI_of_Completed_IRL(previous_path_irl);
const int origin= Ord_of_YS(YS_of_LIM(path_leo_item));
const OR dand_cause= or_by_origin_and_symi(per_ys_data,origin,symbol_instance);
if(!dand_is_duplicate(path_or_node,dand_predecessor,dand_cause)){
draft_and_node_add(bocage_setup_obs,path_or_node,
dand_predecessor,dand_cause);
}
}

/*:919*/
#line 10762 "./marpa.w"

previous_path_irl= path_irl;
}
}

/*:913*/
#line 10734 "./marpa.w"

}
}
}

/*:912*/
#line 10684 "./marpa.w"

/*924:*/
#line 10910 "./marpa.w"

{
SRCL tkn_source_link;
for(tkn_source_link= First_Token_SRCL_of_YIM(work_earley_item);
tkn_source_link;tkn_source_link= Next_SRCL_of_SRCL(tkn_source_link))
{
OR new_token_or_node;
const NSYID token_nsyid= NSYID_of_SRCL(tkn_source_link);
const YIM predecessor_earley_item= Predecessor_of_SRCL(tkn_source_link);
const OR dand_predecessor= safe_or_from_yim(per_ys_data,
predecessor_earley_item);
if(NSYID_is_Valued_in_B(b,token_nsyid))
{



new_token_or_node= (OR)marpa_obs_new(OBS_of_B(b),OR_Object,1);
Type_of_OR(new_token_or_node)= VALUED_TOKEN_OR_NODE;
NSYID_of_OR(new_token_or_node)= token_nsyid;
Value_of_OR(new_token_or_node)= Value_of_SRCL(tkn_source_link);
}
else
{
new_token_or_node= Unvalued_OR_by_NSYID(token_nsyid);
}
draft_and_node_add(bocage_setup_obs,work_proper_or_node,
dand_predecessor,new_token_or_node);
}
}

/*:924*/
#line 10685 "./marpa.w"

/*926:*/
#line 10952 "./marpa.w"

{
SRCL source_link;
for(source_link= First_Completion_SRCL_of_YIM(work_earley_item);
source_link;source_link= Next_SRCL_of_SRCL(source_link))
{
YIM predecessor_earley_item= Predecessor_of_SRCL(source_link);
YIM cause_earley_item= Cause_of_SRCL(source_link);
const int middle_ordinal= Origin_Ord_of_YIM(cause_earley_item);
const AHM cause_ahm= AHM_of_YIM(cause_earley_item);
const SYMI cause_symbol_instance= 
SYMI_of_Completed_IRL(IRL_of_AHM(cause_ahm));
OR dand_predecessor= safe_or_from_yim(per_ys_data,
predecessor_earley_item);
const OR dand_cause= 
or_by_origin_and_symi(per_ys_data,middle_ordinal,
cause_symbol_instance);
draft_and_node_add(bocage_setup_obs,work_proper_or_node,
dand_predecessor,dand_cause);
}
}

/*:926*/
#line 10686 "./marpa.w"

}

/*:910*/
#line 10656 "./marpa.w"

}
}
}

/*:908*/
#line 10347 "./marpa.w"

}
psar_destroy(or_psar);
ORs_of_B(b)= marpa_renew(OR,ORs_of_B(b),OR_Count_of_B(b));
}

/*:891*/
#line 11137 "./marpa.w"

/*932:*/
#line 11024 "./marpa.w"

{
int unique_draft_and_node_count= 0;
/*927:*/
#line 10977 "./marpa.w"

{
const int or_node_count_of_b= OR_Count_of_B(b);
int or_node_id= 0;
while(or_node_id<or_node_count_of_b)
{
const OR work_or_node= OR_of_B_by_ID(b,or_node_id);
DAND dand= DANDs_of_OR(work_or_node);
while(dand)
{
unique_draft_and_node_count++;
dand= Next_DAND_of_DAND(dand);
}
or_node_id++;
}
}

/*:927*/
#line 11027 "./marpa.w"

/*933:*/
#line 11031 "./marpa.w"

{
const int or_count_of_b= OR_Count_of_B(b);
int or_node_id;
int and_node_id= 0;
const AND ands_of_b= ANDs_of_B(b)= 
marpa_new(AND_Object,unique_draft_and_node_count);
for(or_node_id= 0;or_node_id<or_count_of_b;or_node_id++)
{
int and_count_of_parent_or= 0;
const OR or_node= OR_of_B_by_ID(b,or_node_id);
DAND dand= DANDs_of_OR(or_node);
First_ANDID_of_OR(or_node)= and_node_id;
while(dand)
{
const OR cause_or_node= Cause_OR_of_DAND(dand);
const AND and_node= ands_of_b+and_node_id;
OR_of_AND(and_node)= or_node;
Predecessor_OR_of_AND(and_node)= Predecessor_OR_of_DAND(dand);
Cause_OR_of_AND(and_node)= cause_or_node;
and_node_id++;
and_count_of_parent_or++;
dand= Next_DAND_of_DAND(dand);
}
AND_Count_of_OR(or_node)= and_count_of_parent_or;
if(and_count_of_parent_or> 1)Ambiguity_Metric_of_B(b)= 2;
}
AND_Count_of_B(b)= and_node_id;
MARPA_ASSERT(and_node_id==unique_draft_and_node_count);
}


/*:933*/
#line 11028 "./marpa.w"

}

/*:932*/
#line 11138 "./marpa.w"

/*953:*/
#line 11278 "./marpa.w"

{
const YSID end_of_parse_ordinal= Ord_of_YS(end_of_parse_earley_set);
const int start_earley_item_ordinal= Ord_of_YIM(start_yim);
const OR root_or_node= 
OR_by_PSI(per_ys_data,end_of_parse_ordinal,start_earley_item_ordinal);
Top_ORID_of_B(b)= ID_of_OR(root_or_node);
}

/*:953*/
#line 11139 "./marpa.w"
;
marpa_obs_free(bocage_setup_obs);
return b;
NO_PARSE:;
MARPA_ERROR(MARPA_ERR_NO_PARSE);
if(b){
/*965:*/
#line 11355 "./marpa.w"

/*888:*/
#line 10304 "./marpa.w"

{
OR*or_nodes= ORs_of_B(b);
AND and_nodes= ANDs_of_B(b);

grammar_unref(G_of_B(b));
my_free(or_nodes);
ORs_of_B(b)= NULL;
my_free(and_nodes);
ANDs_of_B(b)= NULL;
}

/*:888*/
#line 11356 "./marpa.w"
;
/*941:*/
#line 11090 "./marpa.w"

marpa_obs_free(OBS_of_B(b));

/*:941*/
#line 11357 "./marpa.w"
;

/*:965*/
#line 11145 "./marpa.w"
;
}
return NULL;
}

/*:942*//*955:*/
#line 11289 "./marpa.w"

Marpa_Or_Node_ID _marpa_b_top_or_node(Marpa_Bocage b)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 11292 "./marpa.w"

/*939:*/
#line 11082 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:939*/
#line 11293 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 11294 "./marpa.w"

return Top_ORID_of_B(b);
}

/*:955*//*959:*/
#line 11308 "./marpa.w"

int marpa_b_ambiguity_metric(Marpa_Bocage b)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 11311 "./marpa.w"

/*939:*/
#line 11082 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:939*/
#line 11312 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 11313 "./marpa.w"

return Ambiguity_Metric_of_B(b);
}

/*:959*//*963:*/
#line 11322 "./marpa.w"

PRIVATE void
bocage_unref(BOCAGE b)
{
MARPA_ASSERT(b->t_ref_count> 0)
b->t_ref_count--;
if(b->t_ref_count<=0)
{
bocage_free(b);
}
}
void
marpa_b_unref(Marpa_Bocage b)
{
bocage_unref(b);
}

/*:963*//*964:*/
#line 11340 "./marpa.w"

PRIVATE BOCAGE
bocage_ref(BOCAGE b)
{
MARPA_ASSERT(b->t_ref_count> 0)
b->t_ref_count++;
return b;
}
Marpa_Bocage
marpa_b_ref(Marpa_Bocage b)
{
return bocage_ref(b);
}

/*:964*//*966:*/
#line 11362 "./marpa.w"

PRIVATE void
bocage_free(BOCAGE b)
{
/*939:*/
#line 11082 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:939*/
#line 11366 "./marpa.w"

if(b)
{
/*965:*/
#line 11355 "./marpa.w"

/*888:*/
#line 10304 "./marpa.w"

{
OR*or_nodes= ORs_of_B(b);
AND and_nodes= ANDs_of_B(b);

grammar_unref(G_of_B(b));
my_free(or_nodes);
ORs_of_B(b)= NULL;
my_free(and_nodes);
ANDs_of_B(b)= NULL;
}

/*:888*/
#line 11356 "./marpa.w"
;
/*941:*/
#line 11090 "./marpa.w"

marpa_obs_free(OBS_of_B(b));

/*:941*/
#line 11357 "./marpa.w"
;

/*:965*/
#line 11369 "./marpa.w"
;
}
}

/*:966*//*970:*/
#line 11380 "./marpa.w"

int marpa_b_is_null(Marpa_Bocage b)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 11383 "./marpa.w"

/*939:*/
#line 11082 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:939*/
#line 11384 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 11385 "./marpa.w"

return B_is_Nulling(b);
}

/*:970*//*977:*/
#line 11425 "./marpa.w"

Marpa_Order marpa_o_new(Marpa_Bocage b)
{
/*1208:*/
#line 14586 "./marpa.w"
void*const failure_indicator= NULL;
/*:1208*/
#line 11428 "./marpa.w"

/*939:*/
#line 11082 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:939*/
#line 11429 "./marpa.w"

ORDER o;
/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 11431 "./marpa.w"

o= my_malloc(sizeof(*o));
B_of_O(o)= b;
bocage_ref(b);
/*974:*/
#line 11413 "./marpa.w"

{
o->t_and_node_orderings= NULL;
o->t_is_frozen= 0;
OBS_of_O(o)= NULL;
}

/*:974*//*980:*/
#line 11443 "./marpa.w"

o->t_ref_count= 1;

/*:980*//*993:*/
#line 11611 "./marpa.w"

High_Rank_Count_of_O(o)= 1;
/*:993*/
#line 11435 "./marpa.w"

O_is_Nulling(o)= B_is_Nulling(b);
Ambiguity_Metric_of_O(o)= -1;
return o;
}

/*:977*//*981:*/
#line 11447 "./marpa.w"

PRIVATE void
order_unref(ORDER o)
{
MARPA_ASSERT(o->t_ref_count> 0)
o->t_ref_count--;
if(o->t_ref_count<=0)
{
order_free(o);
}
}
void
marpa_o_unref(Marpa_Order o)
{
order_unref(o);
}

/*:981*//*982:*/
#line 11465 "./marpa.w"

PRIVATE ORDER
order_ref(ORDER o)
{
MARPA_ASSERT(o->t_ref_count> 0)
o->t_ref_count++;
return o;
}
Marpa_Order
marpa_o_ref(Marpa_Order o)
{
return order_ref(o);
}

/*:982*//*983:*/
#line 11479 "./marpa.w"

PRIVATE void order_free(ORDER o)
{
/*984:*/
#line 11488 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*939:*/
#line 11082 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:939*/
#line 11490 "./marpa.w"


/*:984*/
#line 11482 "./marpa.w"

bocage_unref(b);
marpa_obs_free(OBS_of_O(o));
my_free(o);
}

/*:983*//*987:*/
#line 11500 "./marpa.w"

int marpa_o_ambiguity_metric(Marpa_Order o)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 11503 "./marpa.w"

/*984:*/
#line 11488 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*939:*/
#line 11082 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:939*/
#line 11490 "./marpa.w"


/*:984*/
#line 11504 "./marpa.w"

const int old_ambiguity_metric_of_o
= Ambiguity_Metric_of_O(o);
const int ambiguity_metric_of_b
= (Ambiguity_Metric_of_B(b)<=1?1:2);
/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 11509 "./marpa.w"

O_is_Frozen(o)= 1;
if(old_ambiguity_metric_of_o>=0)
return old_ambiguity_metric_of_o;
if(ambiguity_metric_of_b<2
||O_is_Default(o)
||High_Rank_Count_of_O(o)<=0
){
Ambiguity_Metric_of_O(o)= ambiguity_metric_of_b;
return ambiguity_metric_of_b;
}
/*988:*/
#line 11528 "./marpa.w"

{
ANDID**const and_node_orderings= o->t_and_node_orderings;
const AND and_nodes= ANDs_of_B(b);
ORID*top_of_stack;
const ORID root_or_id= Top_ORID_of_B(b);
FSTACK_DECLARE(or_node_stack,ORID)
const int or_count= OR_Count_of_B(b);
Bit_Vector bv_orid_was_stacked;
Ambiguity_Metric_of_O(o)= 1;


bv_orid_was_stacked= bv_create(or_count);
FSTACK_INIT(or_node_stack,ORID,or_count);
*(FSTACK_PUSH(or_node_stack))= root_or_id;
bv_bit_set(bv_orid_was_stacked,root_or_id);
while((top_of_stack= FSTACK_POP(or_node_stack)))
{
const ORID or_id= *top_of_stack;
const OR or_node= OR_of_B_by_ID(b,or_id);
ANDID*ordering= and_node_orderings[or_id];
int and_count= ordering?ordering[0]:AND_Count_of_OR(or_node);
if(and_count> 1)
{



Ambiguity_Metric_of_O(o)= 2;

goto END_OR_NODE_LOOP;

}
{
const ANDID and_id= ordering?ordering[1]:First_ANDID_of_OR(or_node);
const AND and_node= and_nodes+and_id;
const OR predecessor_or= Predecessor_OR_of_AND(and_node);
const OR cause_or= Cause_OR_of_AND(and_node);
if(predecessor_or)
{
const ORID predecessor_or_id= ID_of_OR(predecessor_or);
if(!bv_bit_test_then_set(bv_orid_was_stacked,predecessor_or_id))
{
*(FSTACK_PUSH(or_node_stack))= predecessor_or_id;
}
}
if(cause_or&&!OR_is_Token(cause_or))
{
const ORID cause_or_id= ID_of_OR(cause_or);
if(!bv_bit_test_then_set(bv_orid_was_stacked,cause_or_id))
{
*(FSTACK_PUSH(or_node_stack))= cause_or_id;
}
}
}
}
END_OR_NODE_LOOP:;
FSTACK_DESTROY(or_node_stack);
bv_free(bv_orid_was_stacked);

}

/*:988*/
#line 11520 "./marpa.w"

return Ambiguity_Metric_of_O(o);
}

/*:987*//*991:*/
#line 11594 "./marpa.w"

int marpa_o_is_null(Marpa_Order o)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 11597 "./marpa.w"

/*984:*/
#line 11488 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*939:*/
#line 11082 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:939*/
#line 11490 "./marpa.w"


/*:984*/
#line 11598 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 11599 "./marpa.w"

return O_is_Nulling(o);
}

/*:991*//*994:*/
#line 11613 "./marpa.w"

int marpa_o_high_rank_only_set(
Marpa_Order o,
int count)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 11618 "./marpa.w"

/*984:*/
#line 11488 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*939:*/
#line 11082 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:939*/
#line 11490 "./marpa.w"


/*:984*/
#line 11619 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 11620 "./marpa.w"

if(O_is_Frozen(o))
{
MARPA_ERROR(MARPA_ERR_ORDER_FROZEN);
return failure_indicator;
}
if(_MARPA_UNLIKELY(count<0||count> 1))
{
MARPA_ERROR(MARPA_ERR_INVALID_BOOLEAN);
return failure_indicator;
}
return High_Rank_Count_of_O(o)= count;
}

/*:994*//*995:*/
#line 11635 "./marpa.w"

int marpa_o_high_rank_only(Marpa_Order o)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 11638 "./marpa.w"

/*984:*/
#line 11488 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*939:*/
#line 11082 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:939*/
#line 11490 "./marpa.w"


/*:984*/
#line 11639 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 11640 "./marpa.w"

return High_Rank_Count_of_O(o);
}

/*:995*//*999:*/
#line 11677 "./marpa.w"

int marpa_o_rank(Marpa_Order o)
{
ANDID**and_node_orderings;
struct marpa_obstack*obs;
int bocage_was_reordered= 0;
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 11683 "./marpa.w"

/*984:*/
#line 11488 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*939:*/
#line 11082 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:939*/
#line 11490 "./marpa.w"


/*:984*/
#line 11684 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 11685 "./marpa.w"

if(O_is_Frozen(o))
{
MARPA_ERROR(MARPA_ERR_ORDER_FROZEN);
return failure_indicator;
}
/*1005:*/
#line 11846 "./marpa.w"

{
int and_id;
const int and_count_of_r= AND_Count_of_B(b);
obs= OBS_of_O(o)= marpa_obs_init;
o->t_and_node_orderings= 
and_node_orderings= 
marpa_obs_new(obs,ANDID*,and_count_of_r);
for(and_id= 0;and_id<and_count_of_r;and_id++)
{
and_node_orderings[and_id]= (ANDID*)NULL;
}
}

/*:1005*/
#line 11691 "./marpa.w"

if(High_Rank_Count_of_O(o)){
/*1000:*/
#line 11706 "./marpa.w"

{
const AND and_nodes= ANDs_of_B(b);
const int or_node_count_of_b= OR_Count_of_B(b);
int or_node_id= 0;

while(or_node_id<or_node_count_of_b)
{
const OR work_or_node= OR_of_B_by_ID(b,or_node_id);
const ANDID and_count_of_or= AND_Count_of_OR(work_or_node);
/*1001:*/
#line 11721 "./marpa.w"

{
if(and_count_of_or> 1)
{
int high_rank_so_far= INT_MIN;
const ANDID first_and_node_id= First_ANDID_of_OR(work_or_node);
const ANDID last_and_node_id= 
(first_and_node_id+and_count_of_or)-1;
ANDID*const order_base= 
marpa_obs_start(obs,
sizeof(ANDID)*((size_t)and_count_of_or+1),
ALIGNOF(ANDID));
ANDID*order= order_base+1;
ANDID and_node_id;
bocage_was_reordered= 1;
for(and_node_id= first_and_node_id;and_node_id<=last_and_node_id;
and_node_id++)
{
const AND and_node= and_nodes+and_node_id;
int and_node_rank;
/*1002:*/
#line 11759 "./marpa.w"

{
const OR cause_or= Cause_OR_of_AND(and_node);
if(OR_is_Token(cause_or)){
const NSYID nsy_id= NSYID_of_OR(cause_or);
and_node_rank= Rank_of_NSY(NSY_by_ID(nsy_id));
}else{
and_node_rank= Rank_of_IRL(IRL_of_OR(cause_or));
}
}

/*:1002*/
#line 11741 "./marpa.w"

if(and_node_rank> high_rank_so_far)
{
order= order_base+1;
high_rank_so_far= and_node_rank;
}
if(and_node_rank>=high_rank_so_far)
*order++= and_node_id;
}
{
int final_count= (int)(order-order_base)-1;
*order_base= final_count;
marpa_obs_confirm_fast(obs,(int)sizeof(ANDID)*(final_count+1));
and_node_orderings[or_node_id]= marpa_obs_finish(obs);
}
}
}

/*:1001*/
#line 11716 "./marpa.w"

or_node_id++;
}
}

/*:1000*/
#line 11693 "./marpa.w"

}else{
/*1003:*/
#line 11770 "./marpa.w"

{
const AND and_nodes= ANDs_of_B(b);
const int or_node_count_of_b= OR_Count_of_B(b);
const int and_node_count_of_b= AND_Count_of_B(b);
int or_node_id= 0;
int*rank_by_and_id= marpa_new(int,and_node_count_of_b);
int and_node_id;
for(and_node_id= 0;and_node_id<and_node_count_of_b;and_node_id++)
{
const AND and_node= and_nodes+and_node_id;
int and_node_rank;
/*1002:*/
#line 11759 "./marpa.w"

{
const OR cause_or= Cause_OR_of_AND(and_node);
if(OR_is_Token(cause_or)){
const NSYID nsy_id= NSYID_of_OR(cause_or);
and_node_rank= Rank_of_NSY(NSY_by_ID(nsy_id));
}else{
and_node_rank= Rank_of_IRL(IRL_of_OR(cause_or));
}
}

/*:1002*/
#line 11782 "./marpa.w"

rank_by_and_id[and_node_id]= and_node_rank;
}
while(or_node_id<or_node_count_of_b)
{
const OR work_or_node= OR_of_B_by_ID(b,or_node_id);
const ANDID and_count_of_or= AND_Count_of_OR(work_or_node);
/*1004:*/
#line 11815 "./marpa.w"

{
if(and_count_of_or> 1)
{
const ANDID first_and_node_id= First_ANDID_of_OR(work_or_node);
ANDID*const order_base= 
marpa_obs_new(obs,ANDID,and_count_of_or+1);
ANDID*order= order_base+1;
int nodes_inserted_so_far;
bocage_was_reordered= 1;
and_node_orderings[or_node_id]= order_base;
*order_base= and_count_of_or;
for(nodes_inserted_so_far= 0;nodes_inserted_so_far<and_count_of_or;
nodes_inserted_so_far++)
{
const ANDID new_and_node_id= 
first_and_node_id+nodes_inserted_so_far;
int pre_insertion_ix= nodes_inserted_so_far-1;
while(pre_insertion_ix>=0)
{
if(rank_by_and_id[new_and_node_id]<=
rank_by_and_id[order[pre_insertion_ix]])
break;
order[pre_insertion_ix+1]= order[pre_insertion_ix];
pre_insertion_ix--;
}
order[pre_insertion_ix+1]= new_and_node_id;
}
}
}

/*:1004*/
#line 11789 "./marpa.w"

or_node_id++;
}
my_free(rank_by_and_id);
}

/*:1003*/
#line 11695 "./marpa.w"

}
if(!bocage_was_reordered){
marpa_obs_free(obs);
OBS_of_O(o)= NULL;
o->t_and_node_orderings= NULL;
}
O_is_Frozen(o)= 1;
return 1;
}

/*:999*//*1006:*/
#line 11863 "./marpa.w"

PRIVATE ANDID and_order_ix_is_valid(ORDER o,OR or_node,int ix)
{
if(ix>=AND_Count_of_OR(or_node))return 0;
if(!O_is_Default(o))
{
ANDID**const and_node_orderings= o->t_and_node_orderings;
ORID or_node_id= ID_of_OR(or_node);
ANDID*ordering= and_node_orderings[or_node_id];
if(ordering)
{
int length= ordering[0];
if(ix>=length)return 0;
}
}
return 1;
}

/*:1006*//*1007:*/
#line 11884 "./marpa.w"

PRIVATE ANDID and_order_get(ORDER o,OR or_node,int ix)
{
if(!O_is_Default(o))
{
ANDID**const and_node_orderings= o->t_and_node_orderings;
ORID or_node_id= ID_of_OR(or_node);
ANDID*ordering= and_node_orderings[or_node_id];
if(ordering)
return ordering[1+ix];
}
return First_ANDID_of_OR(or_node)+ix;
}

/*:1007*//*1008:*/
#line 11898 "./marpa.w"

Marpa_And_Node_ID _marpa_o_and_order_get(Marpa_Order o,
Marpa_Or_Node_ID or_node_id,int ix)
{
OR or_node;
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 11903 "./marpa.w"

/*984:*/
#line 11488 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*939:*/
#line 11082 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:939*/
#line 11490 "./marpa.w"


/*:984*/
#line 11904 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 11905 "./marpa.w"

/*1296:*/
#line 15692 "./marpa.w"

{
if(_MARPA_UNLIKELY(or_node_id>=OR_Count_of_B(b)))
{
return-1;
}
if(_MARPA_UNLIKELY(or_node_id<0))
{
MARPA_ERROR(MARPA_ERR_ORID_NEGATIVE);
return failure_indicator;
}
}
/*:1296*/
#line 11906 "./marpa.w"

/*1297:*/
#line 15704 "./marpa.w"

{
if(_MARPA_UNLIKELY(!ORs_of_B(b)))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= OR_of_B_by_ID(b,or_node_id);
}

/*:1297*/
#line 11907 "./marpa.w"

if(ix<0){
MARPA_ERROR(MARPA_ERR_ANDIX_NEGATIVE);
return failure_indicator;
}
if(!and_order_ix_is_valid(o,or_node,ix))return-1;
return and_order_get(o,or_node,ix);
}

/*:1008*//*1013:*/
#line 11960 "./marpa.w"

PRIVATE void tree_exhaust(TREE t)
{
if(FSTACK_IS_INITIALIZED(t->t_nook_stack))
{
FSTACK_DESTROY(t->t_nook_stack);
FSTACK_SAFE(t->t_nook_stack);
}
if(FSTACK_IS_INITIALIZED(t->t_nook_worklist))
{
FSTACK_DESTROY(t->t_nook_worklist);
FSTACK_SAFE(t->t_nook_worklist);
}
bv_free(t->t_or_node_in_use);
t->t_or_node_in_use= NULL;
T_is_Exhausted(t)= 1;
}

/*:1013*//*1014:*/
#line 11978 "./marpa.w"

Marpa_Tree marpa_t_new(Marpa_Order o)
{
/*1208:*/
#line 14586 "./marpa.w"
void*const failure_indicator= NULL;
/*:1208*/
#line 11981 "./marpa.w"

TREE t;
/*984:*/
#line 11488 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*939:*/
#line 11082 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:939*/
#line 11490 "./marpa.w"


/*:984*/
#line 11983 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 11984 "./marpa.w"

t= my_malloc(sizeof(*t));
O_of_T(t)= o;
order_ref(o);
O_is_Frozen(o)= 1;
/*1031:*/
#line 12170 "./marpa.w"

T_is_Exhausted(t)= 0;

/*:1031*/
#line 11989 "./marpa.w"

/*1015:*/
#line 11994 "./marpa.w"

{
t->t_parse_count= 0;
if(O_is_Nulling(o))
{
T_is_Nulling(t)= 1;
t->t_or_node_in_use= NULL;
FSTACK_SAFE(t->t_nook_stack);
FSTACK_SAFE(t->t_nook_worklist);
}
else
{
const int and_count= AND_Count_of_B(b);
const int or_count= OR_Count_of_B(b);
T_is_Nulling(t)= 0;
t->t_or_node_in_use= bv_create(or_count);
FSTACK_INIT(t->t_nook_stack,NOOK_Object,and_count);
FSTACK_INIT(t->t_nook_worklist,int,and_count);
}
}

/*:1015*//*1018:*/
#line 12018 "./marpa.w"

t->t_ref_count= 1;

/*:1018*//*1025:*/
#line 12097 "./marpa.w"
t->t_pause_counter= 0;
/*:1025*/
#line 11990 "./marpa.w"

return t;
}

/*:1014*//*1019:*/
#line 12022 "./marpa.w"

PRIVATE void
tree_unref(TREE t)
{
MARPA_ASSERT(t->t_ref_count> 0)
t->t_ref_count--;
if(t->t_ref_count<=0)
{
tree_free(t);
}
}
void
marpa_t_unref(Marpa_Tree t)
{
tree_unref(t);
}

/*:1019*//*1020:*/
#line 12040 "./marpa.w"

PRIVATE TREE
tree_ref(TREE t)
{
MARPA_ASSERT(t->t_ref_count> 0)
t->t_ref_count++;
return t;
}
Marpa_Tree
marpa_t_ref(Marpa_Tree t)
{
return tree_ref(t);
}

/*:1020*//*1021:*/
#line 12054 "./marpa.w"

PRIVATE void tree_free(TREE t)
{
order_unref(O_of_T(t));
tree_exhaust(t);
my_free(t);
}

/*:1021*//*1026:*/
#line 12098 "./marpa.w"

PRIVATE void
tree_pause(TREE t)
{
MARPA_ASSERT(t->t_pause_counter>=0);
MARPA_ASSERT(t->t_ref_count>=t->t_pause_counter);
t->t_pause_counter++;
tree_ref(t);
}
/*:1026*//*1027:*/
#line 12107 "./marpa.w"

PRIVATE void
tree_unpause(TREE t)
{
MARPA_ASSERT(t->t_pause_counter> 0);
MARPA_ASSERT(t->t_ref_count>=t->t_pause_counter);
t->t_pause_counter--;
tree_unref(t);
}

/*:1027*//*1028:*/
#line 12117 "./marpa.w"

int marpa_t_next(Marpa_Tree t)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 12120 "./marpa.w"

const int termination_indicator= -1;
int is_first_tree_attempt= (t->t_parse_count<1);
/*1012:*/
#line 11956 "./marpa.w"

ORDER o= O_of_T(t);
/*984:*/
#line 11488 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*939:*/
#line 11082 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:939*/
#line 11490 "./marpa.w"


/*:984*/
#line 11958 "./marpa.w"
;

/*:1012*/
#line 12123 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 12124 "./marpa.w"

if(T_is_Paused(t)){
MARPA_ERROR(MARPA_ERR_TREE_PAUSED);
return failure_indicator;
}

if(T_is_Exhausted(t))
{
MARPA_ERROR(MARPA_ERR_TREE_EXHAUSTED);
return termination_indicator;
}

if(T_is_Nulling(t)){
if(is_first_tree_attempt){
t->t_parse_count++;
return 0;
}else{
goto TREE_IS_EXHAUSTED;
}
}

while(1){
const AND ands_of_b= ANDs_of_B(b);
if(is_first_tree_attempt){
is_first_tree_attempt= 0;
/*1037:*/
#line 12199 "./marpa.w"

{
ORID root_or_id= Top_ORID_of_B(b);
OR root_or_node= OR_of_B_by_ID(b,root_or_id);
NOOK nook;



const int choice= 0;
if(!and_order_ix_is_valid(o,root_or_node,choice))
goto TREE_IS_EXHAUSTED;
nook= FSTACK_PUSH(t->t_nook_stack);
tree_or_node_try(t,root_or_id);
OR_of_NOOK(nook)= root_or_node;
Choice_of_NOOK(nook)= choice;
Parent_of_NOOK(nook)= -1;
NOOK_Cause_is_Expanded(nook)= 0;
NOOK_is_Cause(nook)= 0;
NOOK_Predecessor_is_Expanded(nook)= 0;
NOOK_is_Predecessor(nook)= 0;
}

/*:1037*/
#line 12149 "./marpa.w"

}else{
/*1038:*/
#line 12224 "./marpa.w"
{
while(1){
OR iteration_candidate_or_node;
const NOOK iteration_candidate= FSTACK_TOP(t->t_nook_stack,NOOK_Object);
int choice;
if(!iteration_candidate)break;
iteration_candidate_or_node= OR_of_NOOK(iteration_candidate);
choice= Choice_of_NOOK(iteration_candidate)+1;
MARPA_ASSERT(choice> 0);
if(and_order_ix_is_valid(o,iteration_candidate_or_node,choice)){





Choice_of_NOOK(iteration_candidate)= choice;
NOOK_Cause_is_Expanded(iteration_candidate)= 0;
NOOK_Predecessor_is_Expanded(iteration_candidate)= 0;
break;
}
{


const int parent_nook_ix= Parent_of_NOOK(iteration_candidate);
if(parent_nook_ix>=0){
NOOK parent_nook= NOOK_of_TREE_by_IX(t,parent_nook_ix);
if(NOOK_is_Cause(iteration_candidate)){
NOOK_Cause_is_Expanded(parent_nook)= 0;
}
if(NOOK_is_Predecessor(iteration_candidate)){
NOOK_Predecessor_is_Expanded(parent_nook)= 0;
}
}


tree_or_node_release(t,ID_of_OR(iteration_candidate_or_node));
FSTACK_POP(t->t_nook_stack);
}
}
if(Size_of_T(t)<=0)goto TREE_IS_EXHAUSTED;
}

/*:1038*/
#line 12151 "./marpa.w"

}
/*1039:*/
#line 12266 "./marpa.w"
{
{
const int stack_length= Size_of_T(t);
int i;


FSTACK_CLEAR(t->t_nook_worklist);
for(i= 0;i<stack_length;i++){
*(FSTACK_PUSH(t->t_nook_worklist))= i;
}
}
while(1){
NOOKID*p_work_nook_id;
NOOK work_nook;
ANDID work_and_node_id;
AND work_and_node;
OR work_or_node;
OR child_or_node= NULL;
int choice;
int child_is_cause= 0;
int child_is_predecessor= 0;
if(FSTACK_LENGTH(t->t_nook_worklist)<=0){goto TREE_IS_FINISHED;}
p_work_nook_id= FSTACK_TOP(t->t_nook_worklist,NOOKID);
work_nook= NOOK_of_TREE_by_IX(t,*p_work_nook_id);
work_or_node= OR_of_NOOK(work_nook);
work_and_node_id= and_order_get(o,work_or_node,Choice_of_NOOK(work_nook));
work_and_node= ands_of_b+work_and_node_id;
do
{
if(!NOOK_Cause_is_Expanded(work_nook))
{
const OR cause_or_node= Cause_OR_of_AND(work_and_node);
if(!OR_is_Token(cause_or_node))
{
child_or_node= cause_or_node;
child_is_cause= 1;
break;
}
}
NOOK_Cause_is_Expanded(work_nook)= 1;
if(!NOOK_Predecessor_is_Expanded(work_nook))
{
child_or_node= Predecessor_OR_of_AND(work_and_node);
if(child_or_node)
{
child_is_predecessor= 1;
break;
}
}
NOOK_Predecessor_is_Expanded(work_nook)= 1;
FSTACK_POP(t->t_nook_worklist);
goto NEXT_NOOK_ON_WORKLIST;
}
while(0);
if(!tree_or_node_try(t,ID_of_OR(child_or_node)))goto NEXT_TREE;
choice= 0;
if(!and_order_ix_is_valid(o,child_or_node,choice))goto NEXT_TREE;
/*1040:*/
#line 12329 "./marpa.w"

{
NOOKID new_nook_id= Size_of_T(t);
NOOK new_nook= FSTACK_PUSH(t->t_nook_stack);
*(FSTACK_PUSH(t->t_nook_worklist))= new_nook_id;
Parent_of_NOOK(new_nook)= *p_work_nook_id;
Choice_of_NOOK(new_nook)= choice;
OR_of_NOOK(new_nook)= child_or_node;
NOOK_Cause_is_Expanded(new_nook)= 0;
if((NOOK_is_Cause(new_nook)= Boolean(child_is_cause)))
{
NOOK_Cause_is_Expanded(work_nook)= 1;
}
NOOK_Predecessor_is_Expanded(new_nook)= 0;
if((NOOK_is_Predecessor(new_nook)= Boolean(child_is_predecessor)))
{
NOOK_Predecessor_is_Expanded(work_nook)= 1;
}
}

/*:1040*/
#line 12323 "./marpa.w"
;
NEXT_NOOK_ON_WORKLIST:;
}
NEXT_TREE:;
}

/*:1039*/
#line 12153 "./marpa.w"

}
TREE_IS_FINISHED:;
t->t_parse_count++;
return FSTACK_LENGTH(t->t_nook_stack);
TREE_IS_EXHAUSTED:;
tree_exhaust(t);
MARPA_ERROR(MARPA_ERR_TREE_EXHAUSTED);
return termination_indicator;

}

/*:1028*//*1035:*/
#line 12186 "./marpa.w"

PRIVATE int tree_or_node_try(TREE tree,ORID or_node_id)
{
return!bv_bit_test_then_set(tree->t_or_node_in_use,or_node_id);
}
/*:1035*//*1036:*/
#line 12192 "./marpa.w"

PRIVATE void tree_or_node_release(TREE tree,ORID or_node_id)
{
bv_bit_clear(tree->t_or_node_in_use,or_node_id);
}

/*:1036*//*1041:*/
#line 12350 "./marpa.w"

int marpa_t_parse_count(Marpa_Tree t)
{
return t->t_parse_count;
}

/*:1041*//*1042:*/
#line 12358 "./marpa.w"

int _marpa_t_size(Marpa_Tree t)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 12361 "./marpa.w"

/*1012:*/
#line 11956 "./marpa.w"

ORDER o= O_of_T(t);
/*984:*/
#line 11488 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*939:*/
#line 11082 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:939*/
#line 11490 "./marpa.w"


/*:984*/
#line 11958 "./marpa.w"
;

/*:1012*/
#line 12362 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 12363 "./marpa.w"

if(T_is_Exhausted(t)){
MARPA_ERROR(MARPA_ERR_TREE_EXHAUSTED);
return failure_indicator;
}
if(T_is_Nulling(t))return 0;
return Size_of_T(t);
}

/*:1042*//*1063:*/
#line 12576 "./marpa.w"

Marpa_Value marpa_v_new(Marpa_Tree t)
{
/*1208:*/
#line 14586 "./marpa.w"
void*const failure_indicator= NULL;
/*:1208*/
#line 12579 "./marpa.w"

/*1012:*/
#line 11956 "./marpa.w"

ORDER o= O_of_T(t);
/*984:*/
#line 11488 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*939:*/
#line 11082 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:939*/
#line 11490 "./marpa.w"


/*:984*/
#line 11958 "./marpa.w"
;

/*:1012*/
#line 12580 "./marpa.w"
;
/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 12581 "./marpa.w"

if(t->t_parse_count<=0){
MARPA_ERROR(MARPA_ERR_BEFORE_FIRST_TREE);
return NULL;
}
if(!T_is_Exhausted(t))
{
const XSYID xsy_count= XSY_Count_of_G(g);
struct marpa_obstack*const obstack= marpa_obs_init;
const VALUE v= marpa_obs_new(obstack,struct s_value,1);
v->t_obs= obstack;
Step_Type_of_V(v)= Next_Value_Type_of_V(v)= MARPA_STEP_INITIAL;
/*1054:*/
#line 12502 "./marpa.w"

XSYID_of_V(v)= -1;
RULEID_of_V(v)= -1;
Token_Value_of_V(v)= -1;
Token_Type_of_V(v)= DUMMY_OR_NODE;
Arg_0_of_V(v)= -1;
Arg_N_of_V(v)= -1;
Result_of_V(v)= -1;
Rule_Start_of_V(v)= -1;
Token_Start_of_V(v)= -1;
YS_ID_of_V(v)= -1;

/*:1054*//*1061:*/
#line 12565 "./marpa.w"

MARPA_DSTACK_SAFE(VStack_of_V(v));
/*:1061*//*1066:*/
#line 12613 "./marpa.w"

v->t_ref_count= 1;

/*:1066*//*1073:*/
#line 12666 "./marpa.w"

V_is_Nulling(v)= 0;

/*:1073*//*1075:*/
#line 12673 "./marpa.w"

V_is_Trace(v)= 0;
/*:1075*//*1078:*/
#line 12694 "./marpa.w"

NOOK_of_V(v)= -1;
/*:1078*//*1083:*/
#line 12721 "./marpa.w"

{
XSY_is_Valued_BV_of_V(v)= lbv_clone(v->t_obs,Valued_BV_of_B(b),xsy_count);
Valued_Locked_BV_of_V(v)= 
lbv_clone(v->t_obs,Valued_Locked_BV_of_B(b),xsy_count);
}


/*:1083*/
#line 12593 "./marpa.w"

tree_pause(t);
T_of_V(v)= t;
if(T_is_Nulling(o)){
V_is_Nulling(v)= 1;
}else{
const int minimum_stack_size= (8192/sizeof(int));
const int initial_stack_size= 
MAX(Size_of_TREE(t)/1024,minimum_stack_size);
MARPA_DSTACK_INIT(VStack_of_V(v),int,initial_stack_size);
}
return(Marpa_Value)v;
}
MARPA_ERROR(MARPA_ERR_TREE_EXHAUSTED);
return NULL;
}

/*:1063*//*1067:*/
#line 12617 "./marpa.w"

PRIVATE void
value_unref(VALUE v)
{
MARPA_ASSERT(v->t_ref_count> 0)
v->t_ref_count--;
if(v->t_ref_count<=0)
{
value_free(v);
}
}
void
marpa_v_unref(Marpa_Value public_v)
{
value_unref((VALUE)public_v);
}

/*:1067*//*1068:*/
#line 12635 "./marpa.w"

PRIVATE VALUE
value_ref(VALUE v)
{
MARPA_ASSERT(v->t_ref_count> 0)
v->t_ref_count++;
return v;
}
Marpa_Value
marpa_v_ref(Marpa_Value v)
{
return(Marpa_Value)value_ref((VALUE)v);
}

/*:1068*//*1069:*/
#line 12649 "./marpa.w"

PRIVATE void value_free(VALUE v)
{
tree_unpause(T_of_V(v));
/*1062:*/
#line 12567 "./marpa.w"

{
if(_MARPA_LIKELY(MARPA_DSTACK_IS_INITIALIZED(VStack_of_V(v))!=NULL))
{
MARPA_DSTACK_DESTROY(VStack_of_V(v));
}
}

/*:1062*/
#line 12653 "./marpa.w"

/*1056:*/
#line 12518 "./marpa.w"

marpa_obs_free(v->t_obs);

/*:1056*/
#line 12654 "./marpa.w"

}

/*:1069*//*1076:*/
#line 12675 "./marpa.w"

int _marpa_v_trace(Marpa_Value public_v,int flag)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 12678 "./marpa.w"

const VALUE v= (VALUE)public_v;
/*1070:*/
#line 12657 "./marpa.w"

TREE t= T_of_V(v);
/*1012:*/
#line 11956 "./marpa.w"

ORDER o= O_of_T(t);
/*984:*/
#line 11488 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*939:*/
#line 11082 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:939*/
#line 11490 "./marpa.w"


/*:984*/
#line 11958 "./marpa.w"
;

/*:1012*/
#line 12659 "./marpa.w"


/*:1070*/
#line 12680 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 12681 "./marpa.w"

if(_MARPA_UNLIKELY(!V_is_Active(v))){
MARPA_ERROR(MARPA_ERR_VALUATOR_INACTIVE);
return failure_indicator;
}
V_is_Trace(v)= Boolean(flag);
return 1;
}

/*:1076*//*1079:*/
#line 12697 "./marpa.w"

Marpa_Nook_ID _marpa_v_nook(Marpa_Value public_v)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 12700 "./marpa.w"

const VALUE v= (VALUE)public_v;
/*1070:*/
#line 12657 "./marpa.w"

TREE t= T_of_V(v);
/*1012:*/
#line 11956 "./marpa.w"

ORDER o= O_of_T(t);
/*984:*/
#line 11488 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*939:*/
#line 11082 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:939*/
#line 11490 "./marpa.w"


/*:984*/
#line 11958 "./marpa.w"
;

/*:1012*/
#line 12659 "./marpa.w"


/*:1070*/
#line 12702 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 12703 "./marpa.w"

if(_MARPA_UNLIKELY(V_is_Nulling(v)))return-1;
if(_MARPA_UNLIKELY(!V_is_Active(v))){
MARPA_ERROR(MARPA_ERR_VALUATOR_INACTIVE);
return failure_indicator;
}
return NOOK_of_V(v);
}

/*:1079*//*1084:*/
#line 12730 "./marpa.w"

PRIVATE int symbol_is_valued(
VALUE v,
Marpa_Symbol_ID xsy_id)
{
return lbv_bit_test(XSY_is_Valued_BV_of_V(v),xsy_id);
}

/*:1084*//*1085:*/
#line 12739 "./marpa.w"

int marpa_v_symbol_is_valued(
Marpa_Value public_v,
Marpa_Symbol_ID xsy_id)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 12744 "./marpa.w"

const VALUE v= (VALUE)public_v;
/*1070:*/
#line 12657 "./marpa.w"

TREE t= T_of_V(v);
/*1012:*/
#line 11956 "./marpa.w"

ORDER o= O_of_T(t);
/*984:*/
#line 11488 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*939:*/
#line 11082 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:939*/
#line 11490 "./marpa.w"


/*:984*/
#line 11958 "./marpa.w"
;

/*:1012*/
#line 12659 "./marpa.w"


/*:1070*/
#line 12746 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 12747 "./marpa.w"

/*1212:*/
#line 14605 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1212*/
#line 12748 "./marpa.w"

/*1213:*/
#line 14612 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1213*/
#line 12749 "./marpa.w"

return lbv_bit_test(XSY_is_Valued_BV_of_V(v),xsy_id);
}

/*:1085*//*1086:*/
#line 12755 "./marpa.w"

PRIVATE int symbol_is_valued_set(
VALUE v,XSYID xsy_id,int value)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 12759 "./marpa.w"

const int old_value= lbv_bit_test(XSY_is_Valued_BV_of_V(v),xsy_id);
if(old_value==value){
lbv_bit_set(Valued_Locked_BV_of_V(v),xsy_id);
return value;
}

if(_MARPA_UNLIKELY(lbv_bit_test(Valued_Locked_BV_of_V(v),xsy_id))){
return failure_indicator;
}
lbv_bit_set(Valued_Locked_BV_of_V(v),xsy_id);
if(value){
lbv_bit_set(XSY_is_Valued_BV_of_V(v),xsy_id);
}else{
lbv_bit_clear(XSY_is_Valued_BV_of_V(v),xsy_id);
}
return value;
}

/*:1086*//*1087:*/
#line 12778 "./marpa.w"

int marpa_v_symbol_is_valued_set(
Marpa_Value public_v,Marpa_Symbol_ID xsy_id,int value)
{
const VALUE v= (VALUE)public_v;
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 12783 "./marpa.w"

/*1070:*/
#line 12657 "./marpa.w"

TREE t= T_of_V(v);
/*1012:*/
#line 11956 "./marpa.w"

ORDER o= O_of_T(t);
/*984:*/
#line 11488 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*939:*/
#line 11082 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:939*/
#line 11490 "./marpa.w"


/*:984*/
#line 11958 "./marpa.w"
;

/*:1012*/
#line 12659 "./marpa.w"


/*:1070*/
#line 12784 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 12785 "./marpa.w"

if(_MARPA_UNLIKELY(value<0||value> 1))
{
MARPA_ERROR(MARPA_ERR_INVALID_BOOLEAN);
return failure_indicator;
}
/*1212:*/
#line 14605 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1212*/
#line 12791 "./marpa.w"

/*1213:*/
#line 14612 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1213*/
#line 12792 "./marpa.w"

return symbol_is_valued_set(v,xsy_id,value);
}

/*:1087*//*1088:*/
#line 12798 "./marpa.w"

int
marpa_v_valued_force(Marpa_Value public_v)
{
const VALUE v= (VALUE)public_v;
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 12803 "./marpa.w"

XSYID xsy_count;
XSYID xsy_id;
/*1070:*/
#line 12657 "./marpa.w"

TREE t= T_of_V(v);
/*1012:*/
#line 11956 "./marpa.w"

ORDER o= O_of_T(t);
/*984:*/
#line 11488 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*939:*/
#line 11082 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:939*/
#line 11490 "./marpa.w"


/*:984*/
#line 11958 "./marpa.w"
;

/*:1012*/
#line 12659 "./marpa.w"


/*:1070*/
#line 12806 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 12807 "./marpa.w"

xsy_count= XSY_Count_of_G(g);
for(xsy_id= 0;xsy_id<xsy_count;xsy_id++)
{
if(_MARPA_UNLIKELY(!lbv_bit_test(XSY_is_Valued_BV_of_V(v),xsy_id)&&
lbv_bit_test(Valued_Locked_BV_of_V(v),xsy_id)))
{
return failure_indicator;
}
lbv_bit_set(Valued_Locked_BV_of_V(v),xsy_id);
lbv_bit_set(XSY_is_Valued_BV_of_V(v),xsy_id);
}
return xsy_count;
}

/*:1088*//*1089:*/
#line 12822 "./marpa.w"

int marpa_v_rule_is_valued_set(
Marpa_Value public_v,Marpa_Rule_ID xrl_id,int value)
{
const VALUE v= (VALUE)public_v;
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 12827 "./marpa.w"

/*1070:*/
#line 12657 "./marpa.w"

TREE t= T_of_V(v);
/*1012:*/
#line 11956 "./marpa.w"

ORDER o= O_of_T(t);
/*984:*/
#line 11488 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*939:*/
#line 11082 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:939*/
#line 11490 "./marpa.w"


/*:984*/
#line 11958 "./marpa.w"
;

/*:1012*/
#line 12659 "./marpa.w"


/*:1070*/
#line 12828 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 12829 "./marpa.w"

if(_MARPA_UNLIKELY(value<0||value> 1))
{
MARPA_ERROR(MARPA_ERR_INVALID_BOOLEAN);
return failure_indicator;
}
/*1221:*/
#line 14661 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}

/*:1221*/
#line 12835 "./marpa.w"

/*1219:*/
#line 14649 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}

/*:1219*/
#line 12836 "./marpa.w"

{
const XRL xrl= XRL_by_ID(xrl_id);
const XSYID xsy_id= LHS_ID_of_XRL(xrl);
return symbol_is_valued_set(v,xsy_id,value);
}
}

/*:1089*//*1090:*/
#line 12844 "./marpa.w"

int marpa_v_rule_is_valued(
Marpa_Value public_v,Marpa_Rule_ID xrl_id)
{
const VALUE v= (VALUE)public_v;
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 12849 "./marpa.w"

/*1070:*/
#line 12657 "./marpa.w"

TREE t= T_of_V(v);
/*1012:*/
#line 11956 "./marpa.w"

ORDER o= O_of_T(t);
/*984:*/
#line 11488 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*939:*/
#line 11082 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:939*/
#line 11490 "./marpa.w"


/*:984*/
#line 11958 "./marpa.w"
;

/*:1012*/
#line 12659 "./marpa.w"


/*:1070*/
#line 12850 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 12851 "./marpa.w"

/*1221:*/
#line 14661 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}

/*:1221*/
#line 12852 "./marpa.w"

/*1219:*/
#line 14649 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}

/*:1219*/
#line 12853 "./marpa.w"

{
const XRL xrl= XRL_by_ID(xrl_id);
const XSYID xsy_id= LHS_ID_of_XRL(xrl);
return symbol_is_valued(v,xsy_id);
}
}

/*:1090*//*1092:*/
#line 12868 "./marpa.w"

Marpa_Step_Type marpa_v_step(Marpa_Value public_v)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 12871 "./marpa.w"

const VALUE v= (VALUE)public_v;

if(V_is_Nulling(v)){
/*1070:*/
#line 12657 "./marpa.w"

TREE t= T_of_V(v);
/*1012:*/
#line 11956 "./marpa.w"

ORDER o= O_of_T(t);
/*984:*/
#line 11488 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*939:*/
#line 11082 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:939*/
#line 11490 "./marpa.w"


/*:984*/
#line 11958 "./marpa.w"
;

/*:1012*/
#line 12659 "./marpa.w"


/*:1070*/
#line 12875 "./marpa.w"

/*1094:*/
#line 12956 "./marpa.w"

{
while(V_is_Active(v))
{
Marpa_Step_Type current_value_type= Next_Value_Type_of_V(v);
switch(current_value_type)
{
case MARPA_STEP_INITIAL:
case STEP_GET_DATA:
{
Next_Value_Type_of_V(v)= MARPA_STEP_INACTIVE;
XSYID_of_V(v)= g->t_start_xsy_id;
Result_of_V(v)= Arg_0_of_V(v)= Arg_N_of_V(v)= 0;
if(lbv_bit_test(XSY_is_Valued_BV_of_V(v),XSYID_of_V(v)))
return Step_Type_of_V(v)= MARPA_STEP_NULLING_SYMBOL;
}





}
}
}

/*:1094*/
#line 12876 "./marpa.w"

return Step_Type_of_V(v)= MARPA_STEP_INACTIVE;
}

while(V_is_Active(v)){
Marpa_Step_Type current_value_type= Next_Value_Type_of_V(v);
switch(current_value_type)
{
case MARPA_STEP_INITIAL:
{
XSYID xsy_count;
/*1070:*/
#line 12657 "./marpa.w"

TREE t= T_of_V(v);
/*1012:*/
#line 11956 "./marpa.w"

ORDER o= O_of_T(t);
/*984:*/
#line 11488 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*939:*/
#line 11082 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:939*/
#line 11490 "./marpa.w"


/*:984*/
#line 11958 "./marpa.w"
;

/*:1012*/
#line 12659 "./marpa.w"


/*:1070*/
#line 12887 "./marpa.w"

xsy_count= XSY_Count_of_G(g);
lbv_fill(Valued_Locked_BV_of_V(v),xsy_count);
/*1093:*/
#line 12940 "./marpa.w"

{
const LBV xsy_bv= XSY_is_Valued_BV_of_V(v);
const XRLID xrl_count= XRL_Count_of_G(g);
const LBV xrl_bv= lbv_obs_new0(v->t_obs,xrl_count);
XRLID xrlid;
XRL_is_Valued_BV_of_V(v)= xrl_bv;
for(xrlid= 0;xrlid<xrl_count;xrlid++){
const XRL xrl= XRL_by_ID(xrlid);
const XSYID lhs_xsy_id= LHS_ID_of_XRL(xrl);
if(lbv_bit_test(xsy_bv,lhs_xsy_id)){
lbv_bit_set(xrl_bv,xrlid);
}
}
}

/*:1093*/
#line 12890 "./marpa.w"

}

case STEP_GET_DATA:
/*1095:*/
#line 12981 "./marpa.w"

{
AND and_nodes;






int pop_arguments= 1;
/*1070:*/
#line 12657 "./marpa.w"

TREE t= T_of_V(v);
/*1012:*/
#line 11956 "./marpa.w"

ORDER o= O_of_T(t);
/*984:*/
#line 11488 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*939:*/
#line 11082 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:939*/
#line 11490 "./marpa.w"


/*:984*/
#line 11958 "./marpa.w"
;

/*:1012*/
#line 12659 "./marpa.w"


/*:1070*/
#line 12991 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 12992 "./marpa.w"

and_nodes= ANDs_of_B(B_of_O(o));

if(NOOK_of_V(v)<0){
NOOK_of_V(v)= Size_of_TREE(t);
}

while(1)
{
OR or;
IRL nook_irl;
Token_Value_of_V(v)= -1;
RULEID_of_V(v)= -1;
NOOK_of_V(v)--;
if(NOOK_of_V(v)<0)
{
Next_Value_Type_of_V(v)= MARPA_STEP_INACTIVE;
break;
}
if(pop_arguments)
{


Arg_N_of_V(v)= Arg_0_of_V(v);
pop_arguments= 0;
}
{
ANDID and_node_id;
AND and_node;
int cause_or_node_type;
OR cause_or_node;
const NOOK nook= NOOK_of_TREE_by_IX(t,NOOK_of_V(v));
const int choice= Choice_of_NOOK(nook);
or= OR_of_NOOK(nook);
YS_ID_of_V(v)= YS_Ord_of_OR(or);
and_node_id= and_order_get(o,or,choice);
and_node= and_nodes+and_node_id;
cause_or_node= Cause_OR_of_AND(and_node);
cause_or_node_type= Type_of_OR(cause_or_node);
switch(cause_or_node_type)
{
case VALUED_TOKEN_OR_NODE:
Token_Type_of_V(v)= cause_or_node_type;
Arg_0_of_V(v)= ++Arg_N_of_V(v);
{
const OR predecessor= Predecessor_OR_of_AND(and_node);
XSYID_of_V(v)= 
ID_of_XSY(Source_XSY_of_NSYID(NSYID_of_OR(cause_or_node)));
Token_Start_of_V(v)= 
predecessor?YS_Ord_of_OR(predecessor):Origin_Ord_of_OR(or);
Token_Value_of_V(v)= Value_of_OR(cause_or_node);
}

break;
case NULLING_TOKEN_OR_NODE:
Token_Type_of_V(v)= cause_or_node_type;
Arg_0_of_V(v)= ++Arg_N_of_V(v);
{
const XSY source_xsy= 
Source_XSY_of_NSYID(NSYID_of_OR(cause_or_node));
const XSYID source_xsy_id= ID_of_XSY(source_xsy);
if(bv_bit_test(XSY_is_Valued_BV_of_V(v),source_xsy_id))
{
XSYID_of_V(v)= source_xsy_id;
Token_Start_of_V(v)= YS_ID_of_V(v);
}
else
{
Token_Type_of_V(v)= DUMMY_OR_NODE;


}
}

break;
default:
Token_Type_of_V(v)= DUMMY_OR_NODE;
}
}
nook_irl= IRL_of_OR(or);
if(Position_of_OR(or)==Length_of_IRL(nook_irl))
{
int virtual_rhs= IRL_has_Virtual_RHS(nook_irl);
int virtual_lhs= IRL_has_Virtual_LHS(nook_irl);
int real_symbol_count;
const MARPA_DSTACK virtual_stack= &VStack_of_V(v);
if(virtual_lhs)
{
real_symbol_count= Real_SYM_Count_of_IRL(nook_irl);
if(virtual_rhs)
{
*(MARPA_DSTACK_TOP(*virtual_stack,int))+= real_symbol_count;
}
else
{
*MARPA_DSTACK_PUSH(*virtual_stack,int)= real_symbol_count;
}
}
else
{

if(virtual_rhs)
{
real_symbol_count= Real_SYM_Count_of_IRL(nook_irl);
real_symbol_count+= *MARPA_DSTACK_POP(*virtual_stack,int);
}
else
{
real_symbol_count= Length_of_IRL(nook_irl);
}
{


XRLID original_rule_id= ID_of_XRL(Source_XRL_of_IRL(nook_irl));
Arg_0_of_V(v)= Arg_N_of_V(v)-real_symbol_count+1;
pop_arguments= 1;
if(lbv_bit_test(XRL_is_Valued_BV_of_V(v),original_rule_id))
{
RULEID_of_V(v)= original_rule_id;
Rule_Start_of_V(v)= Origin_Ord_of_OR(or);
}
}

}
}
if(RULEID_of_V(v)>=0)
break;
if(Token_Type_of_V(v)!=DUMMY_OR_NODE)
break;
if(V_is_Trace(v))
break;
}
}

/*:1095*/
#line 12894 "./marpa.w"

if(!V_is_Active(v))break;

case MARPA_STEP_TOKEN:
{
int tkn_type= Token_Type_of_V(v);
Next_Value_Type_of_V(v)= MARPA_STEP_RULE;
if(tkn_type==NULLING_TOKEN_OR_NODE)
{
if(lbv_bit_test(XSY_is_Valued_BV_of_V(v),XSYID_of_V(v))){
Result_of_V(v)= Arg_N_of_V(v);
return Step_Type_of_V(v)= MARPA_STEP_NULLING_SYMBOL;
}
}
else if(tkn_type!=DUMMY_OR_NODE)
{
Result_of_V(v)= Arg_N_of_V(v);
return Step_Type_of_V(v)= MARPA_STEP_TOKEN;
}
}

case MARPA_STEP_RULE:
if(RULEID_of_V(v)>=0)
{
Next_Value_Type_of_V(v)= MARPA_STEP_TRACE;
Result_of_V(v)= Arg_0_of_V(v);
return Step_Type_of_V(v)= MARPA_STEP_RULE;
}

case MARPA_STEP_TRACE:
Next_Value_Type_of_V(v)= STEP_GET_DATA;
if(V_is_Trace(v))
{
return Step_Type_of_V(v)= MARPA_STEP_TRACE;
}
}
}

Next_Value_Type_of_V(v)= MARPA_STEP_INACTIVE;
return Step_Type_of_V(v)= MARPA_STEP_INACTIVE;
}

/*:1092*//*1097:*/
#line 13144 "./marpa.w"

PRIVATE int lbv_bits_to_size(int bits)
{
const LBW result= (LBW)(((unsigned int)bits+(lbv_wordbits-1))/lbv_wordbits);
return(int)result;
}

/*:1097*//*1098:*/
#line 13152 "./marpa.w"

PRIVATE Bit_Vector
lbv_obs_new(struct marpa_obstack*obs,int bits)
{
int size= lbv_bits_to_size(bits);
LBV lbv= marpa_obs_new(obs,LBW,size);
return lbv;
}

/*:1098*//*1099:*/
#line 13162 "./marpa.w"

PRIVATE Bit_Vector
lbv_zero(Bit_Vector lbv,int bits)
{
int size= lbv_bits_to_size(bits);
if(size> 0){
LBW*addr= lbv;
while(size--)*addr++= 0u;
}
return lbv;
}

/*:1099*//*1100:*/
#line 13175 "./marpa.w"

PRIVATE Bit_Vector
lbv_obs_new0(struct marpa_obstack*obs,int bits)
{
LBV lbv= lbv_obs_new(obs,bits);
return lbv_zero(lbv,bits);
}

/*:1100*//*1102:*/
#line 13194 "./marpa.w"

PRIVATE LBV lbv_clone(
struct marpa_obstack*obs,LBV old_lbv,int bits)
{
int size= lbv_bits_to_size(bits);
const LBV new_lbv= marpa_obs_new(obs,LBW,size);
if(size> 0){
LBW*from_addr= old_lbv;
LBW*to_addr= new_lbv;
while(size--)*to_addr++= *from_addr++;
}
return new_lbv;
}

/*:1102*//*1103:*/
#line 13210 "./marpa.w"

PRIVATE LBV lbv_fill(
LBV lbv,int bits)
{
int size= lbv_bits_to_size(bits);
if(size> 0){
LBW*to_addr= lbv;
while(size--)*to_addr++= ~((LBW)0);
}
return lbv;
}

/*:1103*//*1106:*/
#line 13246 "./marpa.w"

PRIVATE unsigned int bv_bits_to_size(int bits)
{
return((LBW)bits+bv_modmask)/bv_wordbits;
}
/*:1106*//*1107:*/
#line 13252 "./marpa.w"

PRIVATE unsigned int bv_bits_to_unused_mask(int bits)
{
LBW mask= (LBW)bits&bv_modmask;
if(mask)mask= (LBW)~(~0uL<<mask);else mask= (LBW)~0uL;
return(mask);
}

/*:1107*//*1109:*/
#line 13266 "./marpa.w"

PRIVATE Bit_Vector bv_create(int bits)
{
LBW size= bv_bits_to_size(bits);
LBW bytes= (size+(LBW)bv_hiddenwords)*(LBW)sizeof(Bit_Vector_Word);
LBW*addr= (Bit_Vector)my_malloc0((size_t)bytes);
*addr++= (LBW)bits;
*addr++= size;
*addr++= bv_bits_to_unused_mask(bits);
return addr;
}

/*:1109*//*1111:*/
#line 13284 "./marpa.w"

PRIVATE Bit_Vector
bv_obs_create(struct marpa_obstack*obs,int bits)
{
LBW size= bv_bits_to_size(bits);
LBW bytes= (size+(LBW)bv_hiddenwords)*(LBW)sizeof(Bit_Vector_Word);
LBW*addr= (Bit_Vector)marpa__obs_alloc(obs,(size_t)bytes,ALIGNOF(LBW));
*addr++= (LBW)bits;
*addr++= size;
*addr++= bv_bits_to_unused_mask(bits);
if(size> 0){
Bit_Vector bv= addr;
while(size--)*bv++= 0u;
}
return addr;
}


/*:1111*//*1112:*/
#line 13305 "./marpa.w"

PRIVATE Bit_Vector bv_shadow(Bit_Vector bv)
{
return bv_create((int)BV_BITS(bv));
}
PRIVATE Bit_Vector bv_obs_shadow(struct marpa_obstack*obs,Bit_Vector bv)
{
return bv_obs_create(obs,(int)BV_BITS(bv));
}

/*:1112*//*1113:*/
#line 13319 "./marpa.w"

PRIVATE
Bit_Vector bv_copy(Bit_Vector bv_to,Bit_Vector bv_from)
{
LBW*p_to= bv_to;
const LBW bits= BV_BITS(bv_to);
if(bits> 0)
{
LBW count= BV_SIZE(bv_to);
while(count--)*p_to++= *bv_from++;
}
return(bv_to);
}

/*:1113*//*1114:*/
#line 13337 "./marpa.w"

PRIVATE
Bit_Vector bv_clone(Bit_Vector bv)
{
return bv_copy(bv_shadow(bv),bv);
}

PRIVATE
Bit_Vector bv_obs_clone(struct marpa_obstack*obs,Bit_Vector bv)
{
return bv_copy(bv_obs_shadow(obs,bv),bv);
}

/*:1114*//*1115:*/
#line 13351 "./marpa.w"

PRIVATE void bv_free(Bit_Vector vector)
{
if(_MARPA_LIKELY(vector!=NULL))
{
vector-= bv_hiddenwords;
my_free(vector);
}
}

/*:1115*//*1116:*/
#line 13362 "./marpa.w"

PRIVATE void bv_fill(Bit_Vector bv)
{
LBW size= BV_SIZE(bv);
if(size<=0)return;
while(size--)*bv++= ~0u;
--bv;
*bv&= BV_MASK(bv);
}

/*:1116*//*1117:*/
#line 13373 "./marpa.w"

PRIVATE void bv_clear(Bit_Vector bv)
{
LBW size= BV_SIZE(bv);
if(size<=0)return;
while(size--)*bv++= 0u;
}

/*:1117*//*1119:*/
#line 13387 "./marpa.w"

PRIVATE void bv_over_clear(Bit_Vector bv,int raw_bit)
{
const LBW bit= (LBW)raw_bit;
LBW length= bit/bv_wordbits+1;
while(length--)*bv++= 0u;
}

/*:1119*//*1121:*/
#line 13396 "./marpa.w"

PRIVATE void bv_bit_set(Bit_Vector vector,int raw_bit)
{
const LBW bit= (LBW)raw_bit;
*(vector+(bit/bv_wordbits))|= (bv_lsb<<(bit%bv_wordbits));
}

/*:1121*//*1122:*/
#line 13404 "./marpa.w"

PRIVATE void bv_bit_clear(Bit_Vector vector,int raw_bit)
{
const LBW bit= (LBW)raw_bit;
*(vector+(bit/bv_wordbits))&= ~(bv_lsb<<(bit%bv_wordbits));
}

/*:1122*//*1123:*/
#line 13412 "./marpa.w"

PRIVATE int bv_bit_test(Bit_Vector vector,int raw_bit)
{
const LBW bit= (LBW)raw_bit;
return(*(vector+(bit/bv_wordbits))&(bv_lsb<<(bit%bv_wordbits)))!=0u;
}

/*:1123*//*1124:*/
#line 13424 "./marpa.w"

PRIVATE int
bv_bit_test_then_set(Bit_Vector vector,int raw_bit)
{
const LBW bit= (LBW)raw_bit;
Bit_Vector addr= vector+(bit/bv_wordbits);
LBW mask= bv_lsb<<(bit%bv_wordbits);
if((*addr&mask)!=0u)
return 1;
*addr|= mask;
return 0;
}

/*:1124*//*1125:*/
#line 13438 "./marpa.w"

PRIVATE
int bv_is_empty(Bit_Vector addr)
{
LBW size= BV_SIZE(addr);
int r= 1;
if(size> 0){
*(addr+size-1)&= BV_MASK(addr);
while(r&&(size--> 0))r= (*addr++==0);
}
return(r);
}

/*:1125*//*1126:*/
#line 13452 "./marpa.w"

PRIVATE void bv_not(Bit_Vector X,Bit_Vector Y)
{
LBW size= BV_SIZE(X);
LBW mask= BV_MASK(X);
while(size--> 0)*X++= ~*Y++;
*(--X)&= mask;
}

/*:1126*//*1127:*/
#line 13462 "./marpa.w"

PRIVATE void bv_and(Bit_Vector X,Bit_Vector Y,Bit_Vector Z)
{
LBW size= BV_SIZE(X);
LBW mask= BV_MASK(X);
while(size--> 0)*X++= *Y++&*Z++;
*(--X)&= mask;
}

/*:1127*//*1128:*/
#line 13472 "./marpa.w"

PRIVATE void bv_or(Bit_Vector X,Bit_Vector Y,Bit_Vector Z)
{
LBW size= BV_SIZE(X);
LBW mask= BV_MASK(X);
while(size--> 0)*X++= *Y++|*Z++;
*(--X)&= mask;
}

/*:1128*//*1129:*/
#line 13482 "./marpa.w"

PRIVATE void bv_or_assign(Bit_Vector X,Bit_Vector Y)
{
LBW size= BV_SIZE(X);
LBW mask= BV_MASK(X);
while(size--> 0)*X++|= *Y++;
*(--X)&= mask;
}

/*:1129*//*1130:*/
#line 13492 "./marpa.w"

PRIVATE_NOT_INLINE
int bv_scan(Bit_Vector bv,int raw_start,int*raw_min,int*raw_max)
{
LBW start= (LBW)raw_start;
LBW min;
LBW max;
LBW size= BV_SIZE(bv);
LBW mask= BV_MASK(bv);
LBW offset;
LBW bitmask;
LBW value;
int empty;

if(size==0)return 0;
if(start>=BV_BITS(bv))return 0;
min= start;
max= start;
offset= start/bv_wordbits;
*(bv+size-1)&= mask;
bv+= offset;
size-= offset;
bitmask= (LBW)1<<(start&bv_modmask);
mask= ~(bitmask|(bitmask-(LBW)1));
value= *bv++;
if((value&bitmask)==0)
{
value&= mask;
if(value==0)
{
offset++;
empty= 1;
while(empty&&(--size> 0))
{
if((value= *bv++))empty= 0;else offset++;
}
if(empty){
*raw_min= (int)min;
*raw_max= (int)max;
return 0;
}
}
start= offset*bv_wordbits;
bitmask= bv_lsb;
mask= value;
while(!(mask&bv_lsb))
{
bitmask<<= 1;
mask>>= 1;
start++;
}
mask= ~(bitmask|(bitmask-1));
min= start;
max= start;
}
value= ~value;
value&= mask;
if(value==0)
{
offset++;
empty= 1;
while(empty&&(--size> 0))
{
if((value= ~*bv++))empty= 0;else offset++;
}
if(empty)value= bv_lsb;
}
start= offset*bv_wordbits;
while(!(value&bv_lsb))
{
value>>= 1;
start++;
}
max= --start;
*raw_min= (int)min;
*raw_max= (int)max;
return 1;
}

/*:1130*//*1131:*/
#line 13572 "./marpa.w"

PRIVATE int
bv_count(Bit_Vector v)
{
int start,min,max;
int count= 0;
for(start= 0;bv_scan(v,start,&min,&max);start= max+2)
{
count+= max-min+1;
}
return count;
}

/*:1131*//*1136:*/
#line 13619 "./marpa.w"

PRIVATE void
rhs_closure(GRAMMAR g,Bit_Vector bv,XRLID**xrl_list_x_rh_sym)
{
int min,max,start= 0;
Marpa_Symbol_ID*end_of_stack= NULL;



FSTACK_DECLARE(stack,XSYID)
FSTACK_INIT(stack,XSYID,XSY_Count_of_G(g));










while(bv_scan(bv,start,&min,&max))
{
XSYID xsy_id;
for(xsy_id= min;xsy_id<=max;xsy_id++)
{
*(FSTACK_PUSH(stack))= xsy_id;
}
start= max+2;
}



while((end_of_stack= FSTACK_POP(stack)))
{


const XSYID xsy_id= *end_of_stack;
XRLID*p_xrl= xrl_list_x_rh_sym[xsy_id];
const XRLID*p_one_past_rules= xrl_list_x_rh_sym[xsy_id+1];

for(;p_xrl<p_one_past_rules;p_xrl++)
{


const XRLID rule_id= *p_xrl;
const XRL rule= XRL_by_ID(rule_id);
int rule_length;
int rh_ix;
const XSYID lhs_id= LHS_ID_of_XRL(rule);

const int is_sequence= XRL_is_Sequence(rule);




if(bv_bit_test(bv,lhs_id))
goto NEXT_RULE;

rule_length= Length_of_XRL(rule);













for(rh_ix= 0;rh_ix<rule_length;rh_ix++)
{
if(!bv_bit_test
(bv,RHS_ID_of_XRL(rule,rh_ix)))
goto NEXT_RULE;
}










if(is_sequence&&Minimum_of_XRL(rule)>=2)
{
XSYID separator_id= Separator_of_XRL(rule);
if(separator_id>=0)
{
if(!bv_bit_test(bv,separator_id))
goto NEXT_RULE;
}
}







bv_bit_set(bv,lhs_id);
*(FSTACK_PUSH(stack))= lhs_id;
NEXT_RULE:;
}
}
FSTACK_DESTROY(stack);
}

/*:1136*//*1141:*/
#line 13766 "./marpa.w"

PRIVATE Bit_Matrix
matrix_buffer_create(void*buffer,int rows,int columns)
{
int row;
const LBW bv_data_words= bv_bits_to_size(columns);
const LBW bv_mask= bv_bits_to_unused_mask(columns);

Bit_Matrix matrix_addr= buffer;
matrix_addr->t_row_count= rows;
for(row= 0;row<rows;row++){
const LBW row_start= (LBW)row*(bv_data_words+bv_hiddenwords);
LBW*p_current_word= matrix_addr->t_row_data+row_start;
LBW data_word_counter= bv_data_words;
*p_current_word++= (LBW)columns;
*p_current_word++= bv_data_words;
*p_current_word++= bv_mask;
while(data_word_counter--)*p_current_word++= 0;
}
return matrix_addr;
}

/*:1141*//*1143:*/
#line 13789 "./marpa.w"

PRIVATE size_t matrix_sizeof(int rows,int columns)
{
const LBW bv_data_words= bv_bits_to_size(columns);
const LBW row_bytes= 
(LBW)(bv_data_words+bv_hiddenwords)*(LBW)sizeof(Bit_Vector_Word);
return offsetof(struct s_bit_matrix,
t_row_data)+((size_t)rows)*row_bytes;
}

/*:1143*//*1145:*/
#line 13800 "./marpa.w"

PRIVATE Bit_Matrix matrix_obs_create(
struct marpa_obstack*obs,
int rows,
int columns)
{

Bit_Matrix matrix_addr= 
marpa__obs_alloc(obs,matrix_sizeof(rows,columns),ALIGNOF(Bit_Matrix_Object));
return matrix_buffer_create(matrix_addr,rows,columns);
}

/*:1145*//*1146:*/
#line 13813 "./marpa.w"

PRIVATE void matrix_clear(Bit_Matrix matrix)
{
Bit_Vector row;
int row_ix;
const int row_count= matrix->t_row_count;
Bit_Vector row0= matrix->t_row_data+bv_hiddenwords;
LBW words_per_row= BV_SIZE(row0)+bv_hiddenwords;
row_ix= 0;row= row0;
while(row_ix<row_count){
bv_clear(row);
row_ix++;
row+= words_per_row;
}
}

/*:1146*//*1147:*/
#line 13835 "./marpa.w"

PRIVATE int matrix_columns(Bit_Matrix matrix)
{
Bit_Vector row0= matrix->t_row_data+bv_hiddenwords;
return(int)BV_BITS(row0);
}

/*:1147*//*1148:*/
#line 13851 "./marpa.w"

PRIVATE Bit_Vector matrix_row(Bit_Matrix matrix,int row)
{
Bit_Vector row0= matrix->t_row_data+bv_hiddenwords;
LBW words_per_row= BV_SIZE(row0)+bv_hiddenwords;
return row0+(LBW)row*words_per_row;
}

/*:1148*//*1150:*/
#line 13860 "./marpa.w"

PRIVATE void matrix_bit_set(Bit_Matrix matrix,int row,int column)
{
Bit_Vector vector= matrix_row(matrix,row);
bv_bit_set(vector,column);
}

/*:1150*//*1152:*/
#line 13868 "./marpa.w"

PRIVATE void matrix_bit_clear(Bit_Matrix matrix,int row,int column)
{
Bit_Vector vector= matrix_row(matrix,row);
bv_bit_clear(vector,column);
}

/*:1152*//*1154:*/
#line 13876 "./marpa.w"

PRIVATE int matrix_bit_test(Bit_Matrix matrix,int row,int column)
{
Bit_Vector vector= matrix_row(matrix,row);
return bv_bit_test(vector,column);
}

/*:1154*//*1155:*/
#line 13893 "./marpa.w"

PRIVATE_NOT_INLINE void transitive_closure(Bit_Matrix matrix)
{
int size= matrix_columns(matrix);
int outer_row;
for(outer_row= 0;outer_row<size;outer_row++)
{
Bit_Vector outer_row_v= matrix_row(matrix,outer_row);
int column;
for(column= 0;column<size;column++)
{
Bit_Vector inner_row_v= matrix_row(matrix,column);
if(bv_bit_test(inner_row_v,outer_row))
{
bv_or_assign(inner_row_v,outer_row_v);
}
}
}
}

/*:1155*//*1167:*/
#line 14034 "./marpa.w"

PRIVATE void
cilar_init(const CILAR cilar)
{
cilar->t_obs= marpa_obs_init;
cilar->t_avl= _marpa_avl_create(cil_cmp,NULL);
MARPA_DSTACK_INIT(cilar->t_buffer,int,2);
*MARPA_DSTACK_INDEX(cilar->t_buffer,int,0)= 0;
}
/*:1167*//*1168:*/
#line 14048 "./marpa.w"

PRIVATE void
cilar_buffer_reinit(const CILAR cilar)
{
MARPA_DSTACK_DESTROY(cilar->t_buffer);
MARPA_DSTACK_INIT(cilar->t_buffer,int,2);
*MARPA_DSTACK_INDEX(cilar->t_buffer,int,0)= 0;
}

/*:1168*//*1169:*/
#line 14057 "./marpa.w"

PRIVATE void cilar_destroy(const CILAR cilar)
{
_marpa_avl_destroy(cilar->t_avl);
marpa_obs_free(cilar->t_obs);
MARPA_DSTACK_DESTROY((cilar->t_buffer));
}

/*:1169*//*1170:*/
#line 14066 "./marpa.w"

PRIVATE CIL cil_empty(CILAR cilar)
{
CIL cil= MARPA_DSTACK_BASE(cilar->t_buffer,int);

Count_of_CIL(cil)= 0;
return cil_buffer_add(cilar);
}

/*:1170*//*1171:*/
#line 14076 "./marpa.w"

PRIVATE CIL cil_singleton(CILAR cilar,int element)
{
CIL cil= MARPA_DSTACK_BASE(cilar->t_buffer,int);
Count_of_CIL(cil)= 1;
Item_of_CIL(cil,0)= element;

return cil_buffer_add(cilar);
}

/*:1171*//*1172:*/
#line 14092 "./marpa.w"

PRIVATE CIL cil_buffer_add(CILAR cilar)
{

CIL cil_in_buffer= MARPA_DSTACK_BASE(cilar->t_buffer,int);
CIL found_cil= _marpa_avl_find(cilar->t_avl,cil_in_buffer);
if(!found_cil)
{
int i;
const int cil_size_in_ints= Count_of_CIL(cil_in_buffer)+1;
found_cil= marpa_obs_new(cilar->t_obs,int,cil_size_in_ints);
for(i= 0;i<cil_size_in_ints;i++)
{
found_cil[i]= cil_in_buffer[i];
}
_marpa_avl_insert(cilar->t_avl,found_cil);
}
return found_cil;
}

/*:1172*//*1173:*/
#line 14120 "./marpa.w"

PRIVATE CIL cil_bv_add(CILAR cilar,Bit_Vector bv)
{
int min,max,start= 0;
cil_buffer_clear(cilar);
for(start= 0;bv_scan(bv,start,&min,&max);start= max+2)
{
int new_item;
for(new_item= min;new_item<=max;new_item++)
{
cil_buffer_push(cilar,new_item);
}
}
return cil_buffer_add(cilar);
}

/*:1173*//*1174:*/
#line 14137 "./marpa.w"

PRIVATE void cil_buffer_clear(CILAR cilar)
{
const MARPA_DSTACK dstack= &cilar->t_buffer;
MARPA_DSTACK_CLEAR(*dstack);




*MARPA_DSTACK_PUSH(*dstack,int)= 0;
}

/*:1174*//*1175:*/
#line 14152 "./marpa.w"

PRIVATE CIL cil_buffer_push(CILAR cilar,int new_item)
{
CIL cil_in_buffer;
MARPA_DSTACK dstack= &cilar->t_buffer;
*MARPA_DSTACK_PUSH(*dstack,int)= new_item;



cil_in_buffer= MARPA_DSTACK_BASE(*dstack,int);
Count_of_CIL(cil_in_buffer)++;
return cil_in_buffer;
}

/*:1175*//*1176:*/
#line 14168 "./marpa.w"

PRIVATE CIL cil_buffer_reserve(CILAR cilar,int element_count)
{
const int desired_dstack_capacity= element_count+1;

const int old_dstack_capacity= MARPA_DSTACK_CAPACITY(cilar->t_buffer);
if(old_dstack_capacity<desired_dstack_capacity)
{
const int target_capacity= 
MAX(old_dstack_capacity*2,desired_dstack_capacity);
MARPA_DSTACK_RESIZE(&(cilar->t_buffer),int,target_capacity);
}
return MARPA_DSTACK_BASE(cilar->t_buffer,int);
}

/*:1176*//*1177:*/
#line 14187 "./marpa.w"

PRIVATE CIL cil_merge(CILAR cilar,CIL cil1,CIL cil2)
{
const int cil1_count= Count_of_CIL(cil1);
const int cil2_count= Count_of_CIL(cil2);
CIL new_cil= cil_buffer_reserve(cilar,cil1_count+cil2_count);
int new_cil_ix= 0;
int cil1_ix= 0;
int cil2_ix= 0;
while(cil1_ix<cil1_count&&cil2_ix<cil2_count)
{
const int item1= Item_of_CIL(cil1,cil1_ix);
const int item2= Item_of_CIL(cil2,cil2_ix);
if(item1<item2)
{
Item_of_CIL(new_cil,new_cil_ix)= item1;
cil1_ix++;
new_cil_ix++;
continue;
}
if(item2<item1)
{
Item_of_CIL(new_cil,new_cil_ix)= item2;
cil2_ix++;
new_cil_ix++;
continue;
}
Item_of_CIL(new_cil,new_cil_ix)= item1;
cil1_ix++;
cil2_ix++;
new_cil_ix++;
}
while(cil1_ix<cil1_count){
const int item1= Item_of_CIL(cil1,cil1_ix);
Item_of_CIL(new_cil,new_cil_ix)= item1;
cil1_ix++;
new_cil_ix++;
}
while(cil2_ix<cil2_count){
const int item2= Item_of_CIL(cil2,cil2_ix);
Item_of_CIL(new_cil,new_cil_ix)= item2;
cil2_ix++;
new_cil_ix++;
}
Count_of_CIL(new_cil)= new_cil_ix;
return cil_buffer_add(cilar);
}

/*:1177*//*1178:*/
#line 14240 "./marpa.w"

PRIVATE CIL cil_merge_one(CILAR cilar,CIL cil,int new_element)
{
const int cil_count= Count_of_CIL(cil);
CIL new_cil= cil_buffer_reserve(cilar,cil_count+1);
int new_cil_ix= 0;
int cil_ix= 0;
while(cil_ix<cil_count)
{
const int cil_item= Item_of_CIL(cil,cil_ix);
if(cil_item==new_element)
{


return NULL;
}
if(cil_item> new_element)
break;
Item_of_CIL(new_cil,new_cil_ix)= cil_item;
cil_ix++;
new_cil_ix++;
}
Item_of_CIL(new_cil,new_cil_ix)= new_element;
new_cil_ix++;
while(cil_ix<cil_count)
{
const int cil_item= Item_of_CIL(cil,cil_ix);
Item_of_CIL(new_cil,new_cil_ix)= cil_item;
cil_ix++;
new_cil_ix++;
}
Count_of_CIL(new_cil)= new_cil_ix;
return cil_buffer_add(cilar);
}

/*:1178*//*1179:*/
#line 14275 "./marpa.w"

PRIVATE_NOT_INLINE int
cil_cmp(const void*ap,const void*bp,void*param UNUSED)
{
int ix;
CIL cil1= (CIL)ap;
CIL cil2= (CIL)bp;
int count1= Count_of_CIL(cil1);
int count2= Count_of_CIL(cil2);
if(count1!=count2)
{
return count1> count2?1:-1;
}
for(ix= 0;ix<count1;ix++)
{
const int item1= Item_of_CIL(cil1,ix);
const int item2= Item_of_CIL(cil2,ix);
if(item1==item2)
continue;
return item1> item2?1:-1;
}
return 0;
}

/*:1179*//*1192:*/
#line 14414 "./marpa.w"

PRIVATE void
psar_safe(const PSAR psar)
{
psar->t_psl_length= 0;
psar->t_first_psl= psar->t_first_free_psl= NULL;
}
/*:1192*//*1193:*/
#line 14421 "./marpa.w"

PRIVATE void
psar_init(const PSAR psar,int length)
{
psar->t_psl_length= length;
psar->t_first_psl= psar->t_first_free_psl= psl_new(psar);
}
/*:1193*//*1194:*/
#line 14428 "./marpa.w"

PRIVATE void psar_destroy(const PSAR psar)
{
PSL psl= psar->t_first_psl;
while(psl)
{
PSL next_psl= psl->t_next;
PSL*owner= psl->t_owner;
if(owner)
*owner= NULL;
my_free(psl);
psl= next_psl;
}
}
/*:1194*//*1195:*/
#line 14442 "./marpa.w"

PRIVATE PSL psl_new(const PSAR psar)
{
int i;
PSL new_psl= my_malloc(Sizeof_PSL(psar));
new_psl->t_next= NULL;
new_psl->t_prev= NULL;
new_psl->t_owner= NULL;
for(i= 0;i<psar->t_psl_length;i++){
PSL_Datum(new_psl,i)= NULL;
}
return new_psl;
}
/*:1195*//*1198:*/
#line 14473 "./marpa.w"

PRIVATE void psar_reset(const PSAR psar)
{
PSL psl= psar->t_first_psl;
while(psl&&psl->t_owner){
int i;
for(i= 0;i<psar->t_psl_length;i++){
PSL_Datum(psl,i)= NULL;
}
psl= psl->t_next;
}
psar_dealloc(psar);
}

/*:1198*//*1200:*/
#line 14491 "./marpa.w"

PRIVATE void psar_dealloc(const PSAR psar)
{
PSL psl= psar->t_first_psl;
while(psl){
PSL*owner= psl->t_owner;
if(!owner)break;
(*owner)= NULL;
psl->t_owner= NULL;
psl= psl->t_next;
}
psar->t_first_free_psl= psar->t_first_psl;
}

/*:1200*//*1202:*/
#line 14511 "./marpa.w"

PRIVATE void psl_claim(
PSL*const psl_owner,const PSAR psar)
{
PSL new_psl= psl_alloc(psar);
(*psl_owner)= new_psl;
new_psl->t_owner= psl_owner;
}


/*:1202*//*1203:*/
#line 14521 "./marpa.w"

PRIVATE PSL psl_claim_by_es(
PSAR or_psar,
struct s_bocage_setup_per_ys*per_ys_data,
YSID ysid)
{
PSL*psl_owner= &(per_ys_data[ysid].t_or_psl);
if(!*psl_owner)
psl_claim(psl_owner,or_psar);
return*psl_owner;
}

/*:1203*//*1204:*/
#line 14538 "./marpa.w"

PRIVATE PSL psl_alloc(const PSAR psar)
{
PSL free_psl= psar->t_first_free_psl;
PSL next_psl= free_psl->t_next;
if(!next_psl){
next_psl= free_psl->t_next= psl_new(psar);
next_psl->t_prev= free_psl;
}
psar->t_first_free_psl= next_psl;
return free_psl;
}

/*:1204*//*1232:*/
#line 14770 "./marpa.w"

PRIVATE_NOT_INLINE void
set_error(GRAMMAR g,Marpa_Error_Code code,const char*message,unsigned int flags)
{
g->t_error= code;
g->t_error_string= message;
if(flags&FATAL_FLAG)
g->t_is_ok= 0;
}
/*:1232*//*1233:*/
#line 14789 "./marpa.w"

PRIVATE Marpa_Error_Code
clear_error(GRAMMAR g)
{
if(!IS_G_OK(g))
{
if(g->t_error==MARPA_ERR_NONE)
g->t_error= MARPA_ERR_I_AM_NOT_OK;
return g->t_error;
}
g->t_error= MARPA_ERR_NONE;
g->t_error_string= NULL;
return MARPA_ERR_NONE;
}

/*:1233*//*1237:*/
#line 14832 "./marpa.w"

PRIVATE_NOT_INLINE void*
marpa__default_out_of_memory(void)
{
abort();
return NULL;
}
void*(*const marpa__out_of_memory)(void)= marpa__default_out_of_memory;

/*:1237*//*1242:*/
#line 14870 "./marpa.w"

Marpa_Earley_Set_ID _marpa_r_trace_earley_set(Marpa_Recognizer r)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 14873 "./marpa.w"

/*560:*/
#line 6076 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:560*/
#line 14874 "./marpa.w"

YS trace_earley_set= r->t_trace_earley_set;
/*1228:*/
#line 14714 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 14715 "./marpa.w"

/*1226:*/
#line 14698 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1226*/
#line 14716 "./marpa.w"


/*:1228*/
#line 14876 "./marpa.w"

if(!trace_earley_set){
MARPA_ERROR(MARPA_ERR_NO_TRACE_YS);
return failure_indicator;
}
return Ord_of_YS(trace_earley_set);
}

/*:1242*//*1243:*/
#line 14884 "./marpa.w"

Marpa_Earley_Set_ID marpa_r_latest_earley_set(Marpa_Recognizer r)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 14887 "./marpa.w"

/*560:*/
#line 6076 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:560*/
#line 14888 "./marpa.w"

/*1228:*/
#line 14714 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 14715 "./marpa.w"

/*1226:*/
#line 14698 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1226*/
#line 14716 "./marpa.w"


/*:1228*/
#line 14889 "./marpa.w"

if(G_is_Trivial(g))return 0;
return Ord_of_YS(Latest_YS_of_R(r));
}

/*:1243*//*1244:*/
#line 14894 "./marpa.w"

Marpa_Earleme marpa_r_earleme(Marpa_Recognizer r,Marpa_Earley_Set_ID set_id)
{
/*560:*/
#line 6076 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:560*/
#line 14897 "./marpa.w"

/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 14898 "./marpa.w"

YS earley_set;
/*1226:*/
#line 14698 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1226*/
#line 14900 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 14901 "./marpa.w"

if(set_id<0){
MARPA_ERROR(MARPA_ERR_INVALID_LOCATION);
return failure_indicator;
}
r_update_earley_sets(r);
if(!YS_Ord_is_Valid(r,set_id))
{
MARPA_ERROR(MARPA_ERR_NO_EARLEY_SET_AT_LOCATION);
return failure_indicator;
}
earley_set= YS_of_R_by_Ord(r,set_id);
return Earleme_of_YS(earley_set);
}

/*:1244*//*1246:*/
#line 14919 "./marpa.w"

int _marpa_r_earley_set_size(Marpa_Recognizer r,Marpa_Earley_Set_ID set_id)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 14922 "./marpa.w"

YS earley_set;
/*560:*/
#line 6076 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:560*/
#line 14924 "./marpa.w"

/*1226:*/
#line 14698 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1226*/
#line 14925 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 14926 "./marpa.w"

r_update_earley_sets(r);
if(!YS_Ord_is_Valid(r,set_id))
{
MARPA_ERROR(MARPA_ERR_INVALID_LOCATION);
return failure_indicator;
}
earley_set= YS_of_R_by_Ord(r,set_id);
return YIM_Count_of_YS(earley_set);
}

/*:1246*//*1251:*/
#line 14968 "./marpa.w"

Marpa_Earleme
_marpa_r_earley_set_trace(Marpa_Recognizer r,Marpa_Earley_Set_ID set_id)
{
YS earley_set;
const int es_does_not_exist= -1;
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 14974 "./marpa.w"

/*560:*/
#line 6076 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:560*/
#line 14975 "./marpa.w"

/*1228:*/
#line 14714 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 14715 "./marpa.w"

/*1226:*/
#line 14698 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1226*/
#line 14716 "./marpa.w"


/*:1228*/
#line 14976 "./marpa.w"

if(r->t_trace_earley_set&&Ord_of_YS(r->t_trace_earley_set)==set_id)
{


return Earleme_of_YS(r->t_trace_earley_set);
}
/*1252:*/
#line 14999 "./marpa.w"
{
r->t_trace_earley_set= NULL;
trace_earley_item_clear(r);
/*1264:*/
#line 15188 "./marpa.w"

r->t_trace_pim_nsy_p= NULL;
r->t_trace_postdot_item= NULL;

/*:1264*/
#line 15002 "./marpa.w"

}

/*:1252*/
#line 14983 "./marpa.w"

if(set_id<0)
{
MARPA_ERROR(MARPA_ERR_INVALID_LOCATION);
return failure_indicator;
}
r_update_earley_sets(r);
if(set_id>=MARPA_DSTACK_LENGTH(r->t_earley_set_stack))
{
return es_does_not_exist;
}
earley_set= YS_of_R_by_Ord(r,set_id);
r->t_trace_earley_set= earley_set;
return Earleme_of_YS(earley_set);
}

/*:1251*//*1253:*/
#line 15005 "./marpa.w"

Marpa_AHM_ID
_marpa_r_earley_item_trace(Marpa_Recognizer r,Marpa_Earley_Item_ID item_id)
{
const int yim_does_not_exist= -1;
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 15010 "./marpa.w"

YS trace_earley_set;
YIM earley_item;
YIM*earley_items;
/*560:*/
#line 6076 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:560*/
#line 15014 "./marpa.w"

/*1228:*/
#line 14714 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 14715 "./marpa.w"

/*1226:*/
#line 14698 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1226*/
#line 14716 "./marpa.w"


/*:1228*/
#line 15015 "./marpa.w"

trace_earley_set= r->t_trace_earley_set;
if(!trace_earley_set)
{
/*1252:*/
#line 14999 "./marpa.w"
{
r->t_trace_earley_set= NULL;
trace_earley_item_clear(r);
/*1264:*/
#line 15188 "./marpa.w"

r->t_trace_pim_nsy_p= NULL;
r->t_trace_postdot_item= NULL;

/*:1264*/
#line 15002 "./marpa.w"

}

/*:1252*/
#line 15019 "./marpa.w"

MARPA_ERROR(MARPA_ERR_NO_TRACE_YS);
return failure_indicator;
}
trace_earley_item_clear(r);
if(item_id<0)
{
MARPA_ERROR(MARPA_ERR_YIM_ID_INVALID);
return failure_indicator;
}
if(item_id>=YIM_Count_of_YS(trace_earley_set))
{
return yim_does_not_exist;
}
earley_items= YIMs_of_YS(trace_earley_set);
earley_item= earley_items[item_id];
r->t_trace_earley_item= earley_item;
return AHMID_of_YIM(earley_item);
}

/*:1253*//*1255:*/
#line 15048 "./marpa.w"

PRIVATE void trace_earley_item_clear(RECCE r)
{
/*1254:*/
#line 15045 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:1254*/
#line 15051 "./marpa.w"

trace_source_link_clear(r);
}

/*:1255*//*1256:*/
#line 15055 "./marpa.w"

Marpa_Earley_Set_ID _marpa_r_earley_item_origin(Marpa_Recognizer r)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 15058 "./marpa.w"

YIM item= r->t_trace_earley_item;
/*560:*/
#line 6076 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:560*/
#line 15060 "./marpa.w"

/*1228:*/
#line 14714 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 14715 "./marpa.w"

/*1226:*/
#line 14698 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1226*/
#line 14716 "./marpa.w"


/*:1228*/
#line 15061 "./marpa.w"

if(!item){
/*1254:*/
#line 15045 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:1254*/
#line 15063 "./marpa.w"

MARPA_ERROR(MARPA_ERR_NO_TRACE_YIM);
return failure_indicator;
}
return Origin_Ord_of_YIM(item);
}

/*:1256*//*1258:*/
#line 15075 "./marpa.w"

Marpa_Symbol_ID _marpa_r_leo_predecessor_symbol(Marpa_Recognizer r)
{
const Marpa_Symbol_ID no_predecessor= -1;
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 15079 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
LIM predecessor_leo_item;
/*560:*/
#line 6076 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:560*/
#line 15082 "./marpa.w"

/*1228:*/
#line 14714 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 14715 "./marpa.w"

/*1226:*/
#line 14698 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1226*/
#line 14716 "./marpa.w"


/*:1228*/
#line 15083 "./marpa.w"

if(!postdot_item){
MARPA_ERROR(MARPA_ERR_NO_TRACE_PIM);
return failure_indicator;
}
if(YIM_of_PIM(postdot_item)){
MARPA_ERROR(MARPA_ERR_PIM_IS_NOT_LIM);
return failure_indicator;
}
predecessor_leo_item= Predecessor_LIM_of_LIM(LIM_of_PIM(postdot_item));
if(!predecessor_leo_item)return no_predecessor;
return Postdot_NSYID_of_LIM(predecessor_leo_item);
}

/*:1258*//*1259:*/
#line 15097 "./marpa.w"

Marpa_Earley_Set_ID _marpa_r_leo_base_origin(Marpa_Recognizer r)
{
const JEARLEME pim_is_not_a_leo_item= -1;
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 15101 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
/*560:*/
#line 6076 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:560*/
#line 15103 "./marpa.w"

YIM base_earley_item;
/*1228:*/
#line 14714 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 14715 "./marpa.w"

/*1226:*/
#line 14698 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1226*/
#line 14716 "./marpa.w"


/*:1228*/
#line 15105 "./marpa.w"

if(!postdot_item){
MARPA_ERROR(MARPA_ERR_NO_TRACE_PIM);
return failure_indicator;
}
if(YIM_of_PIM(postdot_item))return pim_is_not_a_leo_item;
base_earley_item= Trailhead_YIM_of_LIM(LIM_of_PIM(postdot_item));
return Origin_Ord_of_YIM(base_earley_item);
}

/*:1259*//*1260:*/
#line 15116 "./marpa.w"

Marpa_AHM_ID _marpa_r_leo_base_state(Marpa_Recognizer r)
{
const JEARLEME pim_is_not_a_leo_item= -1;
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 15120 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
YIM base_earley_item;
/*560:*/
#line 6076 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:560*/
#line 15123 "./marpa.w"

/*1228:*/
#line 14714 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 14715 "./marpa.w"

/*1226:*/
#line 14698 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1226*/
#line 14716 "./marpa.w"


/*:1228*/
#line 15124 "./marpa.w"

if(!postdot_item){
MARPA_ERROR(MARPA_ERR_NO_TRACE_PIM);
return failure_indicator;
}
if(YIM_of_PIM(postdot_item))return pim_is_not_a_leo_item;
base_earley_item= Trailhead_YIM_of_LIM(LIM_of_PIM(postdot_item));
return AHMID_of_YIM(base_earley_item);
}

/*:1260*//*1263:*/
#line 15162 "./marpa.w"

Marpa_Symbol_ID
_marpa_r_postdot_symbol_trace(Marpa_Recognizer r,
Marpa_Symbol_ID nsy_id)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 15167 "./marpa.w"

YS current_ys= r->t_trace_earley_set;
PIM*pim_nsy_p;
PIM pim;
/*560:*/
#line 6076 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:560*/
#line 15171 "./marpa.w"

/*1264:*/
#line 15188 "./marpa.w"

r->t_trace_pim_nsy_p= NULL;
r->t_trace_postdot_item= NULL;

/*:1264*/
#line 15172 "./marpa.w"

/*1228:*/
#line 14714 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 14715 "./marpa.w"

/*1226:*/
#line 14698 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1226*/
#line 14716 "./marpa.w"


/*:1228*/
#line 15173 "./marpa.w"

/*1216:*/
#line 14628 "./marpa.w"

if(_MARPA_UNLIKELY(NSYID_is_Malformed(nsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1216*/
#line 15174 "./marpa.w"

/*1217:*/
#line 14635 "./marpa.w"

if(_MARPA_UNLIKELY(!NSYID_of_G_Exists(nsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}

/*:1217*/
#line 15175 "./marpa.w"

if(!current_ys){
MARPA_ERROR(MARPA_ERR_NO_TRACE_YS);
return failure_indicator;
}
pim_nsy_p= PIM_NSY_P_of_YS_by_NSYID(current_ys,nsy_id);
pim= *pim_nsy_p;
if(!pim)return-1;
r->t_trace_pim_nsy_p= pim_nsy_p;
r->t_trace_postdot_item= pim;
return nsy_id;
}

/*:1263*//*1265:*/
#line 15198 "./marpa.w"

Marpa_Symbol_ID
_marpa_r_first_postdot_item_trace(Marpa_Recognizer r)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 15202 "./marpa.w"

YS current_earley_set= r->t_trace_earley_set;
PIM pim;
/*560:*/
#line 6076 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:560*/
#line 15205 "./marpa.w"

PIM*pim_nsy_p;
/*1264:*/
#line 15188 "./marpa.w"

r->t_trace_pim_nsy_p= NULL;
r->t_trace_postdot_item= NULL;

/*:1264*/
#line 15207 "./marpa.w"

/*1228:*/
#line 14714 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 14715 "./marpa.w"

/*1226:*/
#line 14698 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1226*/
#line 14716 "./marpa.w"


/*:1228*/
#line 15208 "./marpa.w"

if(!current_earley_set){
/*1254:*/
#line 15045 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:1254*/
#line 15210 "./marpa.w"

MARPA_ERROR(MARPA_ERR_NO_TRACE_YS);
return failure_indicator;
}
if(current_earley_set->t_postdot_sym_count<=0)return-1;
pim_nsy_p= current_earley_set->t_postdot_ary+0;
pim= pim_nsy_p[0];
r->t_trace_pim_nsy_p= pim_nsy_p;
r->t_trace_postdot_item= pim;
return Postdot_NSYID_of_PIM(pim);
}

/*:1265*//*1266:*/
#line 15229 "./marpa.w"

Marpa_Symbol_ID
_marpa_r_next_postdot_item_trace(Marpa_Recognizer r)
{
const XSYID no_more_postdot_symbols= -1;
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 15234 "./marpa.w"

YS current_set= r->t_trace_earley_set;
PIM pim;
PIM*pim_nsy_p;
/*560:*/
#line 6076 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:560*/
#line 15238 "./marpa.w"


pim_nsy_p= r->t_trace_pim_nsy_p;
pim= r->t_trace_postdot_item;
/*1264:*/
#line 15188 "./marpa.w"

r->t_trace_pim_nsy_p= NULL;
r->t_trace_postdot_item= NULL;

/*:1264*/
#line 15242 "./marpa.w"

if(!pim_nsy_p||!pim){
MARPA_ERROR(MARPA_ERR_NO_TRACE_PIM);
return failure_indicator;
}
/*1228:*/
#line 14714 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 14715 "./marpa.w"

/*1226:*/
#line 14698 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1226*/
#line 14716 "./marpa.w"


/*:1228*/
#line 15247 "./marpa.w"

if(!current_set){
MARPA_ERROR(MARPA_ERR_NO_TRACE_YS);
return failure_indicator;
}
pim= Next_PIM_of_PIM(pim);
if(!pim){

pim_nsy_p++;
if(pim_nsy_p-current_set->t_postdot_ary
>=current_set->t_postdot_sym_count){
return no_more_postdot_symbols;
}
pim= *pim_nsy_p;
}
r->t_trace_pim_nsy_p= pim_nsy_p;
r->t_trace_postdot_item= pim;
return Postdot_NSYID_of_PIM(pim);
}

/*:1266*//*1267:*/
#line 15267 "./marpa.w"

Marpa_Symbol_ID _marpa_r_postdot_item_symbol(Marpa_Recognizer r)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 15270 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
/*560:*/
#line 6076 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:560*/
#line 15272 "./marpa.w"

/*1228:*/
#line 14714 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 14715 "./marpa.w"

/*1226:*/
#line 14698 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1226*/
#line 14716 "./marpa.w"


/*:1228*/
#line 15273 "./marpa.w"

if(!postdot_item){
MARPA_ERROR(MARPA_ERR_NO_TRACE_PIM);
return failure_indicator;
}
return Postdot_NSYID_of_PIM(postdot_item);
}

/*:1267*//*1272:*/
#line 15303 "./marpa.w"

Marpa_Symbol_ID _marpa_r_first_token_link_trace(Marpa_Recognizer r)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 15306 "./marpa.w"

SRCL source_link;
unsigned int source_type;
YIM item= r->t_trace_earley_item;
/*560:*/
#line 6076 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:560*/
#line 15310 "./marpa.w"

/*1228:*/
#line 14714 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 14715 "./marpa.w"

/*1226:*/
#line 14698 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1226*/
#line 14716 "./marpa.w"


/*:1228*/
#line 15311 "./marpa.w"

/*1286:*/
#line 15500 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
MARPA_ERROR(MARPA_ERR_NO_TRACE_YIM);
return failure_indicator;
}

/*:1286*/
#line 15312 "./marpa.w"

source_type= Source_Type_of_YIM(item);
switch(source_type)
{
case SOURCE_IS_TOKEN:
r->t_trace_source_type= SOURCE_IS_TOKEN;
source_link= SRCL_of_YIM(item);
r->t_trace_source_link= source_link;
return NSYID_of_SRCL(source_link);
case SOURCE_IS_AMBIGUOUS:
{
source_link= LV_First_Token_SRCL_of_YIM(item);
if(source_link)
{
r->t_trace_source_type= SOURCE_IS_TOKEN;
r->t_trace_source_link= source_link;
return NSYID_of_SRCL(source_link);
}
}
}
trace_source_link_clear(r);
return-1;
}

/*:1272*//*1275:*/
#line 15344 "./marpa.w"

Marpa_Symbol_ID _marpa_r_next_token_link_trace(Marpa_Recognizer r)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 15347 "./marpa.w"

SRCL source_link;
YIM item;
/*560:*/
#line 6076 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:560*/
#line 15350 "./marpa.w"

/*1228:*/
#line 14714 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 14715 "./marpa.w"

/*1226:*/
#line 14698 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1226*/
#line 14716 "./marpa.w"


/*:1228*/
#line 15351 "./marpa.w"

/*1286:*/
#line 15500 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
MARPA_ERROR(MARPA_ERR_NO_TRACE_YIM);
return failure_indicator;
}

/*:1286*/
#line 15352 "./marpa.w"

if(r->t_trace_source_type!=SOURCE_IS_TOKEN){
trace_source_link_clear(r);
MARPA_ERROR(MARPA_ERR_NOT_TRACING_TOKEN_LINKS);
return failure_indicator;
}
source_link= Next_SRCL_of_SRCL(r->t_trace_source_link);
if(!source_link){
trace_source_link_clear(r);
return-1;
}
r->t_trace_source_link= source_link;
return NSYID_of_SRCL(source_link);
}

/*:1275*//*1277:*/
#line 15375 "./marpa.w"

Marpa_Symbol_ID _marpa_r_first_completion_link_trace(Marpa_Recognizer r)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 15378 "./marpa.w"

SRCL source_link;
unsigned int source_type;
YIM item= r->t_trace_earley_item;
/*560:*/
#line 6076 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:560*/
#line 15382 "./marpa.w"

/*1228:*/
#line 14714 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 14715 "./marpa.w"

/*1226:*/
#line 14698 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1226*/
#line 14716 "./marpa.w"


/*:1228*/
#line 15383 "./marpa.w"

/*1286:*/
#line 15500 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
MARPA_ERROR(MARPA_ERR_NO_TRACE_YIM);
return failure_indicator;
}

/*:1286*/
#line 15384 "./marpa.w"

switch((source_type= Source_Type_of_YIM(item)))
{
case SOURCE_IS_COMPLETION:
r->t_trace_source_type= SOURCE_IS_COMPLETION;
source_link= SRCL_of_YIM(item);
r->t_trace_source_link= source_link;
return Cause_AHMID_of_SRCL(source_link);
case SOURCE_IS_AMBIGUOUS:
{
source_link= LV_First_Completion_SRCL_of_YIM(item);
if(source_link)
{
r->t_trace_source_type= SOURCE_IS_COMPLETION;
r->t_trace_source_link= source_link;
return Cause_AHMID_of_SRCL(source_link);
}
}
}
trace_source_link_clear(r);
return-1;
}

/*:1277*//*1280:*/
#line 15415 "./marpa.w"

Marpa_Symbol_ID _marpa_r_next_completion_link_trace(Marpa_Recognizer r)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 15418 "./marpa.w"

SRCL source_link;
YIM item;
/*560:*/
#line 6076 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:560*/
#line 15421 "./marpa.w"

/*1228:*/
#line 14714 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 14715 "./marpa.w"

/*1226:*/
#line 14698 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1226*/
#line 14716 "./marpa.w"


/*:1228*/
#line 15422 "./marpa.w"

/*1286:*/
#line 15500 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
MARPA_ERROR(MARPA_ERR_NO_TRACE_YIM);
return failure_indicator;
}

/*:1286*/
#line 15423 "./marpa.w"

if(r->t_trace_source_type!=SOURCE_IS_COMPLETION){
trace_source_link_clear(r);
MARPA_ERROR(MARPA_ERR_NOT_TRACING_COMPLETION_LINKS);
return failure_indicator;
}
source_link= Next_SRCL_of_SRCL(r->t_trace_source_link);
if(!source_link){
trace_source_link_clear(r);
return-1;
}
r->t_trace_source_link= source_link;
return Cause_AHMID_of_SRCL(source_link);
}

/*:1280*//*1282:*/
#line 15446 "./marpa.w"

Marpa_Symbol_ID
_marpa_r_first_leo_link_trace(Marpa_Recognizer r)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 15450 "./marpa.w"

SRCL source_link;
YIM item= r->t_trace_earley_item;
/*560:*/
#line 6076 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:560*/
#line 15453 "./marpa.w"

/*1228:*/
#line 14714 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 14715 "./marpa.w"

/*1226:*/
#line 14698 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1226*/
#line 14716 "./marpa.w"


/*:1228*/
#line 15454 "./marpa.w"

/*1286:*/
#line 15500 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
MARPA_ERROR(MARPA_ERR_NO_TRACE_YIM);
return failure_indicator;
}

/*:1286*/
#line 15455 "./marpa.w"

source_link= First_Leo_SRCL_of_YIM(item);
if(source_link){
r->t_trace_source_type= SOURCE_IS_LEO;
r->t_trace_source_link= source_link;
return Cause_AHMID_of_SRCL(source_link);
}
trace_source_link_clear(r);
return-1;
}

/*:1282*//*1285:*/
#line 15474 "./marpa.w"

Marpa_Symbol_ID
_marpa_r_next_leo_link_trace(Marpa_Recognizer r)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 15478 "./marpa.w"

SRCL source_link;
YIM item;
/*560:*/
#line 6076 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:560*/
#line 15481 "./marpa.w"

/*1228:*/
#line 14714 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 14715 "./marpa.w"

/*1226:*/
#line 14698 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1226*/
#line 14716 "./marpa.w"


/*:1228*/
#line 15482 "./marpa.w"

/*1286:*/
#line 15500 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
MARPA_ERROR(MARPA_ERR_NO_TRACE_YIM);
return failure_indicator;
}

/*:1286*/
#line 15483 "./marpa.w"

if(r->t_trace_source_type!=SOURCE_IS_LEO)
{
trace_source_link_clear(r);
MARPA_ERROR(MARPA_ERR_NOT_TRACING_LEO_LINKS);
return failure_indicator;
}
source_link= Next_SRCL_of_SRCL(r->t_trace_source_link);
if(!source_link)
{
trace_source_link_clear(r);
return-1;
}
r->t_trace_source_link= source_link;
return Cause_AHMID_of_SRCL(source_link);
}

/*:1285*//*1287:*/
#line 15509 "./marpa.w"

PRIVATE void trace_source_link_clear(RECCE r)
{
r->t_trace_source_link= NULL;
r->t_trace_source_type= NO_SOURCE;
}

/*:1287*//*1288:*/
#line 15524 "./marpa.w"

AHMID _marpa_r_source_predecessor_state(Marpa_Recognizer r)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 15527 "./marpa.w"

unsigned int source_type;
SRCL source_link;
/*560:*/
#line 6076 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:560*/
#line 15530 "./marpa.w"

/*1228:*/
#line 14714 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 14715 "./marpa.w"

/*1226:*/
#line 14698 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1226*/
#line 14716 "./marpa.w"


/*:1228*/
#line 15531 "./marpa.w"

source_type= r->t_trace_source_type;
/*1294:*/
#line 15676 "./marpa.w"

source_link= r->t_trace_source_link;
if(!source_link){
MARPA_ERROR(MARPA_ERR_NO_TRACE_SRCL);
return failure_indicator;
}

/*:1294*/
#line 15533 "./marpa.w"

switch(source_type)
{
case SOURCE_IS_TOKEN:
case SOURCE_IS_COMPLETION:{
YIM predecessor= Predecessor_of_SRCL(source_link);
if(!predecessor)return-1;
return AHMID_of_YIM(predecessor);
}
}
MARPA_ERROR(invalid_source_type_code(source_type));
return failure_indicator;
}

/*:1288*//*1289:*/
#line 15565 "./marpa.w"

Marpa_Symbol_ID _marpa_r_source_token(Marpa_Recognizer r,int*value_p)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 15568 "./marpa.w"

unsigned int source_type;
SRCL source_link;
/*560:*/
#line 6076 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:560*/
#line 15571 "./marpa.w"

/*1228:*/
#line 14714 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 14715 "./marpa.w"

/*1226:*/
#line 14698 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1226*/
#line 14716 "./marpa.w"


/*:1228*/
#line 15572 "./marpa.w"

source_type= r->t_trace_source_type;
/*1294:*/
#line 15676 "./marpa.w"

source_link= r->t_trace_source_link;
if(!source_link){
MARPA_ERROR(MARPA_ERR_NO_TRACE_SRCL);
return failure_indicator;
}

/*:1294*/
#line 15574 "./marpa.w"

if(source_type==SOURCE_IS_TOKEN){
if(value_p)*value_p= Value_of_SRCL(source_link);
return NSYID_of_SRCL(source_link);
}
MARPA_ERROR(invalid_source_type_code(source_type));
return failure_indicator;
}

/*:1289*//*1291:*/
#line 15596 "./marpa.w"

Marpa_Symbol_ID _marpa_r_source_leo_transition_symbol(Marpa_Recognizer r)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 15599 "./marpa.w"

unsigned int source_type;
SRCL source_link;
/*560:*/
#line 6076 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:560*/
#line 15602 "./marpa.w"

/*1228:*/
#line 14714 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 14715 "./marpa.w"

/*1226:*/
#line 14698 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1226*/
#line 14716 "./marpa.w"


/*:1228*/
#line 15603 "./marpa.w"

source_type= r->t_trace_source_type;
/*1294:*/
#line 15676 "./marpa.w"

source_link= r->t_trace_source_link;
if(!source_link){
MARPA_ERROR(MARPA_ERR_NO_TRACE_SRCL);
return failure_indicator;
}

/*:1294*/
#line 15605 "./marpa.w"

switch(source_type)
{
case SOURCE_IS_LEO:
return Leo_Transition_NSYID_of_SRCL(source_link);
}
MARPA_ERROR(invalid_source_type_code(source_type));
return failure_indicator;
}

/*:1291*//*1293:*/
#line 15639 "./marpa.w"

Marpa_Earley_Set_ID _marpa_r_source_middle(Marpa_Recognizer r)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 15642 "./marpa.w"

YIM predecessor_yim= NULL;
unsigned int source_type;
SRCL source_link;
/*560:*/
#line 6076 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:560*/
#line 15646 "./marpa.w"

/*1228:*/
#line 14714 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 14715 "./marpa.w"

/*1226:*/
#line 14698 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1226*/
#line 14716 "./marpa.w"


/*:1228*/
#line 15647 "./marpa.w"

source_type= r->t_trace_source_type;
/*1294:*/
#line 15676 "./marpa.w"

source_link= r->t_trace_source_link;
if(!source_link){
MARPA_ERROR(MARPA_ERR_NO_TRACE_SRCL);
return failure_indicator;
}

/*:1294*/
#line 15649 "./marpa.w"


switch(source_type)
{
case SOURCE_IS_LEO:
{
LIM predecessor= LIM_of_SRCL(source_link);
if(predecessor)
predecessor_yim= Trailhead_YIM_of_LIM(predecessor);
break;
}
case SOURCE_IS_TOKEN:
case SOURCE_IS_COMPLETION:
{
predecessor_yim= Predecessor_of_SRCL(source_link);
break;
}
default:
MARPA_ERROR(invalid_source_type_code(source_type));
return failure_indicator;
}

if(predecessor_yim)
return YS_Ord_of_YIM(predecessor_yim);
return Origin_Ord_of_YIM(r->t_trace_earley_item);
}

/*:1293*//*1298:*/
#line 15714 "./marpa.w"

int _marpa_b_or_node_set(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 15719 "./marpa.w"

/*939:*/
#line 11082 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:939*/
#line 15720 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 15721 "./marpa.w"

/*1296:*/
#line 15692 "./marpa.w"

{
if(_MARPA_UNLIKELY(or_node_id>=OR_Count_of_B(b)))
{
return-1;
}
if(_MARPA_UNLIKELY(or_node_id<0))
{
MARPA_ERROR(MARPA_ERR_ORID_NEGATIVE);
return failure_indicator;
}
}
/*:1296*/
#line 15722 "./marpa.w"

/*1297:*/
#line 15704 "./marpa.w"

{
if(_MARPA_UNLIKELY(!ORs_of_B(b)))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= OR_of_B_by_ID(b,or_node_id);
}

/*:1297*/
#line 15723 "./marpa.w"

return YS_Ord_of_OR(or_node);
}

/*:1298*//*1299:*/
#line 15727 "./marpa.w"

int _marpa_b_or_node_origin(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 15732 "./marpa.w"

/*939:*/
#line 11082 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:939*/
#line 15733 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 15734 "./marpa.w"

/*1296:*/
#line 15692 "./marpa.w"

{
if(_MARPA_UNLIKELY(or_node_id>=OR_Count_of_B(b)))
{
return-1;
}
if(_MARPA_UNLIKELY(or_node_id<0))
{
MARPA_ERROR(MARPA_ERR_ORID_NEGATIVE);
return failure_indicator;
}
}
/*:1296*/
#line 15735 "./marpa.w"

/*1297:*/
#line 15704 "./marpa.w"

{
if(_MARPA_UNLIKELY(!ORs_of_B(b)))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= OR_of_B_by_ID(b,or_node_id);
}

/*:1297*/
#line 15736 "./marpa.w"

return Origin_Ord_of_OR(or_node);
}

/*:1299*//*1300:*/
#line 15740 "./marpa.w"

Marpa_IRL_ID _marpa_b_or_node_irl(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 15745 "./marpa.w"

/*939:*/
#line 11082 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:939*/
#line 15746 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 15747 "./marpa.w"

/*1296:*/
#line 15692 "./marpa.w"

{
if(_MARPA_UNLIKELY(or_node_id>=OR_Count_of_B(b)))
{
return-1;
}
if(_MARPA_UNLIKELY(or_node_id<0))
{
MARPA_ERROR(MARPA_ERR_ORID_NEGATIVE);
return failure_indicator;
}
}
/*:1296*/
#line 15748 "./marpa.w"

/*1297:*/
#line 15704 "./marpa.w"

{
if(_MARPA_UNLIKELY(!ORs_of_B(b)))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= OR_of_B_by_ID(b,or_node_id);
}

/*:1297*/
#line 15749 "./marpa.w"

return IRLID_of_OR(or_node);
}

/*:1300*//*1301:*/
#line 15753 "./marpa.w"

int _marpa_b_or_node_position(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 15758 "./marpa.w"

/*939:*/
#line 11082 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:939*/
#line 15759 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 15760 "./marpa.w"

/*1296:*/
#line 15692 "./marpa.w"

{
if(_MARPA_UNLIKELY(or_node_id>=OR_Count_of_B(b)))
{
return-1;
}
if(_MARPA_UNLIKELY(or_node_id<0))
{
MARPA_ERROR(MARPA_ERR_ORID_NEGATIVE);
return failure_indicator;
}
}
/*:1296*/
#line 15761 "./marpa.w"

/*1297:*/
#line 15704 "./marpa.w"

{
if(_MARPA_UNLIKELY(!ORs_of_B(b)))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= OR_of_B_by_ID(b,or_node_id);
}

/*:1297*/
#line 15762 "./marpa.w"

return Position_of_OR(or_node);
}

/*:1301*//*1302:*/
#line 15766 "./marpa.w"

int _marpa_b_or_node_is_whole(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 15771 "./marpa.w"

/*939:*/
#line 11082 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:939*/
#line 15772 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 15773 "./marpa.w"

/*1296:*/
#line 15692 "./marpa.w"

{
if(_MARPA_UNLIKELY(or_node_id>=OR_Count_of_B(b)))
{
return-1;
}
if(_MARPA_UNLIKELY(or_node_id<0))
{
MARPA_ERROR(MARPA_ERR_ORID_NEGATIVE);
return failure_indicator;
}
}
/*:1296*/
#line 15774 "./marpa.w"

/*1297:*/
#line 15704 "./marpa.w"

{
if(_MARPA_UNLIKELY(!ORs_of_B(b)))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= OR_of_B_by_ID(b,or_node_id);
}

/*:1297*/
#line 15775 "./marpa.w"

return Position_of_OR(or_node)>=Length_of_IRL(IRL_of_OR(or_node))?1:0;
}

/*:1302*//*1303:*/
#line 15779 "./marpa.w"

int _marpa_b_or_node_is_semantic(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 15784 "./marpa.w"

/*939:*/
#line 11082 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:939*/
#line 15785 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 15786 "./marpa.w"

/*1296:*/
#line 15692 "./marpa.w"

{
if(_MARPA_UNLIKELY(or_node_id>=OR_Count_of_B(b)))
{
return-1;
}
if(_MARPA_UNLIKELY(or_node_id<0))
{
MARPA_ERROR(MARPA_ERR_ORID_NEGATIVE);
return failure_indicator;
}
}
/*:1296*/
#line 15787 "./marpa.w"

/*1297:*/
#line 15704 "./marpa.w"

{
if(_MARPA_UNLIKELY(!ORs_of_B(b)))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= OR_of_B_by_ID(b,or_node_id);
}

/*:1297*/
#line 15788 "./marpa.w"

return!IRL_has_Virtual_LHS(IRL_of_OR(or_node));
}

/*:1303*//*1304:*/
#line 15792 "./marpa.w"

int _marpa_b_or_node_first_and(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 15797 "./marpa.w"

/*939:*/
#line 11082 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:939*/
#line 15798 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 15799 "./marpa.w"

/*1296:*/
#line 15692 "./marpa.w"

{
if(_MARPA_UNLIKELY(or_node_id>=OR_Count_of_B(b)))
{
return-1;
}
if(_MARPA_UNLIKELY(or_node_id<0))
{
MARPA_ERROR(MARPA_ERR_ORID_NEGATIVE);
return failure_indicator;
}
}
/*:1296*/
#line 15800 "./marpa.w"

/*1297:*/
#line 15704 "./marpa.w"

{
if(_MARPA_UNLIKELY(!ORs_of_B(b)))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= OR_of_B_by_ID(b,or_node_id);
}

/*:1297*/
#line 15801 "./marpa.w"

return First_ANDID_of_OR(or_node);
}

/*:1304*//*1305:*/
#line 15805 "./marpa.w"

int _marpa_b_or_node_last_and(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 15810 "./marpa.w"

/*939:*/
#line 11082 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:939*/
#line 15811 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 15812 "./marpa.w"

/*1296:*/
#line 15692 "./marpa.w"

{
if(_MARPA_UNLIKELY(or_node_id>=OR_Count_of_B(b)))
{
return-1;
}
if(_MARPA_UNLIKELY(or_node_id<0))
{
MARPA_ERROR(MARPA_ERR_ORID_NEGATIVE);
return failure_indicator;
}
}
/*:1296*/
#line 15813 "./marpa.w"

/*1297:*/
#line 15704 "./marpa.w"

{
if(_MARPA_UNLIKELY(!ORs_of_B(b)))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= OR_of_B_by_ID(b,or_node_id);
}

/*:1297*/
#line 15814 "./marpa.w"

return First_ANDID_of_OR(or_node)
+AND_Count_of_OR(or_node)-1;
}

/*:1305*//*1306:*/
#line 15819 "./marpa.w"

int _marpa_b_or_node_and_count(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 15824 "./marpa.w"

/*939:*/
#line 11082 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:939*/
#line 15825 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 15826 "./marpa.w"

/*1296:*/
#line 15692 "./marpa.w"

{
if(_MARPA_UNLIKELY(or_node_id>=OR_Count_of_B(b)))
{
return-1;
}
if(_MARPA_UNLIKELY(or_node_id<0))
{
MARPA_ERROR(MARPA_ERR_ORID_NEGATIVE);
return failure_indicator;
}
}
/*:1296*/
#line 15827 "./marpa.w"

/*1297:*/
#line 15704 "./marpa.w"

{
if(_MARPA_UNLIKELY(!ORs_of_B(b)))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= OR_of_B_by_ID(b,or_node_id);
}

/*:1297*/
#line 15828 "./marpa.w"

return AND_Count_of_OR(or_node);
}

/*:1306*//*1309:*/
#line 15842 "./marpa.w"

int _marpa_o_or_node_and_node_count(Marpa_Order o,
Marpa_Or_Node_ID or_node_id)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 15846 "./marpa.w"

/*984:*/
#line 11488 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*939:*/
#line 11082 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:939*/
#line 11490 "./marpa.w"


/*:984*/
#line 15847 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 15848 "./marpa.w"

/*1296:*/
#line 15692 "./marpa.w"

{
if(_MARPA_UNLIKELY(or_node_id>=OR_Count_of_B(b)))
{
return-1;
}
if(_MARPA_UNLIKELY(or_node_id<0))
{
MARPA_ERROR(MARPA_ERR_ORID_NEGATIVE);
return failure_indicator;
}
}
/*:1296*/
#line 15849 "./marpa.w"

if(!O_is_Default(o))
{
ANDID**const and_node_orderings= o->t_and_node_orderings;
ANDID*ordering= and_node_orderings[or_node_id];
if(ordering)return ordering[0];
}
{
OR or_node;
/*1297:*/
#line 15704 "./marpa.w"

{
if(_MARPA_UNLIKELY(!ORs_of_B(b)))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= OR_of_B_by_ID(b,or_node_id);
}

/*:1297*/
#line 15858 "./marpa.w"

return AND_Count_of_OR(or_node);
}
}

/*:1309*//*1310:*/
#line 15863 "./marpa.w"

int _marpa_o_or_node_and_node_id_by_ix(Marpa_Order o,
Marpa_Or_Node_ID or_node_id,int ix)
{
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 15867 "./marpa.w"

/*984:*/
#line 11488 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*939:*/
#line 11082 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:939*/
#line 11490 "./marpa.w"


/*:984*/
#line 15868 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 15869 "./marpa.w"

/*1296:*/
#line 15692 "./marpa.w"

{
if(_MARPA_UNLIKELY(or_node_id>=OR_Count_of_B(b)))
{
return-1;
}
if(_MARPA_UNLIKELY(or_node_id<0))
{
MARPA_ERROR(MARPA_ERR_ORID_NEGATIVE);
return failure_indicator;
}
}
/*:1296*/
#line 15870 "./marpa.w"

if(!O_is_Default(o))
{
ANDID**const and_node_orderings= o->t_and_node_orderings;
ANDID*ordering= and_node_orderings[or_node_id];
if(ordering)return ordering[1+ix];
}
{
OR or_node;
/*1297:*/
#line 15704 "./marpa.w"

{
if(_MARPA_UNLIKELY(!ORs_of_B(b)))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= OR_of_B_by_ID(b,or_node_id);
}

/*:1297*/
#line 15879 "./marpa.w"

return First_ANDID_of_OR(or_node)+ix;
}
}

/*:1310*//*1312:*/
#line 15886 "./marpa.w"

int _marpa_b_and_node_count(Marpa_Bocage b)
{
/*939:*/
#line 11082 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:939*/
#line 15889 "./marpa.w"

/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 15890 "./marpa.w"

/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 15891 "./marpa.w"

return AND_Count_of_B(b);
}

/*:1312*//*1314:*/
#line 15917 "./marpa.w"

int _marpa_b_and_node_parent(Marpa_Bocage b,
Marpa_And_Node_ID and_node_id)
{
AND and_node;
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 15922 "./marpa.w"

/*939:*/
#line 11082 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:939*/
#line 15923 "./marpa.w"

/*1313:*/
#line 15895 "./marpa.w"

{
if(and_node_id>=AND_Count_of_B(b))
{
return-1;
}
if(and_node_id<0)
{
MARPA_ERROR(MARPA_ERR_ANDID_NEGATIVE);
return failure_indicator;
}
{
AND and_nodes= ANDs_of_B(b);
if(!and_nodes)
{
MARPA_ERROR(MARPA_ERR_NO_AND_NODES);
return failure_indicator;
}
and_node= and_nodes+and_node_id;
}
}

/*:1313*/
#line 15924 "./marpa.w"

return ID_of_OR(OR_of_AND(and_node));
}

/*:1314*//*1315:*/
#line 15928 "./marpa.w"

int _marpa_b_and_node_predecessor(Marpa_Bocage b,
Marpa_And_Node_ID and_node_id)
{
AND and_node;
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 15933 "./marpa.w"

/*939:*/
#line 11082 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:939*/
#line 15934 "./marpa.w"

/*1313:*/
#line 15895 "./marpa.w"

{
if(and_node_id>=AND_Count_of_B(b))
{
return-1;
}
if(and_node_id<0)
{
MARPA_ERROR(MARPA_ERR_ANDID_NEGATIVE);
return failure_indicator;
}
{
AND and_nodes= ANDs_of_B(b);
if(!and_nodes)
{
MARPA_ERROR(MARPA_ERR_NO_AND_NODES);
return failure_indicator;
}
and_node= and_nodes+and_node_id;
}
}

/*:1313*/
#line 15935 "./marpa.w"

{
const OR predecessor_or= Predecessor_OR_of_AND(and_node);
const ORID predecessor_or_id= 
predecessor_or?ID_of_OR(predecessor_or):-1;
return predecessor_or_id;
}
}

/*:1315*//*1316:*/
#line 15944 "./marpa.w"

int _marpa_b_and_node_cause(Marpa_Bocage b,
Marpa_And_Node_ID and_node_id)
{
AND and_node;
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 15949 "./marpa.w"

/*939:*/
#line 11082 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:939*/
#line 15950 "./marpa.w"

/*1313:*/
#line 15895 "./marpa.w"

{
if(and_node_id>=AND_Count_of_B(b))
{
return-1;
}
if(and_node_id<0)
{
MARPA_ERROR(MARPA_ERR_ANDID_NEGATIVE);
return failure_indicator;
}
{
AND and_nodes= ANDs_of_B(b);
if(!and_nodes)
{
MARPA_ERROR(MARPA_ERR_NO_AND_NODES);
return failure_indicator;
}
and_node= and_nodes+and_node_id;
}
}

/*:1313*/
#line 15951 "./marpa.w"

{
const OR cause_or= Cause_OR_of_AND(and_node);
const ORID cause_or_id= 
OR_is_Token(cause_or)?-1:ID_of_OR(cause_or);
return cause_or_id;
}
}

/*:1316*//*1317:*/
#line 15960 "./marpa.w"

int _marpa_b_and_node_symbol(Marpa_Bocage b,
Marpa_And_Node_ID and_node_id)
{
AND and_node;
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 15965 "./marpa.w"

/*939:*/
#line 11082 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:939*/
#line 15966 "./marpa.w"

/*1313:*/
#line 15895 "./marpa.w"

{
if(and_node_id>=AND_Count_of_B(b))
{
return-1;
}
if(and_node_id<0)
{
MARPA_ERROR(MARPA_ERR_ANDID_NEGATIVE);
return failure_indicator;
}
{
AND and_nodes= ANDs_of_B(b);
if(!and_nodes)
{
MARPA_ERROR(MARPA_ERR_NO_AND_NODES);
return failure_indicator;
}
and_node= and_nodes+and_node_id;
}
}

/*:1313*/
#line 15967 "./marpa.w"

{
const OR cause_or= Cause_OR_of_AND(and_node);
const XSYID symbol_id= 
OR_is_Token(cause_or)?NSYID_of_OR(cause_or):-1;
return symbol_id;
}
}

/*:1317*//*1318:*/
#line 15976 "./marpa.w"

Marpa_Symbol_ID _marpa_b_and_node_token(Marpa_Bocage b,
Marpa_And_Node_ID and_node_id,int*value_p)
{
AND and_node;
OR cause_or;
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 15982 "./marpa.w"

/*939:*/
#line 11082 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:939*/
#line 15983 "./marpa.w"

/*1313:*/
#line 15895 "./marpa.w"

{
if(and_node_id>=AND_Count_of_B(b))
{
return-1;
}
if(and_node_id<0)
{
MARPA_ERROR(MARPA_ERR_ANDID_NEGATIVE);
return failure_indicator;
}
{
AND and_nodes= ANDs_of_B(b);
if(!and_nodes)
{
MARPA_ERROR(MARPA_ERR_NO_AND_NODES);
return failure_indicator;
}
and_node= and_nodes+and_node_id;
}
}

/*:1313*/
#line 15984 "./marpa.w"


cause_or= Cause_OR_of_AND(and_node);
if(!OR_is_Token(cause_or))return-1;
if(value_p)*value_p= Value_of_OR(cause_or);
return NSYID_of_OR(cause_or);
}

/*:1318*//*1319:*/
#line 15999 "./marpa.w"

Marpa_Earley_Set_ID _marpa_b_and_node_middle(Marpa_Bocage b,
Marpa_And_Node_ID and_node_id)
{
AND and_node;
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 16004 "./marpa.w"

/*939:*/
#line 11082 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:939*/
#line 16005 "./marpa.w"

/*1313:*/
#line 15895 "./marpa.w"

{
if(and_node_id>=AND_Count_of_B(b))
{
return-1;
}
if(and_node_id<0)
{
MARPA_ERROR(MARPA_ERR_ANDID_NEGATIVE);
return failure_indicator;
}
{
AND and_nodes= ANDs_of_B(b);
if(!and_nodes)
{
MARPA_ERROR(MARPA_ERR_NO_AND_NODES);
return failure_indicator;
}
and_node= and_nodes+and_node_id;
}
}

/*:1313*/
#line 16006 "./marpa.w"

{
const OR predecessor_or= Predecessor_OR_of_AND(and_node);
if(predecessor_or)
{
return YS_Ord_of_OR(predecessor_or);
}
}
return Origin_Ord_of_OR(OR_of_AND(and_node));
}

/*:1319*//*1322:*/
#line 16039 "./marpa.w"

int _marpa_t_nook_or_node(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 16043 "./marpa.w"

/*1012:*/
#line 11956 "./marpa.w"

ORDER o= O_of_T(t);
/*984:*/
#line 11488 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*939:*/
#line 11082 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:939*/
#line 11490 "./marpa.w"


/*:984*/
#line 11958 "./marpa.w"
;

/*:1012*/
#line 16044 "./marpa.w"

/*1321:*/
#line 16021 "./marpa.w"
{
NOOK base_nook;
/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 16023 "./marpa.w"

if(T_is_Exhausted(t)){
MARPA_ERROR(MARPA_ERR_BOCAGE_ITERATION_EXHAUSTED);
return failure_indicator;
}
if(nook_id<0){
MARPA_ERROR(MARPA_ERR_NOOKID_NEGATIVE);
return failure_indicator;
}
if(nook_id>=Size_of_T(t)){
return-1;
}
base_nook= FSTACK_BASE(t->t_nook_stack,NOOK_Object);
nook= base_nook+nook_id;
}

/*:1321*/
#line 16045 "./marpa.w"

return ID_of_OR(OR_of_NOOK(nook));
}

/*:1322*//*1323:*/
#line 16049 "./marpa.w"

int _marpa_t_nook_choice(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 16053 "./marpa.w"

/*1012:*/
#line 11956 "./marpa.w"

ORDER o= O_of_T(t);
/*984:*/
#line 11488 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*939:*/
#line 11082 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:939*/
#line 11490 "./marpa.w"


/*:984*/
#line 11958 "./marpa.w"
;

/*:1012*/
#line 16054 "./marpa.w"

/*1321:*/
#line 16021 "./marpa.w"
{
NOOK base_nook;
/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 16023 "./marpa.w"

if(T_is_Exhausted(t)){
MARPA_ERROR(MARPA_ERR_BOCAGE_ITERATION_EXHAUSTED);
return failure_indicator;
}
if(nook_id<0){
MARPA_ERROR(MARPA_ERR_NOOKID_NEGATIVE);
return failure_indicator;
}
if(nook_id>=Size_of_T(t)){
return-1;
}
base_nook= FSTACK_BASE(t->t_nook_stack,NOOK_Object);
nook= base_nook+nook_id;
}

/*:1321*/
#line 16055 "./marpa.w"

return Choice_of_NOOK(nook);
}

/*:1323*//*1324:*/
#line 16059 "./marpa.w"

int _marpa_t_nook_parent(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 16063 "./marpa.w"

/*1012:*/
#line 11956 "./marpa.w"

ORDER o= O_of_T(t);
/*984:*/
#line 11488 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*939:*/
#line 11082 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:939*/
#line 11490 "./marpa.w"


/*:984*/
#line 11958 "./marpa.w"
;

/*:1012*/
#line 16064 "./marpa.w"

/*1321:*/
#line 16021 "./marpa.w"
{
NOOK base_nook;
/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 16023 "./marpa.w"

if(T_is_Exhausted(t)){
MARPA_ERROR(MARPA_ERR_BOCAGE_ITERATION_EXHAUSTED);
return failure_indicator;
}
if(nook_id<0){
MARPA_ERROR(MARPA_ERR_NOOKID_NEGATIVE);
return failure_indicator;
}
if(nook_id>=Size_of_T(t)){
return-1;
}
base_nook= FSTACK_BASE(t->t_nook_stack,NOOK_Object);
nook= base_nook+nook_id;
}

/*:1321*/
#line 16065 "./marpa.w"

return Parent_of_NOOK(nook);
}

/*:1324*//*1325:*/
#line 16069 "./marpa.w"

int _marpa_t_nook_cause_is_ready(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 16073 "./marpa.w"

/*1012:*/
#line 11956 "./marpa.w"

ORDER o= O_of_T(t);
/*984:*/
#line 11488 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*939:*/
#line 11082 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:939*/
#line 11490 "./marpa.w"


/*:984*/
#line 11958 "./marpa.w"
;

/*:1012*/
#line 16074 "./marpa.w"

/*1321:*/
#line 16021 "./marpa.w"
{
NOOK base_nook;
/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 16023 "./marpa.w"

if(T_is_Exhausted(t)){
MARPA_ERROR(MARPA_ERR_BOCAGE_ITERATION_EXHAUSTED);
return failure_indicator;
}
if(nook_id<0){
MARPA_ERROR(MARPA_ERR_NOOKID_NEGATIVE);
return failure_indicator;
}
if(nook_id>=Size_of_T(t)){
return-1;
}
base_nook= FSTACK_BASE(t->t_nook_stack,NOOK_Object);
nook= base_nook+nook_id;
}

/*:1321*/
#line 16075 "./marpa.w"

return NOOK_Cause_is_Expanded(nook);
}

/*:1325*//*1326:*/
#line 16079 "./marpa.w"

int _marpa_t_nook_predecessor_is_ready(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 16083 "./marpa.w"

/*1012:*/
#line 11956 "./marpa.w"

ORDER o= O_of_T(t);
/*984:*/
#line 11488 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*939:*/
#line 11082 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:939*/
#line 11490 "./marpa.w"


/*:984*/
#line 11958 "./marpa.w"
;

/*:1012*/
#line 16084 "./marpa.w"

/*1321:*/
#line 16021 "./marpa.w"
{
NOOK base_nook;
/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 16023 "./marpa.w"

if(T_is_Exhausted(t)){
MARPA_ERROR(MARPA_ERR_BOCAGE_ITERATION_EXHAUSTED);
return failure_indicator;
}
if(nook_id<0){
MARPA_ERROR(MARPA_ERR_NOOKID_NEGATIVE);
return failure_indicator;
}
if(nook_id>=Size_of_T(t)){
return-1;
}
base_nook= FSTACK_BASE(t->t_nook_stack,NOOK_Object);
nook= base_nook+nook_id;
}

/*:1321*/
#line 16085 "./marpa.w"

return NOOK_Predecessor_is_Expanded(nook);
}

/*:1326*//*1327:*/
#line 16089 "./marpa.w"

int _marpa_t_nook_is_cause(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 16093 "./marpa.w"

/*1012:*/
#line 11956 "./marpa.w"

ORDER o= O_of_T(t);
/*984:*/
#line 11488 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*939:*/
#line 11082 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:939*/
#line 11490 "./marpa.w"


/*:984*/
#line 11958 "./marpa.w"
;

/*:1012*/
#line 16094 "./marpa.w"

/*1321:*/
#line 16021 "./marpa.w"
{
NOOK base_nook;
/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 16023 "./marpa.w"

if(T_is_Exhausted(t)){
MARPA_ERROR(MARPA_ERR_BOCAGE_ITERATION_EXHAUSTED);
return failure_indicator;
}
if(nook_id<0){
MARPA_ERROR(MARPA_ERR_NOOKID_NEGATIVE);
return failure_indicator;
}
if(nook_id>=Size_of_T(t)){
return-1;
}
base_nook= FSTACK_BASE(t->t_nook_stack,NOOK_Object);
nook= base_nook+nook_id;
}

/*:1321*/
#line 16095 "./marpa.w"

return NOOK_is_Cause(nook);
}

/*:1327*//*1328:*/
#line 16099 "./marpa.w"

int _marpa_t_nook_is_predecessor(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 16103 "./marpa.w"

/*1012:*/
#line 11956 "./marpa.w"

ORDER o= O_of_T(t);
/*984:*/
#line 11488 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*939:*/
#line 11082 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:939*/
#line 11490 "./marpa.w"


/*:984*/
#line 11958 "./marpa.w"
;

/*:1012*/
#line 16104 "./marpa.w"

/*1321:*/
#line 16021 "./marpa.w"
{
NOOK base_nook;
/*1229:*/
#line 14722 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1229*/
#line 16023 "./marpa.w"

if(T_is_Exhausted(t)){
MARPA_ERROR(MARPA_ERR_BOCAGE_ITERATION_EXHAUSTED);
return failure_indicator;
}
if(nook_id<0){
MARPA_ERROR(MARPA_ERR_NOOKID_NEGATIVE);
return failure_indicator;
}
if(nook_id>=Size_of_T(t)){
return-1;
}
base_nook= FSTACK_BASE(t->t_nook_stack,NOOK_Object);
nook= base_nook+nook_id;
}

/*:1321*/
#line 16105 "./marpa.w"

return NOOK_is_Predecessor(nook);
}

/*:1328*//*1331:*/
#line 16160 "./marpa.w"

PRIVATE int look_yim(Marpa_Earley_Item_Look*look,
YS earley_set,Marpa_Earley_Item_ID eim_id)
{
int xrl_position;
int raw_xrl_position;
YIM*earley_items= YIMs_of_YS(earley_set);
YIM earley_item= earley_items[eim_id];
AHM ahm= AHM_of_YIM(earley_item);
XRL xrl= XRL_of_AHM(ahm);
if(xrl){
marpa_eim_look_rule_id(look)= ID_of_XRL(xrl);
xrl_position= XRL_Position_of_AHM(ahm);
raw_xrl_position= Raw_XRL_Position_of_AHM(ahm);
}else{
marpa_eim_look_rule_id(look)= -1;
raw_xrl_position= xrl_position= -1;
}
marpa_eim_look_dot(look)= xrl_position;
marpa_eim_look_origin(look)= Origin_Ord_of_YIM(earley_item);
marpa_eim_look_irl_id(look)= IRLID_of_AHM(ahm);
marpa_eim_look_irl_dot(look)= Position_of_AHM(ahm);
return raw_xrl_position;
}

/*:1331*//*1333:*/
#line 16191 "./marpa.w"

int
_marpa_r_look_yim(Marpa_Recognizer r,Marpa_Earley_Item_Look*look,
Marpa_Earley_Set_ID es_id,Marpa_Earley_Item_ID eim_id)
{
const YS earley_set= YS_of_R_by_Ord(r,es_id);
return look_yim(look,earley_set,eim_id);
}

/*:1333*//*1335:*/
#line 16211 "./marpa.w"

int
_marpa_r_yim_check(Marpa_Recognizer r,
Marpa_Earley_Set_ID es_id,Marpa_Earley_Item_ID eim_id)
{
YS earley_set;
/*560:*/
#line 6076 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:560*/
#line 16217 "./marpa.w"

/*1209:*/
#line 14589 "./marpa.w"
const int failure_indicator= -2;

/*:1209*/
#line 16218 "./marpa.w"


if(es_id<0)
{
MARPA_ERROR(MARPA_ERR_INVALID_LOCATION);
return failure_indicator;
}
if(eim_id<0)
{
MARPA_ERROR(MARPA_ERR_YIM_ID_INVALID);
return failure_indicator;
}
r_update_earley_sets(r);
earley_set= YS_of_R_by_Ord(r,es_id);
if(es_id>=MARPA_DSTACK_LENGTH(r->t_earley_set_stack))
{
MARPA_ERROR(MARPA_ERR_INVALID_LOCATION);
return-1;
}
if(eim_id>=YIM_Count_of_YS(earley_set))
{
return 0;
}
return 1;
}

/*:1335*//*1341:*/
#line 16285 "./marpa.w"

int
_marpa_r_look_pim_eim_first(Marpa_Recognizer r,Marpa_Postdot_Item_Look*look,
Marpa_Earley_Set_ID es_id,Marpa_Symbol_ID nsy_id)
{
int earley_item_ix= -1;
const YS earley_set= YS_of_R_by_Ord(r,es_id);
YIM earley_item= NULL;
PIM pim= First_PIM_of_YS_by_NSYID(earley_set,nsy_id);
if(!pim)return-1;
earley_item= YIM_of_PIM(pim);
if(!earley_item)return-1;
look->t_pim_look_current= pim;
earley_item_ix= Ord_of_YIM(earley_item);
marpa_pim_look_eim(look)= earley_item_ix;
return earley_item_ix;
}

/*:1341*//*1343:*/
#line 16322 "./marpa.w"

int
_marpa_r_look_pim_eim_next(Marpa_Postdot_Item_Look*look)
{
int earley_item_ix= -1;
YIM earley_item= NULL;
PIM pim= Next_PIM_of_PIM(look->t_pim_look_current);
if(!pim)return-1;
earley_item= YIM_of_PIM(pim);
if(!earley_item)return-1;
look->t_pim_look_current= pim;
earley_item_ix= Ord_of_YIM(earley_item);
marpa_pim_look_eim(look)= earley_item_ix;
return earley_item_ix;
}

/*:1343*//*1345:*/
#line 16349 "./marpa.w"

void marpa_debug_handler_set(int(*debug_handler)(const char*,...))
{
marpa__debug_handler= debug_handler;
}

/*:1345*//*1346:*/
#line 16355 "./marpa.w"

int marpa_debug_level_set(int new_level)
{
const int old_level= marpa__debug_level;
marpa__debug_level= new_level;
return old_level;
}


/*:1346*/
#line 16536 "./marpa.w"


/*:1364*/

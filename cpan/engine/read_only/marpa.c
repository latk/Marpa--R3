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

/*1450:*/
#line 17309 "./marpa.w"


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
#define XRL_of_YIM(yim) XRL_of_AHM(AHM_of_YIM(yim) ) 
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
#define YIM_of_TRV(trv) ((trv) ->t_trv_yim) 
#define YS_of_TRV(trv) (YS_of_YIM(YIM_of_TRV(trv) ) 
#define LEO_SRCL_of_TRV(trv) ((trv) ->t_trv_leo_srcl) 
#define TOKEN_SRCL_of_TRV(trv) ((trv) ->t_trv_leo_srcl) 
#define COMPLETION_SRCL_of_TRV(trv) ((trv) ->t_trv_leo_srcl)  \

#define TRV_has_Soft_Error(trv) ((trv) ->t_trv_soft_error) 
#define R_of_TRV(trv) ((trv) ->t_trv_recce) 
#define TRV_is_Trivial(trv) ((trv) ->t_is_trivial) 
#define LIM_of_LTRV(ltrv) ((ltrv) ->t_ltrv_lim) 
#define YS_of_LTRV(ltrv) (YS_of_YIM(LIM_of_LTRV(ltrv) )  \

#define LTRV_has_Soft_Error(ltrv) ((ltrv) ->t_ltrv_soft_error) 
#define R_of_LTRV(ltrv) ((ltrv) ->t_ltrv_recce) 
#define PIM_of_PTRV(ptrv) ((ptrv) ->t_ptrv_pim) 
#define YS_of_PTRV(ptrv) ((ptrv) ->t_ptrv_ys)  \

#define PTRV_has_Soft_Error(ptrv) ((ptrv) ->t_ptrv_soft_error) 
#define R_of_PTRV(ptrv) ((ptrv) ->t_ptrv_recce) 
#define PTRV_is_Trivial(ptrv) ((ptrv) ->t_is_trivial) 
#define ORs_of_B(b) ((b) ->t_or_nodes) 
#define OR_of_B_by_ID(b,id) (ORs_of_B(b) [(id) ]) 
#define OR_Count_of_B(b) ((b) ->t_or_node_count) 
#define OR_Capacity_of_B(b) ((b) ->t_or_node_capacity) 
#define ANDs_of_B(b) ((b) ->t_and_nodes) 
#define AND_Count_of_B(b) ((b) ->t_and_node_count) 
#define Top_ORID_of_B(b) ((b) ->t_top_or_node_id) 
#define G_of_B(b) ((b) ->t_grammar) 
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
#define T_Generation(t) ((t) ->t_generation) 
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
#define V_T_Generation(v) ((v) ->t_generation) 
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

#line 17319 "./marpa.w"

#include "marpa_obs.h"
#include "marpa_avl.h"
/*107:*/
#line 1034 "./marpa.w"

struct s_g_event;
typedef struct s_g_event*GEV;
/*:107*//*143:*/
#line 1263 "./marpa.w"

struct s_xsy;
typedef struct s_xsy*XSY;
typedef const struct s_xsy*XSY_Const;

/*:143*//*454:*/
#line 4862 "./marpa.w"

struct s_ahm;
typedef struct s_ahm*AHM;
typedef Marpa_AHM_ID AHMID;

/*:454*//*531:*/
#line 5800 "./marpa.w"

struct s_g_zwa;
struct s_r_zwa;
/*:531*//*538:*/
#line 5837 "./marpa.w"

struct s_zwp;
/*:538*//*631:*/
#line 6731 "./marpa.w"

struct s_earley_set;
typedef struct s_earley_set*YS;
typedef const struct s_earley_set*YS_Const;
struct s_earley_set_key;
typedef struct s_earley_set_key*YSK;
/*:631*//*653:*/
#line 6947 "./marpa.w"

struct s_earley_item;
typedef struct s_earley_item*YIM;
typedef const struct s_earley_item*YIM_Const;
struct s_earley_item_key;
typedef struct s_earley_item_key*YIK;

/*:653*//*663:*/
#line 7121 "./marpa.w"

struct s_earley_ix;
typedef struct s_earley_ix*YIX;
/*:663*//*666:*/
#line 7157 "./marpa.w"

struct s_leo_item;
typedef struct s_leo_item*LIM;
/*:666*//*702:*/
#line 7554 "./marpa.w"

struct s_alternative;
typedef struct s_alternative*ALT;
typedef const struct s_alternative*ALT_Const;
/*:702*//*859:*/
#line 10032 "./marpa.w"

struct s_ur_node_stack;
struct s_ur_node;
typedef struct s_ur_node_stack*URS;
typedef struct s_ur_node*UR;
typedef const struct s_ur_node*UR_Const;
/*:859*//*880:*/
#line 10294 "./marpa.w"

union u_or_node;
typedef union u_or_node*OR;
/*:880*//*902:*/
#line 10659 "./marpa.w"

struct s_draft_and_node;
typedef struct s_draft_and_node*DAND;
/*:902*//*928:*/
#line 11058 "./marpa.w"

struct s_and_node;
typedef struct s_and_node*AND;
/*:928*//*934:*/
#line 11119 "./marpa.w"

typedef struct marpa_traverser*TRAVERSER;
/*:934*//*978:*/
#line 11635 "./marpa.w"

typedef struct marpa_ltraverser*LTRAVERSER;
/*:978*//*1004:*/
#line 11801 "./marpa.w"

typedef struct marpa_ptraverser*PTRAVERSER;
/*:1004*//*1035:*/
#line 12082 "./marpa.w"

typedef struct marpa_bocage*BOCAGE;
/*:1035*//*1051:*/
#line 12232 "./marpa.w"

struct s_bocage_setup_per_ys;
/*:1051*//*1115:*/
#line 12986 "./marpa.w"

typedef Marpa_Tree TREE;
/*:1115*//*1146:*/
#line 13395 "./marpa.w"

struct s_nook;
typedef struct s_nook*NOOK;
/*:1146*//*1150:*/
#line 13440 "./marpa.w"

typedef struct s_value*VALUE;
/*:1150*//*1263:*/
#line 15009 "./marpa.w"

struct s_dqueue;
typedef struct s_dqueue*DQUEUE;
/*:1263*//*1269:*/
#line 15063 "./marpa.w"

struct s_cil_arena;
/*:1269*//*1289:*/
#line 15398 "./marpa.w"

struct s_per_earley_set_list;
typedef struct s_per_earley_set_list*PSL;
/*:1289*//*1291:*/
#line 15413 "./marpa.w"

struct s_per_earley_set_arena;
typedef struct s_per_earley_set_arena*PSAR;
/*:1291*/
#line 17322 "./marpa.w"

/*49:*/
#line 666 "./marpa.w"

typedef struct marpa_g*GRAMMAR;

/*:49*//*142:*/
#line 1261 "./marpa.w"

typedef Marpa_Symbol_ID XSYID;
/*:142*//*216:*/
#line 1904 "./marpa.w"

struct s_nsy;
typedef struct s_nsy*NSY;
typedef Marpa_NSY_ID NSYID;

/*:216*//*255:*/
#line 2189 "./marpa.w"

struct s_xrl;
typedef struct s_xrl*XRL;
typedef XRL RULE;
typedef Marpa_Rule_ID RULEID;
typedef Marpa_Rule_ID XRLID;

/*:255*//*328:*/
#line 2920 "./marpa.w"

struct s_irl;
typedef struct s_irl*IRL;
typedef Marpa_IRL_ID IRLID;

/*:328*//*471:*/
#line 4978 "./marpa.w"
typedef int SYMI;
/*:471*//*532:*/
#line 5809 "./marpa.w"

typedef Marpa_Assertion_ID ZWAID;
typedef struct s_g_zwa*GZWA;
typedef struct s_r_zwa*ZWA;

/*:532*//*539:*/
#line 5840 "./marpa.w"

typedef struct s_zwp*ZWP;
typedef const struct s_zwp*ZWP_Const;
/*:539*//*552:*/
#line 6036 "./marpa.w"

typedef struct marpa_r*RECCE;
/*:552*//*628:*/
#line 6721 "./marpa.w"
typedef Marpa_Earleme JEARLEME;

/*:628*//*630:*/
#line 6725 "./marpa.w"
typedef Marpa_Earley_Set_ID YSID;
/*:630*//*655:*/
#line 6988 "./marpa.w"

typedef int YIMID;

/*:655*//*673:*/
#line 7203 "./marpa.w"

typedef union _Marpa_PIM_Object PIM_Object;
typedef union _Marpa_PIM_Object*PIM;

/*:673*//*682:*/
#line 7283 "./marpa.w"

struct s_source;
typedef struct s_source*SRC;
typedef const struct s_source*SRC_Const;
/*:682*//*686:*/
#line 7311 "./marpa.w"

typedef struct marpa_source_link_s*SRCL;
/*:686*//*827:*/
#line 9630 "./marpa.w"

typedef struct marpa_progress_item*PROGRESS;
/*:827*//*879:*/
#line 10291 "./marpa.w"

typedef Marpa_Or_Node_ID ORID;

/*:879*//*901:*/
#line 10648 "./marpa.w"

typedef int WHEID;

/*:901*//*927:*/
#line 11054 "./marpa.w"

typedef Marpa_And_Node_ID ANDID;

/*:927*//*1145:*/
#line 13391 "./marpa.w"

typedef Marpa_Nook_ID NOOKID;
/*:1145*//*1200:*/
#line 14179 "./marpa.w"

typedef unsigned int LBW;
typedef LBW*LBV;

/*:1200*//*1208:*/
#line 14271 "./marpa.w"

typedef LBW Bit_Vector_Word;
typedef Bit_Vector_Word*Bit_Vector;
/*:1208*//*1266:*/
#line 15030 "./marpa.w"

typedef int*CIL;

/*:1266*//*1270:*/
#line 15066 "./marpa.w"

typedef struct s_cil_arena*CILAR;
/*:1270*/
#line 17323 "./marpa.w"

/*1268:*/
#line 15055 "./marpa.w"

struct s_cil_arena{
struct marpa_obstack*t_obs;
MARPA_AVL_TREE t_avl;
MARPA_DSTACK_DECLARE(t_buffer);
};
typedef struct s_cil_arena CILAR_Object;

/*:1268*/
#line 17324 "./marpa.w"

/*48:*/
#line 660 "./marpa.w"
struct marpa_g{
/*133:*/
#line 1208 "./marpa.w"

int t_is_ok;

/*:133*/
#line 661 "./marpa.w"

/*59:*/
#line 749 "./marpa.w"

MARPA_DSTACK_DECLARE(t_xsy_stack);
MARPA_DSTACK_DECLARE(t_nsy_stack);

/*:59*//*68:*/
#line 808 "./marpa.w"

MARPA_DSTACK_DECLARE(t_xrl_stack);
MARPA_DSTACK_DECLARE(t_irl_stack);
/*:68*//*103:*/
#line 1003 "./marpa.w"
Bit_Vector t_bv_nsyid_is_terminal;
/*:103*//*105:*/
#line 1012 "./marpa.w"

Bit_Vector t_lbv_xsyid_is_completion_event;
Bit_Vector t_lbv_xsyid_completion_event_starts_active;
Bit_Vector t_lbv_xsyid_is_nulled_event;
Bit_Vector t_lbv_xsyid_nulled_event_starts_active;
Bit_Vector t_lbv_xsyid_is_prediction_event;
Bit_Vector t_lbv_xsyid_prediction_event_starts_active;
/*:105*//*112:*/
#line 1056 "./marpa.w"

MARPA_DSTACK_DECLARE(t_events);
/*:112*//*120:*/
#line 1130 "./marpa.w"

MARPA_AVL_TREE t_xrl_tree;
/*:120*//*124:*/
#line 1160 "./marpa.w"

struct marpa_obstack*t_obs;
struct marpa_obstack*t_xrl_obs;
/*:124*//*127:*/
#line 1177 "./marpa.w"

CILAR_Object t_cilar;
/*:127*//*135:*/
#line 1223 "./marpa.w"

const char*t_error_string;
/*:135*//*459:*/
#line 4888 "./marpa.w"

AHM t_ahms;
/*:459*//*533:*/
#line 5816 "./marpa.w"

MARPA_DSTACK_DECLARE(t_gzwa_stack);
/*:533*//*541:*/
#line 5855 "./marpa.w"

MARPA_AVL_TREE t_zwp_tree;
/*:541*/
#line 662 "./marpa.w"

/*53:*/
#line 696 "./marpa.w"
int t_ref_count;
/*:53*//*78:*/
#line 858 "./marpa.w"
XSYID t_start_xsy_id;
/*:78*//*82:*/
#line 895 "./marpa.w"

IRL t_start_irl;
/*:82*//*85:*/
#line 909 "./marpa.w"

int t_external_size;
/*:85*//*88:*/
#line 923 "./marpa.w"
int t_max_rule_length;
/*:88*//*92:*/
#line 936 "./marpa.w"
Marpa_Rank t_default_rank;
/*:92*//*136:*/
#line 1225 "./marpa.w"

Marpa_Error_Code t_error;
/*:136*//*161:*/
#line 1389 "./marpa.w"
int t_force_valued;
/*:161*//*457:*/
#line 4880 "./marpa.w"

int t_ahm_count;
/*:457*//*472:*/
#line 4980 "./marpa.w"

int t_symbol_instance_count;
/*:472*/
#line 663 "./marpa.w"

/*97:*/
#line 971 "./marpa.w"
BITFIELD t_is_precomputed:1;
/*:97*//*100:*/
#line 983 "./marpa.w"
BITFIELD t_has_cycle:1;
/*:100*/
#line 664 "./marpa.w"

};
/*:48*//*111:*/
#line 1049 "./marpa.w"

struct s_g_event{
int t_type;
int t_value;
};
typedef struct s_g_event GEV_Object;
/*:111*//*144:*/
#line 1268 "./marpa.w"

struct s_xsy{
/*202:*/
#line 1804 "./marpa.w"

CIL t_nulled_event_xsyids;
/*:202*//*205:*/
#line 1831 "./marpa.w"
NSY t_nsy_equivalent;
/*:205*//*209:*/
#line 1863 "./marpa.w"
NSY t_nulling_nsy;
/*:209*/
#line 1270 "./marpa.w"

/*145:*/
#line 1277 "./marpa.w"
XSYID t_symbol_id;

/*:145*//*150:*/
#line 1310 "./marpa.w"

Marpa_Rank t_rank;
/*:150*/
#line 1271 "./marpa.w"

/*154:*/
#line 1357 "./marpa.w"
BITFIELD t_is_lhs:1;
/*:154*//*156:*/
#line 1364 "./marpa.w"
BITFIELD t_is_sequence_lhs:1;
/*:156*//*158:*/
#line 1378 "./marpa.w"

BITFIELD t_is_valued:1;
BITFIELD t_is_valued_locked:1;
/*:158*//*166:*/
#line 1448 "./marpa.w"
BITFIELD t_is_accessible:1;
/*:166*//*169:*/
#line 1469 "./marpa.w"
BITFIELD t_is_counted:1;
/*:169*//*172:*/
#line 1485 "./marpa.w"
BITFIELD t_is_nulling:1;
/*:172*//*175:*/
#line 1502 "./marpa.w"
BITFIELD t_is_nullable:1;
/*:175*//*178:*/
#line 1523 "./marpa.w"

BITFIELD t_is_terminal:1;
BITFIELD t_is_locked_terminal:1;
/*:178*//*183:*/
#line 1570 "./marpa.w"
BITFIELD t_is_productive:1;
/*:183*//*186:*/
#line 1591 "./marpa.w"

BITFIELD t_is_completion_event:1;
BITFIELD t_completion_event_starts_active:1;
/*:186*//*191:*/
#line 1661 "./marpa.w"

BITFIELD t_is_nulled_event:1;
BITFIELD t_nulled_event_starts_active:1;
/*:191*//*196:*/
#line 1734 "./marpa.w"

BITFIELD t_is_prediction_event:1;
BITFIELD t_prediction_event_starts_active:1;
/*:196*/
#line 1272 "./marpa.w"

};

/*:144*//*217:*/
#line 1919 "./marpa.w"

struct s_unvalued_token_or_node{
int t_or_node_type;
NSYID t_nsyid;
};

struct s_nsy{
/*236:*/
#line 2056 "./marpa.w"
CIL t_lhs_cil;
/*:236*//*241:*/
#line 2087 "./marpa.w"
XSY t_source_xsy;
/*:241*//*245:*/
#line 2110 "./marpa.w"

XRL t_lhs_xrl;
int t_xrl_offset;
/*:245*/
#line 1926 "./marpa.w"

/*250:*/
#line 2163 "./marpa.w"
Marpa_Rank t_rank;
/*:250*/
#line 1927 "./marpa.w"

/*227:*/
#line 2011 "./marpa.w"
BITFIELD t_is_start:1;
/*:227*//*230:*/
#line 2025 "./marpa.w"
BITFIELD t_is_lhs:1;
/*:230*//*233:*/
#line 2039 "./marpa.w"
BITFIELD t_nsy_is_nulling:1;
/*:233*//*238:*/
#line 2064 "./marpa.w"
BITFIELD t_is_semantic:1;
/*:238*/
#line 1928 "./marpa.w"

struct s_unvalued_token_or_node t_nulling_or_node;
struct s_unvalued_token_or_node t_unvalued_or_node;
};
/*:217*//*254:*/
#line 2180 "./marpa.w"

struct s_xrl{
/*267:*/
#line 2483 "./marpa.w"
int t_rhs_length;
/*:267*//*275:*/
#line 2548 "./marpa.w"
Marpa_Rule_ID t_id;

/*:275*//*276:*/
#line 2551 "./marpa.w"

Marpa_Rank t_rank;
/*:276*/
#line 2182 "./marpa.w"

/*280:*/
#line 2600 "./marpa.w"

BITFIELD t_null_ranks_high:1;
/*:280*//*284:*/
#line 2641 "./marpa.w"
BITFIELD t_is_bnf:1;
/*:284*//*286:*/
#line 2647 "./marpa.w"
BITFIELD t_is_sequence:1;
/*:286*//*288:*/
#line 2661 "./marpa.w"
int t_minimum;
/*:288*//*291:*/
#line 2687 "./marpa.w"
XSYID t_separator_id;
/*:291*//*296:*/
#line 2724 "./marpa.w"
BITFIELD t_is_discard:1;
/*:296*//*300:*/
#line 2764 "./marpa.w"
BITFIELD t_is_proper_separation:1;
/*:300*//*304:*/
#line 2785 "./marpa.w"
BITFIELD t_is_loop:1;
/*:304*//*307:*/
#line 2803 "./marpa.w"
BITFIELD t_is_nulling:1;
/*:307*//*310:*/
#line 2822 "./marpa.w"
BITFIELD t_is_nullable:1;
/*:310*//*314:*/
#line 2841 "./marpa.w"
BITFIELD t_is_accessible:1;
/*:314*//*317:*/
#line 2860 "./marpa.w"
BITFIELD t_is_productive:1;
/*:317*//*320:*/
#line 2878 "./marpa.w"
BITFIELD t_is_used:1;
/*:320*/
#line 2183 "./marpa.w"

/*268:*/
#line 2486 "./marpa.w"
Marpa_Symbol_ID t_symbols[1];


/*:268*/
#line 2184 "./marpa.w"

};
/*:254*//*326:*/
#line 2909 "./marpa.w"

struct s_irl{
/*359:*/
#line 3122 "./marpa.w"
XRL t_source_xrl;
/*:359*//*365:*/
#line 3171 "./marpa.w"
AHM t_first_ahm;
/*:365*/
#line 2911 "./marpa.w"

/*329:*/
#line 2931 "./marpa.w"
IRLID t_irl_id;

/*:329*//*336:*/
#line 2968 "./marpa.w"
int t_length;
/*:336*//*338:*/
#line 2983 "./marpa.w"
int t_ahm_count;

/*:338*//*350:*/
#line 3062 "./marpa.w"
int t_real_symbol_count;
/*:350*//*353:*/
#line 3080 "./marpa.w"
int t_virtual_start;
/*:353*//*356:*/
#line 3100 "./marpa.w"
int t_virtual_end;
/*:356*//*362:*/
#line 3149 "./marpa.w"
Marpa_Rank t_rank;
/*:362*//*473:*/
#line 4986 "./marpa.w"

int t_symbol_instance_base;
int t_last_proper_symi;
/*:473*/
#line 2912 "./marpa.w"

/*341:*/
#line 3016 "./marpa.w"
BITFIELD t_is_virtual_lhs:1;
/*:341*//*344:*/
#line 3032 "./marpa.w"
BITFIELD t_is_virtual_rhs:1;
/*:344*//*347:*/
#line 3051 "./marpa.w"
BITFIELD t_is_right_recursive:1;
/*:347*//*409:*/
#line 4071 "./marpa.w"
BITFIELD t_is_chaf:1;
/*:409*/
#line 2913 "./marpa.w"

/*331:*/
#line 2936 "./marpa.w"

NSYID t_nsyid_array[1];

/*:331*/
#line 2914 "./marpa.w"

};
typedef struct s_irl IRL_Object;

/*:326*//*378:*/
#line 3359 "./marpa.w"

struct sym_rule_pair
{
XSYID t_symid;
RULEID t_ruleid;
};

/*:378*//*453:*/
#line 4856 "./marpa.w"

struct s_ahm{
/*463:*/
#line 4908 "./marpa.w"

IRL t_irl;

/*:463*//*476:*/
#line 5001 "./marpa.w"

CIL t_predicted_irl_cil;
CIL t_lhs_cil;

/*:476*//*477:*/
#line 5009 "./marpa.w"

CIL t_zwa_cil;

/*:477*//*499:*/
#line 5253 "./marpa.w"

CIL t_completion_xsyids;
CIL t_nulled_xsyids;
CIL t_prediction_xsyids;

/*:499*//*503:*/
#line 5283 "./marpa.w"

XRL t_xrl;
/*:503*//*506:*/
#line 5312 "./marpa.w"

CIL t_event_ahmids;
/*:506*/
#line 4858 "./marpa.w"

/*464:*/
#line 4918 "./marpa.w"
NSYID t_postdot_nsyid;

/*:464*//*465:*/
#line 4927 "./marpa.w"

int t_leading_nulls;

/*:465*//*466:*/
#line 4940 "./marpa.w"

int t_position;

/*:466*//*468:*/
#line 4956 "./marpa.w"

int t_quasi_position;

/*:468*//*470:*/
#line 4976 "./marpa.w"

int t_symbol_instance;
/*:470*//*504:*/
#line 5291 "./marpa.w"

int t_xrl_position;

/*:504*//*507:*/
#line 5316 "./marpa.w"

int t_event_group_size;
/*:507*/
#line 4859 "./marpa.w"

/*478:*/
#line 5018 "./marpa.w"

BITFIELD t_predicts_zwa:1;

/*:478*//*502:*/
#line 5274 "./marpa.w"

BITFIELD t_was_predicted:1;
BITFIELD t_is_initial:1;

/*:502*/
#line 4860 "./marpa.w"

};
/*:453*//*537:*/
#line 5830 "./marpa.w"

struct s_g_zwa{
ZWAID t_id;
BITFIELD t_default_value:1;
};
typedef struct s_g_zwa GZWA_Object;

/*:537*//*540:*/
#line 5847 "./marpa.w"

struct s_zwp{
XRLID t_xrl_id;
int t_dot;
ZWAID t_zwaid;
};
typedef struct s_zwp ZWP_Object;

/*:540*//*621:*/
#line 6667 "./marpa.w"

struct s_r_zwa{
ZWAID t_id;
YSID t_memoized_ysid;
BITFIELD t_default_value:1;
BITFIELD t_memoized_value:1;
};
typedef struct s_r_zwa ZWA_Object;

/*:621*//*632:*/
#line 6737 "./marpa.w"

struct s_earley_set_key{
JEARLEME t_earleme;
};
typedef struct s_earley_set_key YSK_Object;
/*:632*//*633:*/
#line 6742 "./marpa.w"

struct s_earley_set{
YSK_Object t_key;
PIM*t_postdot_ary;
YS t_next_earley_set;
/*635:*/
#line 6758 "./marpa.w"

YIM*t_earley_items;

/*:635*//*1300:*/
#line 15501 "./marpa.w"

PSL t_dot_psl;
/*:1300*/
#line 6747 "./marpa.w"

int t_postdot_sym_count;
/*634:*/
#line 6755 "./marpa.w"

int t_yim_count;
/*:634*//*636:*/
#line 6769 "./marpa.w"

int t_ordinal;
/*:636*//*640:*/
#line 6787 "./marpa.w"

int t_value;
void*t_pvalue;
/*:640*/
#line 6749 "./marpa.w"

};
typedef struct s_earley_set YS_Object;

/*:633*//*664:*/
#line 7124 "./marpa.w"

struct s_earley_ix{
PIM t_next;
NSYID t_postdot_nsyid;
YIM t_earley_item;
};
typedef struct s_earley_ix YIX_Object;

/*:664*//*667:*/
#line 7160 "./marpa.w"

struct s_leo_item{
YIX_Object t_earley_ix;
/*668:*/
#line 7176 "./marpa.w"

CIL t_cil;

/*:668*/
#line 7163 "./marpa.w"

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

/*:667*//*703:*/
#line 7565 "./marpa.w"

struct s_alternative{
YS t_start_earley_set;
JEARLEME t_end_earleme;
NSYID t_nsyid;
int t_value;
BITFIELD t_is_valued:1;
};
typedef struct s_alternative ALT_Object;

/*:703*//*860:*/
#line 10048 "./marpa.w"

struct s_ur_node_stack{
struct marpa_obstack*t_obs;
UR t_base;
UR t_top;
};

/*:860*//*861:*/
#line 10055 "./marpa.w"

struct s_ur_node{
UR t_prev;
UR t_next;
YIM t_earley_item;
};
typedef struct s_ur_node UR_Object;

/*:861*//*884:*/
#line 10337 "./marpa.w"

struct s_draft_or_node
{
/*883:*/
#line 10330 "./marpa.w"

/*882:*/
#line 10327 "./marpa.w"

int t_position;

/*:882*/
#line 10331 "./marpa.w"

int t_end_set_ordinal;
int t_start_set_ordinal;
ORID t_id;
IRL t_irl;

/*:883*/
#line 10340 "./marpa.w"

DAND t_draft_and_node;
};

/*:884*//*885:*/
#line 10344 "./marpa.w"

struct s_final_or_node
{
/*883:*/
#line 10330 "./marpa.w"

/*882:*/
#line 10327 "./marpa.w"

int t_position;

/*:882*/
#line 10331 "./marpa.w"

int t_end_set_ordinal;
int t_start_set_ordinal;
ORID t_id;
IRL t_irl;

/*:883*/
#line 10347 "./marpa.w"

int t_first_and_node_id;
int t_and_node_count;
};

/*:885*//*886:*/
#line 10352 "./marpa.w"

struct s_valued_token_or_node
{
/*882:*/
#line 10327 "./marpa.w"

int t_position;

/*:882*/
#line 10355 "./marpa.w"

NSYID t_nsyid;
int t_value;
};

/*:886*//*887:*/
#line 10363 "./marpa.w"

union u_or_node{
struct s_draft_or_node t_draft;
struct s_final_or_node t_final;
struct s_valued_token_or_node t_token;
};
typedef union u_or_node OR_Object;

/*:887*//*903:*/
#line 10666 "./marpa.w"

struct s_draft_and_node{
DAND t_next;
OR t_predecessor;
OR t_cause;
};
typedef struct s_draft_and_node DAND_Object;

/*:903*//*929:*/
#line 11065 "./marpa.w"

struct s_and_node{
OR t_current;
OR t_predecessor;
OR t_cause;
};
typedef struct s_and_node AND_Object;

/*:929*//*1052:*/
#line 12238 "./marpa.w"

struct s_bocage_setup_per_ys{
OR*t_or_node_by_item;
PSL t_or_psl;
PSL t_and_psl;
};
/*:1052*//*1078:*/
#line 12459 "./marpa.w"

struct marpa_order{
struct marpa_obstack*t_ordering_obs;
ANDID**t_and_node_orderings;
/*1081:*/
#line 12477 "./marpa.w"

BOCAGE t_bocage;

/*:1081*/
#line 12463 "./marpa.w"

/*1084:*/
#line 12497 "./marpa.w"
int t_ref_count;
/*:1084*//*1091:*/
#line 12553 "./marpa.w"
int t_ambiguity_metric;

/*:1091*//*1097:*/
#line 12665 "./marpa.w"
int t_high_rank_count;
/*:1097*/
#line 12464 "./marpa.w"

/*1095:*/
#line 12647 "./marpa.w"

BITFIELD t_is_nulling:1;
/*:1095*/
#line 12465 "./marpa.w"

BITFIELD t_is_frozen:1;
};
/*:1078*//*1116:*/
#line 12998 "./marpa.w"

/*1147:*/
#line 13406 "./marpa.w"

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

/*:1147*/
#line 12999 "./marpa.w"

/*1152:*/
#line 13454 "./marpa.w"

struct s_value{
struct marpa_value public;
Marpa_Tree t_tree;
/*1156:*/
#line 13532 "./marpa.w"

struct marpa_obstack*t_obs;
/*:1156*//*1161:*/
#line 13579 "./marpa.w"

MARPA_DSTACK_DECLARE(t_virtual_stack);
/*:1161*//*1186:*/
#line 13752 "./marpa.w"

LBV t_xsy_is_valued;
LBV t_xrl_is_valued;
LBV t_valued_locked;

/*:1186*/
#line 13458 "./marpa.w"

/*1166:*/
#line 13627 "./marpa.w"

int t_ref_count;
/*:1166*//*1173:*/
#line 13685 "./marpa.w"

unsigned int t_generation;

/*:1173*//*1181:*/
#line 13727 "./marpa.w"

NOOKID t_nook;
/*:1181*/
#line 13459 "./marpa.w"

int t_token_type;
int t_next_value_type;
/*1176:*/
#line 13698 "./marpa.w"

BITFIELD t_is_nulling:1;
/*:1176*//*1178:*/
#line 13705 "./marpa.w"

BITFIELD t_trace:1;
/*:1178*/
#line 13462 "./marpa.w"

};

/*:1152*/
#line 13000 "./marpa.w"

struct marpa_tree{
FSTACK_DECLARE(t_nook_stack,NOOK_Object)
FSTACK_DECLARE(t_nook_worklist,int)
Bit_Vector t_or_node_in_use;
Marpa_Order t_order;
/*1122:*/
#line 13071 "./marpa.w"

int t_ref_count;
/*:1122*//*1127:*/
#line 13124 "./marpa.w"
unsigned int t_generation;
/*:1127*/
#line 13006 "./marpa.w"

/*1131:*/
#line 13184 "./marpa.w"

BITFIELD t_is_exhausted:1;
/*:1131*//*1134:*/
#line 13192 "./marpa.w"

BITFIELD t_is_nulling:1;

/*:1134*/
#line 13007 "./marpa.w"

int t_parse_count;
};

/*:1116*//*1243:*/
#line 14793 "./marpa.w"

struct s_bit_matrix{
int t_row_count;
Bit_Vector_Word t_row_data[1];
};
typedef struct s_bit_matrix*Bit_Matrix;
typedef struct s_bit_matrix Bit_Matrix_Object;

/*:1243*//*1264:*/
#line 15012 "./marpa.w"

struct s_dqueue{int t_current;struct marpa_dstack_s t_stack;};

/*:1264*//*1290:*/
#line 15404 "./marpa.w"

struct s_per_earley_set_list{
PSL t_prev;
PSL t_next;
PSL*t_owner;
void*t_data[1];
};
typedef struct s_per_earley_set_list PSL_Object;
/*:1290*//*1292:*/
#line 15429 "./marpa.w"

struct s_per_earley_set_arena{
int t_psl_length;
PSL t_first_psl;
PSL t_first_free_psl;
};
typedef struct s_per_earley_set_arena PSAR_Object;
/*:1292*/
#line 17325 "./marpa.w"

/*672:*/
#line 7198 "./marpa.w"

union _Marpa_PIM_Object{
LIM_Object t_leo;
YIX_Object t_earley;
};
/*:672*/
#line 17326 "./marpa.w"


/*:1450*//*1451:*/
#line 17331 "./marpa.w"

/*40:*/
#line 570 "./marpa.w"

const int marpa_major_version= MARPA_LIB_MAJOR_VERSION;
const int marpa_minor_version= MARPA_LIB_MINOR_VERSION;
const int marpa_micro_version= MARPA_LIB_MICRO_VERSION;

/*:40*//*833:*/
#line 9656 "./marpa.w"

static const struct marpa_progress_item progress_report_not_ready= {-2,-2,-2};

/*:833*//*888:*/
#line 10371 "./marpa.w"

static const int dummy_or_node_type= DUMMY_OR_NODE;
static const OR dummy_or_node= (OR)&dummy_or_node_type;

/*:888*//*1209:*/
#line 14278 "./marpa.w"

static const unsigned int bv_wordbits= lbv_wordbits;
static const unsigned int bv_modmask= lbv_wordbits-1u;
static const unsigned int bv_hiddenwords= 3;
static const unsigned int bv_lsb= lbv_lsb;
static const unsigned int bv_msb= lbv_msb;

/*:1209*/
#line 17332 "./marpa.w"


/*:1451*//*1452:*/
#line 17334 "./marpa.w"

/*553:*/
#line 6038 "./marpa.w"

struct marpa_r{
/*561:*/
#line 6118 "./marpa.w"

GRAMMAR t_grammar;
/*:561*//*568:*/
#line 6145 "./marpa.w"

YS t_first_earley_set;
YS t_latest_earley_set;
JEARLEME t_current_earleme;
/*:568*//*580:*/
#line 6228 "./marpa.w"

Bit_Vector t_lbv_xsyid_completion_event_is_active;
Bit_Vector t_lbv_xsyid_nulled_event_is_active;
Bit_Vector t_lbv_xsyid_prediction_event_is_active;
/*:580*//*583:*/
#line 6253 "./marpa.w"
Bit_Vector t_bv_nsyid_is_expected;
/*:583*//*587:*/
#line 6330 "./marpa.w"
LBV t_nsy_expected_is_event;
/*:587*//*609:*/
#line 6604 "./marpa.w"

Bit_Vector t_bv_irl_seen;
MARPA_DSTACK_DECLARE(t_irl_cil_stack);
/*:609*//*618:*/
#line 6658 "./marpa.w"
struct marpa_obstack*t_obs;
/*:618*//*622:*/
#line 6679 "./marpa.w"

ZWA t_zwas;
/*:622*//*704:*/
#line 7575 "./marpa.w"

MARPA_DSTACK_DECLARE(t_alternatives);
/*:704*//*721:*/
#line 7862 "./marpa.w"

LBV t_valued_terminal;
LBV t_unvalued_terminal;
LBV t_valued;
LBV t_unvalued;
LBV t_valued_locked;

/*:721*//*729:*/
#line 8075 "./marpa.w"
MARPA_DSTACK_DECLARE(t_yim_work_stack);
/*:729*//*733:*/
#line 8090 "./marpa.w"
MARPA_DSTACK_DECLARE(t_completion_stack);
/*:733*//*737:*/
#line 8101 "./marpa.w"
MARPA_DSTACK_DECLARE(t_earley_set_stack);
/*:737*//*774:*/
#line 8731 "./marpa.w"

Bit_Vector t_bv_lim_symbols;
Bit_Vector t_bv_pim_symbols;
void**t_pim_workarea;
/*:774*//*793:*/
#line 9015 "./marpa.w"

void**t_lim_chain;
/*:793*//*828:*/
#line 9632 "./marpa.w"

const struct marpa_progress_item*t_current_report_item;
MARPA_AVL_TRAV t_progress_report_traverser;
/*:828*//*862:*/
#line 10064 "./marpa.w"

struct s_ur_node_stack t_ur_node_stack;
/*:862*//*1293:*/
#line 15437 "./marpa.w"

PSAR_Object t_dot_psar_object;
/*:1293*//*1344:*/
#line 15905 "./marpa.w"

struct s_earley_set*t_trace_earley_set;
/*:1344*//*1351:*/
#line 15981 "./marpa.w"

YIM t_trace_earley_item;
/*:1351*//*1365:*/
#line 16180 "./marpa.w"

PIM*t_trace_pim_nsy_p;
PIM t_trace_postdot_item;
/*:1365*//*1372:*/
#line 16329 "./marpa.w"

SRCL t_trace_source_link;
/*:1372*/
#line 6040 "./marpa.w"

/*556:*/
#line 6068 "./marpa.w"
int t_ref_count;
/*:556*//*572:*/
#line 6182 "./marpa.w"
int t_earley_item_warning_threshold;
/*:572*//*576:*/
#line 6211 "./marpa.w"
JEARLEME t_furthest_earleme;
/*:576*//*581:*/
#line 6232 "./marpa.w"

int t_active_event_count;
/*:581*//*616:*/
#line 6651 "./marpa.w"
YSID t_first_inconsistent_ys;
/*:616*//*637:*/
#line 6773 "./marpa.w"

int t_earley_set_count;
/*:637*/
#line 6041 "./marpa.w"

/*565:*/
#line 6136 "./marpa.w"

BITFIELD t_input_phase:2;
/*:565*//*605:*/
#line 6571 "./marpa.w"

BITFIELD t_use_leo_flag:1;
BITFIELD t_is_using_leo:1;
/*:605*//*612:*/
#line 6623 "./marpa.w"
BITFIELD t_is_exhausted:1;
/*:612*//*1373:*/
#line 16331 "./marpa.w"

BITFIELD t_trace_source_type:3;
/*:1373*/
#line 6042 "./marpa.w"

};

/*:553*/
#line 17335 "./marpa.w"

/*683:*/
#line 7287 "./marpa.w"

struct s_token_source{
NSYID t_nsyid;
int t_value;
};

/*:683*//*684:*/
#line 7296 "./marpa.w"

struct s_source{
void*t_predecessor;
union{
void*t_completion;
struct s_token_source t_token;
}t_cause;
BITFIELD t_is_rejected:1;
BITFIELD t_is_active:1;

};

/*:684*//*687:*/
#line 7313 "./marpa.w"

struct marpa_source_link_s{
SRCL t_next;
struct s_source t_source;
};
typedef struct marpa_source_link_s SRCL_Object;

/*:687*//*688:*/
#line 7320 "./marpa.w"

struct s_ambiguous_source{
SRCL t_leo;
SRCL t_token;
SRCL t_completion;
};

/*:688*//*689:*/
#line 7327 "./marpa.w"

union u_source_container{
struct s_ambiguous_source t_ambiguous;
struct marpa_source_link_s t_unique;
};

/*:689*/
#line 17336 "./marpa.w"

/*654:*/
#line 6967 "./marpa.w"

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

/*:654*/
#line 17337 "./marpa.w"

/*935:*/
#line 11122 "./marpa.w"

struct marpa_traverser{
/*936:*/
#line 11137 "./marpa.w"

YIM t_trv_yim;
SRCL t_trv_leo_srcl;
SRCL t_trv_token_srcl;
SRCL t_trv_completion_srcl;

/*:936*//*942:*/
#line 11162 "./marpa.w"

RECCE t_trv_recce;
/*:942*/
#line 11124 "./marpa.w"

/*959:*/
#line 11467 "./marpa.w"

int t_ref_count;
/*:959*/
#line 11125 "./marpa.w"

/*938:*/
#line 11150 "./marpa.w"

int t_trv_soft_error;
/*:938*//*966:*/
#line 11523 "./marpa.w"

BITFIELD t_is_trivial:1;
/*:966*/
#line 11126 "./marpa.w"

};
typedef struct marpa_traverser TRAVERSER_Object;

/*:935*/
#line 17338 "./marpa.w"

/*979:*/
#line 11638 "./marpa.w"

struct marpa_ltraverser{
/*980:*/
#line 11650 "./marpa.w"

LIM t_ltrv_lim;

/*:980*//*986:*/
#line 11672 "./marpa.w"

RECCE t_ltrv_recce;
/*:986*/
#line 11640 "./marpa.w"

/*996:*/
#line 11741 "./marpa.w"

int t_ref_count;
/*:996*/
#line 11641 "./marpa.w"

/*982:*/
#line 11660 "./marpa.w"

int t_ltrv_soft_error;
/*:982*/
#line 11642 "./marpa.w"

};
typedef struct marpa_ltraverser LTRAVERSER_Object;

/*:979*/
#line 17339 "./marpa.w"

/*1005:*/
#line 11804 "./marpa.w"

struct marpa_ptraverser{
/*1006:*/
#line 11816 "./marpa.w"

PIM t_ptrv_pim;
YS t_ptrv_ys;

/*:1006*//*1012:*/
#line 11839 "./marpa.w"

RECCE t_ptrv_recce;
/*:1012*/
#line 11806 "./marpa.w"

/*1023:*/
#line 11995 "./marpa.w"

int t_ref_count;
/*:1023*/
#line 11807 "./marpa.w"

/*1008:*/
#line 11827 "./marpa.w"

int t_ptrv_soft_error;
/*:1008*//*1030:*/
#line 12051 "./marpa.w"

BITFIELD t_is_trivial:1;
/*:1030*/
#line 11808 "./marpa.w"

};
typedef struct marpa_ptraverser PTRAVERSER_Object;

/*:1005*/
#line 17340 "./marpa.w"

/*1036:*/
#line 12084 "./marpa.w"

struct marpa_bocage{
/*1037:*/
#line 12098 "./marpa.w"

OR*t_or_nodes;
AND t_and_nodes;
/*:1037*//*1041:*/
#line 12127 "./marpa.w"

GRAMMAR t_grammar;

/*:1041*//*1045:*/
#line 12144 "./marpa.w"

struct marpa_obstack*t_obs;
/*:1045*//*1048:*/
#line 12212 "./marpa.w"

LBV t_valued_bv;
LBV t_valued_locked_bv;

/*:1048*/
#line 12086 "./marpa.w"

/*1038:*/
#line 12101 "./marpa.w"

int t_or_node_capacity;
int t_or_node_count;
int t_and_node_count;
ORID t_top_or_node_id;

/*:1038*//*1062:*/
#line 12360 "./marpa.w"
int t_ambiguity_metric;
/*:1062*//*1066:*/
#line 12374 "./marpa.w"
int t_ref_count;
/*:1066*/
#line 12087 "./marpa.w"

/*1073:*/
#line 12431 "./marpa.w"

BITFIELD t_is_nulling:1;
/*:1073*/
#line 12088 "./marpa.w"

};

/*:1036*/
#line 17341 "./marpa.w"


/*:1452*/

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
memoize_xrl_data_for_AHM(AHM current_item, IRL irl);
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
progress_report_items_insert(MARPA_AVL_TREE report_tree,
  AHM report_ahm,
    YIM origin_yim);
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
static inline Marpa_Traverser
trv_new(RECCE r, YIM yim);
static inline void
traverser_unref (TRAVERSER trv);
static inline TRAVERSER
traverser_ref (TRAVERSER trv);
static inline void
traverser_free (TRAVERSER trv);
static inline Marpa_LTraverser
ltrv_new(RECCE r, LIM lim);
static inline void
ltraverser_unref (LTRAVERSER ltrv);
static inline LTRAVERSER
ltraverser_ref (LTRAVERSER ltrv);
static inline void
ltraverser_free (LTRAVERSER ltrv);
static inline Marpa_PTraverser
ptrv_new(RECCE r, YS ys, NSYID nsyid);
static inline void
ptraverser_unref (PTRAVERSER ptrv);
static inline PTRAVERSER
ptraverser_ref (PTRAVERSER ptrv);
static inline void
ptraverser_free (PTRAVERSER ptrv);
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

/*1453:*/
#line 17343 "./marpa.w"

/*1342:*/
#line 15881 "./marpa.w"

extern void*(*const marpa__out_of_memory)(void);

/*:1342*//*1433:*/
#line 17155 "./marpa.w"

extern int marpa__default_debug_handler(const char*format,...);
extern int(*marpa__debug_handler)(const char*,...);
extern int marpa__debug_level;

/*:1433*/
#line 17344 "./marpa.w"

#if MARPA_DEBUG
/*1438:*/
#line 17187 "./marpa.w"

static const char*yim_tag_safe(
char*buffer,GRAMMAR g,YIM yim)UNUSED;
static const char*yim_tag(GRAMMAR g,YIM yim)UNUSED;
/*:1438*//*1440:*/
#line 17213 "./marpa.w"

static char*lim_tag_safe(char*buffer,LIM lim)UNUSED;
static char*lim_tag(LIM lim)UNUSED;
/*:1440*//*1442:*/
#line 17239 "./marpa.w"

static const char*or_tag_safe(char*buffer,OR or)UNUSED;
static const char*or_tag(OR or)UNUSED;
/*:1442*//*1444:*/
#line 17271 "./marpa.w"

static const char*ahm_tag_safe(char*buffer,AHM ahm)UNUSED;
static const char*ahm_tag(AHM ahm)UNUSED;
/*:1444*/
#line 17346 "./marpa.w"

/*1439:*/
#line 17192 "./marpa.w"

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

/*:1439*//*1441:*/
#line 17218 "./marpa.w"

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

/*:1441*//*1443:*/
#line 17243 "./marpa.w"

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

/*:1443*//*1445:*/
#line 17274 "./marpa.w"

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

/*:1445*/
#line 17347 "./marpa.w"

#endif
/*1437:*/
#line 17179 "./marpa.w"

int(*marpa__debug_handler)(const char*,...)= 
marpa__default_debug_handler;
int marpa__debug_level= 0;

/*:1437*/
#line 17349 "./marpa.w"

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
#line 622 "./marpa.w"

int marpa_c_init(Marpa_Config*config)
{
MARPA_OFF_DEBUG3("Debugging at level %ld is on: %s\n",
marpa__debug_level,STRLOC);
config->t_is_ok= I_AM_OK;
config->t_error= MARPA_ERR_NONE;
config->t_error_string= NULL;
return 0;
}

/*:45*//*46:*/
#line 633 "./marpa.w"

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
#line 674 "./marpa.w"

Marpa_Grammar marpa_g_new(Marpa_Config*configuration)
{
GRAMMAR g;
MARPA_OFF_DEBUG3("Debugging at level %ld is on: %s\n",
marpa__debug_level,STRLOC);
if(configuration&&configuration->t_is_ok!=I_AM_OK){
configuration->t_error= MARPA_ERR_I_AM_NOT_OK;
return NULL;
}
g= my_malloc(sizeof(struct marpa_g));


g->t_is_ok= 0;
/*54:*/
#line 697 "./marpa.w"

g->t_ref_count= 1;

/*:54*//*60:*/
#line 753 "./marpa.w"

MARPA_DSTACK_INIT2(g->t_xsy_stack,XSY);
MARPA_DSTACK_SAFE(g->t_nsy_stack);

/*:60*//*69:*/
#line 811 "./marpa.w"

MARPA_DSTACK_INIT2(g->t_xrl_stack,RULE);
MARPA_DSTACK_SAFE(g->t_irl_stack);

/*:69*//*79:*/
#line 859 "./marpa.w"

g->t_start_xsy_id= -1;
/*:79*//*83:*/
#line 897 "./marpa.w"

g->t_start_irl= NULL;

/*:83*//*86:*/
#line 911 "./marpa.w"

External_Size_of_G(g)= 0;

/*:86*//*89:*/
#line 924 "./marpa.w"

g->t_max_rule_length= 0;

/*:89*//*93:*/
#line 937 "./marpa.w"

g->t_default_rank= 0;
/*:93*//*98:*/
#line 972 "./marpa.w"

g->t_is_precomputed= 0;
/*:98*//*101:*/
#line 984 "./marpa.w"

g->t_has_cycle= 0;
/*:101*//*104:*/
#line 1004 "./marpa.w"
g->t_bv_nsyid_is_terminal= NULL;

/*:104*//*106:*/
#line 1019 "./marpa.w"

g->t_lbv_xsyid_is_completion_event= NULL;
g->t_lbv_xsyid_completion_event_starts_active= NULL;
g->t_lbv_xsyid_is_nulled_event= NULL;
g->t_lbv_xsyid_nulled_event_starts_active= NULL;
g->t_lbv_xsyid_is_prediction_event= NULL;
g->t_lbv_xsyid_prediction_event_starts_active= NULL;

/*:106*//*113:*/
#line 1060 "./marpa.w"

MARPA_DSTACK_INIT(g->t_events,GEV_Object,INITIAL_G_EVENTS_CAPACITY);
/*:113*//*121:*/
#line 1132 "./marpa.w"

(g)->t_xrl_tree= _marpa_avl_create(duplicate_rule_cmp,NULL);
/*:121*//*125:*/
#line 1163 "./marpa.w"

g->t_obs= marpa_obs_init;
g->t_xrl_obs= marpa_obs_init;
/*:125*//*128:*/
#line 1179 "./marpa.w"

cilar_init(&(g)->t_cilar);
/*:128*//*137:*/
#line 1227 "./marpa.w"

g->t_error= MARPA_ERR_NONE;
g->t_error_string= NULL;
/*:137*//*162:*/
#line 1390 "./marpa.w"

g->t_force_valued= 0;
/*:162*//*458:*/
#line 4882 "./marpa.w"

g->t_ahm_count= 0;

/*:458*//*460:*/
#line 4890 "./marpa.w"

g->t_ahms= NULL;
/*:460*//*534:*/
#line 5818 "./marpa.w"

MARPA_DSTACK_INIT2(g->t_gzwa_stack,GZWA);
/*:534*//*542:*/
#line 5857 "./marpa.w"

(g)->t_zwp_tree= _marpa_avl_create(zwp_cmp,NULL);
/*:542*/
#line 688 "./marpa.w"



g->t_is_ok= I_AM_OK;
return g;
}

/*:51*//*55:*/
#line 707 "./marpa.w"

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
#line 724 "./marpa.w"

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
#line 736 "./marpa.w"

PRIVATE
void grammar_free(GRAMMAR g)
{
/*61:*/
#line 757 "./marpa.w"

{
MARPA_DSTACK_DESTROY(g->t_xsy_stack);
MARPA_DSTACK_DESTROY(g->t_nsy_stack);
}

/*:61*//*70:*/
#line 815 "./marpa.w"

MARPA_DSTACK_DESTROY(g->t_irl_stack);
MARPA_DSTACK_DESTROY(g->t_xrl_stack);

/*:70*//*114:*/
#line 1062 "./marpa.w"
MARPA_DSTACK_DESTROY(g->t_events);

/*:114*//*123:*/
#line 1139 "./marpa.w"

/*122:*/
#line 1134 "./marpa.w"

{
_marpa_avl_destroy((g)->t_xrl_tree);
(g)->t_xrl_tree= NULL;
}
/*:122*/
#line 1140 "./marpa.w"


/*:123*//*126:*/
#line 1166 "./marpa.w"

marpa_obs_free(g->t_obs);
marpa_obs_free(g->t_xrl_obs);

/*:126*//*129:*/
#line 1181 "./marpa.w"

cilar_destroy(&(g)->t_cilar);

/*:129*//*461:*/
#line 4892 "./marpa.w"

my_free(g->t_ahms);

/*:461*//*535:*/
#line 5820 "./marpa.w"

MARPA_DSTACK_DESTROY(g->t_gzwa_stack);

/*:535*//*543:*/
#line 5859 "./marpa.w"

{
_marpa_avl_destroy((g)->t_zwp_tree);
(g)->t_zwp_tree= NULL;
}

/*:543*//*544:*/
#line 5865 "./marpa.w"

/*122:*/
#line 1134 "./marpa.w"

{
_marpa_avl_destroy((g)->t_xrl_tree);
(g)->t_xrl_tree= NULL;
}
/*:122*/
#line 5866 "./marpa.w"


/*:544*/
#line 740 "./marpa.w"

my_free(g);
}

/*:58*//*63:*/
#line 765 "./marpa.w"

int marpa_g_highest_symbol_id(Marpa_Grammar g){
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 767 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 768 "./marpa.w"

return XSY_Count_of_G(g)-1;
}

/*:63*//*65:*/
#line 777 "./marpa.w"

PRIVATE
void symbol_add(GRAMMAR g,XSY symbol)
{
const XSYID new_id= MARPA_DSTACK_LENGTH((g)->t_xsy_stack);
*MARPA_DSTACK_PUSH((g)->t_xsy_stack,XSY)= symbol;
symbol->t_symbol_id= new_id;
}

/*:65*//*66:*/
#line 789 "./marpa.w"

PRIVATE int xsy_id_is_valid(GRAMMAR g,XSYID xsy_id)
{
return!XSYID_is_Malformed(xsy_id)&&XSYID_of_G_Exists(xsy_id);
}

/*:66*//*67:*/
#line 798 "./marpa.w"

PRIVATE int nsy_is_valid(GRAMMAR g,NSYID nsyid)
{
return nsyid>=0&&nsyid<NSY_Count_of_G(g);
}

/*:67*//*74:*/
#line 822 "./marpa.w"

int marpa_g_highest_rule_id(Marpa_Grammar g){
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 824 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 825 "./marpa.w"

return XRL_Count_of_G(g)-1;
}
int _marpa_g_irl_count(Marpa_Grammar g){
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 829 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 830 "./marpa.w"

return IRL_Count_of_G(g);
}

/*:74*//*76:*/
#line 840 "./marpa.w"

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
#line 861 "./marpa.w"

Marpa_Symbol_ID marpa_g_start_symbol(Marpa_Grammar g)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 864 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 865 "./marpa.w"

if(g->t_start_xsy_id<0){
MARPA_ERROR(MARPA_ERR_NO_START_SYMBOL);
return-1;
}
return g->t_start_xsy_id;
}
/*:80*//*81:*/
#line 878 "./marpa.w"

Marpa_Symbol_ID marpa_g_start_symbol_set(Marpa_Grammar g,Marpa_Symbol_ID xsy_id)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 881 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 882 "./marpa.w"

/*1314:*/
#line 15634 "./marpa.w"

if(_MARPA_UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1314*/
#line 883 "./marpa.w"

/*1316:*/
#line 15645 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1316*/
#line 884 "./marpa.w"

/*1317:*/
#line 15652 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1317*/
#line 885 "./marpa.w"

return g->t_start_xsy_id= xsy_id;
}

/*:81*//*94:*/
#line 939 "./marpa.w"

Marpa_Rank marpa_g_default_rank(Marpa_Grammar g)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 942 "./marpa.w"

clear_error(g);
/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 944 "./marpa.w"

return Default_Rank_of_G(g);
}
/*:94*//*95:*/
#line 949 "./marpa.w"

Marpa_Rank marpa_g_default_rank_set(Marpa_Grammar g,Marpa_Rank rank)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 952 "./marpa.w"

clear_error(g);
/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 954 "./marpa.w"

/*1314:*/
#line 15634 "./marpa.w"

if(_MARPA_UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1314*/
#line 955 "./marpa.w"

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
#line 974 "./marpa.w"

int marpa_g_is_precomputed(Marpa_Grammar g)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 977 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 978 "./marpa.w"

return G_is_Precomputed(g);
}

/*:99*//*102:*/
#line 986 "./marpa.w"

int marpa_g_has_cycle(Marpa_Grammar g)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 989 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 990 "./marpa.w"

return g->t_has_cycle;
}

/*:102*//*116:*/
#line 1072 "./marpa.w"

PRIVATE
void event_new(GRAMMAR g,int type)
{


GEV end_of_stack= G_EVENT_PUSH(g);
end_of_stack->t_type= type;
end_of_stack->t_value= 0;
}
/*:116*//*117:*/
#line 1082 "./marpa.w"

PRIVATE
void int_event_new(GRAMMAR g,int type,int value)
{


GEV end_of_stack= G_EVENT_PUSH(g);
end_of_stack->t_type= type;
end_of_stack->t_value= value;
}

/*:117*//*118:*/
#line 1093 "./marpa.w"

Marpa_Event_Type
marpa_g_event(Marpa_Grammar g,Marpa_Event*public_event,
int ix)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 1098 "./marpa.w"

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
#line 1118 "./marpa.w"

Marpa_Event_Type
marpa_g_event_count(Marpa_Grammar g)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 1122 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 1123 "./marpa.w"

return MARPA_DSTACK_LENGTH(g->t_events);
}

/*:119*//*139:*/
#line 1238 "./marpa.w"

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
#line 1249 "./marpa.w"

Marpa_Error_Code
marpa_g_error_clear(Marpa_Grammar g)
{
clear_error(g);
return g->t_error;
}

/*:140*//*146:*/
#line 1279 "./marpa.w"

PRIVATE XSY
symbol_new(GRAMMAR g)
{
XSY xsy= marpa_obs_new(g->t_obs,struct s_xsy,1);
/*151:*/
#line 1312 "./marpa.w"

xsy->t_rank= Default_Rank_of_G(g);
/*:151*//*155:*/
#line 1358 "./marpa.w"

XSY_is_LHS(xsy)= 0;

/*:155*//*157:*/
#line 1365 "./marpa.w"

XSY_is_Sequence_LHS(xsy)= 0;

/*:157*//*159:*/
#line 1381 "./marpa.w"

XSY_is_Valued(xsy)= g->t_force_valued?1:0;
XSY_is_Valued_Locked(xsy)= g->t_force_valued?1:0;

/*:159*//*167:*/
#line 1449 "./marpa.w"

xsy->t_is_accessible= 0;
/*:167*//*170:*/
#line 1470 "./marpa.w"

xsy->t_is_counted= 0;
/*:170*//*173:*/
#line 1486 "./marpa.w"

xsy->t_is_nulling= 0;
/*:173*//*176:*/
#line 1503 "./marpa.w"

xsy->t_is_nullable= 0;
/*:176*//*179:*/
#line 1526 "./marpa.w"

xsy->t_is_terminal= 0;
xsy->t_is_locked_terminal= 0;
/*:179*//*184:*/
#line 1571 "./marpa.w"

xsy->t_is_productive= 0;
/*:184*//*187:*/
#line 1594 "./marpa.w"

xsy->t_is_completion_event= 0;
xsy->t_completion_event_starts_active= 0;
/*:187*//*192:*/
#line 1664 "./marpa.w"

xsy->t_is_nulled_event= 0;
xsy->t_nulled_event_starts_active= 0;
/*:192*//*197:*/
#line 1737 "./marpa.w"

xsy->t_is_prediction_event= 0;
xsy->t_prediction_event_starts_active= 0;
/*:197*//*203:*/
#line 1816 "./marpa.w"

Nulled_XSYIDs_of_XSY(xsy)= NULL;

/*:203*//*206:*/
#line 1832 "./marpa.w"
NSY_of_XSY(xsy)= NULL;
/*:206*//*210:*/
#line 1864 "./marpa.w"
Nulling_NSY_of_XSY(xsy)= NULL;
/*:210*/
#line 1284 "./marpa.w"

symbol_add(g,xsy);
return xsy;
}

/*:146*//*147:*/
#line 1289 "./marpa.w"

Marpa_Symbol_ID
marpa_g_symbol_new(Marpa_Grammar g)
{
const XSY symbol= symbol_new(g);
return ID_of_XSY(symbol);
}

/*:147*//*149:*/
#line 1298 "./marpa.w"

int marpa_g_symbol_is_start(Marpa_Grammar g,Marpa_Symbol_ID xsy_id)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 1301 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 1302 "./marpa.w"

/*1316:*/
#line 15645 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1316*/
#line 1303 "./marpa.w"

/*1317:*/
#line 15652 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1317*/
#line 1304 "./marpa.w"

if(g->t_start_xsy_id<0)return 0;
return xsy_id==g->t_start_xsy_id?1:0;
}

/*:149*//*152:*/
#line 1315 "./marpa.w"

int marpa_g_symbol_rank(Marpa_Grammar g,
Marpa_Symbol_ID xsy_id)
{
XSY xsy;
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 1320 "./marpa.w"

clear_error(g);
/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 1322 "./marpa.w"

/*1316:*/
#line 15645 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1316*/
#line 1323 "./marpa.w"

/*1318:*/
#line 15657 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return failure_indicator;
}

/*:1318*/
#line 1324 "./marpa.w"

xsy= XSY_by_ID(xsy_id);
return Rank_of_XSY(xsy);
}
/*:152*//*153:*/
#line 1328 "./marpa.w"

int marpa_g_symbol_rank_set(
Marpa_Grammar g,Marpa_Symbol_ID xsy_id,Marpa_Rank rank)
{
XSY xsy;
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 1333 "./marpa.w"

clear_error(g);
/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 1335 "./marpa.w"

/*1314:*/
#line 15634 "./marpa.w"

if(_MARPA_UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1314*/
#line 1336 "./marpa.w"

/*1316:*/
#line 15645 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1316*/
#line 1337 "./marpa.w"

/*1318:*/
#line 15657 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return failure_indicator;
}

/*:1318*/
#line 1338 "./marpa.w"

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
#line 1392 "./marpa.w"

int marpa_g_force_valued(Marpa_Grammar g)
{
XSYID xsyid;
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 1396 "./marpa.w"

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
#line 1411 "./marpa.w"

int marpa_g_symbol_is_valued(
Marpa_Grammar g,
Marpa_Symbol_ID xsy_id)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 1416 "./marpa.w"

/*1316:*/
#line 15645 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1316*/
#line 1417 "./marpa.w"

/*1317:*/
#line 15652 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1317*/
#line 1418 "./marpa.w"

return XSY_is_Valued(XSY_by_ID(xsy_id));
}

/*:164*//*165:*/
#line 1422 "./marpa.w"

int marpa_g_symbol_is_valued_set(
Marpa_Grammar g,Marpa_Symbol_ID xsy_id,int value)
{
XSY symbol;
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 1427 "./marpa.w"

/*1316:*/
#line 15645 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1316*/
#line 1428 "./marpa.w"

/*1317:*/
#line 15652 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1317*/
#line 1429 "./marpa.w"

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
#line 1457 "./marpa.w"

int marpa_g_symbol_is_accessible(Marpa_Grammar g,Marpa_Symbol_ID xsy_id)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 1460 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 1461 "./marpa.w"

/*1315:*/
#line 15640 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1315*/
#line 1462 "./marpa.w"

/*1316:*/
#line 15645 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1316*/
#line 1463 "./marpa.w"

/*1317:*/
#line 15652 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1317*/
#line 1464 "./marpa.w"

return XSY_is_Accessible(XSY_by_ID(xsy_id));
}

/*:168*//*171:*/
#line 1472 "./marpa.w"

int marpa_g_symbol_is_counted(Marpa_Grammar g,
Marpa_Symbol_ID xsy_id)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 1476 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 1477 "./marpa.w"

/*1316:*/
#line 15645 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1316*/
#line 1478 "./marpa.w"

/*1317:*/
#line 15652 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1317*/
#line 1479 "./marpa.w"

return XSY_by_ID(xsy_id)->t_is_counted;
}

/*:171*//*174:*/
#line 1488 "./marpa.w"

int marpa_g_symbol_is_nulling(Marpa_Grammar g,Marpa_Symbol_ID xsy_id)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 1491 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 1492 "./marpa.w"

/*1315:*/
#line 15640 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1315*/
#line 1493 "./marpa.w"

/*1316:*/
#line 15645 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1316*/
#line 1494 "./marpa.w"

/*1317:*/
#line 15652 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1317*/
#line 1495 "./marpa.w"

return XSY_is_Nulling(XSY_by_ID(xsy_id));
}

/*:174*//*177:*/
#line 1505 "./marpa.w"

int marpa_g_symbol_is_nullable(Marpa_Grammar g,Marpa_Symbol_ID xsy_id)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 1508 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 1509 "./marpa.w"

/*1315:*/
#line 15640 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1315*/
#line 1510 "./marpa.w"

/*1316:*/
#line 15645 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1316*/
#line 1511 "./marpa.w"

/*1317:*/
#line 15652 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1317*/
#line 1512 "./marpa.w"

return XSYID_is_Nullable(xsy_id);
}

/*:177*//*181:*/
#line 1532 "./marpa.w"

int marpa_g_symbol_is_terminal(Marpa_Grammar g,
Marpa_Symbol_ID xsy_id)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 1536 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 1537 "./marpa.w"

/*1316:*/
#line 15645 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1316*/
#line 1538 "./marpa.w"

/*1317:*/
#line 15652 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1317*/
#line 1539 "./marpa.w"

return XSYID_is_Terminal(xsy_id);
}
/*:181*//*182:*/
#line 1542 "./marpa.w"

int marpa_g_symbol_is_terminal_set(
Marpa_Grammar g,Marpa_Symbol_ID xsy_id,int value)
{
XSY symbol;
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 1547 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 1548 "./marpa.w"

/*1314:*/
#line 15634 "./marpa.w"

if(_MARPA_UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1314*/
#line 1549 "./marpa.w"

/*1316:*/
#line 15645 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1316*/
#line 1550 "./marpa.w"

/*1317:*/
#line 15652 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1317*/
#line 1551 "./marpa.w"

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
#line 1573 "./marpa.w"

int marpa_g_symbol_is_productive(
Marpa_Grammar g,
Marpa_Symbol_ID xsy_id)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 1578 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 1579 "./marpa.w"

/*1315:*/
#line 15640 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1315*/
#line 1580 "./marpa.w"

/*1316:*/
#line 15645 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1316*/
#line 1581 "./marpa.w"

/*1317:*/
#line 15652 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1317*/
#line 1582 "./marpa.w"

return XSY_is_Productive(XSY_by_ID(xsy_id));
}

/*:185*//*188:*/
#line 1597 "./marpa.w"

int marpa_g_symbol_is_completion_event(Marpa_Grammar g,
Marpa_Symbol_ID xsy_id)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 1601 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 1602 "./marpa.w"

/*1316:*/
#line 15645 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1316*/
#line 1603 "./marpa.w"

/*1317:*/
#line 15652 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1317*/
#line 1604 "./marpa.w"

return XSYID_is_Completion_Event(xsy_id);
}
/*:188*//*189:*/
#line 1607 "./marpa.w"

int marpa_g_symbol_is_completion_event_set(
Marpa_Grammar g,Marpa_Symbol_ID xsy_id,int value)
{
XSY xsy;
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 1612 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 1613 "./marpa.w"

/*1314:*/
#line 15634 "./marpa.w"

if(_MARPA_UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1314*/
#line 1614 "./marpa.w"

/*1316:*/
#line 15645 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1316*/
#line 1615 "./marpa.w"

/*1317:*/
#line 15652 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1317*/
#line 1616 "./marpa.w"

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
#line 1626 "./marpa.w"

int
marpa_g_completion_symbol_activate(Marpa_Grammar g,
Marpa_Symbol_ID xsy_id,
int reactivate)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 1632 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 1633 "./marpa.w"

/*1314:*/
#line 15634 "./marpa.w"

if(_MARPA_UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1314*/
#line 1634 "./marpa.w"

/*1316:*/
#line 15645 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1316*/
#line 1635 "./marpa.w"

/*1317:*/
#line 15652 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1317*/
#line 1636 "./marpa.w"

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
#line 1667 "./marpa.w"

int marpa_g_symbol_is_nulled_event(Marpa_Grammar g,
Marpa_Symbol_ID xsy_id)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 1671 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 1672 "./marpa.w"

/*1316:*/
#line 15645 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1316*/
#line 1673 "./marpa.w"

/*1317:*/
#line 15652 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1317*/
#line 1674 "./marpa.w"

return XSYID_is_Nulled_Event(xsy_id);
}

/*:193*//*194:*/
#line 1680 "./marpa.w"

int marpa_g_symbol_is_nulled_event_set(
Marpa_Grammar g,Marpa_Symbol_ID xsy_id,int value)
{
XSY xsy;
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 1685 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 1686 "./marpa.w"

/*1314:*/
#line 15634 "./marpa.w"

if(_MARPA_UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1314*/
#line 1687 "./marpa.w"

/*1316:*/
#line 15645 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1316*/
#line 1688 "./marpa.w"

/*1317:*/
#line 15652 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1317*/
#line 1689 "./marpa.w"

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
#line 1699 "./marpa.w"

int
marpa_g_nulled_symbol_activate(Marpa_Grammar g,
Marpa_Symbol_ID xsy_id,
int reactivate)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 1705 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 1706 "./marpa.w"

/*1314:*/
#line 15634 "./marpa.w"

if(_MARPA_UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1314*/
#line 1707 "./marpa.w"

/*1316:*/
#line 15645 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1316*/
#line 1708 "./marpa.w"

/*1317:*/
#line 15652 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1317*/
#line 1709 "./marpa.w"

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
#line 1740 "./marpa.w"

int marpa_g_symbol_is_prediction_event(Marpa_Grammar g,
Marpa_Symbol_ID xsy_id)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 1744 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 1745 "./marpa.w"

/*1316:*/
#line 15645 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1316*/
#line 1746 "./marpa.w"

/*1317:*/
#line 15652 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1317*/
#line 1747 "./marpa.w"

return XSYID_is_Prediction_Event(xsy_id);
}
/*:198*//*199:*/
#line 1750 "./marpa.w"

int marpa_g_symbol_is_prediction_event_set(
Marpa_Grammar g,Marpa_Symbol_ID xsy_id,int value)
{
XSY xsy;
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 1755 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 1756 "./marpa.w"

/*1314:*/
#line 15634 "./marpa.w"

if(_MARPA_UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1314*/
#line 1757 "./marpa.w"

/*1316:*/
#line 15645 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1316*/
#line 1758 "./marpa.w"

/*1317:*/
#line 15652 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1317*/
#line 1759 "./marpa.w"

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
#line 1769 "./marpa.w"

int
marpa_g_prediction_symbol_activate(Marpa_Grammar g,
Marpa_Symbol_ID xsy_id,
int reactivate)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 1775 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 1776 "./marpa.w"

/*1314:*/
#line 15634 "./marpa.w"

if(_MARPA_UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1314*/
#line 1777 "./marpa.w"

/*1316:*/
#line 15645 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1316*/
#line 1778 "./marpa.w"

/*1317:*/
#line 15652 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1317*/
#line 1779 "./marpa.w"

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
#line 1799 "./marpa.w"

/*:201*//*207:*/
#line 1833 "./marpa.w"

Marpa_NSY_ID _marpa_g_xsy_nsy(
Marpa_Grammar g,
Marpa_Symbol_ID xsy_id)
{
XSY xsy;
NSY nsy;
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 1840 "./marpa.w"

/*1316:*/
#line 15645 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1316*/
#line 1841 "./marpa.w"

/*1317:*/
#line 15652 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1317*/
#line 1842 "./marpa.w"

xsy= XSY_by_ID(xsy_id);
nsy= NSY_of_XSY(xsy);
return nsy?ID_of_NSY(nsy):-1;
}

/*:207*//*211:*/
#line 1865 "./marpa.w"

Marpa_NSY_ID _marpa_g_xsy_nulling_nsy(
Marpa_Grammar g,
Marpa_Symbol_ID xsy_id)
{
XSY xsy;
NSY nsy;
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 1872 "./marpa.w"

/*1316:*/
#line 15645 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1316*/
#line 1873 "./marpa.w"

/*1317:*/
#line 15652 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1317*/
#line 1874 "./marpa.w"

xsy= XSY_by_ID(xsy_id);
nsy= Nulling_NSY_of_XSY(xsy);
return nsy?ID_of_NSY(nsy):-1;
}

/*:211*//*213:*/
#line 1886 "./marpa.w"

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
#line 1944 "./marpa.w"

PRIVATE NSY
nsy_start(GRAMMAR g)
{
const NSY nsy= marpa_obs_new(g->t_obs,struct s_nsy,1);
ID_of_NSY(nsy)= MARPA_DSTACK_LENGTH((g)->t_nsy_stack);
*MARPA_DSTACK_PUSH((g)->t_nsy_stack,NSY)= nsy;
/*218:*/
#line 1936 "./marpa.w"

nsy->t_nulling_or_node.t_or_node_type= NULLING_TOKEN_OR_NODE;

nsy->t_unvalued_or_node.t_or_node_type= UNVALUED_TOKEN_OR_NODE;
nsy->t_unvalued_or_node.t_nsyid= ID_of_NSY(nsy);

/*:218*//*228:*/
#line 2012 "./marpa.w"
NSY_is_Start(nsy)= 0;
/*:228*//*231:*/
#line 2026 "./marpa.w"
NSY_is_LHS(nsy)= 0;
/*:231*//*234:*/
#line 2040 "./marpa.w"
NSY_is_Nulling(nsy)= 0;
/*:234*//*237:*/
#line 2057 "./marpa.w"
LHS_CIL_of_NSY(nsy)= NULL;

/*:237*//*239:*/
#line 2065 "./marpa.w"
NSY_is_Semantic(nsy)= 0;
/*:239*//*242:*/
#line 2088 "./marpa.w"
Source_XSY_of_NSY(nsy)= NULL;
/*:242*//*246:*/
#line 2113 "./marpa.w"

LHS_XRL_of_NSY(nsy)= NULL;
XRL_Offset_of_NSY(nsy)= -1;

/*:246*//*251:*/
#line 2164 "./marpa.w"

Rank_of_NSY(nsy)= Default_Rank_of_G(g)*EXTERNAL_RANK_FACTOR+MAXIMUM_CHAF_RANK;
/*:251*/
#line 1951 "./marpa.w"

return nsy;
}

/*:220*//*221:*/
#line 1957 "./marpa.w"

PRIVATE NSY
nsy_new(GRAMMAR g,XSY source)
{
const NSY new_nsy= nsy_start(g);
Source_XSY_of_NSY(new_nsy)= source;
Rank_of_NSY(new_nsy)= NSY_Rank_by_XSY(source);
return new_nsy;
}

/*:221*//*222:*/
#line 1969 "./marpa.w"

PRIVATE NSY
semantic_nsy_new(GRAMMAR g,XSY source)
{
const NSY new_nsy= nsy_new(g,source);
NSY_is_Semantic(new_nsy)= 1;
return new_nsy;
}

/*:222*//*223:*/
#line 1980 "./marpa.w"

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
#line 2002 "./marpa.w"

int _marpa_g_nsy_count(Marpa_Grammar g){
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 2004 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 2005 "./marpa.w"

return NSY_Count_of_G(g);
}

/*:226*//*229:*/
#line 2013 "./marpa.w"

int _marpa_g_nsy_is_start(Marpa_Grammar g,Marpa_NSY_ID nsy_id)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 2016 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 2017 "./marpa.w"

/*1315:*/
#line 15640 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1315*/
#line 2018 "./marpa.w"

/*1319:*/
#line 15663 "./marpa.w"

if(_MARPA_UNLIKELY(!nsy_is_valid(g,nsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_NSYID);
return failure_indicator;
}
/*:1319*/
#line 2019 "./marpa.w"

return NSY_is_Start(NSY_by_ID(nsy_id));
}

/*:229*//*232:*/
#line 2027 "./marpa.w"

int _marpa_g_nsy_is_lhs(Marpa_Grammar g,Marpa_NSY_ID nsy_id)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 2030 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 2031 "./marpa.w"

/*1315:*/
#line 15640 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1315*/
#line 2032 "./marpa.w"

/*1319:*/
#line 15663 "./marpa.w"

if(_MARPA_UNLIKELY(!nsy_is_valid(g,nsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_NSYID);
return failure_indicator;
}
/*:1319*/
#line 2033 "./marpa.w"

return NSY_is_LHS(NSY_by_ID(nsy_id));
}

/*:232*//*235:*/
#line 2041 "./marpa.w"

int _marpa_g_nsy_is_nulling(Marpa_Grammar g,Marpa_NSY_ID nsy_id)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 2044 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 2045 "./marpa.w"

/*1315:*/
#line 15640 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1315*/
#line 2046 "./marpa.w"

/*1319:*/
#line 15663 "./marpa.w"

if(_MARPA_UNLIKELY(!nsy_is_valid(g,nsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_NSYID);
return failure_indicator;
}
/*:1319*/
#line 2047 "./marpa.w"

return NSY_is_Nulling(NSY_by_ID(nsy_id));
}

/*:235*//*240:*/
#line 2066 "./marpa.w"

int _marpa_g_nsy_is_semantic(
Marpa_Grammar g,
Marpa_IRL_ID nsy_id)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 2071 "./marpa.w"

/*1319:*/
#line 15663 "./marpa.w"

if(_MARPA_UNLIKELY(!nsy_is_valid(g,nsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_NSYID);
return failure_indicator;
}
/*:1319*/
#line 2072 "./marpa.w"

return NSYID_is_Semantic(nsy_id);
}

/*:240*//*243:*/
#line 2089 "./marpa.w"

Marpa_Rule_ID _marpa_g_source_xsy(
Marpa_Grammar g,
Marpa_IRL_ID nsy_id)
{
XSY source_xsy;
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 2095 "./marpa.w"

/*1319:*/
#line 15663 "./marpa.w"

if(_MARPA_UNLIKELY(!nsy_is_valid(g,nsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_NSYID);
return failure_indicator;
}
/*:1319*/
#line 2096 "./marpa.w"

source_xsy= Source_XSY_of_NSYID(nsy_id);
return ID_of_XSY(source_xsy);
}

/*:243*//*248:*/
#line 2124 "./marpa.w"

Marpa_Rule_ID _marpa_g_nsy_lhs_xrl(Marpa_Grammar g,Marpa_NSY_ID nsy_id)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 2127 "./marpa.w"

/*1319:*/
#line 15663 "./marpa.w"

if(_MARPA_UNLIKELY(!nsy_is_valid(g,nsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_NSYID);
return failure_indicator;
}
/*:1319*/
#line 2128 "./marpa.w"

{
const NSY nsy= NSY_by_ID(nsy_id);
const XRL lhs_xrl= LHS_XRL_of_NSY(nsy);
if(lhs_xrl)
return ID_of_XRL(lhs_xrl);
}
return-1;
}

/*:248*//*249:*/
#line 2148 "./marpa.w"

int _marpa_g_nsy_xrl_offset(Marpa_Grammar g,Marpa_NSY_ID nsy_id)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 2151 "./marpa.w"

NSY nsy;
/*1319:*/
#line 15663 "./marpa.w"

if(_MARPA_UNLIKELY(!nsy_is_valid(g,nsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_NSYID);
return failure_indicator;
}
/*:1319*/
#line 2153 "./marpa.w"

nsy= NSY_by_ID(nsy_id);
return XRL_Offset_of_NSY(nsy);
}

/*:249*//*252:*/
#line 2166 "./marpa.w"

Marpa_Rank _marpa_g_nsy_rank(
Marpa_Grammar g,
Marpa_NSY_ID nsy_id)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 2171 "./marpa.w"

/*1319:*/
#line 15663 "./marpa.w"

if(_MARPA_UNLIKELY(!nsy_is_valid(g,nsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_NSYID);
return failure_indicator;
}
/*:1319*/
#line 2172 "./marpa.w"

return Rank_of_NSY(NSY_by_ID(nsy_id));
}

/*:252*//*258:*/
#line 2207 "./marpa.w"

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
#line 2553 "./marpa.w"

rule->t_rank= Default_Rank_of_G(g);
/*:277*//*281:*/
#line 2602 "./marpa.w"

rule->t_null_ranks_high= 0;
/*:281*//*285:*/
#line 2642 "./marpa.w"

rule->t_is_bnf= 0;

/*:285*//*287:*/
#line 2648 "./marpa.w"

rule->t_is_sequence= 0;

/*:287*//*289:*/
#line 2662 "./marpa.w"

rule->t_minimum= -1;
/*:289*//*292:*/
#line 2688 "./marpa.w"

Separator_of_XRL(rule)= -1;
/*:292*//*297:*/
#line 2725 "./marpa.w"

rule->t_is_discard= 0;
/*:297*//*301:*/
#line 2765 "./marpa.w"

rule->t_is_proper_separation= 0;
/*:301*//*305:*/
#line 2786 "./marpa.w"

rule->t_is_loop= 0;
/*:305*//*308:*/
#line 2804 "./marpa.w"

XRL_is_Nulling(rule)= 0;
/*:308*//*311:*/
#line 2823 "./marpa.w"

XRL_is_Nullable(rule)= 0;
/*:311*//*315:*/
#line 2842 "./marpa.w"

XRL_is_Accessible(rule)= 1;
/*:315*//*318:*/
#line 2861 "./marpa.w"

XRL_is_Productive(rule)= 1;
/*:318*//*321:*/
#line 2880 "./marpa.w"

XRL_is_Used(rule)= 0;
/*:321*/
#line 2231 "./marpa.w"

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
#line 2247 "./marpa.w"

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
#line 3017 "./marpa.w"

IRL_has_Virtual_LHS(irl)= 0;
/*:342*//*345:*/
#line 3033 "./marpa.w"

IRL_has_Virtual_RHS(irl)= 0;
/*:345*//*348:*/
#line 3052 "./marpa.w"

IRL_is_Right_Recursive(irl)= 0;

/*:348*//*351:*/
#line 3063 "./marpa.w"
Real_SYM_Count_of_IRL(irl)= 0;
/*:351*//*354:*/
#line 3081 "./marpa.w"
irl->t_virtual_start= -1;
/*:354*//*357:*/
#line 3101 "./marpa.w"
irl->t_virtual_end= -1;
/*:357*//*360:*/
#line 3123 "./marpa.w"
Source_XRL_of_IRL(irl)= NULL;
/*:360*//*363:*/
#line 3150 "./marpa.w"

Rank_of_IRL(irl)= Default_Rank_of_G(g)*EXTERNAL_RANK_FACTOR+MAXIMUM_CHAF_RANK;
/*:363*//*366:*/
#line 3172 "./marpa.w"

First_AHM_of_IRL(irl)= NULL;

/*:366*//*410:*/
#line 4072 "./marpa.w"

IRL_is_CHAF(irl)= 0;
/*:410*//*474:*/
#line 4989 "./marpa.w"

Last_Proper_SYMI_of_IRL(irl)= -1;

/*:474*/
#line 2260 "./marpa.w"

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
#line 2286 "./marpa.w"

Marpa_Rule_ID
marpa_g_rule_new(Marpa_Grammar g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID*rhs_ids,int length)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 2291 "./marpa.w"

Marpa_Rule_ID rule_id;
RULE rule;
/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 2294 "./marpa.w"

/*1314:*/
#line 15634 "./marpa.w"

if(_MARPA_UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1314*/
#line 2295 "./marpa.w"

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
#line 2340 "./marpa.w"

Marpa_Rule_ID marpa_g_sequence_new(Marpa_Grammar g,
Marpa_Symbol_ID lhs_id,Marpa_Symbol_ID rhs_id,Marpa_Symbol_ID separator_id,
int min,int flags)
{
RULE original_rule;
RULEID original_rule_id= -2;
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 2347 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 2348 "./marpa.w"

/*1314:*/
#line 15634 "./marpa.w"

if(_MARPA_UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1314*/
#line 2349 "./marpa.w"

/*264:*/
#line 2380 "./marpa.w"

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
#line 2350 "./marpa.w"

/*263:*/
#line 2358 "./marpa.w"

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
#line 2351 "./marpa.w"

return original_rule_id;
FAILURE:
return failure_indicator;
}

/*:262*//*266:*/
#line 2433 "./marpa.w"

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
#line 2489 "./marpa.w"

PRIVATE Marpa_Symbol_ID rule_lhs_get(RULE rule)
{
return rule->t_symbols[0];}
/*:269*//*270:*/
#line 2493 "./marpa.w"

Marpa_Symbol_ID marpa_g_rule_lhs(Marpa_Grammar g,Marpa_Rule_ID xrl_id){
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 2495 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 2496 "./marpa.w"

/*1325:*/
#line 15701 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}

/*:1325*/
#line 2497 "./marpa.w"

/*1323:*/
#line 15689 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}

/*:1323*/
#line 2498 "./marpa.w"

return rule_lhs_get(XRL_by_ID(xrl_id));
}
/*:270*//*271:*/
#line 2501 "./marpa.w"

PRIVATE Marpa_Symbol_ID*rule_rhs_get(RULE rule)
{
return rule->t_symbols+1;}
/*:271*//*272:*/
#line 2505 "./marpa.w"

Marpa_Symbol_ID marpa_g_rule_rhs(Marpa_Grammar g,Marpa_Rule_ID xrl_id,int ix){
RULE rule;
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 2508 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 2509 "./marpa.w"

/*1325:*/
#line 15701 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}

/*:1325*/
#line 2510 "./marpa.w"

/*1323:*/
#line 15689 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}

/*:1323*/
#line 2511 "./marpa.w"

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
#line 2524 "./marpa.w"

int marpa_g_rule_length(Marpa_Grammar g,Marpa_Rule_ID xrl_id){
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 2526 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 2527 "./marpa.w"

/*1325:*/
#line 15701 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}

/*:1325*/
#line 2528 "./marpa.w"

/*1323:*/
#line 15689 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}

/*:1323*/
#line 2529 "./marpa.w"

return Length_of_XRL(XRL_by_ID(xrl_id));
}

/*:273*//*278:*/
#line 2556 "./marpa.w"

int marpa_g_rule_rank(Marpa_Grammar g,
Marpa_Rule_ID xrl_id)
{
XRL xrl;
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 2561 "./marpa.w"

clear_error(g);
/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 2563 "./marpa.w"

/*1325:*/
#line 15701 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}

/*:1325*/
#line 2564 "./marpa.w"

/*1324:*/
#line 15695 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return failure_indicator;
}
/*:1324*/
#line 2565 "./marpa.w"

clear_error(g);
xrl= XRL_by_ID(xrl_id);
return Rank_of_XRL(xrl);
}
/*:278*//*279:*/
#line 2570 "./marpa.w"

int marpa_g_rule_rank_set(
Marpa_Grammar g,Marpa_Rule_ID xrl_id,Marpa_Rank rank)
{
XRL xrl;
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 2575 "./marpa.w"

clear_error(g);
/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 2577 "./marpa.w"

/*1314:*/
#line 15634 "./marpa.w"

if(_MARPA_UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1314*/
#line 2578 "./marpa.w"

/*1325:*/
#line 15701 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}

/*:1325*/
#line 2579 "./marpa.w"

/*1324:*/
#line 15695 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return failure_indicator;
}
/*:1324*/
#line 2580 "./marpa.w"

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
#line 2606 "./marpa.w"

int marpa_g_rule_null_high(Marpa_Grammar g,
Marpa_Rule_ID xrl_id)
{
XRL xrl;
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 2611 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 2612 "./marpa.w"

/*1325:*/
#line 15701 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}

/*:1325*/
#line 2613 "./marpa.w"

/*1323:*/
#line 15689 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}

/*:1323*/
#line 2614 "./marpa.w"

xrl= XRL_by_ID(xrl_id);
return Null_Ranks_High_of_RULE(xrl);
}
/*:282*//*283:*/
#line 2618 "./marpa.w"

int marpa_g_rule_null_high_set(
Marpa_Grammar g,Marpa_Rule_ID xrl_id,int flag)
{
XRL xrl;
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 2623 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 2624 "./marpa.w"

/*1314:*/
#line 15634 "./marpa.w"

if(_MARPA_UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1314*/
#line 2625 "./marpa.w"

/*1325:*/
#line 15701 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}

/*:1325*/
#line 2626 "./marpa.w"

/*1323:*/
#line 15689 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}

/*:1323*/
#line 2627 "./marpa.w"

xrl= XRL_by_ID(xrl_id);
if(_MARPA_UNLIKELY(flag<0||flag> 1))
{
MARPA_ERROR(MARPA_ERR_INVALID_BOOLEAN);
return failure_indicator;
}
return Null_Ranks_High_of_RULE(xrl)= Boolean(flag);
}

/*:283*//*290:*/
#line 2664 "./marpa.w"

int marpa_g_sequence_min(
Marpa_Grammar g,
Marpa_Rule_ID xrl_id)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 2669 "./marpa.w"

XRL xrl;
/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 2671 "./marpa.w"

/*1325:*/
#line 15701 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}

/*:1325*/
#line 2672 "./marpa.w"

/*1324:*/
#line 15695 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return failure_indicator;
}
/*:1324*/
#line 2673 "./marpa.w"

xrl= XRL_by_ID(xrl_id);
if(!XRL_is_Sequence(xrl))
{
MARPA_ERROR(MARPA_ERR_NOT_A_SEQUENCE);
return-1;
}
return Minimum_of_XRL(xrl);
}

/*:290*//*293:*/
#line 2690 "./marpa.w"

Marpa_Symbol_ID marpa_g_sequence_separator(
Marpa_Grammar g,
Marpa_Rule_ID xrl_id)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 2695 "./marpa.w"

XRL xrl;
/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 2697 "./marpa.w"

/*1325:*/
#line 15701 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}

/*:1325*/
#line 2698 "./marpa.w"

/*1324:*/
#line 15695 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return failure_indicator;
}
/*:1324*/
#line 2699 "./marpa.w"

xrl= XRL_by_ID(xrl_id);
if(!XRL_is_Sequence(xrl))
{
MARPA_ERROR(MARPA_ERR_NOT_A_SEQUENCE);
return failure_indicator;
}
return Separator_of_XRL(xrl);
}

/*:293*//*298:*/
#line 2727 "./marpa.w"

int _marpa_g_rule_is_keep_separation(
Marpa_Grammar g,
Marpa_Rule_ID xrl_id)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 2732 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 2733 "./marpa.w"

/*1325:*/
#line 15701 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}

/*:1325*/
#line 2734 "./marpa.w"

/*1323:*/
#line 15689 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}

/*:1323*/
#line 2735 "./marpa.w"

return!XRL_by_ID(xrl_id)->t_is_discard;
}

/*:298*//*302:*/
#line 2767 "./marpa.w"

int marpa_g_rule_is_proper_separation(
Marpa_Grammar g,
Marpa_Rule_ID xrl_id)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 2772 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 2773 "./marpa.w"

/*1325:*/
#line 15701 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}

/*:1325*/
#line 2774 "./marpa.w"

/*1323:*/
#line 15689 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}

/*:1323*/
#line 2775 "./marpa.w"

return XRL_is_Proper_Separation(XRL_by_ID(xrl_id));
}

/*:302*//*306:*/
#line 2788 "./marpa.w"

int marpa_g_rule_is_loop(Marpa_Grammar g,Marpa_Rule_ID xrl_id)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 2791 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 2792 "./marpa.w"

/*1315:*/
#line 15640 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1315*/
#line 2793 "./marpa.w"

/*1325:*/
#line 15701 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}

/*:1325*/
#line 2794 "./marpa.w"

/*1323:*/
#line 15689 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}

/*:1323*/
#line 2795 "./marpa.w"

/*1315:*/
#line 15640 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1315*/
#line 2796 "./marpa.w"

return XRL_by_ID(xrl_id)->t_is_loop;
}

/*:306*//*309:*/
#line 2806 "./marpa.w"

int marpa_g_rule_is_nulling(Marpa_Grammar g,Marpa_Rule_ID xrl_id)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 2809 "./marpa.w"

XRL xrl;
/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 2811 "./marpa.w"

/*1315:*/
#line 15640 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1315*/
#line 2812 "./marpa.w"

/*1325:*/
#line 15701 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}

/*:1325*/
#line 2813 "./marpa.w"

/*1323:*/
#line 15689 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}

/*:1323*/
#line 2814 "./marpa.w"

xrl= XRL_by_ID(xrl_id);
return XRL_is_Nulling(xrl);
}

/*:309*//*312:*/
#line 2825 "./marpa.w"

int marpa_g_rule_is_nullable(Marpa_Grammar g,Marpa_Rule_ID xrl_id)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 2828 "./marpa.w"

XRL xrl;
/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 2830 "./marpa.w"

/*1315:*/
#line 15640 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1315*/
#line 2831 "./marpa.w"

/*1325:*/
#line 15701 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}

/*:1325*/
#line 2832 "./marpa.w"

/*1323:*/
#line 15689 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}

/*:1323*/
#line 2833 "./marpa.w"

xrl= XRL_by_ID(xrl_id);
return XRL_is_Nullable(xrl);
}

/*:312*//*316:*/
#line 2844 "./marpa.w"

int marpa_g_rule_is_accessible(Marpa_Grammar g,Marpa_Rule_ID xrl_id)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 2847 "./marpa.w"

XRL xrl;
/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 2849 "./marpa.w"

/*1315:*/
#line 15640 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1315*/
#line 2850 "./marpa.w"

/*1325:*/
#line 15701 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}

/*:1325*/
#line 2851 "./marpa.w"

/*1323:*/
#line 15689 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}

/*:1323*/
#line 2852 "./marpa.w"

xrl= XRL_by_ID(xrl_id);
return XRL_is_Accessible(xrl);
}

/*:316*//*319:*/
#line 2863 "./marpa.w"

int marpa_g_rule_is_productive(Marpa_Grammar g,Marpa_Rule_ID xrl_id)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 2866 "./marpa.w"

XRL xrl;
/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 2868 "./marpa.w"

/*1315:*/
#line 15640 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1315*/
#line 2869 "./marpa.w"

/*1325:*/
#line 15701 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}

/*:1325*/
#line 2870 "./marpa.w"

/*1323:*/
#line 15689 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}

/*:1323*/
#line 2871 "./marpa.w"

xrl= XRL_by_ID(xrl_id);
return XRL_is_Productive(xrl);
}

/*:319*//*322:*/
#line 2882 "./marpa.w"

int
_marpa_g_rule_is_used(Marpa_Grammar g,Marpa_Rule_ID xrl_id)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 2886 "./marpa.w"

/*1325:*/
#line 15701 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}

/*:1325*/
#line 2887 "./marpa.w"

/*1323:*/
#line 15689 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}

/*:1323*/
#line 2888 "./marpa.w"

return XRL_is_Used(XRL_by_ID(xrl_id));
}

/*:322*//*324:*/
#line 2895 "./marpa.w"

Marpa_Rule_ID
_marpa_g_irl_semantic_equivalent(Marpa_Grammar g,Marpa_IRL_ID irl_id)
{
IRL irl;
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 2900 "./marpa.w"

/*1322:*/
#line 15681 "./marpa.w"

if(_MARPA_UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1322*/
#line 2901 "./marpa.w"

irl= IRL_by_ID(irl_id);
if(IRL_has_Virtual_LHS(irl))return-1;
return ID_of_XRL(Source_XRL_of_IRL(irl));
}

/*:324*//*333:*/
#line 2942 "./marpa.w"

Marpa_NSY_ID _marpa_g_irl_lhs(Marpa_Grammar g,Marpa_IRL_ID irl_id){
IRL irl;
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 2945 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 2946 "./marpa.w"

/*1315:*/
#line 15640 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1315*/
#line 2947 "./marpa.w"

/*1322:*/
#line 15681 "./marpa.w"

if(_MARPA_UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1322*/
#line 2948 "./marpa.w"

irl= IRL_by_ID(irl_id);
return LHSID_of_IRL(irl);
}

/*:333*//*335:*/
#line 2955 "./marpa.w"

Marpa_NSY_ID _marpa_g_irl_rhs(Marpa_Grammar g,Marpa_IRL_ID irl_id,int ix){
IRL irl;
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 2958 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 2959 "./marpa.w"

/*1315:*/
#line 15640 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1315*/
#line 2960 "./marpa.w"

/*1322:*/
#line 15681 "./marpa.w"

if(_MARPA_UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1322*/
#line 2961 "./marpa.w"

irl= IRL_by_ID(irl_id);
if(Length_of_IRL(irl)<=ix)return-1;
return RHSID_of_IRL(irl,ix);
}

/*:335*//*337:*/
#line 2969 "./marpa.w"

int _marpa_g_irl_length(Marpa_Grammar g,Marpa_IRL_ID irl_id){
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 2971 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 2972 "./marpa.w"

/*1315:*/
#line 15640 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1315*/
#line 2973 "./marpa.w"

/*1322:*/
#line 15681 "./marpa.w"

if(_MARPA_UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1322*/
#line 2974 "./marpa.w"

return Length_of_IRL(IRL_by_ID(irl_id));
}

/*:337*//*343:*/
#line 3019 "./marpa.w"

int _marpa_g_irl_is_virtual_lhs(
Marpa_Grammar g,
Marpa_IRL_ID irl_id)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 3024 "./marpa.w"

/*1315:*/
#line 15640 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1315*/
#line 3025 "./marpa.w"

/*1322:*/
#line 15681 "./marpa.w"

if(_MARPA_UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1322*/
#line 3026 "./marpa.w"

return IRL_has_Virtual_LHS(IRL_by_ID(irl_id));
}

/*:343*//*346:*/
#line 3035 "./marpa.w"

int _marpa_g_irl_is_virtual_rhs(
Marpa_Grammar g,
Marpa_IRL_ID irl_id)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 3040 "./marpa.w"

/*1315:*/
#line 15640 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1315*/
#line 3041 "./marpa.w"

/*1322:*/
#line 15681 "./marpa.w"

if(_MARPA_UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1322*/
#line 3042 "./marpa.w"

return IRL_has_Virtual_RHS(IRL_by_ID(irl_id));
}

/*:346*//*352:*/
#line 3064 "./marpa.w"

int _marpa_g_real_symbol_count(
Marpa_Grammar g,
Marpa_IRL_ID irl_id)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 3069 "./marpa.w"

/*1315:*/
#line 15640 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1315*/
#line 3070 "./marpa.w"

/*1322:*/
#line 15681 "./marpa.w"

if(_MARPA_UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1322*/
#line 3071 "./marpa.w"

return Real_SYM_Count_of_IRL(IRL_by_ID(irl_id));
}

/*:352*//*355:*/
#line 3082 "./marpa.w"

int _marpa_g_virtual_start(
Marpa_Grammar g,
Marpa_IRL_ID irl_id)
{
IRL irl;
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 3088 "./marpa.w"

/*1315:*/
#line 15640 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1315*/
#line 3089 "./marpa.w"

/*1322:*/
#line 15681 "./marpa.w"

if(_MARPA_UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1322*/
#line 3090 "./marpa.w"

irl= IRL_by_ID(irl_id);
return Virtual_Start_of_IRL(irl);
}

/*:355*//*358:*/
#line 3102 "./marpa.w"

int _marpa_g_virtual_end(
Marpa_Grammar g,
Marpa_IRL_ID irl_id)
{
IRL irl;
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 3108 "./marpa.w"

/*1315:*/
#line 15640 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1315*/
#line 3109 "./marpa.w"

/*1322:*/
#line 15681 "./marpa.w"

if(_MARPA_UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1322*/
#line 3110 "./marpa.w"

irl= IRL_by_ID(irl_id);
return Virtual_End_of_IRL(irl);
}

/*:358*//*361:*/
#line 3124 "./marpa.w"

Marpa_Rule_ID _marpa_g_source_xrl(
Marpa_Grammar g,
Marpa_IRL_ID irl_id)
{
XRL source_xrl;
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 3130 "./marpa.w"

/*1322:*/
#line 15681 "./marpa.w"

if(_MARPA_UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1322*/
#line 3131 "./marpa.w"

source_xrl= Source_XRL_of_IRL(IRL_by_ID(irl_id));
return source_xrl?ID_of_XRL(source_xrl):-1;
}

/*:361*//*364:*/
#line 3152 "./marpa.w"

Marpa_Rank _marpa_g_irl_rank(
Marpa_Grammar g,
Marpa_IRL_ID irl_id)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 3157 "./marpa.w"

/*1322:*/
#line 15681 "./marpa.w"

if(_MARPA_UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1322*/
#line 3158 "./marpa.w"

return Rank_of_IRL(IRL_by_ID(irl_id));
}

/*:364*//*368:*/
#line 3192 "./marpa.w"

int marpa_g_precompute(Marpa_Grammar g)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 3195 "./marpa.w"

int return_value= failure_indicator;
struct marpa_obstack*obs_precompute= marpa_obs_init;
/*373:*/
#line 3321 "./marpa.w"

XRLID xrl_count= XRL_Count_of_G(g);
XSYID pre_census_xsy_count= XSY_Count_of_G(g);
XSYID post_census_xsy_count= -1;

/*:373*//*377:*/
#line 3355 "./marpa.w"

XSYID start_xsy_id= g->t_start_xsy_id;

/*:377*//*390:*/
#line 3658 "./marpa.w"

Bit_Matrix reach_matrix= NULL;

/*:390*/
#line 3198 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 3199 "./marpa.w"

G_EVENTS_CLEAR(g);
/*374:*/
#line 3326 "./marpa.w"

if(_MARPA_UNLIKELY(xrl_count<=0)){
MARPA_ERROR(MARPA_ERR_NO_RULES);
goto FAILURE;
}

/*:374*/
#line 3201 "./marpa.w"

/*1314:*/
#line 15634 "./marpa.w"

if(_MARPA_UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1314*/
#line 3202 "./marpa.w"

/*376:*/
#line 3336 "./marpa.w"

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
#line 3203 "./marpa.w"





MARPA_OFF_DEBUG3("At %s, ahm count is %ld",STRLOC,(long)(g->t_ahm_count));

/*122:*/
#line 1134 "./marpa.w"

{
_marpa_avl_destroy((g)->t_xrl_tree);
(g)->t_xrl_tree= NULL;
}
/*:122*/
#line 3210 "./marpa.w"




{
/*382:*/
#line 3537 "./marpa.w"

Bit_Vector terminal_v= NULL;

/*:382*//*383:*/
#line 3540 "./marpa.w"

Bit_Vector lhs_v= NULL;
Bit_Vector empty_lhs_v= NULL;

/*:383*//*384:*/
#line 3545 "./marpa.w"

RULEID**xrl_list_x_rh_sym= NULL;
RULEID**xrl_list_x_lh_sym= NULL;

/*:384*//*388:*/
#line 3604 "./marpa.w"

Bit_Vector productive_v= NULL;
Bit_Vector nullable_v= NULL;

/*:388*/
#line 3215 "./marpa.w"

/*372:*/
#line 3306 "./marpa.w"

{
/*380:*/
#line 3379 "./marpa.w"

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
#line 3308 "./marpa.w"

/*381:*/
#line 3506 "./marpa.w"

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
#line 3309 "./marpa.w"

/*389:*/
#line 3626 "./marpa.w"

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
#line 3310 "./marpa.w"

/*385:*/
#line 3549 "./marpa.w"

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
#line 3311 "./marpa.w"

/*386:*/
#line 3577 "./marpa.w"

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
#line 3312 "./marpa.w"

/*387:*/
#line 3598 "./marpa.w"

if(_MARPA_UNLIKELY(!bv_bit_test(productive_v,start_xsy_id)))
{
MARPA_ERROR(MARPA_ERR_UNPRODUCTIVE_START);
goto FAILURE;
}
/*:387*/
#line 3313 "./marpa.w"

/*391:*/
#line 3663 "./marpa.w"

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
#line 3314 "./marpa.w"

/*392:*/
#line 3683 "./marpa.w"

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
#line 3315 "./marpa.w"

/*393:*/
#line 3722 "./marpa.w"

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
#line 3773 "./marpa.w"

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
#line 3733 "./marpa.w"

continue;
}
/*394:*/
#line 3742 "./marpa.w"

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
#line 3736 "./marpa.w"

}
}

/*:393*/
#line 3316 "./marpa.w"

/*396:*/
#line 3838 "./marpa.w"

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
#line 3317 "./marpa.w"

/*397:*/
#line 3867 "./marpa.w"

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
#line 3318 "./marpa.w"

}

/*:372*/
#line 3216 "./marpa.w"

/*448:*/
#line 4742 "./marpa.w"

{
int loop_rule_count= 0;
Bit_Matrix unit_transition_matrix= 
matrix_obs_create(obs_precompute,xrl_count,
xrl_count);
/*449:*/
#line 4763 "./marpa.w"

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
#line 4818 "./marpa.w"

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
#line 4791 "./marpa.w"

}
else if(nonnullable_count==0)
{
for(rhs_ix= 0;rhs_ix<rule_length;rhs_ix++)
{




nonnullable_id= RHS_ID_of_RULE(rule,rhs_ix);

if(XSY_is_Nulling(XSY_by_ID(nonnullable_id)))
continue;



/*450:*/
#line 4818 "./marpa.w"

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
#line 4809 "./marpa.w"

}
}
}
}

/*:449*/
#line 4748 "./marpa.w"

transitive_closure(unit_transition_matrix);
/*451:*/
#line 4832 "./marpa.w"

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
#line 4750 "./marpa.w"

if(loop_rule_count)
{
g->t_has_cycle= 1;
int_event_new(g,MARPA_EVENT_LOOP_RULES,loop_rule_count);
}
}

/*:448*/
#line 3217 "./marpa.w"

}



/*515:*/
#line 5430 "./marpa.w"

MARPA_DSTACK_INIT(g->t_irl_stack,IRL,2*MARPA_DSTACK_CAPACITY(g->t_xrl_stack));

/*:515*/
#line 3222 "./marpa.w"

/*516:*/
#line 5438 "./marpa.w"

{
MARPA_DSTACK_INIT(g->t_nsy_stack,NSY,2*MARPA_DSTACK_CAPACITY(g->t_xsy_stack));
}

/*:516*/
#line 3223 "./marpa.w"

/*413:*/
#line 4089 "./marpa.w"

{
/*414:*/
#line 4120 "./marpa.w"

Marpa_Rule_ID rule_id;
int pre_chaf_rule_count;

/*:414*//*417:*/
#line 4178 "./marpa.w"

int factor_count;
int*factor_positions;
/*:417*/
#line 4091 "./marpa.w"

/*418:*/
#line 4181 "./marpa.w"

factor_positions= marpa_obs_new(obs_precompute,int,g->t_max_rule_length);

/*:418*/
#line 4092 "./marpa.w"

/*415:*/
#line 4126 "./marpa.w"

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
#line 4093 "./marpa.w"

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
#line 3920 "./marpa.w"

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
#line 3949 "./marpa.w"

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
#line 3941 "./marpa.w"

if(separator_nsyid>=0&&!XRL_is_Proper_Separation(rule)){
/*400:*/
#line 3962 "./marpa.w"

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
#line 3943 "./marpa.w"

}
/*401:*/
#line 3979 "./marpa.w"

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
#line 3945 "./marpa.w"

/*402:*/
#line 3990 "./marpa.w"

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
#line 3946 "./marpa.w"

}

/*:398*/
#line 4106 "./marpa.w"

continue;
}
/*416:*/
#line 4157 "./marpa.w"

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
#line 4109 "./marpa.w"


if(factor_count> 0)
{
/*419:*/
#line 4185 "./marpa.w"

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
#line 4221 "./marpa.w"

NSY chaf_virtual_nsy;
NSYID chaf_virtual_nsyid;
int first_factor_position= factor_positions[factor_position_ix];
int second_factor_position= factor_positions[factor_position_ix+1];
if(second_factor_position>=nullable_suffix_ix){
piece_end= second_factor_position-1;



/*420:*/
#line 4211 "./marpa.w"

{
const XSYID chaf_xrl_lhs_id= LHS_ID_of_XRL(chaf_xrl);
chaf_virtual_nsy= nsy_new(g,XSY_by_ID(chaf_xrl_lhs_id));
chaf_virtual_nsyid= ID_of_NSY(chaf_virtual_nsy);
}

/*:420*/
#line 4231 "./marpa.w"

/*423:*/
#line 4250 "./marpa.w"

{
{
const int real_symbol_count= piece_end-piece_start+1;
/*428:*/
#line 4348 "./marpa.w"

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
#line 4651 "./marpa.w"

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
#line 4362 "./marpa.w"

}

/*:428*/
#line 4254 "./marpa.w"
;
}
/*424:*/
#line 4264 "./marpa.w"

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
#line 4651 "./marpa.w"

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
#line 4286 "./marpa.w"

}

/*:424*/
#line 4256 "./marpa.w"
;
{
const int real_symbol_count= piece_end-piece_start+1;
/*430:*/
#line 4394 "./marpa.w"

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
#line 4651 "./marpa.w"

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
#line 4418 "./marpa.w"

}

/*:430*/
#line 4259 "./marpa.w"
;
}
/*425:*/
#line 4294 "./marpa.w"

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
#line 4651 "./marpa.w"

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
#line 4332 "./marpa.w"

}
}

/*:425*/
#line 4261 "./marpa.w"
;
}

/*:423*/
#line 4232 "./marpa.w"

factor_position_ix++;
}else{
piece_end= second_factor_position;
/*420:*/
#line 4211 "./marpa.w"

{
const XSYID chaf_xrl_lhs_id= LHS_ID_of_XRL(chaf_xrl);
chaf_virtual_nsy= nsy_new(g,XSY_by_ID(chaf_xrl_lhs_id));
chaf_virtual_nsyid= ID_of_NSY(chaf_virtual_nsy);
}

/*:420*/
#line 4236 "./marpa.w"

/*427:*/
#line 4338 "./marpa.w"

{
const int real_symbol_count= piece_end-piece_start+1;
/*428:*/
#line 4348 "./marpa.w"

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
#line 4651 "./marpa.w"

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
#line 4362 "./marpa.w"

}

/*:428*/
#line 4341 "./marpa.w"

/*429:*/
#line 4366 "./marpa.w"

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
#line 4651 "./marpa.w"

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
#line 4390 "./marpa.w"

}

/*:429*/
#line 4342 "./marpa.w"

/*430:*/
#line 4394 "./marpa.w"

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
#line 4651 "./marpa.w"

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
#line 4418 "./marpa.w"

}

/*:430*/
#line 4343 "./marpa.w"

/*431:*/
#line 4422 "./marpa.w"

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
#line 4651 "./marpa.w"

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
#line 4456 "./marpa.w"

}

/*:431*/
#line 4344 "./marpa.w"

}

/*:427*/
#line 4237 "./marpa.w"

factor_position_ix+= 2;
}
current_lhs_nsy= chaf_virtual_nsy;
current_lhs_nsyid= chaf_virtual_nsyid;
piece_start= piece_end+1;

/*:422*/
#line 4202 "./marpa.w"

}
if(unprocessed_factor_count==2){
/*432:*/
#line 4461 "./marpa.w"

{
const int first_factor_position= factor_positions[factor_position_ix];
const int second_factor_position= factor_positions[factor_position_ix+1];
const int real_symbol_count= Length_of_XRL(rule)-piece_start;
piece_end= Length_of_XRL(rule)-1;
/*433:*/
#line 4474 "./marpa.w"

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
#line 4651 "./marpa.w"

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
#line 4487 "./marpa.w"

}

/*:433*/
#line 4467 "./marpa.w"

/*434:*/
#line 4491 "./marpa.w"

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
#line 4651 "./marpa.w"

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
#line 4514 "./marpa.w"

}

/*:434*/
#line 4468 "./marpa.w"

/*435:*/
#line 4518 "./marpa.w"

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
#line 4651 "./marpa.w"

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
#line 4541 "./marpa.w"

}

/*:435*/
#line 4469 "./marpa.w"

/*436:*/
#line 4546 "./marpa.w"

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
#line 4651 "./marpa.w"

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
#line 4583 "./marpa.w"

}
}

/*:436*/
#line 4470 "./marpa.w"

}

/*:432*/
#line 4205 "./marpa.w"

}else{
/*437:*/
#line 4588 "./marpa.w"

{
int real_symbol_count;
const int first_factor_position= factor_positions[factor_position_ix];
piece_end= Length_of_XRL(rule)-1;
real_symbol_count= piece_end-piece_start+1;
/*438:*/
#line 4599 "./marpa.w"

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
#line 4651 "./marpa.w"

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
#line 4612 "./marpa.w"

}

/*:438*/
#line 4594 "./marpa.w"

/*439:*/
#line 4617 "./marpa.w"

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
#line 4651 "./marpa.w"

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
#line 4643 "./marpa.w"

}
}

/*:439*/
#line 4595 "./marpa.w"

}

/*:437*/
#line 4207 "./marpa.w"

}
}

/*:419*/
#line 4113 "./marpa.w"

continue;
}
/*260:*/
#line 2272 "./marpa.w"

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
#line 4116 "./marpa.w"

}
}

/*:413*/
#line 3224 "./marpa.w"

/*442:*/
#line 4669 "./marpa.w"

{
const XSY start_xsy= XSY_by_ID(start_xsy_id);
if(_MARPA_LIKELY(!XSY_is_Nulling(start_xsy))){
/*443:*/
#line 4677 "./marpa.w"
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
#line 4673 "./marpa.w"

}
}

/*:442*/
#line 3225 "./marpa.w"

post_census_xsy_count= XSY_Count_of_G(g);
/*527:*/
#line 5627 "./marpa.w"

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

/*:527*/
#line 3227 "./marpa.w"




if(!G_is_Trivial(g)){
/*514:*/
#line 5421 "./marpa.w"

const RULEID irl_count= IRL_Count_of_G(g);
const NSYID nsy_count= NSY_Count_of_G(g);
Bit_Matrix nsy_by_right_nsy_matrix;
Bit_Matrix prediction_nsy_by_irl_matrix;

/*:514*/
#line 3233 "./marpa.w"

/*517:*/
#line 5443 "./marpa.w"

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

/*:517*/
#line 3234 "./marpa.w"

/*488:*/
#line 5077 "./marpa.w"

{
IRLID irl_id;
int ahm_count= 0;
AHM base_item;
AHM current_item;
int symbol_instance_of_next_rule= 0;
for(irl_id= 0;irl_id<irl_count;irl_id++){
const IRL irl= IRL_by_ID(irl_id);
/*490:*/
#line 5130 "./marpa.w"

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

/*:490*/
#line 5086 "./marpa.w"

}
current_item= base_item= marpa_new(struct s_ahm,ahm_count);
for(irl_id= 0;irl_id<irl_count;irl_id++){
const IRL irl= IRL_by_ID(irl_id);
SYMI_of_IRL(irl)= symbol_instance_of_next_rule;
/*489:*/
#line 5105 "./marpa.w"

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
/*491:*/
#line 5142 "./marpa.w"

{
/*493:*/
#line 5165 "./marpa.w"

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
/*508:*/
#line 5318 "./marpa.w"

Event_AHMIDs_of_AHM(current_item)= NULL;
Event_Group_Size_of_AHM(current_item)= 0;

/*:508*/
#line 5183 "./marpa.w"

}

/*:493*/
#line 5144 "./marpa.w"

AHM_predicts_ZWA(current_item)= 0;

Postdot_NSYID_of_AHM(current_item)= rh_nsyid;
Position_of_AHM(current_item)= rhs_ix;
SYMI_of_AHM(current_item)
= AHM_is_Prediction(current_item)
?-1
:SYMI_of_IRL(irl)+Position_of_AHM(current_item-1);
memoize_xrl_data_for_AHM(current_item,irl);
}

/*:491*/
#line 5116 "./marpa.w"

current_item++;
leading_nulls= 0;
}
else
{
leading_nulls++;
}
}
/*492:*/
#line 5156 "./marpa.w"

{
/*493:*/
#line 5165 "./marpa.w"

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
/*508:*/
#line 5318 "./marpa.w"

Event_AHMIDs_of_AHM(current_item)= NULL;
Event_Group_Size_of_AHM(current_item)= 0;

/*:508*/
#line 5183 "./marpa.w"

}

/*:493*/
#line 5158 "./marpa.w"

Postdot_NSYID_of_AHM(current_item)= -1;
Position_of_AHM(current_item)= -1;
SYMI_of_AHM(current_item)= SYMI_of_IRL(irl)+Position_of_AHM(current_item-1);
memoize_xrl_data_for_AHM(current_item,irl);
}

/*:492*/
#line 5125 "./marpa.w"

current_item++;
AHM_Count_of_IRL(irl)= (int)(current_item-first_ahm_of_irl);
}

/*:489*/
#line 5092 "./marpa.w"

{
symbol_instance_of_next_rule+= Length_of_IRL(irl);
}
}
SYMI_Count_of_G(g)= symbol_instance_of_next_rule;
MARPA_ASSERT(ahm_count==current_item-base_item);
AHM_Count_of_G(g)= ahm_count;
MARPA_DEBUG3("At %s, Setting debug count to %ld",STRLOC,(long)ahm_count);
g->t_ahms= marpa_renew(struct s_ahm,base_item,ahm_count);
/*496:*/
#line 5236 "./marpa.w"

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

/*:496*/
#line 5102 "./marpa.w"

}

/*:488*/
#line 3235 "./marpa.w"

/*520:*/
#line 5496 "./marpa.w"
{
Bit_Matrix prediction_nsy_by_nsy_matrix= 
matrix_obs_create(obs_precompute,nsy_count,nsy_count);
/*521:*/
#line 5504 "./marpa.w"

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

/*:521*/
#line 5499 "./marpa.w"

transitive_closure(prediction_nsy_by_nsy_matrix);
/*522:*/
#line 5541 "./marpa.w"
{
/*523:*/
#line 5545 "./marpa.w"

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

/*:523*/
#line 5542 "./marpa.w"

}

/*:522*/
#line 5501 "./marpa.w"

}

/*:520*/
#line 3236 "./marpa.w"

/*510:*/
#line 5331 "./marpa.w"
{
nsy_by_right_nsy_matrix= 
matrix_obs_create(obs_precompute,nsy_count,nsy_count);
/*511:*/
#line 5342 "./marpa.w"

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

/*:511*/
#line 5334 "./marpa.w"

transitive_closure(nsy_by_right_nsy_matrix);
/*512:*/
#line 5367 "./marpa.w"

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

/*:512*/
#line 5336 "./marpa.w"

matrix_clear(nsy_by_right_nsy_matrix);
/*513:*/
#line 5394 "./marpa.w"

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

/*:513*/
#line 5338 "./marpa.w"

transitive_closure(nsy_by_right_nsy_matrix);
}

/*:510*/
#line 3237 "./marpa.w"

/*525:*/
#line 5582 "./marpa.w"

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

/*:525*/
#line 3238 "./marpa.w"

/*526:*/
#line 5606 "./marpa.w"

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

/*:526*/
#line 3239 "./marpa.w"

/*528:*/
#line 5671 "./marpa.w"

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

/*:528*/
#line 3241 "./marpa.w"

/*529:*/
#line 5737 "./marpa.w"

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

/*:529*/
#line 3242 "./marpa.w"

/*530:*/
#line 5753 "./marpa.w"

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

/*:530*/
#line 3243 "./marpa.w"

/*549:*/
#line 5958 "./marpa.w"

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

/*:549*/
#line 3244 "./marpa.w"

/*550:*/
#line 6003 "./marpa.w"

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

/*:550*/
#line 3245 "./marpa.w"

}
g->t_is_precomputed= 1;
if(g->t_has_cycle)
{
MARPA_ERROR(MARPA_ERR_GRAMMAR_HAS_CYCLE);
goto FAILURE;
}
/*369:*/
#line 3267 "./marpa.w"

{cilar_buffer_reinit(&g->t_cilar);}
/*:369*/
#line 3253 "./marpa.w"

return_value= 0;
goto CLEANUP;
FAILURE:;
goto CLEANUP;
CLEANUP:;
marpa_obs_free(obs_precompute);
return return_value;
}

/*:368*//*379:*/
#line 3366 "./marpa.w"

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
#line 4078 "./marpa.w"

int _marpa_g_irl_is_chaf(
Marpa_Grammar g,
Marpa_IRL_ID irl_id)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 4083 "./marpa.w"

/*1315:*/
#line 15640 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1315*/
#line 4084 "./marpa.w"

/*1322:*/
#line 15681 "./marpa.w"

if(_MARPA_UNLIKELY(!IRLID_of_G_is_Valid(irl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_IRLID);
return failure_indicator;
}
/*:1322*/
#line 4085 "./marpa.w"

return IRL_is_CHAF(IRL_by_ID(irl_id));
}

/*:412*//*462:*/
#line 4896 "./marpa.w"

PRIVATE int ahm_is_valid(
GRAMMAR g,AHMID item_id)
{
return item_id<(AHMID)AHM_Count_of_G(g)&&item_id>=0;
}

/*:462*//*479:*/
#line 5022 "./marpa.w"

int _marpa_g_ahm_count(Marpa_Grammar g){
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 5024 "./marpa.w"

/*1315:*/
#line 15640 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1315*/
#line 5025 "./marpa.w"

return AHM_Count_of_G(g);
}

/*:479*//*480:*/
#line 5029 "./marpa.w"

Marpa_IRL_ID _marpa_g_ahm_irl(Marpa_Grammar g,
Marpa_AHM_ID item_id){
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 5032 "./marpa.w"

/*1315:*/
#line 15640 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1315*/
#line 5033 "./marpa.w"

/*1328:*/
#line 15724 "./marpa.w"

if(_MARPA_UNLIKELY(!ahm_is_valid(g,item_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AIMID);
return failure_indicator;
}

/*:1328*/
#line 5034 "./marpa.w"

return IRLID_of_AHM(AHM_by_ID(item_id));
}

/*:480*//*482:*/
#line 5039 "./marpa.w"

int _marpa_g_ahm_position(Marpa_Grammar g,
Marpa_AHM_ID item_id){
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 5042 "./marpa.w"

/*1315:*/
#line 15640 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1315*/
#line 5043 "./marpa.w"

/*1328:*/
#line 15724 "./marpa.w"

if(_MARPA_UNLIKELY(!ahm_is_valid(g,item_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AIMID);
return failure_indicator;
}

/*:1328*/
#line 5044 "./marpa.w"

return Position_of_AHM(AHM_by_ID(item_id));
}

/*:482*//*483:*/
#line 5048 "./marpa.w"

int _marpa_g_ahm_raw_position(Marpa_Grammar g,
Marpa_AHM_ID item_id){
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 5051 "./marpa.w"

/*1315:*/
#line 15640 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1315*/
#line 5052 "./marpa.w"

/*1328:*/
#line 15724 "./marpa.w"

if(_MARPA_UNLIKELY(!ahm_is_valid(g,item_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AIMID);
return failure_indicator;
}

/*:1328*/
#line 5053 "./marpa.w"

return Raw_Position_of_AHM(AHM_by_ID(item_id));
}

/*:483*//*484:*/
#line 5057 "./marpa.w"

int _marpa_g_ahm_null_count(Marpa_Grammar g,
Marpa_AHM_ID item_id){
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 5060 "./marpa.w"

/*1315:*/
#line 15640 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1315*/
#line 5061 "./marpa.w"

/*1328:*/
#line 15724 "./marpa.w"

if(_MARPA_UNLIKELY(!ahm_is_valid(g,item_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AIMID);
return failure_indicator;
}

/*:1328*/
#line 5062 "./marpa.w"

return Null_Count_of_AHM(AHM_by_ID(item_id));
}

/*:484*//*486:*/
#line 5067 "./marpa.w"

Marpa_Symbol_ID _marpa_g_ahm_postdot(Marpa_Grammar g,
Marpa_AHM_ID item_id){
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 5070 "./marpa.w"

/*1315:*/
#line 15640 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1315*/
#line 5071 "./marpa.w"

/*1328:*/
#line 15724 "./marpa.w"

if(_MARPA_UNLIKELY(!ahm_is_valid(g,item_id))){
MARPA_ERROR(MARPA_ERR_INVALID_AIMID);
return failure_indicator;
}

/*:1328*/
#line 5072 "./marpa.w"

return Postdot_NSYID_of_AHM(AHM_by_ID(item_id));
}

/*:486*//*494:*/
#line 5186 "./marpa.w"

PRIVATE void
memoize_xrl_data_for_AHM(AHM current_item,IRL irl)
{
XRL source_xrl= Source_XRL_of_IRL(irl);
XRL_of_AHM(current_item)= source_xrl;
if(!source_xrl){


XRL_Position_of_AHM(current_item)= -2;
return;
}
{
const int virtual_start= Virtual_Start_of_IRL(irl);
const int irl_position= Position_of_AHM(current_item);
if(XRL_is_Sequence(source_xrl))
{




XRL_Position_of_AHM(current_item)= irl_position?-1:0;
return;
}


if(IRL_is_CHAF(irl)&&
(irl_position<0||irl_position>=Length_of_IRL(irl)))
{
XRL_Position_of_AHM(current_item)= -1;
return;
}
if(virtual_start>=0)
{
XRL_Position_of_AHM(current_item)= irl_position+virtual_start;
return;
}
XRL_Position_of_AHM(current_item)= irl_position;
}
return;
}

/*:494*//*545:*/
#line 5868 "./marpa.w"

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

/*:545*//*546:*/
#line 5883 "./marpa.w"

Marpa_Assertion_ID
marpa_g_zwa_new(Marpa_Grammar g,int default_value)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 5887 "./marpa.w"

ZWAID zwa_id;
GZWA gzwa;
/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 5890 "./marpa.w"

/*1314:*/
#line 15634 "./marpa.w"

if(_MARPA_UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1314*/
#line 5891 "./marpa.w"

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

/*:546*//*547:*/
#line 5905 "./marpa.w"

Marpa_Assertion_ID
marpa_g_highest_zwa_id(Marpa_Grammar g)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 5909 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 5910 "./marpa.w"

return ZWA_Count_of_G(g)-1;
}

/*:547*//*548:*/
#line 5917 "./marpa.w"

int
marpa_g_zwa_place(Marpa_Grammar g,
Marpa_Assertion_ID zwaid,
Marpa_Rule_ID xrl_id,int rhs_ix)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 5923 "./marpa.w"

void*avl_insert_result;
ZWP zwp;
XRL xrl;
int xrl_length;
/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 5928 "./marpa.w"

/*1314:*/
#line 15634 "./marpa.w"

if(_MARPA_UNLIKELY(G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_PRECOMPUTED);
return failure_indicator;
}

/*:1314*/
#line 5929 "./marpa.w"

/*1325:*/
#line 15701 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}

/*:1325*/
#line 5930 "./marpa.w"

/*1323:*/
#line 15689 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}

/*:1323*/
#line 5931 "./marpa.w"

/*1327:*/
#line 15713 "./marpa.w"

if(_MARPA_UNLIKELY(ZWAID_is_Malformed(zwaid))){
MARPA_ERROR(MARPA_ERR_INVALID_ASSERTION_ID);
return failure_indicator;
}

/*:1327*/
#line 5932 "./marpa.w"

/*1326:*/
#line 15707 "./marpa.w"

if(_MARPA_UNLIKELY(!ZWAID_of_G_Exists(zwaid))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_ASSERTION_ID);
return failure_indicator;
}
/*:1326*/
#line 5933 "./marpa.w"

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

/*:548*//*554:*/
#line 6049 "./marpa.w"

Marpa_Recognizer marpa_r_new(Marpa_Grammar g)
{
RECCE r;
int nsy_count;
int irl_count;
/*1312:*/
#line 15626 "./marpa.w"
void*const failure_indicator= NULL;
/*:1312*/
#line 6055 "./marpa.w"

/*1315:*/
#line 15640 "./marpa.w"

if(_MARPA_UNLIKELY(!G_is_Precomputed(g))){
MARPA_ERROR(MARPA_ERR_NOT_PRECOMPUTED);
return failure_indicator;
}
/*:1315*/
#line 6056 "./marpa.w"

nsy_count= NSY_Count_of_G(g);
irl_count= IRL_Count_of_G(g);
r= my_malloc(sizeof(struct marpa_r));
/*619:*/
#line 6659 "./marpa.w"
r->t_obs= marpa_obs_init;
/*:619*/
#line 6060 "./marpa.w"

/*557:*/
#line 6069 "./marpa.w"

r->t_ref_count= 1;

/*:557*//*562:*/
#line 6120 "./marpa.w"

{
G_of_R(r)= g;
grammar_ref(g);
}
/*:562*//*567:*/
#line 6139 "./marpa.w"

Input_Phase_of_R(r)= R_BEFORE_INPUT;

/*:567*//*569:*/
#line 6149 "./marpa.w"

r->t_first_earley_set= NULL;
r->t_latest_earley_set= NULL;
r->t_current_earleme= -1;

/*:569*//*573:*/
#line 6183 "./marpa.w"

r->t_earley_item_warning_threshold= 
MAX(DEFAULT_YIM_WARNING_THRESHOLD,AHM_Count_of_G(g)*3);
/*:573*//*577:*/
#line 6212 "./marpa.w"
r->t_furthest_earleme= 0;
/*:577*//*584:*/
#line 6254 "./marpa.w"

r->t_bv_nsyid_is_expected= bv_obs_create(r->t_obs,nsy_count);
/*:584*//*588:*/
#line 6331 "./marpa.w"

r->t_nsy_expected_is_event= lbv_obs_new0(r->t_obs,nsy_count);
/*:588*//*606:*/
#line 6574 "./marpa.w"

r->t_use_leo_flag= 1;
r->t_is_using_leo= 0;
/*:606*//*610:*/
#line 6607 "./marpa.w"

r->t_bv_irl_seen= bv_obs_create(r->t_obs,irl_count);
MARPA_DSTACK_INIT2(r->t_irl_cil_stack,CIL);
/*:610*//*613:*/
#line 6624 "./marpa.w"
r->t_is_exhausted= 0;
/*:613*//*617:*/
#line 6652 "./marpa.w"
r->t_first_inconsistent_ys= -1;

/*:617*//*623:*/
#line 6681 "./marpa.w"

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

/*:623*//*638:*/
#line 6775 "./marpa.w"

r->t_earley_set_count= 0;

/*:638*//*705:*/
#line 7578 "./marpa.w"

MARPA_DSTACK_INIT2(r->t_alternatives,ALT_Object);
/*:705*//*730:*/
#line 8076 "./marpa.w"
MARPA_DSTACK_SAFE(r->t_yim_work_stack);
/*:730*//*734:*/
#line 8091 "./marpa.w"
MARPA_DSTACK_SAFE(r->t_completion_stack);
/*:734*//*738:*/
#line 8102 "./marpa.w"
MARPA_DSTACK_SAFE(r->t_earley_set_stack);
/*:738*//*829:*/
#line 9635 "./marpa.w"

r->t_current_report_item= &progress_report_not_ready;
r->t_progress_report_traverser= NULL;
/*:829*//*863:*/
#line 10070 "./marpa.w"

ur_node_stack_init(URS_of_R(r));
/*:863*//*1345:*/
#line 15907 "./marpa.w"

r->t_trace_earley_set= NULL;

/*:1345*//*1352:*/
#line 15983 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:1352*//*1366:*/
#line 16183 "./marpa.w"

r->t_trace_pim_nsy_p= NULL;
r->t_trace_postdot_item= NULL;
/*:1366*//*1374:*/
#line 16333 "./marpa.w"

r->t_trace_source_link= NULL;
r->t_trace_source_type= NO_SOURCE;

/*:1374*/
#line 6061 "./marpa.w"

/*1294:*/
#line 15439 "./marpa.w"

{
if(G_is_Trivial(g)){
psar_safe(Dot_PSAR_of_R(r));
}else{
psar_init(Dot_PSAR_of_R(r),AHM_Count_of_G(g));
}
}
/*:1294*/
#line 6062 "./marpa.w"

/*582:*/
#line 6234 "./marpa.w"

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

/*:582*/
#line 6063 "./marpa.w"

return r;
}

/*:554*//*558:*/
#line 6073 "./marpa.w"

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

/*:558*//*559:*/
#line 6091 "./marpa.w"

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

/*:559*//*560:*/
#line 6105 "./marpa.w"

PRIVATE
void recce_free(struct marpa_r*r)
{
/*563:*/
#line 6125 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:563*/
#line 6109 "./marpa.w"

/*564:*/
#line 6127 "./marpa.w"
grammar_unref(g);

/*:564*//*611:*/
#line 6610 "./marpa.w"

MARPA_DSTACK_DESTROY(r->t_irl_cil_stack);

/*:611*//*706:*/
#line 7580 "./marpa.w"
MARPA_DSTACK_DESTROY(r->t_alternatives);

/*:706*//*732:*/
#line 8084 "./marpa.w"
MARPA_DSTACK_DESTROY(r->t_yim_work_stack);

/*:732*//*736:*/
#line 8099 "./marpa.w"
MARPA_DSTACK_DESTROY(r->t_completion_stack);

/*:736*//*739:*/
#line 8103 "./marpa.w"
MARPA_DSTACK_DESTROY(r->t_earley_set_stack);

/*:739*//*831:*/
#line 9644 "./marpa.w"

/*830:*/
#line 9638 "./marpa.w"

r->t_current_report_item= &progress_report_not_ready;
if(r->t_progress_report_traverser){
_marpa_avl_destroy(MARPA_TREE_OF_AVL_TRAV(r->t_progress_report_traverser));
}
r->t_progress_report_traverser= NULL;
/*:830*/
#line 9645 "./marpa.w"
;
/*:831*//*864:*/
#line 10072 "./marpa.w"

ur_node_stack_destroy(URS_of_R(r));

/*:864*//*1295:*/
#line 15447 "./marpa.w"

psar_destroy(Dot_PSAR_of_R(r));
/*:1295*/
#line 6110 "./marpa.w"

/*620:*/
#line 6660 "./marpa.w"
marpa_obs_free(r->t_obs);

/*:620*/
#line 6111 "./marpa.w"

my_free(r);
}

/*:560*//*570:*/
#line 6157 "./marpa.w"

Marpa_Earleme marpa_r_current_earleme(Marpa_Recognizer r)
{
/*563:*/
#line 6125 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:563*/
#line 6160 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return-1;
}
return Current_Earleme_of_R(r);
}

/*:570*//*571:*/
#line 6172 "./marpa.w"

PRIVATE YS ys_at_current_earleme(RECCE r)
{
const YS latest= Latest_YS_of_R(r);
if(Earleme_of_YS(latest)==Current_Earleme_of_R(r))return latest;
return NULL;
}

/*:571*//*574:*/
#line 6186 "./marpa.w"

int
marpa_r_earley_item_warning_threshold(Marpa_Recognizer r)
{
return r->t_earley_item_warning_threshold;
}

/*:574*//*575:*/
#line 6195 "./marpa.w"

int
marpa_r_earley_item_warning_threshold_set(Marpa_Recognizer r,int threshold)
{
const int new_threshold= threshold<=0?YIM_FATAL_THRESHOLD:threshold;
r->t_earley_item_warning_threshold= new_threshold;
return new_threshold;
}

/*:575*//*578:*/
#line 6213 "./marpa.w"

unsigned int marpa_r_furthest_earleme(Marpa_Recognizer r)
{return(unsigned int)Furthest_Earleme_of_R(r);}

/*:578*//*585:*/
#line 6262 "./marpa.w"

int marpa_r_terminals_expected(Marpa_Recognizer r,Marpa_Symbol_ID*buffer)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 6265 "./marpa.w"

/*563:*/
#line 6125 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:563*/
#line 6266 "./marpa.w"

NSYID xsy_count;
Bit_Vector bv_terminals;
int min,max,start;
int next_buffer_ix= 0;

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 6272 "./marpa.w"

/*1330:*/
#line 15738 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1330*/
#line 6273 "./marpa.w"


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

/*:585*//*586:*/
#line 6300 "./marpa.w"

int marpa_r_terminal_is_expected(Marpa_Recognizer r,
Marpa_Symbol_ID xsy_id)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 6304 "./marpa.w"

/*563:*/
#line 6125 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:563*/
#line 6305 "./marpa.w"

XSY xsy;
NSY nsy;
/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 6308 "./marpa.w"

/*1330:*/
#line 15738 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1330*/
#line 6309 "./marpa.w"

/*1316:*/
#line 15645 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1316*/
#line 6310 "./marpa.w"

/*1318:*/
#line 15657 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return failure_indicator;
}

/*:1318*/
#line 6311 "./marpa.w"

xsy= XSY_by_ID(xsy_id);
if(_MARPA_UNLIKELY(!XSY_is_Terminal(xsy))){
return 0;
}
nsy= NSY_of_XSY(xsy);
if(_MARPA_UNLIKELY(!nsy))return 0;
return bv_bit_test(r->t_bv_nsyid_is_expected,ID_of_NSY(nsy));
}

/*:586*//*589:*/
#line 6334 "./marpa.w"

int
marpa_r_expected_symbol_event_set(Marpa_Recognizer r,Marpa_Symbol_ID xsy_id,
int value)
{
XSY xsy;
NSY nsy;
NSYID nsyid;
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 6342 "./marpa.w"

/*563:*/
#line 6125 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:563*/
#line 6343 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 6344 "./marpa.w"

/*1316:*/
#line 15645 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1316*/
#line 6345 "./marpa.w"

/*1317:*/
#line 15652 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1317*/
#line 6346 "./marpa.w"

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

/*:589*//*591:*/
#line 6385 "./marpa.w"

int
marpa_r_completion_symbol_activate(Marpa_Recognizer r,
Marpa_Symbol_ID xsy_id,int reactivate)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 6390 "./marpa.w"

/*563:*/
#line 6125 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:563*/
#line 6391 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 6392 "./marpa.w"

/*1316:*/
#line 15645 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1316*/
#line 6393 "./marpa.w"

/*1317:*/
#line 15652 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1317*/
#line 6394 "./marpa.w"

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

/*:591*//*593:*/
#line 6432 "./marpa.w"

int
marpa_r_nulled_symbol_activate(Marpa_Recognizer r,Marpa_Symbol_ID xsy_id,
int reactivate)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 6437 "./marpa.w"

/*563:*/
#line 6125 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:563*/
#line 6438 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 6439 "./marpa.w"

/*1316:*/
#line 15645 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1316*/
#line 6440 "./marpa.w"

/*1317:*/
#line 15652 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1317*/
#line 6441 "./marpa.w"

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

/*:593*//*595:*/
#line 6479 "./marpa.w"

int
marpa_r_prediction_symbol_activate(Marpa_Recognizer r,
Marpa_Symbol_ID xsy_id,int reactivate)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 6484 "./marpa.w"

/*563:*/
#line 6125 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:563*/
#line 6485 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 6486 "./marpa.w"

/*1316:*/
#line 15645 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1316*/
#line 6487 "./marpa.w"

/*1317:*/
#line 15652 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1317*/
#line 6488 "./marpa.w"

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

/*:595*//*607:*/
#line 6580 "./marpa.w"

int _marpa_r_is_use_leo(Marpa_Recognizer r)
{
/*563:*/
#line 6125 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:563*/
#line 6583 "./marpa.w"

/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 6584 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 6585 "./marpa.w"

return r->t_use_leo_flag;
}
/*:607*//*608:*/
#line 6588 "./marpa.w"

int _marpa_r_is_use_leo_set(
Marpa_Recognizer r,int value)
{
/*563:*/
#line 6125 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:563*/
#line 6592 "./marpa.w"

/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 6593 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 6594 "./marpa.w"

/*1329:*/
#line 15733 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)!=R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_STARTED);
return failure_indicator;
}
/*:1329*/
#line 6595 "./marpa.w"

return r->t_use_leo_flag= value?1:0;
}

/*:608*//*615:*/
#line 6635 "./marpa.w"

int marpa_r_is_exhausted(Marpa_Recognizer r)
{
/*563:*/
#line 6125 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:563*/
#line 6638 "./marpa.w"

/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 6639 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 6640 "./marpa.w"

return R_is_Exhausted(r);
}

/*:615*//*642:*/
#line 6794 "./marpa.w"

int marpa_r_earley_set_value(Marpa_Recognizer r,Marpa_Earley_Set_ID set_id)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 6797 "./marpa.w"

YS earley_set;
/*563:*/
#line 6125 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:563*/
#line 6799 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 6800 "./marpa.w"

/*1330:*/
#line 15738 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1330*/
#line 6801 "./marpa.w"

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

/*:642*//*643:*/
#line 6817 "./marpa.w"

int
marpa_r_earley_set_values(Marpa_Recognizer r,Marpa_Earley_Set_ID set_id,
int*p_value,void**p_pvalue)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 6822 "./marpa.w"

YS earley_set;
/*563:*/
#line 6125 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:563*/
#line 6824 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 6825 "./marpa.w"

/*1330:*/
#line 15738 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1330*/
#line 6826 "./marpa.w"

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

/*:643*//*644:*/
#line 6844 "./marpa.w"

int marpa_r_latest_earley_set_value_set(Marpa_Recognizer r,int value)
{
YS earley_set;
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 6848 "./marpa.w"

/*563:*/
#line 6125 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:563*/
#line 6849 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 6850 "./marpa.w"

/*1330:*/
#line 15738 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1330*/
#line 6851 "./marpa.w"

earley_set= Latest_YS_of_R(r);
return Value_of_YS(earley_set)= value;
}

/*:644*//*645:*/
#line 6856 "./marpa.w"

int marpa_r_latest_earley_set_values_set(Marpa_Recognizer r,int value,
void*pvalue)
{
YS earley_set;
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 6861 "./marpa.w"

/*563:*/
#line 6125 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:563*/
#line 6862 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 6863 "./marpa.w"

/*1330:*/
#line 15738 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1330*/
#line 6864 "./marpa.w"

earley_set= Latest_YS_of_R(r);
Value_of_YS(earley_set)= value;
PValue_of_YS(earley_set)= pvalue;
return 1;
}

/*:645*//*646:*/
#line 6872 "./marpa.w"

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
/*641:*/
#line 6790 "./marpa.w"

Value_of_YS(set)= -1;
PValue_of_YS(set)= NULL;

/*:641*//*1301:*/
#line 15503 "./marpa.w"

{set->t_dot_psl= NULL;}

/*:1301*/
#line 6887 "./marpa.w"

return set;
}

/*:646*//*656:*/
#line 6997 "./marpa.w"

PRIVATE YIM earley_item_create(const RECCE r,
const YIK_Object key)
{
/*1312:*/
#line 15626 "./marpa.w"
void*const failure_indicator= NULL;
/*:1312*/
#line 7001 "./marpa.w"

/*563:*/
#line 6125 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:563*/
#line 7002 "./marpa.w"

YIM new_item;
YIM*end_of_work_stack;
const YS set= key.t_set;
const int count= ++YIM_Count_of_YS(set);
/*658:*/
#line 7056 "./marpa.w"

if(_MARPA_UNLIKELY(count>=YIM_FATAL_THRESHOLD))
{
MARPA_FATAL(MARPA_ERR_YIM_COUNT);
return failure_indicator;
}

/*:658*/
#line 7007 "./marpa.w"

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

/*:656*//*657:*/
#line 7024 "./marpa.w"

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

/*:657*//*662:*/
#line 7092 "./marpa.w"

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

/*:662*//*674:*/
#line 7213 "./marpa.w"

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
/*:674*//*675:*/
#line 7233 "./marpa.w"

PRIVATE PIM first_pim_of_ys_by_nsyid(YS set,NSYID nsyid)
{
PIM*pim_nsy_p= pim_nsy_p_find(set,nsyid);
return pim_nsy_p?*pim_nsy_p:NULL;
}

/*:675*//*693:*/
#line 7390 "./marpa.w"

PRIVATE
SRCL unique_srcl_new(struct marpa_obstack*t_obs)
{
const SRCL new_srcl= marpa_obs_new(t_obs,SRCL_Object,1);
SRCL_is_Rejected(new_srcl)= 0;
SRCL_is_Active(new_srcl)= 1;
return new_srcl;
}

/*:693*//*694:*/
#line 7400 "./marpa.w"
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

/*:694*//*695:*/
#line 7431 "./marpa.w"

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

/*:695*//*696:*/
#line 7461 "./marpa.w"

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

/*:696*//*698:*/
#line 7510 "./marpa.w"

PRIVATE_NOT_INLINE
void earley_item_ambiguate(struct marpa_r*r,YIM item)
{
unsigned int previous_source_type= Source_Type_of_YIM(item);
Source_Type_of_YIM(item)= SOURCE_IS_AMBIGUOUS;
switch(previous_source_type)
{
case SOURCE_IS_TOKEN:/*699:*/
#line 7527 "./marpa.w"
{
SRCL new_link= marpa_obs_new(r->t_obs,SRCL_Object,1);
*new_link= *SRCL_of_YIM(item);
LV_First_Leo_SRCL_of_YIM(item)= NULL;
LV_First_Completion_SRCL_of_YIM(item)= NULL;
LV_First_Token_SRCL_of_YIM(item)= new_link;
}

/*:699*/
#line 7518 "./marpa.w"

return;
case SOURCE_IS_COMPLETION:/*700:*/
#line 7535 "./marpa.w"
{
SRCL new_link= marpa_obs_new(r->t_obs,SRCL_Object,1);
*new_link= *SRCL_of_YIM(item);
LV_First_Leo_SRCL_of_YIM(item)= NULL;
LV_First_Completion_SRCL_of_YIM(item)= new_link;
LV_First_Token_SRCL_of_YIM(item)= NULL;
}

/*:700*/
#line 7520 "./marpa.w"

return;
case SOURCE_IS_LEO:/*701:*/
#line 7543 "./marpa.w"
{
SRCL new_link= marpa_obs_new(r->t_obs,SRCL_Object,1);
*new_link= *SRCL_of_YIM(item);
LV_First_Leo_SRCL_of_YIM(item)= new_link;
LV_First_Completion_SRCL_of_YIM(item)= NULL;
LV_First_Token_SRCL_of_YIM(item)= NULL;
}

/*:701*/
#line 7522 "./marpa.w"

return;
}
}

/*:698*//*708:*/
#line 7586 "./marpa.w"

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

/*:708*//*710:*/
#line 7630 "./marpa.w"

PRIVATE int alternative_cmp(const ALT_Const a,const ALT_Const b)
{
int subkey= End_Earleme_of_ALT(b)-End_Earleme_of_ALT(a);
if(subkey)return subkey;
subkey= NSYID_of_ALT(a)-NSYID_of_ALT(b);
if(subkey)return subkey;
return Start_Earleme_of_ALT(a)-Start_Earleme_of_ALT(b);
}

/*:710*//*711:*/
#line 7647 "./marpa.w"

PRIVATE ALT alternative_pop(RECCE r,JEARLEME earleme)
{
MARPA_DSTACK alternatives= &r->t_alternatives;
ALT end_of_stack= MARPA_DSTACK_TOP(*alternatives,ALT_Object);

if(!end_of_stack)return NULL;






if(earleme<End_Earleme_of_ALT(end_of_stack))
return NULL;

return MARPA_DSTACK_POP(*alternatives,ALT_Object);
}

/*:711*//*713:*/
#line 7674 "./marpa.w"

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

/*:713*//*714:*/
#line 7697 "./marpa.w"
int marpa_r_start_input(Marpa_Recognizer r)
{
int return_value= 1;
YS set0;
YIK_Object key;

IRL start_irl;
AHM start_ahm;

/*563:*/
#line 6125 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:563*/
#line 7706 "./marpa.w"

/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 7707 "./marpa.w"


/*1329:*/
#line 15733 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)!=R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_STARTED);
return failure_indicator;
}
/*:1329*/
#line 7709 "./marpa.w"

{
/*716:*/
#line 7827 "./marpa.w"

const NSYID nsy_count= NSY_Count_of_G(g);
const NSYID xsy_count= XSY_Count_of_G(g);
Bit_Vector bv_ok_for_chain= bv_create(nsy_count);
/*:716*/
#line 7711 "./marpa.w"

Current_Earleme_of_R(r)= 0;
/*722:*/
#line 7869 "./marpa.w"

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

/*:722*/
#line 7713 "./marpa.w"

G_EVENTS_CLEAR(g);

set0= earley_set_new(r,0);
Latest_YS_of_R(r)= set0;
First_YS_of_R(r)= set0;

if(G_is_Trivial(g)){
return_value+= trigger_trivial_events(r);
/*614:*/
#line 6625 "./marpa.w"

{
R_is_Exhausted(r)= 1;
Input_Phase_of_R(r)= R_AFTER_INPUT;
event_new(g,MARPA_EVENT_EXHAUSTED);
}

/*:614*/
#line 7722 "./marpa.w"

goto CLEANUP;
}
Input_Phase_of_R(r)= R_DURING_INPUT;
psar_reset(Dot_PSAR_of_R(r));
/*775:*/
#line 8735 "./marpa.w"

r->t_bv_lim_symbols= bv_obs_create(r->t_obs,nsy_count);
r->t_bv_pim_symbols= bv_obs_create(r->t_obs,nsy_count);
r->t_pim_workarea= marpa_obs_new(r->t_obs,void*,nsy_count);
/*:775*//*794:*/
#line 9017 "./marpa.w"

r->t_lim_chain= marpa_obs_new(r->t_obs,void*,2*nsy_count);
/*:794*/
#line 7727 "./marpa.w"

/*731:*/
#line 8077 "./marpa.w"

{
if(!MARPA_DSTACK_IS_INITIALIZED(r->t_yim_work_stack))
{
MARPA_DSTACK_INIT2(r->t_yim_work_stack,YIM);
}
}
/*:731*//*735:*/
#line 8092 "./marpa.w"

{
if(!MARPA_DSTACK_IS_INITIALIZED(r->t_completion_stack))
{
MARPA_DSTACK_INIT2(r->t_completion_stack,YIM);
}
}
/*:735*/
#line 7728 "./marpa.w"


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
/*717:*/
#line 7831 "./marpa.w"

bv_free(bv_ok_for_chain);

/*:717*/
#line 7780 "./marpa.w"

}
return return_value;
}

/*:714*//*715:*/
#line 7785 "./marpa.w"

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


/*:715*//*723:*/
#line 7909 "./marpa.w"

Marpa_Earleme marpa_r_alternative(
Marpa_Recognizer r,
Marpa_Symbol_ID tkn_xsy_id,
int value,
int length)
{
/*563:*/
#line 6125 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:563*/
#line 7916 "./marpa.w"

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
/*724:*/
#line 7948 "./marpa.w"
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

/*:724*/
#line 7941 "./marpa.w"

/*727:*/
#line 8008 "./marpa.w"

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

/*:727*/
#line 7942 "./marpa.w"

/*725:*/
#line 7988 "./marpa.w"
{
target_earleme= current_earleme+length;
if(target_earleme>=JEARLEME_THRESHOLD){
MARPA_ERROR(MARPA_ERR_PARSE_TOO_LONG);
return MARPA_ERR_PARSE_TOO_LONG;
}
}

/*:725*/
#line 7943 "./marpa.w"

/*728:*/
#line 8046 "./marpa.w"

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

/*:728*/
#line 7944 "./marpa.w"

return MARPA_ERR_NONE;
}

/*:723*//*741:*/
#line 8123 "./marpa.w"

int
marpa_r_earleme_complete(Marpa_Recognizer r)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 8127 "./marpa.w"

/*563:*/
#line 6125 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:563*/
#line 8128 "./marpa.w"

YIM*cause_p;
YS current_earley_set;
JEARLEME current_earleme;





JEARLEME return_value= -2;

/*1331:*/
#line 15743 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)!=R_DURING_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_ACCEPTING_INPUT);
return failure_indicator;
}

if(_MARPA_UNLIKELY(!R_is_Consistent(r))){
MARPA_ERROR(MARPA_ERR_RECCE_IS_INCONSISTENT);
return failure_indicator;
}

/*:1331*/
#line 8139 "./marpa.w"

if(_MARPA_UNLIKELY(!R_is_Consistent(r))){
MARPA_ERROR(MARPA_ERR_RECCE_IS_INCONSISTENT);
return failure_indicator;
}

{
int count_of_expected_terminals;
/*742:*/
#line 8189 "./marpa.w"

const NSYID nsy_count= NSY_Count_of_G(g);
Bit_Vector bv_ok_for_chain= bv_create(nsy_count);
struct marpa_obstack*const earleme_complete_obs= marpa_obs_init;
/*:742*/
#line 8147 "./marpa.w"

G_EVENTS_CLEAR(g);
psar_dealloc(Dot_PSAR_of_R(r));
bv_clear(r->t_bv_nsyid_is_expected);
bv_clear(r->t_bv_irl_seen);
/*744:*/
#line 8197 "./marpa.w"
{
current_earleme= ++(Current_Earleme_of_R(r));
if(current_earleme> Furthest_Earleme_of_R(r))
{
/*614:*/
#line 6625 "./marpa.w"

{
R_is_Exhausted(r)= 1;
Input_Phase_of_R(r)= R_AFTER_INPUT;
event_new(g,MARPA_EVENT_EXHAUSTED);
}

/*:614*/
#line 8201 "./marpa.w"

MARPA_ERROR(MARPA_ERR_PARSE_EXHAUSTED);
return_value= failure_indicator;
goto CLEANUP;
}
}

/*:744*/
#line 8152 "./marpa.w"

/*746:*/
#line 8220 "./marpa.w"
{
ALT end_of_stack= MARPA_DSTACK_TOP(r->t_alternatives,ALT_Object);
if(!end_of_stack||current_earleme!=End_Earleme_of_ALT(end_of_stack))
{
return_value= 0;
goto CLEANUP;
}
}

/*:746*/
#line 8153 "./marpa.w"

/*745:*/
#line 8210 "./marpa.w"
{
current_earley_set= earley_set_new(r,current_earleme);
Next_YS_of_YS(Latest_YS_of_R(r))= current_earley_set;
Latest_YS_of_R(r)= current_earley_set;
}

/*:745*/
#line 8154 "./marpa.w"

/*747:*/
#line 8229 "./marpa.w"

{
ALT alternative;


while((alternative= alternative_pop(r,current_earleme)))
/*749:*/
#line 8248 "./marpa.w"

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
/*750:*/
#line 8267 "./marpa.w"

{
const YIM scanned_earley_item= earley_item_assign(r,
current_earley_set,
Origin_of_YIM
(predecessor),
scanned_ahm);
YIM_was_Scanned(scanned_earley_item)= 1;
tkn_link_add(r,scanned_earley_item,predecessor,alternative);
}

/*:750*/
#line 8262 "./marpa.w"

}
}
}

/*:749*/
#line 8235 "./marpa.w"

}

/*:747*/
#line 8155 "./marpa.w"

/*751:*/
#line 8283 "./marpa.w"
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

/*:751*/
#line 8156 "./marpa.w"

while((cause_p= MARPA_DSTACK_POP(r->t_completion_stack,YIM))){
YIM cause= *cause_p;
/*752:*/
#line 8304 "./marpa.w"

{
if(YIM_is_Active(cause)&&YIM_is_Completion(cause))
{
NSYID complete_nsyid= LHS_NSYID_of_YIM(cause);
const YS middle= Origin_of_YIM(cause);
/*753:*/
#line 8314 "./marpa.w"

{
PIM postdot_item;
for(postdot_item= First_PIM_of_YS_by_NSYID(middle,complete_nsyid);
postdot_item;postdot_item= Next_PIM_of_PIM(postdot_item))
{
const YIM predecessor= YIM_of_PIM(postdot_item);
if(!predecessor){


const LIM leo_item= LIM_of_PIM(postdot_item);








if(!LIM_is_Active(leo_item))goto NEXT_PIM;

/*756:*/
#line 8381 "./marpa.w"
{
const YS origin= Origin_of_LIM(leo_item);
const AHM effect_ahm= Top_AHM_of_LIM(leo_item);
const YIM effect= earley_item_assign(r,current_earley_set,
origin,effect_ahm);
YIM_was_Fusion(effect)= 1;
if(Earley_Item_has_No_Source(effect))
{


/*755:*/
#line 8375 "./marpa.w"
{
YIM*end_of_stack= MARPA_DSTACK_PUSH(r->t_completion_stack,YIM);
*end_of_stack= effect;
}

/*:755*/
#line 8391 "./marpa.w"

}
leo_link_add(r,effect,leo_item,cause);
}

/*:756*/
#line 8335 "./marpa.w"





goto LAST_PIM;
}else{


if(!YIM_is_Active(predecessor))continue;



/*754:*/
#line 8355 "./marpa.w"

{
const AHM predecessor_ahm= AHM_of_YIM(predecessor);
const AHM effect_ahm= Next_AHM_of_AHM(predecessor_ahm);
const YS origin= Origin_of_YIM(predecessor);
const YIM effect= earley_item_assign(r,current_earley_set,
origin,effect_ahm);
YIM_was_Fusion(effect)= 1;
if(Earley_Item_has_No_Source(effect)){


if(YIM_is_Completion(effect)){
/*755:*/
#line 8375 "./marpa.w"
{
YIM*end_of_stack= MARPA_DSTACK_PUSH(r->t_completion_stack,YIM);
*end_of_stack= effect;
}

/*:755*/
#line 8367 "./marpa.w"

}
}
completion_link_add(r,effect,predecessor,cause);
}

/*:754*/
#line 8348 "./marpa.w"

}
NEXT_PIM:;
}
LAST_PIM:;
}

/*:753*/
#line 8310 "./marpa.w"

}
}

/*:752*/
#line 8159 "./marpa.w"

}
/*757:*/
#line 8396 "./marpa.w"

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

/*:757*/
#line 8161 "./marpa.w"

postdot_items_create(r,bv_ok_for_chain,current_earley_set);





count_of_expected_terminals= bv_count(r->t_bv_nsyid_is_expected);
if(count_of_expected_terminals<=0
&&MARPA_DSTACK_LENGTH(r->t_alternatives)<=0)
{
/*614:*/
#line 6625 "./marpa.w"

{
R_is_Exhausted(r)= 1;
Input_Phase_of_R(r)= R_AFTER_INPUT;
event_new(g,MARPA_EVENT_EXHAUSTED);
}

/*:614*/
#line 8172 "./marpa.w"

}
earley_set_update_items(r,current_earley_set);
/*659:*/
#line 7064 "./marpa.w"

{
const int yim_count= YIM_Count_of_YS(current_earley_set);
if(yim_count>=r->t_earley_item_warning_threshold)
{
int_event_new(g,MARPA_EVENT_EARLEY_ITEM_THRESHOLD,yim_count);
}
}

/*:659*/
#line 8175 "./marpa.w"

if(r->t_active_event_count> 0){
trigger_events(r);
}
return_value= G_EVENT_COUNT(g);
CLEANUP:;
/*743:*/
#line 8193 "./marpa.w"

bv_free(bv_ok_for_chain);
marpa_obs_free(earleme_complete_obs);

/*:743*/
#line 8181 "./marpa.w"

}
return return_value;
}

/*:741*//*758:*/
#line 8421 "./marpa.w"

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

/*:758*//*759:*/
#line 8589 "./marpa.w"

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

/*:759*//*760:*/
#line 8609 "./marpa.w"

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

/*:760*//*761:*/
#line 8638 "./marpa.w"

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

/*:761*//*777:*/
#line 8742 "./marpa.w"

PRIVATE_NOT_INLINE void
postdot_items_create(RECCE r,
Bit_Vector bv_ok_for_chain,
const YS current_earley_set)
{
/*563:*/
#line 6125 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:563*/
#line 8748 "./marpa.w"

/*776:*/
#line 8739 "./marpa.w"

bv_clear(r->t_bv_lim_symbols);
bv_clear(r->t_bv_pim_symbols);
/*:776*/
#line 8749 "./marpa.w"

/*778:*/
#line 8761 "./marpa.w"
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

/*:778*/
#line 8750 "./marpa.w"

if(r->t_is_using_leo){
/*780:*/
#line 8804 "./marpa.w"

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
/*781:*/
#line 8848 "./marpa.w"
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

/*:781*/
#line 8833 "./marpa.w"

}
}
}
NEXT_NSYID:;
}
}
}

/*:780*/
#line 8752 "./marpa.w"

/*790:*/
#line 8936 "./marpa.w"
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

/*792:*/
#line 8992 "./marpa.w"

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

/*:792*/
#line 8953 "./marpa.w"

if(predecessor_lim&&LIM_is_Populated(predecessor_lim)){
/*800:*/
#line 9111 "./marpa.w"

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

/*:800*/
#line 8955 "./marpa.w"

continue;
}
if(!predecessor_lim){


/*802:*/
#line 9152 "./marpa.w"
{
const AHM trailhead_ahm= Trailhead_AHM_of_LIM(lim_to_process);
const YIM base_yim= Trailhead_YIM_of_LIM(lim_to_process);
Origin_of_LIM(lim_to_process)= Origin_of_YIM(base_yim);
CIL_of_LIM(lim_to_process)= Event_AHMIDs_of_AHM(trailhead_ahm);
}

/*:802*/
#line 8961 "./marpa.w"

continue;
}
/*795:*/
#line 9019 "./marpa.w"
{
int lim_chain_ix;
/*798:*/
#line 9039 "./marpa.w"

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

/*792:*/
#line 8992 "./marpa.w"

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

/*:792*/
#line 9072 "./marpa.w"


r->t_lim_chain[lim_chain_ix++]= LIM_of_PIM(lim_to_process);


bv_bit_clear(bv_ok_for_chain,
postdot_nsyid_of_lim_to_process);





if(!predecessor_lim)
break;
if(LIM_is_Populated(predecessor_lim))
break;



}
}

/*:798*/
#line 9021 "./marpa.w"

/*799:*/
#line 9094 "./marpa.w"

for(lim_chain_ix--;lim_chain_ix>=0;lim_chain_ix--){
lim_to_process= r->t_lim_chain[lim_chain_ix];
if(predecessor_lim&&LIM_is_Populated(predecessor_lim)){
/*800:*/
#line 9111 "./marpa.w"

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

/*:800*/
#line 9098 "./marpa.w"

}else{
/*802:*/
#line 9152 "./marpa.w"
{
const AHM trailhead_ahm= Trailhead_AHM_of_LIM(lim_to_process);
const YIM base_yim= Trailhead_YIM_of_LIM(lim_to_process);
Origin_of_LIM(lim_to_process)= Origin_of_YIM(base_yim);
CIL_of_LIM(lim_to_process)= Event_AHMIDs_of_AHM(trailhead_ahm);
}

/*:802*/
#line 9100 "./marpa.w"

}
predecessor_lim= lim_to_process;
}

/*:799*/
#line 9022 "./marpa.w"

}

/*:795*/
#line 8964 "./marpa.w"

}
}
}

/*:790*/
#line 8753 "./marpa.w"

}
/*803:*/
#line 9159 "./marpa.w"
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


/*:803*/
#line 8755 "./marpa.w"

bv_and(r->t_bv_nsyid_is_expected,r->t_bv_pim_symbols,g->t_bv_nsyid_is_terminal);
}

/*:777*//*806:*/
#line 9195 "./marpa.w"

Marpa_Earleme
marpa_r_clean(Marpa_Recognizer r)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 9199 "./marpa.w"

/*563:*/
#line 6125 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:563*/
#line 9200 "./marpa.w"

YSID ysid_to_clean;


const YS current_ys= Latest_YS_of_R(r);
const YSID current_ys_id= Ord_of_YS(current_ys);

int count_of_expected_terminals;
/*807:*/
#line 9256 "./marpa.w"




struct marpa_obstack*const method_obstack= marpa_obs_init;

YIMID*prediction_by_irl= 
marpa_obs_new(method_obstack,YIMID,IRL_Count_of_G(g));

/*:807*/
#line 9208 "./marpa.w"






const JEARLEME return_value= -2;

/*1331:*/
#line 15743 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)!=R_DURING_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_ACCEPTING_INPUT);
return failure_indicator;
}

if(_MARPA_UNLIKELY(!R_is_Consistent(r))){
MARPA_ERROR(MARPA_ERR_RECCE_IS_INCONSISTENT);
return failure_indicator;
}

/*:1331*/
#line 9216 "./marpa.w"


G_EVENTS_CLEAR(g);



if(R_is_Consistent(r))return 0;





earley_set_update_items(r,current_ys);

for(ysid_to_clean= First_Inconsistent_YS_of_R(r);
ysid_to_clean<=current_ys_id;
ysid_to_clean++){
/*809:*/
#line 9270 "./marpa.w"

{
const YS ys_to_clean= YS_of_R_by_Ord(r,ysid_to_clean);
const YIM*yims_to_clean= YIMs_of_YS(ys_to_clean);
const int yim_to_clean_count= YIM_Count_of_YS(ys_to_clean);
Bit_Matrix acceptance_matrix= matrix_obs_create(method_obstack,
yim_to_clean_count,
yim_to_clean_count);
/*810:*/
#line 9290 "./marpa.w"

{
int yim_ix= yim_to_clean_count-1;
YIM yim= yims_to_clean[yim_ix];






while(YIM_was_Predicted(yim)){
prediction_by_irl[IRLID_of_YIM(yim)]= yim_ix;
yim= yims_to_clean[--yim_ix];
}
}

/*:810*/
#line 9278 "./marpa.w"

/*811:*/
#line 9306 "./marpa.w"
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



/*812:*/
#line 9343 "./marpa.w"

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

/*:812*/
#line 9333 "./marpa.w"







}
}

/*:811*/
#line 9279 "./marpa.w"

transitive_closure(acceptance_matrix);
/*817:*/
#line 9403 "./marpa.w"
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

/*:817*/
#line 9281 "./marpa.w"

/*818:*/
#line 9444 "./marpa.w"
{
int yim_ix;
for(yim_ix= 0;yim_ix<yim_to_clean_count;yim_ix++){
const YIM yim= yims_to_clean[yim_ix];
if(!YIM_is_Active(yim))continue;
YIM_is_Rejected(yim)= 1;
}
}

/*:818*/
#line 9282 "./marpa.w"

/*820:*/
#line 9458 "./marpa.w"
{}

/*:820*/
#line 9283 "./marpa.w"

/*821:*/
#line 9462 "./marpa.w"

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

/*:821*/
#line 9284 "./marpa.w"

}

/*:809*/
#line 9233 "./marpa.w"

}




/*822:*/
#line 9507 "./marpa.w"
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

/*:822*/
#line 9239 "./marpa.w"


bv_clear(r->t_bv_nsyid_is_expected);
/*824:*/
#line 9587 "./marpa.w"
{}

/*:824*/
#line 9242 "./marpa.w"

count_of_expected_terminals= bv_count(r->t_bv_nsyid_is_expected);
if(count_of_expected_terminals<=0
&&MARPA_DSTACK_LENGTH(r->t_alternatives)<=0)
{
/*614:*/
#line 6625 "./marpa.w"

{
R_is_Exhausted(r)= 1;
Input_Phase_of_R(r)= R_AFTER_INPUT;
event_new(g,MARPA_EVENT_EXHAUSTED);
}

/*:614*/
#line 9247 "./marpa.w"

}

First_Inconsistent_YS_of_R(r)= -1;

/*808:*/
#line 9265 "./marpa.w"

{
marpa_obs_free(method_obstack);
}

/*:808*/
#line 9252 "./marpa.w"

return return_value;
}

/*:806*//*823:*/
#line 9561 "./marpa.w"

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

/*:823*//*825:*/
#line 9590 "./marpa.w"

int
marpa_r_zwa_default_set(Marpa_Recognizer r,
Marpa_Assertion_ID zwaid,
int default_value)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 9596 "./marpa.w"

/*563:*/
#line 6125 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:563*/
#line 9597 "./marpa.w"

ZWA zwa;
int old_default_value;
/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 9600 "./marpa.w"

/*1327:*/
#line 15713 "./marpa.w"

if(_MARPA_UNLIKELY(ZWAID_is_Malformed(zwaid))){
MARPA_ERROR(MARPA_ERR_INVALID_ASSERTION_ID);
return failure_indicator;
}

/*:1327*/
#line 9601 "./marpa.w"

/*1326:*/
#line 15707 "./marpa.w"

if(_MARPA_UNLIKELY(!ZWAID_of_G_Exists(zwaid))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_ASSERTION_ID);
return failure_indicator;
}
/*:1326*/
#line 9602 "./marpa.w"

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

/*:825*//*826:*/
#line 9614 "./marpa.w"

int
marpa_r_zwa_default(Marpa_Recognizer r,
Marpa_Assertion_ID zwaid)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 9619 "./marpa.w"

/*563:*/
#line 6125 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:563*/
#line 9620 "./marpa.w"

ZWA zwa;
/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 9622 "./marpa.w"

/*1327:*/
#line 15713 "./marpa.w"

if(_MARPA_UNLIKELY(ZWAID_is_Malformed(zwaid))){
MARPA_ERROR(MARPA_ERR_INVALID_ASSERTION_ID);
return failure_indicator;
}

/*:1327*/
#line 9623 "./marpa.w"

/*1326:*/
#line 15707 "./marpa.w"

if(_MARPA_UNLIKELY(!ZWAID_of_G_Exists(zwaid))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_ASSERTION_ID);
return failure_indicator;
}
/*:1326*/
#line 9624 "./marpa.w"

zwa= RZWA_by_ID(zwaid);
return Default_Value_of_ZWA(zwa);
}

/*:826*//*835:*/
#line 9664 "./marpa.w"

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

/*:835*//*836:*/
#line 9681 "./marpa.w"

int marpa_r_progress_report_start(
Marpa_Recognizer r,
Marpa_Earley_Set_ID set_id)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 9686 "./marpa.w"

YS earley_set;
/*563:*/
#line 6125 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:563*/
#line 9688 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 9689 "./marpa.w"

/*1330:*/
#line 15738 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1330*/
#line 9690 "./marpa.w"

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

/*830:*/
#line 9638 "./marpa.w"

r->t_current_report_item= &progress_report_not_ready;
if(r->t_progress_report_traverser){
_marpa_avl_destroy(MARPA_TREE_OF_AVL_TRAV(r->t_progress_report_traverser));
}
r->t_progress_report_traverser= NULL;
/*:830*/
#line 9707 "./marpa.w"

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
/*838:*/
#line 9740 "./marpa.w"

{
SRCL leo_source_link= NULL;

MARPA_OFF_DEBUG2("At %s, Do the progress report",STRLOC);

progress_report_items_insert(report_tree,AHM_of_YIM(earley_item),
earley_item);
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
const AHM trailhead_ahm= Trailhead_AHM_of_LIM(leo_item);
progress_report_items_insert(report_tree,trailhead_ahm,
trailhead_yim);
}

MARPA_OFF_DEBUG3("At %s, finished Leo source link %p",STRLOC,leo_source_link);
}
}

/*:838*/
#line 9719 "./marpa.w"

}
r->t_progress_report_traverser= _marpa_avl_t_init(report_tree);
return(int)marpa_avl_count(report_tree);
}
}
/*:836*//*837:*/
#line 9726 "./marpa.w"

int marpa_r_progress_report_reset(Marpa_Recognizer r)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 9729 "./marpa.w"

MARPA_AVL_TRAV traverser= r->t_progress_report_traverser;
/*563:*/
#line 6125 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:563*/
#line 9731 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 9732 "./marpa.w"

/*1330:*/
#line 15738 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1330*/
#line 9733 "./marpa.w"

/*842:*/
#line 9890 "./marpa.w"

{
if(!traverser)
{
MARPA_ERROR(MARPA_ERR_PROGRESS_REPORT_NOT_STARTED);
return failure_indicator;
}
}

/*:842*/
#line 9734 "./marpa.w"

_marpa_avl_t_reset(traverser);
return 1;
}

/*:837*//*839:*/
#line 9774 "./marpa.w"

PRIVATE void
progress_report_items_insert(MARPA_AVL_TREE report_tree,
AHM report_ahm,
YIM origin_yim)
{
const XRL source_xrl= XRL_of_AHM(report_ahm);

MARPA_OFF_DEBUG5(
"%s Calling progress_report_items_insert(%p, %p, %p)",
STRLOC,report_tree,report_ahm,origin_yim);

if(!source_xrl)return;





if(!IRL_has_Virtual_LHS(IRL_of_YIM(origin_yim))){
int xrl_position= XRL_Position_of_AHM(report_ahm);
int origin_of_xrl= Origin_Ord_of_YIM(origin_yim);
XRLID xrl_id= ID_of_XRL(source_xrl);

PROGRESS new_report_item= 
marpa_obs_new(MARPA_AVL_OBSTACK(report_tree),
struct marpa_progress_item,1);

MARPA_OFF_DEBUG2("%s, === Adding report item ===",STRLOC);
MARPA_OFF_DEBUG3("%s, report irl = %d",STRLOC,IRLID_of_AHM(report_ahm));
MARPA_OFF_DEBUG3("%s, report irl position = %d",STRLOC,Position_of_AHM(report_ahm));

MARPA_OFF_DEBUG3("%s, xrl = %d",STRLOC,ID_of_XRL(source_xrl));
MARPA_OFF_DEBUG3("%s, xrl dot = %d",STRLOC,XRL_Position_of_AHM(report_ahm));
MARPA_OFF_DEBUG3("%s, origin ord = %d",STRLOC,Origin_Ord_of_YIM(origin_yim));

Position_of_PROGRESS(new_report_item)= xrl_position;
Origin_of_PROGRESS(new_report_item)= origin_of_xrl;
RULEID_of_PROGRESS(new_report_item)= xrl_id;
_marpa_avl_insert(report_tree,new_report_item);

return;
}







if(XRL_is_Sequence(source_xrl))return;








{
const NSYID lhs_nsyid= LHS_NSYID_of_YIM(origin_yim);
const YS origin_of_origin_ys= Origin_of_YIM(origin_yim);
PIM pim= First_PIM_of_YS_by_NSYID(origin_of_origin_ys,lhs_nsyid);
for(;pim;pim= Next_PIM_of_PIM(pim))
{
const YIM predecessor= YIM_of_PIM(pim);




if(!predecessor)return;
if(YIM_is_Active(predecessor)){
progress_report_items_insert(report_tree,
report_ahm,predecessor);
}
}
}
}

/*:839*//*840:*/
#line 9852 "./marpa.w"

int marpa_r_progress_report_finish(Marpa_Recognizer r){
const int success= 1;
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 9855 "./marpa.w"

/*563:*/
#line 6125 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:563*/
#line 9856 "./marpa.w"

const MARPA_AVL_TRAV traverser= r->t_progress_report_traverser;
/*1330:*/
#line 15738 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1330*/
#line 9858 "./marpa.w"

/*842:*/
#line 9890 "./marpa.w"

{
if(!traverser)
{
MARPA_ERROR(MARPA_ERR_PROGRESS_REPORT_NOT_STARTED);
return failure_indicator;
}
}

/*:842*/
#line 9859 "./marpa.w"

/*830:*/
#line 9638 "./marpa.w"

r->t_current_report_item= &progress_report_not_ready;
if(r->t_progress_report_traverser){
_marpa_avl_destroy(MARPA_TREE_OF_AVL_TRAV(r->t_progress_report_traverser));
}
r->t_progress_report_traverser= NULL;
/*:830*/
#line 9860 "./marpa.w"

return success;
}

/*:840*//*841:*/
#line 9864 "./marpa.w"

Marpa_Rule_ID marpa_r_progress_item(
Marpa_Recognizer r,int*position,Marpa_Earley_Set_ID*origin
){
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 9868 "./marpa.w"

PROGRESS report_item;
MARPA_AVL_TRAV traverser;
/*563:*/
#line 6125 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:563*/
#line 9871 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 9872 "./marpa.w"

/*1330:*/
#line 15738 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1330*/
#line 9873 "./marpa.w"

traverser= r->t_progress_report_traverser;
if(_MARPA_UNLIKELY(!position||!origin)){
MARPA_ERROR(MARPA_ERR_POINTER_ARG_NULL);
return failure_indicator;
}
/*842:*/
#line 9890 "./marpa.w"

{
if(!traverser)
{
MARPA_ERROR(MARPA_ERR_PROGRESS_REPORT_NOT_STARTED);
return failure_indicator;
}
}

/*:842*/
#line 9879 "./marpa.w"

report_item= _marpa_avl_t_next(traverser);
if(!report_item){
MARPA_ERROR(MARPA_ERR_PROGRESS_REPORT_EXHAUSTED);
return-1;
}
*position= Position_of_PROGRESS(report_item);
*origin= Origin_of_PROGRESS(report_item);
return RULEID_of_PROGRESS(report_item);
}

/*:841*//*865:*/
#line 10075 "./marpa.w"

PRIVATE void ur_node_stack_init(URS stack)
{
stack->t_obs= marpa_obs_init;
stack->t_base= ur_node_new(stack,0);
ur_node_stack_reset(stack);
}

/*:865*//*866:*/
#line 10083 "./marpa.w"

PRIVATE void ur_node_stack_reset(URS stack)
{
stack->t_top= stack->t_base;
}

/*:866*//*867:*/
#line 10089 "./marpa.w"

PRIVATE void ur_node_stack_destroy(URS stack)
{
if(stack->t_base)marpa_obs_free(stack->t_obs);
stack->t_base= NULL;
}

/*:867*//*868:*/
#line 10096 "./marpa.w"

PRIVATE UR ur_node_new(URS stack,UR prev)
{
UR new_ur_node;
new_ur_node= marpa_obs_new(stack->t_obs,UR_Object,1);
Next_UR_of_UR(new_ur_node)= 0;
Prev_UR_of_UR(new_ur_node)= prev;
return new_ur_node;
}

/*:868*//*869:*/
#line 10106 "./marpa.w"

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

/*:869*//*870:*/
#line 10121 "./marpa.w"

PRIVATE UR
ur_node_pop(URS stack)
{
UR new_top= Prev_UR_of_UR(stack->t_top);
if(!new_top)return NULL;
stack->t_top= new_top;
return new_top;
}

/*:870*//*872:*/
#line 10158 "./marpa.w"

PRIVATE void push_ur_if_new(
struct s_bocage_setup_per_ys*per_ys_data,
URS ur_node_stack,YIM yim)
{
if(!psi_test_and_set(per_ys_data,yim))
{
ur_node_push(ur_node_stack,yim);
}
}

/*:872*//*873:*/
#line 10174 "./marpa.w"

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

/*:873*//*875:*/
#line 10216 "./marpa.w"

PRIVATE void
Set_boolean_in_PSI_for_initial_nulls(struct s_bocage_setup_per_ys*per_ys_data,
YIM yim)
{
const AHM ahm= AHM_of_YIM(yim);
if(Null_Count_of_AHM(ahm))
psi_test_and_set(per_ys_data,(yim));
}

/*:875*//*894:*/
#line 10474 "./marpa.w"

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

/*:894*//*904:*/
#line 10674 "./marpa.w"

PRIVATE
DAND draft_and_node_new(struct marpa_obstack*obs,OR predecessor,OR cause)
{
DAND draft_and_node= marpa_obs_new(obs,DAND_Object,1);
Predecessor_OR_of_DAND(draft_and_node)= predecessor;
Cause_OR_of_DAND(draft_and_node)= cause;
MARPA_ASSERT(cause!=NULL);
return draft_and_node;
}

/*:904*//*905:*/
#line 10685 "./marpa.w"

PRIVATE
void draft_and_node_add(struct marpa_obstack*obs,OR parent,OR predecessor,OR cause)
{
MARPA_OFF_ASSERT(Position_of_OR(parent)<=1||predecessor)
const DAND new= draft_and_node_new(obs,predecessor,cause);
Next_DAND_of_DAND(new)= DANDs_of_OR(parent);
DANDs_of_OR(parent)= new;
}

/*:905*//*913:*/
#line 10825 "./marpa.w"

PRIVATE
OR or_by_origin_and_symi(struct s_bocage_setup_per_ys*per_ys_data,
YSID origin,
SYMI symbol_instance)
{
const PSL or_psl_at_origin= per_ys_data[(origin)].t_or_psl;
return PSL_Datum(or_psl_at_origin,(symbol_instance));
}

/*:913*//*918:*/
#line 10884 "./marpa.w"

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

/*:918*//*919:*/
#line 10918 "./marpa.w"

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

/*:919*//*920:*/
#line 10933 "./marpa.w"

PRIVATE
OR set_or_from_yim(struct s_bocage_setup_per_ys*per_ys_data,
YIM psi_yim)
{
const YIM psi_earley_item= psi_yim;
const int psi_earley_set_ordinal= YS_Ord_of_YIM(psi_earley_item);
const int psi_item_ordinal= Ord_of_YIM(psi_earley_item);
return OR_by_PSI(per_ys_data,psi_earley_set_ordinal,psi_item_ordinal);
}

/*:920*//*923:*/
#line 10991 "./marpa.w"

PRIVATE
OR safe_or_from_yim(
struct s_bocage_setup_per_ys*per_ys_data,
YIM yim)
{
if(Position_of_AHM(AHM_of_YIM(yim))<1)return NULL;
return set_or_from_yim(per_ys_data,yim);
}

/*:923*//*941:*/
#line 11155 "./marpa.w"

int marpa_trv_soft_error(Marpa_Traverser trv)
{
return TRV_has_Soft_Error(trv);
}

/*:941*//*946:*/
#line 11176 "./marpa.w"

PRIVATE Marpa_Traverser
trv_new(RECCE r,YIM yim)
{
TRAVERSER trv;

trv= my_malloc(sizeof(*trv));
/*940:*/
#line 11153 "./marpa.w"

TRV_has_Soft_Error(trv)= 0;
/*:940*//*943:*/
#line 11164 "./marpa.w"

R_of_TRV(trv)= r;

/*:943*//*960:*/
#line 11469 "./marpa.w"

trv->t_ref_count= 1;
/*:960*/
#line 11183 "./marpa.w"

recce_ref(r);
if(!yim){
TRV_is_Trivial(trv)= 1;
return trv;
}
TRV_is_Trivial(trv)= 0;
YIM_of_TRV(trv)= yim;
TOKEN_SRCL_of_TRV(trv)= First_Token_SRCL_of_YIM(yim);
COMPLETION_SRCL_of_TRV(trv)= First_Completion_SRCL_of_YIM(yim);
LEO_SRCL_of_TRV(trv)= First_Leo_SRCL_of_YIM(yim);
return trv;
}

/*:946*//*947:*/
#line 11201 "./marpa.w"

Marpa_Traverser marpa_trv_new(Marpa_Recognizer r,
Marpa_Earley_Set_ID es_arg,
Marpa_Earley_Item_ID eim_arg
)
{
/*1312:*/
#line 15626 "./marpa.w"
void*const failure_indicator= NULL;
/*:1312*/
#line 11207 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 11209 "./marpa.w"


if(_MARPA_UNLIKELY(es_arg<=-2))
{
MARPA_ERROR(MARPA_ERR_INVALID_LOCATION);
return failure_indicator;
}
if(_MARPA_UNLIKELY(eim_arg<0))
{
MARPA_ERROR(MARPA_ERR_YIM_ID_INVALID);
return failure_indicator;
}

/*1330:*/
#line 15738 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1330*/
#line 11222 "./marpa.w"


if(G_is_Trivial(g)){
if(es_arg> 0){
MARPA_ERROR(MARPA_ERR_INVALID_LOCATION);
return failure_indicator;
}
if(eim_arg!=0){
MARPA_ERROR(MARPA_ERR_YIM_ID_INVALID);
return failure_indicator;
}
return trv_new(r,NULL);
}

r_update_earley_sets(r);

{
YIM*earley_items;
YIM yim;
YS ys;
int item_count;

if(es_arg==-1)
{
ys= YS_at_Current_Earleme_of_R(r);
}
else
{
if(!YS_Ord_is_Valid(r,es_arg))
{
MARPA_ERROR(MARPA_ERR_INVALID_LOCATION);
return failure_indicator;
}
ys= YS_of_R_by_Ord(r,es_arg);
}

item_count= YIM_Count_of_YS(ys);
if(eim_arg>=item_count){
MARPA_ERROR(MARPA_ERR_YIM_ID_INVALID);
return failure_indicator;
}

earley_items= YIMs_of_YS(ys);
yim= earley_items[eim_arg];
return trv_new(r,yim);
}
}

/*:947*//*948:*/
#line 11271 "./marpa.w"

int marpa_trv_at_completion(Marpa_Traverser trv)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 11274 "./marpa.w"

/*944:*/
#line 11167 "./marpa.w"

const RECCE r UNUSED= R_of_TRV(trv);
const GRAMMAR g UNUSED= G_of_R(r);

/*:944*/
#line 11275 "./marpa.w"

SRCL srcl;
/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 11277 "./marpa.w"


if(G_is_Trivial(g))return 0;
srcl= COMPLETION_SRCL_of_TRV(trv);
return srcl?1:0;
}

/*:948*//*949:*/
#line 11285 "./marpa.w"

int marpa_trv_at_token(Marpa_Traverser trv)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 11288 "./marpa.w"

/*944:*/
#line 11167 "./marpa.w"

const RECCE r UNUSED= R_of_TRV(trv);
const GRAMMAR g UNUSED= G_of_R(r);

/*:944*/
#line 11289 "./marpa.w"

SRCL srcl;
/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 11291 "./marpa.w"


if(G_is_Trivial(g))return 0;
srcl= TOKEN_SRCL_of_TRV(trv);
return srcl?1:0;
}

/*:949*//*950:*/
#line 11299 "./marpa.w"

int marpa_trv_at_leo(Marpa_Traverser trv)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 11302 "./marpa.w"

/*944:*/
#line 11167 "./marpa.w"

const RECCE r UNUSED= R_of_TRV(trv);
const GRAMMAR g UNUSED= G_of_R(r);

/*:944*/
#line 11303 "./marpa.w"

SRCL srcl;
/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 11305 "./marpa.w"


if(G_is_Trivial(g))return 0;
srcl= LEO_SRCL_of_TRV(trv);
return srcl?1:0;
}

/*:950*//*951:*/
#line 11316 "./marpa.w"

Marpa_Traverser marpa_trv_completion_predecessor(Marpa_Traverser trv)
{
/*1312:*/
#line 15626 "./marpa.w"
void*const failure_indicator= NULL;
/*:1312*/
#line 11319 "./marpa.w"

/*944:*/
#line 11167 "./marpa.w"

const RECCE r UNUSED= R_of_TRV(trv);
const GRAMMAR g UNUSED= G_of_R(r);

/*:944*/
#line 11320 "./marpa.w"

SRCL srcl;
YIM predecessor;
/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 11323 "./marpa.w"

TRV_has_Soft_Error(trv)= 0;

if(G_is_Trivial(g)){
TRV_has_Soft_Error(trv)= 1;
MARPA_ERROR(MARPA_ERR_GRAMMAR_IS_TRIVIAL);
return NULL;
}
srcl= COMPLETION_SRCL_of_TRV(trv);
if(!srcl){
MARPA_ERROR(MARPA_ERR_DEVELOPMENT);
TRV_has_Soft_Error(trv)= 1;
return NULL;
}
predecessor= Predecessor_of_SRCL(srcl);
if(!predecessor){
TRV_has_Soft_Error(trv)= 1;
return NULL;
}
return trv_new(r,predecessor);
}

/*:951*//*952:*/
#line 11349 "./marpa.w"

Marpa_LTraverser marpa_trv_lim(Marpa_Traverser trv)
{
/*1312:*/
#line 15626 "./marpa.w"
void*const failure_indicator= NULL;
/*:1312*/
#line 11352 "./marpa.w"

/*944:*/
#line 11167 "./marpa.w"

const RECCE r UNUSED= R_of_TRV(trv);
const GRAMMAR g UNUSED= G_of_R(r);

/*:944*/
#line 11353 "./marpa.w"

SRCL srcl;
LIM predecessor;
/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 11356 "./marpa.w"

TRV_has_Soft_Error(trv)= 0;

if(G_is_Trivial(g)){
TRV_has_Soft_Error(trv)= 1;
MARPA_ERROR(MARPA_ERR_GRAMMAR_IS_TRIVIAL);
return NULL;
}
srcl= LEO_SRCL_of_TRV(trv);
if(!srcl){
MARPA_ERROR(MARPA_ERR_DEVELOPMENT);
TRV_has_Soft_Error(trv)= 1;
return NULL;
}
predecessor= LIM_of_SRCL(srcl);
if(!predecessor){
TRV_has_Soft_Error(trv)= 1;
return NULL;
}
return ltrv_new(r,predecessor);
}

/*:952*//*953:*/
#line 11382 "./marpa.w"

Marpa_Traverser marpa_trv_token_predecessor(Marpa_Traverser trv)
{
/*1312:*/
#line 15626 "./marpa.w"
void*const failure_indicator= NULL;
/*:1312*/
#line 11385 "./marpa.w"

/*944:*/
#line 11167 "./marpa.w"

const RECCE r UNUSED= R_of_TRV(trv);
const GRAMMAR g UNUSED= G_of_R(r);

/*:944*/
#line 11386 "./marpa.w"

SRCL srcl;
YIM predecessor;
/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 11389 "./marpa.w"

TRV_has_Soft_Error(trv)= 0;

if(G_is_Trivial(g)){
TRV_has_Soft_Error(trv)= 1;
MARPA_ERROR(MARPA_ERR_GRAMMAR_IS_TRIVIAL);
return NULL;
}
srcl= TOKEN_SRCL_of_TRV(trv);
if(!srcl){
MARPA_ERROR(MARPA_ERR_DEVELOPMENT);
TRV_has_Soft_Error(trv)= 1;
return NULL;
}
predecessor= Predecessor_of_SRCL(srcl);
if(!predecessor){
TRV_has_Soft_Error(trv)= 1;
return NULL;
}
return trv_new(r,predecessor);
}

/*:953*//*955:*/
#line 11413 "./marpa.w"

int marpa_trv_completion_next(Marpa_Traverser trv)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 11416 "./marpa.w"

/*944:*/
#line 11167 "./marpa.w"

const RECCE r UNUSED= R_of_TRV(trv);
const GRAMMAR g UNUSED= G_of_R(r);

/*:944*/
#line 11417 "./marpa.w"

SRCL srcl;
/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 11419 "./marpa.w"

if(G_is_Trivial(g)){
return 0;
}
srcl= COMPLETION_SRCL_of_TRV(trv);
if(!srcl)return 0;
srcl= COMPLETION_SRCL_of_TRV(trv)= Next_SRCL_of_SRCL(srcl);
if(!srcl)return 0;
return 1;
}

/*:955*//*956:*/
#line 11431 "./marpa.w"

int marpa_trv_leo_next(Marpa_Traverser trv)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 11434 "./marpa.w"

/*944:*/
#line 11167 "./marpa.w"

const RECCE r UNUSED= R_of_TRV(trv);
const GRAMMAR g UNUSED= G_of_R(r);

/*:944*/
#line 11435 "./marpa.w"

SRCL srcl;
/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 11437 "./marpa.w"

if(G_is_Trivial(g)){
return 0;
}
srcl= LEO_SRCL_of_TRV(trv);
if(!srcl)return 0;
srcl= LEO_SRCL_of_TRV(trv)= Next_SRCL_of_SRCL(srcl);
if(!srcl)return 0;
return 1;
}

/*:956*//*957:*/
#line 11449 "./marpa.w"

int marpa_trv_token_next(Marpa_Traverser trv)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 11452 "./marpa.w"

/*944:*/
#line 11167 "./marpa.w"

const RECCE r UNUSED= R_of_TRV(trv);
const GRAMMAR g UNUSED= G_of_R(r);

/*:944*/
#line 11453 "./marpa.w"

SRCL srcl;
/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 11455 "./marpa.w"

if(G_is_Trivial(g)){
return 0;
}
srcl= TOKEN_SRCL_of_TRV(trv);
if(!srcl)return 0;
srcl= TOKEN_SRCL_of_TRV(trv)= Next_SRCL_of_SRCL(srcl);
if(!srcl)return 0;
return 1;
}

/*:957*//*961:*/
#line 11472 "./marpa.w"

PRIVATE void
traverser_unref(TRAVERSER trv)
{
MARPA_ASSERT(trv->t_ref_count> 0)
trv->t_ref_count--;
if(trv->t_ref_count<=0)
{
traverser_free(trv);
}
}
void
marpa_trv_unref(Marpa_Traverser trv)
{
traverser_unref(trv);
}

/*:961*//*962:*/
#line 11490 "./marpa.w"

PRIVATE TRAVERSER
traverser_ref(TRAVERSER trv)
{
MARPA_ASSERT(trv->t_ref_count> 0)
trv->t_ref_count++;
return trv;
}
Marpa_Traverser
marpa_trv_ref(Marpa_Traverser trv)
{
return traverser_ref(trv);
}

/*:962*//*964:*/
#line 11508 "./marpa.w"

PRIVATE void
traverser_free(TRAVERSER trv)
{
/*944:*/
#line 11167 "./marpa.w"

const RECCE r UNUSED= R_of_TRV(trv);
const GRAMMAR g UNUSED= G_of_R(r);

/*:944*/
#line 11512 "./marpa.w"

if(trv)
{
/*937:*/
#line 11145 "./marpa.w"

{
recce_unref(R_of_TRV(trv));
}

/*:937*/
#line 11515 "./marpa.w"
;
}
my_free(trv);
}

/*:964*//*968:*/
#line 11530 "./marpa.w"

int marpa_trv_is_trivial(Marpa_Traverser trv)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 11533 "./marpa.w"

/*944:*/
#line 11167 "./marpa.w"

const RECCE r UNUSED= R_of_TRV(trv);
const GRAMMAR g UNUSED= G_of_R(r);

/*:944*/
#line 11534 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 11535 "./marpa.w"

return TRV_is_Trivial(trv);
}
/*:968*//*971:*/
#line 11547 "./marpa.w"

Marpa_Rule_ID marpa_trv_rule_id(Marpa_Traverser trv)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 11550 "./marpa.w"

/*944:*/
#line 11167 "./marpa.w"

const RECCE r UNUSED= R_of_TRV(trv);
const GRAMMAR g UNUSED= G_of_R(r);

/*:944*/
#line 11551 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 11552 "./marpa.w"

/*969:*/
#line 11538 "./marpa.w"

if(TRV_is_Trivial(trv)){
MARPA_ERROR(MARPA_ERR_GRAMMAR_IS_TRIVIAL);
return failure_indicator;
}

/*:969*/
#line 11553 "./marpa.w"

{
const YIM yim= YIM_of_TRV(trv);
const AHM ahm= AHM_of_YIM(yim);
const XRL xrl= XRL_of_AHM(ahm);
if(xrl)return ID_of_XRL(xrl);
}
return-1;
}

/*:971*//*972:*/
#line 11564 "./marpa.w"

int marpa_trv_dot(Marpa_Traverser trv)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 11567 "./marpa.w"

/*944:*/
#line 11167 "./marpa.w"

const RECCE r UNUSED= R_of_TRV(trv);
const GRAMMAR g UNUSED= G_of_R(r);

/*:944*/
#line 11568 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 11569 "./marpa.w"

/*969:*/
#line 11538 "./marpa.w"

if(TRV_is_Trivial(trv)){
MARPA_ERROR(MARPA_ERR_GRAMMAR_IS_TRIVIAL);
return failure_indicator;
}

/*:969*/
#line 11570 "./marpa.w"

{
const YIM yim= YIM_of_TRV(trv);
const AHM ahm= AHM_of_YIM(yim);
const int xrl_position= XRL_Position_of_AHM(ahm);
if(xrl_position<-1){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return failure_indicator;
}
return xrl_position;
}
}

/*:972*//*973:*/
#line 11584 "./marpa.w"

int marpa_trv_origin(Marpa_Traverser trv)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 11587 "./marpa.w"

/*944:*/
#line 11167 "./marpa.w"

const RECCE r UNUSED= R_of_TRV(trv);
const GRAMMAR g UNUSED= G_of_R(r);

/*:944*/
#line 11588 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 11589 "./marpa.w"

/*969:*/
#line 11538 "./marpa.w"

if(TRV_is_Trivial(trv)){
MARPA_ERROR(MARPA_ERR_GRAMMAR_IS_TRIVIAL);
return failure_indicator;
}

/*:969*/
#line 11590 "./marpa.w"

{
const YIM yim= YIM_of_TRV(trv);
return Origin_Ord_of_YIM(yim);
}
}

/*:973*//*974:*/
#line 11598 "./marpa.w"

Marpa_IRL_ID marpa_trv_nrl_id(Marpa_Traverser trv)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 11601 "./marpa.w"

/*944:*/
#line 11167 "./marpa.w"

const RECCE r UNUSED= R_of_TRV(trv);
const GRAMMAR g UNUSED= G_of_R(r);

/*:944*/
#line 11602 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 11603 "./marpa.w"

/*969:*/
#line 11538 "./marpa.w"

if(TRV_is_Trivial(trv)){
MARPA_ERROR(MARPA_ERR_GRAMMAR_IS_TRIVIAL);
return failure_indicator;
}

/*:969*/
#line 11604 "./marpa.w"

{
const YIM yim= YIM_of_TRV(trv);
const AHM ahm= AHM_of_YIM(yim);
const IRL nrl= IRL_of_AHM(ahm);
if(nrl)return ID_of_IRL(nrl);
}
return-1;
}

/*:974*//*975:*/
#line 11615 "./marpa.w"

int marpa_trv_nrl_dot(Marpa_Traverser trv)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 11618 "./marpa.w"

/*944:*/
#line 11167 "./marpa.w"

const RECCE r UNUSED= R_of_TRV(trv);
const GRAMMAR g UNUSED= G_of_R(r);

/*:944*/
#line 11619 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 11620 "./marpa.w"

/*969:*/
#line 11538 "./marpa.w"

if(TRV_is_Trivial(trv)){
MARPA_ERROR(MARPA_ERR_GRAMMAR_IS_TRIVIAL);
return failure_indicator;
}

/*:969*/
#line 11621 "./marpa.w"

{
const YIM yim= YIM_of_TRV(trv);
const AHM ahm= AHM_of_YIM(yim);
return Position_of_AHM(ahm);
}
}

/*:975*//*985:*/
#line 11665 "./marpa.w"

int marpa_ltrv_soft_error(Marpa_LTraverser ltrv)
{
return LTRV_has_Soft_Error(ltrv);
}

/*:985*//*990:*/
#line 11683 "./marpa.w"

PRIVATE Marpa_LTraverser
ltrv_new(RECCE r,LIM lim)
{
LTRAVERSER ltrv;

ltrv= my_malloc(sizeof(*ltrv));
/*984:*/
#line 11663 "./marpa.w"

LTRV_has_Soft_Error(ltrv)= 0;
/*:984*//*987:*/
#line 11674 "./marpa.w"

R_of_LTRV(ltrv)= r;

/*:987*//*997:*/
#line 11743 "./marpa.w"

ltrv->t_ref_count= 1;
/*:997*/
#line 11690 "./marpa.w"

recce_ref(r);
LIM_of_LTRV(ltrv)= lim;
return ltrv;
}

/*:990*//*991:*/
#line 11697 "./marpa.w"

Marpa_LTraverser marpa_ltrv_predecessor(Marpa_LTraverser ltrv)
{
/*1312:*/
#line 15626 "./marpa.w"
void*const failure_indicator= NULL;
/*:1312*/
#line 11700 "./marpa.w"

/*988:*/
#line 11677 "./marpa.w"

const RECCE r UNUSED= R_of_LTRV(ltrv);
const GRAMMAR g UNUSED= G_of_R(r);

/*:988*/
#line 11701 "./marpa.w"

LIM predecessor;
/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 11703 "./marpa.w"

LTRV_has_Soft_Error(ltrv)= 0;
predecessor= Predecessor_LIM_of_LIM(LIM_of_LTRV(ltrv));
if(!predecessor){
LTRV_has_Soft_Error(ltrv)= 1;
return NULL;
}
return ltrv_new(r,predecessor);
}

/*:991*//*993:*/
#line 11715 "./marpa.w"

Marpa_Rule_ID
marpa_ltrv_trailhead_eim(Marpa_LTraverser ltrv,int*p_dot,Marpa_Earley_Set_ID*p_origin)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 11719 "./marpa.w"

/*988:*/
#line 11677 "./marpa.w"

const RECCE r UNUSED= R_of_LTRV(ltrv);
const GRAMMAR g UNUSED= G_of_R(r);

/*:988*/
#line 11720 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 11721 "./marpa.w"

{
const LIM lim= LIM_of_LTRV(ltrv);
const AHM ahm= Trailhead_AHM_of_LIM(lim);
const YIM yim= Trailhead_YIM_of_LIM(lim);
const XRL xrl= XRL_of_AHM(ahm);
if(xrl){
if(p_dot)
*p_dot= XRL_Position_of_AHM(ahm);
if(p_origin)
*p_origin= Origin_Ord_of_YIM(yim);
return ID_of_XRL(xrl);
}
}
return-1;
}

/*:993*//*998:*/
#line 11746 "./marpa.w"

PRIVATE void
ltraverser_unref(LTRAVERSER ltrv)
{
MARPA_ASSERT(ltrv->t_ref_count> 0)
ltrv->t_ref_count--;
if(ltrv->t_ref_count<=0)
{
ltraverser_free(ltrv);
}
}
void
marpa_ltrv_unref(Marpa_LTraverser ltrv)
{
ltraverser_unref(ltrv);
}

/*:998*//*999:*/
#line 11764 "./marpa.w"

PRIVATE LTRAVERSER
ltraverser_ref(LTRAVERSER ltrv)
{
MARPA_ASSERT(ltrv->t_ref_count> 0)
ltrv->t_ref_count++;
return ltrv;
}
Marpa_LTraverser
marpa_ltrv_ref(Marpa_LTraverser ltrv)
{
return ltraverser_ref(ltrv);
}

/*:999*//*1001:*/
#line 11781 "./marpa.w"

PRIVATE void
ltraverser_free(LTRAVERSER ltrv)
{
/*988:*/
#line 11677 "./marpa.w"

const RECCE r UNUSED= R_of_LTRV(ltrv);
const GRAMMAR g UNUSED= G_of_R(r);

/*:988*/
#line 11785 "./marpa.w"

if(ltrv)
{
/*981:*/
#line 11655 "./marpa.w"

{
recce_unref(R_of_LTRV(ltrv));
}

/*:981*/
#line 11788 "./marpa.w"
;
}
my_free(ltrv);
}

/*:1001*//*1011:*/
#line 11832 "./marpa.w"

int marpa_ptrv_soft_error(Marpa_PTraverser ptrv)
{
return PTRV_has_Soft_Error(ptrv);
}

/*:1011*//*1016:*/
#line 11853 "./marpa.w"

PRIVATE Marpa_PTraverser
ptrv_new(RECCE r,YS ys,NSYID nsyid)
{
PTRAVERSER ptrv;
const PIM pim= First_PIM_of_YS_by_NSYID(ys,nsyid);

if(!pim)return NULL;
ptrv= my_malloc(sizeof(*ptrv));
/*1010:*/
#line 11830 "./marpa.w"

PTRV_has_Soft_Error(ptrv)= 0;
/*:1010*//*1013:*/
#line 11841 "./marpa.w"

R_of_PTRV(ptrv)= r;

/*:1013*//*1024:*/
#line 11997 "./marpa.w"

ptrv->t_ref_count= 1;
/*:1024*/
#line 11862 "./marpa.w"

recce_ref(r);
PIM_of_PTRV(ptrv)= pim;
PTRV_is_Trivial(ptrv)= 0;
YS_of_PTRV(ptrv)= ys;
return ptrv;
}

/*:1016*//*1017:*/
#line 11874 "./marpa.w"

Marpa_PTraverser marpa_ptrv_new(Marpa_Recognizer r,
Marpa_Earley_Set_ID es_arg,
Marpa_NSY_ID nsyid
)
{
/*1312:*/
#line 15626 "./marpa.w"
void*const failure_indicator= NULL;
/*:1312*/
#line 11880 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 11882 "./marpa.w"


if(_MARPA_UNLIKELY(es_arg<=-2))
{
MARPA_ERROR(MARPA_ERR_INVALID_LOCATION);
return failure_indicator;
}
if(_MARPA_UNLIKELY(nsyid<0))
{
MARPA_ERROR(MARPA_ERR_YIM_ID_INVALID);
return failure_indicator;
}

/*1330:*/
#line 15738 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1330*/
#line 11895 "./marpa.w"


if(G_is_Trivial(g)){
if(es_arg> 0){
MARPA_ERROR(MARPA_ERR_INVALID_LOCATION);
return failure_indicator;
}
return NULL;
}

r_update_earley_sets(r);

{
YS ys;

if(es_arg==-1)
{
ys= YS_at_Current_Earleme_of_R(r);
}
else
{
if(!YS_Ord_is_Valid(r,es_arg))
{
MARPA_ERROR(MARPA_ERR_INVALID_LOCATION);
return failure_indicator;
}
ys= YS_of_R_by_Ord(r,es_arg);
}

return ptrv_new(r,ys,nsyid);
}
}

/*:1017*//*1018:*/
#line 11929 "./marpa.w"

int marpa_ptrv_at_lim(Marpa_PTraverser ptrv)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 11932 "./marpa.w"

/*1014:*/
#line 11844 "./marpa.w"

const RECCE r UNUSED= R_of_PTRV(ptrv);
const GRAMMAR g UNUSED= G_of_R(r);

/*:1014*/
#line 11933 "./marpa.w"

PIM pim;
/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 11935 "./marpa.w"


if(G_is_Trivial(g))return 0;
pim= PIM_of_PTRV(ptrv);
if(!pim)return 0;
return PIM_is_LIM(pim);
}

/*:1018*//*1019:*/
#line 11944 "./marpa.w"

int marpa_ptrv_at_eim(Marpa_PTraverser ptrv)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 11947 "./marpa.w"

/*1014:*/
#line 11844 "./marpa.w"

const RECCE r UNUSED= R_of_PTRV(ptrv);
const GRAMMAR g UNUSED= G_of_R(r);

/*:1014*/
#line 11948 "./marpa.w"

PIM pim;
/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 11950 "./marpa.w"


if(G_is_Trivial(g))return 0;
pim= PIM_of_PTRV(ptrv);
if(!pim)return 0;
return!PIM_is_LIM(pim);
}

/*:1019*//*1021:*/
#line 11963 "./marpa.w"

Marpa_Traverser marpa_ptrv_eim_iter(Marpa_PTraverser ptrv)
{
/*1312:*/
#line 15626 "./marpa.w"
void*const failure_indicator= NULL;
/*:1312*/
#line 11966 "./marpa.w"

/*1014:*/
#line 11844 "./marpa.w"

const RECCE r UNUSED= R_of_PTRV(ptrv);
const GRAMMAR g UNUSED= G_of_R(r);

/*:1014*/
#line 11967 "./marpa.w"

PIM pim;
YIM yim;
/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 11970 "./marpa.w"

PTRV_has_Soft_Error(ptrv)= 0;

if(G_is_Trivial(g)){
PTRV_has_Soft_Error(ptrv)= 1;
MARPA_ERROR(MARPA_ERR_GRAMMAR_IS_TRIVIAL);
return NULL;
}
pim= PIM_of_PTRV(ptrv);
if(!pim){
MARPA_ERROR(MARPA_ERR_NO_TRACE_PIM);
PTRV_has_Soft_Error(ptrv)= 1;
return NULL;
}
if(PIM_is_LIM(pim)){
MARPA_ERROR(MARPA_ERR_NO_TRACE_YIM);
PTRV_has_Soft_Error(ptrv)= 1;
return NULL;
}
yim= YIM_of_PIM(pim);
PIM_of_PTRV(ptrv)= Next_PIM_of_PIM(pim);
return trv_new(r,yim);
}

/*:1021*//*1025:*/
#line 12000 "./marpa.w"

PRIVATE void
ptraverser_unref(PTRAVERSER ptrv)
{
MARPA_ASSERT(ptrv->t_ref_count> 0)
ptrv->t_ref_count--;
if(ptrv->t_ref_count<=0)
{
ptraverser_free(ptrv);
}
}
void
marpa_ptrv_unref(Marpa_PTraverser ptrv)
{
ptraverser_unref(ptrv);
}

/*:1025*//*1026:*/
#line 12018 "./marpa.w"

PRIVATE PTRAVERSER
ptraverser_ref(PTRAVERSER ptrv)
{
MARPA_ASSERT(ptrv->t_ref_count> 0)
ptrv->t_ref_count++;
return ptrv;
}
Marpa_PTraverser
marpa_ptrv_ref(Marpa_PTraverser ptrv)
{
return ptraverser_ref(ptrv);
}

/*:1026*//*1028:*/
#line 12036 "./marpa.w"

PRIVATE void
ptraverser_free(PTRAVERSER ptrv)
{
/*1014:*/
#line 11844 "./marpa.w"

const RECCE r UNUSED= R_of_PTRV(ptrv);
const GRAMMAR g UNUSED= G_of_R(r);

/*:1014*/
#line 12040 "./marpa.w"

if(ptrv)
{
/*1007:*/
#line 11822 "./marpa.w"

{
recce_unref(R_of_PTRV(ptrv));
}

/*:1007*/
#line 12043 "./marpa.w"
;
}
my_free(ptrv);
}

/*:1028*//*1032:*/
#line 12058 "./marpa.w"

int marpa_ptrv_is_trivial(Marpa_PTraverser ptrv)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 12061 "./marpa.w"

/*1014:*/
#line 11844 "./marpa.w"

const RECCE r UNUSED= R_of_PTRV(ptrv);
const GRAMMAR g UNUSED= G_of_R(r);

/*:1014*/
#line 12062 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 12063 "./marpa.w"

return PTRV_is_Trivial(ptrv);
}








/*:1032*//*1047:*/
#line 12150 "./marpa.w"

Marpa_Bocage marpa_b_new(Marpa_Recognizer r,
Marpa_Earley_Set_ID ordinal_arg)
{
/*1312:*/
#line 15626 "./marpa.w"
void*const failure_indicator= NULL;
/*:1312*/
#line 12154 "./marpa.w"

/*1050:*/
#line 12221 "./marpa.w"

const GRAMMAR g= G_of_R(r);
const int xsy_count= XSY_Count_of_G(g);
BOCAGE b= NULL;
YS end_of_parse_earley_set;
JEARLEME end_of_parse_earleme;
YIM start_yim= NULL;
struct marpa_obstack*bocage_setup_obs= NULL;
int count_of_earley_items_in_parse;
const int earley_set_count_of_r= YS_Count_of_R(r);

/*:1050*//*1053:*/
#line 12244 "./marpa.w"

struct s_bocage_setup_per_ys*per_ys_data= NULL;

/*:1053*/
#line 12155 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 12156 "./marpa.w"

if(_MARPA_UNLIKELY(ordinal_arg<=-2))
{
MARPA_ERROR(MARPA_ERR_INVALID_LOCATION);
return failure_indicator;
}

/*1330:*/
#line 15738 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1330*/
#line 12163 "./marpa.w"

{
struct marpa_obstack*const obstack= marpa_obs_init;
b= marpa_obs_new(obstack,struct marpa_bocage,1);
OBS_of_B(b)= obstack;
}
/*1039:*/
#line 12107 "./marpa.w"

ORs_of_B(b)= NULL;
OR_Count_of_B(b)= 0;
ANDs_of_B(b)= NULL;
AND_Count_of_B(b)= 0;
Top_ORID_of_B(b)= -1;

/*:1039*//*1042:*/
#line 12130 "./marpa.w"

{
G_of_B(b)= G_of_R(r);
grammar_ref(g);
}

/*:1042*//*1049:*/
#line 12216 "./marpa.w"

Valued_BV_of_B(b)= lbv_clone(b->t_obs,r->t_valued,xsy_count);
Valued_Locked_BV_of_B(b)= 
lbv_clone(b->t_obs,r->t_valued_locked,xsy_count);

/*:1049*//*1063:*/
#line 12361 "./marpa.w"

Ambiguity_Metric_of_B(b)= 1;

/*:1063*//*1067:*/
#line 12375 "./marpa.w"

b->t_ref_count= 1;
/*:1067*//*1074:*/
#line 12433 "./marpa.w"

B_is_Nulling(b)= 0;
/*:1074*/
#line 12169 "./marpa.w"


if(G_is_Trivial(g)){
switch(ordinal_arg){
default:goto NO_PARSE;
case 0:case-1:break;
}
B_is_Nulling(b)= 1;
return b;
}
r_update_earley_sets(r);
/*1054:*/
#line 12247 "./marpa.w"

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

/*:1054*/
#line 12180 "./marpa.w"

if(end_of_parse_earleme==0)
{
if(!XSY_is_Nullable(XSY_by_ID(g->t_start_xsy_id)))
goto NO_PARSE;
B_is_Nulling(b)= 1;
return b;
}
/*1057:*/
#line 12313 "./marpa.w"

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

/*:1057*/
#line 12188 "./marpa.w"

if(!start_yim)goto NO_PARSE;
bocage_setup_obs= marpa_obs_init;
/*1055:*/
#line 12269 "./marpa.w"

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

/*:1055*/
#line 12191 "./marpa.w"

/*871:*/
#line 10139 "./marpa.w"

{
UR_Const ur_node;
const URS ur_node_stack= URS_of_R(r);
ur_node_stack_reset(ur_node_stack);


push_ur_if_new(per_ys_data,ur_node_stack,start_yim);
while((ur_node= ur_node_pop(ur_node_stack)))
{

const YIM parent_earley_item= YIM_of_UR(ur_node);
MARPA_ASSERT(!YIM_was_Predicted(parent_earley_item))
/*874:*/
#line 10192 "./marpa.w"

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

/*:874*/
#line 10152 "./marpa.w"

/*876:*/
#line 10226 "./marpa.w"

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

/*:876*/
#line 10153 "./marpa.w"

/*877:*/
#line 10249 "./marpa.w"

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

/*:877*/
#line 10154 "./marpa.w"

}
}

/*:871*/
#line 12192 "./marpa.w"

/*889:*/
#line 10376 "./marpa.w"

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
/*890:*/
#line 10402 "./marpa.w"

{
int item_ordinal;
for(item_ordinal= 0;item_ordinal<item_count;
item_ordinal++)
{
if(OR_by_PSI(per_ys_data,work_earley_set_ordinal,item_ordinal))
{
const YIM work_earley_item= yims_of_ys[item_ordinal];
{
/*891:*/
#line 10418 "./marpa.w"

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
/*893:*/
#line 10452 "./marpa.w"

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

/*:893*/
#line 10431 "./marpa.w"

/*896:*/
#line 10500 "./marpa.w"

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

/*:896*/
#line 10432 "./marpa.w"

}



MARPA_OFF_ASSERT(psi_or_node)




OR_by_PSI(per_ys_data,working_ys_ordinal,working_yim_ordinal)
= psi_or_node;
/*897:*/
#line 10535 "./marpa.w"

{
SRCL source_link;
for(source_link= First_Leo_SRCL_of_YIM(work_earley_item);
source_link;source_link= Next_SRCL_of_SRCL(source_link))
{
LIM leo_predecessor= LIM_of_SRCL(source_link);
if(leo_predecessor){
/*898:*/
#line 10552 "./marpa.w"

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
/*899:*/
#line 10574 "./marpa.w"

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

/*:899*/
#line 10564 "./marpa.w"

/*900:*/
#line 10599 "./marpa.w"

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

/*:900*/
#line 10565 "./marpa.w"

}
previous_leo_item= this_leo_item;
}
}

/*:898*/
#line 10543 "./marpa.w"

}
}
}

/*:897*/
#line 10444 "./marpa.w"

}

/*:891*/
#line 10412 "./marpa.w"

}
}
}
}

/*:890*/
#line 10395 "./marpa.w"

/*906:*/
#line 10695 "./marpa.w"

{
int item_ordinal;
for(item_ordinal= 0;item_ordinal<item_count;item_ordinal++)
{
OR or_node= OR_by_PSI(per_ys_data,work_earley_set_ordinal,item_ordinal);
const YIM work_earley_item= yims_of_ys[item_ordinal];
const int work_origin_ordinal= Ord_of_YS(Origin_of_YIM(work_earley_item));
/*907:*/
#line 10712 "./marpa.w"

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

/*:907*/
#line 10703 "./marpa.w"

if(or_node){
/*908:*/
#line 10726 "./marpa.w"

{
const AHM work_ahm= AHM_of_YIM(work_earley_item);
MARPA_ASSERT(work_ahm>=AHM_by_ID(1))
const int work_symbol_instance= SYMI_of_AHM(work_ahm);
const OR work_proper_or_node= or_by_origin_and_symi(per_ys_data,
work_origin_ordinal,work_symbol_instance);
/*910:*/
#line 10768 "./marpa.w"

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
/*911:*/
#line 10789 "./marpa.w"

{

IRL path_irl= NULL;

IRL previous_path_irl;
LIM path_leo_item= leo_predecessor;
LIM higher_path_leo_item= Predecessor_LIM_of_LIM(path_leo_item);
OR dand_predecessor;
OR path_or_node;
YIM base_earley_item= Trailhead_YIM_of_LIM(path_leo_item);
dand_predecessor= set_or_from_yim(per_ys_data,base_earley_item);
/*912:*/
#line 10816 "./marpa.w"

{
if(higher_path_leo_item){
/*921:*/
#line 10944 "./marpa.w"

{
int symbol_instance;
const int origin_ordinal= Origin_Ord_of_YIM(base_earley_item);
const AHM ahm= AHM_of_YIM(base_earley_item);
path_irl= IRL_of_AHM(ahm);
symbol_instance= Last_Proper_SYMI_of_IRL(path_irl);
path_or_node= or_by_origin_and_symi(per_ys_data,origin_ordinal,symbol_instance);
}


/*:921*/
#line 10819 "./marpa.w"

}else{
path_or_node= work_proper_or_node;
}
}

/*:912*/
#line 10801 "./marpa.w"

/*914:*/
#line 10835 "./marpa.w"

{
const OR dand_cause
= set_or_from_yim(per_ys_data,cause_earley_item);
if(!dand_is_duplicate(path_or_node,dand_predecessor,dand_cause)){
draft_and_node_add(bocage_setup_obs,path_or_node,
dand_predecessor,dand_cause);
}
}

/*:914*/
#line 10802 "./marpa.w"

previous_path_irl= path_irl;
while(higher_path_leo_item){
path_leo_item= higher_path_leo_item;
higher_path_leo_item= Predecessor_LIM_of_LIM(path_leo_item);
base_earley_item= Trailhead_YIM_of_LIM(path_leo_item);
dand_predecessor
= set_or_from_yim(per_ys_data,base_earley_item);
/*912:*/
#line 10816 "./marpa.w"

{
if(higher_path_leo_item){
/*921:*/
#line 10944 "./marpa.w"

{
int symbol_instance;
const int origin_ordinal= Origin_Ord_of_YIM(base_earley_item);
const AHM ahm= AHM_of_YIM(base_earley_item);
path_irl= IRL_of_AHM(ahm);
symbol_instance= Last_Proper_SYMI_of_IRL(path_irl);
path_or_node= or_by_origin_and_symi(per_ys_data,origin_ordinal,symbol_instance);
}


/*:921*/
#line 10819 "./marpa.w"

}else{
path_or_node= work_proper_or_node;
}
}

/*:912*/
#line 10810 "./marpa.w"

/*917:*/
#line 10861 "./marpa.w"

{
const SYMI symbol_instance= SYMI_of_Completed_IRL(previous_path_irl);
const int origin= Ord_of_YS(YS_of_LIM(path_leo_item));
const OR dand_cause= or_by_origin_and_symi(per_ys_data,origin,symbol_instance);
if(!dand_is_duplicate(path_or_node,dand_predecessor,dand_cause)){
draft_and_node_add(bocage_setup_obs,path_or_node,
dand_predecessor,dand_cause);
}
}

/*:917*/
#line 10811 "./marpa.w"

previous_path_irl= path_irl;
}
}

/*:911*/
#line 10783 "./marpa.w"

}
}
}

/*:910*/
#line 10733 "./marpa.w"

/*922:*/
#line 10959 "./marpa.w"

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

/*:922*/
#line 10734 "./marpa.w"

/*924:*/
#line 11001 "./marpa.w"

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

/*:924*/
#line 10735 "./marpa.w"

}

/*:908*/
#line 10705 "./marpa.w"

}
}
}

/*:906*/
#line 10396 "./marpa.w"

}
psar_destroy(or_psar);
ORs_of_B(b)= marpa_renew(OR,ORs_of_B(b),OR_Count_of_B(b));
}

/*:889*/
#line 12193 "./marpa.w"

/*930:*/
#line 11073 "./marpa.w"

{
int unique_draft_and_node_count= 0;
/*925:*/
#line 11026 "./marpa.w"

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

/*:925*/
#line 11076 "./marpa.w"

/*931:*/
#line 11080 "./marpa.w"

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

/*:931*/
#line 11077 "./marpa.w"

}

/*:930*/
#line 12194 "./marpa.w"

/*1058:*/
#line 12334 "./marpa.w"

{
const YSID end_of_parse_ordinal= Ord_of_YS(end_of_parse_earley_set);
const int start_earley_item_ordinal= Ord_of_YIM(start_yim);
const OR root_or_node= 
OR_by_PSI(per_ys_data,end_of_parse_ordinal,start_earley_item_ordinal);
Top_ORID_of_B(b)= ID_of_OR(root_or_node);
}

/*:1058*/
#line 12195 "./marpa.w"
;
marpa_obs_free(bocage_setup_obs);
return b;
NO_PARSE:;
MARPA_ERROR(MARPA_ERR_NO_PARSE);
if(b){
/*1070:*/
#line 12411 "./marpa.w"

/*1040:*/
#line 12114 "./marpa.w"

{
OR*or_nodes= ORs_of_B(b);
AND and_nodes= ANDs_of_B(b);

grammar_unref(G_of_B(b));
my_free(or_nodes);
ORs_of_B(b)= NULL;
my_free(and_nodes);
ANDs_of_B(b)= NULL;
}

/*:1040*/
#line 12412 "./marpa.w"
;
/*1046:*/
#line 12146 "./marpa.w"

marpa_obs_free(OBS_of_B(b));

/*:1046*/
#line 12413 "./marpa.w"
;

/*:1070*/
#line 12201 "./marpa.w"
;
}
return NULL;
}

/*:1047*//*1060:*/
#line 12345 "./marpa.w"

Marpa_Or_Node_ID _marpa_b_top_or_node(Marpa_Bocage b)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 12348 "./marpa.w"

/*1044:*/
#line 12138 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:1044*/
#line 12349 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 12350 "./marpa.w"

return Top_ORID_of_B(b);
}

/*:1060*//*1064:*/
#line 12364 "./marpa.w"

int marpa_b_ambiguity_metric(Marpa_Bocage b)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 12367 "./marpa.w"

/*1044:*/
#line 12138 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:1044*/
#line 12368 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 12369 "./marpa.w"

return Ambiguity_Metric_of_B(b);
}

/*:1064*//*1068:*/
#line 12378 "./marpa.w"

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

/*:1068*//*1069:*/
#line 12396 "./marpa.w"

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

/*:1069*//*1071:*/
#line 12417 "./marpa.w"

PRIVATE void
bocage_free(BOCAGE b)
{
/*1044:*/
#line 12138 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:1044*/
#line 12421 "./marpa.w"

if(b)
{
/*1070:*/
#line 12411 "./marpa.w"

/*1040:*/
#line 12114 "./marpa.w"

{
OR*or_nodes= ORs_of_B(b);
AND and_nodes= ANDs_of_B(b);

grammar_unref(G_of_B(b));
my_free(or_nodes);
ORs_of_B(b)= NULL;
my_free(and_nodes);
ANDs_of_B(b)= NULL;
}

/*:1040*/
#line 12412 "./marpa.w"
;
/*1046:*/
#line 12146 "./marpa.w"

marpa_obs_free(OBS_of_B(b));

/*:1046*/
#line 12413 "./marpa.w"
;

/*:1070*/
#line 12424 "./marpa.w"
;
}
}

/*:1071*//*1075:*/
#line 12435 "./marpa.w"

int marpa_b_is_null(Marpa_Bocage b)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 12438 "./marpa.w"

/*1044:*/
#line 12138 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:1044*/
#line 12439 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 12440 "./marpa.w"

return B_is_Nulling(b);
}

/*:1075*//*1082:*/
#line 12480 "./marpa.w"

Marpa_Order marpa_o_new(Marpa_Bocage b)
{
/*1312:*/
#line 15626 "./marpa.w"
void*const failure_indicator= NULL;
/*:1312*/
#line 12483 "./marpa.w"

/*1044:*/
#line 12138 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:1044*/
#line 12484 "./marpa.w"

ORDER o;
/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 12486 "./marpa.w"

o= my_malloc(sizeof(*o));
B_of_O(o)= b;
bocage_ref(b);
/*1079:*/
#line 12468 "./marpa.w"

{
o->t_and_node_orderings= NULL;
o->t_is_frozen= 0;
OBS_of_O(o)= NULL;
}

/*:1079*//*1085:*/
#line 12498 "./marpa.w"

o->t_ref_count= 1;

/*:1085*//*1098:*/
#line 12666 "./marpa.w"

High_Rank_Count_of_O(o)= 1;
/*:1098*/
#line 12490 "./marpa.w"

O_is_Nulling(o)= B_is_Nulling(b);
Ambiguity_Metric_of_O(o)= -1;
return o;
}

/*:1082*//*1086:*/
#line 12502 "./marpa.w"

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

/*:1086*//*1087:*/
#line 12520 "./marpa.w"

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

/*:1087*//*1088:*/
#line 12534 "./marpa.w"

PRIVATE void order_free(ORDER o)
{
/*1089:*/
#line 12543 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1044:*/
#line 12138 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:1044*/
#line 12545 "./marpa.w"


/*:1089*/
#line 12537 "./marpa.w"

bocage_unref(b);
marpa_obs_free(OBS_of_O(o));
my_free(o);
}

/*:1088*//*1092:*/
#line 12555 "./marpa.w"

int marpa_o_ambiguity_metric(Marpa_Order o)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 12558 "./marpa.w"

/*1089:*/
#line 12543 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1044:*/
#line 12138 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:1044*/
#line 12545 "./marpa.w"


/*:1089*/
#line 12559 "./marpa.w"

const int old_ambiguity_metric_of_o
= Ambiguity_Metric_of_O(o);
const int ambiguity_metric_of_b
= (Ambiguity_Metric_of_B(b)<=1?1:2);
/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 12564 "./marpa.w"

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
/*1093:*/
#line 12583 "./marpa.w"

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

/*:1093*/
#line 12575 "./marpa.w"

return Ambiguity_Metric_of_O(o);
}

/*:1092*//*1096:*/
#line 12649 "./marpa.w"

int marpa_o_is_null(Marpa_Order o)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 12652 "./marpa.w"

/*1089:*/
#line 12543 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1044:*/
#line 12138 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:1044*/
#line 12545 "./marpa.w"


/*:1089*/
#line 12653 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 12654 "./marpa.w"

return O_is_Nulling(o);
}

/*:1096*//*1099:*/
#line 12668 "./marpa.w"

int marpa_o_high_rank_only_set(
Marpa_Order o,
int count)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 12673 "./marpa.w"

/*1089:*/
#line 12543 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1044:*/
#line 12138 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:1044*/
#line 12545 "./marpa.w"


/*:1089*/
#line 12674 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 12675 "./marpa.w"

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

/*:1099*//*1100:*/
#line 12690 "./marpa.w"

int marpa_o_high_rank_only(Marpa_Order o)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 12693 "./marpa.w"

/*1089:*/
#line 12543 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1044:*/
#line 12138 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:1044*/
#line 12545 "./marpa.w"


/*:1089*/
#line 12694 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 12695 "./marpa.w"

return High_Rank_Count_of_O(o);
}

/*:1100*//*1104:*/
#line 12732 "./marpa.w"

int marpa_o_rank(Marpa_Order o)
{
ANDID**and_node_orderings;
struct marpa_obstack*obs;
int bocage_was_reordered= 0;
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 12738 "./marpa.w"

/*1089:*/
#line 12543 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1044:*/
#line 12138 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:1044*/
#line 12545 "./marpa.w"


/*:1089*/
#line 12739 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 12740 "./marpa.w"

if(O_is_Frozen(o))
{
MARPA_ERROR(MARPA_ERR_ORDER_FROZEN);
return failure_indicator;
}
/*1110:*/
#line 12901 "./marpa.w"

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

/*:1110*/
#line 12746 "./marpa.w"

if(High_Rank_Count_of_O(o)){
/*1105:*/
#line 12761 "./marpa.w"

{
const AND and_nodes= ANDs_of_B(b);
const int or_node_count_of_b= OR_Count_of_B(b);
int or_node_id= 0;

while(or_node_id<or_node_count_of_b)
{
const OR work_or_node= OR_of_B_by_ID(b,or_node_id);
const ANDID and_count_of_or= AND_Count_of_OR(work_or_node);
/*1106:*/
#line 12776 "./marpa.w"

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
/*1107:*/
#line 12814 "./marpa.w"

{
const OR cause_or= Cause_OR_of_AND(and_node);
if(OR_is_Token(cause_or)){
const NSYID nsy_id= NSYID_of_OR(cause_or);
and_node_rank= Rank_of_NSY(NSY_by_ID(nsy_id));
}else{
and_node_rank= Rank_of_IRL(IRL_of_OR(cause_or));
}
}

/*:1107*/
#line 12796 "./marpa.w"

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

/*:1106*/
#line 12771 "./marpa.w"

or_node_id++;
}
}

/*:1105*/
#line 12748 "./marpa.w"

}else{
/*1108:*/
#line 12825 "./marpa.w"

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
/*1107:*/
#line 12814 "./marpa.w"

{
const OR cause_or= Cause_OR_of_AND(and_node);
if(OR_is_Token(cause_or)){
const NSYID nsy_id= NSYID_of_OR(cause_or);
and_node_rank= Rank_of_NSY(NSY_by_ID(nsy_id));
}else{
and_node_rank= Rank_of_IRL(IRL_of_OR(cause_or));
}
}

/*:1107*/
#line 12837 "./marpa.w"

rank_by_and_id[and_node_id]= and_node_rank;
}
while(or_node_id<or_node_count_of_b)
{
const OR work_or_node= OR_of_B_by_ID(b,or_node_id);
const ANDID and_count_of_or= AND_Count_of_OR(work_or_node);
/*1109:*/
#line 12870 "./marpa.w"

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

/*:1109*/
#line 12844 "./marpa.w"

or_node_id++;
}
my_free(rank_by_and_id);
}

/*:1108*/
#line 12750 "./marpa.w"

}
if(!bocage_was_reordered){
marpa_obs_free(obs);
OBS_of_O(o)= NULL;
o->t_and_node_orderings= NULL;
}
O_is_Frozen(o)= 1;
return 1;
}

/*:1104*//*1111:*/
#line 12918 "./marpa.w"

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

/*:1111*//*1112:*/
#line 12939 "./marpa.w"

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

/*:1112*//*1113:*/
#line 12953 "./marpa.w"

Marpa_And_Node_ID _marpa_o_and_order_get(Marpa_Order o,
Marpa_Or_Node_ID or_node_id,int ix)
{
OR or_node;
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 12958 "./marpa.w"

/*1089:*/
#line 12543 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1044:*/
#line 12138 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:1044*/
#line 12545 "./marpa.w"


/*:1089*/
#line 12959 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 12960 "./marpa.w"

/*1400:*/
#line 16732 "./marpa.w"

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
/*:1400*/
#line 12961 "./marpa.w"

/*1401:*/
#line 16744 "./marpa.w"

{
if(_MARPA_UNLIKELY(!ORs_of_B(b)))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= OR_of_B_by_ID(b,or_node_id);
}

/*:1401*/
#line 12962 "./marpa.w"

if(ix<0){
MARPA_ERROR(MARPA_ERR_ANDIX_NEGATIVE);
return failure_indicator;
}
if(!and_order_ix_is_valid(o,or_node,ix))return-1;
return and_order_get(o,or_node,ix);
}

/*:1113*//*1118:*/
#line 13015 "./marpa.w"

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

/*:1118*//*1119:*/
#line 13033 "./marpa.w"

Marpa_Tree marpa_t_new(Marpa_Order o)
{
/*1312:*/
#line 15626 "./marpa.w"
void*const failure_indicator= NULL;
/*:1312*/
#line 13036 "./marpa.w"

TREE t;
/*1089:*/
#line 12543 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1044:*/
#line 12138 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:1044*/
#line 12545 "./marpa.w"


/*:1089*/
#line 13038 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 13039 "./marpa.w"

t= my_malloc(sizeof(*t));
O_of_T(t)= o;
order_ref(o);
O_is_Frozen(o)= 1;
/*1132:*/
#line 13186 "./marpa.w"

T_is_Exhausted(t)= 0;

/*:1132*/
#line 13044 "./marpa.w"

/*1120:*/
#line 13049 "./marpa.w"

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

/*:1120*//*1123:*/
#line 13073 "./marpa.w"

t->t_ref_count= 1;

/*:1123*//*1128:*/
#line 13125 "./marpa.w"
t->t_generation= 0;

/*:1128*/
#line 13045 "./marpa.w"

return t;
}

/*:1119*//*1124:*/
#line 13077 "./marpa.w"

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

/*:1124*//*1125:*/
#line 13095 "./marpa.w"

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

/*:1125*//*1126:*/
#line 13109 "./marpa.w"

PRIVATE void tree_free(TREE t)
{
order_unref(O_of_T(t));
tree_exhaust(t);
my_free(t);
}

/*:1126*//*1129:*/
#line 13128 "./marpa.w"

int marpa_t_next(Marpa_Tree t)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 13131 "./marpa.w"

const int termination_indicator= -1;
int is_first_tree_attempt= (t->t_parse_count<1);
/*1117:*/
#line 13011 "./marpa.w"

ORDER o= O_of_T(t);
/*1089:*/
#line 12543 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1044:*/
#line 12138 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:1044*/
#line 12545 "./marpa.w"


/*:1089*/
#line 13013 "./marpa.w"
;

/*:1117*/
#line 13134 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 13135 "./marpa.w"

{
const unsigned int next_generation= T_Generation(t)+1;
if(next_generation> UINT_MAX-42)
{
MARPA_ERROR(MARPA_ERR_DEVELOPMENT);
return termination_indicator;
}
T_Generation(t)= next_generation;
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
/*1138:*/
#line 13215 "./marpa.w"

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

/*:1138*/
#line 13165 "./marpa.w"

}else{
/*1139:*/
#line 13240 "./marpa.w"
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

/*:1139*/
#line 13167 "./marpa.w"

}
/*1140:*/
#line 13282 "./marpa.w"
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
/*1141:*/
#line 13345 "./marpa.w"

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

/*:1141*/
#line 13339 "./marpa.w"
;
NEXT_NOOK_ON_WORKLIST:;
}
NEXT_TREE:;
}

/*:1140*/
#line 13169 "./marpa.w"

}
TREE_IS_FINISHED:;
t->t_parse_count++;
return FSTACK_LENGTH(t->t_nook_stack);
TREE_IS_EXHAUSTED:;
tree_exhaust(t);
MARPA_ERROR(MARPA_ERR_TREE_EXHAUSTED);
return termination_indicator;

}

/*:1129*//*1136:*/
#line 13202 "./marpa.w"

PRIVATE int tree_or_node_try(TREE tree,ORID or_node_id)
{
return!bv_bit_test_then_set(tree->t_or_node_in_use,or_node_id);
}
/*:1136*//*1137:*/
#line 13208 "./marpa.w"

PRIVATE void tree_or_node_release(TREE tree,ORID or_node_id)
{
bv_bit_clear(tree->t_or_node_in_use,or_node_id);
}

/*:1137*//*1142:*/
#line 13366 "./marpa.w"

int marpa_t_parse_count(Marpa_Tree t)
{
return t->t_parse_count;
}

/*:1142*//*1143:*/
#line 13374 "./marpa.w"

int _marpa_t_size(Marpa_Tree t)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 13377 "./marpa.w"

/*1117:*/
#line 13011 "./marpa.w"

ORDER o= O_of_T(t);
/*1089:*/
#line 12543 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1044:*/
#line 12138 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:1044*/
#line 12545 "./marpa.w"


/*:1089*/
#line 13013 "./marpa.w"
;

/*:1117*/
#line 13378 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 13379 "./marpa.w"

if(T_is_Exhausted(t)){
MARPA_ERROR(MARPA_ERR_TREE_EXHAUSTED);
return failure_indicator;
}
if(T_is_Nulling(t))return 0;
return Size_of_T(t);
}

/*:1143*//*1164:*/
#line 13592 "./marpa.w"

Marpa_Value marpa_v_new(Marpa_Tree t)
{
/*1312:*/
#line 15626 "./marpa.w"
void*const failure_indicator= NULL;
/*:1312*/
#line 13595 "./marpa.w"

/*1117:*/
#line 13011 "./marpa.w"

ORDER o= O_of_T(t);
/*1089:*/
#line 12543 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1044:*/
#line 12138 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:1044*/
#line 12545 "./marpa.w"


/*:1089*/
#line 13013 "./marpa.w"
;

/*:1117*/
#line 13596 "./marpa.w"
;
/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 13597 "./marpa.w"

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
V_T_Generation(v)= T_Generation(t);
/*1155:*/
#line 13518 "./marpa.w"

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

/*:1155*//*1162:*/
#line 13581 "./marpa.w"

MARPA_DSTACK_SAFE(VStack_of_V(v));
/*:1162*//*1167:*/
#line 13629 "./marpa.w"

v->t_ref_count= 1;

/*:1167*//*1177:*/
#line 13700 "./marpa.w"

V_is_Nulling(v)= 0;

/*:1177*//*1179:*/
#line 13707 "./marpa.w"

V_is_Trace(v)= 0;
/*:1179*//*1182:*/
#line 13729 "./marpa.w"

NOOK_of_V(v)= -1;
/*:1182*//*1187:*/
#line 13757 "./marpa.w"

{
XSY_is_Valued_BV_of_V(v)= lbv_clone(v->t_obs,Valued_BV_of_B(b),xsy_count);
Valued_Locked_BV_of_V(v)= 
lbv_clone(v->t_obs,Valued_Locked_BV_of_B(b),xsy_count);
}


/*:1187*/
#line 13610 "./marpa.w"

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

/*:1164*//*1168:*/
#line 13633 "./marpa.w"

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

/*:1168*//*1169:*/
#line 13651 "./marpa.w"

PRIVATE VALUE
value_ref(VALUE v)
{
MARPA_ASSERT(v->t_ref_count> 0)
v->t_ref_count++;
return v;
}
Marpa_Value
marpa_v_ref(Marpa_Value public_v)
{
/*1312:*/
#line 15626 "./marpa.w"
void*const failure_indicator= NULL;
/*:1312*/
#line 13662 "./marpa.w"

const VALUE v= (VALUE)public_v;
/*1171:*/
#line 13677 "./marpa.w"

TREE t= T_of_V(v);
/*1117:*/
#line 13011 "./marpa.w"

ORDER o= O_of_T(t);
/*1089:*/
#line 12543 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1044:*/
#line 12138 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:1044*/
#line 12545 "./marpa.w"


/*:1089*/
#line 13013 "./marpa.w"
;

/*:1117*/
#line 13679 "./marpa.w"


/*:1171*/
#line 13664 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 13665 "./marpa.w"

/*1174:*/
#line 13689 "./marpa.w"

if(_MARPA_UNLIKELY(V_T_Generation(v)!=T_Generation(t))){
MARPA_ERROR(MARPA_ERR_BASE_GENERATION_MISMATCH);
return failure_indicator;
}

/*:1174*/
#line 13666 "./marpa.w"

return(Marpa_Value)value_ref(v);
}

/*:1169*//*1170:*/
#line 13670 "./marpa.w"

PRIVATE void value_free(VALUE v)
{
/*1163:*/
#line 13583 "./marpa.w"

{
if(_MARPA_LIKELY(MARPA_DSTACK_IS_INITIALIZED(VStack_of_V(v))!=NULL))
{
MARPA_DSTACK_DESTROY(VStack_of_V(v));
}
}

/*:1163*/
#line 13673 "./marpa.w"

/*1157:*/
#line 13534 "./marpa.w"

marpa_obs_free(v->t_obs);

/*:1157*/
#line 13674 "./marpa.w"

}

/*:1170*//*1180:*/
#line 13709 "./marpa.w"

int _marpa_v_trace(Marpa_Value public_v,int flag)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 13712 "./marpa.w"

const VALUE v= (VALUE)public_v;
/*1171:*/
#line 13677 "./marpa.w"

TREE t= T_of_V(v);
/*1117:*/
#line 13011 "./marpa.w"

ORDER o= O_of_T(t);
/*1089:*/
#line 12543 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1044:*/
#line 12138 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:1044*/
#line 12545 "./marpa.w"


/*:1089*/
#line 13013 "./marpa.w"
;

/*:1117*/
#line 13679 "./marpa.w"


/*:1171*/
#line 13714 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 13715 "./marpa.w"

/*1174:*/
#line 13689 "./marpa.w"

if(_MARPA_UNLIKELY(V_T_Generation(v)!=T_Generation(t))){
MARPA_ERROR(MARPA_ERR_BASE_GENERATION_MISMATCH);
return failure_indicator;
}

/*:1174*/
#line 13716 "./marpa.w"

if(_MARPA_UNLIKELY(!V_is_Active(v))){
MARPA_ERROR(MARPA_ERR_VALUATOR_INACTIVE);
return failure_indicator;
}
V_is_Trace(v)= Boolean(flag);
return 1;
}

/*:1180*//*1183:*/
#line 13732 "./marpa.w"

Marpa_Nook_ID _marpa_v_nook(Marpa_Value public_v)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 13735 "./marpa.w"

const VALUE v= (VALUE)public_v;
/*1171:*/
#line 13677 "./marpa.w"

TREE t= T_of_V(v);
/*1117:*/
#line 13011 "./marpa.w"

ORDER o= O_of_T(t);
/*1089:*/
#line 12543 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1044:*/
#line 12138 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:1044*/
#line 12545 "./marpa.w"


/*:1089*/
#line 13013 "./marpa.w"
;

/*:1117*/
#line 13679 "./marpa.w"


/*:1171*/
#line 13737 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 13738 "./marpa.w"

/*1174:*/
#line 13689 "./marpa.w"

if(_MARPA_UNLIKELY(V_T_Generation(v)!=T_Generation(t))){
MARPA_ERROR(MARPA_ERR_BASE_GENERATION_MISMATCH);
return failure_indicator;
}

/*:1174*/
#line 13739 "./marpa.w"

if(_MARPA_UNLIKELY(V_is_Nulling(v)))return-1;
if(_MARPA_UNLIKELY(!V_is_Active(v))){
MARPA_ERROR(MARPA_ERR_VALUATOR_INACTIVE);
return failure_indicator;
}
return NOOK_of_V(v);
}

/*:1183*//*1188:*/
#line 13766 "./marpa.w"

PRIVATE int symbol_is_valued(
VALUE v,
Marpa_Symbol_ID xsy_id)
{
return lbv_bit_test(XSY_is_Valued_BV_of_V(v),xsy_id);
}

/*:1188*//*1189:*/
#line 13775 "./marpa.w"

int marpa_v_symbol_is_valued(
Marpa_Value public_v,
Marpa_Symbol_ID xsy_id)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 13780 "./marpa.w"

const VALUE v= (VALUE)public_v;
/*1171:*/
#line 13677 "./marpa.w"

TREE t= T_of_V(v);
/*1117:*/
#line 13011 "./marpa.w"

ORDER o= O_of_T(t);
/*1089:*/
#line 12543 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1044:*/
#line 12138 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:1044*/
#line 12545 "./marpa.w"


/*:1089*/
#line 13013 "./marpa.w"
;

/*:1117*/
#line 13679 "./marpa.w"


/*:1171*/
#line 13782 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 13783 "./marpa.w"

/*1174:*/
#line 13689 "./marpa.w"

if(_MARPA_UNLIKELY(V_T_Generation(v)!=T_Generation(t))){
MARPA_ERROR(MARPA_ERR_BASE_GENERATION_MISMATCH);
return failure_indicator;
}

/*:1174*/
#line 13784 "./marpa.w"

/*1316:*/
#line 15645 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1316*/
#line 13785 "./marpa.w"

/*1317:*/
#line 15652 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1317*/
#line 13786 "./marpa.w"

return lbv_bit_test(XSY_is_Valued_BV_of_V(v),xsy_id);
}

/*:1189*//*1190:*/
#line 13792 "./marpa.w"

PRIVATE int symbol_is_valued_set(
VALUE v,XSYID xsy_id,int value)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 13796 "./marpa.w"

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

/*:1190*//*1191:*/
#line 13815 "./marpa.w"

int marpa_v_symbol_is_valued_set(
Marpa_Value public_v,Marpa_Symbol_ID xsy_id,int value)
{
const VALUE v= (VALUE)public_v;
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 13820 "./marpa.w"

/*1171:*/
#line 13677 "./marpa.w"

TREE t= T_of_V(v);
/*1117:*/
#line 13011 "./marpa.w"

ORDER o= O_of_T(t);
/*1089:*/
#line 12543 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1044:*/
#line 12138 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:1044*/
#line 12545 "./marpa.w"


/*:1089*/
#line 13013 "./marpa.w"
;

/*:1117*/
#line 13679 "./marpa.w"


/*:1171*/
#line 13821 "./marpa.w"

/*1174:*/
#line 13689 "./marpa.w"

if(_MARPA_UNLIKELY(V_T_Generation(v)!=T_Generation(t))){
MARPA_ERROR(MARPA_ERR_BASE_GENERATION_MISMATCH);
return failure_indicator;
}

/*:1174*/
#line 13822 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 13823 "./marpa.w"

if(_MARPA_UNLIKELY(value<0||value> 1))
{
MARPA_ERROR(MARPA_ERR_INVALID_BOOLEAN);
return failure_indicator;
}
/*1316:*/
#line 15645 "./marpa.w"

if(_MARPA_UNLIKELY(XSYID_is_Malformed(xsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1316*/
#line 13829 "./marpa.w"

/*1317:*/
#line 15652 "./marpa.w"

if(_MARPA_UNLIKELY(!XSYID_of_G_Exists(xsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}
/*:1317*/
#line 13830 "./marpa.w"

return symbol_is_valued_set(v,xsy_id,value);
}

/*:1191*//*1192:*/
#line 13836 "./marpa.w"

int
marpa_v_valued_force(Marpa_Value public_v)
{
const VALUE v= (VALUE)public_v;
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 13841 "./marpa.w"

XSYID xsy_count;
XSYID xsy_id;
/*1171:*/
#line 13677 "./marpa.w"

TREE t= T_of_V(v);
/*1117:*/
#line 13011 "./marpa.w"

ORDER o= O_of_T(t);
/*1089:*/
#line 12543 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1044:*/
#line 12138 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:1044*/
#line 12545 "./marpa.w"


/*:1089*/
#line 13013 "./marpa.w"
;

/*:1117*/
#line 13679 "./marpa.w"


/*:1171*/
#line 13844 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 13845 "./marpa.w"

/*1174:*/
#line 13689 "./marpa.w"

if(_MARPA_UNLIKELY(V_T_Generation(v)!=T_Generation(t))){
MARPA_ERROR(MARPA_ERR_BASE_GENERATION_MISMATCH);
return failure_indicator;
}

/*:1174*/
#line 13846 "./marpa.w"

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

/*:1192*//*1193:*/
#line 13861 "./marpa.w"

int marpa_v_rule_is_valued_set(
Marpa_Value public_v,Marpa_Rule_ID xrl_id,int value)
{
const VALUE v= (VALUE)public_v;
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 13866 "./marpa.w"

/*1171:*/
#line 13677 "./marpa.w"

TREE t= T_of_V(v);
/*1117:*/
#line 13011 "./marpa.w"

ORDER o= O_of_T(t);
/*1089:*/
#line 12543 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1044:*/
#line 12138 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:1044*/
#line 12545 "./marpa.w"


/*:1089*/
#line 13013 "./marpa.w"
;

/*:1117*/
#line 13679 "./marpa.w"


/*:1171*/
#line 13867 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 13868 "./marpa.w"

/*1174:*/
#line 13689 "./marpa.w"

if(_MARPA_UNLIKELY(V_T_Generation(v)!=T_Generation(t))){
MARPA_ERROR(MARPA_ERR_BASE_GENERATION_MISMATCH);
return failure_indicator;
}

/*:1174*/
#line 13869 "./marpa.w"

if(_MARPA_UNLIKELY(value<0||value> 1))
{
MARPA_ERROR(MARPA_ERR_INVALID_BOOLEAN);
return failure_indicator;
}
/*1325:*/
#line 15701 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}

/*:1325*/
#line 13875 "./marpa.w"

/*1323:*/
#line 15689 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}

/*:1323*/
#line 13876 "./marpa.w"

{
const XRL xrl= XRL_by_ID(xrl_id);
const XSYID xsy_id= LHS_ID_of_XRL(xrl);
return symbol_is_valued_set(v,xsy_id,value);
}
}

/*:1193*//*1194:*/
#line 13884 "./marpa.w"

int marpa_v_rule_is_valued(
Marpa_Value public_v,Marpa_Rule_ID xrl_id)
{
const VALUE v= (VALUE)public_v;
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 13889 "./marpa.w"

/*1171:*/
#line 13677 "./marpa.w"

TREE t= T_of_V(v);
/*1117:*/
#line 13011 "./marpa.w"

ORDER o= O_of_T(t);
/*1089:*/
#line 12543 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1044:*/
#line 12138 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:1044*/
#line 12545 "./marpa.w"


/*:1089*/
#line 13013 "./marpa.w"
;

/*:1117*/
#line 13679 "./marpa.w"


/*:1171*/
#line 13890 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 13891 "./marpa.w"

/*1174:*/
#line 13689 "./marpa.w"

if(_MARPA_UNLIKELY(V_T_Generation(v)!=T_Generation(t))){
MARPA_ERROR(MARPA_ERR_BASE_GENERATION_MISMATCH);
return failure_indicator;
}

/*:1174*/
#line 13892 "./marpa.w"

/*1325:*/
#line 15701 "./marpa.w"

if(_MARPA_UNLIKELY(XRLID_is_Malformed(xrl_id))){
MARPA_ERROR(MARPA_ERR_INVALID_RULE_ID);
return failure_indicator;
}

/*:1325*/
#line 13893 "./marpa.w"

/*1323:*/
#line 15689 "./marpa.w"

if(_MARPA_UNLIKELY(!XRLID_of_G_Exists(xrl_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_RULE_ID);
return-1;
}

/*:1323*/
#line 13894 "./marpa.w"

{
const XRL xrl= XRL_by_ID(xrl_id);
const XSYID xsy_id= LHS_ID_of_XRL(xrl);
return symbol_is_valued(v,xsy_id);
}
}

/*:1194*//*1196:*/
#line 13909 "./marpa.w"

Marpa_Step_Type marpa_v_step(Marpa_Value public_v)
{
const VALUE v= (VALUE)public_v;
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 13913 "./marpa.w"

/*1171:*/
#line 13677 "./marpa.w"

TREE t= T_of_V(v);
/*1117:*/
#line 13011 "./marpa.w"

ORDER o= O_of_T(t);
/*1089:*/
#line 12543 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1044:*/
#line 12138 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:1044*/
#line 12545 "./marpa.w"


/*:1089*/
#line 13013 "./marpa.w"
;

/*:1117*/
#line 13679 "./marpa.w"


/*:1171*/
#line 13914 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 13915 "./marpa.w"

/*1174:*/
#line 13689 "./marpa.w"

if(_MARPA_UNLIKELY(V_T_Generation(v)!=T_Generation(t))){
MARPA_ERROR(MARPA_ERR_BASE_GENERATION_MISMATCH);
return failure_indicator;
}

/*:1174*/
#line 13916 "./marpa.w"


if(V_is_Nulling(v)){
/*1198:*/
#line 13998 "./marpa.w"

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

/*:1198*/
#line 13919 "./marpa.w"

return Step_Type_of_V(v)= MARPA_STEP_INACTIVE;
}

while(V_is_Active(v)){
Marpa_Step_Type current_value_type= Next_Value_Type_of_V(v);
switch(current_value_type)
{
case MARPA_STEP_INITIAL:
{
XSYID xsy_count;
xsy_count= XSY_Count_of_G(g);
lbv_fill(Valued_Locked_BV_of_V(v),xsy_count);
/*1197:*/
#line 13982 "./marpa.w"

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

/*:1197*/
#line 13932 "./marpa.w"

}

case STEP_GET_DATA:
/*1199:*/
#line 14023 "./marpa.w"

{
AND and_nodes;






int pop_arguments= 1;
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

/*:1199*/
#line 13936 "./marpa.w"

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

/*:1196*//*1201:*/
#line 14184 "./marpa.w"

PRIVATE int lbv_bits_to_size(int bits)
{
const LBW result= (LBW)(((unsigned int)bits+(lbv_wordbits-1))/lbv_wordbits);
return(int)result;
}

/*:1201*//*1202:*/
#line 14192 "./marpa.w"

PRIVATE Bit_Vector
lbv_obs_new(struct marpa_obstack*obs,int bits)
{
int size= lbv_bits_to_size(bits);
LBV lbv= marpa_obs_new(obs,LBW,size);
return lbv;
}

/*:1202*//*1203:*/
#line 14202 "./marpa.w"

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

/*:1203*//*1204:*/
#line 14215 "./marpa.w"

PRIVATE Bit_Vector
lbv_obs_new0(struct marpa_obstack*obs,int bits)
{
LBV lbv= lbv_obs_new(obs,bits);
return lbv_zero(lbv,bits);
}

/*:1204*//*1206:*/
#line 14234 "./marpa.w"

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

/*:1206*//*1207:*/
#line 14250 "./marpa.w"

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

/*:1207*//*1210:*/
#line 14286 "./marpa.w"

PRIVATE unsigned int bv_bits_to_size(int bits)
{
return((LBW)bits+bv_modmask)/bv_wordbits;
}
/*:1210*//*1211:*/
#line 14292 "./marpa.w"

PRIVATE unsigned int bv_bits_to_unused_mask(int bits)
{
LBW mask= (LBW)bits&bv_modmask;
if(mask)mask= (LBW)~(~0uL<<mask);else mask= (LBW)~0uL;
return(mask);
}

/*:1211*//*1213:*/
#line 14306 "./marpa.w"

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

/*:1213*//*1215:*/
#line 14324 "./marpa.w"

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


/*:1215*//*1216:*/
#line 14345 "./marpa.w"

PRIVATE Bit_Vector bv_shadow(Bit_Vector bv)
{
return bv_create((int)BV_BITS(bv));
}
PRIVATE Bit_Vector bv_obs_shadow(struct marpa_obstack*obs,Bit_Vector bv)
{
return bv_obs_create(obs,(int)BV_BITS(bv));
}

/*:1216*//*1217:*/
#line 14359 "./marpa.w"

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

/*:1217*//*1218:*/
#line 14377 "./marpa.w"

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

/*:1218*//*1219:*/
#line 14391 "./marpa.w"

PRIVATE void bv_free(Bit_Vector vector)
{
if(_MARPA_LIKELY(vector!=NULL))
{
vector-= bv_hiddenwords;
my_free(vector);
}
}

/*:1219*//*1220:*/
#line 14402 "./marpa.w"

PRIVATE void bv_fill(Bit_Vector bv)
{
LBW size= BV_SIZE(bv);
if(size<=0)return;
while(size--)*bv++= ~0u;
--bv;
*bv&= BV_MASK(bv);
}

/*:1220*//*1221:*/
#line 14413 "./marpa.w"

PRIVATE void bv_clear(Bit_Vector bv)
{
LBW size= BV_SIZE(bv);
if(size<=0)return;
while(size--)*bv++= 0u;
}

/*:1221*//*1223:*/
#line 14427 "./marpa.w"

PRIVATE void bv_over_clear(Bit_Vector bv,int raw_bit)
{
const LBW bit= (LBW)raw_bit;
LBW length= bit/bv_wordbits+1;
while(length--)*bv++= 0u;
}

/*:1223*//*1225:*/
#line 14436 "./marpa.w"

PRIVATE void bv_bit_set(Bit_Vector vector,int raw_bit)
{
const LBW bit= (LBW)raw_bit;
*(vector+(bit/bv_wordbits))|= (bv_lsb<<(bit%bv_wordbits));
}

/*:1225*//*1226:*/
#line 14444 "./marpa.w"

PRIVATE void bv_bit_clear(Bit_Vector vector,int raw_bit)
{
const LBW bit= (LBW)raw_bit;
*(vector+(bit/bv_wordbits))&= ~(bv_lsb<<(bit%bv_wordbits));
}

/*:1226*//*1227:*/
#line 14452 "./marpa.w"

PRIVATE int bv_bit_test(Bit_Vector vector,int raw_bit)
{
const LBW bit= (LBW)raw_bit;
return(*(vector+(bit/bv_wordbits))&(bv_lsb<<(bit%bv_wordbits)))!=0u;
}

/*:1227*//*1228:*/
#line 14464 "./marpa.w"

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

/*:1228*//*1229:*/
#line 14478 "./marpa.w"

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

/*:1229*//*1230:*/
#line 14492 "./marpa.w"

PRIVATE void bv_not(Bit_Vector X,Bit_Vector Y)
{
LBW size= BV_SIZE(X);
LBW mask= BV_MASK(X);
while(size--> 0)*X++= ~*Y++;
*(--X)&= mask;
}

/*:1230*//*1231:*/
#line 14502 "./marpa.w"

PRIVATE void bv_and(Bit_Vector X,Bit_Vector Y,Bit_Vector Z)
{
LBW size= BV_SIZE(X);
LBW mask= BV_MASK(X);
while(size--> 0)*X++= *Y++&*Z++;
*(--X)&= mask;
}

/*:1231*//*1232:*/
#line 14512 "./marpa.w"

PRIVATE void bv_or(Bit_Vector X,Bit_Vector Y,Bit_Vector Z)
{
LBW size= BV_SIZE(X);
LBW mask= BV_MASK(X);
while(size--> 0)*X++= *Y++|*Z++;
*(--X)&= mask;
}

/*:1232*//*1233:*/
#line 14522 "./marpa.w"

PRIVATE void bv_or_assign(Bit_Vector X,Bit_Vector Y)
{
LBW size= BV_SIZE(X);
LBW mask= BV_MASK(X);
while(size--> 0)*X++|= *Y++;
*(--X)&= mask;
}

/*:1233*//*1234:*/
#line 14532 "./marpa.w"

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

/*:1234*//*1235:*/
#line 14612 "./marpa.w"

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

/*:1235*//*1240:*/
#line 14659 "./marpa.w"

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

/*:1240*//*1245:*/
#line 14806 "./marpa.w"

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

/*:1245*//*1247:*/
#line 14829 "./marpa.w"

PRIVATE size_t matrix_sizeof(int rows,int columns)
{
const LBW bv_data_words= bv_bits_to_size(columns);
const LBW row_bytes= 
(LBW)(bv_data_words+bv_hiddenwords)*(LBW)sizeof(Bit_Vector_Word);
return offsetof(struct s_bit_matrix,
t_row_data)+((size_t)rows)*row_bytes;
}

/*:1247*//*1249:*/
#line 14840 "./marpa.w"

PRIVATE Bit_Matrix matrix_obs_create(
struct marpa_obstack*obs,
int rows,
int columns)
{

Bit_Matrix matrix_addr= 
marpa__obs_alloc(obs,matrix_sizeof(rows,columns),ALIGNOF(Bit_Matrix_Object));
return matrix_buffer_create(matrix_addr,rows,columns);
}

/*:1249*//*1250:*/
#line 14853 "./marpa.w"

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

/*:1250*//*1251:*/
#line 14875 "./marpa.w"

PRIVATE int matrix_columns(Bit_Matrix matrix)
{
Bit_Vector row0= matrix->t_row_data+bv_hiddenwords;
return(int)BV_BITS(row0);
}

/*:1251*//*1252:*/
#line 14891 "./marpa.w"

PRIVATE Bit_Vector matrix_row(Bit_Matrix matrix,int row)
{
Bit_Vector row0= matrix->t_row_data+bv_hiddenwords;
LBW words_per_row= BV_SIZE(row0)+bv_hiddenwords;
return row0+(LBW)row*words_per_row;
}

/*:1252*//*1254:*/
#line 14900 "./marpa.w"

PRIVATE void matrix_bit_set(Bit_Matrix matrix,int row,int column)
{
Bit_Vector vector= matrix_row(matrix,row);
bv_bit_set(vector,column);
}

/*:1254*//*1256:*/
#line 14908 "./marpa.w"

PRIVATE void matrix_bit_clear(Bit_Matrix matrix,int row,int column)
{
Bit_Vector vector= matrix_row(matrix,row);
bv_bit_clear(vector,column);
}

/*:1256*//*1258:*/
#line 14916 "./marpa.w"

PRIVATE int matrix_bit_test(Bit_Matrix matrix,int row,int column)
{
Bit_Vector vector= matrix_row(matrix,row);
return bv_bit_test(vector,column);
}

/*:1258*//*1259:*/
#line 14933 "./marpa.w"

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

/*:1259*//*1271:*/
#line 15074 "./marpa.w"

PRIVATE void
cilar_init(const CILAR cilar)
{
cilar->t_obs= marpa_obs_init;
cilar->t_avl= _marpa_avl_create(cil_cmp,NULL);
MARPA_DSTACK_INIT(cilar->t_buffer,int,2);
*MARPA_DSTACK_INDEX(cilar->t_buffer,int,0)= 0;
}
/*:1271*//*1272:*/
#line 15088 "./marpa.w"

PRIVATE void
cilar_buffer_reinit(const CILAR cilar)
{
MARPA_DSTACK_DESTROY(cilar->t_buffer);
MARPA_DSTACK_INIT(cilar->t_buffer,int,2);
*MARPA_DSTACK_INDEX(cilar->t_buffer,int,0)= 0;
}

/*:1272*//*1273:*/
#line 15097 "./marpa.w"

PRIVATE void cilar_destroy(const CILAR cilar)
{
_marpa_avl_destroy(cilar->t_avl);
marpa_obs_free(cilar->t_obs);
MARPA_DSTACK_DESTROY((cilar->t_buffer));
}

/*:1273*//*1274:*/
#line 15106 "./marpa.w"

PRIVATE CIL cil_empty(CILAR cilar)
{
CIL cil= MARPA_DSTACK_BASE(cilar->t_buffer,int);

Count_of_CIL(cil)= 0;
return cil_buffer_add(cilar);
}

/*:1274*//*1275:*/
#line 15116 "./marpa.w"

PRIVATE CIL cil_singleton(CILAR cilar,int element)
{
CIL cil= MARPA_DSTACK_BASE(cilar->t_buffer,int);
Count_of_CIL(cil)= 1;
Item_of_CIL(cil,0)= element;

return cil_buffer_add(cilar);
}

/*:1275*//*1276:*/
#line 15132 "./marpa.w"

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

/*:1276*//*1277:*/
#line 15160 "./marpa.w"

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

/*:1277*//*1278:*/
#line 15177 "./marpa.w"

PRIVATE void cil_buffer_clear(CILAR cilar)
{
const MARPA_DSTACK dstack= &cilar->t_buffer;
MARPA_DSTACK_CLEAR(*dstack);




*MARPA_DSTACK_PUSH(*dstack,int)= 0;
}

/*:1278*//*1279:*/
#line 15192 "./marpa.w"

PRIVATE CIL cil_buffer_push(CILAR cilar,int new_item)
{
CIL cil_in_buffer;
MARPA_DSTACK dstack= &cilar->t_buffer;
*MARPA_DSTACK_PUSH(*dstack,int)= new_item;



cil_in_buffer= MARPA_DSTACK_BASE(*dstack,int);
Count_of_CIL(cil_in_buffer)++;
return cil_in_buffer;
}

/*:1279*//*1280:*/
#line 15208 "./marpa.w"

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

/*:1280*//*1281:*/
#line 15227 "./marpa.w"

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

/*:1281*//*1282:*/
#line 15280 "./marpa.w"

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

/*:1282*//*1283:*/
#line 15315 "./marpa.w"

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

/*:1283*//*1296:*/
#line 15454 "./marpa.w"

PRIVATE void
psar_safe(const PSAR psar)
{
psar->t_psl_length= 0;
psar->t_first_psl= psar->t_first_free_psl= NULL;
}
/*:1296*//*1297:*/
#line 15461 "./marpa.w"

PRIVATE void
psar_init(const PSAR psar,int length)
{
psar->t_psl_length= length;
psar->t_first_psl= psar->t_first_free_psl= psl_new(psar);
}
/*:1297*//*1298:*/
#line 15468 "./marpa.w"

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
/*:1298*//*1299:*/
#line 15482 "./marpa.w"

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
/*:1299*//*1302:*/
#line 15513 "./marpa.w"

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

/*:1302*//*1304:*/
#line 15531 "./marpa.w"

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

/*:1304*//*1306:*/
#line 15551 "./marpa.w"

PRIVATE void psl_claim(
PSL*const psl_owner,const PSAR psar)
{
PSL new_psl= psl_alloc(psar);
(*psl_owner)= new_psl;
new_psl->t_owner= psl_owner;
}


/*:1306*//*1307:*/
#line 15561 "./marpa.w"

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

/*:1307*//*1308:*/
#line 15578 "./marpa.w"

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

/*:1308*//*1336:*/
#line 15810 "./marpa.w"

PRIVATE_NOT_INLINE void
set_error(GRAMMAR g,Marpa_Error_Code code,const char*message,unsigned int flags)
{
g->t_error= code;
g->t_error_string= message;
if(flags&FATAL_FLAG)
g->t_is_ok= 0;
}
/*:1336*//*1337:*/
#line 15829 "./marpa.w"

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

/*:1337*//*1341:*/
#line 15872 "./marpa.w"

PRIVATE_NOT_INLINE void*
marpa__default_out_of_memory(void)
{
abort();
return NULL;
}
void*(*const marpa__out_of_memory)(void)= marpa__default_out_of_memory;

/*:1341*//*1346:*/
#line 15910 "./marpa.w"

Marpa_Earley_Set_ID _marpa_r_trace_earley_set(Marpa_Recognizer r)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 15913 "./marpa.w"

/*563:*/
#line 6125 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:563*/
#line 15914 "./marpa.w"

YS trace_earley_set= r->t_trace_earley_set;
/*1332:*/
#line 15754 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 15755 "./marpa.w"

/*1330:*/
#line 15738 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1330*/
#line 15756 "./marpa.w"


/*:1332*/
#line 15916 "./marpa.w"

if(!trace_earley_set){
MARPA_ERROR(MARPA_ERR_NO_TRACE_YS);
return failure_indicator;
}
return Ord_of_YS(trace_earley_set);
}

/*:1346*//*1347:*/
#line 15924 "./marpa.w"

Marpa_Earley_Set_ID marpa_r_latest_earley_set(Marpa_Recognizer r)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 15927 "./marpa.w"

/*563:*/
#line 6125 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:563*/
#line 15928 "./marpa.w"

/*1332:*/
#line 15754 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 15755 "./marpa.w"

/*1330:*/
#line 15738 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1330*/
#line 15756 "./marpa.w"


/*:1332*/
#line 15929 "./marpa.w"

if(G_is_Trivial(g))return 0;
return Ord_of_YS(Latest_YS_of_R(r));
}

/*:1347*//*1348:*/
#line 15934 "./marpa.w"

Marpa_Earleme marpa_r_earleme(Marpa_Recognizer r,Marpa_Earley_Set_ID set_id)
{
/*563:*/
#line 6125 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:563*/
#line 15937 "./marpa.w"

/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 15938 "./marpa.w"

YS earley_set;
/*1330:*/
#line 15738 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1330*/
#line 15940 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 15941 "./marpa.w"

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

/*:1348*//*1350:*/
#line 15959 "./marpa.w"

int _marpa_r_earley_set_size(Marpa_Recognizer r,Marpa_Earley_Set_ID set_id)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 15962 "./marpa.w"

YS earley_set;
/*563:*/
#line 6125 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:563*/
#line 15964 "./marpa.w"

/*1330:*/
#line 15738 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1330*/
#line 15965 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 15966 "./marpa.w"

r_update_earley_sets(r);
if(!YS_Ord_is_Valid(r,set_id))
{
MARPA_ERROR(MARPA_ERR_INVALID_LOCATION);
return failure_indicator;
}
earley_set= YS_of_R_by_Ord(r,set_id);
return YIM_Count_of_YS(earley_set);
}

/*:1350*//*1355:*/
#line 16008 "./marpa.w"

Marpa_Earleme
_marpa_r_earley_set_trace(Marpa_Recognizer r,Marpa_Earley_Set_ID set_id)
{
YS earley_set;
const int es_does_not_exist= -1;
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 16014 "./marpa.w"

/*563:*/
#line 6125 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:563*/
#line 16015 "./marpa.w"

/*1332:*/
#line 15754 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 15755 "./marpa.w"

/*1330:*/
#line 15738 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1330*/
#line 15756 "./marpa.w"


/*:1332*/
#line 16016 "./marpa.w"

if(r->t_trace_earley_set&&Ord_of_YS(r->t_trace_earley_set)==set_id)
{


return Earleme_of_YS(r->t_trace_earley_set);
}
/*1356:*/
#line 16039 "./marpa.w"
{
r->t_trace_earley_set= NULL;
trace_earley_item_clear(r);
/*1368:*/
#line 16228 "./marpa.w"

r->t_trace_pim_nsy_p= NULL;
r->t_trace_postdot_item= NULL;

/*:1368*/
#line 16042 "./marpa.w"

}

/*:1356*/
#line 16023 "./marpa.w"

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

/*:1355*//*1357:*/
#line 16045 "./marpa.w"

Marpa_AHM_ID
_marpa_r_earley_item_trace(Marpa_Recognizer r,Marpa_Earley_Item_ID item_id)
{
const int yim_does_not_exist= -1;
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 16050 "./marpa.w"

YS trace_earley_set;
YIM earley_item;
YIM*earley_items;
/*563:*/
#line 6125 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:563*/
#line 16054 "./marpa.w"

/*1332:*/
#line 15754 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 15755 "./marpa.w"

/*1330:*/
#line 15738 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1330*/
#line 15756 "./marpa.w"


/*:1332*/
#line 16055 "./marpa.w"

trace_earley_set= r->t_trace_earley_set;
if(!trace_earley_set)
{
/*1356:*/
#line 16039 "./marpa.w"
{
r->t_trace_earley_set= NULL;
trace_earley_item_clear(r);
/*1368:*/
#line 16228 "./marpa.w"

r->t_trace_pim_nsy_p= NULL;
r->t_trace_postdot_item= NULL;

/*:1368*/
#line 16042 "./marpa.w"

}

/*:1356*/
#line 16059 "./marpa.w"

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

/*:1357*//*1359:*/
#line 16088 "./marpa.w"

PRIVATE void trace_earley_item_clear(RECCE r)
{
/*1358:*/
#line 16085 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:1358*/
#line 16091 "./marpa.w"

trace_source_link_clear(r);
}

/*:1359*//*1360:*/
#line 16095 "./marpa.w"

Marpa_Earley_Set_ID _marpa_r_earley_item_origin(Marpa_Recognizer r)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 16098 "./marpa.w"

YIM item= r->t_trace_earley_item;
/*563:*/
#line 6125 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:563*/
#line 16100 "./marpa.w"

/*1332:*/
#line 15754 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 15755 "./marpa.w"

/*1330:*/
#line 15738 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1330*/
#line 15756 "./marpa.w"


/*:1332*/
#line 16101 "./marpa.w"

if(!item){
/*1358:*/
#line 16085 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:1358*/
#line 16103 "./marpa.w"

MARPA_ERROR(MARPA_ERR_NO_TRACE_YIM);
return failure_indicator;
}
return Origin_Ord_of_YIM(item);
}

/*:1360*//*1362:*/
#line 16115 "./marpa.w"

Marpa_Symbol_ID _marpa_r_leo_predecessor_symbol(Marpa_Recognizer r)
{
const Marpa_Symbol_ID no_predecessor= -1;
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 16119 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
LIM predecessor_leo_item;
/*563:*/
#line 6125 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:563*/
#line 16122 "./marpa.w"

/*1332:*/
#line 15754 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 15755 "./marpa.w"

/*1330:*/
#line 15738 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1330*/
#line 15756 "./marpa.w"


/*:1332*/
#line 16123 "./marpa.w"

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

/*:1362*//*1363:*/
#line 16137 "./marpa.w"

Marpa_Earley_Set_ID _marpa_r_leo_base_origin(Marpa_Recognizer r)
{
const JEARLEME pim_is_not_a_leo_item= -1;
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 16141 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
/*563:*/
#line 6125 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:563*/
#line 16143 "./marpa.w"

YIM base_earley_item;
/*1332:*/
#line 15754 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 15755 "./marpa.w"

/*1330:*/
#line 15738 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1330*/
#line 15756 "./marpa.w"


/*:1332*/
#line 16145 "./marpa.w"

if(!postdot_item){
MARPA_ERROR(MARPA_ERR_NO_TRACE_PIM);
return failure_indicator;
}
if(YIM_of_PIM(postdot_item))return pim_is_not_a_leo_item;
base_earley_item= Trailhead_YIM_of_LIM(LIM_of_PIM(postdot_item));
return Origin_Ord_of_YIM(base_earley_item);
}

/*:1363*//*1364:*/
#line 16156 "./marpa.w"

Marpa_AHM_ID _marpa_r_leo_base_state(Marpa_Recognizer r)
{
const JEARLEME pim_is_not_a_leo_item= -1;
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 16160 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
YIM base_earley_item;
/*563:*/
#line 6125 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:563*/
#line 16163 "./marpa.w"

/*1332:*/
#line 15754 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 15755 "./marpa.w"

/*1330:*/
#line 15738 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1330*/
#line 15756 "./marpa.w"


/*:1332*/
#line 16164 "./marpa.w"

if(!postdot_item){
MARPA_ERROR(MARPA_ERR_NO_TRACE_PIM);
return failure_indicator;
}
if(YIM_of_PIM(postdot_item))return pim_is_not_a_leo_item;
base_earley_item= Trailhead_YIM_of_LIM(LIM_of_PIM(postdot_item));
return AHMID_of_YIM(base_earley_item);
}

/*:1364*//*1367:*/
#line 16202 "./marpa.w"

Marpa_Symbol_ID
_marpa_r_postdot_symbol_trace(Marpa_Recognizer r,
Marpa_Symbol_ID nsy_id)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 16207 "./marpa.w"

YS current_ys= r->t_trace_earley_set;
PIM*pim_nsy_p;
PIM pim;
/*563:*/
#line 6125 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:563*/
#line 16211 "./marpa.w"

/*1368:*/
#line 16228 "./marpa.w"

r->t_trace_pim_nsy_p= NULL;
r->t_trace_postdot_item= NULL;

/*:1368*/
#line 16212 "./marpa.w"

/*1332:*/
#line 15754 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 15755 "./marpa.w"

/*1330:*/
#line 15738 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1330*/
#line 15756 "./marpa.w"


/*:1332*/
#line 16213 "./marpa.w"

/*1320:*/
#line 15668 "./marpa.w"

if(_MARPA_UNLIKELY(NSYID_is_Malformed(nsy_id))){
MARPA_ERROR(MARPA_ERR_INVALID_SYMBOL_ID);
return failure_indicator;
}
/*:1320*/
#line 16214 "./marpa.w"

/*1321:*/
#line 15675 "./marpa.w"

if(_MARPA_UNLIKELY(!NSYID_of_G_Exists(nsy_id))){
MARPA_ERROR(MARPA_ERR_NO_SUCH_SYMBOL_ID);
return-1;
}

/*:1321*/
#line 16215 "./marpa.w"

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

/*:1367*//*1369:*/
#line 16238 "./marpa.w"

Marpa_Symbol_ID
_marpa_r_first_postdot_item_trace(Marpa_Recognizer r)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 16242 "./marpa.w"

YS current_earley_set= r->t_trace_earley_set;
PIM pim;
/*563:*/
#line 6125 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:563*/
#line 16245 "./marpa.w"

PIM*pim_nsy_p;
/*1368:*/
#line 16228 "./marpa.w"

r->t_trace_pim_nsy_p= NULL;
r->t_trace_postdot_item= NULL;

/*:1368*/
#line 16247 "./marpa.w"

/*1332:*/
#line 15754 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 15755 "./marpa.w"

/*1330:*/
#line 15738 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1330*/
#line 15756 "./marpa.w"


/*:1332*/
#line 16248 "./marpa.w"

if(!current_earley_set){
/*1358:*/
#line 16085 "./marpa.w"

r->t_trace_earley_item= NULL;

/*:1358*/
#line 16250 "./marpa.w"

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

/*:1369*//*1370:*/
#line 16269 "./marpa.w"

Marpa_Symbol_ID
_marpa_r_next_postdot_item_trace(Marpa_Recognizer r)
{
const XSYID no_more_postdot_symbols= -1;
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 16274 "./marpa.w"

YS current_set= r->t_trace_earley_set;
PIM pim;
PIM*pim_nsy_p;
/*563:*/
#line 6125 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:563*/
#line 16278 "./marpa.w"


pim_nsy_p= r->t_trace_pim_nsy_p;
pim= r->t_trace_postdot_item;
/*1368:*/
#line 16228 "./marpa.w"

r->t_trace_pim_nsy_p= NULL;
r->t_trace_postdot_item= NULL;

/*:1368*/
#line 16282 "./marpa.w"

if(!pim_nsy_p||!pim){
MARPA_ERROR(MARPA_ERR_NO_TRACE_PIM);
return failure_indicator;
}
/*1332:*/
#line 15754 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 15755 "./marpa.w"

/*1330:*/
#line 15738 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1330*/
#line 15756 "./marpa.w"


/*:1332*/
#line 16287 "./marpa.w"

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

/*:1370*//*1371:*/
#line 16307 "./marpa.w"

Marpa_Symbol_ID _marpa_r_postdot_item_symbol(Marpa_Recognizer r)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 16310 "./marpa.w"

PIM postdot_item= r->t_trace_postdot_item;
/*563:*/
#line 6125 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:563*/
#line 16312 "./marpa.w"

/*1332:*/
#line 15754 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 15755 "./marpa.w"

/*1330:*/
#line 15738 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1330*/
#line 15756 "./marpa.w"


/*:1332*/
#line 16313 "./marpa.w"

if(!postdot_item){
MARPA_ERROR(MARPA_ERR_NO_TRACE_PIM);
return failure_indicator;
}
return Postdot_NSYID_of_PIM(postdot_item);
}

/*:1371*//*1376:*/
#line 16343 "./marpa.w"

Marpa_Symbol_ID _marpa_r_first_token_link_trace(Marpa_Recognizer r)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 16346 "./marpa.w"

SRCL source_link;
unsigned int source_type;
YIM item= r->t_trace_earley_item;
/*563:*/
#line 6125 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:563*/
#line 16350 "./marpa.w"

/*1332:*/
#line 15754 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 15755 "./marpa.w"

/*1330:*/
#line 15738 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1330*/
#line 15756 "./marpa.w"


/*:1332*/
#line 16351 "./marpa.w"

/*1390:*/
#line 16540 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
MARPA_ERROR(MARPA_ERR_NO_TRACE_YIM);
return failure_indicator;
}

/*:1390*/
#line 16352 "./marpa.w"

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

/*:1376*//*1379:*/
#line 16384 "./marpa.w"

Marpa_Symbol_ID _marpa_r_next_token_link_trace(Marpa_Recognizer r)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 16387 "./marpa.w"

SRCL source_link;
YIM item;
/*563:*/
#line 6125 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:563*/
#line 16390 "./marpa.w"

/*1332:*/
#line 15754 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 15755 "./marpa.w"

/*1330:*/
#line 15738 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1330*/
#line 15756 "./marpa.w"


/*:1332*/
#line 16391 "./marpa.w"

/*1390:*/
#line 16540 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
MARPA_ERROR(MARPA_ERR_NO_TRACE_YIM);
return failure_indicator;
}

/*:1390*/
#line 16392 "./marpa.w"

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

/*:1379*//*1381:*/
#line 16415 "./marpa.w"

Marpa_Symbol_ID _marpa_r_first_completion_link_trace(Marpa_Recognizer r)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 16418 "./marpa.w"

SRCL source_link;
unsigned int source_type;
YIM item= r->t_trace_earley_item;
/*563:*/
#line 6125 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:563*/
#line 16422 "./marpa.w"

/*1332:*/
#line 15754 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 15755 "./marpa.w"

/*1330:*/
#line 15738 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1330*/
#line 15756 "./marpa.w"


/*:1332*/
#line 16423 "./marpa.w"

/*1390:*/
#line 16540 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
MARPA_ERROR(MARPA_ERR_NO_TRACE_YIM);
return failure_indicator;
}

/*:1390*/
#line 16424 "./marpa.w"

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

/*:1381*//*1384:*/
#line 16455 "./marpa.w"

Marpa_Symbol_ID _marpa_r_next_completion_link_trace(Marpa_Recognizer r)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 16458 "./marpa.w"

SRCL source_link;
YIM item;
/*563:*/
#line 6125 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:563*/
#line 16461 "./marpa.w"

/*1332:*/
#line 15754 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 15755 "./marpa.w"

/*1330:*/
#line 15738 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1330*/
#line 15756 "./marpa.w"


/*:1332*/
#line 16462 "./marpa.w"

/*1390:*/
#line 16540 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
MARPA_ERROR(MARPA_ERR_NO_TRACE_YIM);
return failure_indicator;
}

/*:1390*/
#line 16463 "./marpa.w"

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

/*:1384*//*1386:*/
#line 16486 "./marpa.w"

Marpa_Symbol_ID
_marpa_r_first_leo_link_trace(Marpa_Recognizer r)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 16490 "./marpa.w"

SRCL source_link;
YIM item= r->t_trace_earley_item;
/*563:*/
#line 6125 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:563*/
#line 16493 "./marpa.w"

/*1332:*/
#line 15754 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 15755 "./marpa.w"

/*1330:*/
#line 15738 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1330*/
#line 15756 "./marpa.w"


/*:1332*/
#line 16494 "./marpa.w"

/*1390:*/
#line 16540 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
MARPA_ERROR(MARPA_ERR_NO_TRACE_YIM);
return failure_indicator;
}

/*:1390*/
#line 16495 "./marpa.w"

source_link= First_Leo_SRCL_of_YIM(item);
if(source_link){
r->t_trace_source_type= SOURCE_IS_LEO;
r->t_trace_source_link= source_link;
return Cause_AHMID_of_SRCL(source_link);
}
trace_source_link_clear(r);
return-1;
}

/*:1386*//*1389:*/
#line 16514 "./marpa.w"

Marpa_Symbol_ID
_marpa_r_next_leo_link_trace(Marpa_Recognizer r)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 16518 "./marpa.w"

SRCL source_link;
YIM item;
/*563:*/
#line 6125 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:563*/
#line 16521 "./marpa.w"

/*1332:*/
#line 15754 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 15755 "./marpa.w"

/*1330:*/
#line 15738 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1330*/
#line 15756 "./marpa.w"


/*:1332*/
#line 16522 "./marpa.w"

/*1390:*/
#line 16540 "./marpa.w"

item= r->t_trace_earley_item;
if(!item){
trace_source_link_clear(r);
MARPA_ERROR(MARPA_ERR_NO_TRACE_YIM);
return failure_indicator;
}

/*:1390*/
#line 16523 "./marpa.w"

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

/*:1389*//*1391:*/
#line 16549 "./marpa.w"

PRIVATE void trace_source_link_clear(RECCE r)
{
r->t_trace_source_link= NULL;
r->t_trace_source_type= NO_SOURCE;
}

/*:1391*//*1392:*/
#line 16564 "./marpa.w"

AHMID _marpa_r_source_predecessor_state(Marpa_Recognizer r)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 16567 "./marpa.w"

unsigned int source_type;
SRCL source_link;
/*563:*/
#line 6125 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:563*/
#line 16570 "./marpa.w"

/*1332:*/
#line 15754 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 15755 "./marpa.w"

/*1330:*/
#line 15738 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1330*/
#line 15756 "./marpa.w"


/*:1332*/
#line 16571 "./marpa.w"

source_type= r->t_trace_source_type;
/*1398:*/
#line 16716 "./marpa.w"

source_link= r->t_trace_source_link;
if(!source_link){
MARPA_ERROR(MARPA_ERR_NO_TRACE_SRCL);
return failure_indicator;
}

/*:1398*/
#line 16573 "./marpa.w"

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

/*:1392*//*1393:*/
#line 16605 "./marpa.w"

Marpa_Symbol_ID _marpa_r_source_token(Marpa_Recognizer r,int*value_p)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 16608 "./marpa.w"

unsigned int source_type;
SRCL source_link;
/*563:*/
#line 6125 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:563*/
#line 16611 "./marpa.w"

/*1332:*/
#line 15754 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 15755 "./marpa.w"

/*1330:*/
#line 15738 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1330*/
#line 15756 "./marpa.w"


/*:1332*/
#line 16612 "./marpa.w"

source_type= r->t_trace_source_type;
/*1398:*/
#line 16716 "./marpa.w"

source_link= r->t_trace_source_link;
if(!source_link){
MARPA_ERROR(MARPA_ERR_NO_TRACE_SRCL);
return failure_indicator;
}

/*:1398*/
#line 16614 "./marpa.w"

if(source_type==SOURCE_IS_TOKEN){
if(value_p)*value_p= Value_of_SRCL(source_link);
return NSYID_of_SRCL(source_link);
}
MARPA_ERROR(invalid_source_type_code(source_type));
return failure_indicator;
}

/*:1393*//*1395:*/
#line 16636 "./marpa.w"

Marpa_Symbol_ID _marpa_r_source_leo_transition_symbol(Marpa_Recognizer r)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 16639 "./marpa.w"

unsigned int source_type;
SRCL source_link;
/*563:*/
#line 6125 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:563*/
#line 16642 "./marpa.w"

/*1332:*/
#line 15754 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 15755 "./marpa.w"

/*1330:*/
#line 15738 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1330*/
#line 15756 "./marpa.w"


/*:1332*/
#line 16643 "./marpa.w"

source_type= r->t_trace_source_type;
/*1398:*/
#line 16716 "./marpa.w"

source_link= r->t_trace_source_link;
if(!source_link){
MARPA_ERROR(MARPA_ERR_NO_TRACE_SRCL);
return failure_indicator;
}

/*:1398*/
#line 16645 "./marpa.w"

switch(source_type)
{
case SOURCE_IS_LEO:
return Leo_Transition_NSYID_of_SRCL(source_link);
}
MARPA_ERROR(invalid_source_type_code(source_type));
return failure_indicator;
}

/*:1395*//*1397:*/
#line 16679 "./marpa.w"

Marpa_Earley_Set_ID _marpa_r_source_middle(Marpa_Recognizer r)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 16682 "./marpa.w"

YIM predecessor_yim= NULL;
unsigned int source_type;
SRCL source_link;
/*563:*/
#line 6125 "./marpa.w"

const GRAMMAR g= G_of_R(r);
/*:563*/
#line 16686 "./marpa.w"

/*1332:*/
#line 15754 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 15755 "./marpa.w"

/*1330:*/
#line 15738 "./marpa.w"

if(_MARPA_UNLIKELY(Input_Phase_of_R(r)==R_BEFORE_INPUT)){
MARPA_ERROR(MARPA_ERR_RECCE_NOT_STARTED);
return failure_indicator;
}
/*:1330*/
#line 15756 "./marpa.w"


/*:1332*/
#line 16687 "./marpa.w"

source_type= r->t_trace_source_type;
/*1398:*/
#line 16716 "./marpa.w"

source_link= r->t_trace_source_link;
if(!source_link){
MARPA_ERROR(MARPA_ERR_NO_TRACE_SRCL);
return failure_indicator;
}

/*:1398*/
#line 16689 "./marpa.w"


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

/*:1397*//*1402:*/
#line 16754 "./marpa.w"

int _marpa_b_or_node_set(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 16759 "./marpa.w"

/*1044:*/
#line 12138 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:1044*/
#line 16760 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 16761 "./marpa.w"

/*1400:*/
#line 16732 "./marpa.w"

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
/*:1400*/
#line 16762 "./marpa.w"

/*1401:*/
#line 16744 "./marpa.w"

{
if(_MARPA_UNLIKELY(!ORs_of_B(b)))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= OR_of_B_by_ID(b,or_node_id);
}

/*:1401*/
#line 16763 "./marpa.w"

return YS_Ord_of_OR(or_node);
}

/*:1402*//*1403:*/
#line 16767 "./marpa.w"

int _marpa_b_or_node_origin(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 16772 "./marpa.w"

/*1044:*/
#line 12138 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:1044*/
#line 16773 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 16774 "./marpa.w"

/*1400:*/
#line 16732 "./marpa.w"

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
/*:1400*/
#line 16775 "./marpa.w"

/*1401:*/
#line 16744 "./marpa.w"

{
if(_MARPA_UNLIKELY(!ORs_of_B(b)))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= OR_of_B_by_ID(b,or_node_id);
}

/*:1401*/
#line 16776 "./marpa.w"

return Origin_Ord_of_OR(or_node);
}

/*:1403*//*1404:*/
#line 16780 "./marpa.w"

Marpa_IRL_ID _marpa_b_or_node_irl(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 16785 "./marpa.w"

/*1044:*/
#line 12138 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:1044*/
#line 16786 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 16787 "./marpa.w"

/*1400:*/
#line 16732 "./marpa.w"

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
/*:1400*/
#line 16788 "./marpa.w"

/*1401:*/
#line 16744 "./marpa.w"

{
if(_MARPA_UNLIKELY(!ORs_of_B(b)))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= OR_of_B_by_ID(b,or_node_id);
}

/*:1401*/
#line 16789 "./marpa.w"

return IRLID_of_OR(or_node);
}

/*:1404*//*1405:*/
#line 16793 "./marpa.w"

int _marpa_b_or_node_position(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 16798 "./marpa.w"

/*1044:*/
#line 12138 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:1044*/
#line 16799 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 16800 "./marpa.w"

/*1400:*/
#line 16732 "./marpa.w"

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
/*:1400*/
#line 16801 "./marpa.w"

/*1401:*/
#line 16744 "./marpa.w"

{
if(_MARPA_UNLIKELY(!ORs_of_B(b)))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= OR_of_B_by_ID(b,or_node_id);
}

/*:1401*/
#line 16802 "./marpa.w"

return Position_of_OR(or_node);
}

/*:1405*//*1406:*/
#line 16806 "./marpa.w"

int _marpa_b_or_node_is_whole(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 16811 "./marpa.w"

/*1044:*/
#line 12138 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:1044*/
#line 16812 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 16813 "./marpa.w"

/*1400:*/
#line 16732 "./marpa.w"

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
/*:1400*/
#line 16814 "./marpa.w"

/*1401:*/
#line 16744 "./marpa.w"

{
if(_MARPA_UNLIKELY(!ORs_of_B(b)))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= OR_of_B_by_ID(b,or_node_id);
}

/*:1401*/
#line 16815 "./marpa.w"

return Position_of_OR(or_node)>=Length_of_IRL(IRL_of_OR(or_node))?1:0;
}

/*:1406*//*1407:*/
#line 16819 "./marpa.w"

int _marpa_b_or_node_is_semantic(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 16824 "./marpa.w"

/*1044:*/
#line 12138 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:1044*/
#line 16825 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 16826 "./marpa.w"

/*1400:*/
#line 16732 "./marpa.w"

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
/*:1400*/
#line 16827 "./marpa.w"

/*1401:*/
#line 16744 "./marpa.w"

{
if(_MARPA_UNLIKELY(!ORs_of_B(b)))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= OR_of_B_by_ID(b,or_node_id);
}

/*:1401*/
#line 16828 "./marpa.w"

return!IRL_has_Virtual_LHS(IRL_of_OR(or_node));
}

/*:1407*//*1408:*/
#line 16832 "./marpa.w"

int _marpa_b_or_node_first_and(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 16837 "./marpa.w"

/*1044:*/
#line 12138 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:1044*/
#line 16838 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 16839 "./marpa.w"

/*1400:*/
#line 16732 "./marpa.w"

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
/*:1400*/
#line 16840 "./marpa.w"

/*1401:*/
#line 16744 "./marpa.w"

{
if(_MARPA_UNLIKELY(!ORs_of_B(b)))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= OR_of_B_by_ID(b,or_node_id);
}

/*:1401*/
#line 16841 "./marpa.w"

return First_ANDID_of_OR(or_node);
}

/*:1408*//*1409:*/
#line 16845 "./marpa.w"

int _marpa_b_or_node_last_and(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 16850 "./marpa.w"

/*1044:*/
#line 12138 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:1044*/
#line 16851 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 16852 "./marpa.w"

/*1400:*/
#line 16732 "./marpa.w"

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
/*:1400*/
#line 16853 "./marpa.w"

/*1401:*/
#line 16744 "./marpa.w"

{
if(_MARPA_UNLIKELY(!ORs_of_B(b)))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= OR_of_B_by_ID(b,or_node_id);
}

/*:1401*/
#line 16854 "./marpa.w"

return First_ANDID_of_OR(or_node)
+AND_Count_of_OR(or_node)-1;
}

/*:1409*//*1410:*/
#line 16859 "./marpa.w"

int _marpa_b_or_node_and_count(Marpa_Bocage b,
Marpa_Or_Node_ID or_node_id)
{
OR or_node;
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 16864 "./marpa.w"

/*1044:*/
#line 12138 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:1044*/
#line 16865 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 16866 "./marpa.w"

/*1400:*/
#line 16732 "./marpa.w"

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
/*:1400*/
#line 16867 "./marpa.w"

/*1401:*/
#line 16744 "./marpa.w"

{
if(_MARPA_UNLIKELY(!ORs_of_B(b)))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= OR_of_B_by_ID(b,or_node_id);
}

/*:1401*/
#line 16868 "./marpa.w"

return AND_Count_of_OR(or_node);
}

/*:1410*//*1413:*/
#line 16882 "./marpa.w"

int _marpa_o_or_node_and_node_count(Marpa_Order o,
Marpa_Or_Node_ID or_node_id)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 16886 "./marpa.w"

/*1089:*/
#line 12543 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1044:*/
#line 12138 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:1044*/
#line 12545 "./marpa.w"


/*:1089*/
#line 16887 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 16888 "./marpa.w"

/*1400:*/
#line 16732 "./marpa.w"

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
/*:1400*/
#line 16889 "./marpa.w"

if(!O_is_Default(o))
{
ANDID**const and_node_orderings= o->t_and_node_orderings;
ANDID*ordering= and_node_orderings[or_node_id];
if(ordering)return ordering[0];
}
{
OR or_node;
/*1401:*/
#line 16744 "./marpa.w"

{
if(_MARPA_UNLIKELY(!ORs_of_B(b)))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= OR_of_B_by_ID(b,or_node_id);
}

/*:1401*/
#line 16898 "./marpa.w"

return AND_Count_of_OR(or_node);
}
}

/*:1413*//*1414:*/
#line 16903 "./marpa.w"

int _marpa_o_or_node_and_node_id_by_ix(Marpa_Order o,
Marpa_Or_Node_ID or_node_id,int ix)
{
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 16907 "./marpa.w"

/*1089:*/
#line 12543 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1044:*/
#line 12138 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:1044*/
#line 12545 "./marpa.w"


/*:1089*/
#line 16908 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 16909 "./marpa.w"

/*1400:*/
#line 16732 "./marpa.w"

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
/*:1400*/
#line 16910 "./marpa.w"

if(!O_is_Default(o))
{
ANDID**const and_node_orderings= o->t_and_node_orderings;
ANDID*ordering= and_node_orderings[or_node_id];
if(ordering)return ordering[1+ix];
}
{
OR or_node;
/*1401:*/
#line 16744 "./marpa.w"

{
if(_MARPA_UNLIKELY(!ORs_of_B(b)))
{
MARPA_ERROR(MARPA_ERR_NO_OR_NODES);
return failure_indicator;
}
or_node= OR_of_B_by_ID(b,or_node_id);
}

/*:1401*/
#line 16919 "./marpa.w"

return First_ANDID_of_OR(or_node)+ix;
}
}

/*:1414*//*1416:*/
#line 16926 "./marpa.w"

int _marpa_b_and_node_count(Marpa_Bocage b)
{
/*1044:*/
#line 12138 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:1044*/
#line 16929 "./marpa.w"

/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 16930 "./marpa.w"

/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 16931 "./marpa.w"

return AND_Count_of_B(b);
}

/*:1416*//*1418:*/
#line 16957 "./marpa.w"

int _marpa_b_and_node_parent(Marpa_Bocage b,
Marpa_And_Node_ID and_node_id)
{
AND and_node;
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 16962 "./marpa.w"

/*1044:*/
#line 12138 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:1044*/
#line 16963 "./marpa.w"

/*1417:*/
#line 16935 "./marpa.w"

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

/*:1417*/
#line 16964 "./marpa.w"

return ID_of_OR(OR_of_AND(and_node));
}

/*:1418*//*1419:*/
#line 16968 "./marpa.w"

int _marpa_b_and_node_predecessor(Marpa_Bocage b,
Marpa_And_Node_ID and_node_id)
{
AND and_node;
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 16973 "./marpa.w"

/*1044:*/
#line 12138 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:1044*/
#line 16974 "./marpa.w"

/*1417:*/
#line 16935 "./marpa.w"

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

/*:1417*/
#line 16975 "./marpa.w"

{
const OR predecessor_or= Predecessor_OR_of_AND(and_node);
const ORID predecessor_or_id= 
predecessor_or?ID_of_OR(predecessor_or):-1;
return predecessor_or_id;
}
}

/*:1419*//*1420:*/
#line 16984 "./marpa.w"

int _marpa_b_and_node_cause(Marpa_Bocage b,
Marpa_And_Node_ID and_node_id)
{
AND and_node;
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 16989 "./marpa.w"

/*1044:*/
#line 12138 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:1044*/
#line 16990 "./marpa.w"

/*1417:*/
#line 16935 "./marpa.w"

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

/*:1417*/
#line 16991 "./marpa.w"

{
const OR cause_or= Cause_OR_of_AND(and_node);
const ORID cause_or_id= 
OR_is_Token(cause_or)?-1:ID_of_OR(cause_or);
return cause_or_id;
}
}

/*:1420*//*1421:*/
#line 17000 "./marpa.w"

int _marpa_b_and_node_symbol(Marpa_Bocage b,
Marpa_And_Node_ID and_node_id)
{
AND and_node;
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 17005 "./marpa.w"

/*1044:*/
#line 12138 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:1044*/
#line 17006 "./marpa.w"

/*1417:*/
#line 16935 "./marpa.w"

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

/*:1417*/
#line 17007 "./marpa.w"

{
const OR cause_or= Cause_OR_of_AND(and_node);
const XSYID symbol_id= 
OR_is_Token(cause_or)?NSYID_of_OR(cause_or):-1;
return symbol_id;
}
}

/*:1421*//*1422:*/
#line 17016 "./marpa.w"

Marpa_Symbol_ID _marpa_b_and_node_token(Marpa_Bocage b,
Marpa_And_Node_ID and_node_id,int*value_p)
{
AND and_node;
OR cause_or;
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 17022 "./marpa.w"

/*1044:*/
#line 12138 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:1044*/
#line 17023 "./marpa.w"

/*1417:*/
#line 16935 "./marpa.w"

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

/*:1417*/
#line 17024 "./marpa.w"


cause_or= Cause_OR_of_AND(and_node);
if(!OR_is_Token(cause_or))return-1;
if(value_p)*value_p= Value_of_OR(cause_or);
return NSYID_of_OR(cause_or);
}

/*:1422*//*1423:*/
#line 17039 "./marpa.w"

Marpa_Earley_Set_ID _marpa_b_and_node_middle(Marpa_Bocage b,
Marpa_And_Node_ID and_node_id)
{
AND and_node;
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 17044 "./marpa.w"

/*1044:*/
#line 12138 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:1044*/
#line 17045 "./marpa.w"

/*1417:*/
#line 16935 "./marpa.w"

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

/*:1417*/
#line 17046 "./marpa.w"

{
const OR predecessor_or= Predecessor_OR_of_AND(and_node);
if(predecessor_or)
{
return YS_Ord_of_OR(predecessor_or);
}
}
return Origin_Ord_of_OR(OR_of_AND(and_node));
}

/*:1423*//*1426:*/
#line 17079 "./marpa.w"

int _marpa_t_nook_or_node(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 17083 "./marpa.w"

/*1117:*/
#line 13011 "./marpa.w"

ORDER o= O_of_T(t);
/*1089:*/
#line 12543 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1044:*/
#line 12138 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:1044*/
#line 12545 "./marpa.w"


/*:1089*/
#line 13013 "./marpa.w"
;

/*:1117*/
#line 17084 "./marpa.w"

/*1425:*/
#line 17061 "./marpa.w"
{
NOOK base_nook;
/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 17063 "./marpa.w"

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

/*:1425*/
#line 17085 "./marpa.w"

return ID_of_OR(OR_of_NOOK(nook));
}

/*:1426*//*1427:*/
#line 17089 "./marpa.w"

int _marpa_t_nook_choice(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 17093 "./marpa.w"

/*1117:*/
#line 13011 "./marpa.w"

ORDER o= O_of_T(t);
/*1089:*/
#line 12543 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1044:*/
#line 12138 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:1044*/
#line 12545 "./marpa.w"


/*:1089*/
#line 13013 "./marpa.w"
;

/*:1117*/
#line 17094 "./marpa.w"

/*1425:*/
#line 17061 "./marpa.w"
{
NOOK base_nook;
/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 17063 "./marpa.w"

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

/*:1425*/
#line 17095 "./marpa.w"

return Choice_of_NOOK(nook);
}

/*:1427*//*1428:*/
#line 17099 "./marpa.w"

int _marpa_t_nook_parent(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 17103 "./marpa.w"

/*1117:*/
#line 13011 "./marpa.w"

ORDER o= O_of_T(t);
/*1089:*/
#line 12543 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1044:*/
#line 12138 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:1044*/
#line 12545 "./marpa.w"


/*:1089*/
#line 13013 "./marpa.w"
;

/*:1117*/
#line 17104 "./marpa.w"

/*1425:*/
#line 17061 "./marpa.w"
{
NOOK base_nook;
/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 17063 "./marpa.w"

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

/*:1425*/
#line 17105 "./marpa.w"

return Parent_of_NOOK(nook);
}

/*:1428*//*1429:*/
#line 17109 "./marpa.w"

int _marpa_t_nook_cause_is_ready(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 17113 "./marpa.w"

/*1117:*/
#line 13011 "./marpa.w"

ORDER o= O_of_T(t);
/*1089:*/
#line 12543 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1044:*/
#line 12138 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:1044*/
#line 12545 "./marpa.w"


/*:1089*/
#line 13013 "./marpa.w"
;

/*:1117*/
#line 17114 "./marpa.w"

/*1425:*/
#line 17061 "./marpa.w"
{
NOOK base_nook;
/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 17063 "./marpa.w"

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

/*:1425*/
#line 17115 "./marpa.w"

return NOOK_Cause_is_Expanded(nook);
}

/*:1429*//*1430:*/
#line 17119 "./marpa.w"

int _marpa_t_nook_predecessor_is_ready(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 17123 "./marpa.w"

/*1117:*/
#line 13011 "./marpa.w"

ORDER o= O_of_T(t);
/*1089:*/
#line 12543 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1044:*/
#line 12138 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:1044*/
#line 12545 "./marpa.w"


/*:1089*/
#line 13013 "./marpa.w"
;

/*:1117*/
#line 17124 "./marpa.w"

/*1425:*/
#line 17061 "./marpa.w"
{
NOOK base_nook;
/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 17063 "./marpa.w"

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

/*:1425*/
#line 17125 "./marpa.w"

return NOOK_Predecessor_is_Expanded(nook);
}

/*:1430*//*1431:*/
#line 17129 "./marpa.w"

int _marpa_t_nook_is_cause(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 17133 "./marpa.w"

/*1117:*/
#line 13011 "./marpa.w"

ORDER o= O_of_T(t);
/*1089:*/
#line 12543 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1044:*/
#line 12138 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:1044*/
#line 12545 "./marpa.w"


/*:1089*/
#line 13013 "./marpa.w"
;

/*:1117*/
#line 17134 "./marpa.w"

/*1425:*/
#line 17061 "./marpa.w"
{
NOOK base_nook;
/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 17063 "./marpa.w"

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

/*:1425*/
#line 17135 "./marpa.w"

return NOOK_is_Cause(nook);
}

/*:1431*//*1432:*/
#line 17139 "./marpa.w"

int _marpa_t_nook_is_predecessor(Marpa_Tree t,int nook_id)
{
NOOK nook;
/*1313:*/
#line 15629 "./marpa.w"
const int failure_indicator= -2;

/*:1313*/
#line 17143 "./marpa.w"

/*1117:*/
#line 13011 "./marpa.w"

ORDER o= O_of_T(t);
/*1089:*/
#line 12543 "./marpa.w"

const BOCAGE b= B_of_O(o);
/*1044:*/
#line 12138 "./marpa.w"

const GRAMMAR g UNUSED= G_of_B(b);

/*:1044*/
#line 12545 "./marpa.w"


/*:1089*/
#line 13013 "./marpa.w"
;

/*:1117*/
#line 17144 "./marpa.w"

/*1425:*/
#line 17061 "./marpa.w"
{
NOOK base_nook;
/*1333:*/
#line 15762 "./marpa.w"

if(HEADER_VERSION_MISMATCH){
MARPA_ERROR(MARPA_ERR_HEADERS_DO_NOT_MATCH);
return failure_indicator;
}
if(_MARPA_UNLIKELY(!IS_G_OK(g))){
MARPA_ERROR(g->t_error);
return failure_indicator;
}

/*:1333*/
#line 17063 "./marpa.w"

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

/*:1425*/
#line 17145 "./marpa.w"

return NOOK_is_Predecessor(nook);
}

/*:1432*//*1434:*/
#line 17160 "./marpa.w"

void marpa_debug_handler_set(int(*debug_handler)(const char*,...))
{
marpa__debug_handler= debug_handler;
}

/*:1434*//*1435:*/
#line 17166 "./marpa.w"

int marpa_debug_level_set(int new_level)
{
const int old_level= marpa__debug_level;
marpa__debug_level= new_level;
return old_level;
}


/*:1435*/
#line 17350 "./marpa.w"


/*:1453*/

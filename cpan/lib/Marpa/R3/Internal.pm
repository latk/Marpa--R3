# Marpa::R3 is Copyright (C) 2016, Jeffrey Kegler.
#
# This module is free software; you can redistribute it and/or modify it
# under the same terms as Perl 5.10.1. For more details, see the full text
# of the licenses in the directory LICENSES.
#
# This program is distributed in the hope that it will be
# useful, but it is provided “as is” and without any express
# or implied warranties. For details, see the full text of
# of the licenses in the directory LICENSES.

# DO NOT EDIT THIS FILE DIRECTLY
# It was generated by make_internal_pm.pl

package Marpa::R3::Internal;

use 5.010001;
use strict;
use warnings;
use Carp;

use vars qw($VERSION $STRING_VERSION);
$VERSION        = '4.001_033';
$STRING_VERSION = $VERSION;
$VERSION = eval $VERSION;


package Marpa::R3::Internal::XSY;
use constant ID => 0;
use constant NAME => 1;
use constant NAME_SOURCE => 2;
use constant BLESSING => 3;
use constant LEXEME_SEMANTICS => 4;
use constant DSL_FORM => 5;
use constant IF_INACCESSIBLE => 6;

package Marpa::R3::Internal::XRL;
use constant ID => 0;
use constant NAME => 1;
use constant LHS => 2;
use constant START => 3;
use constant LENGTH => 4;
use constant PRECEDENCE_COUNT => 5;

package Marpa::R3::Internal::XBNF;
use constant ID => 0;
use constant NAME => 1;
use constant START => 2;
use constant LENGTH => 3;
use constant LHS => 4;
use constant RHS => 5;
use constant RANK => 6;
use constant NULL_RANKING => 7;
use constant MIN => 8;
use constant SEPARATOR => 9;
use constant PROPER => 10;
use constant DISCARD_SEPARATION => 11;
use constant MASK => 12;
use constant ACTION_NAME => 13;
use constant BLESSING => 14;
use constant SYMBOL_AS_EVENT => 15;
use constant EVENT => 16;
use constant XRL => 17;

package Marpa::R3::Internal::Trace::G;
use constant NAME => 0;
use constant SLG_C => 1;
use constant C => 2;
use constant XSY_BY_ISYID => 3;
use constant XBNF_BY_IRLID => 4;
use constant ACTION_BY_IRLID => 5;
use constant MASK_BY_IRLID => 6;
use constant START_NAME => 7;

package Marpa::R3::Internal::Progress_Report;
use constant RULE_ID => 0;
use constant POSITION => 1;
use constant ORIGIN => 2;
use constant CURRENT => 3;

package Marpa::R3::Internal::Glade;
use constant ID => 0;
use constant SYMCHES => 1;
use constant VISITED => 2;
use constant REGISTERED => 3;

package Marpa::R3::Internal::Choicepoint;
use constant ASF => 0;
use constant FACTORING_STACK => 1;
use constant OR_NODE_IN_USE => 2;

package Marpa::R3::Internal::Nook;
use constant PARENT => 0;
use constant OR_NODE => 1;
use constant FIRST_CHOICE => 2;
use constant LAST_CHOICE => 3;
use constant IS_CAUSE => 4;
use constant IS_PREDECESSOR => 5;
use constant CAUSE_IS_EXPANDED => 6;
use constant PREDECESSOR_IS_EXPANDED => 7;

package Marpa::R3::Internal::ASF;
use constant SLR => 0;
use constant LEXEME_RESOLUTIONS => 1;
use constant RULE_RESOLUTIONS => 2;
use constant FACTORING_MAX => 3;
use constant RULE_BLESSINGS => 4;
use constant SYMBOL_BLESSINGS => 5;
use constant SYMCH_BLESSING_PACKAGE => 6;
use constant FACTORING_BLESSING_PACKAGE => 7;
use constant PROBLEM_BLESSING_PACKAGE => 8;
use constant DEFAULT_RULE_BLESSING_PACKAGE => 9;
use constant DEFAULT_TOKEN_BLESSING_PACKAGE => 10;
use constant OR_NODES => 11;
use constant GLADES => 12;
use constant INTSET_BY_KEY => 13;
use constant NEXT_INTSET_ID => 14;
use constant NIDSET_BY_ID => 15;
use constant POWERSET_BY_ID => 16;

package Marpa::R3::Internal::ASF::Traverse;
use constant ASF => 0;
use constant VALUES => 1;
use constant CODE => 2;
use constant PER_TRAVERSE_OBJECT => 3;
use constant GLADE => 4;
use constant SYMCH_IX => 5;
use constant FACTORING_IX => 6;

package Marpa::R3::Internal::Nidset;
use constant ID => 0;
use constant NIDS => 1;

package Marpa::R3::Internal::Powerset;
use constant ID => 0;
use constant NIDSET_IDS => 1;

package Marpa::R3::Internal::Scanless::G;
use constant C => 0;
use constant L0_TRACER => 1;
use constant G1_TRACER => 2;
use constant CHARACTER_CLASS_TABLE => 3;
use constant DISCARD_EVENT_BY_LEXER_RULE => 4;
use constant XSY_BY_ID => 5;
use constant XSY_BY_NAME => 6;
use constant L0_XBNF_BY_ID => 7;
use constant G1_XBNF_BY_ID => 8;
use constant L0_XBNF_BY_NAME => 9;
use constant G1_XBNF_BY_NAME => 10;
use constant XRL_BY_ID => 11;
use constant XRL_BY_NAME => 12;
use constant COMPLETION_EVENT_BY_ID => 13;
use constant NULLED_EVENT_BY_ID => 14;
use constant PREDICTION_EVENT_BY_ID => 15;
use constant LEXEME_EVENT_BY_ID => 16;
use constant SYMBOL_IDS_BY_EVENT_NAME_AND_TYPE => 17;
use constant BLESS_PACKAGE => 18;
use constant IF_INACCESSIBLE => 19;
use constant WARNINGS => 20;
use constant TRACE_FILE_HANDLE => 21;
use constant CHARACTER_CLASSES => 22;

package Marpa::R3::Internal::Scanless::R;
use constant SLG => 0;
use constant SLR_C => 1;
use constant P_INPUT_STRING => 2;
use constant EXHAUSTION_ACTION => 3;
use constant REJECTION_ACTION => 4;
use constant TRACE_FILE_HANDLE => 5;
use constant TRACE_VALUES => 6;
use constant TRACE_ACTIONS => 7;
use constant READ_STRING_ERROR => 8;
use constant EVENTS => 9;
use constant ERROR_MESSAGE => 10;
use constant MAX_PARSES => 11;
use constant RANKING_METHOD => 12;
use constant NO_PARSE => 13;
use constant NULL_VALUES => 14;
use constant TREE_MODE => 15;
use constant END_OF_PARSE => 16;
use constant SEMANTICS_PACKAGE => 17;
use constant REGISTRATIONS => 18;
use constant CLOSURE_BY_SYMBOL_ID => 19;
use constant CLOSURE_BY_RULE_ID => 20;

1;

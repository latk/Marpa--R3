#!perl
# Copyright 2011 Jeffrey Kegler
# This file is part of Marpa::PP.  Marpa::PP is free software: you can
# redistribute it and/or modify it under the terms of the GNU Lesser
# General Public License as published by the Free Software Foundation,
# either version 3 of the License, or (at your option) any later version.
#
# Marpa::PP is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser
# General Public License along with Marpa::PP.  If not, see
# http://www.gnu.org/licenses/.
# Two rules which start with nullables, and cycle.

use 5.010;
use strict;
use warnings;

use Test::More tests => 4;

use Marpa::PP::Test;

BEGIN {
    Test::More::use_ok('Marpa::Any');
}

## no critic (Subroutines::RequireArgUnpacking)

sub default_action {
    shift;
    my $v_count = scalar @_;
    return q{} if $v_count <= 0;
    my @vals = map { $_ // q{-} } @_;
    return '(' . join( q{;}, @vals ) . ')';
} ## end sub default_action

sub rule_n {
    shift;
    return 'n(' . ( join q{;}, map { $_ // q{-} } @_ ) . ')';
}

sub start_rule {
    shift;
    return 'S(' . ( join q{;}, ( map { $_ // q{-} } @_ ) ) . ')';
}

sub rule_f {
    shift;
    return 'f(' . ( join q{;}, ( map { $_ // q{-} } @_ ) ) . ')';
}

## use critic

my $grammar = Marpa::Grammar->new(
    {   start           => 'S',
        strip           => 0,
        infinite_action => 'quiet',

        rules => [
            { lhs => 'S', rhs => [qw/n f/], action => 'main::start_rule' },
            { lhs => 'n', rhs => ['a'],     action => 'main::rule_n' },
            { lhs => 'n', rhs => [] },
            { lhs => 'f', rhs => ['a'],     action => 'main::rule_f' },
            { lhs => 'f', rhs => [] },
            { lhs => 'f', rhs => ['S'],     action => 'main::rule_f' },
        ],
        symbols        => { a => { terminal => 1 }, },
        default_action => 'main::default_action',
    }
);

$grammar->precompute();

# PP and XS differ on this test.  The result of this test
# is not well-defined, and it exists as much to track
# changes as anything.
# So I do not treat the difference as a bug.

my @expected3 = ();
if ($Marpa::USING_PP) {
    push @expected3, qw{
        S(-;f(S(n(A);f(S(-;f(S(n(A);f(A))))))))
        S(-;f(S(n(A);f(S(-;f(S(n(A);f(S(-;f(A))))))))))
        S(-;f(S(n(A);f(S(-;f(S(n(A);f(S(-;f(S(n(A);-)))))))))))
        S(-;f(S(n(A);f(S(-;f(S(n(A);f(S(n(A);-)))))))))
        S(-;f(S(n(A);f(S(n(A);f(A))))))
        S(-;f(S(n(A);f(S(n(A);f(S(-;f(A))))))))
        S(-;f(S(n(A);f(S(n(A);f(S(-;f(S(n(A);-)))))))))
        S(-;f(S(n(A);f(S(n(A);f(S(n(A);-)))))))
    };
} ## end if ($Marpa::USING_PP)

push @expected3, qw{
    S(n(A);f(S(-;f(S(n(A);f(A))))))
    S(n(A);f(S(-;f(S(n(A);f(S(-;f(A))))))))
    S(n(A);f(S(-;f(S(n(A);f(S(-;f(S(n(A);-)))))))))
    S(n(A);f(S(-;f(S(n(A);f(S(n(A);-)))))))
    S(n(A);f(S(n(A);f(A))))
    S(n(A);f(S(n(A);f(S(-;f(A))))))
    S(n(A);f(S(n(A);f(S(-;f(S(n(A);-)))))))
    S(n(A);f(S(n(A);f(S(n(A);-)))))
};

my @expected = (
    [q{}],
    [   qw{
            S(-;f(A))
            S(-;f(S(n(A);-)))
            S(n(A);-)
            }
    ],
    [   qw{
            S(-;f(S(n(A);f(S(-;f(A))))))
            S(-;f(S(n(A);f(S(-;f(S(n(A);-)))))))
            S(-;f(S(n(A);f(S(n(A);-)))))
            S(-;f(S(n(A);f(A))))
            S(n(A);f(S(-;f(A))))
            S(n(A);f(S(-;f(S(n(A);-)))))
            S(n(A);f(S(n(A);-)))
            S(n(A);f(A))
            }
    ],
    \@expected3,
);

for my $input_length ( 1 .. 3 ) {
    my $recce = Marpa::Recognizer->new(
        { grammar => $grammar, max_parses => 99 } );
    $recce->tokens( [ ( [ 'a', 'A' ] ) x $input_length ] );
    my $expected = $expected[$input_length];
    my @values   = ();
    while ( my $value_ref = $recce->value() ) {
        push @values, ${$value_ref};
    }
    Marpa::Test::is(
        ( join "\n", sort @values ),
        ( join "\n", sort @{$expected} ),
        "value for input length $input_length"
    );
} ## end for my $input_length ( 1 .. 3 )

1;    # In case used as "do" file

# Local Variables:
#   mode: cperl
#   cperl-indent-level: 4
#   fill-column: 100
# End:
# vim: expandtab shiftwidth=4:

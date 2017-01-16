#!perl
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

# Synopsis tests

# Test SLIF -- predicted, nulled and completed events with 
# deactivation and reactivation, initialization at DSL time,
# initialization override at recce creation time

use 5.010001;
use strict;
use warnings;

use Test::More tests => 10;
use English qw( -no_match_vars );
use POSIX qw(setlocale LC_ALL);

POSIX::setlocale(LC_ALL, "C");

use lib 'inc';
use Marpa::R3::Test;
use Marpa::R3;

my $rules = <<'END_OF_GRAMMAR';
:start ::= sequence
sequence ::= A B C D
    action => OK
A ::= 'a'
A ::= # empty
B ::= 'b'
B ::= # empty
C ::= 'c'
C ::= # empty
D ::= 'd'
D ::= # empty

# Marpa::R3::Display
# name: SLIF predicted event statement synopsis

event '^a' = predicted A
event '^b'=off = predicted B
event '^c'=on = predicted C
event '^d' = predicted D

# Marpa::R3::Display::End

# Marpa::R3::Display
# name: SLIF completed event statement synopsis

event 'a' = completed A
event 'b'=off = completed B
event 'c'=on = completed C
event 'd' = completed D

# Marpa::R3::Display::End

# Marpa::R3::Display
# name: SLIF nulled event statement synopsis

event '!a' = nulled A
event '!b'=off = nulled B
event '!c'=on = nulled C
event '!d' = nulled D

# Marpa::R3::Display::End

END_OF_GRAMMAR

# This test the order of events
# No more than one of each event type per line
# so that order is non-arbitrary
my $location_0_events = qq{0 !a !b !c !d ^a ^b ^c ^d\n};
my $after_0_events = <<'END_OF_EVENTS';
1 !b !c !d ^b ^c ^d a
2 !c !d ^c ^d b
3 !d ^d c
4 d
END_OF_EVENTS

my $grammar = Marpa::R3::Scanless::G->new( { source => \$rules } );

my @events = map { ( '!' . $_, '^' . $_, $_ ) } qw(a b c d);

# Test of all events
my $events_expected = <<'EOS';
0 !a !c !d ^a ^c ^d
1 !c !d ^c ^d a
2 !c !d ^c ^d
3 !d ^d c
4 d
EOS
do_test( "all events", $grammar, q{abcd}, $events_expected );

$events_expected = <<'EOS';
0 !a !c !d ^a ^c ^d
1
2
3
4
EOS
do_test( "all events deactivated",
    $grammar, q{abcd}, $events_expected, [] );

# Add events for symbol b
my %event_is_active = map { ( $_, 1 ) } @events;
my $extra_recce_arg = { 'event_is_active' => \%event_is_active };
$events_expected = <<'EOS';
0 !a !b !c !d ^a ^b ^c ^d
1 !b !c !d ^b ^c ^d a
2 !c !d ^c ^d b
3 !d ^d c
4 d
EOS
do_test( 'all events activated in $recce->new()', $grammar, q{abcd}, $events_expected, undef,
    $extra_recce_arg );

$events_expected = <<'EOS';
0 !a !b !c !d ^a ^b ^c ^d
1
2
3
4
EOS
do_test( 'all events activated in $recce->new(), then deactivated',
    $grammar, q{abcd}, $events_expected, [], $extra_recce_arg );

$event_is_active{$_} = 0 for keys %event_is_active;

$events_expected = <<'EOS';
0
1
2
3
4
EOS
do_test( 'all events deactivated in $recce->new(), then deactivated again',
    $grammar, q{abcd}, $events_expected, [], $extra_recce_arg );

sub show_last_subtext {
    my ($recce) = @_;
    my ( $start, $length ) = $recce->last_completed('subtext');
    return 'No expression was successfully parsed' if not defined $start;
    return $recce->g1_literal( $start, $length );
}

sub do_test {
    my ( $test, $slg, $string, $expected_events, $reactivate_events, $recce_args ) = @_;
    $recce_args //= {};
    my $recce = Marpa::R3::Scanless::R->new(
        { grammar => $grammar, semantics_package => 'My_Actions' }, $recce_args );
    if (defined $reactivate_events) {

# Marpa::R3::Display
# name: SLIF activate() method synopsis

        $recce->activate($_, 0) for @events;

# Marpa::R3::Display::End

        $recce->activate($_) for @{$reactivate_events};

    }

    my @actual_events = ();
    my $length = length $string;
    my $pos    = $recce->read( \$string );
    READ: while (1) {

        EVENT:
        for my $event ( @{ $recce->events() } ) {
            my ($name) = @{$event};
            push @{$actual_events[$pos]}, $name;
        }

        last READ if $pos >= $length;
        $pos = $recce->resume($pos);
    } ## end READ: while (1)

    my $value_ref = $recce->value();
    if ( not defined $value_ref ) {
        die "No parse\n";
    }
    my $actual_value = ${$value_ref};
    my $actual_events = q{};
    for (my $i = 0; $i <= $length; $i++) {
        my $events = $actual_events[$i] // [];
        $actual_events .= join " ", $i, sort @{$events};
        $actual_events .= "\n";
    }
    Test::More::is( $actual_value, q{1792}, qq{Value for $test} );
    Marpa::R3::Test::is( $actual_events, $expected_events,
        qq{Events for $test} );
} ## end sub do_test

sub My_Actions::OK { return 1792 };

# vim: expandtab shiftwidth=4:

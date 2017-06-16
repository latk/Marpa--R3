#!/usr/bin/perl
# Marpa::R3 is Copyright (C) 2017, Jeffrey Kegler.
#
# This module is free software; you can redistribute it and/or modify it
# under the same terms as Perl 5.10.1. For more details, see the full text
# of the licenses in the directory LICENSES.
#
# This program is distributed in the hope that it will be
# useful, but it is provided "as is" and without any express
# or implied warranties. For details, see the full text of
# of the licenses in the directory LICENSES.

# A display-focused test.
# Examples of event handler usage

use 5.010001;
use strict;
use warnings;
use English qw( -no_match_vars );
use POSIX qw(setlocale LC_ALL);

POSIX::setlocale(LC_ALL, "C");

use Test::More tests => 1;

use lib 'inc';
use Marpa::R3::Test;

## no critic (ErrorHandling::RequireCarping);

## Basic

use Marpa::R3;

# Marpa::R3::Display
# name: event examples: grammar 1

my $g = Marpa::R3::Scanless::G->new(
    {
        source => \<<'END_OF_DSL'
        top ::= A B C
        A ::= 'a'
        B ::= 'b'
        C ::= 'c'
        event A = completed A
        event B = completed B
        event C = completed C
        :discard ~ ws
        ws ~ [\s]+
END_OF_DSL
    },
);

# Marpa::R3::Display::End

my @results = ();
my $recce;

# Marpa::R3::Display
# name: event examples: basic

@results = ();
$recce   = Marpa::R3::Scanless::R->new(
    {
        grammar        => $g,
        event_handlers => {
            A => sub () { push @results, 'A'; 'ok' },
            B => sub () { push @results, 'B'; 'ok' },
            C => sub () { push @results, 'C'; 'ok' },
        }
    }
);

# Marpa::R3::Display::End

$recce->read( \"a b c" );
Test::More::is( ( join q{ }, @results ), 'A B C', 'example 1' );

# Marpa::R3::Display
# name: event examples: default

@results = ();
$recce = Marpa::R3::Scanless::R->new(
    {
        grammar        => $g,
        event_handlers => {
            "'default" => sub () {
                my ( $slr, $event_name ) = @_;
                push @results, $event_name;
                'ok';
            },
        }
    }
);

# Marpa::R3::Display::End

$recce->read( \"a b c" );
Test::More::is( ( join q{ }, @results ), 'A B C', 'example 1' );

# Marpa::R3::Display
# name: event examples: default and explicit

@results = ();
$recce = Marpa::R3::Scanless::R->new(
    {
        grammar        => $g,
        event_handlers => {
            A => sub () { push @results, 'A'; 'ok' },
            "'default" => sub () {
                my ( $slr, $event_name ) = @_;
                push @results, "!A=$event_name";
                'ok';
            },
        }
    }
);

# Marpa::R3::Display::End

$recce->read( \"a b c" );
Test::More::is( ( join q{ }, @results ), 'A !A=B !A=C', 'example 1' );

## Basic (with default)

## Rejected, Exhausted

## Data (using after lexeme)

## Data using factory

## Per-location processing, using pause

## Per-location processing, using array

# vim: expandtab shiftwidth=4:

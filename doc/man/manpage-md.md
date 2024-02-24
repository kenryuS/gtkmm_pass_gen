% PassGen(1) Version 1.0.0 | Password Generator Docmumentation

NAME
====

PassGen - Generates random password

SYNOPSIS
========

| `PassGen [-A|--upper|-a|--lower|-n|--number|-s|--special] [-l|--length length]`
| `PassGen [-g|--gui|-t|--tui]`
| `PassGen [-h|--help|-b|--build-info]`

DESCRIPTION
===========

There are three different mode on UIs: CUI, TUI, GUI(GTK).

When you running the program in TUI or GUI mode, all other flags or options are ommited.

You can generate random password by specifing character sets and length.

OPTIONS
=======

`-h, --help`

: prints help

`-b, --build-info`

: prints build parameters used in CMake build

`-A, --upper`

: (CUI Mode) include English upper case alphabets in password

`-a, --lower`

: (CUI Mode) include English lower case alphabets in password

`-n, --number`

: (CUI Mode) include Arabical numerical characters in password

`-s, --special`

: (CUI Mode) include special characters in password

`-l, --length`

: (CUI Mode) specifies length of password

`-g, --gui`

: (GUI Mode) Run the GTK GUI version of program

`-t, --tui`

: (TUI Mode) Run the NCURSES TUI version of program


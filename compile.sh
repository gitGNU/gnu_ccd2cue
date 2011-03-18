#!/bin/bash

if test "$1" == "-d"
then
    gcc src/ccd2cue.c -o bin/ccd2cue -ggdb
else
    gcc src/ccd2cue.c -o bin/ccd2cue
fi

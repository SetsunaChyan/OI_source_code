#!/bin/bash

makeps="true"
makepdf="true"
clean="true"

cd pics
./r.sh "$*"
cd ..

function maketex {
    latex $1.tex
    latex $1.tex
    if [ "$makeps" == "true" ]; then
        dvips $1.dvi
    fi
    if [ "$makepdf" == "true" ]; then
        if which dvipdf >/dev/null 2>/dev/null
        then
            dvipdf $1.dvi
        elif which ps2pdf > /dev/null 2>/dev/null
        then
            ps2pdf $1.ps
        fi
    fi
}

maketex problems

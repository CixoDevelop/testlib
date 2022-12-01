#!/bin/bash

SOURCE=../sources/testlib.c
OBJECT=./testlib.o
LIB=./libtestlib.a

CC="gcc"
CC_FLAGS="-Wall -Wextra -Wpedantic -O3" 

AR="ar"
AR_FLAGS="-cq"

set -x

rm $OBJECT -f
rm $LIB -f

$CC $CC_FLAGS -c $SOURCE -o $OBJECT
$AR $AR_FLAGS $LIB $OBJECT

rm $OBJECT -f

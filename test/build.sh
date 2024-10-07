#!/bin/bash -x

mkdir -p build

CC="gcc"
CFLAGS="-Wall -Wextra -std=c99"
RAYDIR="../lib/raylib/src"
APPLFLAGS="-framework IOKit -framework OpenGL -framework Cocoa"

$CC $CFLAGS -c ../src/vector.c -o ../build/vector.o -I../lib
$CC $CFLAGS -o build/$1 $1/$1.c -I../lib -I$RAYDIR -L$RAYDIR -lraylib $APPLFLAGS ../build/vector.o

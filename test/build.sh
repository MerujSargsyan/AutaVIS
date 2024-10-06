#!/bin/bash -x

mkdir -p build

CC="gcc"
CFLAGS="-Wall -Wextra -std=c99"
RAYDIR="../lib/raylib/src"
APPLFLAGS="-framework IOKit -framework OpenGL -framework Cocoa"

$CC $CFLAGS -o build/$1 $1/$1.c -I$RAYDIR -L$RAYDIR -lraylib $APPLFLAGS

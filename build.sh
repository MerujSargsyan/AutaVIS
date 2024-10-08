#!/bin/bash -x

git submodule update --init --recursive
cd lib/raylib/src/ && make && cd -

mkdir -p build

CC="gcc"
CFLAGS="-Wall -Wextra -std=c99"
RAYDIR="lib/raylib/src"
APPLFLAGS="-framework IOKit -framework OpenGL -framework Cocoa"

$CC $CFLAGS -c src/vector.c -o build/vector.o -Ilib/
$CC $CFLAGS -o build/main src/main.c -Ilib/ -I$RAYDIR -L$RAYDIR build/vector.o -lraylib $APPLFLAGS

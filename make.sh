#!/bin/sh
# Dit script ondersteunt drie commando's:
#   compile: Compileert de bronbestanden en maakt de binary
#   run:   Voert de binary uit (bouwt eerst als die nog niet bestaat)
#   clean: Verwijdert de binary en de build directory

# Variabelen (hardcoded voor eenvoud)
SRC_DIR="src"
BUILD_DIR="build"
TARGET="game.bin"
CFLAGS="-Wall -Wextra -std=c11"

# TODO
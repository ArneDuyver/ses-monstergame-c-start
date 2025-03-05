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

# Zorg dat er minstens één argument is meegegeven
if [ "$#" -lt 1 ]; then
    echo "Gebruik: $0 {compile|run|clean} [--hp <waarde>]"
    exit 1
fi

COMMAND=$1
# Shift the parameters so the second becomes the first etc.
shift 

if [ "$COMMAND" = "compile" ]; then
    echo "Bouwen van het project..."

    # Maak de build-directory als deze nog niet bestaat
    if [ ! -d "$BUILD_DIR" ]; then
        mkdir -p "$BUILD_DIR"
    fi

    # Compileer main.c en game.c naar objectbestanden in build/
    echo "Compileren van $SRC_DIR/main.c..."
    gcc $CFLAGS -c "$SRC_DIR/main.c" -o "$BUILD_DIR/main.o"
    echo "Compileren van $SRC_DIR/game.c..."
    gcc $CFLAGS -c "$SRC_DIR/game.c" -o "$BUILD_DIR/game.o"

    # Link de objectbestanden naar de uiteindelijke binary in de root
    echo "Linken naar $TARGET..."
    gcc $CFLAGS -o "$TARGET" "$BUILD_DIR/main.o" "$BUILD_DIR/game.o"
    echo "Build succesvol: $TARGET is aangemaakt."

elif [ "$COMMAND" = "run" ]; then
    # Bouw de binary als deze niet bestaat
    if [ ! -f "$TARGET" ]; then
        echo "Binary niet gevonden, eerst bouwen..."
        sh "$0" build "$@"
    fi
    echo "Uitvoeren van $TARGET..."
    ./"$TARGET" "$@"

elif [ "$COMMAND" = "clean" ]; then
    echo "Opruimen..."
    # Verwijder de binary en de build-directory
    rm -rf "$BUILD_DIR/*"
    rm -f "$TARGET"
    echo "Opruimen voltooid."

else
    echo "Onbekend commando: $COMMAND"
    echo "Gebruik: $0 {compile|run|clean} [--hp <waarde>]"
    exit 1
fi
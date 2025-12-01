#!/usr/bin/env bash

set -e

PROJECT_ROOT="$(pwd)"

# Compute relative path between two paths without GNU realpath.
relpath() {
    local target="$1"
    local base="$2"

    target="$(cd "$(dirname "$target")" && pwd)/$(basename "$target")"
    base="$(cd "$base" && pwd)"

    # Split paths into arrays
    IFS='/' read -r -a target_parts <<< "$target"
    IFS='/' read -r -a base_parts <<< "$base"

    # Find common prefix length
    local i=0
    while [[ $i -lt ${#target_parts[@]} && $i -lt ${#base_parts[@]} && "${target_parts[$i]}" == "${base_parts[$i]}" ]]; do
        ((i++))
    done

    # Build relative path: go up from base
    local up=""
    for ((j=i; j<${#base_parts[@]}; j++)); do
        up="../$up"
    done

    # Add the remaining part of target
    local down=""
    for ((j=i; j<${#target_parts[@]}; j++)); do
        down="$down/${target_parts[$j]}"
    done

    # Remove leading slash
    down="${down#/}"

    echo "$up$down"
}

TEMPLATE='
# Load .env variables
include RELPATH
export $$(shell sed -n '\''s/^\([^#][^=]*\)=.*/\1/p'\'' RELPATH)

one:
	/usr/bin/g++ 1.cpp -o exe -O2 -std=c++20
	./exe < input.txt > output.txt

two:
	/usr/bin/g++ 2.cpp -o exe -O2 -std=c++20
	./exe < input.txt > output.txt

get:
	aocdl -year YEAR -day DAY -force -session-cookie $(AOC_SESSION)

cp:
	cp 1.cpp 2.cpp

clear:
	rm exe
'

find . -type f -name Makefile | while read -r mkfile; do
    dir="$(dirname "$mkfile")"

    YEAR="$(basename "$(dirname "$dir")")"
    # Normalize dayXX, day1, day01, day10
    DAY="$(basename "$dir" | sed -E 's/^day0?//; s/^day//')"

    RELPATH="$(relpath "$PROJECT_ROOT/.env" "$dir")"

    CONTENT="$TEMPLATE"
    CONTENT="${CONTENT//RELPATH/$RELPATH}"
    CONTENT="${CONTENT//YEAR/$YEAR}"
    CONTENT="${CONTENT//DAY/$DAY}"

    echo "Updating $mkfile ..."
    printf "%s\n" "$CONTENT" > "$mkfile"
done

echo "All Makefiles updated successfully."

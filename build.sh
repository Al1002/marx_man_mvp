#!/bin/bash

# Function to recursively build directories
recursive_build() {
    local dir="$1"
    cd "$dir" || exit 1

    # Check if Makefile exists
    if [ ! -f "Makefile" ]; then
        cd ..
        return
    fi
    echo "Building in $dir"

    # Build in subdirectories
    for subdir in */; do
        if [ -d "$subdir" ]; then
            recursive_build "$subdir"
        fi
    done
    
    # Build in parent directory
    make build > /dev/null
    
    cd ..
}

script_dir="$(dirname "$0")"

cd $script_dir

recursive_build src/

source dependencies.conf
if [ -f main.cpp ]; then
    g++ main.cpp -o main.out -L.lib $LIBS
fi

if [ -f main.c ]; then
    gcc main.c -o main.out -L.lib $LIBS
fi

#!/bin/bash

contest=$(printf "%03d" "$1")
last=${2:-g}

dir="abc/$contest"
mkdir -p "$dir"

for problem in {a..z}; do
    file="$dir/$problem.cpp"

    if [ ! -e "$file" ]; then
        {
            echo "// The template file is below"
            echo "// https://github.com/micci439899/atcoder"
            echo ""
            cat template.cpp
        } > "$file"

        echo "Created: $file"
    fi

    if [ "$problem" = "$last" ]; then
        break
    fi
done
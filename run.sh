#!/bin/bash

input_num="$1"

file_to_compile="src/${input_num}_*.c"

if [ -f "$file_to_compile" ]; then
    file_name=$(basename "$file_to_compile" .c)
    if [ ! -d "compiled" ]; then
        mkdir compiled
    fi

    gcc -g "$file_to_compile" -o "compiled/$file_name"
    chmod u+x "compiled/$file_name"
    "./compiled/$file_name"
else
    echo "Invalid or non-existent numeric input."
    echo "Please provide a number that corresponds to the first character of the name of one of the available files"
    echo "Example: ./run.sh 1"
    echo "Available files:"
    find src/ -maxdepth 1 -type f -name '[0-9]*_*.c' -exec basename {} \;
fi


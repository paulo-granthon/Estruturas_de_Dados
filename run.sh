#!/bin/bash

function run_file {
    directory="$1"
    input_num="$2"

    file_to_compile=$(find src/"${directory}"/ -maxdepth 1 -type f -name "${input_num}_*.c")

    if [ -f "$file_to_compile" ]; then

        file_name=$(basename "$file_to_compile" .c)

        if [ ! -d "compiled" ]; then
            mkdir compiled
        fi
        if [ ! -d "compiled/${directory}" ]; then
            mkdir compiled/"${directory}"
        fi

        gcc -g "$file_to_compile" \
            ./src/utils/error_codes.c \
            ./src/utils/operation_codes.c \
            ./src/utils/array_utils.c \
            -o "compiled/$directory/$file_name"
        chmod u+x "compiled/$directory/$file_name"
        "./compiled/$directory/$file_name"
    else
        echo "Invalid or non-existent numeric input."
        echo "Please provide a number that corresponds to the first character of the name of one of the available files"
        echo "Available files in \`${directory}\`:"
        find src/"${directory}/" -maxdepth 1 -type f -name '[0-9]*_*.c' -exec basename {} \;
    fi
}

case "$1" in
    "d")
        run_file data_structures "$2"
        ;;
    "m")
        run_file misc "$2"
        ;;
    *)
        echo "Invalid or non-existent scope input. Usage:"
        echo "$0 [d | m] [number]"
        echo "  d : The data_structure/ directory"
        echo "  m : The misc/ directory"
        ;;
esac

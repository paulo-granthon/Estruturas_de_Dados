#!/bin/bash

num_files=$(find src/ -maxdepth 1 -type f -name '[0-9]*_*.c' | wc -l)
input_num="$1"

if ! [[ "$input_num" =~ ^[0-9]+$ ]]; then
  echo "Invalid input. Please provide a number between 1 and $num_files."
else
  if ((input_num >= 0 && input_num <= num_files)); then
    file_to_compile=$(find src/ -maxdepth 1 -type f -name "${input_num}_*.c")
    file_name=$(basename "$file_to_compile" .c)
    
    if [ ! -d "compiled" ]; then
      mkdir compiled
    fi
    
    gcc -g "$file_to_compile" -o "compiled/$file_name"
    chmod u+x "compiled/$file_name"
    "./compiled/$file_name"
  else
    echo "Invalid number. Please provide a number between 1 and $num_files."
    echo "Available files:"
    find src/ -maxdepth 1 -type f -name '[0-9]*_*.c' -exec basename {} \;
  fi
fi


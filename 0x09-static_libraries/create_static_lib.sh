#!/bin/bash

# Collect all .c files in the current directory
source_files=$(ls *.c 2>/dev/null)

# Check if there are any .c files
if [ -z "$source_files" ]; then
  echo "No .c files found in the current directory."
  exit 1
fi

# Compile the .c files and create a static library
gcc -c $source_files        # Compile each .c file into a corresponding .o file
ar rcs liball.a *.o         # Create the static library from all the .o files

# Clean up by removing the intermediate .o files
rm -f *.o

echo "Static library liball.a created successfully."

#!/bin/bash

# Compile source files to object files
g++ -c main.cpp -o main.o
g++ -c question_functions.cpp -o question_functions.o
g++ -c player_functions.cpp -o player_functions.o

# Link object files to create executable
g++ main.o question_functions.o player_functions.o -o millionaire_game

# Check if compilation and linking were successful
if [ $? -eq 0 ]; then
    echo "Compilation and linking successful. Executable created: millionaire_game"
else
    echo "Error: Compilation or linking failed."
fi
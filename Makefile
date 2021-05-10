# Makefile for the directory manager repo
# Instructions to use: 
# 1. Type `make compile` on the terminal to compile
# 2. Type `make run` on the terminal to run the program

# compiler options
CC=gcc

# file paths
file=main.c
output=main.out


compile:
	@echo "Building code."
	$(CC) -o $(output) **/*.c *.c

run:
	./$(output)


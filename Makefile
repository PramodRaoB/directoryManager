#!bin/bash
# Makefile for the directory manager repo
# Instructions to use: 
# 1. Type `make compile` on the terminal to compile
# 2. Type `make run` on the terminal to run the program

# compiler options
CC=gcc
CLANG=clang

# file paths
file=main.c
output=main.out

default:
	$(CC) -o $(output) **/*.c *.c
	./$(output)
	rm $(output)
clang:
	$(CLANG) -o $(output) **/*.c *.c
	./$(output)
	rm $(output)

compile:
# 	@echo "Building code."
	$(CC) -o $(output) **/*.c *.c

run:
	./$(output)


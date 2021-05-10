#!bin/bash
# Makefile for the directory manager repo
# Instructions to use: 
# 1. Type `make compile` on the terminal to compile
# 2. Type `make run` on the terminal to run the program
# 3. Type `make clean` after execution to clear the bin folder

# compiler options
CC=gcc

CFLAGS=-c -o


# file paths
TREE=Directree
BIN=bin
UTILS=utils
HASH="Hash(Alias)"
file=main.c
output=main.out

default:
	$(CC) -o $(output) **/*.c *.c
	./$(output)
	clear
	


compile:
# 	@echo "Building code."
	$(CC) -o $(output) **/*.c *.c

run:
	./$(output)


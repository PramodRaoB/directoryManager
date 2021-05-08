#ifndef __STRING_PARSER_H__
#define __STRING_PARSER_H__

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *read_string(void);

int *parser_func(char *path);
int len_of_parser_func(char *path);
char **String_Parser(char *path);
int is_Correct_Path(char *path, char **words);

void print_len_directories(char *path, char **words);
void print_words(char **words, char *path);

#endif

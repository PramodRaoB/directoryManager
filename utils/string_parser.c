#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long

// Memory optimisation while reading a character string

char *read_string(void) {
  char *arr;
  int len = 0;
  int update = 1;

  arr = (char *)malloc(sizeof(char));
  char ch;
  printf("Enter The Path: \n");
  while (ch != '\n') {
    ch = getc(stdin);
    arr = (char *)realloc(arr, update * sizeof(char));
    arr[len] = ch;
    len++;
    update++;
  }

  arr[len] = '\0';
  return arr;
}

// prints a char string

void print_string(char *arr) {
  int len = strlen(arr);
  len--;
  for (int i = 0; i < len; i++) {
    printf("%c", arr[i]);
  }
  printf("\n");
}

// prints an integer array

void print_arr(int *arr, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

// gives the indices of the '/' position in the path

int *parser_func(char *path) {
  int *indices;
  indices = (int *)malloc(sizeof(int));
  int upd = 1;
  int len = strlen(path);
  len--;
  for (int i = 0; i < len; i++) {
    // ASCII Value of / is 47
    if ((int)path[i] == 47) {
      indices = (int *)realloc(indices, upd * sizeof(int));
      indices[upd - 1] = i;
      upd++;
    }
  }
  upd--;
  return indices;
}

// gives the number of '/'s in a string

int len_of_parser_func(char *path) {
  int *indices;
  indices = (int *)malloc(sizeof(int));
  int upd = 1;
  int len = strlen(path);
  len--;
  for (int i = 0; i < len; i++) {
    if ((int)path[i] == 47) {
      indices = (int *)realloc(indices, upd * sizeof(int));
      indices[upd - 1] = i;
      upd++;
    }
  }
  upd--;
  return upd;
}

// Parses the string taking / as a delimiter and stores all the directory names

char **String_Parser(char *path) {
  char **words;
  int realloc_fac = 1;
  int len = strlen(path);
  len--;
  int no_of_words = len_of_parser_func(path) + 1;
  int *indices;
  indices = parser_func(path);
  words = (char **)malloc(sizeof(char *) * (no_of_words));
  int j = 0;
  indices = (int *)realloc(indices, sizeof(int) * (no_of_words + 1));
  for (int i = no_of_words - 2; i >= 0; i--) {
    indices[i + 1] = indices[i];
  }
  indices[0] = -1;
  indices[no_of_words] = (len);
  int cnt = 0;
  for (int i = 0; i < no_of_words; i++) {
    int size = 0;
    words[i] = (char *)malloc(sizeof(char) * (indices[i + 1] - indices[i] - 1));
    for (int j = indices[i] + 1; j < indices[i + 1]; j++) {
      words[i][size++] = path[j];
    }
    words[i][size] = '\0';
  }
  return words;
}

// Checks if a path follows the structure or not
// Invalid paths are dealt with

int is_Correct_Path(char *path, char **words) {
  int len = strlen(path);
  len--;
  int no_of_words = len_of_parser_func(path) + 1;
  int *indices;
  indices = parser_func(path);
  int j = 0;
  indices = (int *)realloc(indices, sizeof(int) * (no_of_words + 1));
  for (int i = no_of_words - 2; i >= 0; i--) {
    indices[i + 1] = indices[i];
  }
  indices[0] = -1;
  indices[no_of_words] = (len);
  int cnt = 0;
  int flag = 0;
  for (int i = 0; i < no_of_words; i++) {
    if (strlen(words[i]) == 0) {
      flag = 1;
      break;
    }
  }
  return flag;
}

// Prints the the length of the name of each directory/file in a given path

void print_len_directories(char *path, char **words) {
  int len = strlen(path);
  len--;
  int no_of_words = len_of_parser_func(path) + 1;
  int *indices;
  indices = parser_func(path);
  int j = 0;
  indices = (int *)realloc(indices, sizeof(int) * (no_of_words + 1));
  for (int i = no_of_words - 2; i >= 0; i--) {
    indices[i + 1] = indices[i];
  }
  indices[0] = -1;
  indices[no_of_words] = (len);
  int cnt = 0;
  for (int i = 0; i < no_of_words; i++) {
    printf("%ld\n", strlen(words[i]));
  }
}

// prints all the directory names represented by a path

void print_words(char **words, char *path) {
  int len = len_of_parser_func(path) + 1;
  for (int i = 0; i < len; i++) {
    printf("%s\n", words[i]);
  }
}

// to test the functionality

int main() {
  char ch = 'Y';
  while (ch == 'Y') {
    char *path;
    path = read_string();
    String_Parser(path);
    char **final_arr;
    final_arr = String_Parser(path);
    if (is_Correct_Path(path, final_arr)) {
      printf("\nINVALID PATH!!!\n");
      printf("PLEASE ENTER A VALID PATH!!!\n");
      printf("\n");
    } else {
      printf("\nTHE PATH CONTAINS THE FOLLOWING DIRECTORIES/FILES: \n");
      print_words(final_arr, path);
      printf("\n");
    }
    printf("DO U WANT TO CONTINUE?(Y/N)\n");
    char buff;
    scanf("%c%c", &ch, &buff);
  }
}

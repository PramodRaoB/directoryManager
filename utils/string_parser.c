#include "string_parser.h"
#define ll long long

// Memory optimisation while reading a character string
// Uses vector based implememntation
// reallocates memory to 2*size everytime it gets full.
char *read_string(void)
{
    char *arr;
    int len = 0;
    int update = 16;
    char ch;
    int size = 0;

    arr = (char *)malloc(update * sizeof(char));
    // printf("Enter The Path: \n");
    while (ch != '\n')
    {
        ch = getc(stdin);
        size++;
        if (size == update)
        {
            update *= 2;
            //printf("SIZE Currently is: %d\n", size);
            arr = (char *)realloc(arr, update * sizeof(char));
            //printf("New SIZE Currently is: %d\n", update);
        }
        arr[len] = ch;
        len++;
    }

    arr[len] = '\0';
    return arr;
}

// prints a char string given a char array as a parameter
void print_string(char *arr)
{
    int len = strlen(arr);
    len--;
    for (int i = 0; i < len; i++)
    {
        printf("%c", arr[i]);
    }
    printf("\n");
}

// prints an integer array given an integer array and its length as parameters
void print_arr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// gives the indices of the '/' position in the path
// The only parameter for this function is a 1D array which represents the path
int *parser_func(char *path)
{
    int *indices;
    int upd = 1;
    indices = (int *)malloc(upd * sizeof(int));
    int len = strlen(path) - 1;
    int size = 0;
    for (int i = 0; i < len; i++)
    {
        // ASCII Value of / is 47
        if ((int)path[i] == 47)
        {
            indices[size++] = i;
            if (size == upd)
            {
                indices = (int *)realloc(indices, upd * sizeof(int));
                upd *= 2;
            }
        }
    }
    return indices;
}

// gives the number of '/'s in a string
// The only parameter for this function is a 1D array which represents the path
int len_of_parser_func(char *path)
{
    int len = strlen(path) - 1;
    int size = 0;
    for (int i = 0; i < len; i++)
    {
        // ASCII Value of / is 47
        if ((int)path[i] == 47)
        {
            size++;
        }
    }
    return size;
}

// Parses the string taking / as a delimiter and stores all the directory names
// The only parameter for this function is a 1D array which represents the path
char **String_Parser(char *path)
{
    char **words;
    int realloc_fac = 1;
    int len = strlen(path) - 1;
    int no_of_words = len_of_parser_func(path) + 1;
    //printf("%d\n", no_of_words);
    int *indices;
    indices = parser_func(path);
    words = (char **)malloc(sizeof(char *) * (no_of_words + 2));
    int j = 0;
    indices = (int *)realloc(indices, sizeof(int) * (no_of_words + 1));
    for (int i = no_of_words - 2; i >= 0; i--)
    {
        indices[i + 1] = indices[i];
    }
    indices[0] = -1;
    indices[no_of_words] = (len);
    int cnt = 0;
    for (int i = 0; i < no_of_words; i++)
    {
        int size = 0;
        words[i] = (char *)malloc(sizeof(char) * (indices[i + 1] - indices[i] - 1));
        for (int j = indices[i] + 1; j < indices[i + 1]; j++)
        {
            words[i][size++] = path[j];
        }
        words[i][size] = '\0';
    }
    return words;
}

// Checks if a path follows the structure or not
// Invalid paths are dealt with
// Takes a 1D array, path and a 2D array, words. The 2D array, words, has all the files/directory names stored in it
int is_Correct_Path(char *path, char **words)
{
    int no_of_words = len_of_parser_func(path) + 1;
    int len = strlen(path) - 1;
    int flag = 0;
    for (int i = 0; i < no_of_words; i++)
    {
        if (strlen(words[i]) == 0)
        {
            flag = 1;
            break;
        }
    }
    return flag;
}

// Prints the the length of the name of each directory/file in a given path
// Takes the 2D array words and the 1D array path as parameters
void print_len_directories(char *path, char **words)
{
    int no_of_words = len_of_parser_func(path) + 1;
    int len = strlen(path) - 1;
    for (int i = 0; i < no_of_words; i++)
    {
        printf("%ld\n", strlen(words[i]));
    }
}

// prints all the directory names represented by a path
// Takes the 2D array words, and the 1D array path as parameters
void print_words(char **words, char *path)
{
    int len = len_of_parser_func(path) + 1;
    for (int i = 0; i < len; i++)
    {
        printf("%s\n", words[i]);
    }
}


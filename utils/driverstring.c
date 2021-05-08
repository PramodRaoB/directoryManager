// to test the functionality
// Definition of a correct path is taken to be as follows :
// Location1/Location2/Location3....../LocationN
// Note there isnt a / before location 1 for a correct path.
// Any other path that doesnt follow the given structure is going to throw an error message of INVALID PATH.

// final_arr contains all the files/directories names in a path

#include "string_parser.h"
int main()
{
    char ch = 'Y';
    while (ch == 'Y')
    {
        char *path;
        path = read_string();
        String_Parser(path);
        char **final_arr;
        final_arr = String_Parser(path);
        if (is_Correct_Path(path, final_arr))
        {
            printf("\nINVALID PATH!!!\n");
            printf("PLEASE ENTER A VALID PATH!!!\n");
            printf("\n");
        }
        else
        {
            printf("\nTHE PATH CONTAINS THE FOLLOWING DIRECTORIES/FILES: \n");
            print_words(final_arr, path);
            printf("\n");
        }
        printf("DO U WANT TO CONTINUE?(Y/N)\n");
        char buff;
        scanf("%c%c", &ch, &buff);
    }
}

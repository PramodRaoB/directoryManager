// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>
// #include <string.h>
// #include <math.h>
// #include "hash.h"
// #include "../utils/utils.h"

// int main()
// {
//     AliasTableStruct table;
//     table = CreateHash(4);
//     int t;
//     printf("Enter number of tcs: \n");
//     scanf("%d", &t);
//     while (t--)
//     {
//         char arr1[50];
//         char arr2[20];
//         printf("Enter the path and the alias: \n");
//         scanf("%s %s", arr1, arr2);
//         table = InsertPathQP (arr1, arr2, table);
//         int hash = HornerHash(arr2,table->table_size);
//         printf("%s\n%s\n%lld\n%lld\n", table->start[hash].path, table->start[hash].ali,table->num_elems,table->table_size);
//         char *path = FindAlias(arr2, table);
//         printf("%s\n", path);
//     }
// }

// ///////////////////////////////////////////////////////////////////////////////////////////////////////

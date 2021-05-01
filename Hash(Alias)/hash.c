#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <string.h>
#include "hash.h"

/*Create Hash Table Struct*/
AliasTableStruct createhash(int size) {
    AliasTableStruct table;

    table = (AliasTableStruct)malloc(sizeof(struct stHT_alias));
    table->table_size = size;
    table->start = (Alias *)malloc(size * sizeof(Alias));

    for (int i = 0; i < size; i++) {
        strcpy(table->start[i].path, "VALID");
        strcpy(table->start[i].ali, "VALID");
    }

    return table;
}

/*Returns hash value for strings*/
int HornerHash(char arr[20], int size) {
    long long hash = 0;
    int len = strlen(arr);

    for (int i = 0; i < len; i++) {
        hash = (hash * 33 + (int)arr[i]) % (size);
    }

    return hash;
}

/*Insert Path into quadratic probing table, qp = quadratic probing*/
void InsertPathQP(char curr_path[50], char curr_alias[20], Alias qp[], long long size) {
    long long hash = HornerHash(curr_alias, size);
    long long temp = hash, val = 1;

    while (strcmp(qp[hash].path, "VALID") != 0) {
        if (strcmp(qp[hash].ali, curr_alias) == 0) {
            printf("Alias already used.\n");
            char ch, buff;
            printf("Replace existing path with new path?(Y/N)\n");
            scanf("%c%c", &buff, &ch);
            if (ch == 'Y') {
                strcpy(qp[hash].path, curr_path);
                printf("Path for the alias has been updated\n");
                printf("Current Path for the alias '%s' is: %s\n", qp[hash].ali, qp[hash].path);
                return;
            } else {
                printf("Would you like to change the alias for the current path?(Y/N)\n");
                char d, buff2;
                scanf("%c%c", &buff2, &d);
                if (d == 'Y') {
                    char dummy[20];
                    printf("Enter new alias.\n");
                    scanf("%s", dummy);
                    InsertPathQP(curr_path, dummy, qp, size);
                    return;
                } else {
                    return;
                }
            }
        }
        temp = (hash + val * val) % size;
        val++;
    }

    strcpy(qp[hash].path, curr_path);
    strcpy(qp[hash].ali, curr_alias);
}

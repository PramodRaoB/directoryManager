#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <string.h>
#include "hash.h"


struct stHT_alias *createhash(int size)
{
    Alias Table;
    Table = (Alias)malloc(sizeof(struct stHT_alias));
    Table->iTableSize = size;
    Table->start = (struct alias *)malloc(size * sizeof(struct alias));
    for (int i = 0; i < size; i++)
    {
        strcpy(Table->start[i].path, "VALID");
        strcpy(Table->start[i].ali, "VALID");
    }
    return Table;
}


int hornercalc_modiiit(char arr[20], int size)
{
    long long hash = 0;
    int len = strlen(arr);
    for (int i = 0; i < len; i++)
    {
        hash = (hash * 33 + (int)arr[i]) % (size);
    }
    return hash;
}

////////////////////////////////////////////////////////////////////////////////////////
void Insert_path_qp(char arr1[50], char arr2[20], struct alias qp[], long long size)
{
    int len = strlen(arr2);
    long long hash = hornercalc_modiiit(arr2, size);
    long long temp = hash;
    long long val = 1;
    while (strcmp(qp[hash].path, "VALID") != 0)
    {
        if (strcmp(qp[hash].ali, arr2) == 0)
        {
            printf("ALIAS ALREADY USED!!\n");
            char ch, buff;
            printf("DO U WANT TO CHANGE THE PATH FOR THE ALREADY EXISTING ALIAS WITH THE PATH THAT U CURRENTLY GAVE(Y/n)\n");
            scanf("%c%c", &buff, &ch);
            if (ch == 'Y')
            {
                strcpy(qp[hash].path, arr1);
                printf("THE PATH FOR THE ALIAS HAS BEEN UPDATED....\n");
                printf("THE CURRENT PATH FOR THE ALIAS %s is: %s\n", qp[hash].ali, qp[hash].path);
                return;
            }
            else
            {
                printf("DO U WANT TO CHANGE THE ALIAS FOR THE CURRENT PATH(Y/n)\n");
                char d, buff2;
                scanf("%c%c", &buff2, &d);
                if (d == 'Y')
                {
                    char dummy[20];
                    printf("ENTER NEW ALIAS: \n");
                    scanf("%s", dummy);
                    Insert_path_qp(arr1, dummy, qp, size);
                    return;
                }
                else
                {
                    return;
                }
            }
        }
        temp = (hash + val * val) % size;
        val++;
    }
    strcpy(qp[hash].path, arr1);
    strcpy(qp[hash].ali, arr2);
}

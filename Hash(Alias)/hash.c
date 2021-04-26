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

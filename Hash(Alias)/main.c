#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include "hash.h"

int main()
{
    Alias qp;
    qp = createhash(1000);
    int t;
    printf("Enter number of tcs: \n");
    scanf("%d", &t);
    while (t--)
    {
        char arr1[50];
        char arr2[20];
        printf("Enter the path and the alias: \n");
        scanf("%s %s", arr1, arr2);
        Insert_path_qp(arr1, arr2, qp->start, qp->iTableSize);
        int hash = hornercalc_modiiit(arr2,qp->iTableSize);
        printf("%s\n%s\n", qp->start[hash].path, qp->start[hash].ali);
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////

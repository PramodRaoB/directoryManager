#ifndef _HASHTABLE_H_

#define _HASHTABLE_H

typedef long long Element;
typedef long long Key;
typedef struct stHT_alias *Alias;

#define _invalid -5555;


//mini proj

void Insert_path_qp(char arr1[50], char arr2[20], struct alias qp[], long long size);
struct stHT_alias *createhash(int size);
int hornercalc_modiiit(char arr[20], int size);

//////////////////////////////////////////////////////////////////////////////////////

struct stHT_alias
{
    long long iTableSize;
    struct alias *start;
};

struct alias
{
    char path[50];
    char ali[20];
};

#endif

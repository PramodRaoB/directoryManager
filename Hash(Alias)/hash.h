#ifndef _HASHTABLE_H_

#define _HASHTABLE_H_

typedef long long Element;
typedef long long Key;
typedef struct stHT_alias *AliasTableStruct;
typedef struct alias Alias;
#define _invalid -5555;

/*Stores Hashtable size and alias pointer "start"*/
struct stHT_alias {
	long long table_size;
	struct alias *start;
};

/*Alias struct contains a string that stores the absolute path and the Alias, another string*/
struct alias {
	char path[50];
	char ali[20];
};

void InsertPathQP(char arr1[50], char arr2[20], struct alias qp[], long long size);

struct stHT_alias *createhash(int size);

int HornerHash(char arr[20], int size);


#endif

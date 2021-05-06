#ifndef _HASHTABLE_H_

#define _HASHTABLE_H_

typedef struct stHT_alias *AliasTableStruct;
typedef struct alias Alias;
typedef unsigned long long llu;

/*Stores Hashtable size and alias pointer "start"*/
struct stHT_alias
{
	llu table_size;
	llu num_elems;
	struct alias *start;
};

/*Alias struct contains a string that stores the absolute path and the Alias, another string*/
struct alias
{
	char path[50];
	char ali[20];
};

/*Takes the path and the alias and puts them into a hashtable*/
AliasTableStruct InsertPathQP(char arr1[50], char arr2[20], AliasTableStruct table);

/*Creates hashtable*/
AliasTableStruct CreateHash(llu size);

/*Rehashes the table when it reaches 50% of its max capacity*/
AliasTableStruct Rehash(AliasTableStruct Old);

/*Returns key*/
llu HornerHash(char arr[20], llu size);

#endif

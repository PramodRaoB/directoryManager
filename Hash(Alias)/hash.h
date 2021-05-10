#ifndef _HASHTABLE_H_
#define _HASHTABLE_H_

#include "../utils/utils.h"
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include.h"


#define INITIAL_TABLE_SIZE 109
#define MAX_PATH_LENGTH 1001
#define MAX_ALIAS_LENGTH 100
#define MAX_NAME_LENGTH 100

typedef struct stHT_alias *AliasTableStruct;
typedef struct alias Alias;
typedef unsigned long long llu;

/*Stores Hashtable size and alias pointer "start"*/
struct stHT_alias {
	llu table_size;
	llu num_elems;
	struct alias *start;
};

/*Alias struct contains a string that stores the absolute path and the Alias,
 * another string*/
struct alias {
	char path[MAX_PATH_LENGTH];
	char ali[MAX_ALIAS_LENGTH];
};

/*Takes the path and the alias and puts them into a hashtable*/
AliasTableStruct InsertPathQP(char arr1[MAX_PATH_LENGTH],
                              char arr2[MAX_ALIAS_LENGTH],
                              AliasTableStruct table);

/*Creates hashtable*/
AliasTableStruct CreateHash(llu size);

/*Rehashes the table when it reaches 50% of its max capacity*/
AliasTableStruct Rehash(AliasTableStruct Old);

/*Returns key*/
llu HornerHash(char arr[MAX_ALIAS_LENGTH], llu size);

/*Finds the path for a given alias*/
char *FindAlias(char *alias, AliasTableStruct table);

/*Deletes the Hashtable*/
void DeleteAliasTable(AliasTableStruct table);

#endif

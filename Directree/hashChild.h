#ifndef HASH_CHILD_H
#define HASH_CHILD_H

#include "NodeElement.h"

HashTable *initTable(int size);

unsigned int getHash(char *str, int m);
void rehashTable(HashTable *ht);

void insertIntoTable(HashTable *ht, ElementType x);
ElementType findInTable(HashTable *ht, char *node);

#endif

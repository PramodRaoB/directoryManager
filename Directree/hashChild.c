#include "hashChild.h"
#include "../utils/utils.h"
#include "NodeElement.h"
#include <stdlib.h>
#include <string.h>

HashTable *initTable(int size) {
  HashTable *ht = (HashTable *)malloc(sizeof(HashTable));
  ht->tableSize = size;
  ht->table = (ElementType *)malloc(sizeof(ElementType) * size);
  ht->filledSize = 0;

  for (int i = 0; i < size; i++)
    ht->table[i] = NULL;
  return ht;
}

unsigned int getHash(char *str, int m) {
  unsigned long hash = 5381;

  int len = strlen(str);
  for (int i = 0; i < len; i++) {
    char c = str[i];
    hash = (((hash << 5) + hash) + c) % m; /* hash * 33 + c */
  }

  return hash;
}

void rehashTable(HashTable *ht) {
  int newSize = nextPrime(ht->tableSize * 2 + 1);
  int oldSize = ht->tableSize;

  ElementType *newTable = (ElementType *)malloc(newSize * sizeof(ElementType));
  for (int i = 0; i < newSize; i++)
    newTable[i] = NULL;
  ElementType *oldTable = ht->table;

  ht->table = newTable;
  ht->tableSize = newSize;
  ht->filledSize = 0;

  for (int i = 0; i < ht->tableSize; i++) {
    if (oldTable[i]) {
      insertIntoTable(ht, oldTable[i]);
    }
  }

  free(oldTable);
}

void insertIntoTable(HashTable *ht, ElementType x) {
  if (ht->tableSize <= ht->filledSize * 2) {
    rehashTable(ht);
  }

  unsigned int newHash = getHash(x->file->name, ht->tableSize);
  int offset = 0;
  int toAdd = 1;
  while (ht->table[(newHash + offset) % ht->tableSize] != NULL) {
    offset += toAdd;
    toAdd += 2;
  }
  ht->table[(newHash + offset) % ht->tableSize] = x;
}

ElementType findInTable(HashTable *ht, char *nodeName) {
  unsigned int searchHash = getHash(nodeName, ht->tableSize);
  int offset = 0;
  int toAdd = 1;
  while (ht->table[(searchHash + offset) % ht->tableSize] != NULL) {
    char *potential =
        ht->table[(searchHash + offset) % ht->tableSize]->file->name;
    if (strcmp(potential, nodeName) == 0) {
      return ht->table[(searchHash + offset) % ht->tableSize];
    }
    offset += toAdd;
    toAdd += 2;
  }
  return NULL;
}

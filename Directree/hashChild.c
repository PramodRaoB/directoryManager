#include "hashChild.h"
#include "../utils/utils.h"
#include "NodeElement.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>

/*
 * Returns an "initialized" hashtable
 * Allocates memory for the hashtable container and the actual table
 * then sets all the table entries to NULL
 */

HashTable *initTable(int size) {
  // mallocs
  HashTable *ht = (HashTable *)malloc(sizeof(HashTable));
  assert(ht != NULL);
  ht->table = (ElementType *)malloc(sizeof(ElementType) * size);
  assert(ht->table != NULL);

  // assignments
  ht->tableSize = size;
  ht->filledSize = 0;

  for (int i = 0; i < size; i++)
    ht->table[i] = NULL;

  return ht;
}

/*
 * Returns the hash value of a given string
 * Uses the djb2 hash function
 * */
unsigned int getHash(char *str, int m) {
  unsigned long hash = 5381;

  int len = strlen(str);
  for (int i = 0; i < len; i++) {
    char c = str[i];
    hash = (((hash << 5) + hash) + c) % m; /* hash * 33 + c */
  }

  return hash;
}

/*
 * Increases the capacity of hashtable to the smallest prime number greater than
 * twice the current capacity
 * Allocates memory and then inserts elements from old table into new
 * */
void rehashTable(HashTable *ht) {
  int newSize = nextPrime(ht->tableSize * 2 + 1);
  int oldSize = ht->tableSize;
  ElementType *oldTable = ht->table;

  ElementType *newTable = (ElementType *)malloc(newSize * sizeof(ElementType));
  assert(newTable != NULL);
  for (int i = 0; i < newSize; i++)
    newTable[i] = NULL;

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

/*
 * Inserts given node pointer into hashtable
 * if load factor of table is >= 0.5, rehashes the table
 * Uses quadratic probing for insertion
 * */

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

/*
 * Given a string, returns pointer to node if it exists in the hashtable
 * returns NULL if not found
 * */
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

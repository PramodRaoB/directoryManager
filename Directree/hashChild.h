#ifndef HASH_CHILD_H
#define HASH_CHILD_H

#include "NodeElement.h"

/*
 * Returns an "initialized" hashtable
 * Allocates memory for the hashtable container and the actual table
 * then sets all the table entries to NULL
 */
HashTable *initTable(int size);

/*
 * Returns the hash value of a given string
 * Uses the djb2 hash function
 * */
unsigned int getHash(char *str, int m);

/*
 * Increases the capacity of hashtable to the smallest prime number greater than
 * twice the current capacity
 * Allocates memory and then inserts elements from old table into new
 * */
void rehashTable(HashTable *ht);

/*
 * Inserts given node pointer into hashtable
 * if load factor of table is >= 0.5, rehashes the table
 * Uses quadratic probing for insertion
 * */
void insertIntoTable(HashTable *ht, ElementType x);

/*
 * Given a string, returns pointer to node if it exists in the hashtable
 * returns NULL if not found
 * */
ElementType findInTable(HashTable *ht, char *node);

#endif

#ifndef NODE_ELEMENT_H
#define NODE_ELEMENT_H

#define NAME_SIZE 100

#include "trie.h"
#include <stdbool.h>

typedef struct treenode TreeNode;
typedef struct filedetails FileDetails;
typedef struct hashTable HashTable;

struct treenode {
  FileDetails *file;

  TreeNode *first_child;
  TreeNode *next;
  TreeNode *current;
  TreeNode *parent;

  HashTable *ht;
  Trie childTrie;
};

struct filedetails {
  char *name;
  bool is_file;
};

struct hashTable {
  int tableSize;
  int filledSize;
  TreeNode **table;

  // function pointers
};
#endif

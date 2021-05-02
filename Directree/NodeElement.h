#ifndef NODE_ELEMENT_H
#define NODE_ELEMENT_H

#define NAME_SIZE 5
#include <stdbool.h>

typedef struct treenode TreeNode;

struct treenode {
  char name[NAME_SIZE];
  bool is_file;
  unsigned int hash;

  TreeNode *firstchild;
  TreeNode *next;
  TreeNode *current;
  TreeNode *parent;
};

#endif

#ifndef NODE_ELEMENT_H
#define NODE_ELEMENT_H

#define NAME_SIZE 64

#include <stdbool.h>

typedef struct treenode TreeNode;
typedef struct filedetails FileDetails;

struct treenode {
  FileDetails *file;

  TreeNode *first_child;
  TreeNode *next;
  TreeNode *current;
  TreeNode *parent;
};

struct filedetails {
  char *name;
  bool is_file;
};
#endif

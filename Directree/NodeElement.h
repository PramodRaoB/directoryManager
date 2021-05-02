#ifndef NODE_ELEMENT_H
#define NODE_ELEMENT_H

#define NAME_SIZE 5

typedef struct treenode TreeNode;

struct treenode {
  char name[NAME_SIZE];
  bool is_file;
  TreeNode *firstchild;
  TreeNode *next;
  TreeNode *current;
  TreeNode *parent;
};

#endif

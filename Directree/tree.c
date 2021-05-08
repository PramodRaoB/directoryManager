#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hashChild.h"
#include "tree.h"

#define ll long long int

TreeNode *init_node(char *name, bool is_file, TreeNode *parent) {
  int name_length = strlen(name) + 1;

  // Mallocs
  TreeNode *new_node;
  new_node = (TreeNode *)malloc(sizeof(TreeNode));
  assert(new_node != NULL);
  new_node->file = (FileDetails *)malloc(sizeof(FileDetails));
  assert(new_node->file != NULL);
  new_node->file->name = (char *)malloc(name_length * sizeof(char));
  assert(new_node->file->name != NULL);

  if (!is_file)
    new_node->ht = initTable(1009);
  else
    new_node->ht = NULL;

  // Assignments
  new_node->file->is_file = is_file;
  strcpy(new_node->file->name, name);

  new_node->first_child = NULL;
  new_node->next = NULL;
  new_node->current = new_node;
  new_node->parent = parent;

  return new_node;
}

void add_node(TreeNode *parent, char *name, bool is_file) {
  // Change for array implementation
  TreeNode *new_node = init_node(name, is_file, parent);
  insertIntoTable(parent->ht, new_node);
  /*useless*/ add_at_start(new_node, parent);
}

void add_at_start(TreeNode *newNode, TreeNode *parent) {
  newNode->next = parent->first_child;
  parent->first_child = newNode;
}

void delete_tree(TreeNode *root) {
  // End of children list
  if (root == NULL) {
    return;
  }

  TreeNode *temp = root->first_child;
  TreeNode *temp_next;

  // Iterates through each child and deletes subdirectories recursively
  while (temp) {
    temp_next = temp->next;
    delete_tree(temp);
    temp = temp_next;
  }

  // The root is either a file or an empty directory
  free(root->file->name);
  free(root->file);
  free(root->ht->table);
  free(root->ht);
  free(root);
  root = NULL;
  return;
}

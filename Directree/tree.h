#ifndef __TREE_H__
#define __TREE_H__

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "NodeElement.h"

/*
 * Creates an empty directree with one node named "root"
 * */
TreeNode *init_tree();

/*
 * Inputs: File name, isFIle, address of the parent node
 * mallocs and initialises all properties of the node
 * returns pointer to the created node

 * Call this function with parent = NULL to create an empty tree
 * */
TreeNode *init_node(char *name, bool is_file, TreeNode *parent);

/*
 * **Call this function to add anything to the tree**
 * **Part of the ADD function**

 * Takes argument pointer to parent node
 * (Must be a directory. The file gets inserted here)
 * Takes new node name and is_file as arguments
*/
void add_node(TreeNode *parent, char *name, bool is_file);

/*
 * Takes args: Node to be added and parent node
 * adds the node at beginning of child linked list
 * (called by add_node function)
 * */
void add_at_start(TreeNode *newNode, TreeNode *parent);

// Given the absolute path of a file/dir, the function returns the pointer to
// that file/dir
TreeNode *traversal(char *path, TreeNode *root);

/*
 * Takes arg: pointer to current directory
 * 8 Prints all the contents present in the current directory
 * Returns number of files in the directory
 * */
int print_contents(TreeNode *current);

/*
 * Takes current node and returns full path to it
 * */
char *get_path(TreeNode *current);

/*
 * Gets path by calling get_path and prints path to current node
 * */
void print_current_path(TreeNode *current);

/*
 * Takes in pointer to the root node and deletes the whole tree after
 * */
void delete_tree(TreeNode *root);

/*
 * Prints the tree from given node in an aesthetically pleasing way
 * */
void dfsTree(TreeNode *curr, int numSpaces);

#endif

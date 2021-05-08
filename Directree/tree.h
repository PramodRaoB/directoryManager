#ifndef __TREE_H__
#define __TREE_H__

#include <stdbool.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "NodeElement.h"

/*
 * Inputs: File name, isFIle, address of the parent node
 * mallocs and initialises all properties of the node
 * returns pointer to the created node

 * Call this function with parent = NULL to create an empty tree
 * */
TreeNode *init_node(char *name, bool is_file, TreeNode *parent);

/*
**Call this function to add anything to the tree**
**Part of the ADD function**

Takes argument pointer to parent node
(Must be a directory. The file gets inserted here)
Takes new node name and is_file as arguments
*/
void add_node(TreeNode *parent, char *name, bool is_file);

/*
Takes args: Node to be added and parent node
adds the node at beginning of child linked list
(called by add_node function)
(useless in array implementation)
*/
void add_at_start(TreeNode *newNode, TreeNode *parent);


void delete_tree(TreeNode *root);

//Given the absolute path of a file/dir, the function returns the pointer to that file/dir
ElementType traversal(char *path, ElementType root);

/*
 * Takes arg: pointer to current directory
 * 8 Prints all the contents present in the current directory
 * Returns number of files in the directory
 * */
int print_contents(ElementType current);

#endif

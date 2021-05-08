#ifndef __DIRECTORYMANAGER_H__
#define __DIRECTORYMANAGER_H__

#include "include.h"
/*
 * Adds given file/folder into current directory
 * Takes file name, type and current directory as parameters
 * Calls the add_node function on current directory
 * */
void ADD(char *fileName, bool isFile, TreeNode *currentDir);

/*
 * MOVE function takes in the pointer to the directory from which the path is given
 * It scans for a path input
 * returns pointer to the end of path if valid
 * Else returns root
 * */
TreeNode *MOVE(TreeNode *root);

/*
 * ALIAS function takes in the Alias table and root of the tree.
 * We scan for the path and the alias and check if the path is a correct path by using traversal function.
 * Insert the path and the alias in the Alias Hashtable.
 * */
void ALIAS(AliasTableStruct table, TreeNode *root);

TreeNode *TELEPORT(AliasTableStruct table, TreeNode *root);

void FIND();

void QUIT();

#endif

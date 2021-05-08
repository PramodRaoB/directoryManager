#ifndef __DIRECTORYMANAGER_H__
#define __DIRECTORYMANAGER_H__

#include "include.h"

/*
 * Prints a welcome message
 * */
void STARTUP();
/*
 * Adds given file/folder into current directory
 * It then takes inputs from the user for the name and type of node to be added
 * Calls the add_node function on current directory with the given details
 * */
void ADD(TreeNode *currentDir);

/*
 * MOVE function takes in the pointer to the directory from which the path is
 * given It scans for a path input returns pointer to the end of path if valid
 * Else returns root
 * */
TreeNode *MOVE(TreeNode *root);

/*
 * ALIAS function takes in the Alias table and root of the tree.
 * We scan for the path and the alias and check if the path is a correct path by
 * using traversal function. Insert the path and the alias in the Alias
 * Hashtable.
 * */
void ALIAS(AliasTableStruct table, TreeNode *root);

TreeNode *TELEPORT(AliasTableStruct table, TreeNode *root);

void FIND(TreeNode *currentDir);

void HELP();

void QUIT();

#endif

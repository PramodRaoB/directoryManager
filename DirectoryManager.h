#ifndef __DIRECTORYMANAGER_H__
#define __DIRECTORYMANAGER_H__

#include "include.h"

/*
 * Prints a welcome message
 * and a basic description of the program
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
TreeNode *MOVE(TreeNode *root, TreeNode *current);

/*
 * ALIAS function takes in the Alias table and root of the tree.
 * We scan for the path and the alias and check if the path is a correct path by
 * using traversal function. Insert the path and the alias in the Alias
 * Hashtable.
 * */
AliasTableStruct ALIAS(AliasTableStruct table, TreeNode *root);

/*
 * TELEPORT function takes in the Alias table and root of the tree.
 * It scans for the alias and moves the root to the location
 * pointed by the alias
 * */
TreeNode *TELEPORT(AliasTableStruct table, TreeNode *root);

/*
 * Takes the pointer to current directory
 * Takes user input for the prefix to be searched
 * Uses a trie data structure to print all files in the current directory
 * starting with the prefix
 * */
void FIND(TreeNode *currentDir);

/*
 * Prints a help message containing a short description of the cli commands,
 * their usage and examples
 * */
void HELP();

/*
 * Frees all remaining heap blocks and exits the program
 * */
void QUIT(TreeNode *root, AliasTableStruct alias_table);

#endif

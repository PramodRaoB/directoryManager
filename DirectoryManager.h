#ifndef __DIRECTORYMANAGER_H__
#define __DIRECTORYMANAGER_H__

#include "include.h"
/*
 * Adds given file/folder into current directory
 * Takes file name, type and current directory as parameters
 * Calls the add_node function on current directory
 * */
void ADD(char *fileName, bool isFile, TreeNode *currentDir);

ElementType MOVE(ElementType root);

void ALIAS(AliasTableStruct table, ElementType root);

ElementType TELEPORT(AliasTableStruct table, ElementType root);

void FIND();

void QUIT();

#endif

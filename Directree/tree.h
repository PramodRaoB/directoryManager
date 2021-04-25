#ifndef __TREE_H__
#define __TREE_H__
#define NAME_SIZE 5
#include <stdbool.h>
#include <stdio.h>


typedef struct treenode TreeNode;

struct treenode{
    char name[NAME_SIZE];
    bool isFile;
    TreeNode* firstchild;
  	TreeNode* next;
  	TreeNode* current;
  	TreeNode* parent;
};

/* 
Inputs: File name, isFIle, address of the parent node
mallocs and initialises all properties of the node
returns pointer to the created node
*/
TreeNode* initNode(char* name, bool isFile, TreeNode* parent);

/*
Part of the ADD function
Takes argument pointer to parent node

Reads user input, calls initnode, adds node as a child to the parent node
*/
void addNode(TreeNode*parent);

// takes a character aray and returns pointer to the treenode at the destination
TreeNode* move(char* destination);

void getInputDirectory();

// traverse tree, add node
TreeNode* traverseTree();

/*
Takes args: char array, isfile
reads and copies inputs to the args
*/
void getInputData(char* name, bool* isFile);

/*
Takes args: Node to be added and parent node
adds the node at beginning of child linked list
(useless in array implementation)
*/
void addAtStart(TreeNode* newNode, TreeNode* parent);

#endif


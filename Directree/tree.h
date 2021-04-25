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

// takes input, calls initnode, adds node to correct location
void addNode(TreeNode*parent);

// takes a character aray and returns pointer to the treenode at the location
TreeNode* move(char* location);

void getInputDirectory();

// traverse tree, add node
TreeNode* traverseTree();

// takes input: name, isfile, reads and copies inputs
void getInputData(char* name, bool* isFile);

// adds at beginning of sibling linked list (useless in array implementation)
void addAtStart(TreeNode* newNode, TreeNode* Parent);

#endif


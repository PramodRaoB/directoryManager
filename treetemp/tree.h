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

//creates and initialises all properties of the node
TreeNode* initNode(char* name, bool isFile, TreeNode* parents);

//takes input, calls initnode, adds node to correct location
void addNode(TreeNode*parent);

// takes a character aray and returns pointer to the treenode at the location
TreeNode* move(char* location);


//traverse tree, add node
TreeNode* traverseTree();

//takes input: name, isfile
void getInputData(char* name, bool* isFile);

//adds at beginning of sibling linked list (useless in array implementation)
void addAtStart(TreeNode* newNode, TreeNode* Parent);

void getInputDirectory();
#endif


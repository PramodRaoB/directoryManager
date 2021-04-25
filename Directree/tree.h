#ifndef __TREE_H__
#define __TREE_H__
#define NAME_SIZE 5
#include <stdbool.h>
#include <stdio.h>


typedef struct treenode TreeNode;

struct treenode{
    char name[NAME_SIZE];
    bool is_file;
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
TreeNode* init_node(char* name, bool is_file, TreeNode* parent);

/*
Part of the ADD function
Takes argument pointer to parent node

Reads user input, calls initnode, adds node as a child to the parent node
*/
void add_node(TreeNode*parent);

// takes a character aray and returns pointer to the treenode at the destination
TreeNode* move(char* destination);

void get_input_directory();

// traverse tree, add node
TreeNode* traverse_tree();

/*
Takes args: char array, isfile
reads and copies inputs to the args
*/
void get_input_data(char* name, bool* is_file);

/*
Takes args: Node to be added and parent node
adds the node at beginning of child linked list
(useless in array implementation)
*/
void add_at_start(TreeNode* newNode, TreeNode* parent);

#endif


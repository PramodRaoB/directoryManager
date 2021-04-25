//.c file
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
#include<stdbool.h>
#include<string.h>
#include<assert.h>
#include<ctype.h>

#include"tree.h"

#define ll long long int

TreeNode* init_node(char* name, bool is_file, TreeNode* parent){

    TreeNode* NewNode;
    NewNode =(TreeNode*)malloc(sizeof(TreeNode));
    assert(NewNode != NULL);

    NewNode->is_file = is_file;
    NewNode->firstchild = NULL;
    NewNode->next = NULL;
    NewNode->current = NewNode;
    NewNode->parent = parent;
    strcpy(NewNode->name, name);

    return NewNode;
}

void add_at_start(TreeNode* newNode, TreeNode* parent){
    if(parent->firstchild){
        newNode->next = parent->firstchild->next;
        parent->firstchild->next = newNode;
    }
    else{
        parent->firstchild = newNode;
    }
}

void add_node(TreeNode* parent){
    char name[NAME_SIZE];
    bool is_file;
    
    get_input_data(name, &is_file);
    TreeNode* newNode = init_node(name, is_file, parent);
    /*useless*/add_at_start(newNode, parent);
}

void get_input_data(char* name, bool* is_file){
    scanf("%s", name);
    scanf("%d", is_file);
}





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

TreeNode* initNode(char* name, bool isFile, TreeNode* parent){

    TreeNode* NewNode;
    NewNode =(TreeNode*)malloc(sizeof(TreeNode));
    assert(NewNode != NULL);

    NewNode->isFile = isFile;
    NewNode->firstchild = NULL;
    NewNode->next = NULL;
    NewNode->current = NewNode;
    NewNode->parent = parent;
    strcpy(NewNode->name, name);

    return NewNode;
}

void addAtStart(TreeNode* newNode, TreeNode* parent){
     if(parent->firstchild){
        newNode->next = parent->firstchild->next;
        parent->firstchild->next = newNode;
    }
    else{
        parent->firstchild = newNode;
    }
}

void addNode(TreeNode* parent){
    char name[50];
    bool isFile;
    
    getInputData(name, &isFile);
    TreeNode* newNode = initNode(name, isFile, parent);
    /*useless*/addAtStart(newNode, parent);
}

void getInputData(char* name, bool* isFile){
    scanf("%s", name);
    scanf("%d", isFile);
}




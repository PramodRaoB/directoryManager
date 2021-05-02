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
    int name_length = strlen(name);

    // Mallocs
    TreeNode* new_node;
    new_node =(TreeNode*)malloc(sizeof(TreeNode));
    assert(new_node != NULL);
    new_node->file = (FileDetails*)malloc(sizeof(FileDetails));
    new_node->file->name = (char*)malloc(name_length*sizeof(char));
    assert(new_node->file!=NULL);
    assert(new_node->file->name!=NULL);

    // Assignments
    new_node->file->is_file = is_file;
    strcpy(new_node->file->name, name);
    
    new_node->first_child = NULL;
    new_node->next = NULL;
    new_node->current = new_node;
    new_node->parent = parent;

    return new_node;
}

void add_at_start(TreeNode* newNode, TreeNode* parent){
    if(parent->first_child){
        newNode->next = parent->first_child->next;
        parent->first_child->next = newNode;
    }
    else{
        parent->first_child = newNode;
    }
}

void add_node(TreeNode* parent){
    char name[NAME_SIZE];
    bool is_file;
    
    get_input_data(name, &is_file);

    // Change for array implementation
    TreeNode* new_node = init_node(name, is_file, parent);
    /*useless*/add_at_start(new_node, parent);
}

void get_input_data(char* name, bool* is_file){
    scanf("%s", name);
    scanf("%d", &is_file);
}

void delete_tree(TreeNode* root){
    // End of children list
    if(root == NULL){
        return;
    }

    TreeNode* temp = root->first_child;
    TreeNode* temp_next;

    // Iterates through each child and deletes subdirectories recursively
    while(temp){
        temp_next = temp->next;
        delete_tree(temp);
        temp = temp_next;
    }

    // The root is either a file or an empty directory
    free(root->file->name);
    free(root);
    root = NULL;
    return;

}


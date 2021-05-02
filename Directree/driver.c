#include <stdio.h>
#include "tree.h"

int main(){
    TreeNode* root = init_node("root", 0, NULL);
    TreeNode* current = root;

    print_contents(root);
    // essentially the add_node function but without taking user inputs
    TreeNode* new_node = init_node("hello", 1, current);
    add_at_start(new_node, current);
    print_contents(root);

    new_node = init_node("lalala", 0, current);
    add_at_start(new_node, current);
    print_contents(root);

    current = new_node;

    new_node = init_node("secondlayer",0, current);
    add_at_start(new_node, current);
    print_contents(current);
    
    delete_tree(root);
}
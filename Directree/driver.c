// #include "NodeElement.h"
// #include "hashChild.h"
// #include "tree.h"
// #include <stdio.h>
// #include <stdlib.h>

// /*
// Takes args: char array, isfile
// reads and copies inputs to the args
// */
// void get_input_data(char *name, bool *is_file) {
//   scanf("%s", name);
//   scanf("%d", is_file);
// }

// /*
// Takes arg: pointer to current directory
// Prints all the contents present in the current directory
// */

// int main() {
//   TreeNode *root = init_node("root", 0, NULL);
//   TreeNode *current = root;

//   print_contents(root);
//   // essentially the add_node function but without taking user inputs
//   add_node(current, "hello", 0);
//   print_contents(current);

//   add_node(current, "hi", 0);
//   print_contents(current);

//   TreeNode *temp = findInTable(current->ht, "hello");
//   if (temp)
//     printf("found\n");
//   else
//     printf("no\n");
//   temp = findInTable(current->ht, "h");
//   if (temp)
//     printf("found\n");
//   else
//     printf("no\n");

//   add_node(current, "how", 0);
//   temp = findInTable(current->ht, "how");
//   if (temp)
//     printf("found\n");
//   else
//     printf("no\n");
//   temp = findInTable(current->ht, "howw");
//   if (temp)
//     printf("found\n");
//   else
//     printf("no\n");
//   print_contents(current);

//   current = current->first_child;

//   add_node(current, "second layer", 0);
//   temp = findInTable(current->ht, "hi");
//   if (temp)
//     printf("found\n");
//   else
//     printf("no\n");
//   temp = findInTable(current->ht, "second layr");
//   if (temp)
//     printf("found\n");
//   else
//     printf("no\n");
//   temp = findInTable(current->ht, "second layer");
//   if (temp)
//     printf("found\n");
//   else
//     printf("no\n");
//   print_contents(current);

//   delete_tree(root);
// }

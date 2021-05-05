#include "tree.h"
#include <stdio.h>

/*
Takes args: char array, isfile
reads and copies inputs to the args
*/
void get_input_data(char *name, bool *is_file) {
  scanf("%s", name);
  scanf("%d", is_file);
}

/*
Takes arg: pointer to current directory
Prints all the contents present in the current directory
*/
void print_contents(TreeNode *current) {
  TreeNode *temp = current->first_child;
  int count = 0;

  while (temp) {
    count++;
    // printf("%d. ", count);
    // count++;
    if (temp->file->is_file) {
      printf("File:\t");
    } else
      printf("Folder:\t");

    printf("%s\n", temp->file->name);
    temp = temp->next;
  }
  printf("%d item(s) in directory %s\n\n", count, current->file->name);
}

int main() {
  TreeNode *root = init_node("root", 0, NULL);
  TreeNode *current = root;

  print_contents(root);
  // essentially the add_node function but without taking user inputs
  add_node(current, "hello", 0);
  print_contents(current);

  add_node(current, "hi", 0);
  print_contents(current);

  add_node(current, "how", 0);
  print_contents(current);

  current = current->first_child;

  add_node(current, "second layer", 0);
  print_contents(current);

  delete_tree(root);
}

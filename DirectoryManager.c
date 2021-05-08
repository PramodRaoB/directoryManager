#include "DirectoryManager.h"

void ADD(char *fileName, bool isFile, TreeNode *currentDir) {
  add_node(currentDir, fileName, isFile);
}

ElementType MOVE(ElementType root){
  char *input_string;
  ElementType current;

  input_string = read_string();

  current = traversal(input_string, root);

    /*error*/
    /*Returning NULL if path found wrong*/
  if(current == NULL){

    // no changes to the input root
    printf("INVALID PATH!\n\n");
    return root;
  }

  /*The given path leads to a file*/
  if(current->file->is_file){
    // no changes to the input root
    printf("GIVEN PATH LEADS TO A FILE\n");
    printf("COULD NOT MOVE TO THE LOCATION\n\n");
    return root;
  }

  return current;

}

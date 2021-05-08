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
/*
  ALIAS function takes in the Alias table and root of the tree.
  We scan for the path and the alias and check if the path is a correct path by using traversal function.
  Insert the path and the alias in the Alias Hashtable.
*/
void ALIAS(AliasTableStruct table, ElementType root)
{
  char path[50];
  char alias[20];
  scanf("%s %s",path,alias);
  ElementType Node;
  Node= traversal(path,root);
  if(Node!=NULL)
  {
    table= InsertPathQP(path,alias,table);
    return;
  }
  printf("Invalid Path");

}

ElementType TELEPORT(AliasTableStruct table, ElementType root)
{
  char alias[20];
  scanf("%s",alias);
  char *path=FindAlias(alias,table);
  
  ElementType current;

  current = traversal(path, root);

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

void FIND()
{

}

void QUIT()
{

}
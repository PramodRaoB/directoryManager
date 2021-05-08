#include "DirectoryManager.h"

void ADD(char *fileName, bool isFile, TreeNode *currentDir)
{
  add_node(currentDir, fileName, isFile);
}

TreeNode *MOVE(TreeNode *root)
{
  char *input_string;
  TreeNode *current;

  input_string = read_string();

  current = traversal(input_string, root);

  /*error*/
  /*Returning NULL if path is wrong*/
  if (current == NULL)
  {
    // no changes to the input root
    printf("INVALID PATH!\n\n");
    return root;
  }

  /*The given path leads to a file*/
  if (current->file->is_file)
  {
    // no changes to the input root
    printf("GIVEN PATH LEADS TO A FILE\n");
    printf("COULD NOT MOVE TO THE LOCATION\n\n");
    return root;
  }

  return current;
}

void ALIAS(AliasTableStruct table, TreeNode *root)
{
  char path[MAX_PATH_LENGTH];
  char alias[MAX_ALIAS_LENGTH];
  scanf("%s %s", path, alias);
  TreeNode *Node;
  Node = traversal(path, root);

  if (Node != NULL&& Node->file->is_file !=1)
  {
    
    table = InsertPathQP(path, alias, table);
    /*
    if (Node->file->is_file)
    {
      printf("Note: %s is a file\n", Node->file->name);
    }
    else
    {
      printf("Note: %s is a directory\n", Node->file->name);
    }
    */
    return;
  }
  else if(Node!=NULL)
  {
    printf("Error: %s is a file\n", Node->file->name);
  }
  else
  printf("Error: Invalid Path");
}

TreeNode *TELEPORT(AliasTableStruct table, TreeNode *root)
{
  char alias[MAX_ALIAS_LENGTH];
  scanf("%s", alias);
  char *path = FindAlias(alias, table);

  TreeNode *current;

  current = traversal(path, root);

  /*error*/
  /*Returning NULL if path found wrong*/
  if (current == NULL)
  {

    // no changes to the input root
    printf("INVALID PATH!\n\n");
    return root;
  }

  /*The given path leads to a file*/
  if (current->file->is_file)
  {
    printf("Alias retrieved to file: %s\n", current->file->name);
  }
  else
  {
    printf("Alias retrieved to directory: %s\n", current->file->name);
  }

  return current;
}

void FIND()
{
}

void QUIT()
{
}
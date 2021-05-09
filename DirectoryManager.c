#include "DirectoryManager.h"

void STARTUP() {}
void ADD(TreeNode *currentDir) {
  char fileName[MAX_NAME_LENGTH];
  char typeChoice[10];
  bool isFile;
  scanf("%s %s", fileName, typeChoice);
  if (strcasecmp(typeChoice, "FILE") == 0)
    isFile = true;
  else if (strcasecmp(typeChoice, "FOLDER") == 0)
    isFile = false;
  else {
    printf("Error: Invalid type\n(Valid types: \"FILE\", \"FOLDER\")\nNote: "
           "File/Folder name cannot contain spaces.");
    return;
  }
  add_node(currentDir, fileName, isFile);
}

TreeNode *MOVE(TreeNode *root, TreeNode *current) {
  char *input_string;
  TreeNode *temp;

  input_string = read_string();
  if (input_string[0] == 0) {
    printf("Error: Invalid path\n\n");
    return current;
  }
  temp = traversal(input_string, root);
  free(input_string);
  /*error*/
  /*Returning NULL if path is wrong*/
  if (temp == NULL) {
    // no changes to the input root
    printf("Error: Invalid path\n\n");
    return current;
  }

  /*The given path leads to a file*/
  if (temp->file->is_file) {
    // no changes to the input root
    printf("Error: Given path leads to a file, move was unsuccessful\n");
    return current;
  }

  // printf("Move successful\n");
  return temp;
}

AliasTableStruct ALIAS(AliasTableStruct table, TreeNode *root) {
  char path[MAX_PATH_LENGTH];
  char alias[MAX_ALIAS_LENGTH];
  scanf("%s %s", path, alias);
  TreeNode *Node;
  Node = traversal(path, root);

  // printf("booo");
  if (Node != NULL && Node->file->is_file != 1) {

    table = InsertPathQP(path, alias, table);
    return table;
  } else if (Node != NULL) {
    printf("Error: %s is a file\n", Node->file->name);
  } else
    printf("Error: Invalid Path");

  return table;
}

TreeNode *TELEPORT(AliasTableStruct table, TreeNode *root) {
  char alias[MAX_ALIAS_LENGTH];
  scanf("%s", alias);
  char *path = FindAlias(alias, table);

  TreeNode *current;

  current = traversal(path, root);

  /*error*/
  /*Returning NULL if path found wrong*/
  if (current == NULL) {
    // no changes to the input root
    printf("Error: Invalid path\n");
    return root;
  }

  return current;
}

void FIND(TreeNode *currentDir) {
  //printf("Enter prefix string: ");

  char *prefixStr = read_string();
  if(prefixStr[0]=='\0')
  {
    printf("Error: No prefix string found\n");
    return ;
  }
  printf("The following files/folders in the current directory contain prefix "
         "%s:\n\n",
         prefixStr);
  printTrieWithPrefix(currentDir->childTrie, prefixStr);
  free(prefixStr);
}

void HELP() {}

void QUIT(TreeNode *root, AliasTableStruct alias_table) {
  delete_tree(root);
  DeleteAliasTable(alias_table);

  exit(0);
}

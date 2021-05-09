#include "DirectoryManager.h"

void STARTUP() {
  printf("==============================================================\n");
  printf("\t\tDirectory management program\n");
  printf("Major functions: 'add', 'move', 'alias', 'teleport', 'find'\n");
  printf("Enter 'help' for a full list of commands and usage\n");
  printf("Enter 'quit' to terminate the program\n");
  printf("==============================================================\n");
}

void ADD(TreeNode *currentDir) {
  char fileName[MAX_NAME_LENGTH];
  char typeChoice[10];
  bool isFile;
  scanf("%s %s", fileName, typeChoice);
  
  int name_size = strlen(fileName);
  for(int i = 0;i < name_size; i++){
    if(fileName[i] < 'a' || fileName[i] > 'z'){
      printf("Error: Name expected in all lowercase\n");
      printf("Nothing was added\n");
      return;
    }
  }
  if (strcasecmp(typeChoice, "FILE") == 0)
    isFile = true;
  else if (strcasecmp(typeChoice, "FOLDER") == 0)
    isFile = false;
  else {
    printf("Error: Invalid type (Valid types: \"file\", \"folder\")\n"
           "Note: File/Folder name cannot contain spaces\n");
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
  if (prefixStr[0] == '\0') {
    printf("Error: No prefix string found\n");
    return ;
  }
  printf("The following files/folders in the current directory contain prefix "
         "%s:\n\n",
         prefixStr);
  printTrieWithPrefix(currentDir->childTrie, prefixStr);
  free(prefixStr);
}

void HELP() {
  printf("\nList of available commands and basic usage:\n\n");
  printf("add\t\tAdd file/directory inside current directory (only lowercase names)\n");
  printf("\t\tUsage: add <name> <type>\n\n");
  printf("move\t\tChange current directory to any directory by taking input the complete path to that directory\n");
  printf("\t\tUsage: move <path>\n\n");
  printf("alias\t\tTakes input the complete path to that directory and the alias\n");
  printf("\t\tUsage: alias <path> <aliasforpath>\n\n");
  printf("teleport\tChange the current directory to any directory by taking input the alias of that directory\n");
  printf("\t\tUsage: teleport <aliasforpath>\n\n");
  printf("find\t\tSearch for all the files/directories with given prefix inside current directory\n");
  printf("\t\tUsage: find <prefix>\n\n");
  printf("ls\t\tPrints all the files/folders in the current directory\n");
  printf("\t\tUsage: ls\n\n");
  printf("cd\t\tChange current directory to any directory inside the current directory by taking input the\n\t\t\
relative path that starts with the name of the current directory\n");
  printf("\t\tUsage: cd <path>\n\n");
  printf("quit\t\tTerminates the program\n");
  printf("\t\tUsage: quit\n\n");
}

void QUIT(TreeNode *root, AliasTableStruct alias_table) {
  delete_tree(root);
  DeleteAliasTable(alias_table);

  exit(0);
}

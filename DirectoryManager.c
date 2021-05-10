// #include "DirectoryManager.h"
#include"include.h"
void STARTUP() {

    blue();
    printf("\t\t     _____________________________________________________________\n");
    purple();
    printf("\t\t                      Directory Management Program               \n");
    blue();
    printf("\t\t      Major functions: 'add', 'move', 'alias', 'teleport', 'find'\n");
    printf("\t\t      Enter 'help' for a full list of commands and usage         \n");
    printf("\t\t      Enter 'quit' to terminate the program                      \n");
    printf("\t\t     _____________________________________________________________\n\n");
    reset();

    blue();
    printf("______________________________________________________________\n");
    printf("\t\tDirectory Management Program\n");
    printf("Major functions: 'add', 'move', 'alias', 'teleport', 'find'\n");
    printf("Enter 'help' for a full list of commands and usage\n");
    printf("Enter 'quit' to terminate the program\n");
    printf("______________________________________________________________\n\n");
    reset();

}

void ADD(TreeNode *currentDir) {
    char fileName[MAX_NAME_LENGTH];
    char typeChoice[10];
    bool isFile;
    scanf("%s %s", fileName, typeChoice);

    int name_size = strlen(fileName);
    for (int i = 0; i < name_size; i++) {
        if (fileName[i] < 'a' || fileName[i] > 'z') {
            red();
            printf("Error: Name expected in all lowercase\n");
            printf("Nothing was added\n");
            reset();
            return;
        }
    }
    if (strcasecmp(typeChoice, "FILE") == 0)
        isFile = true;
    else if (strcasecmp(typeChoice, "FOLDER") == 0)
        isFile = false;
    else {
        red();
        printf("Error: Invalid type (Valid types: \"file\", \"folder\")\n");
        reset();
        yellow();
        printf("Note: File/Folder name cannot contain spaces\n");
        reset();
        return;
    }
    add_node(currentDir, fileName, isFile);
}

TreeNode *MOVE(TreeNode *root, TreeNode *current) {
    char *input_string;
    TreeNode *temp;

    input_string = read_string();
    if (input_string[0] == 0) {
        red();
        printf("Error: Invalid path\n\n");
        reset();
        return current;
    }
    temp = traversal(input_string, root);
    free(input_string);

    /*error*/
    /*Returning NULL if path is wrong*/
    if (temp == NULL) {
        // no changes to the input root
        red();
        printf("Error: Invalid path\n\n");
        reset();
        return current;
    }

    /*The given path leads to a file*/
    if (temp->file->is_file) {
        // no changes to the input root
        red();
        printf("Error: Given path leads to a file, move was unsuccessful\n");
        reset();
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
        red();
        printf("Error: %s is a file\n", Node->file->name);
        reset();
    } else {
        red();
        printf("Error: Invalid Path\n");
        reset();
    }

    return table;
}

TreeNode *TELEPORT(AliasTableStruct table, TreeNode *root) {
    char alias[MAX_ALIAS_LENGTH];
    scanf("%s", alias);
    char *path = FindAlias(alias, table);
    //changed here to resolve seg fault when non existing directory
    if (!path)return root;
    TreeNode *current;

    current = traversal(path, root);

    /*error*/
    /*Returning NULL if path found wrong*/
    if (current == NULL) {
        // no changes to the input root
        red();
        printf("Error: Invalid path\n");
        reset();
        return root;
    }

    return current;
}

void FIND(TreeNode *currentDir) {
    //printf("Enter prefix string: ");

    char *prefixStr = read_string();
    if (prefixStr[0] == '\0') {
        red();
        printf("Error: No prefix string found\n");
        reset();
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
    printf("\t\tUsage: add <name> <type>\n");
    printf("\t\tExamples: 'add foo folder', 'add bar file'\n\n");

    printf("move\t\tChange current directory to any directory by taking input the complete path to that directory\n");
    printf("\t\tUsage: move <path>\n");
    printf("\t\tExample: 'move root/foo'\n\n");

    printf("alias\t\tTakes input the complete path to that directory and the alias\n");
    printf("\t\tUsage: alias <path> <aliasforpath>\n");
    printf("\t\tExample: 'alias root/foo hello\n\n");

    printf("teleport\tChange the current directory to any directory by taking input the alias of that directory\n");
    printf("\t\tUsage: teleport <aliasforpath>\n");
    printf("\t\tExample:(from the alias example) 'teleport hello'\n\n");

    printf("find\t\tSearch for all the files/directories with given prefix inside current directory\n");
    printf("\t\tUsage: find <prefix>\n");
    printf("\t\tExample: 'find f' in root prints foo\n\n");

    printf("ls\t\tPrints all the files/folders in the current directory\n");
    printf("\t\tUsage: ls\n\n");

    printf("cd\t\tChange current directory to any directory inside the current directory by taking input the\n\t\t\
relative path that starts with the name of the current directory\n");
    printf("\t\tUsage: cd <path>\n\n");

    printf("quit\t\tTerminates the program\n");
    printf("\t\tUsage: quit\n\n");

}
void HEAVYRIGHT() {
    purple();
    setlocale(LC_CTYPE, "");
    wchar_t star = 0x276F;
    wprintf(L"%lc ", star);
    reset();
}


void RIGHTARROW() {
    setlocale(LC_CTYPE, "");
    wchar_t star = 0x3009;
    wprintf(L"%lc ", star);
}


void QUIT(TreeNode *root, AliasTableStruct alias_table) {
    delete_tree(root);
    DeleteAliasTable(alias_table);
}
void DESIGN() {
    yellow();
    printf("\t ______      _____   ______      _____     ____   ________   ______      _____    _____  \n");
    printf("\t(_  __ \\    (_   _) (   __ \\    / ___/    / ___) (___  ___) (   __ \\    / ___/   / ___/  \n");
    printf("\t  ) ) \\ \\     | |    ) (__) )  ( (__     / /         ) )     ) (__) )  ( (__    ( (__    \n");
    printf("\t ( (   ) )    | |   (    __/    ) __)   ( (         ( (     (    __/    ) __)    ) __)   \n");
    printf("\t  ) )  ) )    | |    ) \\ \\  _  ( (      ( (          ) )     ) \\ \\  _  ( (      ( (      \n");
    printf("\t / /__/ /    _| |__ ( ( \\ \\_))  \\ \\___   \\ \\___     ( (     ( ( \\ \\_))  \\ \\___   \\ \\___  \n");
    printf("\t(______/    /_____(  )_) \\__/    \\____\\   \\____)    /__\\     )_) \\__/    \\____\\   \\____\\ \n");
    printf("                                                                                         \n");
    reset();
    // printf("                                                                                         ");
    // printf("                                                                                         ");
    // printf("                                                                                         ");
    // printf("                                                                                         ");
    // printf("                                                                                         ");
    // printf("                                                                                         ");
    // printf("                                                                                         ");
    // printf("                                                                                         ");
}


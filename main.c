#include "DirectoryManager.h"
#include "include.h"

int main() {
  printf("\x1b[2J\x1b[1;1H");
  fflush(stdout);
  TreeNode *root = init_tree();
  AliasTableStruct alias_table = CreateHash(INITIAL_TABLE_SIZE);
  char command[15];

  STARTUP();

  TreeNode *current = root;

  while (1) {
    print_current_path(current);

    scanf("%s", command);

    if (!strcasecmp(command, "move")) {
      current = MOVE(root, current);
      continue;
    } else if (!strcasecmp(command, "add")) {
      ADD(current);
      continue;
    } else if (!strcasecmp(command, "alias")) {
      alias_table = ALIAS(alias_table, root);
      continue;
    } else if (!strcasecmp(command, "teleport")) {
      current = TELEPORT(alias_table, root);
      continue;
    } else if (!strcasecmp(command, "find")) {
      FIND(current);
      continue;
    } else if (!strcasecmp(command, "ls")) {
      print_contents(current);
      continue;
    } else if (!strcasecmp(command, "help")) {
      HELP();
      continue;
    } else if (!strcasecmp(command, "cd")) {
      current = MOVE(current, current);
      continue;
    } else if (!strcasecmp(command, "quit")) {
      printf("Program is ending *sad windows xp noises*\n");
      QUIT(root, alias_table);
    } else {
      red();
      printf("Error: Invalid command, try again.\n");
      reset();
      printf("Type \"");
      green();
      printf("help");
      reset();
      printf("\" for help\n");
    }
  }
  printf("\x1b[2J\x1b[1;1H");
  fflush(stdout);
  return 0;
}
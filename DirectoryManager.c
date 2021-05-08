#include "DirectoryManager.h"

void add(char *fileName, bool isFile, TreeNode *currentDir) {
  add_node(currentDir, fileName, isFile);
}

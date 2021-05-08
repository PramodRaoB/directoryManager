#include "DirectoryManager.h"

void ADD(char *fileName, bool isFile, TreeNode *currentDir) {
  add_node(currentDir, fileName, isFile);
}

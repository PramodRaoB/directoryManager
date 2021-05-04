# Changelog

## 02 May 2021

## by Pramod Rao B (@PramodRaoB) in branch `childHashTable` (merged)

### Commits today: 4

- Added hashChild.h and hashChild.c
- Implemented insertion and finding in hash table which stores pointers to tree node
- Used djb2 for better hash function with name of the node being key
- Added NodeElement.h to restructure the tree node
- Resolved merge conflicts with tree.h because of branch originating from an older commit

## by Tejah S S (@BuzzingTaz) in branch `dynamic_string` (merged)

### Commits today: 2

- Added driver.c to test implementations. To be removed later.
- Added `print_contents` function. It lists all files and folders present in the current directory.
- Reordered functions in tree.c to match tree.h
- Bug fixes in tree.c

### Commits today: 1

- Added `struct filedetails` with the typedef `FileDetails`. It contains elements `char* name` and `bool is_file`. Done in order to make the array implementation of children easier.
- Changed `name` from a fixed length string to a variable length string.
- Changed `TreeNode* firstchild` to `TreeNode* first_child` to comply with the naming standards.
- Implemented Delete Tree function
- Added comments
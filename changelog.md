# Changelog

## 02 May 2021

## by Tejah S S (@BuzzingTaz) in branch `dynamic_string`

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

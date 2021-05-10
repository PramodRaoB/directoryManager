# README
# Installation and Setup

To setup the program on your desktop, do the following.

`git clone [https://github.com/PramodRaoB/directoryManager](https://github.com/PramodRaoB/directoryManager)`

In the directory of your choice.

# Usage

In the local repository, just type the following into the console

`make`

make runs the Makefile which contains the instructions to compile and run the program.

Note: The Makefile assumes the compiler to be `gcc`

For clang users, use `make clang`

# Features

1. Add a file in the current directory using the `add` function
2. Move to any directory using `move`.
3. Save path to directory using `alias`.
4. Move to any directory using `teleport`by providing alias of the path.
5. `find`allows you to search through the current directory with a specified prefix
6. Exit the program using `quit`
7. Display contents of current directory using `ls`.
8. Use `cd` to move to directory of choice from the current directory.
            9. Use `help` to learn more about the usage.

# Repository Contents

```bash

├── DirectoryManager.c
├── DirectoryManager.h
├── Directree
│   ├── NodeElement.h
│   ├── hashChild.c
│   ├── hashChild.h
│   ├── tree.c
│   ├── tree.h
│   ├── trie.c
│   └── trie.h
├── Hash(Alias)
│   ├── hash.c
│   └── hash.h
├── Makefile
├── README.md
├── a.out
├── changelog.md
├── design.sh
├── documentation.md
├── include.h
├── main.c
├── main.out
└── utils
├── colors.c
├── colors.h
├── design.sh
├── stack.c
├── stack.h
├── string_parser.c
├── string_parser.h
├── utils.c
└── utils.h
```

# Contribution

### Pramod Rao Budramane

- Trie Implementation
- Hashtable for child nodes, prime functions
- Maintaining repository
	            - Program Quality Testing

### Soveet Kumar Nayak

- Driver functions
- Aliases, hashing for it, and rehashing
- Teleport function, and traversal
- Quality Control, Help function

### Srikar Bhavesh Desu

- String Parser
- Aliases, Hashing
- Finding in Alias table
- Program testing and bug fixes

### Tejah S.S.

- Tree Structure
- Move function, main functions
- Improvement in functions, primary bug fixing, error fixtures
- Comments and code readability, Makefile, Formatting, Code Maintenance, Named the repository

### Varshita Kolipaka

- Tree Structure, Improved Alias Function
- Commented Code, Test code for bugs, Makefile, Made styling consistent
- Frontend Interface and design, Code Documentation, README, cleaned
- Code Maintenance

# Data structures Used

We have used a combination of Linked List trees, Hashtables, and tries to optimise the time complexity.

We have used $2$ Hashtables, One that contains the aliases to the absolute paths and the other which contains pointers to nodes in the tree. The former hashtable is a struct of alias and absolute path, and when the `alias` command is used, the alias is updated and during `teleport` , the alias is checked against the paths stored. The latter hashtable is used to speed up the lookup as it returns a pointer to the required node (here, a file / folder) in $O(1)$ as opposed to a $O(N)$ lookup in a traditional tree structure. .

We have used a tree AND a hashtable. A hashtable alone will not allow us to print contents of the directory optimally. A tree structure enables us to go through the files / directories under current folder, both faster and more systematically.

For the `find` function, we have used a Trie. This enables us to lookup All files and folders with a specified prefix in a complexity of O(Length of word + Number of words with same prefix). The complexity of creating a trie is O(W * L) , where W is the number of words, and L is an average length of the word. `O(length of prefix + sum of lengths of all words with the given prefix)`.
The insertion is of the complexity `O(length of word)`

# Primary Functions

-- -

## `ADD(...)`

	```c
	void ADD(TreeNode * currentDir);
	```

	**INPUT:** Pointer to current directory

	**WORKING:**

	-Scans for `Name` and `FileType` where latter determines whether the token entered is a file or a directory.

	- Calls `add_node()` to add node to current directory.

	**RETURN VALUE :** NONE

	**TIME COMPLEXITY :** Depends on `add_node(...)` (Explained Later)

	**DATA STRUCTURES :** Linked List Tree, Hashtable, Trie

-- -

## `MOVE(...)`

	            ```c
	            TreeNode *MOVE(TreeNode *root, TreeNode *current);
	            ```

	            **INPUT :** Pointer to root directory, pointer to current directory

	            **WORKING :**

	            -Reads path from user

	            **RETURN VALUE :** Pointer to required directory

	            **TIME COMPLEXITY :** Depends on `add_node(...)` (Explained Later)

	            DATA STRUCTURES : Linked List Tree, Hashtable

	            -- -

## `ALIAS(...)`

	            ```c
	            AliasTableStruct ALIAS(AliasTableStruct table, TreeNode *root);
	            ```

	            **INPUT : Pointer to table of aliases, Pointer to root**

	            **WORKING :**

	            -Reads path and alias from user

	            - Traverses to required directory using `InsertPathQP(...)` and updates path for

	            **RETURN VALUE :** Pointer to Alias Table

	            **TIME COMPLEXITY :** Depends on `InsertPathQP(...)` (Explained Later)

	            DATA STRUCTURES : Hashtable, Linked List Tree

	            -- -

## `TELEPORT(...)`

	            ```c
	            TreeNode *TELEPORT(AliasTableStruct table, TreeNode *root);
	            ```

	            **INPUT : Pointer to table of aliases, Pointer to root**

	            **WORKING :**

	            -Reads alias from user

	            - Finds absolute path in Alias Table using `FindAlias(...)`

	            -Traverses to required directory using `Traversal(...)`

	            **RETURN VALUE :** Pointer to current directory

	            **TIME COMPLEXITY :** Depends on `FindAlias(...)` (Explained Later)

	            and `traversal(...)`

	            DATA STRUCTURES : Linked List Tree, Hashtable

	            -- -

## `FIND(...)`

	            ```c
	            void FIND(TreeNode *currentDir);
	            ```

	            **INPUT : Pointer to table of aliases, Pointer to root**

	            **WORKING :**

	            -Reads prefix from user

	            - Prints all items in current directory with given prefix using the `printTrieWithPrefix(...)`

	            **RETURN VALUE : -**

	            **TIME COMPLEXITY :** Depends on `printViewWithPrefix(...)` (Explained Later)

	            DATA STRUCTURES : Tries

## `HELP(...)`

	            ```c
	            void HELP();
	            ```

	            **INPUT : Pointer to table of aliases, Pointer to root**

	            **WORKING :**

	            Prints help manual.

	            **RETURN VALUE : -* *

	            **TIME COMPLEXITY :**  $O(1)$

## `print_current_path(...)`

	            ```c
	            void print_current_path(TreeNode *current)
	            ```

	            **INPUT :** Pointer to current directory

	            **WORKING :**

	            Prints the current path using a recursive util function by traversing from current to root directory

	            **RETURN VALUE : -* *

	            **TIME COMPLEXITY :**  $O(No.\ Files\ * ( HashTable\ Size + Len\ Largest\ Word ))$

	            This is because each tree node consists of a Children Hashtable and a trie, both of whose memory we free before terminating the program. This prevents memory leaks. The alias hashtable has been ignore as it is insignificant aymptotically.

## `TREE(...)`

	            ```c
	            void dfsTree(TreeNode *curr, int numSpaces);
	            ```

	            **INPUT :** Pointer to current directory, and number of spaces initialised to 0

	            **WORKING :**

	            Calls itself recursively to print an ascii tree of the files and folders within the directory heirarchally

	            **RETURN VALUE : -* *

	            **TIME COMPLEXITY :**  $O(No.\ of\ files / folders\ in\ current\ directory)$

	            This is because each tree node consists of a Children Hashtable and a trie, both of whose memory we free before terminating the program. This prevents memory leaks. The alias hashtable has been ignore as it is insignificant aymptotically.

## `QUIT(...)`

	            ```c
	            QUIT(TreeNode *root, AliasTableStruct alias_table);
	            ```

	            **INPUT : Pointer to table of aliases, Pointer to root**

	            **WORKING :**

	            Quits the program.

	            **RETURN VALUE : - -**

	            **TIME COMPLEXITY :**  $O(No.\ Files\ * ( HashTable\ Size + Len\ Largest\ Word ))$

	            This is because each tree node consists of a Children Hashtable and a trie, both of whose memory we free before terminating the program. This prevents memory leaks. The alias hashtable has been ignore as it is insignificant aymptotically.

## Secondary/Helper Functions

## `add_node(...)`

	            ```c
	            void add_node(TreeNode *parent, char *name, bool is_file);
	            ```

	            **INPUT : Pointer to parent, name, whether it's a file**

	            **WORKING:**

	            Adds a node pointer to the array of children of the current directory.

	            Insert into the linked list of children nodes of parent

	            Adds string to the trie in the parent node.

	            ERROR HANDLING: We ensure that we do not insert an invalid element type, only lowercase alphabets, and a repeated file/folder, it will be checked for in the Hashtable of children and will not be inserted into the trie and tree. (We check in the hashtable, because the search is $O(1)$)

	            **RETURN VALUE: -**

	            **TIME COMPLEXITY:**

	            Insertion into hashtable: $O(1)$ (Assuming less collisions)

	            Insertion into trie: $O(Length\  of\  string)$

	            Insertion into tree: $O(1)$

	            This is because each tree node consists of a Children Hashtable and a trie, both of whose memory we free before terminating the program. This prevents memory leaks. The alias hashtable has been ignore as it is insignificant aymptotically.

## `read_string(...)`

	            ```c
	            char *read_string(void);
	            ```

	            **INPUT: void**

	            **WORKING:**

	            Scans for path as a string and converts it into a 2d array of words.

	            The string will be read through, and trailing `\n` and  spaces will be removed/

	            **RETURN VALUE:** Input string if there are no spaces in between. else NULL.

	            **TIME COMPLEXITY:**  $O(Length\ of\ string)$

	            This is because we loop through the whole string to check for trailing spaces

## `traversal(...)`

	            ```c
	            TreeNode *traversal(char *path, TreeNode *root);
	            ```

	            **INPUT:** Path, pointer to root

	            **WORKING:**

	            Parses the path using the `string_parser()`, `len_of_parser_func()`

	            Used in `ADD()`, `MOVE()`, `TELEPORT()`

	            **RETURN VALUE:**  Pointer to the node pointed to by the path

	            **TIME COMPLEXITY:**  $O(Path\ Length\  +\ levels\  in \ tree)$
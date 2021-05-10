```c

```

# Installation and Setup

To setup the program on your desktop, do the following. `Insert dependencies if anyinsert some commands`

# Usage

	`Insert makefile and commands to run program`

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
	│   ├── driver.c
	│   ├── hashChild.c
	│   ├── hashChild.h
	│   ├── tree.c
	│   ├── tree.h
	│   ├── trie.c
	│   └── trie.h
	├── Hash(Alias)
		│   ├── driver.c
		│   ├── hash.c
		│   └── hash.h
		├── README.md
		├── changelog.md
		├── doc.md
		├── include.h
		├── main.c
		└── utils
		├── driver.c
		├── driverstring.c
		├── stack.c
		├── stack.h
		├── string_parser.c
		├── string_parser.h
		├── utils.c
		└── utils.h

		```

# Primary Functions

		-- -

## `ADD(...)`

		```c
		void ADD(TreeNode *currentDir);
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

**INPUT:** Pointer to root directory, pointer to current directory

**WORKING:**

-Reads path from user

**RETURN VALUE:** Pointer to required directory

**TIME COMPLEXITY:** Depends on `add_node(...)` (Explained Later)

DATA STRUCTURES: Linked List Tree, Hashtable

-- -

## `ALIAS(...)`

```c
AliasTableStruct ALIAS(AliasTableStruct table, TreeNode *root);
```

**INPUT: Pointer to table of aliases, Pointer to root**

**WORKING:**

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

**INPUT: Pointer to table of aliases, Pointer to root**

**WORKING:**

-Reads alias from user

- Finds absolute path in Alias Table using `FindAlias(...)`

-Traverses to required directory using `Traversal(...)`

**RETURN VALUE:** Pointer to current directory

**TIME COMPLEXITY:** Depends on `FindAlias(...)` (Explained Later)

and `traversal(...)`

DATA STRUCTURES: Linked List Tree, Hashtable

-- -

## `FIND(...)`

```c
void FIND(TreeNode *currentDir);
```

**INPUT: Pointer to table of aliases, Pointer to root**

**WORKING:**

-Reads prefix from user

- Prints all items in current directory with given prefix using the `printTrieWithPrefix(...)`

**RETURN VALUE: -**

**TIME COMPLEXITY:** Depends on `printViewWithPrefix(...)` (Explained Later)

DATA STRUCTURES: Tries

## `HELP(...)`

```c
void HELP();
```

**INPUT: Pointer to table of aliases, Pointer to root**

**WORKING:**

Prints help manual.

**RETURN VALUE: -* *

**TIME COMPLEXITY:**  $O(1)$

## `QUIT(...)`

```c
QUIT(TreeNode *root, AliasTableStruct alias_table)
```

**INPUT: Pointer to table of aliases, Pointer to root**

**WORKING:**

Quits the program.

**RETURN VALUE: - -**

**TIME COMPLEXITY:**  $O(No.\ Files\ * ( HashTable\ Size + Len\ Largest\ Word ))$

This is because each tree node consists of a Children Hashtable and a trie, both of whose memory we free before terminating the program. This prevents memory leaks. The alias hashtable has been ignore as it is insignificant aymptotically.

## Secondary/Helper Functions

## `add_node(...)`

```c
void add_node(TreeNode *parent, char *name, bool is_file
              ```

              **INPUT: Pointer to parent, name, whether it's a file**

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

              **RETURN VALUE: string read from input**

              **TIME COMPLEXITY:**  $O(Length\ of\ string)$

              This is because we loop through the whole string to check for trailing spaces

## `traversal(...)`

              ```c
              TreeNode *traversal(char *path, TreeNode *root);
              ```

              **INPUT: Path, pointer to root**

              **WORKING:**

              Parses the path using the `string_parser()`, `len_of_parser_func()`

              Used in `ADD()`, `MOVE()`, `TELEPORT()`

              **RETURN VALUE: - -**

              **TIME COMPLEXITY:**  $O(No.\ Files\ *( HashTable\ Size + Len\ Largest\ Word ))$

              This is because each tree node consists of a Children Hashtable and a trie, both of whose memory we free before terminating the program. This prevents memory leaks. The alias hashtable has been ignore as it is insignificant aymptotically.

## `QUIT(...)`

              ```c
              QUIT(TreeNode *root, AliasTableStruct alias_table)
              ```

              **INPUT: Pointer to table of aliases, Pointer to root**

              **WORKING:**

              Quits the program.

              **RETURN VALUE: - -**

              **TIME COMPLEXITY:**  $O(No.\ Files\ *( HashTable\ Size + Len\ Largest\ Word ))$

              This is because each tree node consists of a Children Hashtable and a trie, both of whose memory we free before terminating the program. This prevents memory leaks. The alias hashtable has been ignore as it is insignificant aymptotically.

## `QUIT(...)`

              ```c
              QUIT(TreeNode *root, AliasTableStruct alias_table);
              ```

              **INPUT: Pointer to table of aliases, Pointer to root**

              **WORKING:**

              Quits the program.

              **RETURN VALUE: - -**

              **TIME COMPLEXITY:**  $O(No.\ Files\ *( HashTable\ Size + Len\ Largest\ Word ))$

              This is because each tree node consists of a Children Hashtable and a trie, both of whose memory we free before terminating the program. This prevents memory leaks. The alias hashtable has been ignore as it is insignificant aymptotically.
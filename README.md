#README

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
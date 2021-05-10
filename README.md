# [Directory Manager](https://github.com/PramodRaoB/directoryManager)

## Repo for the DSA Mini-project Directory Manager

## Getting files

To setup the program on your desktop, do the following.

`git clone https://github.com/PramodRaoB/directoryManager`

In the directory of your choice.
This includes all files required for the program and the report + code documentation.

# Running the program

In the local repository, just type the following into the console

```bash
make
```

This runs the Makefile which contains the instructions to compile and run the program.

Note: The Makefile assumes the compiler to be `gcc`

For clang users, use

```bash
`make clang`
```

# Usage

The user can type `help` after running the program to see a full list of commands available to the user. In short,

To add a file/folder to the directory use the command where type can be "file" or "folder"
```
add <name> <type>
```

To move to a different directory. Here the path cannot contain spaces, and be in the format "root/".
```
move <path>
```

To alias a path to a string, use the following command. Path should follow the same rules as above.
```
alias <path>
```

To teleport to the alias use this command. The alias should be created first using `alias` before teleporting.
```
teleport <alias>
```

To quit the program, type
```
quit
```

## Features

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
│   ├── NodeElement.h
│   ├── hashChild.c
│   ├── hashChild.h
│   ├── tree.c
│   ├── tree.h
│   ├── trie.c
│   └── trie.h
├── Hash(Alias)
│   ├── hash.c
│   └── hash.h
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

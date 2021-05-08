#ifndef TRIE_H
#define TRIE_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct trieNode TrieNode;
typedef TrieNode *Trie;

struct trieNode {
  int nodeCount;
  Trie *children;

  bool isEndOfWord;

  // functions
  void (*insert)(Trie, char *);
  int (*count)(const Trie, const char *);
};

Trie createTrie();

void trieInsert(Trie T, char *str);
bool trieSearch(Trie T, const char *str);

void printTrie(Trie T);
void printTrieWithPrefix(Trie T, char *str);

#endif

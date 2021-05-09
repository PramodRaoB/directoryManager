#include "trie.h"
#include "../utils/stack.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char alpha[27] = "abcdefghijklmnopqrstuvwxyz";

Trie createTrie() {
  Trie T = (Trie)malloc(sizeof(TrieNode));
  T->children = (Trie *)malloc(26 * sizeof(Trie));

  for (int i = 0; i < 26; i++) {
    T->children[i] = NULL;
  }

  T->isEndOfWord = false;
  T->count = 0;

  return T;
}

void trieInsert(Trie T, char *str) {
  int n = strlen(str);

  for (int i = 0; i < n; i++) {
    int curr = str[i] - 'a';

    if (T->children[curr] == NULL) {
      T->children[curr] = createTrie();
    }
    T->children[curr]->count++;

    T = T->children[curr];
  }
  T->isEndOfWord = true;
}

bool trieSearch(Trie T, const char *str) {
  int n = strlen(str);

  for (int i = 0; i < n; i++) {
    int curr = str[i] - 'a';

    if (T->children[curr] == NULL) {
      return false;
    }

    T = T->children[curr];
  }

  if (T->isEndOfWord)
    return true;

  return false;
}

void printTrie(Trie T) {
  for (int i = 0; i < 26; i++) {
    if (T->children[i] != NULL) {
      printf("%c %d\n", (char)(i + 'a'), T->children[i]->nodeCount);
      printTrie(T->children[i]);
    }
  }
}

void dfsPrint(Trie T, Stack *s) {
  if (T->isEndOfWord)
    s->print(s);
  for (int i = 0; i < 26; i++) {
    if (T->children[i] != NULL) {
      s->push(s, alpha[i]);
      dfsPrint(T->children[i], s);
    }
  }
  s->pop(s);
}

void printTrieWithPrefix(Trie T, char *str) {
  int n = strlen(str);
  Stack *s = initStack();

  for (int i = 0; i < n; i++) {
    int curr = str[i] - 'a';

    if (T->children[curr] == NULL) {
      free(s->arr);
      free(s);
      return;
    }

    s->push(s, str[i]);
    T = T->children[curr];
  }
  dfsPrint(T, s);
  free(s->arr);
  free(s);
}

void deleteTrie(Trie T) {
  for (int i = 0; i < 26; i++) {
    if (T->children[i] != NULL)
      deleteTrie(T->children[i]);
  }
  free(T);
}

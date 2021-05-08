#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

Stack *initStack() {
  Stack *s = (Stack *)malloc(sizeof(Stack));
  s->size = 0;
  s->capacity = 1;
  s->arr = (char *)malloc(s->capacity);

  s->push = __push;
  s->pop = __pop;
  s->print = __print;

  return s;
}

void __push(Stack *s, char c) {
  if (s->size == s->capacity) {
    s->capacity *= 2;
    s->arr = (char *)realloc(s->arr, s->capacity);
  }

  s->arr[s->size++] = c;
}

void __pop(Stack *s) {
  if (s->size == 0)
    return;
  s->size--;
  if (s->capacity > 2 * s->size) {
    s->capacity /= 2;
    s->arr = (char *)realloc(s->arr, s->capacity);
  }
}

void __print(Stack *s) {
  unsigned int n = s->size;
  for (int i = 0; i < n; i++)
    printf("%c", s->arr[i]);

  printf("\n");
}

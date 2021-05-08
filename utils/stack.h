#ifndef STACK_H
#define STACK_H

typedef struct stack Stack;

struct stack {
  unsigned int size;
  unsigned int capacity;
  char *arr;

  void (*push)(Stack *, char);
  void (*pop)(Stack *);
  void (*print)(Stack *s);
};

Stack *initStack();
void __push(Stack *s, char c);
void __pop(Stack *s);
void __print(Stack *s);

#endif

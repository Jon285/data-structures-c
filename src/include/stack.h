#ifndef STACK_HEADER
#define STACK_HEADER

#include <stddef.h>

struct StackNode {
  void *data;
  struct StackNode *below;
};

typedef struct _Stack {
  struct StackNode *top;

  size_t size;
  void (*destructor)(void *data);
} Stack;

void stack_init(Stack *stack, void (*destroy)(void *data));
void stack_destroy(Stack *stack);
void stack_push(Stack *stack, void *data);
void *stack_pop(Stack *stack);
void *stack_peek(Stack *stack);

#endif

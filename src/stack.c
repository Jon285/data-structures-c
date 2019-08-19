#include <stdlib.h>

#include "include/stack.h"

void stack_init(Stack *stack, void (*destroy)(void *data)) {
  stack->top = NULL;
  stack->size = 0;
  stack->destructor = destroy;
}

void stack_destroy(Stack *stack) {
  void *data = NULL;

  while (stack->size != 0) {
    stack_pop(stack);

    if (stack->destructor != NULL)
      stack->destructor(data);
  }
}

void stack_push(Stack *stack, void *data) {
  struct StackNode *new_node = malloc(sizeof(struct StackNode));

  if (new_node == NULL)
    return;

  new_node->below = stack->top;
  new_node->data = data;
  stack->top = new_node;
  stack->size++;
}

void *stack_pop(Stack *stack) {
  struct StackNode *top = stack->top;

  stack->top = top->below;
  void *data_ret = top->data;

  free(top);
  stack->size--;

  return data_ret;
}

void *stack_peek(Stack *stack) { return stack->top->data; }

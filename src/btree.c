#include <stdlib.h>

#include "../include/btree.h"

void btree_init(BinaryTree *tree, void (*destructor)(void *)) {
  tree->size = 0;
  tree->destructor = destructor;
  tree->root = NULL;
}

void btree_destroy(BinaryTree *tree) {}

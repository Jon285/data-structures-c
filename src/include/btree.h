#ifndef BTREE_HEADER
#define BTREE_HEADER

#include <stddef.h>

struct BTNode {
  void *data;
  struct BTNode *parent;
  struct BTNode *left;
  struct BTNode *right;
};

typedef struct BTree {
  struct BTNode *root;

  size_t size;
  void (*destructor)(void *data);
} BinaryTree;

void btree_init(BinaryTree *tree, void (*destructor)(void *data));
void btree_destroy(BinaryTree *tree);
void btree_ins_left(BinaryTree *tree, struct BTNode *node, void *data);
void btree_ins_right(BinaryTree *tree, struct BTNode *node, void *data);
void btree_rem_left(BinaryTree *tree, struct BTNode *node);
void btree_rem_right(BinaryTree *tree, struct BTNode *node);

#endif

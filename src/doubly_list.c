/*   Copyright 2019 Jônatas Batista
**
**   Licensed under the Apache License, Version 2.0 (the "License");
**   you may not use this file except in compliance with the License.
**   You may obtain a copy of the License at
**
**       http://www.apache.org/licenses/LICENSE-2.0
**
**   Unless required by applicable law or agreed to in writing, software
**   distributed under the License is distributed on an "AS IS" BASIS,
**   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
**   See the License for the specific language governing permissions and
**   limitations under the License.
*/

#include <stdlib.h>

#include "./include/doubly_list.h"

void dlist_create(DLinkedList *list, void (*destroyer)(void *data)) {
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
  list->destructor = destroyer;
}
void dlist_destroy(DLinkedList *list) {
  void *data = NULL;

  while (list->size > 0) {
    data = dlist_remove_back(list);
    if (list->destructor != NULL)
      list->destructor(data);
  }
}

void dlist_insert_front(DLinkedList *list, void *data) {
  struct DNode *new_node = malloc(sizeof(struct DNode));

  new_node->data = data;
  new_node->next = list->head;
  new_node->prev = NULL;

  if (list->head != NULL)
    list->head->prev = new_node;

  if (list->tail == NULL)
    list->tail = new_node;

  list->head = new_node;
  list->size++;
}

void dlist_insert_back(DLinkedList *list, void *data) {
  struct DNode *new_node = malloc(sizeof(struct DNode));

  new_node->data = data;
  new_node->next = NULL;
  new_node->prev = list->tail;

  if (list->tail != NULL)
    list->tail->next = new_node;

  if (list->head == NULL)
    list->head = new_node;

  list->tail = new_node;
  list->size++;
}
void dlist_insert_next(DLinkedList *list, struct DNode *node, void *data) {
  struct DNode *new_node = malloc(sizeof(struct DNode));

  new_node->next = node->next;
  new_node->prev = node;
  new_node->data = data;
  node->next->prev = new_node;
  node->next = new_node;

  list->size++;
}

void *dlist_remove_back(DLinkedList *list) {
  struct DNode *rem_node = list->tail;

  if (rem_node == NULL)
    return NULL;

  rem_node->prev->next = NULL;
  list->tail = rem_node->prev;

  void *data = rem_node->data;

  free(rem_node);
  list->size--;

  return data;
}

void *dlist_remove_front(DLinkedList *list) {
  struct DNode *rem_node = list->head;

  if (rem_node == NULL)
    return NULL;

  rem_node->next->prev = NULL;
  list->head = rem_node->next;

  void *data = rem_node->data;

  free(rem_node);
  list->size--;

  return data;
}

void *dlist_remove_next(DLinkedList *list, struct DNode *node) {
  struct DNode *rem_node = node->next;

  if (rem_node == NULL)
    return NULL;

  rem_node->next->prev = node;
  node->next = rem_node->next;

  void *data = rem_node->data;

  free(rem_node);
  list->size--;

  return data;
}

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

#include "./include/single_list.h"

void list_init(LinkedList *list, void (*destruct)(void *data)) {
  list->size = 0;
  list->head = NULL;
  list->tail = NULL;
  list->destructor = destruct;
}

void list_destroy(LinkedList *list) {
  while (list->head != NULL) {
    list_remove_front(list, NULL);
  }
}

void list_insert_front(LinkedList *list, void *data) {
  struct SNode *new_node = malloc(sizeof(struct SNode));

  new_node->data = data;
  new_node->next = list->head;
  list->head = new_node;

  if (list->size == 0)
    list->tail = new_node;

  list->size++;
}

void list_insert_back(LinkedList *list, void *data) {
  struct SNode *new_node = malloc(sizeof(struct SNode));

  new_node->data = data;
  new_node->next = NULL;

  // deal with an empty list
  if (list->size == 0)
    list->head = new_node;
  else
    list->tail->next = new_node;

  list->tail = new_node;

  list->size++;
}

void list_insert_next(LinkedList *list, struct SNode *node, void *data) {
  struct SNode *new_node = malloc(sizeof(struct SNode));

  new_node->data = data;
  new_node->next = node->next;
  node->next = new_node;

  list->size++;
}

void list_remove_front(LinkedList *list, void **data_save) {
  if (list->head == NULL)
    return;

  struct SNode *rem_node = list->head;

  if (data_save != NULL)
    *data_save = rem_node->data;
  else if (list->destructor != NULL)
    list->destructor(rem_node->data);

  list->head = rem_node->next;

  free(rem_node);
  list->size--;
  return;
}

void list_remove_back(LinkedList *list, void **data_save) {
  if (list->tail == NULL)
    return;

  struct SNode *current = list->head;

  if (current->next == NULL) {

    if (data_save != NULL)
      *data_save = current->data;
    else if (list->destructor != NULL)
      list->destructor(current->data);

    free(current);

    list->head = NULL;
    list->tail = NULL;
    list->size--;

    return;
  }

  while (current->next != list->tail)
    current = current->next;

  struct SNode *rem_node = current->next;

  if (data_save != NULL)
    *data_save = rem_node->data;
  else if (list->destructor != NULL)
    list->destructor(rem_node->data);

  free(rem_node);

  list->tail = current;
  list->size--;
}

void list_remove_next(LinkedList *list, struct SNode *node, void **data_save) {
  if (node->next == NULL)
    return;

  struct SNode *rem_node = node->next;

  if (data_save != NULL)
    *data_save = rem_node->data;
  else if (list->destructor != NULL)
    list->destructor(rem_node->data);

  node->next = rem_node->next;

  free(rem_node);
  list->size--;
}

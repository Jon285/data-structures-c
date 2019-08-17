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

#ifndef SINGLE_LIST_HEADER
#define SINGLE_LIST_HEADER

#include <stddef.h>

struct SNode {
  void *data;
  struct SNode *next;
};

typedef struct LinkedList {
  struct SNode *head;
  struct SNode *tail;

  size_t size;

  void (*destructor)(void *data);
} LinkedList;

void list_init(LinkedList *list, void (*destruct)(void *data));
void list_destroy(LinkedList *list);

void list_insert_front(LinkedList *list, void *data);
void list_insert_back(LinkedList *list, void *data);
void list_insert_next(LinkedList *list, struct SNode *node, void *data);

void list_remove_front(LinkedList *list, void **data_save);
void list_remove_back(LinkedList *list, void **data_save);
void list_remove_next(LinkedList *list, struct SNode *node, void **data_save);

/* inline size_t list_size(LinkedList *list) { return list->size; } */
/* inline struct SNode *list_head(LinkedList *list) { return list->head; } */
/* inline struct SNode *list_tail(LinkedList *list) { return list->tail; } */

#endif

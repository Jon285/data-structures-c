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

#ifndef DOUBLY_LIST_HEADER
#define DOUBLY_LIST_HEADER

#include <stddef.h>

struct DNode {
  void *data;
  struct DNode *next;
  struct DNode *prev;
};

typedef struct DLinkedList {
  struct DNode *head;
  struct DNode *tail;

  size_t size;
  void (*destructor)(void *data);
} DLinkedList;

void dlist_create(DLinkedList *list, void (*destroyer)(void *data));
void dlist_destroy(DLinkedList *list);

void dlist_insert_front(DLinkedList *list, void *data);
void dlist_insert_back(DLinkedList *list, void *data);
void dlist_insert_next(DLinkedList *list, struct DNode *node, void *data);
void dlist_insert_before(DLinkedList *list, struct DNode *node, void *data);

void dlist_remove_back(DLinkedList *list, void **data_save);
void dlist_remove_front(DLinkedList *list, void **data_save);
void dlist_remove_next(DLinkedList *list, struct DNode *node, void **data_save);
void dlist_remove_before(DLinkedList *list, struct DNode *node,
                         void **data_save);

#endif

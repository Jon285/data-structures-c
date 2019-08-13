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

  void *(*allocator)(size_t);
  void *(*callocator)(size_t);
  void (*destructor)(void *);
} DLinkedList;

void dlist_create(DLinkedList **list);
void dlist_destroy(DLinkedList *list, void (*destoyer)(void *));
void dlist_insert_front(DLinkedList *list, void *data);
void dlist_insert_back(DLinkedList *list, void *data);
void dlist_insert_at(DLinkedList *list, void *data, unsigned int index);
void dlist_remove_back(DLinkedList *list);
void dlist_remove_front(DLinkedList *list);
void dlist_remove_at(DLinkedList *list, unsigned int index);

#endif

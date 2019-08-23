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

#ifndef QUEUE_HEADER
#define QUEUE_HEADER

#include <stddef.h>

struct QueueNode {
  void *data;
  struct QueueNode *prev;
};

typedef struct _Queue {
  struct QueueNode *head;
  struct QueueNode *tail;

  size_t size;
  void (*destructor)(void *data);
} Queue;

void queue_init(Queue *queue, void (*destroy)(void *data));
void queue_destroy(Queue *queue);
void queue_enqueue(Queue *queue, void *data);
void queue_dequeue(Queue *queue, void **data);

#endif

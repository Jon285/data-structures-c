#include "../include/queue.h"

#include <stdlib.h>

void queue_init(Queue *queue, void (*destroy)(void *data)) {
  queue->head = NULL;
  queue->tail = NULL;
  queue->size = 0;
  queue->destructor = destroy;
}

void queue_destroy(Queue *queue) {
  while (queue->size > 0)
    queue_dequeue(queue, NULL);
}

void queue_enqueue(Queue *queue, void *data) {
  struct QueueNode *new_node = malloc(sizeof(struct QueueNode));

  if (new_node == NULL)
    return;

  new_node->data = data;
  new_node->prev = NULL;

  if (queue->size == 0) {
    queue->head = new_node;
  } else {
    queue->tail->prev = new_node;
  }
  queue->tail = new_node;
  queue->size++;
}

void queue_dequeue(Queue *queue, void **data) {
  struct QueueNode *rem_node = queue->head;

  if (rem_node == NULL)
    return;

  queue->head = rem_node->prev;

  if (queue->head == NULL)
    queue->tail = NULL;

  if (data != NULL)
    *data = rem_node->data;
  else if (queue->destructor != NULL)
    queue->destructor(rem_node->data);

  free(rem_node);
  queue->size--;
}

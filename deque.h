#ifndef DEQUE_H
#define DEQUE_H

#include <stdio.h>
#include <limits.h>
#include "dynamic-array.h"

typedef struct {
    node_t *data;
    int first;
    int last;
} deque;

deque init_queue();
int is_queue_empty(deque*);
void enqueue(deque*, int);
int dequeue(deque*);

#endif

#ifndef QUEUE_H
#define QUEUE_H

#include "dynamic-array.h"

typedef struct {
    node_t *data;
    int top;
    int first;
} queue;

int is_empty(queue*);
void enqueue(queue*, int);
int dequeue(queue*);

#endif

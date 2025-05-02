#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include "dynamic-array.h"

typedef struct {
    node_t *data;
    int top;
    int first;
} queue;

queue init_queue();
int is_queue_empty(queue*);
void enqueue(queue*, int);
int dequeue(queue*);

#endif

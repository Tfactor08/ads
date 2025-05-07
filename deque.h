#ifndef DEQUE_H
#define DEQUE_H

#include <stdio.h>
#include "dynamic-array.h"

typedef struct {
    node_t *data;
    int first;
    int last;
} deque;

deque init_deque();
int is_deque_empty(deque*);
void push_back(deque*, int);
int pop_back(deque*);
void push_front(deque*, int);
int pop_front(deque*);

#endif

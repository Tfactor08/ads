#ifndef STACK_H
#define STACK_H

#include "dynamic-array.h"

typedef struct {
    node_t *data;
    int top;
} stack;

stack init_stack();
int is_empty(stack*);
void push(stack*, int);
int pop(stack*);

#endif

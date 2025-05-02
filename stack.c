#include <stdio.h>

#include "stack.h"

//typedef struct node_t node_t;
//typedef struct stack stack;
//
//node_t* init_array(int n);
//void add_element(node_t*, int, int);
//int get_element(node_t*, int);
//
//struct node_t {
//    int data;
//    node_t *next;
//};
//
//struct stack {
//    node_t *data;
//    int top;
//};

stack init_stack() {
    stack s; 
    s.top = -1;
    s.data = init_array(0);
    return s;
}

int is_empty(stack *s) {
    return s->top == -1;
}

void push(stack *s, int value) {
    if (s->top == -1) {
        s->data->data = value;
        s->top++;
        return;
    }
    add_element(s->data, ++(s->top), value);
}

int pop(stack *s) {
    if (is_empty(s)) {
        printf("Cannot pop from empty stack\n");
        return -1;
    }
    return get_element(s->data, (s->top)--);
}

//int main()
//{
//    stack s = init_stack();
//    push(&s, 69);
//    push(&s, 42);
//    printf("%d\t%d\n", pop(&s), pop(&s));
//}

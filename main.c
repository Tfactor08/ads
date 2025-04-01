#include <stdio.h>

typedef struct node_t node_t;
typedef struct stack stack;

// dynamic-array.c
node_t* init_array(int n);
void go_through(node_t*);
void free_array(node_t*);
void add_element(node_t*, int, int);
int get_element(node_t*, int);

// stack.c
stack init_stack();
int is_empty(stack *s);
void push(stack *s, int);
int pop(stack *s);

struct stack {
    node_t *data;
    int top;
};

int main()
{
    stack s = init_stack();
    push(&s, 69);
    push(&s, 42);
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
    free_array(s.data);

    return 0;
}

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>

typedef struct node_t node_t;
typedef struct queue queue;
typedef struct stack stack;

struct node_t {
    int data;
    node_t *next;
};

struct queue {
    node_t *data;
    int top;
    int first;
};

struct stack {
    node_t *data;
    int top;
};

// queue.c
queue init_queue();
int is_queue_empty(queue*);
void enqueue(queue*, int);
int dequeue(queue*);
queue gen_queue(int, char);

// stack.c
stack init_stack();
void push(stack*, int);
int pop(stack*);
int is_stack_empty(stack*);

int stack_has(stack, int);
void go_through_stack(stack*);

/* form a stack S containing all unique elements of queues L1 and L2 */
int main()
{
    srand(time(NULL));

    stack s = init_stack();
    queue l1 = gen_queue(10, 1);
    putchar('\n');
    queue l2 = gen_queue(10, 1);
    putchar('\n');
    putchar('\n');

    for (int i = 0; i < 10; ++i) {
        int next = dequeue(&l1);
        if (!stack_has(s, next))
            push(&s, next);
    }
    putchar('\n');
    for (int i = 0; i < 10; ++i) {
        int next = dequeue(&l2);
        if (!stack_has(s, next))
            push(&s, next);
    }

    go_through_stack(&s);
    putchar('\n');

    return 0;
}

int stack_has(stack s, int n)
{
    while (!is_stack_empty(&s))
        if (pop(&s) == n)
            return 1;
    return 0;
}

void go_through_stack(stack *s)
{
    while (!is_stack_empty(s))
        printf("%d\t", pop(s));
}

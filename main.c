#include "dynamic-array.h"
#include "stack.h"
#include "queue.h"

int main()
{
    // queue.c
    printf("queue.c\n");
    queue q = init_queue();
    enqueue(&q, 69);
    enqueue(&q, 69);
    printf("\t%d\n", dequeue(&q));
    printf("\t%d\n", dequeue(&q));
    free_array(q.data);
    putchar('\n');

    // stack.c
    printf("stack.c\n");
    stack s = init_stack();
    push(&s, 69);
    push(&s, 42);
    printf("\t%d\n", pop(&s));
    printf("\t%d\n", pop(&s));
    putchar('\n');

    // dynamic-array.c
    printf("dynamic-array.c\n");
    node_t *arr = init_array(4);    
    add_element(arr, 4, 69);
    go_through(arr);
    free_array(arr);

    return 0;
}

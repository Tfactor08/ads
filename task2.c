#include <time.h>

#include "queue.h"
#include "stack.h"

int stack_has(stack, int);
void go_through_stack(stack*);

/* form a stack S containing all unique elements of queues L1 and L2 */
int main()
{
    srand(time(NULL));

    stack s = init_stack();
    printf("Queue L1:\n");
    queue l1 = gen_queue(10, 1);
    putchar('\n');
    printf("Queue L2:\n");
    queue l2 = gen_queue(10, 1);
    putchar('\n');

    for (int i = 0; i < 10; ++i) {
        int next = dequeue(&l1);
        if (!stack_has(s, next))
            push(&s, next);
    }
    for (int i = 0; i < 10; ++i) {
        int next = dequeue(&l2);
        if (!stack_has(s, next))
            push(&s, next);
    }

    printf("Stack S:\n");
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

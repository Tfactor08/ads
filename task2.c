#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>

typedef struct node_t node_t;
typedef struct queue queue;

struct node_t {
    int data;
    node_t *next;
};

struct queue {
    node_t *data;
    int top;
    int first;
};

// queue.c
queue init_queue();
int is_empty(queue*);
void enqueue(queue*, int);
int dequeue(queue*);

queue gen_queue(int);

/* form a stack S containing all unique elements of queues L1 and L2 */
int main()
{
    srand(time(NULL));

    queue l1 = gen_queue(10);
    putchar('\n');
    queue l2 = gen_queue(10);

    for (int i = 0; i < 10; ++i)
        printf("%d\t", dequeue(&l1));
    putchar('\n');
    for (int i = 0; i < 10; ++i)
        printf("%d\t", dequeue(&l2));

    return 0;
}

queue gen_queue(int n)
{
    queue q = init_queue();
    for (int i = 0; i < n; ++i)
        enqueue(&q, rand() % 20);
    return q;
}

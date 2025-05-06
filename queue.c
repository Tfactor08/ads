#include "queue.h"

queue init_queue() {
    queue q; 
    q.first = -1;
    q.last = -1;
    q.data = init_array(0);
    return q;
}

int is_queue_empty(queue *q) {
    return q->last == -1;
}

void enqueue(queue *q, int value) {
    if (is_queue_empty(q)) {
        q->data->data = value;
        q->first = q->last = 0;
        return;
    }
    add_element(q->data, ++(q->last), value);
}

int dequeue(queue *q) {
    if (is_queue_empty(q)) {
        printf("Cannot pop from empty queue\n");
        return -1;
    }
    if (q->first == q->last) {
        int e = get_element(q->data, q->first);
        q->first = q->last = -1;
        return e;
    }
    return get_element(q->data, (q->first)++);
}

queue gen_queue(int n, int out)
{
    queue q = init_queue();
    for (int i = 0; i < n; ++i) {
        int r = rand() % 21;
        enqueue(&q, r);
        if (out)
            printf("%d\t", r);
    }
    return q;
}

//int main()
//{
//    queue q = init_queue();
//
//    printf("first -> %d\n", q.first);
//    printf("last -> %d\n", q.last);
//
//    putchar('\n');
//
//    enqueue(&q, 69);
//    enqueue(&q, 42);
//    enqueue(&q, 42);
//    enqueue(&q, 42);
//
//    printf("enqueue -> %d\n", 69);
//    printf("enqueue -> %d\n", 42);
//    printf("enqueue -> %d\n", 42);
//    printf("enqueue -> %d\n", 42);
//
//    putchar('\n');
//
//    printf("first -> %d\n", q.first);
//    printf("last -> %d\n", q.last);
//
//    putchar('\n');
//
//    printf("dequeue -> %d\n", dequeue(&q));
//    printf("dequeue -> %d\n", dequeue(&q));
//
//    putchar('\n');
//
//    printf("first -> %d\n", q.first);
//    printf("last -> %d\n", q.last);
//
//    putchar('\n');
//
//    printf("dequeue -> %d\n", dequeue(&q));
//    printf("dequeue -> %d\n", dequeue(&q));
//
//    putchar('\n');
//
//    printf("first -> %d\n", q.first);
//    printf("last -> %d\n", q.last);
//
//    dequeue(&q);
//}

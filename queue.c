#include "queue.h"

queue init_queue() {
    queue q; 
    q.first = -1;
    q.last = -1; // top
    q.data = init_array(0);
    return q;
}

int is_queue_empty(queue *q) {
    return q->last == -1;
}

void enqueue(queue *q, int value) {
    if (is_queue_empty(q)) {
        q->data->data = value;
        q->last++;
        return;
    }
    add_element(q->data, ++(q->last), value);
}

int dequeue(queue *q) {
    if (is_queue_empty(q)) {
        printf("Cannot pop from empty queue\n");
        return -1;
    }
    return get_element(q->data, ++(q->first));
}

//int main()
//{
//    queue q = init_queue();
//    enqueue(&q, 69);
//    enqueue(&q, 42);
//    printf("%d\t%d\n", dequeue(&q), dequeue(&q));
//}

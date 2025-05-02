#include "queue.h"

queue init_queue() {
    queue s; 
    s.top = -1;
    s.first = -1;
    s.data = init_array(0);
    return s;
}

int is_queue_empty(queue *s) {
    return s->top == -1;
}

void enqueue(queue *s, int value) {
    if (s->top == -1) {
        s->data->data = value;
        s->top++;
        return;
    }
    add_element(s->data, ++(s->top), value);
}

int dequeue(queue *s) {
    if (is_queue_empty(s)) {
        printf("Cannot pop from empty queue\n");
        return -1;
    }
    return get_element(s->data, ++(s->first));
}

//int main()
//{
//    queue q = init_queue();
//    enqueue(&q, 69);
//    enqueue(&q, 42);
//    printf("%d\t%d\n", dequeue(&q), dequeue(&q));
//}

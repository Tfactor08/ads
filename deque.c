#include "deque.h"

// TODO
// all typical funcs are implemented but not tested (even once), so it likelly has ton of errors and
// mistakes (maybe only errors, maybe only mistakes)

deque init_deque() {
    deque d; 
    d.first = -1;
    d.last = -1;
    d.data = init_array(0);
    return d;
}

int is_deque_empty(deque *d) {
    return d->first == -1 && d->last == -1;
}

void push_back(deque *d, int value) {
    if (is_deque_empty(d)) {
        d->data->data = value;
        d->last++;
        return;
    }
    add_element(d->data, ++(d->last), value);
}

void push_front(deque *d, int value) {
    if (is_deque_empty(d)) {
        d->data->data = value;
        d->first++;
        return;
    }
    if (d->first == 0)
        add_element(d->data, 0, value);
    else
        add_element(d->data, --(d->first), value);
    d->last++;
}

int pop_front(deque *d) {
    if (is_deque_empty(s)) {
        printf("Cannot pop from empty deque\n");
        return -1;
    }
    return get_element(s->data, ++(s->first));
}

int pop_back(deque *d) {
    if (is_deque_empty(s)) {
        printf("Cannot pop from empty deque\n");
        return -1;
    }
    return get_element(s->data, (s->last)--);
}

//int main()
//{
//    queue q = init_queue();
//    enqueue(&q, 69);
//    enqueue(&q, 42);
//    printf("%d\t%d\n", dequeue(&q), dequeue(&q));
//}

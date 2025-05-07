#include "deque.h"

// push_back -- same as enqueue operation in queue.c
// pop_front -- same as dequeue operation in queue.c

// TODO
// All typical funcs are implemented but not tested (even once), so it likelly has ton of errors and
// mistakes (maybe only errors, maybe only mistakes).
// Update: yes, it had. Even queue implementation had mistakes, so I fixed that first;
// Seems like deque ops are also fixed, but everthing needs to be tested.

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
        d->first = d->last = 0;
        return;
    }
    add_element(d->data, ++(d->last), value);
}

void push_front(deque *d, int value) {
    if (is_deque_empty(d)) {
        d->data->data = value;
        d->first = d->last = 0;
        return;
    }
    if (d->first == 0)
        add_element(d->data, 0, value);
    else
        add_element(d->data, --(d->first), value);
    d->last++;
}

int pop_front(deque *d) {
    if (is_deque_empty(d)) {
        printf("Cannot pop from empty deque\n");
        return -1;
    }
    if (d->first == d->last) {
        int e = get_element(d->data, d->first);
        d->first = d->last = -1;
        return e;
    }
    return get_element(d->data, (d->first)++);
}

int pop_back(deque *d) {
    if (is_deque_empty(d)) {
        printf("Cannot pop from empty deque\n");
        return -1;
    }
    if (d->first == d->last) {
        int e = get_element(d->data, d->last);
        d->first = d->last = -1;
        return e;
    }
    return get_element(d->data, (d->last)--);
}

//int main()
//{
//    deque d = init_deque();
//
//    printf("first -> %d\n", d.first);
//    printf("last -> %d\n", d.last);
//
//    putchar('\n');
//
//    push_back(&d, 1);
//    push_back(&d, 2);
//    push_back(&d, 3);
//
//    printf("push_back -> %d\n", 1);
//    printf("push_back -> %d\n", 2);
//    printf("push_back -> %d\n", 3);
//
//    putchar('\n');
//
//    push_front(&d, 69);
//
//    printf("push_front -> %d\n", 69);
//
//    printf("first -> %d\n", d.first);
//    printf("last -> %d\n", d.last);
//
//    putchar('\n');
//
//    printf("pop_front -> %d\n", pop_front(&d));
//    printf("pop_front -> %d\n", pop_front(&d));
//
//    putchar('\n');
//
//    printf("first -> %d\n", d.first);
//    printf("last -> %d\n", d.last);
//
//    putchar('\n');
//
//    printf("pop_front -> %d\n", pop_front(&d));
//    printf("pop_front -> %d\n", pop_front(&d));
//
//    putchar('\n');
//
//    printf("first -> %d\n", d.first);
//    printf("last -> %d\n", d.last);
//
//    pop_front(&d);
//}

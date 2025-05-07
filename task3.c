#include "deque.h"

deque gen_deque(int, int);
void remove_negatives(deque*);

// TODO
// no clue how to iterate through deque elements since we can't know when it becomes empty if we
// don't pop the elements. Does that mean we have to pop all of them, save somewhere (in another
// deque?), then push them back to the original deque?

/* process deque D containing integers: remove all negative values */
int main()
{
    srand(time(NULL));

    deque d = gen_deque(10, 1);
    putchar('\n');

    remove_negatives(&d);

    return 0;
}

void remove_negatives(deque *d)
{
    while (!is_deque_empty(d)) { // TODO wrong!
        int n = pop_back(d);
        if (n >= 0)
            push_back(d, n);
    }
}

void go_through_deque(deque *d)
{
    while (!is_deque_empty(d)) { // TODO wrong!
        int n = pop_back(d);
        printf("%d\t", n);
        push_back(d, n);
    }
}

deque gen_deque(int n, int out)
{
    deque d = init_deque();
    for (int i = 0; i < n; ++i) {
        int r = rand() % 21 - 10;
        push_back(&d, r);
        if (out)
            printf("%d\t", r);
    }
    return d;
}

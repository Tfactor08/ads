#include "deque.h"

deque gen_deque(int, int);
void remove_negatives(deque*);
void go_through_deque(deque);

/* process deque D containing integers: remove all negative values */
int main()
{
    srand(time(NULL));

    deque d = gen_deque(10, 0);
    go_through_deque(d);
    putchar('\n');

    remove_negatives(&d);
    go_through_deque(d);

    return 0;
}

void remove_negatives(deque *d)
{
    deque dtmp = init_deque();
    while (!is_deque_empty(d)) {
        int n = pop_back(d);
        if (n >= 0)
            push_back(&dtmp, n);
    }
    while (!is_deque_empty(&dtmp)) {
        int n = pop_back(&dtmp);
        push_back(d, n);
    }
}

void go_through_deque(deque d)
{
    while (!is_deque_empty(&d)) {
        int n = pop_front(&d);
        printf("%d\t", n);
    }
    putchar('\n');
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

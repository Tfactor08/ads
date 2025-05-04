#include "stack.h"

stack init_stack() {
    stack s; 
    s.top = -1;
    s.data = init_array(0);
    return s;
}

int is_stack_empty(stack *s) {
    return s->top == -1;
}

void push(stack *s, int value) {
    if (s->top == -1) {
        s->data->data = value;
        s->top++;
        return;
    }
    add_element(s->data, ++(s->top), value);
}

int pop(stack *s) {
    if (is_stack_empty(s)) {
        printf("Cannot pop from empty stack\n");
        return -1;
    }
    return get_element(s->data, (s->top)--);
}

//int main()
//{
//    stack s = init_stack();
//    push(&s, 69);
//    push(&s, 42);
//    printf("%d\t%d\n", pop(&s), pop(&s));
//    printf("%d\n", s.top);
//    push(&s, 13);
//    printf("%d\n", pop(&s));
//}

#include <stdio.h>
#define MAX_SIZE 100

typedef struct {
    int arr[MAX_SIZE];
    int top;
} Stack;


void initialize(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack s) {
    return s.top == -1;
}


int isFull(Stack s) {
    return s.top == MAX_SIZE - 1;
}


void push(Stack *s, int data) {
    if (isFull(*s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->arr[++s->top] = data;
}


int pop(Stack *s) {
    if (isEmpty(*s)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->arr[s->top--];
}


int peek(Stack s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    return s.arr[s.top];
}

int main() {
    Stack stack;
    initialize(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Top element of stack: %d\n", peek(stack));

    printf("Popped element: %d\n", pop(&stack));
    printf("Popped element: %d\n", pop(&stack));

    printf("Top element of stack: %d\n", peek(stack));

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *top;
} Stack;


void initialize(Stack *s) {
    s->top = NULL;
}


int isEmpty(Stack s) {
    return s.top == NULL;
}


void push(Stack *s, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = data;
    newNode->next = s->top;
    s->top = newNode;
}


int pop(Stack *s) {
    if (isEmpty(*s)) {
        printf("Stack Underflow\n");
        return -1;
    }
    Node *temp = s->top;
    int data = temp->data;
    s->top = temp->next;
    free(temp);
    return data;
}


int peek(Stack s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    return s.top->data;
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

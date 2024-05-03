#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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
        exit(EXIT_FAILURE);
    }
    s->arr[++s->top] = data;
}

int pop(Stack *s) {
    if (isEmpty(*s)) {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
    return s->arr[s->top--];
}

int evaluatePostfix(char *exp) {
    Stack stack;
    initialize(&stack);

    int i = 0;
    while (exp[i] != '\0') {
        if (isdigit(exp[i])) {
            push(&stack, exp[i] - '0');
        } else {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);
            switch (exp[i]) {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    push(&stack, operand1 / operand2);
                    break;
                default:
                    printf("Invalid postfix expression\n");
                    exit(EXIT_FAILURE);
            }
        }
        i++;
    }
    return pop(&stack);
}

int main() {
    char exp[] = "82/3-32*+";
    printf("Postfix expression: %s\n", exp);
    printf("Result: %d\n", evaluatePostfix(exp));
    return 0;
}

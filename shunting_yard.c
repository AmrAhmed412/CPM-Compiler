#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "shunting_yard.h"

#define STACK_SIZE 100

// Structure for stack
typedef struct {
    char data[STACK_SIZE];
    int top;
} Stack;

// Initialize stack
static void init(Stack *stack) {
    stack->top = -1;
}

// Check if stack is empty
static int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Check if stack is full
static int isFull(Stack *stack) {
    return stack->top == STACK_SIZE - 1;
}

// Push an element onto the stack
static void push(Stack *stack, char value) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    stack->data[++stack->top] = value;
}

// Pop an element from the stack
static char pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->data[stack->top--];
}

// Get the top element of the stack without popping it
static char peek(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        exit(EXIT_FAILURE);
    }
    return stack->data[stack->top];
}

// Get the precedence of an operator
static int precedence(char op) {
    switch(op) {
        case '+':
            return 1;
        case '-':
            return 1;
        case '*':
            return 2;
        case '/':
            return 2;
        default:
            return 0;
    }
}

// Convert infix expression to postfix expression
char* shunting_yard(char *infix) {
    int i, j;
    Stack stack;
    init(&stack);
    char *postfix = (char *)malloc(strlen(infix) * sizeof(char));
    if (postfix == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    for (i = 0, j = 0; infix[i]; i++) {
        if (isdigit(infix[i]) || isalpha(infix[i])){
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            push(&stack, infix[i]);
        } else if (infix[i] == ')') {
            while (!isEmpty(&stack) && peek(&stack) != '(') {
                postfix[j++] = pop(&stack);
            }
            if (!isEmpty(&stack) && peek(&stack) != '(') {
                printf("Invalid expression\n");
                exit(EXIT_FAILURE);
            } else {
                pop(&stack); // Discard the '('
            }
        } else {
            while (!isEmpty(&stack) && precedence(peek(&stack)) >= precedence(infix[i])) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, infix[i]);
        }
    }
    while (!isEmpty(&stack)) {
        postfix[j++] = pop(&stack);
    }
    postfix[j] = '\0'; // Null terminate the string 3lashan lma n loop 3la el string n2ol eno 5alas
    return postfix;
}
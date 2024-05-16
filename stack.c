#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include <string.h>

// Function to initialize the stack
void initialize(Stack *stack) {
    stack->top = -1; // Initialize top to -1 (empty stack)
}

// Function to check if the stack is empty
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

// Function to push an element onto the stack
void push(Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow! Cannot push element.\n");
        return;
    }
    stack->items[++stack->top] = value;
}

// Function to pop an element from the stack
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow! Cannot pop element.\n");
        return -1;
    }
    return stack->items[stack->top--];
}

// Function to peek the top element of the stack without removing it
int peek(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty! Cannot peek.\n");
        return -1;
    }
    return stack->items[stack->top];
}

// Function to display the elements of the stack
void display(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->items[i]);
    }
    printf("\n");
}
#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h> // For malloc and free

// Define the maximum size of the stack
#define MAX_SIZE 100

// Define the structure of a stack
typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;


// Function declarations
void initialize(Stack *stack);
int isEmpty(Stack *stack);
int isFull(Stack *stack);
void push(Stack *stack, int value);
int pop(Stack *stack);
int peek(Stack *stack);
void display(Stack *stack);


#endif // STACK_H
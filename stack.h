#ifndef STACK_H
#define STACK_H

// Define the maximum size of the stack
#define SIZE 100

// Define the structure of a stack
typedef struct {
    int items[SIZE];
    int top;
} Stack;

// Function to initialize the stack
void initialize(Stack *stack);

// Function to check if the stack is empty
int isEmpty(Stack *stack) ;
// Function to check if the stack is full
int isFull(Stack *stack);

// Function to push an element onto the stack
void push(Stack *stack, int value);

// Function to pop an element from the stack
int pop(Stack *stack);

// Function to peek the top element of the stack without removing it
int peek(Stack *stack);

// Function to display the elements of the stack
void displayQuad(Stack *stack);


#endif
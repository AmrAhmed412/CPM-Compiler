#ifndef STACK_H
#define STACK_H

// Define the maximum size of the stack
#define SIZE 100

// Define the structure of a stack
struct Stack{
    int items[SIZE];
    int top;
};

// Function to initialize the stack
void initialize(struct Stack* stack);

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) ;
// Function to check if the stack is full
int isFull(struct Stack* stack);

// Function to push an element onto the stack
void push(struct Stack* stack, int value);

// Function to pop an element from the stack
int pop(struct Stack* stack);

// Function to peek the top element of the stack without removing it
int peek(struct Stack* stack);

// Function to display the elements of the stack
void displayQuad(struct Stack* stack);


#endif
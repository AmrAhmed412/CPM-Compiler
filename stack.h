#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h> // For malloc and free
#include "linked_list.h"

#define MAX_SIZE 100 // Maximum size of the stack

struct Stack
{
    int index;
    struct Node *items[MAX_SIZE];
    struct Node *top;
};

// Function declarations
void initializeStack(struct Stack *stack);
int isFull(struct Stack *stack);
int isEmpty(struct Stack *stack);
void push(struct Stack *stack, struct Node *head);
struct Node *pop(struct Stack *stack);
struct Node *peek(struct Stack *stack);

#endif // STACK_H
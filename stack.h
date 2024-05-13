#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h> // For malloc and free
#include "linked_list.h"
#include <string.h>

#define MAX_SIZE 100 // Maximum size of the stack

struct Stack
{
    int index;
    struct Node *items[MAX_SIZE];
    struct Node *top;
};

// Function declarations
void initializeStack();
int isFull();
int isEmpty();
void push(struct Node *head);
struct Node *pop();
struct Node *peek();
struct Node *searchStack(char *name);

#endif // STACK_H
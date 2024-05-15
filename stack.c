#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack *globalStack;

// Function definitions
void initializeStack()
{
    globalStack = (struct Stack *)malloc(sizeof(struct Stack));
    globalStack->index = -1; // Initialize index of the stack to -1 (empty stack)
    globalStack->top = NULL; // Initialize top of the stack to -1 (empty stack)
}

int isFull()
{
    return globalStack->index == MAX_SIZE - 1;
}

int isEmpty()
{
    return globalStack->index == -1;
}

void push(struct Node *head)
{
    if (isFull())
    {
        printf("Stack overflow! Cannot push element.\n");
    }
    else
    {
        globalStack->index++;
        globalStack->items[globalStack->index] = head;
        globalStack->top = head;
    }
}

struct Node *pop()
{
    if (isEmpty())
    {
        printf("Stack underflow! Cannot pop element.\n");
        return NULL; // Return a special value indicating stack underflow
    }
    else
    {
        struct Node *poppedValue = globalStack->items[globalStack->index];
        globalStack->index--;
        globalStack->top = globalStack->items[globalStack->index];
        return poppedValue;
    }
}

struct Node *peek()
{
    if (isEmpty())
    {
        printf("Stack is empty! Cannot peek.\n");
        return NULL; // Return a special value indicating empty stack
    }
    else
    {
        return globalStack->top;
    }
}

// Function to display the stack
void displayStack()
{
    if (isEmpty())
    {
        printf("Stack is empty!\n");
    }
    else
    {
        printf("Stack contents:\n");
        for (int i = globalStack->index; i >= 0; i--)
        {
            displayListStack(globalStack->items[i]);
            printf("\n");
        }
    }
}

struct Node *searchStack(char *name)
{

    for (int i = globalStack->index; i >= 0; i--)
    {

        displayListStack(globalStack->items[i]);
        // printf("Searching in stack number:%d\n", i + 1);
        struct Node *current = globalStack->items[i];
        while (current != NULL)
        {
            if (strcmp(current->name, name) == 0)
            {
                return current; // Element found in the stack
            }
            current = current->next;
        }
    }
    return NULL;
}

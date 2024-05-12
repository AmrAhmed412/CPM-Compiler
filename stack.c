#include "stack.h"

// Function definitions
void initializeStack(struct Stack *stack)
{
    stack->index = -1; // Initialize index of the stack to -1 (empty stack)
    stack->top = NULL; // Initialize top of the stack to -1 (empty stack)
}

int isFull(struct Stack *stack)
{
    return stack->index == MAX_SIZE - 1;
}

int isEmpty(struct Stack *stack)
{
    return stack->top == NULL;
}

void push(struct Stack *stack, struct Node *head)
{
    if (isFull(stack))
    {
        printf("Stack overflow! Cannot push element.\n");
    }
    else
    {
        stack->index++;
        stack->items[stack->index] = head;
        stack->top = head;
    }
}

struct Node *pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack underflow! Cannot pop element.\n");
        return NULL; // Return a special value indicating stack underflow
    }
    else
    {
        struct Node *poppedValue = stack->items[stack->index];
        stack->index--;
        stack->top = stack->items[stack->index];
        return poppedValue;
    }
}

struct Node *peek(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty! Cannot peek.\n");
        return NULL; // Return a special value indicating empty stack
    }
    else
    {
        return stack->top;
    }
}
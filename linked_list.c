#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node *head;
struct Node *prevHead;
struct Node *scopes[100];
int scopeIndex = 0;

void initializeList()
{
    head = (struct Node *)malloc(sizeof(struct Node));
    // prevHead = (struct Node *)malloc(sizeof(struct Node));
    head->name = "null";
    head->datatype = "null";
    head->type = "null";
    head->init = -1;
    head->lineNo = -1;
    head->next = NULL;
    scopes[scopeIndex] = head; // Global scope
}

// Function to create a new node with the given data and insert it at the end of the linked list
void createNode(char *name, char *datatype, char *type, int init, int lineNo)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        fprintf(stderr, "Failed to allocate memory for new node\n");
        exit(EXIT_FAILURE);
    }
    // printf("initialized: %s\n", init);
    newNode->name = strdup(name);
    newNode->datatype = strdup(datatype);
    newNode->type = strdup(type);
    newNode->init = init;
    // printf("node initialized: %s\n", newNode->init);
    newNode->lineNo = lineNo;
    newNode->next = NULL; // Initialize the next pointer to NULL
    printf("head->name: %s\n", head->name);
    if (strcmp(head->name, "null") == 0)
    {
        head = newNode;
        scopes[scopeIndex] = newNode;
    }
    else
    {
        struct Node *current = head;
        while (current->next != NULL)
        {
            current = current->next;
            printf("current->name: %s\n", current->name);
        }
        current->next = newNode;
    }
}

// Function to delete a node with the given data from the linked list
void deleteNode(char *name)
{
    struct Node *current = head;
    struct Node *prev = NULL;

    while (current != NULL && current->name != name)
    {
        prev = current;
        current = current->next;
    }

    if (current == NULL)
    {
        printf("Node with name %d not found\n", name);
        return;
    }

    if (prev == NULL)
    {
        // Node to be deleted is the head node
        head = current->next;
    }
    else
    {
        prev->next = current->next;
    }

    free(current); // Free memory occupied by the deleted node
}

// Function to display the linked list
void displayList()
{
    struct Node *current = head;
    printf("NAME, DATATYPE, TYPE, INITIALIZED, LINE NO\n");
    while (current != NULL)
    {

        printf("%s, %s, %s, %d, %d \n", current->name, current->datatype, current->type, current->init, current->lineNo);
        current = current->next;
    }
    printf("NULL\n");
}

void displayListStack(struct Node *node)
{
    struct Node *current = node;
    printf("NAME, DATATYPE, TYPE, INITIALIZED, LINE NO\n");
    while (current != NULL)
    {
        printf("%s, %s, %s, %d, %d", current->name, current->datatype, current->type, current->init, current->lineNo);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to free memory allocated for the linked list
void freeList()
{
    struct Node *current = head;
    while (current != NULL)
    {
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }
}

struct Node *search(char *name)
{
    struct Node *current = head;
    while (current != NULL)
    {
        if (strcmp(current->name, name) == 0)
        {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// void Head_for_push()
// {
//     prevHead = head;

//     struct Node *newhead = (struct Node *)malloc(sizeof(struct Node));
//     newhead->name = "null";
//     newhead->datatype = "null";
//     newhead->type = "null";
//     newhead->init = -1;
//     newhead->lineNo = -1;
//     newhead->next = NULL;

//     head = newhead;
// }
// void Head_for_pop()
// {
//     head = prevHead;
// }
void Head_for_push()
{
    prevHead = head;
    struct Node *newhead = (struct Node *)malloc(sizeof(struct Node));
    if (newhead == NULL)
    {
        fprintf(stderr, "Failed to allocate memory for new head node\n");
        exit(EXIT_FAILURE);
    }
    newhead->name = strdup("null");
    newhead->datatype = strdup("null");
    newhead->type = strdup("null");
    newhead->init = -1;
    newhead->lineNo = -1;
    newhead->next = head;
    head = newhead;
}

void Head_for_pop()
{
    if (prevHead == NULL)
    {
        fprintf(stderr, "Previous head is not set\n");
        exit(EXIT_FAILURE);
    }
    struct Node *temp = head;
    head = prevHead;
    free(temp);      // Free the memory of the previous head
    prevHead = NULL; // Reset prevHead
}

struct Node *getHead()
{
    return head;
}

void scopePush()
{
    scopeIndex++;
    Head_for_push();
    scopes[scopeIndex] = head;
}

void scopePop()
{
    scopeIndex--;
    Head_for_pop();
}

struct Node *searchScope(char *name)
{
    printf("scope index %d\n", scopeIndex);
    for (int i = scopeIndex; i >= 0; i--)
    {
        displayList();
        struct Node *current = scopes[i];
        printf("current->name = %s , name = %s , their comparison = %d", current->name, name, strcmp(current->name, name));
        while (current != NULL)
        {
            // printf("current->name = %s , name = %s , their comparison = %d", current->name, name, strcmp(current->name, name));
            if (strcmp(current->name, name) == 0)
            {
                return current;
            }
            current = current->next;
        }
    }
    return NULL;
}

// struct Node *searchScope(char *name)
// {
//     int iter = scopeIndex;

//     while (iter > -1)
//     {
//         struct Node *current = scopes[iter];
//         while (current != NULL)
//         {
//             if (strcmp(current->name, name) == 0)
//             {
//                 return current;
//             }
//             current = current->next;
//         }
//         iter--;
//     }
// }

void displayScope()
{
    for (int i = scopeIndex; i >= 0; i--)
    {
        struct Node *current = scopes[i];
        printf("===================Scope (%d): ==================\n", i);
        while (current != NULL)
        {
            printf("%s, %s, %s, %d, %d\n", current->name, current->datatype, current->type, current->init, current->lineNo);
            current = current->next;
        }
    }
}

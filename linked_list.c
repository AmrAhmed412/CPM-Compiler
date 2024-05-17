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
}

void write_file()
{
    // write the current linked list to a file
    FILE *f = fopen("symbol_table.txt", "a");
    if (f == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }
    struct Node *current = head;
    fprintf(f, "SCOPE %d\n", scopeIndex);
    fprintf(f, "NAME\t DATATYPE\t TYPE\t INITIALIZED\t LINE No.\n");
    while (current != NULL)
    {
        fprintf(f, "%s\t\t %s\t\t %s\t\t %d\t\t %d \n", current->name, current->datatype, current->type, current->init, current->lineNo);
        current = current->next;
    }
    fprintf(f, "=============================================================\n");
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
    newhead->next = NULL;
    head = newhead;
}

void Head_for_pop()
{
    head = scopes[scopeIndex];
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
    for (int i = scopeIndex; i >= 0; i--)
    {
        struct Node *current = scopes[i];
        while (current != NULL)
        {
            if (strcmp(current->name, name) == 0)
            {
                return current;
            }
            current = current->next;
        }
    }
    return NULL;
}


void displayScope()
{
    FILE *f = fopen("symbol_table.txt", "w");
    for (int i = scopeIndex; i >= 0; i--)
    {
        struct Node *current = scopes[i];
        fprintf(f,"===================Scope (%d): ==================\n", i);
        fprintf(f,"NAME\t DATATYPE\t TYPE\t INITIALIZED\t LINE No.\n");
        while (current != NULL)
        {
            fprintf(f,"%s %s %s %d %d\n", current->name, current->datatype, current->type, current->init, current->lineNo);
            current = current->next;
        }
    }
    fclose(f);
}

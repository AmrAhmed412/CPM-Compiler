#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

// Function to create a new node with the given data
struct Node *createNode(char *name, char *datatype, char *type, char *value, int lineNo)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        fprintf(stderr, "Failed to allocate memory for new node\n");
        exit(EXIT_FAILURE);
    }
    newNode->name = name;
    newNode->datatype = datatype;
    newNode->type = type;
    newNode->value = value;
    newNode->lineNo = lineNo;
    newNode->next = NULL; // Initialize the next pointer to NULL
    return newNode;
}

// Function to insert a new node at the beginning of the linked list
void insertAtBeginning(struct Node **head, char *name, char *datatype, char *type, char *value, int lineNo)
{
    struct Node *newNode = createNode(name, datatype, type, value, lineNo);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a new node at the end of the linked list
void insertAtEnd(struct Node **head, char *name, char *datatype, char *type, char *value, int lineNo)
{
    struct Node *newNode = createNode(name, datatype, type, value, lineNo);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct Node *current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to delete a node with the given data from the linked list
void deleteNode(struct Node **head, char *name)
{
    struct Node *current = *head;
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
        *head = current->next;
    }
    else
    {
        prev->next = current->next;
    }

    free(current); // Free memory occupied by the deleted node
}

// Function to display the linked list
void displayList(struct Node *head)
{
    struct Node *current = head;
    printf("NAME, DATATYPE, TYPE, VALUE, LINE NO\n");
    while (current != NULL)
    {
        printf("[%s, %s, %s, %s, %s] -> ", current->name, current->datatype, current->type, current->value, current->lineNo);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to free memory allocated for the linked list
void freeList(struct Node *head)
{
    struct Node *current = head;
    while (current != NULL)
    {
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }
}

struct Node *search(struct Node *head, char *name)
{
    struct Node *current = head;
    while (current != NULL)
    {
        if (current->name == name)
        {
            // printf("Node with name %s found\n", name);
            return current;
        }
        current = current->next;
    }
    printf("Node with name %s not found\n", name);
}

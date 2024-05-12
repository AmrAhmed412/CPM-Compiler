#ifndef LINKED_LIST_H
#define LINKED_LIST_H

// Define the structure for a node in the linked list
struct Node
{
    char *name;
    char *datatype;
    char *type; // variable, function, parameter,..etc
    char *value;
    char *lineNo;
    struct Node *next;
};

// Function prototypes for linked list operations

// Function to create a new node with the given data
struct Node *createNode(char *name, char *datatype, char *type, char *value, int lineNo);

// Function to insert a new node at the beginning of the linked list
void insertAtBeginning(struct Node **head, char *name, char *datatype, char *type, char *value, int lineNo);

// Function to insert a new node at the end of the linked list
void insertAtEnd(struct Node **head, char *name, char *datatype, char *type, char *value, int lineNo);

// Function to delete a node with the given data from the linked list
void deleteNode(struct Node **head, char *name);

// Function to display the linked list
void displayList(struct Node *head);

// Function to free memory allocated for the linked list
void freeList(struct Node *head);

struct Node *search(struct Node *head, char *name);

#endif

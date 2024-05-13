#ifndef LINKED_LIST_H
#define LINKED_LIST_H

// Define the structure for a node in the linked list
struct Node
{
    char *name;
    char *datatype;
    char *type; // variable, function, parameter,..etc
    char *value;
    int lineNo;
    struct Node *next;
};

// Function prototypes for linked list operations

// Function to create a new node with the given data
void createNode(char *name, char *datatype, char *type, char *value, int lineNo);

// Function to delete a node with the given data from the linked list
void deleteNode(char *name);

// Function to display the linked list
void displayList();

void displayListStack(struct Node *head);

// Function to free memory allocated for the linked list
void freeList();

void updateHead();

struct Node *search(char *name);
struct Node *getHead();

#endif

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

// Define the structure for a node in the linked list
struct Node
{
    char *name;
    char *datatype;
    char *type; // variable, function, parameter,..etc
    int init;
    int lineNo;

    struct Node *next;
};

// Function prototypes for linked list operations

// Function to create a new node with the given data
void initializeList();

void createNode(char *name, char *datatype, char *type, int init, int lineNo);

// Function to delete a node with the given data from the linked list
void deleteNode(char *name);

// Function to display the linked list
void displayList();

void write_file();

void displayListStack(struct Node *head);

// Function to free memory allocated for the linked list
void freeList();

struct Node *search(char *name);

void Head_for_push();
void Head_for_pop();

struct Node *getHead();
void scopePush();
void scopePop();
struct Node *searchScope(char *name);
void displayScope();

#endif

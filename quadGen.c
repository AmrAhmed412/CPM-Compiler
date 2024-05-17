#include "stack.h"
#include "quadGen.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 300

int global_T = 0; //for variables
int global_L = 0; //for jump

//list of quads
struct Quad quads[MAX_SIZE];
// struct Quad tempQuad[30];

// int temp_idx = 0;
int quad_idx = 0;

struct Stack *temp_stack;
struct Stack *else_stack;
struct Stack *while_stack;
struct Stack *for_stack;

void quad_init(){
    temp_stack = (struct Stack*)malloc(sizeof(struct Stack));
    initialize(temp_stack);
    else_stack = (struct Stack*)malloc(sizeof(struct Stack));
    initialize(else_stack);
    while_stack = (struct Stack*)malloc(sizeof(struct Stack));
    initialize(while_stack);
    for_stack = (struct Stack*)malloc(sizeof(struct Stack));
    initialize(for_stack);
}

void add_quad(char *op, char *arg1, char *arg2, char *result) {
    struct Quad quad;
    strcpy(quad.op, op);
    strcpy(quad.arg1, arg1);
    strcpy(quad.arg2, arg2);
    strcpy(quad.result, result);

    //apppend to global list
    quads[quad_idx++] = quad;
}

void print_quads() {
    //print non empty quads
    printf("Quads:\n");
    printf("op\targ1\targ2\tresult\n");
    for (int i = 0; i < quad_idx; i++) {
        struct Quad quad = quads[i];
        if (strcmp(quad.op, "") != 0) {
            printf("%s\t%s\t%s\t%s\n",quad.op, quad.arg1, quad.arg2, quad.result);
        }
    }
}

void inc_T_idx(){
    global_T++;
}

void inc_L_idx(){
    global_L++;
}

int get_T_idx(){
    return global_T;
}

int get_L_idx(){
    return global_L;
}


int get_last_T(char *T_id){
    //search for he quad above it the current T_idx is 
    struct Quad prev = quads[quad_idx-1];
    if(strcmp(prev.result, T_id) == 0){
        return 1;
    }
    return 0; //here i will need to inc the T_idx aka "use another temp"
}

char* buildTable_exp(char* op, char* arg1, char* arg2, int isAssign) {
    char str[20];
    sprintf(str, "%d", get_T_idx());
    char* T = (char*)malloc(20 * sizeof(char)); // Allocate memory for T dynamically
    strcpy(T, "T");
    strcat(T, str);
    add_quad(op, arg1, arg2, T);
    if (isAssign == 1) {
        add_quad("ASSIGN", T, "", arg2);
        // inc_T_idx();
    }
    inc_T_idx();
        
    // print_quads();
    return T;
}

void buildTable_assign(char* arg1, char* arg2){                              
    char str[20];
    sprintf(str, "%d", get_T_idx());
    char T [20] = "T";
    strcat(T,str);

    int useLast = get_last_T(T);
    if (useLast == 1)
    {
        add_quad("ASSIGN",T,"", arg1);
    }
    else
    {
        add_quad("ASSIGN",arg2,"", arg1);
    }
}



void CreateLabel(){
    char str[20];
    sprintf(str, "%d", get_L_idx());
    char L [20] = "L";
    strcat(L,str);
    add_quad("LABEL:",L,"","");
    push(temp_stack, get_L_idx());
    inc_L_idx();
}

void CreateLabelIF(){
    char str[20];
    sprintf(str, "%d", get_L_idx());
    char L [20] = "L";
    strcat(L,str);
    // add_quad("LABEL:",L,"","");
    push(temp_stack, get_L_idx()); //kda dh awl el else aka enter else
    inc_L_idx();
    push(else_stack, get_L_idx()); //efks el else 3and0 y3ny awl condition true
    inc_L_idx();
}


void CreateLabelWhile(){
    char str[20];
    sprintf(str, "%d", get_L_idx());
    char L [20] = "L";
    strcat(L,str);
    add_quad("LABEL:",L,"","");
    push(temp_stack, get_L_idx()); //for the jump back the while
    inc_L_idx();
    push(while_stack, get_L_idx()); //for the jump outside the while
    inc_L_idx();
}

void CreateLabelFor(){
    char str[20];
    sprintf(str, "%d", get_L_idx());
    char L [20] = "L";
    strcat(L,str);
    add_quad("LABEL:",L,"","");
    push(temp_stack, get_L_idx()); //3lashan atla3 tany lel statement
    inc_L_idx();
    push(for_stack, get_L_idx()); //3lashan lma el check yb2a false yro7 lel ba2y
    inc_L_idx();
}


int getStackTop(){
    return peek(temp_stack);
}

int getElseTop(){
    return peek(else_stack);
}

int getWhileTop(){
    return peek(while_stack);
}

int getForTop(){
    return peek(for_stack);
}

//pop from stack and return label

char* PopLabel(){
    int idx = pop(temp_stack);
    char str[20];
    sprintf(str, "%d", idx);
    char L [20] = "L";
    strcat(L,str);
    char* label = strdup(L); // Allocate memory and copy the string
    if (label == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    return label;
}

char* PopElseLabel(){
    int idx = pop(else_stack);
    char str[20];
    sprintf(str, "%d", idx);
    char L [20] = "L";
    strcat(L,str);
    char* label = strdup(L); // Allocate memory and copy the string
    if (label == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    return label;
}

char* PopWhileLabel(){
    int idx = pop(while_stack);
    char str[20];
    sprintf(str, "%d", idx);
    char L [20] = "L";
    strcat(L,str);
    char* label = strdup(L); // Allocate memory and copy the string
    if (label == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    return label;
}

char* PopForLabel(){
    int idx = pop(for_stack);
    char str[20];
    sprintf(str, "%d", idx);
    char L [20] = "L";
    strcat(L,str);
    char* label = strdup(L); // Allocate memory and copy the string
    if (label == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    return label;
}


void write_quad_to_file (){
    FILE *f = fopen("quads.txt", "w");
    if (f == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }
    fprintf(f, "OP\targ1\targ2\tresult\n");
    for (int i = 0; i < quad_idx; i++)
    {
        struct Quad quad = quads[i];
        if (strcmp(quad.op, "") != 0)
        {
            fprintf(f, "%s, %s, %s, %s\n", quad.op, quad.arg1, quad.arg2, quad.result);
        }
    }
    fclose(f);
}


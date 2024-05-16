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

void add_quad(char *op, char *arg1, char *arg2, char *result) {
    struct Quad quad;
    strcpy(quad.op, op);
    strcpy(quad.arg1, arg1);
    strcpy(quad.arg2, arg2);
    strcpy(quad.result, result);

    //apppend to global list
    quads[quad_idx++] = quad;
}

// void add_temp_quad(char *op, char *arg1, char *arg2, char *result) {
//     struct Quad quad;
//     strcpy(quad.op, op);
//     strcpy(quad.arg1, arg1);
//     strcpy(quad.arg2, arg2);
//     strcpy(quad.result, result);

//     //apppend to global list
//     tempQuad[temp_idx++] = quad;
// }


// void flush_temp() {
//     for (int i = 0; i < temp_idx; i++) {
//         struct Quad quad = tempQuad[i];
//         if (strcmp(quad.op, "") == 0) {
//             break;
//         }
//         add_quad(quad.op, quad.arg1, quad.arg2, quad.result);
//     }
//     temp_idx = 0;
// }

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
        printf("arg1 = %s\n", arg1);
        printf("arg2 = %s\n", arg2);
        printf("T = %s\n", T);
        add_quad(":=", T, "", arg2);
    }
    // print_quads();
    inc_T_idx();
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
        add_quad(":=",T,"", arg1);
    }
    else
    {
        add_quad(":=",arg2,"", arg1);
    }
}


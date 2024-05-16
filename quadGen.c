#include "quadGen.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>+

#define MAX_SIZE 300

int global_T = 0; //for variables
int global_L = 0; //for jump

//list of quads
struct Quad quads[MAX_SIZE];
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

void print_quads() {
    //loop till the last element in list of quads
    printf("Quads Table:\n");
    printf("Op\tArg1\tArg2\tResult\n");

    for (int i = 0; i < MAX_SIZE; i++) {
        //if the quad is empty, break
        if (quads[i].op == NULL) {
            break;
        }
        //print the quad
        printf("%s\t%s\t%s\t%s\n", quads[i].op, quads[i].arg1, quads[i].arg2, quads[i].result);
    }
}

int get_T_idx(){
    return global_T++;
}

int get_L_idx(){
    return global_L++;
}
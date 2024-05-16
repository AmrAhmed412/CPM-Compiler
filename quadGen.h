#ifndef QUADGEN_H
#define QUADGEN_H


// Define a function or a class here
struct Quad {
    char op[10];
    char arg1[10];
    char arg2[10];
    char result[10];
};

void add_quad(char *op, char *arg1, char *arg2, char *result);

int get_T_idx();
int get_L_idx();

void print_quads();

#endif

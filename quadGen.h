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
// void add_temp_quad(char *op, char *arg1, char *arg2, char *result);


void flush_temp();

int get_last_T(char *T_id);
// int get_last_T_inTemp(char *T_id);

void inc_T_idx();
void inc_L_idx();

int get_T_idx();
int get_L_idx();

void print_quads();

char* buildTable_exp(char* op, char* arg1, char* arg2, int isAssign);
void buildTable_assign(char* arg1, char* arg2);
#endif

#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h> // For malloc and free
#include <string.h>

/////////////////////////// COMPARATOR FUNCTIONS ///////////////////////////

int boolchecker(char *type, int var_init);
int cmp_diff_types1(char *var_type, int var_init1, int val_type);
int cmp_diff_types2(int val_type, char *var_type, int var_init2);
int cmp(int type1, char *var_type1, int var_init1, int type2, char *var_type2, int var_init2);
int express(int op, int type1, char *var_type1, int var_init1, int type2, char *var_type2, int var_init2);
char *value_int_to_string_util(int value);
/////////////////////////// EXPRESSION FUNCTIONS ///////////////////////////

#endif
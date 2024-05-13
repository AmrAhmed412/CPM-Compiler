#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h> // For malloc and free
#include <string.h>

int boolchecker(char *type, char *var_val);
int cmp_values_bool(int op, int var_val1, int var_val2);
int cmp_values_int(int op, int var_val1, int var_val2);
int cmp_values_float(int op, float var_val1, float var_val2);
int cmp_values_char(int op, char var_val1, char var_val2);
int cmp_diff_types2(int op, int val_type, char *var_val1, char *var_type, char *var_val2);
int cmp_diff_types1(int op, int val_type, char *var_val1, char *var_type, char *var_val2);
int cmp_two_vals(int op, int type1, char *var_val1, int type2, char *var_val2);
int cmp_two_vars(int op, char *var_val1, char *var_type1, char *var_val2, char *var_type2);
int cmp(int op, int type1, char *var_val1, char *var_type1, int type2, char *var_val2, char *var_type2);

#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int boolchecker(char *type, char *var_val)
{
    if (strcmp(var_val, "N/A") != 0)
    {
        if (strcmp(type, "bool") == 0)
        {
            return 1;
        }
        else if (strcmp(type, "int") == 0)
        {
            if (atoi(var_val) == 0 || atoi(var_val) == 1)
            {
                return 1;
            }
        }
    }
    return 0;
}
int cmp_values_bool(int op, int var_val1, int var_val2) // zpecial case
{
    if (op == 1)
    {
        return var_val1 == var_val2;
    }
    else if (op == 2)
    {
        return var_val1 != var_val2;
    }
    else
    {
        return -1;
    }
}
int cmp_values_int(int op, int var_val1, int var_val2)
{
    if (op == 1)
    {
        return var_val1 == var_val2;
    }
    else if (op == 2)
    {
        return var_val1 != var_val2;
    }
    else if (op == 3)
    {
        return var_val1 > var_val2;
    }
    else if (op == 4)
    {
        return var_val1 < var_val2;
    }
    else if (op == 5)
    {
        return var_val1 >= var_val2;
    }
    else if (op == 6)
    {
        return var_val1 <= var_val2;
    }
    else
    {
        return -1;
    }
}
int cmp_values_float(int op, float var_val1, float var_val2)
{
    if (op == 1)
    {
        return var_val1 == var_val2;
    }
    else if (op == 2)
    {
        return var_val1 != var_val2;
    }
    else if (op == 3)
    {
        return var_val1 > var_val2;
    }
    else if (op == 4)
    {
        return var_val1 < var_val2;
    }
    else if (op == 5)
    {
        return var_val1 >= var_val2;
    }
    else if (op == 6)
    {
        return var_val1 <= var_val2;
    }
    else
    {
        return -1;
    }
}
int cmp_values_char(int op, char var_val1, char var_val2)
{
    if (op == 1)
    {
        return var_val1 == var_val2;
    }
    else if (op == 2)
    {
        return var_val1 != var_val2;
    }
    else if (op == 3)
    {
        return var_val1 > var_val2;
    }
    else if (op == 4)
    {
        return var_val1 < var_val2;
    }
    else if (op == 5)
    {
        return var_val1 >= var_val2;
    }
    else if (op == 6)
    {
        return var_val1 <= var_val2;
    }
    else
    {
        return -1;
    }
}
int cmp_diff_types2(int op, int val_type, char *var_val1, char *var_type, char *var_val2)
{
    if (val_type == 2 && strcmp(var_type, "int") == 0)
    {
        return cmp_values_int(op, atoi(var_val1), atoi(var_val2));
    }
    else if (val_type == 3 && strcmp(var_type, "float") == 0)
    {
        return cmp_values_float(op, atof(var_val1), atof(var_val2));
    }
    else if (val_type == 5 && strcmp(var_type, "char") == 0)
    {
        return cmp_values_char(op, var_val1[0], var_val2[0]);
    }
    else if (val_type == 6 && strcmp(var_type, "bool") == 0)
    {
        return cmp_values_bool(op, atoi(var_val1), atoi(var_val2));
    }
    else
    {
        return -1;
    }
}
int cmp_diff_types1(int op, int val_type, char *var_val1, char *var_type, char *var_val2)
{
    if (val_type == 2 && strcmp(var_type, "int") == 0)
    {
        return cmp_values_int(op, atoi(var_val2), atoi(var_val1));
    }
    else if (val_type == 3 && strcmp(var_type, "float") == 0)
    {
        return cmp_values_float(op, atof(var_val2), atof(var_val1));
    }
    else if (val_type == 5 && strcmp(var_type, "char") == 0)
    {
        return cmp_values_char(op, var_val2[0], var_val1[0]);
    }
    else if (val_type == 6 && strcmp(var_type, "bool") == 0)
    {
        return cmp_values_bool(op, atoi(var_val2), atoi(var_val1));
    }
    else
    {
        return -1;
    }
}
int cmp_two_vals(int op, int type1, char *var_val1, int type2, char *var_val2)
{

    if (type1 == 2)
    {
        return cmp_values_int(op, atoi(var_val1), atoi(var_val2));
    }
    else if (type1 == 3)
    {
        return cmp_values_float(op, atof(var_val1), atof(var_val2));
    }
    else if (type1 == 5)
    {
        return cmp_values_char(op, var_val1[0], var_val2[0]);
    }
    else if (type1 == 6)
    {
        return cmp_values_bool(op, atoi(var_val1), atoi(var_val2));
    }
    return -1;
}
int cmp_two_vars(int op, char *var_val1, char *var_type1, char *var_val2, char *var_type2)
{
    if (strcmp(var_type1, var_type2) == 0)
    {
        if (strcmp(var_type1, "int") == 0)
        {
            return cmp_values_int(op, atoi(var_val1), atoi(var_val2));
        }
        else if (strcmp(var_type1, "float") == 0)
        {
            return cmp_values_float(op, atof(var_val1), atof(var_val2));
        }
        else if (strcmp(var_type1, "char") == 0)
        {
            return cmp_values_char(op, var_val1[0], var_val2[0]);
        }
        else if (strcmp(var_type1, "bool") == 0)
        {
            return cmp_values_bool(op, atoi(var_val1), atoi(var_val2));
        }
    }
    return -1;
}

int cmp(int op, int type1, char *var_val1, char *var_type1, int type2, char *var_val2, char *var_type2) // make all input values(var_val) into strings
{
    if (type1 == type2)
    {
        if (type1 > 1)
        {
            return cmp_two_vals(op, type1, var_val1, type2, var_val2);
        }
        else if (type1 == 1)
        {
            return cmp_two_vars(op, var_val1, var_type2, var_val2, var_type2);
        }
    }
    else if (type1 == 1)
    {
        return cmp_diff_types1(op, type2, var_val2, var_type1, var_val1);
    }
    else if (type2 == 1)
    {
        return cmp_diff_types2(op, type1, var_val1, var_type2, var_val2);
    }
    return -1;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int boolchecker(char *type, int var_init)
{
    if (var_init != 0)
    {
        if (strcmp(type, "bool") == 0)
        {
            return 1;
        }
    }
    return 0;
}

int cmp_diff_types2(int val_type, char *var_type, int var_init2)
{
    if (var_init2 == 0)
    {
        printf("ERROR: Variable not initialized\n");
        return 0;
    }
    if (val_type == 2 && strcmp(var_type, "int") == 0)
    {
        return 1;
    }
    else if (val_type == 3 && strcmp(var_type, "float") == 0)
    {
        return 1;
    }
    else if (val_type == 5 && strcmp(var_type, "char") == 0)
    {
        return 1;
    }
    else if (val_type == 6 && strcmp(var_type, "bool") == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int cmp_diff_types1(char *var_type, int var_init1, int val_type)
{
    if (var_init1 == 0)
    {
        printf("ERROR: Variable not initialized\n");
        return 0;
    }
    if (val_type == 2 && strcmp(var_type, "int") == 0)
    {
        return 1;
    }
    else if (val_type == 3 && strcmp(var_type, "float") == 0)
    {
        return 1;
    }
    else if (val_type == 5 && strcmp(var_type, "char") == 0)
    {
        return 1;
    }
    else if (val_type == 6 && strcmp(var_type, "bool") == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int cmp(int type1, char *var_type1, int var_init1, int type2, char *var_type2, int var_init2) // make all input values(var_val) into strings
{
    if (type1 == type2)
    {
        if (type1 > 1)
        {
            return 1;
        }
        else if (type1 == 1)
        {
            if (strcmp(var_type1, var_type2) == 0)
            {
                return 1;
            }
            return 0;
        }
    }
    else if (type1 == 1)
    {
        return cmp_diff_types1(var_type1, var_init1, type2);
    }
    else if (type2 == 1)
    {
        return cmp_diff_types2(type1, var_type2, var_init2);
    }
    return 0;
}
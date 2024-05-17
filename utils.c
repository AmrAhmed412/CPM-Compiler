#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *exp_ops[4] = {"add", "subtract", "multiply", "divide"};

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
        const char *filename = "symbol_table.txt";
    
    // Open the file in write mode to clear its contents
    FILE *file = fopen(filename, "w");
    
    if (file == NULL) {
        perror("Failed to open file");
        return 1;
    }
        fprintf(file, "ERROR: Variable not initialized\n");
    // Close the file
    fclose(file);
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
        const char *filename = "symbol_table.txt";
    
    // Open the file in write mode to clear its contents
    FILE *file = fopen(filename, "w");
    
    if (file == NULL) {
        perror("Failed to open file");
        return 1;
    }
        fprintf(file,"ERROR: Variable not initialized\n");
    // Close the file
    fclose(file);

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

char *value_int_to_string_util(int value)
{
    char *output = (char *)malloc(10);
    if (value == 2)
        return "int";
    else if (value == 3)
        return "float";
    else if (value == 4)
        return "string";
    else if (value == 5)
        return "char";
    else if (value == 6)
        return "bool";
}

int express(int op, int type1, char *var_type1, int var_init1, int type2, char *var_type2, int var_init2)
{
    // char* error = "\0";
    if (type1 == type2)
    {
        if (type1 == 1)
        {
            if (var_init1 == 1 && var_init2 == 1)
            {
                if (strcmp(var_type1, var_type2) != 0)
                {
                    const char *filename = "symbol_table.txt";
    
    // Open the file in write mode to clear its contents
    FILE *file = fopen(filename, "w");
    
    if (file == NULL) {
        perror("Failed to open file");
        return 1;
    }
                    fprintf(file, "Cannot %s different data types\n", exp_ops[op]);
    // Close the file
    fclose(file);
                    return 0;
                }
            }
            else
            {
                printf("Cannot %s uninitialized variables\n", exp_ops[op]);
                return 0;
            }
        }
        else
        {
            if (!(type1 == 2 || type1 == 3))
            {
                const char *filename = "symbol_table.txt";
    
    // Open the file in write mode to clear its contents
    FILE *file = fopen(filename, "w");
    
    if (file == NULL) {
        perror("Failed to open file");
        return 1;
    }
                fprintf(file, "Cannot %s non numeric values\n");
    
    // Close the file
    fclose(file);
                return 0;
            }
        }
    }
    else
    {
        if (type1 == 1)
        {
            if (var_init1 == 1)
            {
                if (type2 == 2 || type2 == 3)
                {
                    if (strcmp(var_type1, value_int_to_string_util(type2)) != 0)
                    {
                        const char *filename = "symbol_table.txt";
    
    // Open the file in write mode to clear its contents
    FILE *file = fopen(filename, "w");
    
    if (file == NULL) {
        perror("Failed to open file");
        return 1;
    }
                        fprintf(file, "Cannot %s different data types\n");
    // Close the file
    fclose(file);
                        return 0;
                    }
                }
                else
                {
                    const char *filename = "symbol_table.txt";
    
    // Open the file in write mode to clear its contents
    FILE *file = fopen(filename, "w");
    
    if (file == NULL) {
        perror("Failed to open file");
        return 1;
    }
                    fprintf(file, "Cannot %s non numeric values\n");

    // Close the file
    fclose(file);
                    return 0;
                }
            }
            else
            {
                const char *filename = "symbol_table.txt";
    
    // Open the file in write mode to clear its contents
    FILE *file = fopen(filename, "w");
    
    if (file == NULL) {
        perror("Failed to open file");
        return 1;
    }
                fprintf(file, "Cannot %s uninitialized variables\n");

    // Close the file
    fclose(file);
                return 0;
            }
        }
        else
        {
            if (type1 == 2 || type1 == 3)
            {
                if (type2 == 1)
                {
                    if (var_init2 == 1)
                    {
                        if (strcmp(var_type2, value_int_to_string_util(type1)) != 0)
                        {
                            const char *filename = "symbol_table.txt";
    
    // Open the file in write mode to clear its contents
    FILE *file = fopen(filename, "w");
    
    if (file == NULL) {
        perror("Failed to open file");
        return 1;
    }
                            fprintf(file, "Cannot %s different data types\n");
    // Close the file
    fclose(file);
                            return 0;
                        }
                    }
                }
                else
                {
                    const char *filename = "symbol_table.txt";
    
    // Open the file in write mode to clear its contents
    FILE *file = fopen(filename, "w");
    
    if (file == NULL) {
        perror("Failed to open file");
        return 1;
    }
                    fprintf(file, "Cannot %s non numeric values\n");
    // Close the file
    fclose(file);
                    return 0;
                }
            }
        }
    }
    return 1;
}
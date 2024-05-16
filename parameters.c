#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PARAMETERS 100

char *names[MAX_PARAMETERS];
char *datatypes[MAX_PARAMETERS];
int count = 0;
int idx = 0;
int param_value_type[MAX_PARAMETERS]; // datatype of variable
char *param_var_type[MAX_PARAMETERS]; // name of variable
int param_var_init[MAX_PARAMETERS];   // if variable is initialized or not

void addParameter(char *datatype, char *name)
{
    if (count >= MAX_PARAMETERS)
    {
        printf("Maximum number of parameters exceeded\n");
        return;
    }
    names[count] = strdup(name);
    datatypes[count] = strdup(datatype);
    count++;
}

void clear()
{
    for (int i = 0; i < count; i++)
    {
        free(names[i]);
        free(datatypes[i]);
    }
    count = 0;
}

char *convert_to_string()
{
    char *temp = malloc(sizeof(char) * 1024); // Assuming a maximum length for the string
    if (temp == NULL)
    {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    temp[0] = '\0'; // Initialize the string
    for (int i = 0; i < count; i++)
    {
        printf("Datatype: %s\n", datatypes[i]);
        strcat(temp, datatypes[i]);
        strcat(temp, " ");
    }
    return temp;
}

void display()
{
    for (int i = 0; i < count; i++)
    {
        printf("%s %s", datatypes[i], names[i]);
    }
}

int get_count()
{
    return count;
}

char **get_names()
{
    return names;
}

char **get_datatypes()
{
    return datatypes;
}

int func_type_check(char *var_datatype, char *func_datatype)
{
    char *arrow = strchr(func_datatype, '>');
    int index = (int)(arrow - func_datatype) + 1;
    int len = strlen(func_datatype) - index + 1;
    char *output = (char *)malloc(len);
    strncpy(output, func_datatype + (index), len);
    // printf("output: %s\n", output);
    if (strcmp(output, "void") == 0)
    {
        // printf("output: %s\n", output);

        // printf("Var datatype: %s\n", var_datatype);
        if (strlen(var_datatype) != 0)
        {
            printf("Void function cannot be assigned to a variable\n");
            return 0;
        }
    }
    else if (strcmp(var_datatype, output) != 0)
    {
        printf("Output datatype mismatch\n");
        return 0;
    }
    return 1;
}

int func_input_check(char *func_datatype, char *input_datatype, int input_idx)
{
    char *arrow = strchr(func_datatype, '=');
    int index = 0;
    int len = (int)(arrow - func_datatype);
    char *input = (char *)malloc(len);

    strncpy(input, func_datatype, len);
    if (len != 0)
    {
        const char delim[] = " ";
        char *token = strtok(input, delim);
        char *tokens[100];
        int iter = 0;
        while (token != NULL)
        {
            tokens[iter] = token;
            // printf("token: %s ,%d\n", tokens[iter], iter); // int int =>int
            iter++;
            token = strtok(NULL, delim); // Get the next token
        }
        // printf("input_data: %s , token: %s\n", input_datatype, tokens[input_idx]);
        if (strcmp(input_datatype, tokens[input_idx]) != 0)
        {
            printf("Datatype mismatch in index: %d\n", input_idx);
            return 0;
        }
    }
    else
    {
        printf("No input parameters\n");
        return 0;
    }
    return 1;
}

char *value_int_to_string(int value)
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

int get_index()
{
    return idx;
}

void addCallParams(int value_type, char *var_type, int var_init)
{
    param_value_type[idx] = value_type;
    param_var_type[idx] = var_type;
    param_var_init[idx] = var_init;
    idx++;
}

int *get_param_value_type()
{
    return param_value_type;
}

char **get_param_var_type()
{
    return param_var_type;
}

int *get_param_var_init()
{
    return param_var_init;
}

void set_index(int value)
{
    idx = value;
}

void clear_call_params()
{
    for (int i = 0; i < idx; i++)
    {
        param_var_type[i] = NULL;
        param_value_type[i] = 0;
        param_var_init[i] = 0;
    }
    idx = 0;
}

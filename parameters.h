#ifndef PARAMETERS_H
#define PARAMETERS_H

void addParameter(char *datatype, char *name);
void clear();
char *convert_to_string();
void display();
int get_count();
char **get_names();
char **get_datatypes();
int func_type_check(char *var_datatype, char *func_datatype);
int func_input_check(char *func_datatype, char *input_datatype, int input_idx);
char *value_int_to_string(int value);
int get_index();
void addCallParams(int value_type, char *var_type, int var_init, char *var_name);
int *get_param_value_type();
char **get_param_var_type();
int *get_param_var_init();
char **get_param_var_name();
void set_index(int value);
void clear_call_params();

#endif
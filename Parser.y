%{
    int yyerror(char *s); 
    int yylex(void);
    #include <stdio.h>
	#include <stdlib.h>
	#include <stdarg.h>
	#include <string.h>	
    #include "linked_list.h"
    #include "utils.h"
    #include "parameters.h"
    #include "quadGen.h"
    // #include "stack.h"


    
    int line=1;
    

%}
%union{
	int integerval;                /* integer value */
    int boolval;              /* boolean value      */
	float floatval;               /* float Value    */
	char  charval;              /* character value  */
    char* type;                     /* data type    */
    char* stringval;            /* string value    */
    char* varval ;            /* VARIABLE Value    */
    char* compare;             /* comparison value    */

    struct {
    int value_type; //1-6 for variable, int, float, string, char, bool
    int var_init;   //if variable is initialized or not
    char* var_type; //datatype of variable
    char* var_name; //name of variable
    char* RegQuad; //last reg used in quadS
    }terminal_values; /* terminal values */

    struct {
   

    }callParameters;

    

}
        //Data Types
%token <type> INT FLOAT STRING CHAR CONST VOID BOOL 
/* %token ENUM */
        //Keywords
%token IF ELSE WHILE FOR SWITCH CASE DEFAULT BREAK CONTINUE RETURN REPEAT UNTIL
        

        //Values     
%token  <stringval> STRING_LITERAL 
%token  <charval> CHAR_LITERAL 
%token  <integerval> INTEGER_LITERAL 
%token  <floatval> FLOAT_LITERAL
%token  <boolval> BOOLEAN_TRUE 
%token  <boolval> BOOLEAN_FALSE 

%type <type> typeSpecifier
%type <terminal_values> values
%type <terminal_values> variableValue
/* %type <terminal_values> factor */
/* %type <terminal_values> term */
%type <terminal_values> expression
%type <compare> comparators
%type <callParameters> callParameters

        //Variable
%token  <varval> VARIABLE

        //Mathematical Operators
%token PLUS MINUS MULTIPLY DIVIDE 

        //Logical Operators
%token AND OR NOT

        //Relational Operators
%token EQUAL NOT_EQUAL GREATER LESS GREATER_EQUAL LESS_EQUAL 

        //Assignment Operator   
%token ASSIGN PLUS_ASSIGN MINUS_ASSIGN MULTIPLY_ASSIGN DIVIDE_ASSIGN 


// Associativity
%left ASSIGN
%left GREATER LESS
%left GREATER_EQUAL LESS_EQUAL
%left EQUAL NOT_EQUAL
%left AND OR NOT
%left PLUS MINUS 
%left MULTIPLY DIVIDE
%left PLUS_ASSIGN MINUS_ASSIGN MULTIPLY_ASSIGN DIVIDE_ASSIGN 

 

%%

program:              {printf("Empty Program ;-;\n");}      
    | programStatements     { printf("Program\n");};                  

programStatements:         
      statement programStatements                               {printf("Program statements\n");}
    | function functionScope programStatements { display();} 
    | function  functionScope {printf("Function Declaration with no parameters\n");}      
    | statement
    ;

function:
typeSpecifier VARIABLE '(' parameters ')'                   {
                                                                struct Node *node = searchScope($2);
                                                                if(node!=NULL)
                                                                {
                                                                    printf("Function already declared\n");
                                                                }
                                                                else
                                                                {
                                                                    char *temp = malloc(sizeof(char) * 1024);
                                                                    temp[0]='\0';
                                                                    strcat(temp,convert_to_string());
                                                                    strcat(temp,"=>");
                                                                    strcat(temp,$1);
                                                                    createNode($2,temp,"function",-1,line);
                                                                    line++;
                                                                    scopePush();
                                                                    char** names = get_names();
                                                                    char** datatypes = get_datatypes();
                                                                    int count = get_count();
                                                                    for (int i=0;i<count;i++)
                                                                    {
                                                                        createNode(names[i],datatypes[i],"variable",1,line);
                                                                    }
                                                                    line++;
                                                                    free(temp);
                                                                    clear();
                                                                }
                                                            }
| typeSpecifier VARIABLE '('')'                 {
                                                    struct Node *node = searchScope($2);
                                                    if(node!=NULL)
                                                    {
                                                        printf("Function already declared\n");
                                                    }
                                                    else
                                                    {
                                                        char *temp = malloc(sizeof(char) * 1024);
                                                        temp[0]='\0';
                                                        strcat(temp,"=>");
                                                        strcat(temp,$1);
                                                        createNode($2,temp,"function",-1,line);
                                                        line++;
                                                        scopePush();
                                                        free(temp);
                                                    }
                                                }
;

functionScope:
    '{' inBlockscope closeScope
;

openScope:
    '{' {
            scopePush();
            //create label for the scope
            CreateLabel();
        }
    ;
closeScope:
    '}' {   

            printf("==============Symbol Table before popping==============\n");
            // displayList();
            write_file();
            scopePop();
        }
    ;


inBlockscope:
     inBlockscope statement    {printf("Block Scope\n");}
    |statement 
    ;

statement:                 
    declaration ';'           {}
    | assignment ';'        {} 
    | ifStatement           {printf("If Statement\n");}
    | whileStatement        {printf("While Statement\n");}
    | forStatement          {printf("For Statement\n");} 
    | switchStatement       {printf("Switch Statement\n");}
    | returnStatement       {printf("Return Statement\n");}
    | repeatUntilStatement  {printf("Repeat Until Statement from statement\n");}
    | functionCall       {printf("Function Call\n");}
    | BREAK ';'        {printf("Break\n");}
    | CONTINUE ';'      {printf("Continue\n");}
    | error ';'     { yyerrok; }
    ;  

functionCall:

    VARIABLE ASSIGN VARIABLE '('')' ';'             {
                                                        struct Node* temp = searchScope($1);
                                                        if (temp ==NULL)
                                                        {
                                                            printf("Variable not declared\n");
                                                        }
                                                        else
                                                        {
                                                            struct Node* temp2 = searchScope($3);
                                                            if (temp2 ==NULL)
                                                            {
                                                                printf("Function not declared\n");
                                                            }
                                                            else
                                                            {
                                                                int good = func_type_check(temp->datatype,temp2->datatype);
                                                                if(good){
                                                                    char *equal = strchr(temp2->datatype, '=');
                                                                    int index = (int)(equal - temp2->datatype);
                                                                    if (index!=0)
                                                                    {
                                                                        printf("Function's parameters are not passed to the function\n");
                                                                    }
                                                                    else
                                                                    {
                                                                        add_quad("CALL", $3, "0", "");
                                                                    }
                                                                }
                                                            }
                                                            line++;
                                                        }
                                                    }
    | VARIABLE ASSIGN VARIABLE '(' callParameters ')' ';'   {   
                                                                struct Node* temp = searchScope($1);
                                                                if (temp ==NULL)
                                                                {
                                                                    printf("Variable not declared\n");
                                                                }
                                                                else
                                                                {
                                                                    struct Node* temp2 = searchScope($3);
                                                                    if (temp2 ==NULL)
                                                                    {
                                                                        printf("Function not declared\n");
                                                                    }
                                                                    else
                                                                    {
                                                                        int good = func_type_check(temp->datatype,temp2->datatype);
                                                                        if(good){
                                                                            int idx = get_index();
                                                                            int* param_value_type = get_param_value_type();
                                                                            char **param_var_type = get_param_var_type();
                                                                            int *param_var_init = get_param_var_init();
                                                                            char **param_var_name = get_param_var_name();
                                                                            int flag = 1;
                                                                            int good_in;
                                                                            for (int i=0;i<idx;i++)
                                                                            {
                                                                                if (param_value_type[i]==1)
                                                                                {
                                                                                    if (param_var_init[i]==0)
                                                                                    {
                                                                                        printf("Variable not initialized\n");
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        printf("Variable: %s\n",param_var_type[i]);
                                                                                        good_in = func_input_check(temp2->datatype,param_var_type[i],i);
                                                                                        flag = flag && good_in;

                                                                                    }

                                                                                }
                                                                                else
                                                                                {   
                                                                                    char *val_type = value_int_to_string(param_value_type[i]);
                                                                                    printf("Variable: %s\n",val_type);
                                                                                    good_in = func_input_check(temp2->datatype,val_type,i);
                                                                                    flag = flag && good_in;
                                                                                }
                                                                            }
                                                                            if (flag == 1){
                                                                                for (int i=0;i<idx;i++)
                                                                                {
                                                                                    add_quad("PARAM", param_var_name[i], "", "");
                                                                                }
                                                                            }
                                                                            char id_call[20];
                                                                            sprintf(id_call,"%d",idx);
                                                                            add_quad("CALL", $3, id_call, "");
                                                                            clear_call_params();
                                                                        }
                                                                    }
                                                                }
                                                                line++;

                                                            }
    | VARIABLE '(' ')' ';'  {   
                                struct Node* temp = searchScope($1);
                                if (temp ==NULL)
                                {
                                    printf("Function not declared\n");
                                }
                                else
                                {
                                    int good = func_type_check("",temp->datatype);
                                    if (good){
                                        char *equal = strchr(temp->datatype, '=');
                                        int index = (int)(equal - temp->datatype);
                                        if (index!=0)
                                        {
                                            printf("Function's parameters are not passed to the function\n");
                                        }
                                        else
                                        {
                                            add_quad("CALL", $1, "0", "");
                                        }
                                    }
                                }
                                line++;
                            }
    | VARIABLE '(' callParameters ')' ';'   {
                                                struct Node* temp = searchScope($1);
                                                if (temp ==NULL)
                                                {
                                                    printf("Function not declared\n");
                                                }
                                                else
                                                {
                                                   int flag =  func_type_check("",temp->datatype);
                                                   if (flag !=0)
                                                   {
                                                        int idx = get_index();
                                                        int* param_value_type = get_param_value_type();
                                                        char **param_var_type = get_param_var_type();
                                                        int *param_var_init = get_param_var_init();
                                                        char **param_var_name = get_param_var_name();
                                                        int flag = 1;
                                                        int good_in;
                                                        for (int i=0;i<idx;i++)
                                                        {
                                                            if (param_value_type[i]==1)
                                                            {
                                                                if (param_var_init[i]==0)
                                                                {
                                                                    printf("Variable not initialized\n");
                                                                }
                                                                else
                                                                {
                                                                    printf("Variable: %s\n",param_var_type[i]);
                                                                    good_in = func_input_check(temp->datatype,param_var_type[i],i);
                                                                    flag = flag && good_in;
                                                                }
                                                            }
                                                            else
                                                            {   
                                                                char *val_type = value_int_to_string(param_value_type[i]);
                                                                printf("Variable: %s\n",val_type);
                                                                good_in =  func_input_check(temp->datatype,val_type,i);
                                                                flag = flag && good_in;
                                                            }
                                                        }
                                                        if (flag == 1){
                                                            for (int i=0;i<idx;i++)
                                                            {
                                                                add_quad("PARAM", param_var_name[i], "", "");
                                                            }
                                                        }
                                                        line++;
                                                        char id_call2[20];
                                                        sprintf(id_call2,"%d",idx);
                                                        add_quad("CALL", $1, id_call2, "");
                                                        clear_call_params();
                                                   }
                                                   
                                                }
                                                line++;
                                            }
    | typeSpecifier VARIABLE ASSIGN VARIABLE '(' ')' ';'    {
                                                                struct Node* temp = searchScope($2);
                                                                if (temp ==NULL)
                                                                {
                                                                    struct Node* temp2 = searchScope($4);
                                                                    if (temp2 ==NULL)
                                                                    {
                                                                        printf("Function not declared\n");
                                                                    }
                                                                    else
                                                                    {
                                                                        int flag =func_type_check($1,temp2->datatype);
                                                                        if (flag !=0)
                                                                        {
                                                                            char *equal = strchr(temp2->datatype, '=');
                                                                            int index = (int)(equal - temp2->datatype);
                                                                            if (index!=0)
                                                                            {
                                                                                printf("Function's parameters are not passed to the function\n");
                                                                            }
                                                                            else
                                                                            {
                                                                                createNode($2,$1,"variable",1,line);
                                                                                char str[20];
                                                                                sprintf(str, "%d", get_T_idx());
                                                                                char* T = (char*)malloc(20 * sizeof(char)); // Allocate memory for T dynamically
                                                                                strcpy(T, "T");
                                                                                strcat(T, str);
                                                                                add_quad("CALL", $4, "0", T);
                                                                                add_quad("ASSIGN", T, "", $2);
                                                                                inc_T_idx();
                                                                                

                                                                            }
                                                                        }
                                                                       
                                                                    }
                                                                }
                                                                else
                                                                {
                                                                    printf("Variable already declared\n");
                                                                }
                                                                line++;
                                                            }
| typeSpecifier VARIABLE ASSIGN VARIABLE '(' callParameters ')' ';'    
                                                            {
                                                                struct Node* temp = searchScope($2);
                                                                if (temp ==NULL)
                                                                {
                                                                    struct Node* temp2 = searchScope($4);
                                                                    if (temp2 ==NULL)
                                                                    {
                                                                        printf("Function not declared\n");
                                                                    }
                                                                    else
                                                                    {
                                                                        int flag =func_type_check($1,temp2->datatype);
                                                                        if (flag !=0)
                                                                        {
                                                                            int idx = get_index();
                                                                            int* param_value_type = get_param_value_type();
                                                                            char **param_var_type = get_param_var_type();
                                                                            int *param_var_init = get_param_var_init();
                                                                            char **param_var_name = get_param_var_name();
                                                                            int flag = 1;
                                                                            int good_in;                                                                   for (int i=0;i<idx;i++)
                                                                            {
                                                                                if (param_value_type[i]==1)
                                                                                {
                                                                                    if (param_var_init[i]==0)
                                                                                    {
                                                                                        printf("Variable not initialized\n");
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        printf("Variable: %s\n",param_var_type[i]);
                                                                                        good_in = func_input_check(temp2->datatype,param_var_type[i],i);
                                                                                        flag = flag && good_in;
                                                                                    }
                                                                                }
                                                                                else
                                                                                {   
                                                                                    char *val_type = value_int_to_string(param_value_type[i]);
                                                                                    printf("Variable: %s\n",val_type);
                                                                                    good_in = func_input_check(temp2->datatype,val_type,i);
                                                                                    flag = flag && good_in;
                                                                                }
                                                                            }
                                                                            if (flag == 1){
                                                                                for (int i=0;i<idx;i++)
                                                                                {
                                                                                    add_quad("PARAM", param_var_name[i], "", "");
                                                                                }
                                                                            }
                                                                            char str4[20];
                                                                            sprintf(str4, "%d", get_T_idx());
                                                                            char* T = (char*)malloc(20 * sizeof(char)); // Allocate memory for T dynamically
                                                                            strcpy(T, "T");
                                                                            strcat(T, str4);

                                                                            char size[20];
                                                                            sprintf(size,"%d",idx);
                                                                            add_quad("CALL", $4, size, T);
                                                                            add_quad("ASSIGN", T, "", $2);
                                                                            inc_T_idx();
                                                                            clear_call_params();
                                                                        }
                                                                       
                                                                    }
                                                                }
                                                                else
                                                                {
                                                                    printf("Variable already declared\n");
                                                                }
                                                                line++;
                                                            }
;

callParameters:             
    values      {
                    addCallParams($1.value_type,$1.var_type,$1.var_init, $1.var_name);
                }  
    | callParameters','values      
                                { 
                                    addCallParams($3.value_type,$3.var_type,$3.var_init, $3.var_name);
                                } 
    ;

parameters:                 
    typeSpecifier VARIABLE      {addParameter($1,$2);} 
    | parameters ',' typeSpecifier VARIABLE        {addParameter($3,$4);}
    ;

declaration:
    typeSpecifier VARIABLE                                          {
                                                                        if (strcmp($1,"void")!=0)
                                                                        {
                                                                            struct Node *var = searchScope($2);
                                                                            
                                                                            if(var!=NULL){
                                                                                printf("Variable already declared\n");
                                                                            }else{
                                                                                createNode($2,$1,"variable",0,line);

                                                                                buildTable_exp("ASSIGN","",$2,0);
                                                                                print_quads();

                                                                            }
                                                                            line++;
                                                                        }
                                                                        else
                                                                        {
                                                                            printf("Void cannot be assigned to a variable\n");
                                                                        }
                                                                    }

    | typeSpecifier VARIABLE ASSIGN expression                      {
                                                                        if (strcmp($1,"void")!=0)
                                                                        {
                                                                            struct Node *var = searchScope($2);
                                                                        
                                                                            if(var!=NULL){
                                                                                printf("Variable already declared\n");
                                                                            }else{
                                                                                if ($4.value_type!=1)
                                                                                {
                                                                                    if (strcmp($1,value_int_to_string_util($4.value_type))==0)
                                                                                    {
                                                                                        createNode($2,$1,"variable",1,line);
                                                                                        buildTable_assign($2, $4.RegQuad);
                                                                                        print_quads();
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        printf("Type Mismatch\n");
                                                                                    
                                                                                    }
                                                                                }
                                                                                else
                                                                                {
                                                                                    if (strcmp($1,$4.var_type)==0)
                                                                                    {
                                                                                        createNode($2,$1,"variable",1,line);
                                                                                        buildTable_assign($2, $4.RegQuad);
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        printf("Type Mismatch\n");
                                                                                    }
                                                                                }
                                                                            }
                                                                            line++;
                                                                        }
                                                                        else
                                                                        {
                                                                            printf("Void cannot be assigned to a variable\n");
                                                                        }
                                                                       
                                                                    }
    ;

typeSpecifier:
    INT         {$$="int";}
    | FLOAT     {$$="float";}                          
    | STRING    {$$="string";} 
    | CHAR      {$$="char";} 
    | CONST     {$$="const";}
    | VOID      {$$="void";}
    | BOOL      {$$="bool";}
    ;

assignment:
    VARIABLE ASSIGN expression              {
                                                // x = 1+2+3      ========> case 1
                                                // quad(+,1,2,T1)
                                                // quad(+,T1,3,T2)
                                                // quad(:=,T2,,x)

                                                // x = 2;         ========> case 2
                                                // quad(:=,2,,x)

                                                struct Node *var = searchScope($1);
                                                if(var==NULL)
                                                {
                                                    printf("Variable not declared\n");
                                                }
                                                else
                                                {
                                                    if ($3.value_type!=1)
                                                    {
                                                        if (strcmp(var->datatype,value_int_to_string_util($3.value_type))==0)
                                                        {
                                                            var->init=1; 
                                                            buildTable_assign($1, $3.RegQuad);
                                                            print_quads();
                                                        }
                                                        else
                                                        {
                                                            printf("Type Mismatch\n");
                                                        }
                                                    }
                                                    else
                                                    {
                                                        if (strcmp(var->datatype,$3.var_type)==0)
                                                        {
                                                            var->init=1;  
                                                            buildTable_assign($1, $3.var_name);
                                                            print_quads();
                                                        }
                                                        else
                                                        {
                                                            printf("Type Mismatch\n");
                                                        }
                                                    } 
                                                }
                                                line++;
                                            }
    | VARIABLE PLUS_ASSIGN expression       {
                                                // x += 1+2+3      ========> case 1
                                                // quad(+,1,2,T1)
                                                // quad(+,T1,3,T2)
                                                // quad(+,T2,x,T4)
                                                //// quad(:=,T4,,x)

                                                // x += 2;         ========> case 2
                                                // quad(+,2,x,T1)
                                                // quad(:=,T1,,x)
                                                struct Node *var = searchScope($1);
                                                if(var==NULL)
                                                {
                                                    printf("Variable not declared\n");
                                                }
                                                else
                                                {
                                                    if (var->init==0)
                                                    {
                                                        printf("Variable not initialized\n");
                                                    }
                                                    else
                                                    {
                                                        if ($3.value_type!=1)
                                                        {
                                                            if (strcmp(var->datatype,value_int_to_string_util($3.value_type))==0)
                                                            {
                                                                var->init=1;
                                                                buildTable_exp("ADD", $3.RegQuad, $1, 1);
                                                                print_quads();
                                                            }
                                                            else
                                                            {
                                                                printf("Type Mismatch\n");
                                                            }
                                                        }
                                                        else
                                                        {
                                                            if (strcmp(var->datatype,$3.var_type)==0)
                                                            {
                                                                var->init=1;  
                                                                buildTable_exp("ADD", $3.RegQuad, $1, 1);
                                                                print_quads();
                                                            }
                                                            else
                                                            {
                                                                printf("Type Mismatch\n");
                                                            }
                                                        }
                                                    }
                                                }
                                                line++;
                                            }
    | VARIABLE MINUS_ASSIGN expression      {
                                                struct Node *var = searchScope($1);
                                                if(var==NULL)
                                                {
                                                    printf("Variable not declared\n");
                                                }
                                                else
                                                {
                                                    if (var->init==0)
                                                    {
                                                        printf("Variable not initialized\n");
                                                    }
                                                    else
                                                    {
                                                       if ($3.value_type!=1)
                                                        {
                                                            if (strcmp(var->datatype,value_int_to_string_util($3.value_type))==0)
                                                            {
                                                                var->init=1; 
                                                                buildTable_exp("SUB", $3.RegQuad, $1, 1);
                                                                print_quads(); 
                                                            }
                                                            else
                                                            {
                                                                printf("Type Mismatch\n");
                                                            
                                                            }
                                                        }
                                                        else
                                                        {
                                                            if (strcmp(var->datatype,$3.var_type)==0)
                                                            {
                                                                var->init=1;  
                                                                buildTable_exp("SUB", $3.RegQuad, $1, 1);
                                                                print_quads(); 
                                                            }
                                                                else
                                                            {
                                                                printf("Type Mismatch\n");
                                                            }
                                                        }
                                                    }
                                                }
                                                line++;
                                            }       
    
    | VARIABLE MULTIPLY_ASSIGN expression   {
                                                struct Node *var = searchScope($1);
                                                if(var==NULL)
                                                {
                                                    printf("Variable not declared\n");
                                                }
                                                else
                                                {
                                                    if (var->init==0)
                                                    {
                                                        printf("Variable not initialized\n");
                                                    }
                                                     else
                                                    {
                                                      if ($3.value_type!=1)
                                                        {
                                                            if (strcmp(var->datatype,value_int_to_string_util($3.value_type))==0)
                                                            {
                                                                var->init=1; 
                                                                buildTable_exp("MUL", $3.RegQuad, $1, 1);
                                                                print_quads();
                                                            }
                                                            else
                                                            {
                                                                printf("Type Mismatch\n");
                                                            
                                                            }
                                                        }
                                                        else
                                                        {
                                                            if (strcmp(var->datatype,$3.var_type)==0)
                                                            {
                                                                var->init=1;
                                                                buildTable_exp("MUL", $3.RegQuad, $1, 1);
                                                                print_quads();
                                                            }
                                                                else
                                                            {
                                                                printf("Type Mismatch\n");
                                                            }
                                                        }
                                                    }
                                                }
                                                line++;
                                            }
    | VARIABLE DIVIDE_ASSIGN expression     {
                                                struct Node *var = searchScope($1);
                                                if(var==NULL)
                                                {
                                                    printf("Variable not declared\n");
                                                }
                                                else
                                                {

                                                    if (var->init==0)
                                                    {
                                                        printf("Variable not initialized\n");
                                                    }
                                                    else
                                                    {
                                                        buildTable_exp("DIV", $3.RegQuad, $1, 1);
                                                        print_quads();  
                                                       if ($3.value_type!=1)
                                                        {
                                                            if (strcmp(var->datatype,value_int_to_string_util($3.value_type))==0)
                                                            {
                                                                var->init=1; 
                                                                
                                                            }
                                                            else
                                                            {
                                                                printf("Type Mismatch\n");
                                                            
                                                            }
                                                        }
                                                        else
                                                        {
                                                            if (strcmp(var->datatype,$3.var_type)==0)
                                                            {
                                                                var->init=1; 
                                                            }
                                                                else
                                                            {
                                                                printf("Type Mismatch\n");
                                                            }
                                                        }

                                                    }
                                                }
                                                line++;
                                            }
    ;

expression:
    expression PLUS expression            {
                                        // 1+2+3
                                        // quad(+,1,2,T1)
                                        // quad(+,T1,3,T2)
                                        // quad(:=,T2,,x)
                                        
                                        int res = express(0,$1.value_type,$1.var_type,$1.var_init,$3.value_type,$3.var_type,$3.var_init);
                                        if (res == 1)
                                        {
                                            
                                            //2+5+3
                                            // int isUsed[2];
                                            // int* temp =  buildTable_exp("ADD", $1.var_name, $1.isUsed_in_Calc,  $3.var_name, $3.isUsed_in_Calc, 0);
                                            // $1.isUsed_in_Calc = temp[0];
                                            // $3.isUsed_in_Calc = temp[1];
                                            
                                            // buildTable_exp("ADD", $1.var_name, $3.var_name, 0);
                                            // printf("res1 = %s\n",$1.RegQuad);
                                            // printf("res2 = %s\n",$3.RegQuad);
                                            printf("\n");
                                            $$.var_type = $1.var_type;
                                            $$.value_type = $1.value_type;
                                            $$.var_init = $1.var_init;
                                            $$.RegQuad = buildTable_exp("ADD", $1.RegQuad, $3.RegQuad, 0);
                                        }
                                        else
                                        {
                                            $$.value_type = 1;
                                            $$.var_type = "Mismatch";
                                        }
                                        // printf("res = zeeroo");
                       
                                    }
    | expression MINUS expression   {
                                        
                                       int res = express(1,$1.value_type,$1.var_type,$1.var_init,$3.value_type,$3.var_type,$3.var_init);
                                       if (res == 1)
                                        {
                                            printf("\n");
                                            $$.var_type = $1.var_type;
                                            $$.value_type = $1.value_type;
                                            $$.var_init = $1.var_init;
                                            $$.RegQuad = buildTable_exp("SUB", $1.RegQuad, $3.RegQuad, 0);
                                            //  int* temp =  buildTable_exp("SUB", $1.var_name, $1.isUsed_in_Calc,  $3.var_name, $3.isUsed_in_Calc, 0);
                                            // $1.isUsed_in_Calc = temp[0];
                                            // $3.isUsed_in_Calc = temp[1];
                                            // print_quads();
                                        }
                                         else
                                        {
                                            $$.value_type = 1;
                                            $$.var_type = "Mismatch";
                                        }
                                    }
    | expression MULTIPLY expression            {
                                        int res =express(2,$1.value_type,$1.var_type,$1.var_init,$3.value_type,$3.var_type,$3.var_init);
                                        if (res == 1)
                                        {
                                            printf("\n");
                                            $$.var_type = $1.var_type;
                                            $$.value_type = $1.value_type;
                                            $$.var_init = $1.var_init;
                                            $$.RegQuad = buildTable_exp("MUL", $1.RegQuad, $3.RegQuad, 0);
                                            // int* temp =  buildTable_exp("MUL", $1.var_name, $1.isUsed_in_Calc,  $3.var_name, $3.isUsed_in_Calc, 0);
                                            // $1.isUsed_in_Calc = temp[0];
                                            // $3.isUsed_in_Calc = temp[1];
                                            // print_quads();
                                        }
                                         else
                                        {
                                            $$.value_type = 1;
                                            $$.var_type = "Mismatch";
                                        }
                                    }
    | expression DIVIDE expression  {
                                        int res =  express(3,$1.value_type,$1.var_type,$1.var_init,$3.value_type,$3.var_type,$3.var_init);
                                        if (res == 1)
                                        {
                                            printf("\n");
                                            $$.var_type = $1.var_type;
                                            $$.value_type = $1.value_type;
                                            $$.var_init = $1.var_init;
                                            $$.RegQuad = buildTable_exp("DIV", $1.RegQuad, $3.RegQuad, 0);
                                            // int* temp =  buildTable_exp("DIV", $1.var_name, $1.isUsed_in_Calc,  $3.var_name, $3.isUsed_in_Calc, 0);
                                            // $1.isUsed_in_Calc = temp[0];
                                            // $3.isUsed_in_Calc = temp[1];
                                            // print_quads();
                                        }
                                         else
                                        {
                                            $$.value_type = 1;
                                            $$.var_type = "Mismatch";
                                        }
                                    }
    |'(' expression ')'            {$$=$2;} //can be changed
    | values                       {$$=$1;}
    ;

comparators:
    values EQUAL values             {
                                        int res = cmp($1.value_type,$1.var_type,$1.var_init,$3.value_type,$3.var_type,$3.var_init);
                                        if (res==0)
                                        {
                                            printf("Comparison not possible\n");
                                        }
                                        $$ = buildTable_exp("EQ", $1.RegQuad, $3.RegQuad, 0);
                                        
                                    }
    | values NOT_EQUAL values       {   
                                        int res = cmp($1.value_type,$1.var_type,$1.var_init,$3.value_type,$3.var_type,$3.var_init);
                                        if (res==0)
                                        {
                                            printf("Comparison not possible\n");
                                        }
                                        $$ = buildTable_exp("NEQ", $1.RegQuad, $3.RegQuad, 0);
                                    }
    | values GREATER values         {    
                                        int res = cmp($1.value_type,$1.var_type,$1.var_init,$3.value_type,$3.var_type,$3.var_init);
                                        if (res==0)
                                        {
                                            printf("Comparison not possible\n");
                                        }
                                        $$ = buildTable_exp("GT", $1.RegQuad, $3.RegQuad, 0);
                                    }
    | values LESS values            { //print all parameters of cmp
                                        int res = cmp($1.value_type,$1.var_type,$1.var_init,$3.value_type,$3.var_type,$3.var_init);
                                        if (res==0)
                                        {
                                            printf("Comparison not possible\n");
                                        }
                                        $$ = buildTable_exp("LT", $1.RegQuad, $3.RegQuad, 0);
                                    }
    | values GREATER_EQUAL values   {
                                        int res = cmp($1.value_type,$1.var_type,$1.var_init,$3.value_type,$3.var_type,$3.var_init);
                                        if (res==0)
                                        {
                                            printf("Comparison not possible\n");
                                        }
                                        $$ = buildTable_exp("GTE", $1.RegQuad, $3.RegQuad, 0);
                                    }
    | values LESS_EQUAL values              {
                                                int res = cmp($1.value_type,$1.var_type,$1.var_init,$3.value_type,$3.var_type,$3.var_init);
                                                if (res==0)
                                                {
                                                    printf("Comparison not possible\n");
                                                }
                                                $$ = buildTable_exp("LTE", $1.RegQuad, $3.RegQuad, 0);
                                            }
    | variableValue AND variableValue       { 
                                                if (boolchecker($1.var_type,$1.var_init)==0 || boolchecker($3.var_type,$3.var_init)==0)
                                                {
                                                    printf("And Operator can only be used with boolean values\n");
                                                   
                                                } 
                                                $$ = buildTable_exp("AND", $1.RegQuad, $3.RegQuad, 0);
                                            }
    | variableValue OR variableValue        {
                                                if (boolchecker($1.var_type,$1.var_init)==0 || boolchecker($3.var_type,$3.var_init)==0)
                                                {
                                                    printf("Or Operator can only be used with boolean values\n");
                                                   
                                                } 
                                                $$ = buildTable_exp("OR", $1.RegQuad, $3.RegQuad, 0);
                                            }                              
    | NOT variableValue                     {
                                                if (boolchecker($2.var_type,$2.var_init)==0)
                                                {
                                                    printf("Not Operator can only be used with boolean values\n");
                                                }
                                                $$ = buildTable_exp("NOT", $2.RegQuad, "", 0);
                                            }
    ;

values:
    variableValue       {
                            $$= $1;
                        }        
    | INTEGER_LITERAL   {
                            $$.value_type = 2;
                            char* str = malloc(20); // Allocate memory for the string
                            sprintf(str, "%d", $1); // Convert the integer to a string
                            $$.var_name = str; 
                            // $$.isUsed_in_Calc = 0;
                            $$.RegQuad = str;
                        }              
    | FLOAT_LITERAL     {
                            $$.value_type = 3;
                            char* str = malloc(20); // Allocate memory for the string
                            sprintf(str, "%f", $1); // Convert the integer to a string
                            $$.var_name = str;
                            // $$.isUsed_in_Calc = 0;
                            $$.RegQuad = str;
                        } 
    | STRING_LITERAL    {
                            $$.value_type = 4;
                            $$.var_name = $1;
                            $$.RegQuad = $1;
                        } 
    | CHAR_LITERAL      {
                            $$.value_type = 5;
                            char str[2];
                            str[0] = $1;
                            str[1] = '\0';
                            $$.var_name = str;
                            $$.RegQuad = str;
                        }
    | BOOLEAN_TRUE      {
                            $$.value_type = 6;
                            $$.var_name = "true";
                            $$.RegQuad = "true";
                        }
    | BOOLEAN_FALSE     {
                            $$.value_type = 6;
                            $$.var_name = "false";
                            $$.RegQuad = "false";
                        }
    ;

variableValue:
    VARIABLE            {
                            $$.value_type = 1;
                            struct Node *node  = searchScope($1);
                            if(node == NULL){
                                printf("Variable not declared\n");
                            }
                            else
                            {
                                if (node->init!=0)
                                {
                                    $$.var_name = $1;
                                    $$.var_type=node->datatype; 
                                    $$.var_init=node->init;
                                    $$.RegQuad = $1;
                                }else
                                {
                                    printf("Variable not initialized\n");
                                }
                            }
                        }       
;
ifStatement:
    ifComparators 
    | ifVariable
    ;

openScopeIF:
    '{' {
            scopePush();

            CreateLabelIF(); //push index of label in stack
            char str1[20];
            sprintf(str1, "%d", getStackTop());
            char L [20] = "L";
            strcat(L,str1);

            char str[20];
            sprintf(str, "%d", get_T_idx()-1);
            char* T = (char*)malloc(20 * sizeof(char)); // Allocate memory for T dynamically
            strcpy(T, "T");
            strcat(T, str);
            
            add_quad("JE 0",T,"",L);

        }
    ;

closeScopeIF:
    '}' {   
            printf("==============Symbol Table before popping==============\n");
            // displayList();
            write_file();
            scopePop();
            // char* go_to = PopLabel();
            // buildTable_exp("JMP", go_to, "", 0);

            //pop from stack and add the label to the quad
            //go to else end scop (IF EXIST)
            char str1[20];
            sprintf(str1, "%d", getElseTop());
            char L [20] = "L";
            strcat(L,str1);
            add_quad("JMP","","",L);
            add_quad("LABEL: ",PopLabel(),"","");
        }
    ;

openScopeELSE:
    '{'     {
                scopePush();
            }
    ;

closeScopeELSE:
    '}'     {
                printf("==============Symbol Table before popping==============\n");
                // displayList();
                write_file();
                scopePop();
                add_quad("LABEL: ",PopElseLabel(),"","");
            }
    ;


ifComparators:
    IF '(' comparators ')'  openScopeIF  inBlockscope closeScopeIF elseClause  
    | IF '(' comparators ')' openScopeIF inBlockscope closeScopeIF { 
                                                                        //pop from stack and add the label to the quad
                                                                        add_quad("LABEL: ",PopElseLabel(),"","");
                                                                    }
    ;

ifVariable:
    IF '(' VARIABLE ')' openScopeIF inBlockscope closeScopeIF elseClause
    | IF '(' VARIABLE ')' openScopeIF inBlockscope closeScopeIF
    ;

elseClause:
    ELSE openScopeELSE inBlockscope closeScopeELSE 
    ;

openScopeWhile:
    '{' {
            scopePush();

            //add_quad lel condition ba2a
            char str[20];
            sprintf(str, "%d", get_T_idx()-1);
            char* T = (char*)malloc(20 * sizeof(char)); // Allocate memory for T dynamically
            strcpy(T, "T");
            strcat(T, str);
            printf("T = %s\n",T);
            char str1[20];
            sprintf(str1, "%d", getWhileTop());
            char* L = (char*)malloc(20 * sizeof(char)); // Allocate memory for T dynamically
            strcpy(L, "L");
            strcat(L, str1);
            add_quad("JE 0",T,"",L);
        }
    ;

closeScopeWhile:
    '}' {   
            // printf("==============Symbol Table before popping==============\n");
            // displayList();
            write_file();
            scopePop();

            add_quad("JMP","","",PopLabel());
        }
    ;
whileOpen:
    '(' {
            CreateLabelWhile();
        }
    ;

whileStatement:
    WHILE whileOpen comparators ')' openScopeWhile  inBlockscope closeScopeWhile    {add_quad("LABEL: ",PopWhileLabel(),"","");}
    ;


forExpression:
    VARIABLE PLUS_ASSIGN expression     {}
    | VARIABLE MINUS_ASSIGN expression  {} 
    | VARIABLE MULTIPLY_ASSIGN expression   {} 
    | VARIABLE DIVIDE_ASSIGN expression     {} 

    ;

forStatement:
    FOR ForBracket forScope    { }
    ;
bora3y:
    INT VARIABLE ASSIGN INTEGER_LITERAL     { 
                                                scopePush();
                                                createNode($2,"int","variable",1,line);
                                            }
    ;

ForBracket:
    '(' bora3y ';' comparators ';' forExpression ')' 
    ;


forScope:
                                                                                             
    '{'  inBlockscope closeScope        {}  
    ;

switchStatement:
    SWITCH '(' VARIABLE ')' openScope  caseStatements closeScope  {printf("Switch Statement\n");}
    ;

caseStatements:
    | CASE INTEGER_LITERAL ':' openScope inBlockscope BREAK ';' closeScope caseStatements   {printf("Case Statement multiple statements\n");}
    | DEFAULT ':' openScope inBlockscope BREAK ';' closeScope   {printf("Default Statement multiple statements\n");}
    ;

returnStatement:
    RETURN expression ';'   {printf("Return Statement with expression\n");} 
    | RETURN ';'    {printf("Return Statement without expression\n");}
    ;

repeatUntilStatement:
    REPEAT openScope  inBlockscope '}' UNTIL '(' comparators ')' ';'        {
                                                                                //get the labes pushed
                                                                                // printf("==============Symbol Table before popping==============\n");
                                                                                // displayList();
                                                                                write_file();
                                                                                scopePop();
                                                                                char* go_to = PopLabel();
                                                                                char* cmp = $7;
                                                                                buildTable_exp("JE 0", cmp, go_to, 2);

                                                                            }
;
%%

int main() {
    initializeList();
    quad_init();
    yyparse();
    /* displayList(); */
    write_file();

    /* displayScope(); */
    return 0;
}
int yyerror(char *s) {
    printf("\nERROR: %s\n", s);
    return 0;
}
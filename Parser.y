%{
    int yyerror(char *s); 
    int yylex(void);
    #include <stdio.h>
	#include <stdlib.h>
	#include <stdarg.h>
	#include <string.h>	
    // #include <stdbool.h>
    #include "stack.h"
    #include "linked_list.h"
    #include "utils.h"
    
    // struct terminal_values {
    // int value_type;
    // char* var_type;
    // union {
    //     char* var_val;
    //     int integer_val;
    //     float float_val;
    //     char* string_val;
    //     char char_val;
    //     int bool_val; 
    // } value;
    // };

    // int boolchecker(struct terminal_values var); 

    int line=1;

%}
%union{
    char* type;                 /* data type */
	int integerval;               /* integer value */
	float floatval;               /* float Value */
    char * stringval;             /* string value */
	char  charval;               /* character value */
	char * varval ;                    	/* VARIABLE Value */
    int boolval;               /* boolean value */
    int compare;              /* comparison value */

    struct  {
    int value_type;
    char* var_type;
    union {
        char* var_val;
        int integer_val;
        float float_val;
        char* string_val;
        char char_val;
        int bool_val; 
    } value;
    }terminal_values; /* terminal values */

}
        //Data Types
%token <type> INT FLOAT STRING CHAR CONST VOID BOOL 
/* %token ENUM */
        //Keywords
%token IF ELSE WHILE FOR SWITCH CASE DEFAULT BREAK CONTINUE RETURN REPEAT UNTIL
        

        //Values     
%token  <stringval> STRING_LITERAL 
%token  <charval>CHAR_LITERAL 
%token  <integerval>INTEGER_LITERAL 
%token  <floatval>FLOAT_LITERAL
%token  <boolval> BOOLEAN_TRUE 
%token  <boolval> BOOLEAN_FALSE 

%type <type> typeSpecifier
%type <terminal_values> values
%type <terminal_values> variableValue
%type <terminal_values> factor
%type <terminal_values> term
%type <terminal_values> expression
%type <compare> comparators
        //Variable
%token  <varval>VARIABLE

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
    | typeSpecifier VARIABLE '(' parameters ')' '{'  inBlockscope '}' programStatements {printf("Function Declaration\n");} 
    | typeSpecifier VARIABLE '('')' '{'   inBlockscope '}'  programStatements {printf("Function Declaration with no parameters\n");}
    | typeSpecifier VARIABLE '(' parameters ')' '{'   inBlockscope '}'  {printf("Function Declaration\n");} 
    | typeSpecifier VARIABLE '('')' '{' inBlockscope '}'   {printf("Function Declaration with no parameters\n");}      
    | statement
    ;

openScope:
    '{' {Head_for_push();
        push(getHead());}
    ;
closeScope:
    '}' {   
            printf("==============Symbol Table before popping==============\n");
            displayList();
            pop();
            Head_for_pop();
        }
    ;


inBlockscope:
      inBlockscope statement   {printf("Block Scope\n");}
    |statement 
    ;

statement:                 
    declaration ';'           {printf("Declaration\n");}
    | assignment ';'        {printf("Assignment\n");} 
    | ifStatement           {printf("If Statement\n");}
    | whileStatement        {printf("While Statement\n");}
    | forStatement          {printf("For Statement\n");} 
    | switchStatement       {printf("Switch Statement\n");}
    | returnStatement       {printf("Return Statement\n");}
    | repeatUntilStatement  {printf("Repeat Until Statement from statement\n");}
    | functionCall       {printf("Function Call\n");}
    /* | enumStatement         {printf("Enum Statement\n");} */
    | VARIABLE ASSIGN functionCall       {printf("Function Call with Assignment\n");}
    | typeSpecifier VARIABLE ASSIGN functionCall     {printf("Function Call with Assignment\n");}  
    | BREAK ';'        {printf("Break\n");}
    | CONTINUE ';'      {printf("Continue\n");}
    | error ';'     { yyerrok; }
    ;  

functionCall:               
    VARIABLE '(' ')' ';'               {printf("Function Call\n");}
    | VARIABLE '(' callParameters ')' ';'  {printf("Function Call with Parameters\n");}
    ;

callParameters:             
    values    {printf("Parameter\n");}
    | callParameters ',' values   {printf("Multiple  Parameters\n");}
    ;

parameters:                 
    typeSpecifier VARIABLE      {printf("Parameters\n");} 
    | parameters ',' typeSpecifier VARIABLE     {printf("Multiple Parameters\n");}
    ;

declaration:
    typeSpecifier VARIABLE                                          {
                                                                        struct Node *var = searchStack($2);
                                                                        if(var!=NULL){
                                                                            printf("Variable already declared\n");
                                                                        }else{
                                                                            createNode($2,$1,"variable",NULL,line);
                                                                            
                                                                            if (isEmpty()==1){
                                                                                push(getHead());
                                                                                printf("current Stack top name: %s\n",peek()->name);
                                                                            }
                                                                        }
                                                                        line++;
                                                                    }

    | typeSpecifier VARIABLE ASSIGN expression                      {struct Node *var = searchStack($2);
                                                                        if(var!=NULL){
                                                                            printf("Variable already declared\n");
                                                                        }else{
                                                                            char value[1024];
                                                                            sprintf(value,"%d",$4.value.integer_val);
                                                                            createNode($2,$1,"variable",value,line);
                                                                            free(value);
                                                                            if (isEmpty()==1){
                                                                                push(getHead());
                                                                                printf("current Stack top name: %s\n",peek()->name);
                                                                            }
                                                                        }
                                                                        line++;}
    /* | ENUM VARIABLE VARIABLE                                        {printf("Enum Declaration\n");}
    | ENUM VARIABLE VARIABLE ASSIGN VARIABLE                        {printf("Enum Declaration with Assignment\n");} */
    ;

typeSpecifier:
    INT         {$$="int";printf("int\n");}
    | FLOAT     {$$="float"; printf("Float\n");}                          
    | STRING    {$$="string"; printf("String\n");} 
    | CHAR      {$$="char"; printf("Char\n");} 
    | CONST     {$$="const"; printf("Const\n");}
    | VOID      {$$="void"; printf("Void\n");}
    | BOOL      {$$="bool"; printf("Bool\n");}
    ;

assignment:
    VARIABLE ASSIGN expression              {
                                                struct Node *var = searchStack($1);
                                                if(var==NULL)
                                                {
                                                    printf("Variable not declared\n");
                                                }
                                                else
                                                {
                                                    char value[1024];
                                                    sprintf(value,"%d",$3.value.integer_val);
                                                    var->value=value;
                                                    free(value);
                                                    printf("Variable initialized\n");
                                                }
                                                line++;
                                            }
    | VARIABLE PLUS_ASSIGN expression       {
                                                struct Node *var = searchStack($1);
                                                if(var==NULL)
                                                {
                                                    printf("Variable not declared\n");
                                                }
                                                else
                                                {
                                                    if (var->value!=NULL)
                                                    {
                                                        char value[1024];
                                                        sprintf(value,"%d",atoi(var->value)+$3.value.integer_val);
                                                        var->value=value;
                                                        free(value);
                                                        printf("Variable initialized\n");
                                                    }
                                                    else
                                                    {
                                                        printf("Variable not initialized\n");
                                                    }
                                                }
                                                line++;
                                            }
    | VARIABLE MINUS_ASSIGN expression      {
                                                struct Node *var = searchStack($1);
                                                if(var==NULL)
                                                {
                                                    printf("Variable not declared\n");
                                                }
                                                else
                                                {
                                                    if (var->value!=NULL)
                                                    {
                                                        char value[100];
                                                        sprintf(value,"%d",atoi(var->value)-$3.value.integer_val);
                                                        var->value=value;
                                                        printf("Variable initialized\n");
                                                    }
                                                    else
                                                    {
                                                        printf("Variable not initialized\n");
                                                    }
                                                }
                                                line++;
                                            }       
    
    | VARIABLE MULTIPLY_ASSIGN expression   {
                                                struct Node *var = searchStack($1);
                                                if(var==NULL)
                                                {
                                                    printf("Variable not declared\n");
                                                }
                                                else
                                                {
                                                    if (var->value!=NULL)
                                                    {
                                                        char value[100];
                                                        sprintf(value,"%d",atoi(var->value)*$3.value.integer_val);
                                                        var->value=value;
                                                        printf("Variable initialized\n");
                                                    }
                                                    else
                                                    {
                                                        printf("Variable not initialized\n");
                                                    }
                                                }
                                                line++;
                                            }
    | VARIABLE DIVIDE_ASSIGN expression     {
                                                struct Node *var = searchStack($1);
                                                if(var==NULL)
                                                {
                                                    printf("Variable not declared\n");
                                                }
                                                else
                                                {
                                                    if (var->value!=NULL)
                                                    {
                                                        char value[100];
                                                        sprintf(value,"%d",atoi(var->value)/$3.value.integer_val);
                                                        var->value=value;
                                                        printf("Variable initialized\n");
                                                    }
                                                    else
                                                    {
                                                        printf("Variable not initialized\n");
                                                    }
                                                }
                                                line++;
                                            }
    ;

expression:
    expression PLUS term            {                                        
                                        $$.value_type=$1.value_type;
                                        $$.value.integer_val=$1.value.integer_val-$3.value.integer_val;
                                    }
    | expression MINUS term         { 
                                        $$.value_type=$1.value_type;
                                        $$.value.integer_val=$1.value.integer_val-$3.value.integer_val;
                                    }
    | term                          {$$=$1;
     printf("expr3ession:%d\n",$$.value.integer_val);}
    ;

term:
    term MULTIPLY factor            { 
                                        $$.value_type=$1.value_type;
                                        $$.value.integer_val=$1.value.integer_val*$3.value.integer_val;
                                    }
    | term DIVIDE factor            {
                                        $$.value_type=$1.value_type;
                                        $$.value.integer_val=$1.value.integer_val/$3.value.integer_val;
                                    }
    | factor                       {$$=$1;
     printf("term:%d\n",$$.value.integer_val);}
    ;

factor:
    '(' expression ')'             {$$=$2;} //can be changed
    | values                       {$$=$1;
                                    printf("Factor:%d\n",$$.value.integer_val);}
    ;

comparators:
    values EQUAL values         {
                                    char* value1;
                                    char* value2;
                                    if ($1.value_type==2)
                                    {  
                                        sprintf(value1,"%d",$1.value.integer_val);
                                    }
                                    if ($1.value_type==6)
                                    {  
                                        sprintf(value1,"%d",$1.value.bool_val);
                                    }
                                    if ($1.value_type==3)
                                    {  
                                        sprintf(value1,"%f",$1.value.float_val);
                                    }
                                    if ($3.value_type==2)
                                    {  
                                        sprintf(value2,"%d",$3.value.integer_val);
                                    }
                                    if ($3.value_type==6)
                                    {  
                                        sprintf(value2,"%d",$3.value.bool_val);
                                    }
                                    if ($3.value_type==3)
                                    {  
                                        sprintf(value2,"%f",$3.value.float_val);
                                    }
                                    int res = cmp(1,$1.value_type,value1,$1.var_type,$3.value_type,value2,$3.var_type);
                                    if (res!=-1)
                                    {
                                        $$=res;
                                    }
                                    else
                                    {
                                        printf("Comparison not possible\n");
                                    };
                                }
    | values NOT_EQUAL values   {  char* value1;
                                        char* value2;
                                        if ($1.value_type==2)
                                        {  
                                            sprintf(value1,"%d",$1.value.integer_val);
                                        }
                                        if ($1.value_type==6)
                                        {  
                                            sprintf(value1,"%d",$1.value.bool_val);
                                        }
                                        if ($1.value_type==3)
                                        {  
                                            sprintf(value1,"%f",$1.value.float_val);
                                        }
                                        if ($3.value_type==2)
                                        {  
                                            sprintf(value2,"%d",$3.value.integer_val);
                                        }
                                        if ($3.value_type==6)
                                        {  
                                            sprintf(value2,"%d",$3.value.bool_val);
                                        }
                                        if ($3.value_type==3)
                                        {  
                                            sprintf(value2,"%f",$3.value.float_val);
                                        }
                                        int res = cmp(2,$1.value_type,value1,$1.var_type,$3.value_type,value2,$3.var_type);
                                        if (res!=-1)
                                        {
                                            $$=res;
                                        }
                                        else
                                        {
                                            printf("Comparison not possible\n");
                                        }}
    | values GREATER values     {  char* value1;
                                        char* value2;
                                        if ($1.value_type==2)
                                        {  
                                            sprintf(value1,"%d",$1.value.integer_val);
                                        }
                                        if ($1.value_type==6)
                                        {  
                                            sprintf(value1,"%d",$1.value.bool_val);
                                        }
                                        if ($1.value_type==3)
                                        {  
                                            sprintf(value1,"%f",$1.value.float_val);
                                        }
                                        if ($3.value_type==2)
                                        {  
                                            sprintf(value2,"%d",$3.value.integer_val);
                                        }
                                        if ($3.value_type==6)
                                        {  
                                            sprintf(value2,"%d",$3.value.bool_val);
                                        }
                                        if ($3.value_type==3)
                                        {  
                                            sprintf(value2,"%f",$3.value.float_val);
                                        }
                                        int res = cmp(3,$1.value_type,value1,$1.var_type,$3.value_type,value2,$3.var_type);
                                        if (res!=-1)
                                        {
                                            $$=res;
                                        }
                                        else
                                        {
                                            printf("Comparison not possible\n");
                                        }}
    | values LESS values        {  char value1[1024];
                                        char value2[1024];
                                        if ($1.value_type==2)
                                        {  
                                            sprintf(value1,"%d",$1.value.integer_val);
                                        }
                                        if ($1.value_type==6)
                                        {  
                                            sprintf(value1,"%d",$1.value.bool_val);
                                        }
                                        if ($1.value_type==3)
                                        {  
                                            sprintf(value1,"%f",$1.value.float_val);
                                        }
                                        if ($3.value_type==2)
                                        {  
                                            sprintf(value2,"%d",$3.value.integer_val);
                                        }
                                        if ($3.value_type==6)
                                        {  
                                            sprintf(value2,"%d",$3.value.bool_val);
                                        }
                                        if ($3.value_type==3)
                                        {  
                                            sprintf(value2,"%f",$3.value.float_val);
                                        }
                                        int res = cmp(4,$1.value_type,value1,$1.var_type,$3.value_type,value2,$3.var_type);
                                        if (res!=-1)
                                        {
                                            $$=res;
                                        }
                                        else
                                        {
                                            printf("Comparison not possible\n");
                                        }}
    | values GREATER_EQUAL values   {
          char* value1;
                                        char* value2;
                                        if ($1.value_type==2)
                                        {  
                                            sprintf(value1,"%d",$1.value.integer_val);
                                        }
                                        if ($1.value_type==6)
                                        {  
                                            sprintf(value1,"%d",$1.value.bool_val);
                                        }
                                        if ($1.value_type==3)
                                        {  
                                            sprintf(value1,"%f",$1.value.float_val);
                                        }
                                        if ($3.value_type==2)
                                        {  
                                            sprintf(value2,"%d",$3.value.integer_val);
                                        }
                                        if ($3.value_type==6)
                                        {  
                                            sprintf(value2,"%d",$3.value.bool_val);
                                        }
                                        if ($3.value_type==3)
                                        {  
                                            sprintf(value2,"%f",$3.value.float_val);
                                        }
                                        int res = cmp(5,$1.value_type,value1,$1.var_type,$3.value_type,value2,$3.var_type);
                                        if (res!=-1)
                                        {
                                            $$=res;
                                        }
                                        else
                                        {
                                            printf("Comparison not possible\n");
                                        }
    }
    | values LESS_EQUAL values      {
                                        char* value1;
                                        char* value2;
                                        if ($1.value_type==2)
                                        {  
                                            sprintf(value1,"%d",$1.value.integer_val);
                                        }
                                        if ($1.value_type==6)
                                        {  
                                            sprintf(value1,"%d",$1.value.bool_val);
                                        }
                                        if ($1.value_type==3)
                                        {  
                                            sprintf(value1,"%f",$1.value.float_val);
                                        }
                                        if ($3.value_type==2)
                                        {  
                                            sprintf(value2,"%d",$3.value.integer_val);
                                        }
                                        if ($3.value_type==6)
                                        {  
                                            sprintf(value2,"%d",$3.value.bool_val);
                                        }
                                        if ($3.value_type==3)
                                        {  
                                            sprintf(value2,"%f",$3.value.float_val);
                                        }
                                        int res = cmp(6,$1.value_type,value1,$1.var_type,$3.value_type,value2,$3.var_type);
                                        if (res!=-1)
                                        {
                                            $$=res;
                                        }
                                        else
                                        {
                                            printf("Comparison not possible\n");
                                        }
                                    }
    | variableValue AND variableValue       { 
                                                if (boolchecker($1.var_type,$1.value.var_val)==1 && boolchecker($3.var_type,$3.value.var_val)==1)
                                                {
                                                    $$=atoi($1.value.var_val) && atoi($3.value.var_val);
                                                } else
                                                {
                                                    printf("Or Operator can only be used with boolean values\n");
                                                }
                                            }
    | variableValue OR variableValue        {
                                                if (boolchecker($1.var_type,$1.value.var_val)==1 && boolchecker($3.var_type,$3.value.var_val)==1)
                                                {
                                                    $$=atoi($1.value.var_val) || atoi($3.value.var_val);
                                                } else
                                                {
                                                    printf("Or Operator can only be used with boolean values\n");
                                                }
                                            }

                                        
    | NOT variableValue                     {
                                                if (boolchecker($2.var_type,$2.value.var_val)==1)
                                                {
                                                    $$=!$2.value.var_val;
                                                }else
                                                {
                                                    printf("Not Operator can only be used with boolean values\n");
                                                }
                                            }
    ;

values:
    variableValue       {
                            $$.value_type = $1.value_type;
                            $$.value.var_val = $1.value.var_val;
                            $$.var_type = $1.var_type;
                        }        
    | INTEGER_LITERAL   {
                            $$.value_type = 2;
                            $$.value.integer_val = $1;
                            printf("int_literal:%d\n", $1);
                        }              
    | FLOAT_LITERAL     {
                            $$.value_type = 3;
                            $$.value.float_val = $1;
                        } 
    | STRING_LITERAL    {
                            $$.value_type = 4;
                            $$.value.string_val = $1;
                        } 
    | CHAR_LITERAL      {
                            $$.value_type = 5;
                            $$.value.char_val = $1;
                        }
    | BOOLEAN_TRUE      {
                            $$.value_type = 6;
                            $$.value.bool_val = 1;
                        }
    | BOOLEAN_FALSE     {
                            $$.value_type = 6;
                            $$.value.bool_val = 0;
                        }
    ;

variableValue:
    VARIABLE       {
                            $$.value_type = 1;
                            struct Node *var = searchStack($1);
                            $$.value.var_val ="N/A";
                            $$.var_type="N/A";
                            if(var==NULL){
                                printf("Variable not declared\n");
                            }
                            else
                            {
                                if (var->value!=NULL)
                                {
                                    $$.value.var_val =var->value; 
                                    $$.var_type=var->datatype; 
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

ifComparators:
    IF '(' comparators ')' openScope inBlockscope closeScope elseClause
    | IF '(' comparators ')' openScope inBlockscope closeScope

ifVariable:
    IF '(' VARIABLE ')' openScope inBlockscope closeScope elseClause
    | IF '(' VARIABLE ')' openScope inBlockscope closeScope


elseClause:
    ELSE openScope inBlockscope closeScope
    ;
    
whileStatement:
    WHILE '(' comparators ')' openScope  inBlockscope closeScope    {printf("While Multiple Statements\n");}
    ;


forExpression:
    VARIABLE PLUS_ASSIGN expression     {printf("For statement Variable Plus Equal\n");}
    | VARIABLE MINUS_ASSIGN expression  {printf("For statement Variable Minus Equal\n");} 
    | VARIABLE MULTIPLY_ASSIGN expression   {printf("For statement Variable Multiply Equal\n");} 
    | VARIABLE DIVIDE_ASSIGN expression     {printf("For statement Variable Divide Equal\n");} 

    ;

forStatement:
FOR '(' INT VARIABLE ASSIGN INTEGER_LITERAL ';' comparators ';' forExpression ')' '{'  inBlockscope closeScope      {  
                                                                                                                        Head_for_push();
                                                                                                                        push(getHead());
                                                                                                                        char value[1024];
                                                                                                                        sprintf(value,"%d",$6);
                                                                                                                        createNode($4,$3,"variable",value,line);
                                                                                                                        free(value);
                                                                                                                        line++;
                                                                                                                    }
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
    REPEAT openScope  inBlockscope closeScope UNTIL '(' comparators ')' ';'  {printf("Repeat Until Statement scope\n");}
;
%%

int main() {
    initializeStack();
    yyparse();
    displayList();
    return 0;
}

int yyerror(char *s) {
    printf("\nERROR: %s\n", s);
    return 0;
}
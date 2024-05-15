%{
    int yyerror(char *s); 
    int yylex(void);
    #include <stdio.h>
	#include <stdlib.h>
	#include <stdarg.h>
	#include <string.h>	
    // #include <stdbool.h>
    // #include "stack.h"
    #include "linked_list.h"
    #include "utils.h"

    int line=1;
    //Arr dynamic

%}
%union{
    char* type;                     /* data type    */
	int integerval;                /* integer value */
	float floatval;               /* float Value    */
    char * stringval;            /* string value    */
	char  charval;              /* character value  */
    char * varval ;            /* VARIABLE Value    */
    int boolval;              /* boolean value      */
    int compare;             /* comparison value    */

    struct  {
    int value_type; //1-6 for variable, int, float, string, char, bool
    char* var_type; //datatype of variable
    int var_init;   //if variable is initialized or not

    }terminal_values; /* terminal values */

    struct {
    char* param_types; //datatype of variable
    char* param_name[20]; //name of variable

    }parameters;

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
%type <terminal_values> factor
%type <terminal_values> term
%type <terminal_values> expression
%type <compare> comparators
%type <parameters> parameters
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
    | typeSpecifier VARIABLE '(' parameters ')' '{'  inBlockscope '}' programStatements {} 
    | typeSpecifier VARIABLE '('')' '{'   inBlockscope '}'  programStatements {printf("Function Declaration with no parameters\n");}
    | typeSpecifier VARIABLE '(' parameters ')' '{'   inBlockscope '}'  {printf("Function Declaration\n");} 
    | typeSpecifier VARIABLE '('')' '{' inBlockscope '}'   {printf("Function Declaration with no parameters\n");}      
    | statement
    ;

openScope:
    '{' {scopePush();}
    ;
closeScope:
    '}' {   

            printf("==============Symbol Table before popping==============\n");
            displayList();
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
    |comparators ';'       {printf("Comparators\n");}
    /* | comparators ';'       {printf("Comparators\n");} */
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
    | typeSpecifier VARIABLE ','parameters       {printf("Multiple Parameters\n");}
    ;

declaration:
    typeSpecifier VARIABLE                                          {
                                                                        struct Node *var = searchScope($2);
                                                                        
                                                                        if(var!=NULL){
                                                                            printf("Variable already declared\n");
                                                                        }else{
                                                                            createNode($2,$1,"variable",0,line);
                                                                        }
                                                                        line++;
                                                                    }

    | typeSpecifier VARIABLE ASSIGN expression                      {
                                                                       
                                                                        struct Node *var = searchScope($2);
                                                                       
                                                                        if(var!=NULL){
                                                                            printf("Variable already declared\n");
                                                                        }else{
                                                                            createNode($2,$1,"variable",1,line);
                                                                        }
                                                                        line++;
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
                                                struct Node *var = searchScope($1);
                                                if(var==NULL)
                                                {
                                                    printf("Variable not declared\n");
                                                }
                                                else
                                                {
                                                    var->init=1;  
                                                }
                                                line++;
                                            }
    | VARIABLE PLUS_ASSIGN expression       {
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
                                                }
                                                line++;
                                            }
    ;



expression:
    expression PLUS term            {;}
    | expression MINUS term         {;}
    | term                          {$$=$1;
                                    
                                    }
                                    
    ;

term:
    term MULTIPLY factor            {;}
    | term DIVIDE factor            {;}
    | factor                       {$$=$1;}
    ;

factor:
    '(' expression ')'             {$$=$2;} //can be changed
    | values                       {$$=$1;}
    ;

comparators:
    values EQUAL values             {
                                        int res = cmp($1.value_type,$1.var_type,$1.var_init,$3.value_type,$3.var_type,$3.var_init);
                                        if (res==0)
                                        {
                                            printf("Comparison not possible\n");
                                        }
                                    }
    | values NOT_EQUAL values       {   
                                        int res = cmp($1.value_type,$1.var_type,$1.var_init,$3.value_type,$3.var_type,$3.var_init);
                                        if (res==0)
                                        {
                                            printf("Comparison not possible\n");
                                        }
                                    }
    | values GREATER values         {    
                                        int res = cmp($1.value_type,$1.var_type,$1.var_init,$3.value_type,$3.var_type,$3.var_init);
                                        if (res==0)
                                        {
                                            printf("Comparison not possible\n");
                                        }
                                    }
    | values LESS values            { //print all parameters of cmp
                               
                                       
                                        int res = cmp($1.value_type,$1.var_type,$1.var_init,$3.value_type,$3.var_type,$3.var_init);
                                        if (res==0)
                                        {
                                            printf("Comparison not possible\n");
                                        }
                                    }
    | values GREATER_EQUAL values   {
                                        int res = cmp($1.value_type,$1.var_type,$1.var_init,$3.value_type,$3.var_type,$3.var_init);
                                        if (res==0)
                                        {
                                            printf("Comparison not possible\n");
                                        }
                                    }
    | values LESS_EQUAL values      {
                                        int res = cmp($1.value_type,$1.var_type,$1.var_init,$3.value_type,$3.var_type,$3.var_init);
                                        if (res==0)
                                        {
                                            printf("Comparison not possible\n");
                                        }
                                    }
    | variableValue AND variableValue       { 
                                                if (boolchecker($1.var_type,$1.var_init)==0 || boolchecker($3.var_type,$3.var_init)==0)
                                                {
                                                    printf("And Operator can only be used with boolean values\n");
                                                   
                                                } 
                                            }
    | variableValue OR variableValue        {
                                                if (boolchecker($1.var_type,$1.var_init)==0 || boolchecker($3.var_type,$3.var_init)==0)
                                                {
                                                    printf("Or Operator can only be used with boolean values\n");
                                                   
                                                } 
                                            }                              
    | NOT variableValue                     {
                                                if (boolchecker($2.var_type,$2.var_init)==0)
                                                {
                                                    printf("Not Operator can only be used with boolean values\n");
                                                }
                                            }
    ;

values:
    variableValue       {
                            $$= $1;
                        }        
    | INTEGER_LITERAL   {
                            $$.value_type = 2;
                           
                        }              
    | FLOAT_LITERAL     {
                            $$.value_type = 3;
                        } 
    | STRING_LITERAL    {
                            $$.value_type = 4;
                        } 
    | CHAR_LITERAL      {
                            $$.value_type = 5;
                        }
    | BOOLEAN_TRUE      {
                            $$.value_type = 6;
                        }
    | BOOLEAN_FALSE     {
                            $$.value_type = 6;
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
                                    $$.var_type=node->datatype; 
                                    $$.var_init=node->init;
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
    VARIABLE PLUS_ASSIGN expression     {}
    | VARIABLE MINUS_ASSIGN expression  {} 
    | VARIABLE MULTIPLY_ASSIGN expression   {} 
    | VARIABLE DIVIDE_ASSIGN expression     {} 

    ;

forStatement:
FOR ForBracket forScope    {  
                                                                                                
                                // Head_for_push();
                                // struct Node *var = getHead();push(var);
                                //if for loop is in start of the program
                            }
    ;
bora3y:
INT VARIABLE ASSIGN INTEGER_LITERAL { scopePush();createNode($2,"int","variable",1,line);};

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
    REPEAT openScope  inBlockscope closeScope UNTIL '(' comparators ')' ';'  {printf("Repeat Until Statement scope\n");}
;
%%

int main() {
    initializeList();
    yyparse();
    displayList();
    return 0;
}
int yyerror(char *s) {
    printf("\nERROR: %s\n", s);
    return 0;
}
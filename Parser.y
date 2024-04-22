%{
    int yyerror(char *s); 
    int yylex(void);
    #include <stdio.h>
	#include <stdlib.h>
	#include <stdarg.h>
	#include <string.h>	
    #include <stdbool.h>
    

%}
%union{
	int integerval;               /* integer value */
	float floatval;               /* float Value */
    char * stringval;             /* string value */
	char  charval;               /* character value */
	char * varval ;                    	/* VARIABLE Value */
    bool boolval;               /* boolean value */
}
        //Data Types
%token  INT FLOAT STRING CHAR CONST ENUM VOID BOOL

        //Keywords
%token IF ELSE WHILE FOR SWITCH CASE DEFAULT BREAK CONTINUE RETURN REPEAT UNTIL
        


        //Values     
%token  <stringval> STRING_LITERAL 
%token  <charval>CHAR_LITERAL 
%token  <integerval>INTEGER_LITERAL 
%token  <floatval>FLOAT_LITERAL
%token  <boolval> BOOLEAN_TRUE 
%token  <boolval> BOOLEAN_FALSE 

        //Variable
%token  <varval>VARIABLE

        //Mathematical Operators
%token PLUS MINUS MULTIPLY DIVIDE 

        //Logical Operators
%token AND OR NOT

        //Relational Operators
%token EQUAL NOT_EQUAL GREATER LESS GREATER_EQUAL LESS_EQUAL 

        //Assignment Operator   
%token ASSIGN PLUS_ASSIGN MINUS_ASSIGN MULTIPLY_ASSIGN DIVIDE_ASSIGN INCREMENT DECREMENT

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
    | programStatements     {printf("Program Finished\n");}
    ; 

programStatements:         
    typeSpecifier VARIABLE '(' parameters ')' '{' programStatements '}' {printf("Function Declaration\n");} 
    | typeSpecifier VARIABLE '('')' '{' programStatements '}'  {printf("Function Declaration with no parameters\n");}      {printf("Program statements\n");}
    | programStatements statement  
    | statement
    ;


statement:                 
    declaration ';'           {printf("declaration\n");}
    | assignment ';'        {printf("Assignment\n");} 
    /* | expression ';'        {printf("Expression\n");} */
    | ifStatement           {printf("If Statement\n");}
    | whileStatement        {printf("While Statement\n");}
    | forStatement          {printf("For Statement\n");} 
    | switchStatement       {printf("Switch Statement\n");}
    | returnStatement       {printf("Return Statement\n");}
    | repeatUntilStatement  {printf("Repeat Until Statement\n");}
    | functionCall       {printf("Function Call\n");}
    | enumStatement         {printf("Enum Statement\n");}
    | VARIABLE ASSIGN functionCall       {printf("Function Call with Assignment\n");}
    | typeSpecifier VARIABLE ASSIGN functionCall     {printf("Function Call with Assignment\n");}  
    | BREAK ';'        {printf("Break\n");}
    | CONTINUE ';'      {printf("Continue\n");}
    /* |';'                {printf("Semicolon\n");} */
    ;  

functionCall:               
    VARIABLE '(' ')' ';'               {printf("Function Call\n");}
    | VARIABLE '(' callParameters ')' ';'  {printf("Function Call with Parameters\n");}
    ;

callParameters:             
    VARIABLE    {printf("Parameter\n");}
    | callParameters ',' VARIABLE   {printf("Multiple  Parameters\n");}
    ;

/* functionDeclaration:        
    ; */

enumStatement:             
    ENUM VARIABLE '{' enumValues '}' ';' {printf("Enum Statement\n");}
    ;

enumValues:                 
    VARIABLE {printf("Enum Value\n");}
    | enumValues ',' VARIABLE   {printf("Multiple Enum Values\n");}
    ;

parameters:                 
    typeSpecifier VARIABLE      {printf("Parameters\n");}
    | parameters ',' typeSpecifier VARIABLE     {printf("Multiple Parameters\n");}
    ;

declaration:
    typeSpecifier VARIABLE     {printf("Declaration with no assignment\n");}
    | typeSpecifier VARIABLE ASSIGN expression  {printf("Declaration with Assignment\n");}
    ;

typeSpecifier:
    INT         {printf("int\n");}
    | FLOAT     {printf("Float\n");}                          
    | STRING    {printf("String\n");} 
    | CHAR      {printf("Char\n");} 
    | CONST     {printf("Const\n");}
    | VOID      {printf("Void\n");}
    | BOOL      {printf("Bool\n");}
    ;

assignment:
    VARIABLE ASSIGN expression       {printf("Assignment\n");}
    | VARIABLE PLUS_ASSIGN expression       {printf("Plus Assignment\n");}
    | VARIABLE MINUS_ASSIGN expression      {printf("Minus Assignment\n");}
    | VARIABLE MULTIPLY_ASSIGN expression   {printf("Multiply Assignment\n");}
    | VARIABLE DIVIDE_ASSIGN expression     {printf("Divide Assignment\n");}
    | crements                {printf("Crements\n");}
    ;

crements:
    VARIABLE INCREMENT             {printf("Increment\n");}
    | VARIABLE DECREMENT            {printf("Decrement\n");}
    ;

expression:
    Mathematicalexpressions         {printf("Expression\n");}
    | comparators                   {printf("Comparators\n");}                   
    | '(' expression ')'            {printf("Bracket Expression\n");}
    | values                        {printf("Values\n");}
    ;

Mathematicalexpressions:
    expression PLUS expression          {printf("Mathematical Expressions\n");}
    | expression MINUS expression       {printf("Minus Expressions\n");}
    | expression MULTIPLY expression    {printf("Multiply Expressions\n");}
    | expression DIVIDE expression      {printf("Divide Expressions\n");}
    | crements                          {printf("Crements\n");}
    ;

comparators:
    values EQUAL values         {printf("Equal\n");}
    | values NOT_EQUAL values   {printf("Not Equal\n");}
    | values GREATER values     {printf("Greater\n");}
    | values LESS values        {printf("Less\n");}
    | values GREATER_EQUAL values   {printf("Greater Equal\n");}
    | values LESS_EQUAL values      {printf("Less Equal\n");}
    | VARIABLE AND VARIABLE             {printf("And\n");}
    | VARIABLE OR VARIABLE              {printf("Or\n");}
    | NOT VARIABLE                    {printf("Not\n");}
    ;

values:
     VARIABLE           {printf("Variable\n");}
    | INTEGER_LITERAL   {printf("Integer Literal\n");}              
    | FLOAT_LITERAL     {printf("Float Literal\n");} 
    | STRING_LITERAL    {printf("String Literal\n");} 
    | CHAR_LITERAL      {printf("Char Literal\n");}
    | BOOLEAN_TRUE      {printf("Boolean True\n");}
    | BOOLEAN_FALSE     {printf("Boolean False\n");}
    ;
ifStatement:
    IF '(' comparators ')' statement    {printf("If Single Statement with comparators\n");} 
    | IF '(' comparators ')' statement  ELSE statement  {printf("If Else Single Statement with comparators\n");}
    | IF '(' comparators ')' '{' programStatements '}'  {printf("If Multiple Statements with comparators\n");}
    | IF '(' comparators ')' '{' programStatements '}' ELSE '{' programStatements '}'   {printf("If Else Multiple Statements with comparators\n");}
    | IF '(' comparators ')' '{' programStatements '}' ELSE statement   {printf("If Multiple Statements Else Single Statement with comparators\n");}
    | IF '(' comparators ')' statement ELSE '{' programStatements '}'   {printf("If Single Statement Else Multiple Statements with comparators\n");}
    | IF '(' VARIABLE ')' statement    {printf("If Single Statement with VARIABLE\n");} 
    | IF '(' VARIABLE ')' statement  ELSE statement  {printf("If Else Single Statement with VARIABLE\n");}
    | IF '(' VARIABLE ')' '{' programStatements '}'  {printf("If Multiple Statements with VARIABLE\n");}
    | IF '(' VARIABLE ')' '{' programStatements '}' ELSE '{' programStatements '}'   {printf("If Else Multiple Statements with VARIABLE\n");}
    | IF '(' VARIABLE ')' '{' programStatements '}' ELSE statement   {printf("If Multiple Statements Else Single Statement with VARIABLE\n");}
    | IF '(' VARIABLE ')' statement ELSE '{' programStatements '}'   {printf("If Single Statement Else Multiple Statements with VARIABLE\n");}
    ;

whileStatement:
    WHILE '(' expression ')' statement      {printf("While Single Statement\n");}
    | WHILE '(' expression ')' '{' programStatements '}'    {printf("While Multiple Statements\n");}
    ;

forExpression:

    VARIABLE PLUS_ASSIGN expression     {printf("For statement Variable Plus Equal\n");}
    | VARIABLE MINUS_ASSIGN expression  {printf("For statement Variable Minus Equal\n");} 
    | VARIABLE MULTIPLY_ASSIGN expression   {printf("For statement Variable Multiply Equal\n");} 
    | VARIABLE DIVIDE_ASSIGN expression     {printf("For statement Variable Divide Equal\n");} 
    | crements                          {printf("For statement Crements\n");} 
    ;

forStatement:
    FOR '(' INT VARIABLE ASSIGN INTEGER_LITERAL ';' comparators ';' forExpression ')' statement   {printf("For Single Statement\n");}
    | FOR '(' INT VARIABLE ASSIGN INTEGER_LITERAL ';' comparators ';' forExpression ')' '{' programStatements '}'   {printf("For Multiple Statements\n");}
    ;

switchStatement:
    SWITCH '(' VARIABLE ')' '{' caseStatements '}'  {printf("Switch Statement\n");}
    ;

caseStatements:
    CASE INTEGER_LITERAL ':' programStatements  BREAK ';'   {printf("Case Statement\n");}
    | DEFAULT ':' programStatements     {printf("Default Statement\n");}
    ;

returnStatement:
    RETURN expression ';'   {printf("Return Statement with expression\n");}
    | RETURN ';'    {printf("Return Statement without expression\n");}
    ;

repeatUntilStatement:
    REPEAT '{' programStatements '}' UNTIL '(' comparators ')' ';'  {printf("Repeat Until Statement\n");}
;
%%

int main() {
    yyparse();

    return 0;
}

int yyerror(char *s) {
    printf("\nERROR: %s\n", s);
    return 0;
}
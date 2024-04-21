%{
    int yyerror(char *s); 
    int yylex(void);

%}

        //Data Types
%token INT FLOAT STRING CHAR CONST ENUM VOID

        //Keywords
%token IF ELSE WHILE FOR SWITCH CASE DEFAULT BREAK CONTINUE RETURN REPEAT UNTIL
        
        //Boolean values
%token BOOLEAN_TRUE BOOLEAN_FALSE 

        //Values     
%token STRING_LITERAL CHAR_LITERAL INTEGER_LITERAL FLOAT_LITERAL

        //Variable
%token VARIABLE

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

program:                    {printf("Program is empty\n")}     
    | programStatements 
    ; 

programStatements:          {printf("Program statements\n")}
    programStatements statement 
    |statement 
    |functionDeclaration
    ;


statement:
    declaration ';' 
    | assignment ';' 
    | expression ';' 
    | ifStatement 
    | whileStatement 
    | forStatement 
    | switchStatement 
    | returnStatement 
    | repeatUntilStatement
    | functionCall ';'
    | VARIABLE ASSIGN functionCall ';'
    | typeSpecifier VARIABLE ASSIGN functionCall ';'  
    | BREAK ';'
    | CONTINUE ';'
    ;  

functionCall:
    VARIABLE '(' ')' 
    | VARIABLE '(' callParameters ')'
    ;

callParameters:
    VARIABLE 
    | callParameters ',' VARIABLE 
    ;

functionDeclaration:
    typeSpecifier VARIABLE '(' parameters ')' '{' programStatements '}' 
    | typeSpecifier VARIABLE '(' ')' '{' programStatements '}'
    | VOID 
    ;

enumStatement:
    ENUM VARIABLE '{' enumValues '}' ';'
    ;

enumValues:
    VARIABLE 
    | enumValues ',' VARIABLE 
    ;

parameters:
    typeSpecifier VARIABLE 
    | parameters ',' typeSpecifier VARIABLE 
    ;

declaration:
    typeSpecifier VARIABLE 
    | typeSpecifier VARIABLE ASSIGN expression 
    ;

typeSpecifier:
    INT 
    | FLOAT 
    | STRING 
    | CHAR 
    | CONST  
    | VOID 
    ;

assignment:
    VARIABLE ASSIGN expression 
    | VARIABLE PLUS_ASSIGN expression 
    | VARIABLE MINUS_ASSIGN expression 
    | VARIABLE MULTIPLY_ASSIGN expression 
    | VARIABLE DIVIDE_ASSIGN expression 
    |crements 
    ;

crements:
    VARIABLE INCREMENT 
    | VARIABLE DECREMENT 
    ;

expression:
    Mathematicalexpressions
    | expression AND expression 
    | expression OR expression 
    | NOT expression 
    | comparators
    | '(' expression ')' 
    | values
    ;

Mathematicalexpressions:
    expression PLUS expression 
    | expression MINUS expression 
    | expression MULTIPLY expression 
    | expression DIVIDE expression
    | crements
    ;

comparators:
    expression EQUAL expression 
    | expression NOT_EQUAL expression 
    | expression GREATER expression 
    | expression LESS expression 
    | expression GREATER_EQUAL expression 
    | expression LESS_EQUAL expression 
    ;

values:
     VARIABLE 
    | INTEGER_LITERAL 
    | FLOAT_LITERAL 
    | STRING_LITERAL 
    | CHAR_LITERAL
    | BOOLEAN_TRUE
    | BOOLEAN_FALSE
    ;
ifStatement:
    IF '(' comparators ')' statement 
    | IF '(' comparators ')' statement  ELSE statement
    | IF '(' comparators ')' '{' programStatements '}'
    | IF '(' comparators ')' '{' programStatements '}' ELSE '{' programStatements '}' 
    ;

whileStatement:
    WHILE '(' expression ')' statement 
    | WHILE '(' expression ')' '{' programStatements '}' 
    ;

forExpression:

    VARIABLE PLUS_ASSIGN expression 
    | VARIABLE MINUS_ASSIGN expression 
    | VARIABLE MULTIPLY_ASSIGN expression 
    | VARIABLE DIVIDE_ASSIGN expression 
    | crements 

forStatement:
    FOR '(' INT VARIABLE ASSIGN INTEGER_LITERAL ';' comparators ';' forExpression ')' statement
    | FOR '(' INT VARIABLE ASSIGN INTEGER_LITERAL ';' comparators ';' forExpression ')' '{' programStatements '}'
    ;

switchStatement:
    SWITCH '(' VARIABLE ')' '{' caseStatements '}'
    ;

caseStatements:
    CASE INTEGER_LITERAL ':' programStatements  BREAK ';'
    | DEFAULT ':' programStatements
    ;

returnStatement:
    RETURN expression ';'
    | RETURN ';'
    ;

repeatUntilStatement:
    REPEAT '{' programStatements '}' UNTIL '(' comparators ')' ';'
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
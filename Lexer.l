%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <string.h>
    #include "y.tab.h"
    int yyerror(char *s); 
%}

%%
        /*we need to capture:
        - integers 0|[1-9][0-9]*
        - floats [0-9]*\.[0-9]+
        - strings (variables)[_A-Za-z][_A-Za-z0-9]*
        - operators +|-|*|/|==|!=|<=|>=|<|>|=|+=|-=|*=|/=|++|--|&&| ||
        - comments 
        - keywords (if|else|while|for|return|break|continue|switch|case|default|void|int|float|string|char|const|enum|true|false)
        */ 

        /*Integers and floats*/

0|[1-9][0-9]*  { yylval.integerval = atoi(yytext);return INTEGER_LITERAL; }             /* Match a number */
[0-9]*\.[0-9]+  { yylval.floatval = atof(yytext);return FLOAT_LITERAL; }                 /* Match a float */

        /*Keywords*/
"if"                { return IF; }
"else"              { return ELSE; }
"while"             { return WHILE; }
"for"               { return FOR; }
"return"            { return RETURN; }
"break"             { return BREAK; }
"continue"          { return CONTINUE; }
"switch"            { return SWITCH; }
"case"              { return CASE; }
"repeat"            { return REPEAT; }
"until"             { return UNTIL; }
"default"           { return DEFAULT; }

"void"              { return VOID; }
"int"               { return INT; }
"float"             { return FLOAT; }
"string"            { return STRING; }
"char"              { return CHAR; }
"const"             { return CONST; }
"enum"              { return ENUM; }
"bool"              { return BOOL; }
"true"              { yylval.boolval = true; return BOOLEAN_TRUE; }
"false"             { yylval.boolval = false; return BOOLEAN_FALSE; }

        /* Variable names*/

[_A-Za-z][_A-Za-z0-9]*  { yylval.varval = strdup(yytext); return VARIABLE; }    /* Match a variable name */

        /*Strings and characters*/

\"[a-zA-Z0-9_\-!@#$%~\^&\*\(\)\[\]\+\?']*\"  { yylval.stringval = strdup(yytext); return STRING_LITERAL; }    /* Match a string */
\'[a-zA-Z0-9]\' { yylval.charval = yytext[1]; return CHAR_LITERAL; }    /* Match a character */

        /*Operators*/

"+"                { return PLUS; }
"-"                { return MINUS; }
"*"                { return MULTIPLY; }
"/"                { return DIVIDE; }

"=="               { return EQUAL; } //logical equal
"!="               { return NOT_EQUAL; }
">"                { return GREATER; }
"<"                { return LESS; }
"<="               { return LESS_EQUAL; }
">="               { return GREATER_EQUAL; }

"="                { return ASSIGN; } //assignment statement
"+="               { return PLUS_ASSIGN; }
"-="               { return MINUS_ASSIGN; }
"*="               { return MULTIPLY_ASSIGN; }
"/="               { return DIVIDE_ASSIGN; }
"++"               { return INCREMENT; }
"--"               { return DECREMENT; }

"&&"               { return AND; }
"||"               { return OR; }
"!"                { return NOT; }

        /*Punctuation*/

[;,:]             { return yytext[0]; }
[(){}\[\]]          { return yytext[0]; }
        /*Comments*/ 

\/\/[^\n]*             { /* ignore single line comments */ };
\/\*([^*]|\*[^\/])*\*\/        { /* ignore multi line comments */ };

            /*Whitespace*/

[ \t]+           { /* ignore whitespace */ };

.               { yyerror("Unrecognized character"); }

%%

int yywrap(void) {
    return 1;
}
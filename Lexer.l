%{
    #include <stdio.h>
    #include "Parser.tab.h"
    int yyerror(char *s); 
%}

%%
        /*we need to capture:
        - integers 0|[1-9][0-9]*
        - floats [0-9]*\.[0-9]+
        - strings (variables)[_A-Za-z][_A-Za-z0-9]*
        - operators +|-|*|/|==|!=|<=|>=|<|>|=|+=|-=|*=|/=|++|--|&&| ||
        - comments 
        - keywords (if|else|while|for|return|break|continue|switch|case|default|void|int|float|string|char|const|auto|enum|true|false)
        */ 

        /*Integers and floats*/

0|[1-9][0-9]*  { yylval.integerval = atoi(yytext);return INTEGER; }             /* Match a number */
[0-9]*\.[0-9]+  { yylval.floatval = atof(yytext);return FLOAT; }                 /* Match a float */

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
"default"           { return DEFAULT; }
"void"              { return VOID; }
"int"               { return INT; }
"float"             { return FLOAT; }
"string"            { return STRING; }
"char"              { return CHAR; }
"const"             { return CONST; }
"auto"              { return AUTO; }
"enum"              { return ENUM; }
"true"              { yylval.boolval = TRUE; return BOOL_TRUE; }
"false"             { yylval.boolval = FALSE; return BOOL_FALSE; }

        /* Variable names*/

[_A-Za-z][_A-Za-z0-9]*  { yylval.stringval = strdup(yytext); return VARIABLE; }    /* Match a variable name */

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
"<="               { return LESS_EQUAL; }
">="               { return GREATER_EQUAL; }
"<"                { return LESS; }
">"                { return GREATER; }
"="                { return ASSIGN; } //assignment statement
"+="               { return PLUS_ASSIGN; }
"-="               { return MINUS_ASSIGN; }
"*="               { return MULTIPLY_ASSIGN; }
"/="               { return DIVIDE_ASSIGN; }
"++"               { return INCREMENT; }
"--"               { return DECREMENT; }
"&&"               { return AND; }
"||"               { return OR; }

        /*Punctuation*/

[;,:]             { return yytext[0]; }
[(){}\[\]]          { return yytext[0]; }
        /*Comments*/ 

\/\/[^\n]*             { /* ignore single line comments */ };
\/\*([^*]|\*[^\/])*\*\/        { /* ignore multi line comments */ };

            /*Whitespace*/

[ \t\n]+           { /* ignore whitespace */ };

.               { yyerror("Unrecognized character"); }

%%

int yywrap(void) {
    return 1;
}
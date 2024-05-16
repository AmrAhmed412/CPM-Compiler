
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INT = 258,
     FLOAT = 259,
     STRING = 260,
     CHAR = 261,
     CONST = 262,
     VOID = 263,
     BOOL = 264,
     IF = 265,
     ELSE = 266,
     WHILE = 267,
     FOR = 268,
     SWITCH = 269,
     CASE = 270,
     DEFAULT = 271,
     BREAK = 272,
     CONTINUE = 273,
     RETURN = 274,
     REPEAT = 275,
     UNTIL = 276,
     STRING_LITERAL = 277,
     CHAR_LITERAL = 278,
     INTEGER_LITERAL = 279,
     FLOAT_LITERAL = 280,
     BOOLEAN_TRUE = 281,
     BOOLEAN_FALSE = 282,
     VARIABLE = 283,
     PLUS = 284,
     MINUS = 285,
     MULTIPLY = 286,
     DIVIDE = 287,
     AND = 288,
     OR = 289,
     NOT = 290,
     EQUAL = 291,
     NOT_EQUAL = 292,
     GREATER = 293,
     LESS = 294,
     GREATER_EQUAL = 295,
     LESS_EQUAL = 296,
     ASSIGN = 297,
     PLUS_ASSIGN = 298,
     MINUS_ASSIGN = 299,
     MULTIPLY_ASSIGN = 300,
     DIVIDE_ASSIGN = 301
   };
#endif
/* Tokens.  */
#define INT 258
#define FLOAT 259
#define STRING 260
#define CHAR 261
#define CONST 262
#define VOID 263
#define BOOL 264
#define IF 265
#define ELSE 266
#define WHILE 267
#define FOR 268
#define SWITCH 269
#define CASE 270
#define DEFAULT 271
#define BREAK 272
#define CONTINUE 273
#define RETURN 274
#define REPEAT 275
#define UNTIL 276
#define STRING_LITERAL 277
#define CHAR_LITERAL 278
#define INTEGER_LITERAL 279
#define FLOAT_LITERAL 280
#define BOOLEAN_TRUE 281
#define BOOLEAN_FALSE 282
#define VARIABLE 283
#define PLUS 284
#define MINUS 285
#define MULTIPLY 286
#define DIVIDE 287
#define AND 288
#define OR 289
#define NOT 290
#define EQUAL 291
#define NOT_EQUAL 292
#define GREATER 293
#define LESS 294
#define GREATER_EQUAL 295
#define LESS_EQUAL 296
#define ASSIGN 297
#define PLUS_ASSIGN 298
#define MINUS_ASSIGN 299
#define MULTIPLY_ASSIGN 300
#define DIVIDE_ASSIGN 301




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 20 "Parser.y"

    char* type;                     /* data type    */
	int integerval;                /* integer value */
	float floatval;               /* float Value    */
    char * stringval;            /* string value    */
	char  charval;              /* character value  */
    char * varval ;            /* VARIABLE Value    */
    int boolval;              /* boolean value      */
    int compare;             /* comparison value    */

    struct {
    int value_type; //1-6 for variable, int, float, string, char, bool
    char* var_type; //datatype of variable
    int var_init;   //if variable is initialized or not
    char* var_name; //name of variable
    int isUsed_in_Calc;
    }terminal_values; /* terminal values */

    struct {
   

    }callParameters;

    




/* Line 1676 of yacc.c  */
#line 173 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;



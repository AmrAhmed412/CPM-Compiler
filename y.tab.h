
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
     ENUM = 263,
     VOID = 264,
     BOOL = 265,
     IF = 266,
     ELSE = 267,
     WHILE = 268,
     FOR = 269,
     SWITCH = 270,
     CASE = 271,
     DEFAULT = 272,
     BREAK = 273,
     CONTINUE = 274,
     RETURN = 275,
     REPEAT = 276,
     UNTIL = 277,
     STRING_LITERAL = 278,
     CHAR_LITERAL = 279,
     INTEGER_LITERAL = 280,
     FLOAT_LITERAL = 281,
     BOOLEAN_TRUE = 282,
     BOOLEAN_FALSE = 283,
     VARIABLE = 284,
     PLUS = 285,
     MINUS = 286,
     MULTIPLY = 287,
     DIVIDE = 288,
     AND = 289,
     OR = 290,
     NOT = 291,
     EQUAL = 292,
     NOT_EQUAL = 293,
     GREATER = 294,
     LESS = 295,
     GREATER_EQUAL = 296,
     LESS_EQUAL = 297,
     ASSIGN = 298,
     PLUS_ASSIGN = 299,
     MINUS_ASSIGN = 300,
     MULTIPLY_ASSIGN = 301,
     DIVIDE_ASSIGN = 302,
     INCREMENT = 303,
     DECREMENT = 304
   };
#endif
/* Tokens.  */
#define INT 258
#define FLOAT 259
#define STRING 260
#define CHAR 261
#define CONST 262
#define ENUM 263
#define VOID 264
#define BOOL 265
#define IF 266
#define ELSE 267
#define WHILE 268
#define FOR 269
#define SWITCH 270
#define CASE 271
#define DEFAULT 272
#define BREAK 273
#define CONTINUE 274
#define RETURN 275
#define REPEAT 276
#define UNTIL 277
#define STRING_LITERAL 278
#define CHAR_LITERAL 279
#define INTEGER_LITERAL 280
#define FLOAT_LITERAL 281
#define BOOLEAN_TRUE 282
#define BOOLEAN_FALSE 283
#define VARIABLE 284
#define PLUS 285
#define MINUS 286
#define MULTIPLY 287
#define DIVIDE 288
#define AND 289
#define OR 290
#define NOT 291
#define EQUAL 292
#define NOT_EQUAL 293
#define GREATER 294
#define LESS 295
#define GREATER_EQUAL 296
#define LESS_EQUAL 297
#define ASSIGN 298
#define PLUS_ASSIGN 299
#define MINUS_ASSIGN 300
#define MULTIPLY_ASSIGN 301
#define DIVIDE_ASSIGN 302
#define INCREMENT 303
#define DECREMENT 304




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 12 "Parser.y"

	int integerval;               /* integer value */
	float floatval;               /* float Value */
    char * stringval;             /* string value */
	char  charval;               /* character value */
	char * varval ;                    	/* VARIABLE Value */
    bool boolval;               /* boolean value */



/* Line 1676 of yacc.c  */
#line 161 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;



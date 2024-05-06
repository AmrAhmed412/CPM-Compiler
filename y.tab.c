
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "Parser.y"

    int yyerror(char *s); 
    int yylex(void);
    #include <stdio.h>
	#include <stdlib.h>
	#include <stdarg.h>
	#include <string.h>	
    #include <stdbool.h>
    



/* Line 189 of yacc.c  */
#line 86 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


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

/* Line 214 of yacc.c  */
#line 12 "Parser.y"

	int integerval;               /* integer value */
	float floatval;               /* float Value */
    char * stringval;             /* string value */
	char  charval;               /* character value */
	char * varval ;                    	/* VARIABLE Value */
    bool boolval;               /* boolean value */



/* Line 214 of yacc.c  */
#line 231 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 243 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  73
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1089

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  106
/* YYNRULES -- Number of states.  */
#define YYNSTATES  238

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   304

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      50,    51,     2,     2,    55,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    56,    54,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    52,     2,    53,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     6,     9,    19,    28,    37,    45,
      47,    50,    52,    55,    58,    60,    62,    64,    66,    68,
      70,    72,    74,    78,    83,    86,    89,    92,    97,   103,
     105,   109,   116,   118,   122,   125,   130,   133,   138,   142,
     148,   150,   152,   154,   156,   158,   160,   162,   166,   170,
     174,   178,   182,   184,   187,   190,   193,   196,   200,   204,
     206,   210,   214,   216,   220,   222,   224,   226,   230,   234,
     238,   242,   246,   250,   254,   258,   261,   263,   265,   267,
     269,   271,   273,   275,   277,   279,   288,   296,   305,   313,
     318,   324,   332,   336,   340,   344,   348,   350,   363,   378,
     386,   394,   400,   410,   418,   422,   425
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      58,     0,    -1,    -1,    59,    -1,    61,    59,    -1,    68,
      29,    50,    66,    51,    52,    60,    53,    59,    -1,    68,
      29,    50,    51,    52,    60,    53,    59,    -1,    68,    29,
      50,    66,    51,    52,    60,    53,    -1,    68,    29,    50,
      51,    52,    60,    53,    -1,    61,    -1,    60,    61,    -1,
      61,    -1,    67,    54,    -1,    69,    54,    -1,    76,    -1,
      80,    -1,    82,    -1,    83,    -1,    85,    -1,    86,    -1,
      62,    -1,    64,    -1,    29,    43,    62,    -1,    68,    29,
      43,    62,    -1,    18,    54,    -1,    19,    54,    -1,     1,
      54,    -1,    29,    50,    51,    54,    -1,    29,    50,    63,
      51,    54,    -1,    75,    -1,    63,    55,    75,    -1,     8,
      29,    52,    65,    53,    54,    -1,    29,    -1,    65,    55,
      29,    -1,    68,    29,    -1,    66,    55,    68,    29,    -1,
      68,    29,    -1,    68,    29,    43,    71,    -1,     8,    29,
      29,    -1,     8,    29,    29,    43,    29,    -1,     3,    -1,
       4,    -1,     5,    -1,     6,    -1,     7,    -1,     9,    -1,
      10,    -1,    29,    43,    71,    -1,    29,    44,    71,    -1,
      29,    45,    71,    -1,    29,    46,    71,    -1,    29,    47,
      71,    -1,    70,    -1,    29,    48,    -1,    29,    49,    -1,
      48,    29,    -1,    49,    29,    -1,    71,    30,    72,    -1,
      71,    31,    72,    -1,    72,    -1,    72,    32,    73,    -1,
      72,    33,    73,    -1,    73,    -1,    50,    71,    51,    -1,
      75,    -1,    70,    -1,    74,    -1,    75,    37,    75,    -1,
      75,    38,    75,    -1,    75,    39,    75,    -1,    75,    40,
      75,    -1,    75,    41,    75,    -1,    75,    42,    75,    -1,
      29,    34,    29,    -1,    29,    35,    29,    -1,    36,    29,
      -1,    29,    -1,    25,    -1,    26,    -1,    23,    -1,    24,
      -1,    27,    -1,    28,    -1,    77,    -1,    78,    -1,    11,
      50,    74,    51,    52,    60,    53,    79,    -1,    11,    50,
      74,    51,    52,    60,    53,    -1,    11,    50,    29,    51,
      52,    60,    53,    79,    -1,    11,    50,    29,    51,    52,
      60,    53,    -1,    12,    52,    60,    53,    -1,    13,    50,
      71,    51,    61,    -1,    13,    50,    71,    51,    52,    60,
      53,    -1,    29,    44,    71,    -1,    29,    45,    71,    -1,
      29,    46,    71,    -1,    29,    47,    71,    -1,    70,    -1,
      14,    50,     3,    29,    43,    25,    54,    74,    54,    81,
      51,    61,    -1,    14,    50,     3,    29,    43,    25,    54,
      74,    54,    81,    51,    52,    60,    53,    -1,    15,    50,
      29,    51,    52,    84,    53,    -1,    16,    25,    56,    61,
      18,    54,    84,    -1,    17,    56,    61,    18,    54,    -1,
      16,    25,    56,    52,    60,    18,    54,    53,    84,    -1,
      17,    56,    52,    60,    18,    54,    53,    -1,    20,    71,
      54,    -1,    20,    54,    -1,    21,    52,    60,    53,    22,
      50,    74,    51,    54,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    65,    65,    66,    70,    71,    72,    73,    74,    75,
      79,    80,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,   102,   103,   107,
     108,   115,   119,   120,   124,   125,   129,   130,   131,   132,
     136,   137,   138,   139,   140,   141,   142,   146,   147,   148,
     149,   150,   151,   155,   156,   157,   158,   177,   178,   179,
     183,   184,   185,   189,   190,   191,   192,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   208,   209,   210,   211,
     212,   213,   214,   235,   236,   240,   241,   244,   245,   249,
     274,   275,   280,   281,   282,   283,   284,   288,   289,   293,
     297,   298,   299,   300,   304,   305,   309
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "FLOAT", "STRING", "CHAR",
  "CONST", "ENUM", "VOID", "BOOL", "IF", "ELSE", "WHILE", "FOR", "SWITCH",
  "CASE", "DEFAULT", "BREAK", "CONTINUE", "RETURN", "REPEAT", "UNTIL",
  "STRING_LITERAL", "CHAR_LITERAL", "INTEGER_LITERAL", "FLOAT_LITERAL",
  "BOOLEAN_TRUE", "BOOLEAN_FALSE", "VARIABLE", "PLUS", "MINUS", "MULTIPLY",
  "DIVIDE", "AND", "OR", "NOT", "EQUAL", "NOT_EQUAL", "GREATER", "LESS",
  "GREATER_EQUAL", "LESS_EQUAL", "ASSIGN", "PLUS_ASSIGN", "MINUS_ASSIGN",
  "MULTIPLY_ASSIGN", "DIVIDE_ASSIGN", "INCREMENT", "DECREMENT", "'('",
  "')'", "'{'", "'}'", "';'", "','", "':'", "$accept", "program",
  "programStatements", "inBlockscope", "statement", "functionCall",
  "callParameters", "enumStatement", "enumValues", "parameters",
  "declaration", "typeSpecifier", "assignment", "crements", "expression",
  "term", "factor", "comparators", "values", "ifStatement",
  "ifComparators", "ifVariable", "elseClause", "whileStatement",
  "forExpression", "forStatement", "switchStatement", "caseStatements",
  "returnStatement", "repeatUntilStatement", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
      40,    41,   123,   125,    59,    44,    58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    57,    58,    58,    59,    59,    59,    59,    59,    59,
      60,    60,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    62,    62,    63,
      63,    64,    65,    65,    66,    66,    67,    67,    67,    67,
      68,    68,    68,    68,    68,    68,    68,    69,    69,    69,
      69,    69,    69,    70,    70,    70,    70,    71,    71,    71,
      72,    72,    72,    73,    73,    73,    73,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    75,    75,    75,    75,
      75,    75,    75,    76,    76,    77,    77,    78,    78,    79,
      80,    80,    81,    81,    81,    81,    81,    82,    82,    83,
      84,    84,    84,    84,    85,    85,    86
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     1,     2,     9,     8,     8,     7,     1,
       2,     1,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     4,     2,     2,     2,     4,     5,     1,
       3,     6,     1,     3,     2,     4,     2,     4,     3,     5,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     3,
       3,     3,     1,     2,     2,     2,     2,     3,     3,     1,
       3,     3,     1,     3,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     8,     7,     8,     7,     4,
       5,     7,     3,     3,     3,     3,     1,    12,    14,     7,
       7,     5,     9,     7,     3,     2,     9
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    40,    41,    42,    43,    44,     0,    45,    46,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     3,     0,    20,    21,     0,     0,     0,    52,
      14,    83,    84,    15,    16,    17,    18,    19,    26,     0,
       0,     0,     0,     0,    24,    25,    79,    80,    77,    78,
      81,    82,    76,     0,     0,   105,    65,     0,    59,    62,
      66,    64,     0,     0,     0,     0,     0,     0,    53,    54,
       0,    55,    56,     1,     4,    12,    36,    13,    38,     0,
      76,     0,     0,     0,     0,     0,     0,     0,    75,     0,
       0,     0,   104,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    11,     0,    76,    22,    47,    48,    49,    50,
      51,    76,     0,     0,    29,     0,     0,     0,    32,     0,
       0,     0,     0,     0,     0,    73,    74,    63,    57,    58,
      60,    61,    67,    68,    69,    70,    71,    72,     0,    10,
      36,    27,     0,     0,    23,    37,     0,     0,     0,    39,
       0,     0,     0,     0,     0,    90,     0,     0,     0,    28,
      30,     0,     0,     0,    34,    31,    33,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    88,    86,
      91,     0,     0,     0,    99,    76,     0,     0,     0,    35,
       0,    87,    85,     0,     0,     0,     0,     0,     6,     0,
       0,     0,     0,     0,     0,     0,   106,     5,     0,     0,
      96,     0,     0,     0,     0,   101,    89,     0,     0,     0,
       0,     0,     0,     0,    24,    92,    93,    94,    95,     0,
      97,    24,   100,   103,     0,     0,    98,   102
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    21,    22,   101,   102,    24,   113,    25,   119,   147,
      26,   103,    28,    29,    57,    58,    59,    60,    61,    30,
      31,    32,   191,    33,   211,    34,    35,   173,    36,    37
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -180
static const yytype_int16 yypact[] =
{
     840,   -46,  -180,  -180,  -180,  -180,  -180,   -18,  -180,  -180,
     -23,    38,    41,    50,    -6,    25,    -7,   -28,   270,    75,
      83,   127,  -180,   872,  -180,  -180,    98,   103,   107,  -180,
    -180,  -180,  -180,  -180,  -180,  -180,  -180,  -180,  -180,   -22,
     231,   130,   131,   114,  -180,  -180,  -180,  -180,  -180,  -180,
    -180,  -180,    71,   135,   130,  -180,  -180,   -26,    39,  -180,
    -180,    99,   968,  1039,   130,   130,   130,   130,  -180,  -180,
      70,  -180,  -180,  -180,  -180,  -180,    60,  -180,   128,   145,
     -20,   125,    99,    27,   148,   133,   152,   156,  -180,    51,
     130,   130,  -180,   130,   130,   282,   282,   282,   282,   282,
     282,   232,  -180,   157,    80,  -180,    78,    78,    78,    78,
      78,  -180,   136,   -42,  -180,  1039,    29,   162,  -180,    -1,
     140,   141,   640,   153,   143,  -180,  -180,  -180,    39,    39,
    -180,  -180,  -180,  -180,  -180,  -180,  -180,  -180,   176,  -180,
     159,  -180,   146,   282,  -180,    78,   151,    -2,   177,  -180,
     155,   178,   968,   968,   968,  -180,   180,   100,   160,  -180,
    -180,   968,   165,   318,  -180,  -180,  -180,   283,   334,   385,
     164,   186,   163,   167,   246,   436,   968,   193,   211,   211,
    -180,   246,   168,   690,  -180,    89,   174,   904,   487,  -180,
     179,  -180,  -180,   172,   740,   968,   214,   190,  -180,   936,
     968,    -3,   968,   230,  1000,   195,  -180,  -180,   538,   101,
    -180,   212,  1032,   208,   210,  -180,  -180,   130,   130,   130,
     130,   790,   222,   100,   213,    78,    78,    78,    78,   968,
    -180,   215,  -180,  -180,   589,   100,  -180,  -180
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -180,  -180,   -17,   -69,     0,   -60,  -180,  -180,  -180,  -180,
    -180,     2,  -180,    -4,    10,    72,    79,   -39,   -30,  -180,
    -180,  -180,    86,  -180,  -180,  -180,  -180,  -179,  -180,  -180
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -10
static const yytype_int16 yytable[] =
{
      23,    81,    27,   105,    90,    91,    74,    78,    38,   142,
      82,    39,    56,   143,    86,    87,    46,    47,    48,    49,
      50,    51,    52,    23,    62,    27,   209,    40,    92,    53,
      79,   120,     2,     3,     4,     5,     6,    56,     8,     9,
     114,    19,    20,    54,   232,    19,    20,    55,    44,   162,
      56,    83,   150,   163,   151,   144,   237,    90,    91,    56,
      56,    56,    56,    56,    89,   132,   133,   134,   135,   136,
     137,    93,    94,   106,   107,   108,   109,   110,   122,    45,
     146,    90,    91,   167,   168,   169,    56,    56,    41,    56,
      56,    42,   175,    46,    47,    48,    49,    50,    51,   111,
      43,   139,   127,   115,    71,    86,    87,   188,    90,    91,
     116,    56,    72,   160,    86,    87,   171,   172,   148,    68,
      69,   112,   155,    86,    87,   145,   204,    73,    68,    69,
      70,   208,    76,   212,    84,   186,    95,    96,    97,    98,
      99,   100,   193,    85,    82,   217,   218,   219,   220,    68,
      69,    82,    75,    46,    47,    48,    49,    50,    51,    52,
     234,    77,   128,   129,    88,   177,    53,   139,   139,   139,
     198,   117,   130,   131,   118,   139,   121,   123,    19,    20,
      54,   125,   207,   196,   124,   126,   140,    23,   139,    27,
     141,   149,   152,   153,   203,   157,   156,   210,   158,    23,
     159,    27,   115,   161,   139,   170,   164,   166,   139,   165,
     174,   182,   139,    56,    56,    56,    56,   176,   181,   183,
     184,   230,   189,   190,   194,   197,   201,   225,   226,   227,
     228,   200,   205,     1,   139,     2,     3,     4,     5,     6,
       7,     8,     9,    10,   206,    11,    12,    13,   213,   215,
      14,    15,    16,    17,    46,    47,    48,    49,    50,    51,
      80,    18,   223,   221,   224,   192,   233,    53,   235,    46,
      47,    48,    49,    50,    51,   185,   231,     0,     0,     0,
      19,    20,    53,     0,     1,   138,     2,     3,     4,     5,
       6,     7,     8,     9,    10,     0,    11,    12,    13,     0,
       0,    14,    15,    16,    17,    46,    47,    48,    49,    50,
      51,   111,    18,    63,    64,    65,    66,    67,    68,    69,
      70,     2,     3,     4,     5,     6,     0,     8,     9,     0,
       0,    19,    20,     0,     0,     1,   178,     2,     3,     4,
       5,     6,     7,     8,     9,    10,     0,    11,    12,    13,
       0,     0,    14,    15,    16,    17,     0,     0,     0,     0,
       0,     0,     0,    18,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    19,    20,     0,     0,     1,   179,     2,     3,
       4,     5,     6,     7,     8,     9,    10,     0,    11,    12,
      13,     0,     0,    14,    15,    16,    17,     0,     0,     0,
       0,     0,     0,     0,    18,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    19,    20,     0,     0,     1,   180,     2,
       3,     4,     5,     6,     7,     8,     9,    10,     0,    11,
      12,    13,     0,     0,    14,    15,    16,    17,     0,     0,
       0,     0,     0,     0,     0,    18,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    19,    20,     0,     0,     1,   187,
       2,     3,     4,     5,     6,     7,     8,     9,    10,     0,
      11,    12,    13,     0,     0,    14,    15,    16,    17,     0,
       0,     0,     0,     0,     0,     0,    18,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    19,    20,     0,     0,     1,
     199,     2,     3,     4,     5,     6,     7,     8,     9,    10,
       0,    11,    12,    13,     0,     0,    14,    15,    16,    17,
       0,     0,     0,     0,     0,     0,     0,    18,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    19,    20,     0,     0,
       1,   216,     2,     3,     4,     5,     6,     7,     8,     9,
      10,     0,    11,    12,    13,     0,     0,    14,    15,    16,
      17,     0,     0,     0,     0,     0,     0,     0,    18,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    19,    20,     0,
       0,     1,   236,     2,     3,     4,     5,     6,     7,     8,
       9,    10,     0,    11,    12,    13,     0,     0,    14,    15,
      16,    17,     0,     0,     0,     0,     0,     0,     0,    18,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    19,    20,
       0,     1,   154,     2,     3,     4,     5,     6,     7,     8,
       9,    10,     0,    11,    12,    13,     0,     0,    14,    15,
      16,    17,     0,     0,     0,     0,     0,     0,     0,    18,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    19,    20,
       0,     1,   195,     2,     3,     4,     5,     6,     7,     8,
       9,    10,     0,    11,    12,    13,     0,     0,    14,    15,
      16,    17,     0,     0,     0,     0,     0,     0,     0,    18,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    19,    20,
       0,     1,   202,     2,     3,     4,     5,     6,     7,     8,
       9,    10,     0,    11,    12,    13,     0,     0,    14,    15,
      16,    17,     0,     0,     0,     0,     0,     0,     0,    18,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    19,    20,
      -2,     1,   229,     2,     3,     4,     5,     6,     7,     8,
       9,    10,     0,    11,    12,    13,     0,     0,    14,    15,
      16,    17,     0,     0,     0,     0,     0,     0,     0,    18,
       0,     0,    -9,     1,     0,     2,     3,     4,     5,     6,
       7,     8,     9,    10,     0,    11,    12,    13,    19,    20,
      14,    15,    16,    17,     0,     0,     0,     0,     0,     0,
       0,    18,     0,     0,    -8,     1,     0,     2,     3,     4,
       5,     6,     7,     8,     9,    10,     0,    11,    12,    13,
      19,    20,    14,    15,    16,    17,     0,     0,     0,     0,
       0,     0,     0,    18,     0,     0,    -7,     1,     0,     2,
       3,     4,     5,     6,     7,     8,     9,    10,     0,    11,
      12,    13,    19,    20,    14,    15,    16,    17,     0,     0,
       0,     0,     0,     0,     0,    18,     0,     0,     0,     1,
       0,     2,     3,     4,     5,     6,     7,     8,     9,    10,
       0,    11,    12,    13,    19,    20,    14,    15,    16,    17,
       0,     0,     0,     0,     0,     0,     0,    18,     0,     0,
       0,     1,     0,     2,     3,     4,     5,     6,     7,     8,
       9,    10,     0,    11,    12,    13,    19,    20,   214,    15,
      16,    17,     0,     0,     0,     0,     0,     0,     0,    18,
       0,     0,     0,     1,     0,     2,     3,     4,     5,     6,
       7,     8,     9,    10,     0,    11,    12,    13,    19,    20,
     222,    15,    16,    17,     0,     0,     0,     0,     0,     0,
       0,    18,    46,    47,    48,    49,    50,    51,   104,     0,
       0,     0,     0,     0,     0,    53,     0,     0,     0,     0,
      19,    20,     0,     0,     0,     0,     0,    19,    20,    54
};

static const yytype_int16 yycheck[] =
{
       0,    40,     0,    63,    30,    31,    23,    29,    54,    51,
      40,    29,    16,    55,    34,    35,    23,    24,    25,    26,
      27,    28,    29,    23,    52,    23,    29,    50,    54,    36,
      52,    51,     3,     4,     5,     6,     7,    41,     9,    10,
      70,    48,    49,    50,   223,    48,    49,    54,    54,    51,
      54,    41,    53,    55,    55,   115,   235,    30,    31,    63,
      64,    65,    66,    67,    54,    95,    96,    97,    98,    99,
     100,    32,    33,    63,    64,    65,    66,    67,    51,    54,
      51,    30,    31,   152,   153,   154,    90,    91,    50,    93,
      94,    50,   161,    23,    24,    25,    26,    27,    28,    29,
      50,   101,    51,    43,    29,    34,    35,   176,    30,    31,
      50,   115,    29,   143,    34,    35,    16,    17,   116,    48,
      49,    51,   122,    34,    35,   115,   195,     0,    48,    49,
      50,   200,    29,   202,     3,   174,    37,    38,    39,    40,
      41,    42,   181,    29,   174,    44,    45,    46,    47,    48,
      49,   181,    54,    23,    24,    25,    26,    27,    28,    29,
     229,    54,    90,    91,    29,   163,    36,   167,   168,   169,
     187,    43,    93,    94,    29,   175,    51,    29,    48,    49,
      50,    29,   199,   183,    51,    29,    29,   187,   188,   187,
      54,    29,    52,    52,   194,    52,    43,   201,    22,   199,
      54,   199,    43,    52,   204,    25,    29,    29,   208,    54,
      50,    25,   212,   217,   218,   219,   220,    52,    54,    56,
      53,   221,    29,    12,    56,    51,    54,   217,   218,   219,
     220,    52,    18,     1,   234,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    54,    13,    14,    15,    18,    54,
      18,    19,    20,    21,    23,    24,    25,    26,    27,    28,
      29,    29,    54,    51,    54,   179,    53,    36,    53,    23,
      24,    25,    26,    27,    28,    29,    54,    -1,    -1,    -1,
      48,    49,    36,    -1,     1,    53,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    -1,    13,    14,    15,    -1,
      -1,    18,    19,    20,    21,    23,    24,    25,    26,    27,
      28,    29,    29,    43,    44,    45,    46,    47,    48,    49,
      50,     3,     4,     5,     6,     7,    -1,     9,    10,    -1,
      -1,    48,    49,    -1,    -1,     1,    53,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    -1,    13,    14,    15,
      -1,    -1,    18,    19,    20,    21,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    48,    49,    -1,    -1,     1,    53,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    -1,    13,    14,
      15,    -1,    -1,    18,    19,    20,    21,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    48,    49,    -1,    -1,     1,    53,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    -1,    13,
      14,    15,    -1,    -1,    18,    19,    20,    21,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    48,    49,    -1,    -1,     1,    53,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    -1,
      13,    14,    15,    -1,    -1,    18,    19,    20,    21,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    48,    49,    -1,    -1,     1,
      53,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      -1,    13,    14,    15,    -1,    -1,    18,    19,    20,    21,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    48,    49,    -1,    -1,
       1,    53,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    -1,    13,    14,    15,    -1,    -1,    18,    19,    20,
      21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    49,    -1,
      -1,     1,    53,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    -1,    13,    14,    15,    -1,    -1,    18,    19,
      20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    49,
      -1,     1,    52,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    -1,    13,    14,    15,    -1,    -1,    18,    19,
      20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    49,
      -1,     1,    52,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    -1,    13,    14,    15,    -1,    -1,    18,    19,
      20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    49,
      -1,     1,    52,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    -1,    13,    14,    15,    -1,    -1,    18,    19,
      20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    49,
       0,     1,    52,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    -1,    13,    14,    15,    -1,    -1,    18,    19,
      20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      -1,    -1,     0,     1,    -1,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    -1,    13,    14,    15,    48,    49,
      18,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    -1,    -1,     0,     1,    -1,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    -1,    13,    14,    15,
      48,    49,    18,    19,    20,    21,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,     0,     1,    -1,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    -1,    13,
      14,    15,    48,    49,    18,    19,    20,    21,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,     1,
      -1,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      -1,    13,    14,    15,    48,    49,    18,    19,    20,    21,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,
      -1,     1,    -1,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    -1,    13,    14,    15,    48,    49,    18,    19,
      20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      -1,    -1,    -1,     1,    -1,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    -1,    13,    14,    15,    48,    49,
      18,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    23,    24,    25,    26,    27,    28,    29,    -1,
      -1,    -1,    -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,
      48,    49,    -1,    -1,    -1,    -1,    -1,    48,    49,    50
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    13,    14,    15,    18,    19,    20,    21,    29,    48,
      49,    58,    59,    61,    62,    64,    67,    68,    69,    70,
      76,    77,    78,    80,    82,    83,    85,    86,    54,    29,
      50,    50,    50,    50,    54,    54,    23,    24,    25,    26,
      27,    28,    29,    36,    50,    54,    70,    71,    72,    73,
      74,    75,    52,    43,    44,    45,    46,    47,    48,    49,
      50,    29,    29,     0,    59,    54,    29,    54,    29,    52,
      29,    74,    75,    71,     3,    29,    34,    35,    29,    71,
      30,    31,    54,    32,    33,    37,    38,    39,    40,    41,
      42,    60,    61,    68,    29,    62,    71,    71,    71,    71,
      71,    29,    51,    63,    75,    43,    50,    43,    29,    65,
      51,    51,    51,    29,    51,    29,    29,    51,    72,    72,
      73,    73,    75,    75,    75,    75,    75,    75,    53,    61,
      29,    54,    51,    55,    62,    71,    51,    66,    68,    29,
      53,    55,    52,    52,    52,    61,    43,    52,    22,    54,
      75,    52,    51,    55,    29,    54,    29,    60,    60,    60,
      25,    16,    17,    84,    50,    60,    52,    68,    53,    53,
      53,    54,    25,    56,    53,    29,    74,    53,    60,    29,
      12,    79,    79,    74,    56,    52,    61,    51,    59,    53,
      52,    54,    52,    61,    60,    18,    54,    59,    60,    29,
      70,    81,    60,    18,    18,    54,    53,    44,    45,    46,
      47,    51,    18,    54,    54,    71,    71,    71,    71,    52,
      61,    54,    84,    53,    60,    53,    53,    84
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 65 "Parser.y"
    {printf("Empty Program ;-;\n");}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 66 "Parser.y"
    {printf("Program Finished\n");}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 70 "Parser.y"
    {printf("Program statements\n");}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 71 "Parser.y"
    {printf("Function Declaration\n");}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 72 "Parser.y"
    {printf("Function Declaration with no parameters\n");}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 73 "Parser.y"
    {printf("Function Declaration\n");}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 74 "Parser.y"
    {printf("Function Declaration with no parameters\n");}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 79 "Parser.y"
    {printf("Block Scope\n");}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 84 "Parser.y"
    {printf("declaration\n");}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 85 "Parser.y"
    {printf("Assignment\n");}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 86 "Parser.y"
    {printf("If Statement\n");}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 87 "Parser.y"
    {printf("While Statement\n");}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 88 "Parser.y"
    {printf("For Statement\n");}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 89 "Parser.y"
    {printf("Switch Statement\n");}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 90 "Parser.y"
    {printf("Return Statement\n");}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 91 "Parser.y"
    {printf("Repeat Until Statement from statement\n");}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 92 "Parser.y"
    {printf("Function Call\n");}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 93 "Parser.y"
    {printf("Enum Statement\n");}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 94 "Parser.y"
    {printf("Function Call with Assignment\n");}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 95 "Parser.y"
    {printf("Function Call with Assignment\n");}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 96 "Parser.y"
    {printf("Break\n");}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 97 "Parser.y"
    {printf("Continue\n");}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 98 "Parser.y"
    { yyerrok; }
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 102 "Parser.y"
    {printf("Function Call\n");}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 103 "Parser.y"
    {printf("Function Call with Parameters\n");}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 107 "Parser.y"
    {printf("Parameter\n");}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 108 "Parser.y"
    {printf("Multiple  Parameters\n");}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 115 "Parser.y"
    {printf("Enum Statement\n");}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 119 "Parser.y"
    {printf("Enum Value\n");}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 120 "Parser.y"
    {printf("Multiple Enum Values\n");}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 124 "Parser.y"
    {printf("Parameters\n");}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 125 "Parser.y"
    {printf("Multiple Parameters\n");}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 129 "Parser.y"
    {printf("Declaration with no assignment\n");}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 130 "Parser.y"
    {printf("Declaration with Assignment\n");}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 131 "Parser.y"
    {printf("Enum Declaration\n");}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 132 "Parser.y"
    {printf("Enum Declaration with Assignment\n");}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 136 "Parser.y"
    {printf("int\n");}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 137 "Parser.y"
    {printf("Float\n");}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 138 "Parser.y"
    {printf("String\n");}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 139 "Parser.y"
    {printf("Char\n");}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 140 "Parser.y"
    {printf("Const\n");}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 141 "Parser.y"
    {printf("Void\n");}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 142 "Parser.y"
    {printf("Bool\n");}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 146 "Parser.y"
    {printf("Assignment\n");}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 147 "Parser.y"
    {printf("Plus Assignment\n");}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 148 "Parser.y"
    {printf("Minus Assignment\n");}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 149 "Parser.y"
    {printf("Multiply Assignment\n");}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 150 "Parser.y"
    {printf("Divide Assignment\n");}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 151 "Parser.y"
    {printf("Crements\n");}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 155 "Parser.y"
    {printf("Increment after Variable\n");}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 156 "Parser.y"
    {printf("Decrement after Variable \n");}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 157 "Parser.y"
    {printf("Increment before Variable \n");}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 158 "Parser.y"
    {printf("Decrement before Variable \n");}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 177 "Parser.y"
    {printf("Addition\n");}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 178 "Parser.y"
    {printf("Subtraction\n");}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 179 "Parser.y"
    {printf("Term\n");}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 183 "Parser.y"
    {printf("Multiplication\n");}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 184 "Parser.y"
    {printf("Division\n");}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 185 "Parser.y"
    {printf("Factor\n");}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 189 "Parser.y"
    {printf("Bracket Expression\n");}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 190 "Parser.y"
    {printf("Values\n");}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 191 "Parser.y"
    {printf("Crements\n");}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 192 "Parser.y"
    {printf("Comparators\n");}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 196 "Parser.y"
    {printf("Equal\n");}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 197 "Parser.y"
    {printf("Not Equal\n");}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 198 "Parser.y"
    {printf("Greater\n");}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 199 "Parser.y"
    {printf("Less\n");}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 200 "Parser.y"
    {printf("Greater Equal\n");}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 201 "Parser.y"
    {printf("Less Equal\n");}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 202 "Parser.y"
    {printf("And\n");}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 203 "Parser.y"
    {printf("Or\n");}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 204 "Parser.y"
    {printf("Not\n");}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 208 "Parser.y"
    {printf("Variable\n");}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 209 "Parser.y"
    {printf("Integer Literal\n");}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 210 "Parser.y"
    {printf("Float Literal\n");}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 211 "Parser.y"
    {printf("String Literal\n");}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 212 "Parser.y"
    {printf("Char Literal\n");}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 213 "Parser.y"
    {printf("Boolean True\n");}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 214 "Parser.y"
    {printf("Boolean False\n");}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 274 "Parser.y"
    {printf("While Single Statement\n");}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 275 "Parser.y"
    {printf("While Multiple Statements\n");}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 280 "Parser.y"
    {printf("For statement Variable Plus Equal\n");}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 281 "Parser.y"
    {printf("For statement Variable Minus Equal\n");}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 282 "Parser.y"
    {printf("For statement Variable Multiply Equal\n");}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 283 "Parser.y"
    {printf("For statement Variable Divide Equal\n");}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 284 "Parser.y"
    {printf("For statement Crements\n");}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 288 "Parser.y"
    {printf("For Single Statement\n");}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 289 "Parser.y"
    {printf("For Multiple Statements\n");}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 293 "Parser.y"
    {printf("Switch Statement\n");}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 297 "Parser.y"
    {printf("Case Statement single statement\n");}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 298 "Parser.y"
    {printf("Default Statement single statement\n");}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 299 "Parser.y"
    {printf("Case Statement multiple statements\n");}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 300 "Parser.y"
    {printf("Default Statement multiple statements\n");}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 304 "Parser.y"
    {printf("Return Statement with expression\n");}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 305 "Parser.y"
    {printf("Return Statement without expression\n");}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 309 "Parser.y"
    {printf("Repeat Until Statement scope\n");}
    break;



/* Line 1455 of yacc.c  */
#line 2488 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 311 "Parser.y"


int main() {
    yyparse();

    return 0;
}

int yyerror(char *s) {
    printf("\nERROR: %s\n", s);
    return 0;
}

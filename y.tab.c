
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
    // #include <stdbool.h>
    // #include "stack.h"
    #include "linked_list.h"
    #include "utils.h"
    #include "parameters.h"


    
    int line=1;
    



/* Line 189 of yacc.c  */
#line 94 "y.tab.c"

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

/* Line 214 of yacc.c  */
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
    }terminal_values; /* terminal values */

    struct {
   

    }callParameters;

    




/* Line 214 of yacc.c  */
#line 249 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 261 "y.tab.c"

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
#define YYFINAL  64
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   458

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  98
/* YYNRULES -- Number of states.  */
#define YYNSTATES  220

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   301

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      47,    48,     2,     2,    52,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    53,    51,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    49,     2,    50,     2,     2,     2,     2,
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
      45,    46
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     6,     9,    13,    16,    18,    24,
      29,    33,    35,    37,    40,    42,    45,    48,    50,    52,
      54,    56,    58,    60,    62,    65,    68,    71,    78,    86,
      91,    97,   105,   114,   116,   120,   123,   128,   131,   136,
     138,   140,   142,   144,   146,   148,   150,   154,   158,   162,
     166,   170,   174,   178,   180,   184,   188,   190,   194,   196,
     200,   204,   208,   212,   216,   220,   224,   228,   231,   233,
     235,   237,   239,   241,   243,   245,   247,   249,   251,   260,
     268,   277,   285,   290,   298,   302,   306,   310,   314,   318,
     323,   331,   335,   343,   344,   354,   362,   366,   369
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      55,     0,    -1,    -1,    56,    -1,    62,    56,    -1,    57,
      58,    56,    -1,    57,    58,    -1,    62,    -1,    67,    28,
      47,    65,    48,    -1,    67,    28,    47,    48,    -1,    49,
      61,    60,    -1,    49,    -1,    50,    -1,    61,    62,    -1,
      62,    -1,    66,    51,    -1,    68,    51,    -1,    75,    -1,
      79,    -1,    81,    -1,    85,    -1,    87,    -1,    88,    -1,
      63,    -1,    17,    51,    -1,    18,    51,    -1,     1,    51,
      -1,    28,    42,    28,    47,    48,    51,    -1,    28,    42,
      28,    47,    64,    48,    51,    -1,    28,    47,    48,    51,
      -1,    28,    47,    64,    48,    51,    -1,    67,    28,    42,
      28,    47,    48,    51,    -1,    67,    28,    42,    28,    47,
      64,    48,    51,    -1,    73,    -1,    64,    52,    73,    -1,
      67,    28,    -1,    65,    52,    67,    28,    -1,    67,    28,
      -1,    67,    28,    42,    69,    -1,     3,    -1,     4,    -1,
       5,    -1,     6,    -1,     7,    -1,     8,    -1,     9,    -1,
      28,    42,    69,    -1,    28,    43,    69,    -1,    28,    44,
      69,    -1,    28,    45,    69,    -1,    28,    46,    69,    -1,
      69,    29,    70,    -1,    69,    30,    70,    -1,    70,    -1,
      70,    31,    71,    -1,    70,    32,    71,    -1,    71,    -1,
      47,    69,    48,    -1,    73,    -1,    73,    36,    73,    -1,
      73,    37,    73,    -1,    73,    38,    73,    -1,    73,    39,
      73,    -1,    73,    40,    73,    -1,    73,    41,    73,    -1,
      74,    33,    74,    -1,    74,    34,    74,    -1,    35,    74,
      -1,    74,    -1,    24,    -1,    25,    -1,    22,    -1,    23,
      -1,    26,    -1,    27,    -1,    28,    -1,    76,    -1,    77,
      -1,    10,    47,    72,    48,    59,    61,    60,    78,    -1,
      10,    47,    72,    48,    59,    61,    60,    -1,    10,    47,
      28,    48,    59,    61,    60,    78,    -1,    10,    47,    28,
      48,    59,    61,    60,    -1,    11,    59,    61,    60,    -1,
      12,    47,    72,    48,    59,    61,    60,    -1,    28,    43,
      69,    -1,    28,    44,    69,    -1,    28,    45,    69,    -1,
      28,    46,    69,    -1,    13,    83,    84,    -1,     3,    28,
      42,    24,    -1,    47,    82,    51,    72,    51,    80,    48,
      -1,    49,    61,    60,    -1,    14,    47,    28,    48,    59,
      86,    60,    -1,    -1,    15,    24,    53,    59,    61,    17,
      51,    60,    86,    -1,    16,    53,    59,    61,    17,    51,
      60,    -1,    19,    69,    51,    -1,    19,    51,    -1,    20,
      59,    61,    60,    21,    47,    72,    48,    51,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    98,    98,    99,   102,   103,   104,   105,   109,   137,
     158,   162,   165,   175,   176,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   196,   221,   269,
     270,   271,   272,   276,   279,   288,   289,   293,   311,   354,
     355,   356,   357,   358,   359,   360,   364,   400,   441,   483,
     524,   569,   585,   598,   603,   615,   627,   631,   632,   636,
     643,   650,   657,   666,   673,   680,   687,   694,   703,   706,
     710,   713,   716,   719,   722,   728,   748,   749,   753,   754,
     757,   758,   762,   766,   771,   772,   773,   774,   779,   787,
     790,   796,   800,   803,   804,   805,   809,   810,   814
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "FLOAT", "STRING", "CHAR",
  "CONST", "VOID", "BOOL", "IF", "ELSE", "WHILE", "FOR", "SWITCH", "CASE",
  "DEFAULT", "BREAK", "CONTINUE", "RETURN", "REPEAT", "UNTIL",
  "STRING_LITERAL", "CHAR_LITERAL", "INTEGER_LITERAL", "FLOAT_LITERAL",
  "BOOLEAN_TRUE", "BOOLEAN_FALSE", "VARIABLE", "PLUS", "MINUS", "MULTIPLY",
  "DIVIDE", "AND", "OR", "NOT", "EQUAL", "NOT_EQUAL", "GREATER", "LESS",
  "GREATER_EQUAL", "LESS_EQUAL", "ASSIGN", "PLUS_ASSIGN", "MINUS_ASSIGN",
  "MULTIPLY_ASSIGN", "DIVIDE_ASSIGN", "'('", "')'", "'{'", "'}'", "';'",
  "','", "':'", "$accept", "program", "programStatements", "function",
  "functionScope", "openScope", "closeScope", "inBlockscope", "statement",
  "functionCall", "callParameters", "parameters", "declaration",
  "typeSpecifier", "assignment", "expression", "term", "factor",
  "comparators", "values", "variableValue", "ifStatement", "ifComparators",
  "ifVariable", "elseClause", "whileStatement", "forExpression",
  "forStatement", "bora3y", "ForBracket", "forScope", "switchStatement",
  "caseStatements", "returnStatement", "repeatUntilStatement", 0
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
     295,   296,   297,   298,   299,   300,   301,    40,    41,   123,
     125,    59,    44,    58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    54,    55,    55,    56,    56,    56,    56,    57,    57,
      58,    59,    60,    61,    61,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    63,    63,    63,
      63,    63,    63,    64,    64,    65,    65,    66,    66,    67,
      67,    67,    67,    67,    67,    67,    68,    68,    68,    68,
      68,    69,    69,    69,    70,    70,    70,    71,    71,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    73,    73,
      73,    73,    73,    73,    73,    74,    75,    75,    76,    76,
      77,    77,    78,    79,    80,    80,    80,    80,    81,    82,
      83,    84,    85,    86,    86,    86,    87,    87,    88
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     1,     2,     3,     2,     1,     5,     4,
       3,     1,     1,     2,     1,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     2,     6,     7,     4,
       5,     7,     8,     1,     3,     2,     4,     2,     4,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     8,     7,
       8,     7,     4,     7,     3,     3,     3,     3,     3,     4,
       7,     3,     7,     0,     9,     7,     3,     2,     9
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    39,    40,    41,    42,    43,    44,    45,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     3,
       0,     0,    23,     0,     0,     0,    17,    76,    77,    18,
      19,    20,    21,    22,    26,     0,     0,     0,     0,     0,
      24,    25,    71,    72,    69,    70,    73,    74,    75,     0,
      97,     0,    53,    56,    58,    68,    11,     0,     0,     0,
       0,     0,     0,     0,     1,     0,     0,     4,    15,    37,
      16,    75,     0,     0,     0,    68,     0,     0,     0,     0,
      88,     0,     0,     0,     0,    96,     0,     0,     0,    14,
       0,    75,    46,    47,    48,    49,    50,     0,     0,    33,
       0,     5,     0,     0,     0,    67,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      57,    51,    52,    54,    55,    12,     0,    13,    37,     0,
      29,     0,     0,    10,    75,    38,     9,     0,     0,     0,
       0,    59,    60,    61,    62,    63,    64,    65,    66,     0,
       0,     0,    91,    93,     0,     0,     0,    30,    34,     0,
       8,     0,    35,     0,     0,     0,    89,     0,     0,     0,
       0,     0,    27,     0,     0,     0,     0,    81,    79,    83,
       0,     0,     0,     0,    92,     0,    28,    31,     0,    36,
       0,    80,    78,     0,     0,     0,     0,    90,     0,     0,
       0,    32,     0,    84,    85,    86,    87,     0,     0,    98,
       0,     0,     0,    82,     0,    24,    24,    95,    93,    94
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    18,    19,    20,    66,    57,   126,    88,    89,    22,
      98,   137,    23,    90,    25,    51,    52,    53,    73,    54,
      55,    26,    27,    28,   191,    29,   181,    30,    78,    38,
      80,    31,   170,    32,    33
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -126
static const yytype_int16 yypact[] =
{
     213,   -44,  -126,  -126,  -126,  -126,  -126,  -126,  -126,   -37,
     -31,   -12,   -10,    20,    28,   103,   -25,    18,    42,  -126,
       3,   239,  -126,    35,    29,    52,  -126,  -126,  -126,  -126,
    -126,  -126,  -126,  -126,  -126,   390,   409,   110,    70,   111,
    -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,   350,
    -126,     2,    -5,  -126,  -126,  -126,  -126,   291,   357,   350,
     350,   350,   350,   164,  -126,   291,   265,  -126,  -126,    -9,
    -126,    93,   114,    95,    55,    40,   104,   123,    87,   291,
    -126,   108,    11,   350,   350,  -126,   350,   350,   165,  -126,
     129,   112,    79,    79,    79,    79,    79,   107,   -23,  -126,
     165,  -126,   383,    41,   -25,  -126,   -25,   423,   423,   423,
     423,   423,   423,   114,   114,   -25,   118,   409,   165,   -25,
    -126,    -5,    -5,  -126,  -126,  -126,   140,  -126,   125,   176,
    -126,   130,   423,  -126,   133,    79,  -126,     6,   148,   291,
     291,  -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,   291,
     170,   144,  -126,    96,   149,   146,    24,  -126,  -126,   342,
    -126,   449,  -126,   165,   165,   165,  -126,   177,   182,   154,
     159,   409,  -126,   178,   183,    58,   200,   224,   224,  -126,
      90,   188,   184,   -25,  -126,   190,  -126,  -126,   199,  -126,
     -25,  -126,  -126,   350,   350,   350,   350,  -126,   -25,   291,
     203,  -126,   291,    79,    79,    79,    79,   291,   317,  -126,
     165,   343,   204,  -126,   209,   159,   159,  -126,    96,  -126
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -126,  -126,   -15,  -126,  -126,   -76,   -95,   -62,     0,  -126,
    -125,  -126,  -126,     1,  -126,   -47,    33,    37,   -18,   -27,
     -16,  -126,  -126,  -126,    83,  -126,  -126,  -126,  -126,  -126,
    -126,  -126,    44,  -126,  -126
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -8
static const yytype_int16 yytable[] =
{
      21,    24,    82,   100,   156,   133,    67,    34,    74,    74,
      35,    92,    93,    94,    95,    96,    36,   118,    76,    75,
      75,    21,    24,   152,    56,   131,    86,    87,   139,   132,
     140,    83,    84,   102,   175,    37,    99,    39,   103,   149,
      83,    84,    64,   153,     2,     3,     4,     5,     6,     7,
       8,   101,    65,    85,   160,   135,   105,    69,   161,   120,
      58,    59,    60,    61,    62,    63,    21,    24,   177,   178,
     179,    40,   173,   113,   114,   184,   132,   163,   164,    41,
     141,   142,   143,   144,   145,   146,    68,   165,   127,   136,
      74,   107,   108,   109,   110,   111,   112,   147,   148,   151,
     127,    75,    99,    70,   138,   158,   188,   199,    83,    84,
     132,   168,   169,    77,   202,   213,   121,   122,   127,    79,
     217,   218,   207,   123,   124,    42,    43,    44,    45,    46,
      47,    48,    99,   193,   194,   195,   196,   208,   117,    81,
     210,   104,    48,   106,    74,   211,   203,   204,   205,   206,
      49,   116,   115,   185,    50,    75,   119,   128,   130,   129,
     150,   154,   176,   127,   127,   127,     1,   102,     2,     3,
       4,     5,     6,     7,     8,     9,   162,    10,    11,    12,
     159,   157,    13,    14,    15,    16,    42,    43,    44,    45,
      46,    47,    48,    17,   166,   167,   171,   172,    42,    43,
      44,    45,    46,    47,    48,   180,   182,   183,   127,   125,
     127,   127,    97,    -2,     1,   125,     2,     3,     4,     5,
       6,     7,     8,     9,   155,    10,    11,    12,   189,   186,
      13,    14,    15,    16,   187,   190,   197,   198,   200,    -7,
       1,    17,     2,     3,     4,     5,     6,     7,     8,     9,
     201,    10,    11,    12,   209,   215,    13,    14,    15,    16,
     216,   192,   219,     0,     0,    -6,     1,    17,     2,     3,
       4,     5,     6,     7,     8,     9,     0,    10,    11,    12,
       0,     0,    13,    14,    15,    16,     0,     0,     0,     0,
       0,     0,     1,    17,     2,     3,     4,     5,     6,     7,
       8,     9,     0,    10,    11,    12,     0,     0,    13,    14,
      15,    16,     0,     0,     0,     0,     0,     0,     1,    17,
       2,     3,     4,     5,     6,     7,     8,     9,     0,    10,
      11,    12,     0,     0,   212,    14,    15,    16,     0,     0,
       0,     0,     0,     0,     1,    17,     2,     3,     4,     5,
       6,     7,     8,     9,     0,    10,    11,    12,     0,     0,
     214,    14,    15,    16,    42,    43,    44,    45,    46,    47,
      48,    17,    42,    43,    44,    45,    46,    47,    48,    42,
      43,    44,    45,    46,    47,    91,     0,     0,     0,     0,
     174,     0,     0,     0,     0,     0,     0,    49,     0,     0,
       0,     0,     0,     0,    49,    42,    43,    44,    45,    46,
      47,   134,    42,    43,    44,    45,    46,    47,    71,     0,
       0,     0,     0,     0,     0,    72,     0,     0,     0,     0,
      49,    42,    43,    44,    45,    46,    47,    48,     0,     0,
       0,     0,     0,     0,    72,    42,    43,    44,    45,    46,
      47,    48,     2,     3,     4,     5,     6,     7,     8
};

static const yytype_int16 yycheck[] =
{
       0,     0,    49,    65,   129,   100,    21,    51,    35,    36,
      47,    58,    59,    60,    61,    62,    47,    79,    36,    35,
      36,    21,    21,   118,    49,    48,    31,    32,   104,    52,
     106,    29,    30,    42,   159,    47,    63,    47,    47,   115,
      29,    30,     0,   119,     3,     4,     5,     6,     7,     8,
       9,    66,    49,    51,    48,   102,    72,    28,    52,    48,
      42,    43,    44,    45,    46,    47,    66,    66,   163,   164,
     165,    51,    48,    33,    34,   170,    52,   139,   140,    51,
     107,   108,   109,   110,   111,   112,    51,   149,    88,    48,
     117,    36,    37,    38,    39,    40,    41,   113,   114,   117,
     100,   117,   129,    51,   103,   132,    48,   183,    29,    30,
      52,    15,    16,     3,   190,   210,    83,    84,   118,    49,
     215,   216,   198,    86,    87,    22,    23,    24,    25,    26,
      27,    28,   159,    43,    44,    45,    46,   199,    51,    28,
     202,    48,    28,    48,   171,   207,   193,   194,   195,   196,
      47,    28,    48,   171,    51,   171,    48,    28,    51,    47,
      42,    21,   161,   163,   164,   165,     1,    42,     3,     4,
       5,     6,     7,     8,     9,    10,    28,    12,    13,    14,
      47,    51,    17,    18,    19,    20,    22,    23,    24,    25,
      26,    27,    28,    28,    24,    51,    47,    51,    22,    23,
      24,    25,    26,    27,    28,    28,    24,    53,   208,    50,
     210,   211,    48,     0,     1,    50,     3,     4,     5,     6,
       7,     8,     9,    10,    48,    12,    13,    14,    28,    51,
      17,    18,    19,    20,    51,    11,    48,    53,    48,     0,
       1,    28,     3,     4,     5,     6,     7,     8,     9,    10,
      51,    12,    13,    14,    51,    51,    17,    18,    19,    20,
      51,   178,   218,    -1,    -1,     0,     1,    28,     3,     4,
       5,     6,     7,     8,     9,    10,    -1,    12,    13,    14,
      -1,    -1,    17,    18,    19,    20,    -1,    -1,    -1,    -1,
      -1,    -1,     1,    28,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    14,    -1,    -1,    17,    18,
      19,    20,    -1,    -1,    -1,    -1,    -1,    -1,     1,    28,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    12,
      13,    14,    -1,    -1,    17,    18,    19,    20,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    28,     3,     4,     5,     6,
       7,     8,     9,    10,    -1,    12,    13,    14,    -1,    -1,
      17,    18,    19,    20,    22,    23,    24,    25,    26,    27,
      28,    28,    22,    23,    24,    25,    26,    27,    28,    22,
      23,    24,    25,    26,    27,    28,    -1,    -1,    -1,    -1,
      48,    -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    22,    23,    24,    25,    26,
      27,    28,    22,    23,    24,    25,    26,    27,    28,    -1,
      -1,    -1,    -1,    -1,    -1,    35,    -1,    -1,    -1,    -1,
      47,    22,    23,    24,    25,    26,    27,    28,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    22,    23,    24,    25,    26,
      27,    28,     3,     4,     5,     6,     7,     8,     9
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     4,     5,     6,     7,     8,     9,    10,
      12,    13,    14,    17,    18,    19,    20,    28,    55,    56,
      57,    62,    63,    66,    67,    68,    75,    76,    77,    79,
      81,    85,    87,    88,    51,    47,    47,    47,    83,    47,
      51,    51,    22,    23,    24,    25,    26,    27,    28,    47,
      51,    69,    70,    71,    73,    74,    49,    59,    42,    43,
      44,    45,    46,    47,     0,    49,    58,    56,    51,    28,
      51,    28,    35,    72,    73,    74,    72,     3,    82,    49,
      84,    28,    69,    29,    30,    51,    31,    32,    61,    62,
      67,    28,    69,    69,    69,    69,    69,    48,    64,    73,
      61,    56,    42,    47,    48,    74,    48,    36,    37,    38,
      39,    40,    41,    33,    34,    48,    28,    51,    61,    48,
      48,    70,    70,    71,    71,    50,    60,    62,    28,    47,
      51,    48,    52,    60,    28,    69,    48,    65,    67,    59,
      59,    73,    73,    73,    73,    73,    73,    74,    74,    59,
      42,    72,    60,    59,    21,    48,    64,    51,    73,    47,
      48,    52,    28,    61,    61,    61,    24,    51,    15,    16,
      86,    47,    51,    48,    48,    64,    67,    60,    60,    60,
      28,    80,    24,    53,    60,    72,    51,    51,    48,    28,
      11,    78,    78,    43,    44,    45,    46,    48,    53,    59,
      48,    51,    59,    69,    69,    69,    69,    59,    61,    51,
      61,    61,    17,    60,    17,    51,    51,    60,    60,    86
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
#line 98 "Parser.y"
    {printf("Empty Program ;-;\n");}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 99 "Parser.y"
    { printf("Program\n");}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 102 "Parser.y"
    {printf("Program statements\n");}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 103 "Parser.y"
    { display();}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 104 "Parser.y"
    {printf("Function Declaration with no parameters\n");}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 109 "Parser.y"
    {
                                                                struct Node *node = searchScope((yyvsp[(2) - (5)].varval));
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
                                                                    strcat(temp,(yyvsp[(1) - (5)].type));
                                                                    createNode((yyvsp[(2) - (5)].varval),temp,"function",-1,line);
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
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 137 "Parser.y"
    {
                                                    struct Node *node = searchScope((yyvsp[(2) - (4)].varval));
                                                    if(node!=NULL)
                                                    {
                                                        printf("Function already declared\n");
                                                    }
                                                    else
                                                    {
                                                        char *temp = malloc(sizeof(char) * 1024);
                                                        temp[0]='\0';
                                                        strcat(temp,"=>");
                                                        strcat(temp,(yyvsp[(1) - (4)].type));
                                                        createNode((yyvsp[(2) - (4)].varval),temp,"function",-1,line);
                                                        line++;
                                                        scopePush();
                                                        free(temp);
                                                    }
                                                }
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 162 "Parser.y"
    {scopePush();}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 165 "Parser.y"
    {   

            printf("==============Symbol Table before popping==============\n");
            displayList();
            scopePop();
        }
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 175 "Parser.y"
    {printf("Block Scope\n");}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 180 "Parser.y"
    {}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 181 "Parser.y"
    {}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 182 "Parser.y"
    {printf("If Statement\n");}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 183 "Parser.y"
    {printf("While Statement\n");}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 184 "Parser.y"
    {printf("For Statement\n");}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 185 "Parser.y"
    {printf("Switch Statement\n");}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 186 "Parser.y"
    {printf("Return Statement\n");}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 187 "Parser.y"
    {printf("Repeat Until Statement from statement\n");}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 188 "Parser.y"
    {printf("Function Call\n");}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 189 "Parser.y"
    {printf("Break\n");}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 190 "Parser.y"
    {printf("Continue\n");}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 191 "Parser.y"
    { yyerrok; }
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 196 "Parser.y"
    {
                                                        struct Node* temp = searchScope((yyvsp[(1) - (6)].varval));
                                                        if (temp ==NULL)
                                                        {
                                                            printf("Variable not declared\n");
                                                        }
                                                        else
                                                        {
                                                            struct Node* temp2 = searchScope((yyvsp[(3) - (6)].varval));
                                                            if (temp2 ==NULL)
                                                            {
                                                                printf("Function not declared\n");
                                                            }
                                                            else
                                                            {
                                                                func_type_check(temp->datatype,temp2->datatype);
                                                                char *equal = strchr(temp2->datatype, '=');
                                                                int index = (int)(equal - temp2->datatype);
                                                                if (index!=0)
                                                                {
                                                                    printf("Function's parameters are not passed to the function\n");
                                                                }
                                                            }
                                                        }
                                                    }
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 222 "Parser.y"
    {
                                                                printf("LMAOOOOOOOOOOOOOOOOOOOO\n");    
                                                                struct Node* temp = searchScope((yyvsp[(1) - (7)].varval));
                                                                if (temp ==NULL)
                                                                {
                                                                    printf("Variable not declared\n");
                                                                }
                                                                else
                                                                {
                                                                    struct Node* temp2 = searchScope((yyvsp[(3) - (7)].varval));
                                                                    if (temp2 ==NULL)
                                                                    {
                                                                        printf("Function not declared\n");
                                                                    }
                                                                    else
                                                                    {
                                                                        func_type_check(temp->datatype,temp2->datatype);
                                                                        int idx = get_index();
                                                                        int* param_value_type = get_param_value_type();
                                                                        char **param_var_type = get_param_var_type();
                                                                        int *param_var_init = get_param_var_init();
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
                                                                                        func_input_check(temp2->datatype,param_var_type[i],i);
                                                                                    }
                                                                                }
                                                                                else
                                                                                {   
                                                                                    char *val_type = value_int_to_string(param_value_type[i]);
                                                                                    printf("Variable: %s\n",val_type);
                                                                                    func_input_check(temp2->datatype,val_type,i);
                                                                                }
                                                                            }
                                                                            clear_call_params();
                                                                    }
                                                                }

                                                            }
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 269 "Parser.y"
    {printf("Function Call\n");}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 270 "Parser.y"
    {printf("Function Call with Parameters\n");}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 271 "Parser.y"
    {printf("Function Call with Assignment\n");}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 272 "Parser.y"
    {printf("Function Call with Assignment and Parameters\n");}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 276 "Parser.y"
    {
                    addCallParams((yyvsp[(1) - (1)].terminal_values).value_type,(yyvsp[(1) - (1)].terminal_values).var_type,(yyvsp[(1) - (1)].terminal_values).var_init);
                }
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 280 "Parser.y"
    { 
                                    printf("el index rabena yente2em menno: %d",get_index());
                                    addCallParams((yyvsp[(3) - (3)].terminal_values).value_type,(yyvsp[(3) - (3)].terminal_values).var_type,(yyvsp[(3) - (3)].terminal_values).var_init);
                                    printf("el index rabena yente2em menno: %d",get_index());
                                }
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 288 "Parser.y"
    {addParameter((yyvsp[(1) - (2)].type),(yyvsp[(2) - (2)].varval));}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 289 "Parser.y"
    {addParameter((yyvsp[(3) - (4)].type),(yyvsp[(4) - (4)].varval));}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 293 "Parser.y"
    {
                                                                        if (strcmp((yyvsp[(1) - (2)].type),"void")!=0)
                                                                        {
                                                                            struct Node *var = searchScope((yyvsp[(2) - (2)].varval));
                                                                            
                                                                            if(var!=NULL){
                                                                                printf("Variable already declared\n");
                                                                            }else{
                                                                                createNode((yyvsp[(2) - (2)].varval),(yyvsp[(1) - (2)].type),"variable",0,line);
                                                                            }
                                                                            line++;
                                                                        }
                                                                        else
                                                                        {
                                                                            printf("Void cannot be assigned to a variable\n");
                                                                        }
                                                                    }
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 311 "Parser.y"
    {
                                                                        if (strcmp((yyvsp[(1) - (4)].type),"void")!=0)
                                                                        {
                                                                            struct Node *var = searchScope((yyvsp[(2) - (4)].varval));
                                                                        
                                                                            if(var!=NULL){
                                                                                printf("Variable already declared\n");
                                                                            }else{
                                                                                if ((yyvsp[(4) - (4)].terminal_values).value_type!=1)
                                                                                {
                                                                                    if (strcmp((yyvsp[(1) - (4)].type),value_int_to_string_util((yyvsp[(4) - (4)].terminal_values).value_type))==0)
                                                                                    {
                                                                                        createNode((yyvsp[(2) - (4)].varval),(yyvsp[(1) - (4)].type),"variable",1,line);
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        printf("Type Mismatch\n");
                                                                                    
                                                                                    }
                                                                                }
                                                                                else
                                                                                {
                                                                                    if (strcmp((yyvsp[(1) - (4)].type),(yyvsp[(4) - (4)].terminal_values).var_type)==0)
                                                                                    {
                                                                                        createNode((yyvsp[(2) - (4)].varval),(yyvsp[(1) - (4)].type),"variable",1,line);
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
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 354 "Parser.y"
    {(yyval.type)="int";}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 355 "Parser.y"
    {(yyval.type)="float";}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 356 "Parser.y"
    {(yyval.type)="string";}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 357 "Parser.y"
    {(yyval.type)="char";}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 358 "Parser.y"
    {(yyval.type)="const";}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 359 "Parser.y"
    {(yyval.type)="void";}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 360 "Parser.y"
    {(yyval.type)="bool";}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 364 "Parser.y"
    {
                                                struct Node *var = searchScope((yyvsp[(1) - (3)].varval));
                                                if(var==NULL)
                                                {
                                                    printf("Variable not declared\n");
                                                }
                                                else
                                                {
                                                    if ((yyvsp[(3) - (3)].terminal_values).value_type!=1)
                                                    {
                                                        if (strcmp(var->datatype,value_int_to_string_util((yyvsp[(3) - (3)].terminal_values).value_type))==0)
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
                                                        if (strcmp(var->datatype,(yyvsp[(3) - (3)].terminal_values).var_type)==0)
                                                        {
                                                            var->init=1;  
                                                        }
                                                            else
                                                        {
                                                            printf("Type Mismatch\n");
                                                        }
                                                    }
                            
                                                    // var->init=1;  
                                                }
                                                line++;
                                            }
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 400 "Parser.y"
    {
                                                struct Node *var = searchScope((yyvsp[(1) - (3)].varval));
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
                                                        if ((yyvsp[(3) - (3)].terminal_values).value_type!=1)
                                                        {
                                                            if (strcmp(var->datatype,value_int_to_string_util((yyvsp[(3) - (3)].terminal_values).value_type))==0)
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
                                                            if (strcmp(var->datatype,(yyvsp[(3) - (3)].terminal_values).var_type)==0)
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
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 441 "Parser.y"
    {
                                                struct Node *var = searchScope((yyvsp[(1) - (3)].varval));
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
                                                       if ((yyvsp[(3) - (3)].terminal_values).value_type!=1)
                                                        {
                                                            if (strcmp(var->datatype,value_int_to_string_util((yyvsp[(3) - (3)].terminal_values).value_type))==0)
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
                                                            if (strcmp(var->datatype,(yyvsp[(3) - (3)].terminal_values).var_type)==0)
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
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 483 "Parser.y"
    {
                                                struct Node *var = searchScope((yyvsp[(1) - (3)].varval));
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
                                                      if ((yyvsp[(3) - (3)].terminal_values).value_type!=1)
                                                        {
                                                            if (strcmp(var->datatype,value_int_to_string_util((yyvsp[(3) - (3)].terminal_values).value_type))==0)
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
                                                            if (strcmp(var->datatype,(yyvsp[(3) - (3)].terminal_values).var_type)==0)
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
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 524 "Parser.y"
    {
                                                struct Node *var = searchScope((yyvsp[(1) - (3)].varval));
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
                                                       if ((yyvsp[(3) - (3)].terminal_values).value_type!=1)
                                                        {
                                                            if (strcmp(var->datatype,value_int_to_string_util((yyvsp[(3) - (3)].terminal_values).value_type))==0)
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
                                                            if (strcmp(var->datatype,(yyvsp[(3) - (3)].terminal_values).var_type)==0)
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
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 569 "Parser.y"
    {
                                        
                                       int res = express(0,(yyvsp[(1) - (3)].terminal_values).value_type,(yyvsp[(1) - (3)].terminal_values).var_type,(yyvsp[(1) - (3)].terminal_values).var_init,(yyvsp[(3) - (3)].terminal_values).value_type,(yyvsp[(3) - (3)].terminal_values).var_type,(yyvsp[(3) - (3)].terminal_values).var_init);
                                       if (res == 1)
                                        {

                                            (yyval.terminal_values)=(yyvsp[(1) - (3)].terminal_values);
                                        }
                                        else
                                        {
                                            (yyval.terminal_values).value_type = 1;
                                            (yyval.terminal_values).var_type = "Mismatch";
                                        }
                                        // printf("res = zeeroo");
                       
                                    }
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 585 "Parser.y"
    {
                                        
                                       int res = express(1,(yyvsp[(1) - (3)].terminal_values).value_type,(yyvsp[(1) - (3)].terminal_values).var_type,(yyvsp[(1) - (3)].terminal_values).var_init,(yyvsp[(3) - (3)].terminal_values).value_type,(yyvsp[(3) - (3)].terminal_values).var_type,(yyvsp[(3) - (3)].terminal_values).var_init);
                                       if (res == 1)
                                        {
                                            (yyval.terminal_values)=(yyvsp[(1) - (3)].terminal_values);
                                        }
                                         else
                                        {
                                            (yyval.terminal_values).value_type = 1;
                                            (yyval.terminal_values).var_type = "Mismatch";
                                        }
                                    }
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 598 "Parser.y"
    {(yyval.terminal_values)=(yyvsp[(1) - (1)].terminal_values);}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 603 "Parser.y"
    {
                                        int res =express(2,(yyvsp[(1) - (3)].terminal_values).value_type,(yyvsp[(1) - (3)].terminal_values).var_type,(yyvsp[(1) - (3)].terminal_values).var_init,(yyvsp[(3) - (3)].terminal_values).value_type,(yyvsp[(3) - (3)].terminal_values).var_type,(yyvsp[(3) - (3)].terminal_values).var_init);
                                        if (res == 1)
                                        {
                                            (yyval.terminal_values)=(yyvsp[(1) - (3)].terminal_values);
                                        }
                                         else
                                        {
                                            (yyval.terminal_values).value_type = 1;
                                            (yyval.terminal_values).var_type = "Mismatch";
                                        }
                                    }
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 615 "Parser.y"
    {
                                        int res =  express(3,(yyvsp[(1) - (3)].terminal_values).value_type,(yyvsp[(1) - (3)].terminal_values).var_type,(yyvsp[(1) - (3)].terminal_values).var_init,(yyvsp[(3) - (3)].terminal_values).value_type,(yyvsp[(3) - (3)].terminal_values).var_type,(yyvsp[(3) - (3)].terminal_values).var_init);
                                        if (res == 1)
                                        {
                                            (yyval.terminal_values)=(yyvsp[(1) - (3)].terminal_values);
                                        }
                                         else
                                        {
                                            (yyval.terminal_values).value_type = 1;
                                            (yyval.terminal_values).var_type = "Mismatch";
                                        }
                                    }
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 627 "Parser.y"
    {(yyval.terminal_values)=(yyvsp[(1) - (1)].terminal_values);}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 631 "Parser.y"
    {(yyval.terminal_values)=(yyvsp[(2) - (3)].terminal_values);}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 632 "Parser.y"
    {(yyval.terminal_values)=(yyvsp[(1) - (1)].terminal_values);}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 636 "Parser.y"
    {
                                        int res = cmp((yyvsp[(1) - (3)].terminal_values).value_type,(yyvsp[(1) - (3)].terminal_values).var_type,(yyvsp[(1) - (3)].terminal_values).var_init,(yyvsp[(3) - (3)].terminal_values).value_type,(yyvsp[(3) - (3)].terminal_values).var_type,(yyvsp[(3) - (3)].terminal_values).var_init);
                                        if (res==0)
                                        {
                                            printf("Comparison not possible\n");
                                        }
                                    }
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 643 "Parser.y"
    {   
                                        int res = cmp((yyvsp[(1) - (3)].terminal_values).value_type,(yyvsp[(1) - (3)].terminal_values).var_type,(yyvsp[(1) - (3)].terminal_values).var_init,(yyvsp[(3) - (3)].terminal_values).value_type,(yyvsp[(3) - (3)].terminal_values).var_type,(yyvsp[(3) - (3)].terminal_values).var_init);
                                        if (res==0)
                                        {
                                            printf("Comparison not possible\n");
                                        }
                                    }
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 650 "Parser.y"
    {    
                                        int res = cmp((yyvsp[(1) - (3)].terminal_values).value_type,(yyvsp[(1) - (3)].terminal_values).var_type,(yyvsp[(1) - (3)].terminal_values).var_init,(yyvsp[(3) - (3)].terminal_values).value_type,(yyvsp[(3) - (3)].terminal_values).var_type,(yyvsp[(3) - (3)].terminal_values).var_init);
                                        if (res==0)
                                        {
                                            printf("Comparison not possible\n");
                                        }
                                    }
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 657 "Parser.y"
    { //print all parameters of cmp
                               
                                       
                                        int res = cmp((yyvsp[(1) - (3)].terminal_values).value_type,(yyvsp[(1) - (3)].terminal_values).var_type,(yyvsp[(1) - (3)].terminal_values).var_init,(yyvsp[(3) - (3)].terminal_values).value_type,(yyvsp[(3) - (3)].terminal_values).var_type,(yyvsp[(3) - (3)].terminal_values).var_init);
                                        if (res==0)
                                        {
                                            printf("Comparison not possible\n");
                                        }
                                    }
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 666 "Parser.y"
    {
                                        int res = cmp((yyvsp[(1) - (3)].terminal_values).value_type,(yyvsp[(1) - (3)].terminal_values).var_type,(yyvsp[(1) - (3)].terminal_values).var_init,(yyvsp[(3) - (3)].terminal_values).value_type,(yyvsp[(3) - (3)].terminal_values).var_type,(yyvsp[(3) - (3)].terminal_values).var_init);
                                        if (res==0)
                                        {
                                            printf("Comparison not possible\n");
                                        }
                                    }
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 673 "Parser.y"
    {
                                        int res = cmp((yyvsp[(1) - (3)].terminal_values).value_type,(yyvsp[(1) - (3)].terminal_values).var_type,(yyvsp[(1) - (3)].terminal_values).var_init,(yyvsp[(3) - (3)].terminal_values).value_type,(yyvsp[(3) - (3)].terminal_values).var_type,(yyvsp[(3) - (3)].terminal_values).var_init);
                                        if (res==0)
                                        {
                                            printf("Comparison not possible\n");
                                        }
                                    }
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 680 "Parser.y"
    { 
                                                if (boolchecker((yyvsp[(1) - (3)].terminal_values).var_type,(yyvsp[(1) - (3)].terminal_values).var_init)==0 || boolchecker((yyvsp[(3) - (3)].terminal_values).var_type,(yyvsp[(3) - (3)].terminal_values).var_init)==0)
                                                {
                                                    printf("And Operator can only be used with boolean values\n");
                                                   
                                                } 
                                            }
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 687 "Parser.y"
    {
                                                if (boolchecker((yyvsp[(1) - (3)].terminal_values).var_type,(yyvsp[(1) - (3)].terminal_values).var_init)==0 || boolchecker((yyvsp[(3) - (3)].terminal_values).var_type,(yyvsp[(3) - (3)].terminal_values).var_init)==0)
                                                {
                                                    printf("Or Operator can only be used with boolean values\n");
                                                   
                                                } 
                                            }
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 694 "Parser.y"
    {
                                                if (boolchecker((yyvsp[(2) - (2)].terminal_values).var_type,(yyvsp[(2) - (2)].terminal_values).var_init)==0)
                                                {
                                                    printf("Not Operator can only be used with boolean values\n");
                                                }
                                            }
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 703 "Parser.y"
    {
                            (yyval.terminal_values)= (yyvsp[(1) - (1)].terminal_values);
                        }
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 706 "Parser.y"
    {
                            (yyval.terminal_values).value_type = 2;
                           
                        }
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 710 "Parser.y"
    {
                            (yyval.terminal_values).value_type = 3;
                        }
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 713 "Parser.y"
    {
                            (yyval.terminal_values).value_type = 4;
                        }
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 716 "Parser.y"
    {
                            (yyval.terminal_values).value_type = 5;
                        }
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 719 "Parser.y"
    {
                            (yyval.terminal_values).value_type = 6;
                        }
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 722 "Parser.y"
    {
                            (yyval.terminal_values).value_type = 6;
                        }
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 728 "Parser.y"
    {
                            (yyval.terminal_values).value_type = 1;
                            struct Node *node  = searchScope((yyvsp[(1) - (1)].varval));
                            if(node == NULL){
                                printf("Variable not declared\n");
                            }
                            else
                            {
                                if (node->init!=0)
                                {
                                    (yyval.terminal_values).var_type=node->datatype; 
                                    (yyval.terminal_values).var_init=node->init;
                                }else
                                {
                                    printf("Variable not initialized\n");
                                }
                            }
                        }
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 766 "Parser.y"
    {printf("While Multiple Statements\n");}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 771 "Parser.y"
    {}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 772 "Parser.y"
    {}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 773 "Parser.y"
    {}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 774 "Parser.y"
    {}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 779 "Parser.y"
    {  
                                                                                                
                                // Head_for_push();
                                // struct Node *var = getHead();push(var);
                                //if for loop is in start of the program
                            }
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 787 "Parser.y"
    { scopePush();createNode((yyvsp[(2) - (4)].varval),"int","variable",1,line);}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 796 "Parser.y"
    {}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 800 "Parser.y"
    {printf("Switch Statement\n");}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 804 "Parser.y"
    {printf("Case Statement multiple statements\n");}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 805 "Parser.y"
    {printf("Default Statement multiple statements\n");}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 809 "Parser.y"
    {printf("Return Statement with expression\n");}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 810 "Parser.y"
    {printf("Return Statement without expression\n");}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 814 "Parser.y"
    {printf("Repeat Until Statement scope\n");}
    break;



/* Line 1455 of yacc.c  */
#line 2806 "y.tab.c"
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
#line 816 "Parser.y"


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

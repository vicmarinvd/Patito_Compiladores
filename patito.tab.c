/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ID = 258,
     CTE_ENT = 259,
     CTE_FLT = 260,
     LETRERO = 261,
     PROGRAM = 262,
     VARS = 263,
     INICIO = 264,
     FIN = 265,
     SI = 266,
     SINO = 267,
     MIENTRAS = 268,
     HAZ = 269,
     ESCRIBE = 270,
     NULA = 271,
     ENTERO = 272,
     FLOTANTE = 273,
     OPEQ = 274,
     OPNEQ = 275,
     OPGT = 276,
     OPLT = 277,
     UMINUS = 278
   };
#endif
/* Tokens.  */
#define ID 258
#define CTE_ENT 259
#define CTE_FLT 260
#define LETRERO 261
#define PROGRAM 262
#define VARS 263
#define INICIO 264
#define FIN 265
#define SI 266
#define SINO 267
#define MIENTRAS 268
#define HAZ 269
#define ESCRIBE 270
#define NULA 271
#define ENTERO 272
#define FLOTANTE 273
#define OPEQ 274
#define OPNEQ 275
#define OPGT 276
#define OPLT 277
#define UMINUS 278




/* Copy the first part of user declarations.  */
#line 1 "patito.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cuadruplos.h"

// Variables externas del lexer
extern int  yylineno;
extern int  errores_lexicos;
extern FILE *yyin;

void yyerror(const char *s);
int  yylex(void);

static int errsintx  = 0;
static int errsemant = 0;


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

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 20 "patito.y"
{ char sval[64]; int tval; }
/* Line 193 of yacc.c.  */
#line 162 "patito.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 175 "patito.tab.c"

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
# if defined YYENABLE_NLS && YYENABLE_NLS
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
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
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
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   152

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  75
/* YYNRULES -- Number of states.  */
#define YYNSTATES  140

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   278

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      31,    32,    25,    23,    30,    24,     2,    26,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    29,    28,
       2,    35,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    33,     2,    34,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    27
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     4,    14,    16,    17,    20,    21,    22,
      31,    32,    33,    38,    39,    41,    43,    46,    47,    49,
      51,    52,    64,    65,    71,    72,    75,    76,    78,    79,
      83,    86,    87,    92,    93,   100,   102,   104,   106,   110,
     114,   118,   122,   126,   130,   134,   138,   141,   144,   148,
     149,   155,   157,   159,   161,   163,   164,   168,   169,   170,
     175,   176,   177,   178,   188,   189,   198,   199,   203,   204,
     210,   211,   215,   216,   220,   223
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      37,     0,    -1,    -1,     7,     3,    28,    38,    39,    47,
       9,    55,    10,    -1,    40,    -1,    -1,     8,    41,    -1,
      -1,    -1,     3,    42,    44,    29,    46,    28,    43,    41,
      -1,    -1,    -1,    30,     3,    45,    44,    -1,    -1,    17,
      -1,    18,    -1,    49,    47,    -1,    -1,    16,    -1,    46,
      -1,    -1,    48,     3,    50,    31,    51,    32,    33,    54,
      55,    34,    28,    -1,    -1,     3,    29,    46,    52,    53,
      -1,    -1,    30,    51,    -1,    -1,    40,    -1,    -1,    33,
      56,    34,    -1,    57,    56,    -1,    -1,     3,    35,    59,
      28,    -1,    -1,     3,    31,    58,    62,    32,    28,    -1,
      69,    -1,    66,    -1,    73,    -1,    59,    23,    59,    -1,
      59,    24,    59,    -1,    59,    25,    59,    -1,    59,    26,
      59,    -1,    59,    21,    59,    -1,    59,    22,    59,    -1,
      59,    19,    59,    -1,    59,    20,    59,    -1,    24,    59,
      -1,    23,    59,    -1,    31,    59,    32,    -1,    -1,     3,
      31,    60,    62,    32,    -1,     3,    -1,    61,    -1,     4,
      -1,     5,    -1,    -1,    59,    63,    64,    -1,    -1,    -1,
      30,    59,    65,    64,    -1,    -1,    -1,    -1,    13,    67,
      31,    59,    32,    68,    14,    55,    28,    -1,    -1,    11,
      31,    59,    32,    70,    55,    71,    28,    -1,    -1,    12,
      72,    55,    -1,    -1,    15,    31,    74,    32,    28,    -1,
      -1,     6,    75,    77,    -1,    -1,    59,    76,    77,    -1,
      30,    74,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    50,    50,    49,    76,    76,    77,    81,    86,    80,
      98,   103,   102,   108,   112,   113,   121,   122,   126,   127,
     132,   131,   156,   155,   168,   171,   171,   172,   172,   178,
     179,   179,   182,   203,   202,   216,   217,   218,   227,   244,
     261,   278,   291,   308,   325,   337,   349,   360,   364,   369,
     368,   387,   399,   404,   405,   414,   413,   421,   426,   425,
     433,   442,   448,   441,   477,   476,   490,   489,   507,   519,
     524,   523,   531,   530,   540,   541
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "CTE_ENT", "CTE_FLT", "LETRERO",
  "PROGRAM", "VARS", "INICIO", "FIN", "SI", "SINO", "MIENTRAS", "HAZ",
  "ESCRIBE", "NULA", "ENTERO", "FLOTANTE", "OPEQ", "OPNEQ", "OPGT", "OPLT",
  "'+'", "'-'", "'*'", "'/'", "UMINUS", "';'", "':'", "','", "'('", "')'",
  "'{'", "'}'", "'='", "$accept", "programa", "@1", "opc_var", "vars",
  "mas_vars", "@2", "@3", "decl_id", "@4", "tipo", "list_funciones",
  "func_tipo", "funcs", "@5", "list_func_def", "@6", "cont_lista",
  "hay_var", "cuerpo", "bloq_cuerpo", "estatuto", "@7", "expresion", "@8",
  "cte", "argum", "@9", "lista_exp", "@10", "ciclo", "@11", "@12",
  "condicion", "@13", "condicional_sino", "@14", "imprime",
  "conte_imprimir", "@15", "@16", "mas_imp", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,    43,    45,    42,    47,   278,    59,    58,
      44,    40,    41,   123,   125,    61
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    36,    38,    37,    39,    39,    40,    42,    43,    41,
      41,    45,    44,    44,    46,    46,    47,    47,    48,    48,
      50,    49,    52,    51,    51,    53,    53,    54,    54,    55,
      56,    56,    57,    58,    57,    57,    57,    57,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    60,
      59,    59,    59,    61,    61,    63,    62,    62,    65,    64,
      64,    67,    68,    66,    70,    69,    72,    71,    71,    73,
      75,    74,    76,    74,    77,    77
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     9,     1,     0,     2,     0,     0,     8,
       0,     0,     4,     0,     1,     1,     2,     0,     1,     1,
       0,    11,     0,     5,     0,     2,     0,     1,     0,     3,
       2,     0,     4,     0,     6,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     3,     0,
       5,     1,     1,     1,     1,     0,     3,     0,     0,     4,
       0,     0,     0,     9,     0,     8,     0,     3,     0,     5,
       0,     3,     0,     3,     2,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     2,     5,    10,    17,     4,
       7,     6,    18,    14,    15,    19,     0,     0,    17,    13,
       0,    20,    16,     0,     0,    31,     0,     0,    11,     0,
       0,     0,    61,     0,     0,    31,    36,    35,    37,     3,
      24,    13,     0,    33,     0,     0,     0,     0,    29,    30,
       0,     0,    12,     8,    57,    51,    53,    54,     0,     0,
       0,     0,    52,     0,     0,    70,    72,     0,     0,     0,
      10,    55,     0,    49,    47,    46,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    32,    64,     0,    75,    75,
       0,    22,    28,     9,    60,     0,    57,    48,    44,    45,
      42,    43,    38,    39,    40,    41,     0,    62,     0,    71,
      73,    69,    26,    27,     0,     0,    56,    34,     0,    68,
       0,    74,    24,    23,     0,    58,    50,    66,     0,     0,
      25,     0,    60,     0,    65,     0,    21,    59,    67,    63
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     6,     8,     9,    11,    19,    70,    24,    41,
      15,    16,    17,    18,    27,    51,   112,   123,   114,    26,
      34,    35,    54,    66,    96,    62,    72,    94,   116,   132,
      36,    46,   120,    37,   106,   128,   133,    38,    67,    88,
      89,   109
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -86
static const yytype_int8 yypact[] =
{
      15,    25,    30,     4,   -86,   -86,    34,    40,     1,   -86,
     -86,   -86,   -86,   -86,   -86,   -86,    38,    46,     1,    20,
      18,   -86,   -86,    63,    41,    91,    58,    49,   -86,    -9,
     -24,    50,   -86,    51,    61,    91,   -86,   -86,   -86,   -86,
      66,    20,    55,   -86,    22,    22,    65,     0,   -86,   -86,
      68,    52,   -86,   -86,    22,    69,   -86,   -86,    22,    22,
      22,    88,   -86,    35,    22,   -86,    98,    71,    -9,    72,
      40,    98,    83,   -86,   -86,   -86,    53,    22,    22,    22,
      22,    22,    22,    22,    22,   -86,   -86,    67,   101,   101,
      70,   -86,    34,   -86,   102,    73,    22,   -86,   104,   104,
      39,    39,   -13,   -13,   -86,   -86,    18,   -86,     0,   -86,
     -86,   -86,   103,   -86,    18,    22,   -86,   -86,   105,   122,
     121,   -86,    66,   -86,   106,    98,   -86,   -86,   108,    18,
     -86,   110,   102,    18,   -86,   111,   -86,   -86,   -86,   -86
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -86,   -86,   -86,   -86,    54,    74,   -86,   -86,   100,   -86,
     -27,   124,   -86,   -86,   -86,    21,   -86,   -86,   -86,   -85,
     112,   -86,   -86,   -44,   -86,   -86,    56,   -86,    13,   -86,
     -86,   -86,   -86,   -86,   -86,   -86,   -86,   -86,    42,   -86,
     -86,    59
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      61,    63,    42,    55,    56,    57,    65,    43,    13,    14,
      71,    44,    83,    84,    74,    75,    76,    12,    13,    14,
      87,   119,     1,    58,    59,    55,    56,    57,     3,   124,
       4,    60,     5,    98,    99,   100,   101,   102,   103,   104,
     105,    91,     7,    10,   135,    58,    59,    20,   138,    21,
      23,    25,    71,    60,    77,    78,    79,    80,    81,    82,
      83,    84,    81,    82,    83,    84,    28,    86,    39,    50,
      29,   125,    77,    78,    79,    80,    81,    82,    83,    84,
      40,    45,    47,    53,    69,    97,    77,    78,    79,    80,
      81,    82,    83,    84,    30,    48,    64,    68,   111,   107,
      73,   117,    31,    90,    32,    92,    33,    77,    78,    79,
      80,    81,    82,    83,    84,    95,    85,    77,    78,    79,
      80,    81,    82,    83,    84,    79,    80,    81,    82,    83,
      84,   108,   115,   122,   127,   129,   134,   126,   136,   139,
     131,    52,    22,   130,    93,   137,   113,    49,   110,     0,
     121,     0,   118
};

static const yytype_int16 yycheck[] =
{
      44,    45,    29,     3,     4,     5,     6,    31,    17,    18,
      54,    35,    25,    26,    58,    59,    60,    16,    17,    18,
      64,   106,     7,    23,    24,     3,     4,     5,     3,   114,
       0,    31,    28,    77,    78,    79,    80,    81,    82,    83,
      84,    68,     8,     3,   129,    23,    24,     9,   133,     3,
      30,    33,    96,    31,    19,    20,    21,    22,    23,    24,
      25,    26,    23,    24,    25,    26,     3,    32,    10,     3,
      29,   115,    19,    20,    21,    22,    23,    24,    25,    26,
      31,    31,    31,    28,    32,    32,    19,    20,    21,    22,
      23,    24,    25,    26,     3,    34,    31,    29,    28,    32,
      31,    28,    11,    32,    13,    33,    15,    19,    20,    21,
      22,    23,    24,    25,    26,    32,    28,    19,    20,    21,
      22,    23,    24,    25,    26,    21,    22,    23,    24,    25,
      26,    30,    30,    30,    12,    14,    28,    32,    28,    28,
      34,    41,    18,   122,    70,   132,    92,    35,    89,    -1,
     108,    -1,    96
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,    37,     3,     0,    28,    38,     8,    39,    40,
       3,    41,    16,    17,    18,    46,    47,    48,    49,    42,
       9,     3,    47,    30,    44,    33,    55,    50,     3,    29,
       3,    11,    13,    15,    56,    57,    66,    69,    73,    10,
      31,    45,    46,    31,    35,    31,    67,    31,    34,    56,
       3,    51,    44,    28,    58,     3,     4,     5,    23,    24,
      31,    59,    61,    59,    31,     6,    59,    74,    29,    32,
      43,    59,    62,    31,    59,    59,    59,    19,    20,    21,
      22,    23,    24,    25,    26,    28,    32,    59,    75,    76,
      32,    46,    33,    41,    63,    32,    60,    32,    59,    59,
      59,    59,    59,    59,    59,    59,    70,    32,    30,    77,
      77,    28,    52,    40,    54,    30,    64,    28,    62,    55,
      68,    74,    30,    53,    55,    59,    32,    12,    71,    14,
      51,    34,    65,    72,    28,    55,    28,    64,    55,    28
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
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
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
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
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



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

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
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
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
#line 50 "patito.y"
    {
        // PN-1: inicializar todas las estructuras
        initCubo();
        initTabla(&tablaGlobal);
        initDirectorio(&directorio);
        initStack(&pilaIDs);
        initPilaOperandos(&pilaOperandos);
        initPilaTipos(&pilaTipos);
        initPilaOperadores(&pilaOperadores);
        initPilaJumps(&pilaJumps);
        initFila(&filaCuadruplos);
        tablaActual = &tablaGlobal;
        printf("Leyendo: %s\n", (yyvsp[(2) - (3)].sval));
      ;}
    break;

  case 3:
#line 65 "patito.y"
    {
        printf("\nprograma Patito es valido.\n");
        imprimirDirectorio(&directorio);
        imprimirFila(&filaCuadruplos);
      ;}
    break;

  case 7:
#line 81 "patito.y"
    {
        // PN-2: acumular el primer ID de la declaracion
        pushID(&pilaIDs, (yyvsp[(1) - (1)].sval));
      ;}
    break;

  case 8:
#line 86 "patito.y"
    {
        // PN-3: vaciar la pila de IDs a la tabla activa
        // detecta variable doblemente declarada
        while (!stackVacio(&pilaIDs)) {
            char *nombre = popID(&pilaIDs);
            if (insertarVariable(tablaActual, nombre, (yyvsp[(5) - (6)].tval)) != 0)
                fprintf(stderr,
                    "Error Semantico: variable doblemente declarada '%s'\n",
                    nombre);
        }
      ;}
    break;

  case 11:
#line 103 "patito.y"
    {
        // PN-4: acumular IDs adicionales (x, y, z : entero)
        pushID(&pilaIDs, (yyvsp[(2) - (2)].sval));
      ;}
    break;

  case 14:
#line 112 "patito.y"
    { (yyval.tval) = TIPO_INT; ;}
    break;

  case 15:
#line 113 "patito.y"
    { (yyval.tval) = TIPO_FLT; ;}
    break;

  case 18:
#line 126 "patito.y"
    { (yyval.tval) = TIPO_NULA; ;}
    break;

  case 19:
#line 127 "patito.y"
    { (yyval.tval) = (yyvsp[(1) - (1)].tval); ;}
    break;

  case 20:
#line 132 "patito.y"
    {
        // PN-5: registrar funcion en el directorio
        // detecta funcion doblemente declarada
        // cambia el ambito activo a las locales de la funcion
        if (insertarFuncion(&directorio, (yyvsp[(2) - (2)].sval), (yyvsp[(1) - (2)].tval)) != 0) {
            fprintf(stderr,
                "Error Semantico: funcion doblemente declarada '%s'\n", (yyvsp[(2) - (2)].sval));
            errsemant++;
            funcionActual = NULL;
        } else {
            funcionActual = buscarFuncion(&directorio, (yyvsp[(2) - (2)].sval));
            tablaActual   = &funcionActual->locales;
        }
      ;}
    break;

  case 21:
#line 147 "patito.y"
    {
        // PN-6: cerrar ambito de la funcion, volver a global
        funcionActual = NULL;
        tablaActual   = &tablaGlobal;
      ;}
    break;

  case 22:
#line 156 "patito.y"
    {
        // PN-7: registrar parametro formal en locales de la funcion
        // detecta parametro doblemente declarado
        if (funcionActual) {
            if (insertarVariable(&funcionActual->locales, (yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].tval)) != 0) {
                fprintf(stderr,
                    "Error Semantico: parametro duplicado '%s'\n", (yyvsp[(1) - (3)].sval));
                errsemant++;
            }
        }
      ;}
    break;

  case 32:
#line 183 "patito.y"
    {
        // PN-8: asignacion
        // verificar compatibilidad de tipos con el cubo semantico
        // generar cuadruplo de asignacion
        int t_expr = popTipo(&pilaTipos);
        int t_var  = getTipoVar((yyvsp[(1) - (4)].sval));
        if (t_var == TIPO_ERR) {
            fprintf(stderr,
                "Error Semantico: variable no declarada '%s'\n", (yyvsp[(1) - (4)].sval));
            errsemant++;
        } else if (consultarCubo(t_var, t_expr, OP_ASG) == TIPO_ERR) {
            fprintf(stderr,
                "Error Semantico: asignacion incompatible %s = %s\n",
                tipoToString(t_var), tipoToString(t_expr));
            errsemant++;
        }
        generarCuad("=", (yyvsp[(3) - (4)].sval), "_", (yyvsp[(1) - (4)].sval));
      ;}
    break;

  case 33:
#line 203 "patito.y"
    {
        // PN-9a: preparar llamada como estatuto
        contadorArgs = 0;
        strncpy(funcCallBuf, (yyvsp[(1) - (2)].sval), 63);
      ;}
    break;

  case 34:
#line 209 "patito.y"
    {
        // PN-9b: generar cuadruplo CALL (resultado descartado)
        char cnt[10];
        sprintf(cnt, "%d", contadorArgs);
        generarCuad("CALL", funcCallBuf, cnt, "_");
      ;}
    break;

  case 38:
#line 228 "patito.y"
    {
        // PN-E1: verificar tipos con cubo, generar cuadruplo +
        int t_der = popTipo(&pilaTipos);
        int t_izq = popTipo(&pilaTipos);
        int t_res = consultarCubo(t_izq, t_der, OP_ADD);
        if (t_res == TIPO_ERR) {
            fprintf(stderr, "Error Semantico: tipos incompatibles en '+'\n");
            errsemant++;
        }
        char *tmp = nuevoTemp();
        generarCuad("+", (yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].sval), tmp);
        strcpy((yyval.sval), tmp);
        pushTipo(&pilaTipos, t_res);
      ;}
    break;

  case 39:
#line 245 "patito.y"
    {
        // PN-E2: verificar tipos con cubo, generar cuadruplo -
        int t_der = popTipo(&pilaTipos);
        int t_izq = popTipo(&pilaTipos);
        int t_res = consultarCubo(t_izq, t_der, OP_SUB);
        if (t_res == TIPO_ERR) {
            fprintf(stderr, "Error Semantico: tipos incompatibles en '-'\n");
            errsemant++;
        }
        char *tmp = nuevoTemp();
        generarCuad("-", (yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].sval), tmp);
        strcpy((yyval.sval), tmp);
        pushTipo(&pilaTipos, t_res);
      ;}
    break;

  case 40:
#line 262 "patito.y"
    {
        // PN-E3: verificar tipos con cubo, generar cuadruplo *
        int t_der = popTipo(&pilaTipos);
        int t_izq = popTipo(&pilaTipos);
        int t_res = consultarCubo(t_izq, t_der, OP_MUL);
        if (t_res == TIPO_ERR) {
            fprintf(stderr, "Error Semantico: tipos incompatibles en '*'\n");
            errsemant++;
        }
        char *tmp = nuevoTemp();
        generarCuad("*", (yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].sval), tmp);
        strcpy((yyval.sval), tmp);
        pushTipo(&pilaTipos, t_res);
      ;}
    break;

  case 41:
#line 279 "patito.y"
    {
        // PN-E4: generar cuadruplo / (resultado siempre FLT)
        int t_der = popTipo(&pilaTipos);
        int t_izq = popTipo(&pilaTipos);
        int t_res = consultarCubo(t_izq, t_der, OP_DIV);
        char *tmp = nuevoTemp();
        generarCuad("/", (yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].sval), tmp);
        strcpy((yyval.sval), tmp);
        pushTipo(&pilaTipos, t_res);
      ;}
    break;

  case 42:
#line 292 "patito.y"
    {
        // PN-E5: relacional >, resultado siempre INT (booleano)
        int t_der = popTipo(&pilaTipos);
        int t_izq = popTipo(&pilaTipos);
        int t_res = consultarCubo(t_izq, t_der, OP_GT);
        if (t_res == TIPO_ERR) {
            fprintf(stderr, "Error Semantico: tipos incompatibles en '>'\n");
            errsemant++;
        }
        char *tmp = nuevoTemp();
        generarCuad(">", (yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].sval), tmp);
        strcpy((yyval.sval), tmp);
        pushTipo(&pilaTipos, TIPO_INT);
      ;}
    break;

  case 43:
#line 309 "patito.y"
    {
        // PN-E6: relacional <, resultado siempre INT (booleano)
        int t_der = popTipo(&pilaTipos);
        int t_izq = popTipo(&pilaTipos);
        int t_res = consultarCubo(t_izq, t_der, OP_LT);
        if (t_res == TIPO_ERR) {
            fprintf(stderr, "Error Semantico: tipos incompatibles en '<'\n");
            errsemant++;
        }
        char *tmp = nuevoTemp();
        generarCuad("<", (yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].sval), tmp);
        strcpy((yyval.sval), tmp);
        pushTipo(&pilaTipos, TIPO_INT);
      ;}
    break;

  case 44:
#line 326 "patito.y"
    {
        // PN-E7: relacional ==, resultado siempre INT (booleano)
        int t_der = popTipo(&pilaTipos);
        int t_izq = popTipo(&pilaTipos);
        char *tmp = nuevoTemp();
        generarCuad("==", (yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].sval), tmp);
        strcpy((yyval.sval), tmp);
        pushTipo(&pilaTipos, TIPO_INT);
      ;}
    break;

  case 45:
#line 338 "patito.y"
    {
        // PN-E8: relacional !=, resultado siempre INT (booleano)
        int t_der = popTipo(&pilaTipos);
        int t_izq = popTipo(&pilaTipos);
        char *tmp = nuevoTemp();
        generarCuad("!=", (yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].sval), tmp);
        strcpy((yyval.sval), tmp);
        pushTipo(&pilaTipos, TIPO_INT);
      ;}
    break;

  case 46:
#line 350 "patito.y"
    {
        // PN-E9: genera cuadruplo UMINUS, conserva el tipo
        int t = popTipo(&pilaTipos);
        char *tmp = nuevoTemp();
        generarCuad("UMINUS", (yyvsp[(2) - (2)].sval), "_", tmp);
        strcpy((yyval.sval), tmp);
        pushTipo(&pilaTipos, t);
      ;}
    break;

  case 47:
#line 361 "patito.y"
    { strcpy((yyval.sval), (yyvsp[(2) - (2)].sval)); ;}
    break;

  case 48:
#line 365 "patito.y"
    { strcpy((yyval.sval), (yyvsp[(2) - (3)].sval)); ;}
    break;

  case 49:
#line 369 "patito.y"
    {
        // PN-E10a: preparar nombre y contador de args
        contadorArgs = 0;
        strncpy(funcCallBuf, (yyvsp[(1) - (2)].sval), 63);
      ;}
    break;

  case 50:
#line 375 "patito.y"
    {
        // PN-E10b: generar CALL, empujar tipo de retorno
        char cnt[10];
        sprintf(cnt, "%d", contadorArgs);
        Funcion *f = buscarFuncion(&directorio, funcCallBuf);
        char *tmp = nuevoTemp();
        generarCuad("CALL", funcCallBuf, cnt, tmp);
        strcpy((yyval.sval), tmp);
        pushTipo(&pilaTipos, f ? f->tipoRetorno : TIPO_ERR);
      ;}
    break;

  case 51:
#line 388 "patito.y"
    {
        // PN-E11: empujar nombre e tipo a las pilas
        strcpy((yyval.sval), (yyvsp[(1) - (1)].sval));
        int t = getTipoVar((yyvsp[(1) - (1)].sval));
        if (t == TIPO_ERR)
            fprintf(stderr,
                "Error Semantico: variable no declarada '%s'\n", (yyvsp[(1) - (1)].sval));
        pushTipo(&pilaTipos, t);
      ;}
    break;

  case 52:
#line 400 "patito.y"
    { strcpy((yyval.sval), (yyvsp[(1) - (1)].sval)); ;}
    break;

  case 53:
#line 404 "patito.y"
    { strcpy((yyval.sval), (yyvsp[(1) - (1)].sval)); pushTipo(&pilaTipos, TIPO_INT); ;}
    break;

  case 54:
#line 405 "patito.y"
    { strcpy((yyval.sval), (yyvsp[(1) - (1)].sval)); pushTipo(&pilaTipos, TIPO_FLT); ;}
    break;

  case 55:
#line 414 "patito.y"
    {
        // PN-A1: generar ARG para el primer argumento
        generarCuad("ARG", (yyvsp[(1) - (1)].sval), "_", "_");
        popTipo(&pilaTipos);
        contadorArgs++;
      ;}
    break;

  case 58:
#line 426 "patito.y"
    {
        // PN-A2: generar ARG para cada argumento adicional
        generarCuad("ARG", (yyvsp[(2) - (2)].sval), "_", "_");
        popTipo(&pilaTipos);
        contadorArgs++;
      ;}
    break;

  case 61:
#line 442 "patito.y"
    {
        // PN-C1: guardar posicion de inicio del ciclo en PilaJumps
        // este indice sera el destino del GOTO al final del cuerpo
        pushJump(&pilaJumps, filaCuadruplos.count);
      ;}
    break;

  case 62:
#line 448 "patito.y"
    {
        // PN-C2: condicion evaluada
        // generar GOTOF con destino pendiente (??)
        // guardar su indice para backpatching posterior
        popTipo(&pilaTipos);
        generarCuad("GOTOF", (yyvsp[(4) - (5)].sval), "_", "???");
        pushJump(&pilaJumps, filaCuadruplos.count - 1);
      ;}
    break;

  case 63:
#line 457 "patito.y"
    {
        // PN-C3: fin del cuerpo
        // sacar indice del GOTOF y del inicio del ciclo
        // generar GOTO de regreso al inicio
        // rellenar el GOTOF con la posicion actual (salida del ciclo)
        int fin     = popJump(&pilaJumps);
        int retorno = popJump(&pilaJumps);
        char buf[12];
        sprintf(buf, "%d", retorno);
        generarCuad("GOTO", "_", "_", buf);
        fillJump(&filaCuadruplos, fin, filaCuadruplos.count);
      ;}
    break;

  case 64:
#line 477 "patito.y"
    {
        // PN-IF1: condicion evaluada
        // generar GOTOF con destino pendiente
        // guardar su indice para backpatching
        popTipo(&pilaTipos);
        generarCuad("GOTOF", (yyvsp[(3) - (4)].sval), "_", "???");
        pushJump(&pilaJumps, filaCuadruplos.count - 1);
      ;}
    break;

  case 66:
#line 490 "patito.y"
    {
        // PN-IF2: fin del bloque verdadero
        // generar GOTO para saltar el bloque sino (destino pendiente)
        // rellenar el GOTOF anterior con la posicion actual
        generarCuad("GOTO", "_", "_", "???");
        int falso = popJump(&pilaJumps);
        pushJump(&pilaJumps, filaCuadruplos.count - 1);
        fillJump(&filaCuadruplos, falso, filaCuadruplos.count);
      ;}
    break;

  case 67:
#line 500 "patito.y"
    {
        // PN-IF3: fin del bloque sino
        // rellenar el GOTO con la posicion actual
        int fin = popJump(&pilaJumps);
        fillJump(&filaCuadruplos, fin, filaCuadruplos.count);
      ;}
    break;

  case 68:
#line 507 "patito.y"
    {
        // PN-IF-END: si no hay sino, rellenar el GOTOF con la posicion actual
        int fin = popJump(&pilaJumps);
        fillJump(&filaCuadruplos, fin, filaCuadruplos.count);
      ;}
    break;

  case 70:
#line 524 "patito.y"
    {
        // PN-P1: imprimir string literal
        generarCuad("PRINT", (yyvsp[(1) - (1)].sval), "_", "_");
      ;}
    break;

  case 72:
#line 531 "patito.y"
    {
        // PN-P2: imprimir resultado de expresion
        generarCuad("PRINT", (yyvsp[(1) - (1)].sval), "_", "_");
        popTipo(&pilaTipos);
      ;}
    break;


/* Line 1267 of yacc.c.  */
#line 1977 "patito.tab.c"
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
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  if (yyn == YYFINAL)
    YYACCEPT;

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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
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


#line 544 "patito.y"


void yyerror(const char *s) {
    fprintf(stderr, "Error Sintactico, Linea %d: %s\n", yylineno, s);
    errsintx++;
}

int main(int argc, char *argv[]) {

    if (argc > 1) {
        FILE *f = fopen(argv[1], "r");
        if (!f) {
            fprintf(stderr, "Error: no se pudo abrir '%s'\n", argv[1]);
            return 1;
        }
        yyin = f;
        printf("Leyendo: %s\n", argv[1]);
    } else {
        printf("Leyendo desde stdin:\n");
    }

    yyparse();

    printf("Errores lexicos:     %d\n", errores_lexicos);
    printf("Errores sintacticos: %d\n", errsintx);
    printf("Errores semanticos:  %d\n", errsemant);

    if (argc > 1) fclose(yyin);

    return (errores_lexicos + errsintx + errsemant > 0) ? 1 : 0;
}


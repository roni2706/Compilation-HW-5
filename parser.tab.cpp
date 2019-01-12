/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 2 "parser.ypp" /* yacc.c:339  */

	#include <iostream>
	#include <sstream>
	#include <stdlib.h>
	#include "parser.hpp"
	#include "output.hpp"
	#include "parser.tab.hpp"
	
	using namespace output;
	using std::cout;
	using std::endl;
	
	extern int yylineno;
	int yylex();
	void yyerror(char const*);
	
	SymbolTable* table = NULL;
	RegPool* regPool;
	

#line 87 "parser.tab.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.hpp".  */
#ifndef YY_YY_PARSER_TAB_HPP_INCLUDED
# define YY_YY_PARSER_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    VOID = 258,
    INT = 259,
    BYTE = 260,
    B = 261,
    BOOL = 262,
    STRUCT = 263,
    TRUE = 264,
    FALSE = 265,
    RETURN = 266,
    IF = 267,
    ELSE = 269,
    WHILE = 270,
    BREAK = 271,
    CONTINUE = 272,
    SC = 273,
    COMMA = 274,
    LBRACE = 275,
    RBRACE = 276,
    ID = 277,
    NUM = 278,
    STRING = 279,
    EF = 280,
    ASSIGN = 281,
    OR = 282,
    AND = 283,
    EQ = 284,
    REL = 285,
    ADD = 286,
    MUL = 287,
    NOT = 288,
    LPAREN = 289,
    RPAREN = 290,
    PERIOD = 291
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 174 "parser.tab.cpp" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   180

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  85
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  148

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   291

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    86,    86,   110,   110,    86,   142,   142,   148,   154,
     162,   175,   191,   154,   207,   213,   219,   219,   238,   246,
     254,   262,   270,   289,   306,   316,   316,   335,   353,   370,
     380,   386,   392,   403,   392,   414,   420,   426,   446,   446,
     480,   498,   480,   534,   542,   555,   574,   580,   580,   599,
     607,   599,   622,   634,   646,   654,   646,   674,   674,   729,
     737,   745,   758,   770,   786,   807,   815,   823,   831,   839,
     847,   885,   923,   940,   940,   980,   991,  1002,  1020,  1029,
    1040,  1051,  1074,  1105,  1136,  1172
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VOID", "INT", "BYTE", "B", "BOOL",
  "STRUCT", "TRUE", "FALSE", "RETURN", "IF", "\"then\"", "ELSE", "WHILE",
  "BREAK", "CONTINUE", "SC", "COMMA", "LBRACE", "RBRACE", "ID", "NUM",
  "STRING", "EF", "ASSIGN", "OR", "AND", "EQ", "REL", "ADD", "MUL", "NOT",
  "LPAREN", "RPAREN", "PERIOD", "$accept", "Program", "$@1", "$@2", "$@3",
  "Funcs", "$@4", "FuncDecl", "$@5", "$@6", "$@7", "$@8", "Structs",
  "StructsDecl", "$@9", "RetType", "Formals", "FormalsList", "FormalDecl",
  "$@10", "StructMemList", "StructMem", "Statements", "Statement", "$@11",
  "$@12", "$@13", "$@14", "$@15", "$@16", "$@17", "$@18", "If", "$@19",
  "$@20", "Call", "$@21", "CallParams", "ExpList", "VarDecl", "Type",
  "StructType", "Exp", "$@22", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291
};
# endif

#define YYPACT_NINF -67

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-67)))

#define YYTABLE_NINF -74

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-74)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -67,     5,    -1,   -67,   -11,   -67,    -1,   -67,   149,   -67,
       7,   -67,   -67,   -67,   -67,   -67,   -67,    -2,   -67,   162,
      16,   149,   -67,    19,   -67,    22,   -67,   -67,    13,    31,
     -67,    34,   153,   -67,   -67,    33,    21,    42,   -67,    44,
     -67,   -67,   -67,   153,   -67,    45,    51,   -67,   -67,   -67,
      81,    46,    36,    39,    49,    58,    66,   -67,    -5,   -67,
      81,   -67,    73,    76,     4,    78,    96,   103,   -67,   -67,
     -67,   -18,    93,   -67,    41,    41,   -67,    77,    41,    41,
     -67,   -67,    81,   -67,   -67,   -67,   117,   -67,   -67,   -67,
     -67,    41,   -67,   -67,   123,   -67,   -67,   105,   -67,    41,
      41,    41,    41,    41,    41,   114,   114,    81,    41,    41,
     146,   -67,    81,    84,   148,   -67,   119,   133,   133,    48,
     107,   -67,   120,   136,   151,    92,   138,   155,   114,   -67,
     -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,    41,   150,
      81,    81,   114,    41,   -67,   -67,    99,   -67
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,    15,     1,     0,     3,    15,    16,     8,    14,
       0,    19,    65,    66,    67,     4,     6,     0,    18,     0,
       0,     8,     9,     0,    27,     0,     5,     7,     0,     0,
      28,     0,    21,    17,    29,     0,     0,    20,    22,     0,
      25,    68,    10,     0,    24,     0,     0,    23,    26,    11,
       0,     0,     0,     0,     0,     0,     0,    32,     0,    36,
      12,    30,    46,     0,     0,     0,     0,    16,    79,    80,
      44,    72,    76,    78,     0,     0,    75,     0,     0,     0,
      52,    53,     0,    38,    57,    40,     0,    31,    47,    43,
      35,     0,    63,    64,     0,    77,    81,     0,    45,     0,
       0,     0,     0,     0,     0,    54,    49,    33,     0,    60,
       0,    13,     0,     0,     0,    69,    83,    82,    85,    84,
      71,    70,     0,     0,     0,     0,     0,    59,    61,    41,
      48,    37,    74,    55,    50,    34,    39,    58,     0,     0,
       0,     0,    62,     0,    56,    51,     0,    42
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -67,   -67,   -67,   -67,   -67,   154,   -67,   -67,   -67,   -67,
     -67,   -67,   171,     0,   -67,   -67,   -67,   -67,   135,   -67,
     -67,   156,    98,   -59,   -67,   -67,   -67,   -67,   -67,   -67,
     -67,   -67,   -67,   -67,   -67,   -50,   -67,   -67,   -67,   -67,
      -4,   -29,   -66,   -67
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     8,    20,    15,    21,    16,    28,    46,
      50,    86,     5,    59,    10,    17,    36,    37,    38,    45,
      23,    24,    60,    61,    82,   124,   108,   110,   139,   112,
     123,   141,    62,   122,   140,    76,   109,   126,   127,    64,
      65,    66,    77,    94
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      63,    87,     6,    40,    18,     3,     6,     4,    96,    97,
      63,     7,   105,   106,    40,    25,    84,    18,   -73,    25,
      22,    83,    90,    12,    13,   113,    14,    19,    39,    84,
      91,    85,    63,   116,   117,   118,   119,   120,   121,    39,
      29,    26,   125,   128,    31,    68,    69,    32,    87,    33,
      68,    69,    34,   130,    70,    41,    42,    63,    71,    72,
      73,    43,    63,    71,    72,    73,    44,    48,    67,    74,
      75,    49,   142,    78,    74,    75,    80,   146,   -74,   103,
     104,   144,   145,    79,    81,    12,    13,    88,    14,    51,
      63,    63,    52,    53,    89,    98,    54,    55,    56,    95,
      92,    57,   131,    58,    99,   100,   101,   102,   103,   104,
     136,    99,   100,   101,   102,   103,   104,   147,    93,    99,
     100,   101,   102,   103,   104,   -68,    99,   100,   101,   102,
     103,   104,    99,   100,   101,   102,   103,   104,   111,   104,
     115,    99,   100,   101,   102,   103,   104,   100,   101,   102,
     103,   104,    11,    12,    13,   133,    14,    12,    13,   114,
      14,    35,   101,   102,   103,   104,    12,    13,   129,    14,
     132,   134,   135,   137,   138,    27,   143,     9,    47,    30,
     107
};

static const yytype_uint8 yycheck[] =
{
      50,    60,     2,    32,     8,     0,     6,     8,    74,    75,
      60,    22,    78,    79,    43,    19,    34,    21,    36,    23,
      22,    26,    18,     4,     5,    91,     7,    20,    32,    34,
      26,    36,    82,    99,   100,   101,   102,   103,   104,    43,
      21,    25,   108,   109,    22,     9,    10,    34,   107,    18,
       9,    10,    18,   112,    18,    22,    35,   107,    22,    23,
      24,    19,   112,    22,    23,    24,    22,    22,    22,    33,
      34,    20,   138,    34,    33,    34,    18,   143,    30,    31,
      32,   140,   141,    34,    18,     4,     5,    14,     7,     8,
     140,   141,    11,    12,    18,    18,    15,    16,    17,     6,
      22,    20,    18,    22,    27,    28,    29,    30,    31,    32,
      18,    27,    28,    29,    30,    31,    32,    18,    22,    27,
      28,    29,    30,    31,    32,    22,    27,    28,    29,    30,
      31,    32,    27,    28,    29,    30,    31,    32,    21,    32,
      35,    27,    28,    29,    30,    31,    32,    28,    29,    30,
      31,    32,     3,     4,     5,    35,     7,     4,     5,    36,
       7,     8,    29,    30,    31,    32,     4,     5,    22,     7,
      22,    35,    21,    35,    19,    21,    26,     6,    43,    23,
      82
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    38,    39,     0,     8,    49,    50,    22,    40,    49,
      51,     3,     4,     5,     7,    42,    44,    52,    77,    20,
      41,    43,    22,    57,    58,    77,    25,    42,    45,    21,
      58,    22,    34,    18,    18,     8,    53,    54,    55,    77,
      78,    22,    35,    19,    22,    56,    46,    55,    22,    20,
      47,     8,    11,    12,    15,    16,    17,    20,    22,    50,
      59,    60,    69,    72,    76,    77,    78,    22,     9,    10,
      18,    22,    23,    24,    33,    34,    72,    79,    34,    34,
      18,    18,    61,    26,    34,    36,    48,    60,    14,    18,
      18,    26,    22,    22,    80,     6,    79,    79,    18,    27,
      28,    29,    30,    31,    32,    79,    79,    59,    63,    73,
      64,    21,    66,    79,    36,    35,    79,    79,    79,    79,
      79,    79,    70,    67,    62,    79,    74,    75,    79,    22,
      60,    18,    22,    35,    35,    21,    18,    35,    19,    65,
      71,    68,    79,    26,    60,    60,    79,    18
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    37,    39,    40,    41,    38,    43,    42,    42,    45,
      46,    47,    48,    44,    49,    49,    51,    50,    52,    52,
      53,    53,    54,    54,    55,    56,    55,    57,    57,    58,
      59,    59,    61,    62,    60,    60,    60,    60,    63,    60,
      64,    65,    60,    60,    60,    60,    60,    66,    60,    67,
      68,    60,    60,    60,    70,    71,    69,    73,    72,    74,
      74,    75,    75,    76,    76,    77,    77,    77,    78,    79,
      79,    79,    79,    80,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     0,     6,     0,     3,     0,     0,
       0,     0,     0,    12,     2,     0,     0,     7,     1,     1,
       1,     0,     1,     3,     2,     0,     3,     1,     2,     3,
       1,     2,     0,     0,     5,     2,     1,     4,     0,     5,
       0,     0,     8,     2,     2,     3,     1,     0,     4,     0,
       0,     7,     2,     2,     0,     0,     7,     0,     5,     1,
       0,     1,     3,     2,     2,     1,     1,     1,     2,     3,
       3,     3,     1,     0,     4,     1,     1,     2,     1,     1,
       1,     2,     3,     3,     3,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

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
#line 86 "parser.ypp" /* yacc.c:1646  */
    {
		/********************************************************************/
			string baseTypes[] = { "int","bool","byte","string" };
			table = new SymbolTable(baseTypes, 4, "block");
			regPool = new RegPool();
			string printParamNames[] = { "_noName" };
			string printParamTypes[] = { "string" };
			table->addFunc(
				"print",
				"void",
				printParamNames,
				printParamTypes,
				1
			);
			string printiParamNames[] = { "_noName" };
			string printiParamTypes[] = { "int" };
			table->addFunc(
				"printi",
				"void",
				printiParamNames,
				printiParamTypes,
				1
			);
		/********************************************************************/
		}
#line 1389 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 110 "parser.ypp" /* yacc.c:1646  */
    { }
#line 1395 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 110 "parser.ypp" /* yacc.c:1646  */
    {
		/********************************************************************/
			try {
				if ((table->findFunc("main").getRetType() != "void") ||
					(table->findFunc("main").size() != 0)){
						throw FunctionNotFoundException();
				}
			}
			catch (FunctionNotFoundException e) {
				// Missing main function
				errorMainMissing();
				exit(0);
			}
			try {
				table->printScope();
				table->printFuncs();
				table->printStructs();
				table->removeScope();
			}
			catch (RemovedBaseScopeException e) {
				// as it sould
			}
		/********************************************************************/
		}
#line 1424 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 133 "parser.ypp" /* yacc.c:1646  */
    {
		/********************************************************************/
			return 0;
		}
#line 1433 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 142 "parser.ypp" /* yacc.c:1646  */
    { }
#line 1439 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 142 "parser.ypp" /* yacc.c:1646  */
    { }
#line 1445 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 148 "parser.ypp" /* yacc.c:1646  */
    { }
#line 1451 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 154 "parser.ypp" /* yacc.c:1646  */
    {
		/********************************************************************/
			if (table->isNameUsed(*((yyvsp[0].str)))){
				// Redeclaration of function
				errorDef(yylineno,*((yyvsp[0].str)));
				exit(0);
			}
		/********************************************************************/
		}
#line 1465 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 162 "parser.ypp" /* yacc.c:1646  */
    {
		/********************************************************************/
			if ((yyvsp[-1].funcParams)){
				table->addFunc(
					*((yyvsp[-4].str)),
					*((yyvsp[-5].str)),
					*((yyvsp[-1].funcParams))
				);
			}
			else {
				table->addFunc(*((yyvsp[-4].str)),*((yyvsp[-5].str)));
			}
		/********************************************************************/
		}
#line 1484 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 175 "parser.ypp" /* yacc.c:1646  */
    {
		/********************************************************************/
			if ((yyvsp[-3].funcParams)){
				table->addScope(
					((yyvsp[-3].funcParams))->getParamsNames(),
					((yyvsp[-3].funcParams))->getParamsTypes(),
					("function"),
					(*((yyvsp[-7].str))));
				delete ((yyvsp[-3].funcParams));
			}
			else {
				table->addScope("function",*((yyvsp[-7].str)));
			}
			delete ((yyvsp[-6].str));
			delete ((yyvsp[-7].str));
		/********************************************************************/
		}
#line 1506 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 191 "parser.ypp" /* yacc.c:1646  */
    { }
#line 1512 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 191 "parser.ypp" /* yacc.c:1646  */
    {
		/********************************************************************/
			try{
				table->printScope();
				table->printStructs();
				table->removeScope();
			}
			catch (NoScopesException e){
				throw NoScopesException();
			}
		}
#line 1528 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 207 "parser.ypp" /* yacc.c:1646  */
    { }
#line 1534 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 213 "parser.ypp" /* yacc.c:1646  */
    { }
#line 1540 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 219 "parser.ypp" /* yacc.c:1646  */
    {
		/********************************************************************/
			if (table->isNameUsed(*((yyvsp[0].str)))){
					// Redeclaration of struct
					errorDef(yylineno,*((yyvsp[0].str)));
					exit(0);
				}
		/********************************************************************/
		}
#line 1554 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 227 "parser.ypp" /* yacc.c:1646  */
    {
		/********************************************************************/
			table->addStruct(*((yyvsp[-5].str)),*((yyvsp[-2].structMembers)));
			delete ((yyvsp[-5].str));
			delete ((yyvsp[-2].structMembers));
		}
#line 1565 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 238 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.str) = (yyvsp[0].str);
		}
#line 1573 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 246 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.str) = (yyvsp[0].str);
		}
#line 1581 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 254 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.funcParams) = (yyvsp[0].funcParams);
		}
#line 1589 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 262 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.funcParams) = NULL;
		}
#line 1597 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 270 "parser.ypp" /* yacc.c:1646  */
    {
			try{
				FuncParams* params = new FuncParams();
				params->addParam(*((yyvsp[0].var)));
				(yyval.funcParams) = params;
				delete ((yyvsp[0].var));
			}
			catch (NameAlreadyExistsException e){
				// Redeclaration of function parameter
				errorDef(yylineno,((yyvsp[0].var))->getName());
				exit(0);
			}
			
		}
#line 1616 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 289 "parser.ypp" /* yacc.c:1646  */
    {
			try {
				((yyvsp[-2].funcParams))->addParam(*((yyvsp[0].var)));
				(yyval.funcParams) = (yyvsp[-2].funcParams);
				delete ((yyvsp[0].var));
			}
			catch (NameAlreadyExistsException e){
				// Redeclaration of function parameter
				errorDef(yylineno,((yyvsp[0].var))->getName());
				exit(0);
			}		
		}
#line 1633 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 306 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.var) = new Var(*((yyvsp[0].str)),*((yyvsp[-1].str)));
			delete ((yyvsp[0].str));
			delete ((yyvsp[-1].str));
		}
#line 1643 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 316 "parser.ypp" /* yacc.c:1646  */
    { 
		/********************************************************************/
			if (!table->isTypeExists(*((yyvsp[0].str)))){
				// Declaration of function parameter of undefined struct type
				errorUndefStruct(yylineno,*((yyvsp[0].str)));
				exit(0);
			}
		/********************************************************************/
		}
#line 1657 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 324 "parser.ypp" /* yacc.c:1646  */
    {
		/********************************************************************/
			(yyval.var) = new Var(*((yyvsp[0].str)),*((yyvsp[-2].str)));
			delete ((yyvsp[0].str));
			delete ((yyvsp[-2].str));
		}
#line 1668 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 335 "parser.ypp" /* yacc.c:1646  */
    {
			try {
				StructMembers* members = new StructMembers();
				members->addMember(*((yyvsp[0].var)));
				(yyval.structMembers) = members;
				delete ((yyvsp[0].var));
			}
			catch (NameAlreadyExistsException e){
				// Redeclaration of struct members
				errorDef(yylineno,((yyvsp[0].var))->getName());
				exit(0);
			}
		}
#line 1686 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 353 "parser.ypp" /* yacc.c:1646  */
    {
			try {
				((yyvsp[-1].structMembers))->addMember(*((yyvsp[0].var)));
				(yyval.structMembers) = (yyvsp[-1].structMembers);
				delete ((yyvsp[0].var));
			}
			catch (NameAlreadyExistsException e){
				// Redeclaration of struct members
				errorDef(yylineno,((yyvsp[0].var))->getName());
				exit(0);
			}
		}
#line 1703 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 370 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.var) = new Var(*((yyvsp[-1].str)),*((yyvsp[-2].str)));
			delete ((yyvsp[-1].str));
			delete ((yyvsp[-2].str));
		}
#line 1713 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 380 "parser.ypp" /* yacc.c:1646  */
    { }
#line 1719 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 386 "parser.ypp" /* yacc.c:1646  */
    { }
#line 1725 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 392 "parser.ypp" /* yacc.c:1646  */
    { 
		/********************************************************************/
			const string& initiator = table->getScopeInitiator();
			const string& retType = table->getScopeRetType();
			if (initiator == "while"){
				table->addScope("while",retType);
			}
			else {
				table->addScope(initiator,retType);
			}
		/********************************************************************/
		}
#line 1742 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 403 "parser.ypp" /* yacc.c:1646  */
    { }
#line 1748 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 403 "parser.ypp" /* yacc.c:1646  */
    {
		/********************************************************************/
			table->printScope();
			table->printStructs();
			table->removeScope();
		}
#line 1759 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 414 "parser.ypp" /* yacc.c:1646  */
    { }
#line 1765 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 420 "parser.ypp" /* yacc.c:1646  */
    { }
#line 1771 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 426 "parser.ypp" /* yacc.c:1646  */
    {
			const string& leftType = ((yyvsp[-3].var))->getType();
			const string& leftName = ((yyvsp[-3].var))->getName();
			const string& rightType = ((yyvsp[-1].var))->getType();
			const string& rightName = ((yyvsp[-1].var))->getName();
			if ((leftType != rightType)&&
				(leftType != "int" || rightType != "byte")){
				// Mismatch of assing operation
				errorMismatch(yylineno);
				exit(0);
			}
			if (rightName == "__temp"){
				delete ((yyvsp[-1].var));
			}
		}
#line 1791 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 446 "parser.ypp" /* yacc.c:1646  */
    { 
		/********************************************************************/
		try {
				table->findVar(*((yyvsp[-1].str)));
			}
			catch (VariableNotFoundException e){
				// Using undefined variable
				errorUndef(yylineno,*((yyvsp[-1].str)));
				exit(0);
			}
		/********************************************************************/
		}
#line 1808 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 457 "parser.ypp" /* yacc.c:1646  */
    { 
		/********************************************************************/
			const string& rightType = ((yyvsp[-1].var))->getType();
			const string& rightName = ((yyvsp[-1].var))->getName();
			const string& leftType = (
				table->findVar(*((yyvsp[-4].str)))).getType();
			const string& leftName = (
				table->findVar(*((yyvsp[-4].str)))).getName();
			if ((leftType != rightType)&&
				(leftType != "int" || rightType != "byte")){
				// Mismatch of assing operation
				errorMismatch(yylineno);
				exit(0);
			}
			if (rightName == "__temp"){
				delete ((yyvsp[-1].var));
			}
		}
#line 1831 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 480 "parser.ypp" /* yacc.c:1646  */
    { 
		/********************************************************************/
			try{
				const string& structName =
					table->findVar(*((yyvsp[-1].str))).getType();
				table->findStruct(structName);
			}
			catch (VariableNotFoundException e){
				// Using undefined struct
				errorUndef(yylineno,*((yyvsp[-1].str)));
				exit(0);
			}
			catch (StructNotFoundException e){
				// Using undefined struct
				errorUndef(yylineno,*((yyvsp[-1].str)));
				exit(0);
			}
		/********************************************************************/
		}
#line 1855 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 498 "parser.ypp" /* yacc.c:1646  */
    { 
		/********************************************************************/
			try{
				const string& structName =
					table->findVar(*((yyvsp[-3].str))).getType();
				table->findStruct(structName).find(*((yyvsp[0].str)));
			}
			catch (VariableNotFoundException e){
				// Using undefined struct member
				errorUndefStructMember(yylineno,*((yyvsp[-3].str)));
				exit(0);
			}
		/********************************************************************/
		}
#line 1874 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 511 "parser.ypp" /* yacc.c:1646  */
    {
		/********************************************************************/
			const string& rightType = ((yyvsp[-1].var))->getType();
			const string& rightName = ((yyvsp[-1].var))->getName();
			const string& structName =
					table->findVar(*((yyvsp[-7].str))).getType();
			const string& leftType = 
				table->findStruct(structName).find(*((yyvsp[-4].str))).getType();
			if ((leftType != rightType)&&
				(leftType != "int" || rightType != "byte")){
				// Mismatch of assing operation
				errorMismatch(yylineno);
				exit(0);
			}
			if (rightName == "__temp"){
				delete ((yyvsp[-1].var));
			}
		}
#line 1897 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 534 "parser.ypp" /* yacc.c:1646  */
    {
			delete ((yyvsp[-1].var));	
		}
#line 1905 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 542 "parser.ypp" /* yacc.c:1646  */
    {
			const string& leftType = table->getScopeRetType();
			if (leftType != "void"){
				// Mismatch of return type (non-void)
				errorMismatch(yylineno);
				exit(0);
			}
		}
#line 1918 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 555 "parser.ypp" /* yacc.c:1646  */
    {
			const string& leftType = table->getScopeRetType();
			const string& rightType = ((yyvsp[-1].var))->getType();
			const string& rightName = ((yyvsp[-1].var))->getName();
			if ((leftType != rightType)&&
				(leftType != "int" || rightType != "byte")){
				// Mismatch of return type
				errorMismatch(yylineno);
				exit(0);
			}
			if (rightName == "__temp"){
				delete ((yyvsp[-1].var));
			}
		}
#line 1937 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 574 "parser.ypp" /* yacc.c:1646  */
    { }
#line 1943 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 580 "parser.ypp" /* yacc.c:1646  */
    {
			if (table->getScopeInitiator() != "while") {
				table->addScope("else", table->getScopeRetType());
			}
			else {
				table->addScope("while", table->getScopeRetType());
			}
		/********************************************************************/
		}
#line 1957 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 588 "parser.ypp" /* yacc.c:1646  */
    {
		/********************************************************************/
			table->printScope();
			table->printStructs();
			table->removeScope();
		}
#line 1968 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 599 "parser.ypp" /* yacc.c:1646  */
    { 
		/********************************************************************/
			if (((yyvsp[0].var))->getType() != "bool"){
				// Mismatch of while condition type
				errorMismatch(yylineno);
				exit(0);
			}
		/********************************************************************/
		}
#line 1982 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 607 "parser.ypp" /* yacc.c:1646  */
    {
		/********************************************************************/
			table->addScope("while", table->getScopeRetType());
		/********************************************************************/
		}
#line 1992 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 611 "parser.ypp" /* yacc.c:1646  */
    {
		/********************************************************************/
			table->printScope();
			table->printStructs();
			table->removeScope();
		}
#line 2003 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 622 "parser.ypp" /* yacc.c:1646  */
    {
			if (table->getScopeInitiator() != "while"){
				// Using break statment outside of while loop
				errorUnexpectedBreak(yylineno);
				exit(0);
			}
		}
#line 2015 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 634 "parser.ypp" /* yacc.c:1646  */
    {
			if (table->getScopeInitiator() != "while"){
				// Using continue statment outside of while loop
				errorUnexpectedContinue(yylineno);
				exit(0);
			}
		}
#line 2027 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 646 "parser.ypp" /* yacc.c:1646  */
    { 
		/********************************************************************/
			if (((yyvsp[0].var))->getType() != "bool"){
				// Mismatch of if condition type
				errorMismatch(yylineno);
				exit(0);
			}
		/********************************************************************/
		}
#line 2041 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 654 "parser.ypp" /* yacc.c:1646  */
    {
		/********************************************************************/
			if (table->getScopeInitiator() != "while") {
				table->addScope("if", table->getScopeRetType());
			}
			else {
				table->addScope("while", table->getScopeRetType());
			}
		/********************************************************************/
		}
#line 2056 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 663 "parser.ypp" /* yacc.c:1646  */
    {
		/********************************************************************/
			table->printScope();
			table->printStructs();
			table->removeScope();
		}
#line 2067 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 674 "parser.ypp" /* yacc.c:1646  */
    { 
		/********************************************************************/
			try {
				table->findFunc(*((yyvsp[-1].str)));
			}
			catch (FunctionNotFoundException e) {
					// Calling undefined function
					errorUndefFunc(yylineno,*((yyvsp[-1].str)));
					exit(0);
				}
		/********************************************************************/
		}
#line 2084 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 685 "parser.ypp" /* yacc.c:1646  */
    {
		/********************************************************************/
			FuncNode const *func = &(table->findFunc(*((yyvsp[-4].str))));
			if ((yyvsp[-1].funcParams)){
				const vector<string>& givenParamTypes =
					((yyvsp[-1].funcParams))->getParamsTypes();
				const vector<string>& paramTypes = func->getParamsTypes();	
				if (((yyvsp[-1].funcParams))->size() != func->size()){
					// Calling function with wrong signature
					errorPrototypeMismatch(
						yylineno,*((yyvsp[-4].str)),
						printTypeNames(paramTypes));
					exit(0);
				}
				for (int i=0; i<func->size(); i++){
					if ((paramTypes[i] != givenParamTypes[i]) &&
						(paramTypes[i] != "int" || givenParamTypes[i] != "byte")){
						// Calling function with wrong signature
						errorPrototypeMismatch(
							yylineno,
							*((yyvsp[-4].str)),
							printTypeNames(paramTypes));
						exit(0);
					}
				}
				delete ((yyvsp[-1].funcParams));
			}
			else {
				if (func->size() != 0){
					// Calling function with wrong signature
					errorPrototypeMismatch(
						yylineno,
						*((yyvsp[-4].str)),
						printTypeNames(func->getParamsTypes()));
					exit(0);
				}
			}
			(yyval.var) = new Var("__temp",func->getRetType());
		}
#line 2128 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 729 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.funcParams) = (yyvsp[0].funcParams);
		}
#line 2136 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 737 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.funcParams) = NULL;
		}
#line 2144 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 745 "parser.ypp" /* yacc.c:1646  */
    {
			FuncParams* parameters = new FuncParams();
			parameters->addParam(*((yyvsp[0].var)));
			(yyval.funcParams) = parameters;
			if (((yyvsp[0].var))->getName() == "__temp"){
				delete ((yyvsp[0].var));
			}
		}
#line 2157 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 758 "parser.ypp" /* yacc.c:1646  */
    {
			((yyvsp[-2].funcParams))->addParam(*((yyvsp[0].var)));
			(yyval.funcParams) = (yyvsp[-2].funcParams);
			if (((yyvsp[0].var))->getName() == "__temp"){
				delete ((yyvsp[0].var));
			}
		}
#line 2169 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 770 "parser.ypp" /* yacc.c:1646  */
    {
			try {
				table->addVar(*((yyvsp[0].str)),*((yyvsp[-1].str)));
				(yyval.var) = const_cast<Var*>(&(table->findVar(*((yyvsp[0].str)))));
			}
			catch (NameAlreadyExistsException e){
				// Redeclaration of variable
				errorDef(yylineno,*((yyvsp[0].str)));
				exit(0);
			}
		}
#line 2185 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 786 "parser.ypp" /* yacc.c:1646  */
    {
			try {
				table->addVar(*((yyvsp[0].str)),*((yyvsp[-1].str)));
				(yyval.var) = const_cast<Var*>(&(table->findVar(*((yyvsp[0].str)))));
			}
			catch (InvalidTypeNameException e){
				// Redeclaration of variable
				errorUndefStruct(yylineno,*((yyvsp[-1].str)));
				exit(0);
			}
			catch (NameAlreadyExistsException e){
				// Redeclaration of variable
				errorDef(yylineno,*((yyvsp[0].str)));
				exit(0);
			}
		}
#line 2206 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 807 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.str) = (yyvsp[0].str);
		}
#line 2214 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 815 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.str) = (yyvsp[0].str);
		}
#line 2222 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 823 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.str) = (yyvsp[0].str);
		}
#line 2230 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 831 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.str) = (yyvsp[0].str);
		}
#line 2238 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 839 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.var) = (yyvsp[-1].var);
		}
#line 2246 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 847 "parser.ypp" /* yacc.c:1646  */
    { 
			if ((((yyvsp[-2].var))->getType() != "int") && 
				(((yyvsp[-2].var))->getType() != "byte")){
				// Mismatch of type for operation
				errorMismatch(yylineno);
				exit(0);	
			}
			if ((((yyvsp[0].var))->getType() != "int") && 
				(((yyvsp[0].var))->getType() != "byte")){
				// Mismatch of type for operation
				errorMismatch(yylineno);
				exit(0);	
			}
			if ((((yyvsp[-2].var))->getType() == "int") || 
				(((yyvsp[0].var))->getType() == "int")){
				(yyval.var) = new Var("__temp","int");
			}
			else {
				(yyval.var) = new Var("__temp","byte");
			}
			(yyval.var)->allocReg(regPool->allocateReg());
			regPool->freeReg((yyvsp[-2].var)->getReg());
			regPool->freeReg((yyvsp[0].var)->getReg());
			// TODO: emit code
			(yyvsp[-2].var)->freeReg();
			(yyvsp[0].var)->freeReg();
			if (((yyvsp[-2].var))->getName() == "__temp"){
				delete ((yyvsp[-2].var));
			}
			if (((yyvsp[0].var))->getName() == "__temp"){
				delete ((yyvsp[0].var));
			}
		}
#line 2284 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 885 "parser.ypp" /* yacc.c:1646  */
    {
			if ((((yyvsp[-2].var))->getType() != "int") && 
				(((yyvsp[-2].var))->getType() != "byte")){
				// Mismatch of type for operation
				errorMismatch(yylineno);
				exit(0);	
			}
			if ((((yyvsp[0].var))->getType() != "int") && 
				(((yyvsp[0].var))->getType() != "byte")){
				// Mismatch of type for operation
				errorMismatch(yylineno);
				exit(0);	
			}
			if ((((yyvsp[-2].var))->getType() == "int") || 
				(((yyvsp[0].var))->getType() == "int")){
				(yyval.var) = new Var("__temp","int");
			}
			else {
				(yyval.var) = new Var("__temp","byte");
			}
			(yyval.var)->allocReg(regPool->allocateReg());
			regPool->freeReg((yyvsp[-2].var)->getReg());
			regPool->freeReg((yyvsp[0].var)->getReg());
			// TODO: emit code
			(yyvsp[-2].var)->freeReg();
			(yyvsp[0].var)->freeReg();
			if (((yyvsp[-2].var))->getName() == "__temp"){
				delete ((yyvsp[-2].var));
			}
			if (((yyvsp[0].var))->getName() == "__temp"){
				delete ((yyvsp[0].var));
			}
		}
#line 2322 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 923 "parser.ypp" /* yacc.c:1646  */
    {
			try {
				(yyval.var) = const_cast<Var*>(&(table->findVar(*((yyvsp[0].str)))));
			}
			catch (VariableNotFoundException e){
				// Using undefined variable
				errorUndef(yylineno,*((yyvsp[0].str)));
				exit(0);
			}
			(yyval.var)->allocReg(regPool->allocateReg());
			// TODO: emit code
		}
#line 2339 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 940 "parser.ypp" /* yacc.c:1646  */
    { 
		/********************************************************************/
			try{
				const string& structName =
					table->findVar(*((yyvsp[0].str))).getType();
				table->findStruct(structName);
			}
			catch (VariableNotFoundException e){
				// Using undefined struct
				errorUndef(yylineno,*((yyvsp[0].str)));
				exit(0);
			}
			catch (StructNotFoundException e){
				// Using undefined struct
				errorUndef(yylineno,*((yyvsp[0].str)));
				exit(0);
			}
		/********************************************************************/
		}
#line 2363 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 958 "parser.ypp" /* yacc.c:1646  */
    {
		/********************************************************************/
			const StructNode* strct;
			try{
				const string& structName =
					table->findVar(*((yyvsp[-3].str))).getType();
				strct = &(table->findStruct(structName));
				(yyval.var) = new Var("__temp",strct->find(*((yyvsp[0].str))).getType());
			}
			catch (VariableNotFoundException e){
				// Using undefined struct member
				errorUndefStructMember(yylineno,*((yyvsp[-3].str)));
				exit(0);
			}
			(yyval.var)->allocReg(regPool->allocateReg());
			// TODO: emit code
		}
#line 2385 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 980 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.var) = (yyvsp[0].var);
			(yyval.var)->allocReg(regPool->allocateReg());
			// TODO: emit code
			// result = Call
		}
#line 2396 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 991 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.var) = new Var("__temp","int");
			(yyval.var)->allocReg(regPool->allocateReg());
			// TODO: emit code
			// result = NUM
		}
#line 2407 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 1002 "parser.ypp" /* yacc.c:1646  */
    {
			if ((yyvsp[-1].num) > 255){
				std::stringstream ss;
				ss << (yyvsp[-1].num);
				// Invalid value for byte
				errorByteTooLarge(yylineno,ss.str());
				exit(0);
			}
			(yyval.var) = new Var("__temp","byte");
			(yyval.var)->allocReg(regPool->allocateReg());
			// TODO: emit code
			// result = NUM
		}
#line 2425 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 1020 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.var) = new Var("__temp","string");
			// TODO: emit code
		}
#line 2434 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 1029 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.var) = new Var("__temp","bool");
			(yyval.var)->allocReg(regPool->allocateReg());
			// TODO: emit code
			// result = 1
		}
#line 2445 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 1040 "parser.ypp" /* yacc.c:1646  */
    {
			(yyval.var) = new Var("__temp","bool");
			(yyval.var)->allocReg(regPool->allocateReg());
			// TODO: emit code
			// result = 0
		}
#line 2456 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 1051 "parser.ypp" /* yacc.c:1646  */
    {
			const string& leftType = ((yyvsp[0].var))->getType();
			const string& leftName = ((yyvsp[0].var))->getName();
			if (leftType != "bool"){
				// Mismatch of type for operation
				errorMismatch(yylineno);
				exit(0);
			}
			(yyval.var) = new Var("__temp","bool");
			(yyval.var)->allocReg(regPool->allocateReg());
			regPool->freeReg((yyvsp[0].var)->getReg());
			// TODO: emit code
			// result = 1 - left
			(yyvsp[0].var)->freeReg();
			if (leftName == "__temp"){
				delete ((yyvsp[0].var));
			}
		}
#line 2479 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 1074 "parser.ypp" /* yacc.c:1646  */
    { 
			if (((yyvsp[-2].var))->getType() != "bool"){
				// Mismatch of type for operation
				errorMismatch(yylineno);
				exit(0);
			}
			if (((yyvsp[0].var))->getType() != "bool"){
				// Mismatch of type for operation
				errorMismatch(yylineno);
				exit(0);
			}
			(yyval.var) = new Var("__temp","bool");	
			(yyval.var)->allocReg(regPool->allocateReg());
			regPool->freeReg((yyvsp[-2].var)->getReg());
			regPool->freeReg((yyvsp[0].var)->getReg());
			// TODO: emit code
			// result = left AND right
			(yyvsp[-2].var)->freeReg();
			(yyvsp[0].var)->freeReg();
			if (((yyvsp[-2].var))->getName() == "__temp"){
				delete ((yyvsp[-2].var));
			}
			if (((yyvsp[0].var))->getName() == "__temp"){
				delete ((yyvsp[0].var));
			}
		}
#line 2510 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 1105 "parser.ypp" /* yacc.c:1646  */
    {
			if (((yyvsp[-2].var))->getType() != "bool"){
				// Mismatch of type for operation
				errorMismatch(yylineno);
				exit(0);
			}
			if (((yyvsp[0].var))->getType() != "bool"){
				// Mismatch of type for operation
				errorMismatch(yylineno);
				exit(0);
			}
			(yyval.var) = new Var("__temp","bool");	
			(yyval.var)->allocReg(regPool->allocateReg());
			regPool->freeReg((yyvsp[-2].var)->getReg());
			regPool->freeReg((yyvsp[0].var)->getReg());
			// TODO: emit code
			// result = left OR right
			(yyvsp[-2].var)->freeReg();
			(yyvsp[0].var)->freeReg();
			if (((yyvsp[-2].var))->getName() == "__temp"){
				delete ((yyvsp[-2].var));
			}
			if (((yyvsp[0].var))->getName() == "__temp"){
				delete ((yyvsp[0].var));
			}
		}
#line 2541 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 1136 "parser.ypp" /* yacc.c:1646  */
    {
			if ((((yyvsp[-2].var))->getType() != "int")&&
				(((yyvsp[-2].var))->getType() != "byte")){
				// Mismatch of type for operation
				errorMismatch(yylineno);
				exit(0);
			}
			if ((((yyvsp[0].var))->getType() != "int")&&
				(((yyvsp[0].var))->getType() != "byte")){
				// Mismatch of type for operation
				errorMismatch(yylineno);
				exit(0);
			}
			(yyval.var) = new Var("__temp","bool");
			(yyval.var)->allocReg(regPool->allocateReg());
			regPool->freeReg((yyvsp[-2].var)->getReg());
			regPool->freeReg((yyvsp[0].var)->getReg());
			// TODO: emit code
			// if left REL right
			//		result = 1
			// else
			// 		result = 0
			(yyvsp[-2].var)->freeReg();
			(yyvsp[0].var)->freeReg();
			if (((yyvsp[-2].var))->getName() == "__temp"){
				delete ((yyvsp[-2].var));
			}
			if (((yyvsp[0].var))->getName() == "__temp"){
				delete ((yyvsp[0].var));
			}
		}
#line 2577 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 1172 "parser.ypp" /* yacc.c:1646  */
    {
			if ((((yyvsp[-2].var))->getType() != "int")&&
				(((yyvsp[-2].var))->getType() != "byte")){
				// Mismatch of type for operation
				errorMismatch(yylineno);
				exit(0);
			}
			if ((((yyvsp[0].var))->getType() != "int")&&
				(((yyvsp[0].var))->getType() != "byte")){
				// Mismatch of type for operation
				errorMismatch(yylineno);
				exit(0);
			}
			(yyval.var) = new Var("__temp","bool");
			(yyval.var)->allocReg(regPool->allocateReg());
			regPool->freeReg((yyvsp[-2].var)->getReg());
			regPool->freeReg((yyvsp[0].var)->getReg());
			// TODO: emit code
			// result = left AND right
			(yyvsp[-2].var)->freeReg();
			(yyvsp[0].var)->freeReg();
			if (((yyvsp[-2].var))->getName() == "__temp") {
				delete ((yyvsp[-2].var));
			}
			if (((yyvsp[0].var))->getName() == "__temp") {
				delete ((yyvsp[0].var));
			}
		}
#line 2610 "parser.tab.cpp" /* yacc.c:1646  */
    break;


#line 2614 "parser.tab.cpp" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 1203 "parser.ypp" /* yacc.c:1906  */


int main() {
	yyparse();
	return 0;
}

void yyerror(char const* s){
	errorSyn(yylineno);
	exit(0);
}


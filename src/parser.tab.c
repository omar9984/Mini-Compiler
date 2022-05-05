/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

	#include <stdio.h>
	int yylex(void);
	void yyerror(char*);
	int sym[26];
	#define debug 1
	int i = 0;
	#include <stdlib.h>
	extern FILE* yyin;

#line 13 "parser.y"

/*
TODO Later
union {
    int		IValue;
	double DValue;
    char* sValue;
*/

#line 92 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_EQUAL = 3,                      /* EQUAL  */
  YYSYMBOL_LOGIC_OR = 4,                   /* LOGIC_OR  */
  YYSYMBOL_LOGIC_AND = 5,                  /* LOGIC_AND  */
  YYSYMBOL_LOGIC_EQ = 6,                   /* LOGIC_EQ  */
  YYSYMBOL_LOGIC_NEQ = 7,                  /* LOGIC_NEQ  */
  YYSYMBOL_LOGIC_LT = 8,                   /* LOGIC_LT  */
  YYSYMBOL_LOGIC_LEQ = 9,                  /* LOGIC_LEQ  */
  YYSYMBOL_LOGIC_GT = 10,                  /* LOGIC_GT  */
  YYSYMBOL_LOGIC_GEQ = 11,                 /* LOGIC_GEQ  */
  YYSYMBOL_PLUS = 12,                      /* PLUS  */
  YYSYMBOL_MINUS = 13,                     /* MINUS  */
  YYSYMBOL_MULT = 14,                      /* MULT  */
  YYSYMBOL_DIV = 15,                       /* DIV  */
  YYSYMBOL_VAR = 16,                       /* VAR  */
  YYSYMBOL_ENDL = 17,                      /* ENDL  */
  YYSYMBOL_IF = 18,                        /* IF  */
  YYSYMBOL_ELIF = 19,                      /* ELIF  */
  YYSYMBOL_ELSE = 20,                      /* ELSE  */
  YYSYMBOL_FOR = 21,                       /* FOR  */
  YYSYMBOL_WHILE = 22,                     /* WHILE  */
  YYSYMBOL_REPEAT = 23,                    /* REPEAT  */
  YYSYMBOL_UNTIL = 24,                     /* UNTIL  */
  YYSYMBOL_SWITCH = 25,                    /* SWITCH  */
  YYSYMBOL_CASE = 26,                      /* CASE  */
  YYSYMBOL_BREAK = 27,                     /* BREAK  */
  YYSYMBOL_DEFAULT = 28,                   /* DEFAULT  */
  YYSYMBOL_TYPE_INT = 29,                  /* TYPE_INT  */
  YYSYMBOL_TYPE_CHAR = 30,                 /* TYPE_CHAR  */
  YYSYMBOL_TYPE_CONST = 31,                /* TYPE_CONST  */
  YYSYMBOL_TYPE_BOOL = 32,                 /* TYPE_BOOL  */
  YYSYMBOL_TYPE_DOUBLE = 33,               /* TYPE_DOUBLE  */
  YYSYMBOL_INT_VALUE = 34,                 /* INT_VALUE  */
  YYSYMBOL_DOUBLE_VALUE = 35,              /* DOUBLE_VALUE  */
  YYSYMBOL_FALSE_VALUE = 36,               /* FALSE_VALUE  */
  YYSYMBOL_TRUE_VALUE = 37,                /* TRUE_VALUE  */
  YYSYMBOL_38_ = 38,                       /* '='  */
  YYSYMBOL_39_ = 39,                       /* '('  */
  YYSYMBOL_40_ = 40,                       /* ')'  */
  YYSYMBOL_41_ = 41,                       /* '{'  */
  YYSYMBOL_42_ = 42,                       /* '}'  */
  YYSYMBOL_43_ = 43,                       /* ':'  */
  YYSYMBOL_YYACCEPT = 44,                  /* $accept  */
  YYSYMBOL_program = 45,                   /* program  */
  YYSYMBOL_block_code = 46,                /* block_code  */
  YYSYMBOL_statement = 47,                 /* statement  */
  YYSYMBOL_for_inital = 48,                /* for_inital  */
  YYSYMBOL_for_condition = 49,             /* for_condition  */
  YYSYMBOL_for_inc = 50,                   /* for_inc  */
  YYSYMBOL_switch_block = 51,              /* switch_block  */
  YYSYMBOL_case_statement = 52,            /* case_statement  */
  YYSYMBOL_case_block = 53,                /* case_block  */
  YYSYMBOL_else_block = 54,                /* else_block  */
  YYSYMBOL_if_block = 55,                  /* if_block  */
  YYSYMBOL_elif_block = 56,                /* elif_block  */
  YYSYMBOL_block_statements = 57,          /* block_statements  */
  YYSYMBOL_expr = 58,                      /* expr  */
  YYSYMBOL_logic_expr = 59,                /* logic_expr  */
  YYSYMBOL_const_val = 60,                 /* const_val  */
  YYSYMBOL_typing = 61,                    /* typing  */
  YYSYMBOL_Constant_type = 62              /* Constant_type  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   393

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  64
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  134

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   292


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      39,    40,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    43,     2,
       2,    38,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    41,     2,    42,     2,     2,     2,     2,
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
      35,    36,    37
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    43,    43,    44,    47,    50,    51,    52,    53,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      72,    73,    76,    77,    80,    81,    85,    86,    87,    88,
      92,    93,    94,    98,   103,   107,   108,   111,   113,   114,
     119,   120,   121,   122,   123,   124,   125,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   140,   141,   142,   143,
     147,   148,   149,   150,   154
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "EQUAL", "LOGIC_OR",
  "LOGIC_AND", "LOGIC_EQ", "LOGIC_NEQ", "LOGIC_LT", "LOGIC_LEQ",
  "LOGIC_GT", "LOGIC_GEQ", "PLUS", "MINUS", "MULT", "DIV", "VAR", "ENDL",
  "IF", "ELIF", "ELSE", "FOR", "WHILE", "REPEAT", "UNTIL", "SWITCH",
  "CASE", "BREAK", "DEFAULT", "TYPE_INT", "TYPE_CHAR", "TYPE_CONST",
  "TYPE_BOOL", "TYPE_DOUBLE", "INT_VALUE", "DOUBLE_VALUE", "FALSE_VALUE",
  "TRUE_VALUE", "'='", "'('", "')'", "'{'", "'}'", "':'", "$accept",
  "program", "block_code", "statement", "for_inital", "for_condition",
  "for_inc", "switch_block", "case_statement", "case_block", "else_block",
  "if_block", "elif_block", "block_statements", "expr", "logic_expr",
  "const_val", "typing", "Constant_type", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-83)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-23)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -83,    55,   -83,     3,   -31,   -26,   -24,   -25,   -21,   -83,
     -83,   -83,   -83,   -83,   -83,   -83,   -83,   -83,    63,   205,
     -83,   -83,   336,   -83,   -83,     4,    13,    63,    63,    63,
       5,    63,   232,    -2,    63,   -83,   118,   -83,   -83,   254,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,   -83,    18,    20,   350,   364,   130,    34,    23,
     142,   -83,   276,    19,   179,   -83,   -83,   -83,    35,    35,
      35,    35,    35,    35,    35,    35,   -83,   -83,   -83,   -83,
     -83,    39,   -83,   -83,   -25,    63,    63,   -25,   -83,    63,
      16,   -83,   -16,   378,    42,   378,    43,   -83,   191,   -19,
      24,   -25,   -83,    44,    46,   -83,    17,    22,    25,   -19,
      63,   -83,   -83,    67,    26,    31,   298,   -83,   -83,   203,
      63,   -25,   298,    58,    54,   -83,   -25,   378,   -83,   -83,
     -83,    65,   -83,   -83
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     1,    41,     0,     0,     0,     0,     0,    60,
      63,    64,    62,    61,    59,    58,    56,    57,     0,     0,
       2,     4,     0,    46,    40,     0,     0,     0,     0,     0,
      21,     0,     0,     0,     0,    41,     0,    19,    38,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     5,     0,     0,     0,     0,     0,     0,     0,
       0,    36,     0,     0,     0,    55,    18,    39,    49,    50,
      47,    48,    51,    52,    53,    54,    42,    43,    44,    45,
       7,     0,     9,     6,     0,     0,    23,     0,    35,     0,
       0,     8,    10,    20,     0,     0,    46,    14,     0,    29,
       0,     0,    11,    13,    25,    15,     0,     0,     0,    29,
       0,    34,    12,     0,     0,     0,    28,    17,    26,     0,
       0,     0,     0,     0,    30,    27,     0,    24,    16,    33,
      32,     0,    37,    31
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -83,   -83,   -83,    -1,   -83,   -83,   -83,   -14,   -39,   -83,
       1,   -82,   -83,    69,   -17,    21,     0,    79,   -83
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,    20,    38,    59,    94,   114,   108,   125,   109,
     102,    33,   103,    39,    22,    23,    24,    25,    26
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      21,    36,    92,   100,   101,    97,    27,   106,    29,   107,
      55,    56,    57,    30,    60,    31,    32,    64,    34,   111,
      53,    58,    63,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    85,    67,   128,
      86,    28,     9,    10,   132,    12,    13,    48,    49,    50,
      51,    14,    15,    16,    17,     2,    91,    99,    89,   104,
     -22,    67,   113,   110,   101,   116,   121,   117,    93,    95,
     120,     3,    98,     4,   122,   130,     5,     6,     7,    35,
       8,   131,   133,   129,     9,    10,    11,    12,    13,    14,
      15,    16,    17,   119,    18,   118,    19,    14,    15,    16,
      17,    62,    18,   127,   112,    54,   115,    96,     0,     0,
       0,     0,     0,     0,     0,   124,     0,     0,     0,     0,
       0,   124,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    65,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      84,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    87,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    90,
       0,     3,     0,     4,     0,     0,     5,     6,     7,     0,
       8,   105,     0,     0,     9,    10,    11,    12,    13,    14,
      15,    16,    17,   126,    18,     0,    19,    37,     3,     0,
       4,     0,     0,     5,     6,     7,     0,     8,     0,     0,
       0,     9,    10,    11,    12,    13,    14,    15,    16,    17,
       3,    18,     4,    19,    61,     5,     6,     7,     0,     8,
       0,     0,     0,     9,    10,    11,    12,    13,    14,    15,
      16,    17,     3,    18,     4,    19,    66,     5,     6,     7,
       0,     8,     0,     0,     0,     9,    10,    11,    12,    13,
      14,    15,    16,    17,     3,    18,     4,    19,    88,     5,
       6,     7,     0,     8,     0,   123,     0,     9,    10,    11,
      12,    13,    14,    15,    16,    17,     0,    18,     0,    19,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,     0,    52,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,     0,    82,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
       0,    83,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51
};

static const yytype_int8 yycheck[] =
{
       1,    18,    84,    19,    20,    87,     3,    26,    39,    28,
      27,    28,    29,    39,    31,    39,    41,    34,    39,   101,
      16,    16,    24,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    17,    16,     3,    39,   121,
      17,    38,    29,    30,   126,    32,    33,    12,    13,    14,
      15,    34,    35,    36,    37,     0,    17,    41,    39,    17,
      17,    62,    16,    39,    20,    43,    40,    42,    85,    86,
       3,    16,    89,    18,    43,    17,    21,    22,    23,    16,
      25,    27,    17,   122,    29,    30,    31,    32,    33,    34,
      35,    36,    37,   110,    39,   109,    41,    34,    35,    36,
      37,    32,    39,   120,   103,    26,   106,    86,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   116,    -1,    -1,    -1,    -1,
      -1,   122,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    40,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    40,
      -1,    16,    -1,    18,    -1,    -1,    21,    22,    23,    -1,
      25,    40,    -1,    -1,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    40,    39,    -1,    41,    42,    16,    -1,
      18,    -1,    -1,    21,    22,    23,    -1,    25,    -1,    -1,
      -1,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      16,    39,    18,    41,    42,    21,    22,    23,    -1,    25,
      -1,    -1,    -1,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    16,    39,    18,    41,    42,    21,    22,    23,
      -1,    25,    -1,    -1,    -1,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    16,    39,    18,    41,    42,    21,
      22,    23,    -1,    25,    -1,    27,    -1,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    -1,    39,    -1,    41,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    -1,    17,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    -1,    17,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      -1,    17,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    45,     0,    16,    18,    21,    22,    23,    25,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    39,    41,
      46,    47,    58,    59,    60,    61,    62,     3,    38,    39,
      39,    39,    41,    55,    39,    16,    58,    42,    47,    57,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    17,    16,    61,    58,    58,    58,    16,    48,
      58,    42,    57,    24,    58,    40,    42,    47,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      17,    16,    17,    17,    40,     3,    17,    40,    42,    39,
      40,    17,    55,    58,    49,    58,    59,    55,    58,    41,
      19,    20,    54,    56,    17,    40,    26,    28,    51,    53,
      39,    55,    54,    16,    50,    60,    43,    42,    51,    58,
       3,    40,    43,    27,    47,    52,    40,    58,    55,    52,
      17,    27,    55,    17
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    44,    45,    45,    46,    47,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    47,
      48,    48,    49,    49,    50,    50,    51,    51,    51,    51,
      52,    52,    52,    53,    54,    55,    55,    56,    57,    57,
      58,    58,    58,    58,    58,    58,    58,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    60,    60,    60,    60,
      61,    61,    61,    61,    62
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     1,     2,     4,     3,     4,     4,
       5,     6,     7,     6,     5,     6,     9,     7,     3,     2,
       3,     0,     1,     0,     3,     0,     2,     3,     2,     0,
       1,     3,     2,     4,     2,     3,     2,     5,     1,     2,
       1,     1,     3,     3,     3,     3,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 2: /* program: program block_code  */
#line 43 "parser.y"
                           {printf("matched okay\n");}
#line 1277 "parser.tab.c"
    break;

  case 6: /* statement: VAR '=' expr ENDL  */
#line 51 "parser.y"
                             { if(debug){printf("%d typing VAR=expr \n", i++);} }
#line 1283 "parser.tab.c"
    break;

  case 7: /* statement: typing VAR ENDL  */
#line 52 "parser.y"
                          { if(debug){printf("%d typing VAR \n", i++);}  }
#line 1289 "parser.tab.c"
    break;

  case 8: /* statement: Constant_type typing VAR ENDL  */
#line 53 "parser.y"
                                        { if(debug){printf("%d typing VAR \n", i++);}  }
#line 1295 "parser.tab.c"
    break;

  case 9: /* statement: VAR EQUAL expr ENDL  */
#line 56 "parser.y"
                              {if(debug){printf("%d VAR EQUAL expr  \n", i++);} }
#line 1301 "parser.tab.c"
    break;

  case 10: /* statement: IF '(' expr ')' if_block  */
#line 57 "parser.y"
                                     {if(debug){printf("%d if (expr) do expr  \n", i++);} }
#line 1307 "parser.tab.c"
    break;

  case 11: /* statement: IF '(' expr ')' if_block else_block  */
#line 58 "parser.y"
                                              {if(debug){printf("%d if  (expr) else  do expr  \n", i++);} }
#line 1313 "parser.tab.c"
    break;

  case 12: /* statement: IF '(' expr ')' if_block elif_block else_block  */
#line 59 "parser.y"
                                                          {if (debug){printf("%d IF ELIF ELSE expr  \n", i++);} }
#line 1319 "parser.tab.c"
    break;

  case 13: /* statement: IF '(' expr ')' if_block elif_block  */
#line 60 "parser.y"
                                              {if(debug){printf("%dIF ELIF  expr  \n", i++);} }
#line 1325 "parser.tab.c"
    break;

  case 14: /* statement: WHILE '(' expr ')' if_block  */
#line 61 "parser.y"
                                     {if(debug){printf("%dIF WHILE  expr  \n", i++);} }
#line 1331 "parser.tab.c"
    break;

  case 15: /* statement: REPEAT if_block UNTIL '(' expr ')'  */
#line 62 "parser.y"
                                             {if(debug){printf("%dIF WHILE  expr  \n", i++);} }
#line 1337 "parser.tab.c"
    break;

  case 16: /* statement: FOR '(' for_inital ENDL for_condition ENDL for_inc ')' if_block  */
#line 63 "parser.y"
                                                                            { if(debug){printf("%d for loop  expr  \n", i++);} }
#line 1343 "parser.tab.c"
    break;

  case 17: /* statement: SWITCH '(' expr ')' '{' switch_block '}'  */
#line 64 "parser.y"
                                                   {if(debug){printf("%dswitch  expr  \n", i++);} }
#line 1349 "parser.tab.c"
    break;

  case 18: /* statement: '{' block_statements '}'  */
#line 65 "parser.y"
                                   { if(debug){printf("%d {  } \n", i++);} }
#line 1355 "parser.tab.c"
    break;

  case 26: /* switch_block: case_block switch_block  */
#line 85 "parser.y"
                                        { if(debug){printf("%d {  } \n", i++);} }
#line 1361 "parser.tab.c"
    break;

  case 27: /* switch_block: DEFAULT ':' case_statement  */
#line 86 "parser.y"
                                         { if(debug){printf("%d {  } \n", i++);} }
#line 1367 "parser.tab.c"
    break;

  case 28: /* switch_block: DEFAULT ':'  */
#line 87 "parser.y"
                                 { if(debug){printf("%d {  } \n", i++);} }
#line 1373 "parser.tab.c"
    break;

  case 33: /* case_block: CASE const_val ':' case_statement  */
#line 98 "parser.y"
                                          {  if(debug){printf("%dcase_block statement break;\n", i++);} }
#line 1379 "parser.tab.c"
    break;

  case 38: /* block_statements: statement  */
#line 113 "parser.y"
                  {}
#line 1385 "parser.tab.c"
    break;

  case 39: /* block_statements: block_statements statement  */
#line 114 "parser.y"
                                     {}
#line 1391 "parser.tab.c"
    break;

  case 40: /* expr: const_val  */
#line 119 "parser.y"
                        {if(debug){printf("%d const_val \n", i++);} }
#line 1397 "parser.tab.c"
    break;

  case 41: /* expr: VAR  */
#line 120 "parser.y"
                {if(debug){printf("%d VAR \n", i++);} }
#line 1403 "parser.tab.c"
    break;

  case 42: /* expr: expr PLUS expr  */
#line 121 "parser.y"
                         { if(debug){printf("%d expr + expr  \n", i++);} }
#line 1409 "parser.tab.c"
    break;

  case 43: /* expr: expr MINUS expr  */
#line 122 "parser.y"
                          {if(debug){printf("%d expr - expr \n", i++);}}
#line 1415 "parser.tab.c"
    break;

  case 44: /* expr: expr MULT expr  */
#line 123 "parser.y"
                         { if(debug){printf("%d expr * expr \n", i++);}}
#line 1421 "parser.tab.c"
    break;

  case 45: /* expr: expr DIV expr  */
#line 124 "parser.y"
                        {if(debug){printf("%d  expr / expr  \n", i++);}}
#line 1427 "parser.tab.c"
    break;

  case 47: /* logic_expr: expr LOGIC_EQ expr  */
#line 128 "parser.y"
                           {}
#line 1433 "parser.tab.c"
    break;

  case 48: /* logic_expr: expr LOGIC_NEQ expr  */
#line 129 "parser.y"
                              {}
#line 1439 "parser.tab.c"
    break;

  case 49: /* logic_expr: expr LOGIC_OR expr  */
#line 130 "parser.y"
                             {}
#line 1445 "parser.tab.c"
    break;

  case 50: /* logic_expr: expr LOGIC_AND expr  */
#line 131 "parser.y"
                              {}
#line 1451 "parser.tab.c"
    break;

  case 51: /* logic_expr: expr LOGIC_LT expr  */
#line 132 "parser.y"
                             {}
#line 1457 "parser.tab.c"
    break;

  case 52: /* logic_expr: expr LOGIC_LEQ expr  */
#line 133 "parser.y"
                              {}
#line 1463 "parser.tab.c"
    break;

  case 53: /* logic_expr: expr LOGIC_GT expr  */
#line 134 "parser.y"
                             {}
#line 1469 "parser.tab.c"
    break;

  case 54: /* logic_expr: expr LOGIC_GEQ expr  */
#line 135 "parser.y"
                              {}
#line 1475 "parser.tab.c"
    break;

  case 55: /* logic_expr: '(' expr ')'  */
#line 136 "parser.y"
                       {if(debug){printf("%d (expr) \n", i++);}  }
#line 1481 "parser.tab.c"
    break;

  case 60: /* typing: TYPE_INT  */
#line 147 "parser.y"
                 {if(debug){printf("Type INT recieved\n");}}
#line 1487 "parser.tab.c"
    break;

  case 61: /* typing: TYPE_DOUBLE  */
#line 148 "parser.y"
                      {if(debug){printf("Type DOuble recieved\n");}}
#line 1493 "parser.tab.c"
    break;

  case 62: /* typing: TYPE_BOOL  */
#line 149 "parser.y"
                    {if(debug){printf("Type BOOL recieved\n");}}
#line 1499 "parser.tab.c"
    break;

  case 63: /* typing: TYPE_CHAR  */
#line 150 "parser.y"
                    {if(debug){printf("Type CHAR recieved\n");}}
#line 1505 "parser.tab.c"
    break;

  case 64: /* Constant_type: TYPE_CONST  */
#line 154 "parser.y"
                  {}
#line 1511 "parser.tab.c"
    break;


#line 1515 "parser.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 157 "parser.y"



void yyerror(char*s){
	fprintf(stderr, "%s\n", s);
}


void parse(FILE* fileInput)
    {
        yyin= fileInput;
        while(feof(yyin)==0)
        {
        yyparse();
        }
    }


int main(int argc,char* argv[]){

	 FILE* fileInput;
    char inputBuffer[36];
    char lineData[36];

    if((fileInput=fopen(argv[1],"r"))==NULL)
        {
        printf("Error reading files, the program terminates immediately\n");
        exit(0);
        }
    parse(fileInput);

	// yyparse();
	// printf("end of parser\n");
	return 0;
}

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
#line 1 "./rules/parser.y"

	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	#define debug 0
	int yylex(void);
	void yyerror(char*);
	void semantic_error();
	void semantic_error_with_msg(char *);
	bool symbol_table_contains(char*);
	int symbol_table_get_varType(char*);
	bool is_var_initialized(char*);
	bool is_var_constant(char*);
	void symbol_table_insert(char*,char*,bool,bool,char*);
	void set_var_initialized(char*);
	void set_var_used(char*);
	bool check_type_match(char*,char*,int);
	int check_val_type(char*);
	int convert_name_type(char*);
	char* reverse_type_value(int);
	void initialize_variable(char*,char*);
	void print_symbol_table();
	void quadruple_insert(char* op, char* src1, char* src2, char* dst,bool defer);
	void print_quadruples();
	char* ALU(char,char*,char*);
	void manage_colon();
	void add_label();
	void jump(bool,int);
	void apply_defer();
	void print_warning();


	int i = 0;
	// int scope = 1;
	int label = 1;
	int label_switch_case = 1;
	int t = 1, t_reg = 0;
	int flag_until = 0;
	int flag_case = 0;
	int flag_last_case = 0;
	bool semantic_error_found = false;
	extern int lineno;
	extern FILE *yyin;
	const char* arr_type[5] = {"int","double","bool","char","string"};
	struct symbol_table {
		char name[50];
		int type;
		bool initialized;
		bool constant;
		bool used;
		int line_num;
	};

	struct Quadruple {
		char dst[50], src1[50], src2[50], op[50];
		char description[100];
	};

#line 130 "parser.tab.c"

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
  YYSYMBOL_COLON = 18,                     /* COLON  */
  YYSYMBOL_IF = 19,                        /* IF  */
  YYSYMBOL_ELIF = 20,                      /* ELIF  */
  YYSYMBOL_ELSE = 21,                      /* ELSE  */
  YYSYMBOL_FOR = 22,                       /* FOR  */
  YYSYMBOL_WHILE = 23,                     /* WHILE  */
  YYSYMBOL_REPEAT = 24,                    /* REPEAT  */
  YYSYMBOL_UNTIL = 25,                     /* UNTIL  */
  YYSYMBOL_SWITCH = 26,                    /* SWITCH  */
  YYSYMBOL_CASE = 27,                      /* CASE  */
  YYSYMBOL_DEFAULT = 28,                   /* DEFAULT  */
  YYSYMBOL_END = 29,                       /* END  */
  YYSYMBOL_TYPE_INT = 30,                  /* TYPE_INT  */
  YYSYMBOL_TYPE_CHAR = 31,                 /* TYPE_CHAR  */
  YYSYMBOL_TYPE_CONST = 32,                /* TYPE_CONST  */
  YYSYMBOL_TYPE_BOOL = 33,                 /* TYPE_BOOL  */
  YYSYMBOL_TYPE_DOUBLE = 34,               /* TYPE_DOUBLE  */
  YYSYMBOL_TYPE_STRING = 35,               /* TYPE_STRING  */
  YYSYMBOL_INT_VALUE = 36,                 /* INT_VALUE  */
  YYSYMBOL_DOUBLE_VALUE = 37,              /* DOUBLE_VALUE  */
  YYSYMBOL_FALSE_VALUE = 38,               /* FALSE_VALUE  */
  YYSYMBOL_TRUE_VALUE = 39,                /* TRUE_VALUE  */
  YYSYMBOL_CHAR_VALUE = 40,                /* CHAR_VALUE  */
  YYSYMBOL_STRING_VALUE = 41,              /* STRING_VALUE  */
  YYSYMBOL_42_ = 42,                       /* '('  */
  YYSYMBOL_43_ = 43,                       /* ')'  */
  YYSYMBOL_44_ = 44,                       /* '{'  */
  YYSYMBOL_45_ = 45,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 46,                  /* $accept  */
  YYSYMBOL_program = 47,                   /* program  */
  YYSYMBOL_block_code = 48,                /* block_code  */
  YYSYMBOL_statement = 49,                 /* statement  */
  YYSYMBOL_for_inital = 50,                /* for_inital  */
  YYSYMBOL_for_condition = 51,             /* for_condition  */
  YYSYMBOL_for_inc = 52,                   /* for_inc  */
  YYSYMBOL_switch_block = 53,              /* switch_block  */
  YYSYMBOL_case_statement = 54,            /* case_statement  */
  YYSYMBOL_case_statement_extended = 55,   /* case_statement_extended  */
  YYSYMBOL_case_block = 56,                /* case_block  */
  YYSYMBOL_if_block = 57,                  /* if_block  */
  YYSYMBOL_elif_block = 58,                /* elif_block  */
  YYSYMBOL_elif_block_extended = 59,       /* elif_block_extended  */
  YYSYMBOL_block_statements = 60,          /* block_statements  */
  YYSYMBOL_expr = 61,                      /* expr  */
  YYSYMBOL_logic_expr = 62,                /* logic_expr  */
  YYSYMBOL_const_val = 63,                 /* const_val  */
  YYSYMBOL_typing = 64,                    /* typing  */
  YYSYMBOL_Constant_type = 65,             /* Constant_type  */
  YYSYMBOL_colon = 66,                     /* colon  */
  YYSYMBOL_if_clause = 67,                 /* if_clause  */
  YYSYMBOL_elif_clause = 68,               /* elif_clause  */
  YYSYMBOL_else_clause = 69,               /* else_clause  */
  YYSYMBOL_while_clause = 70,              /* while_clause  */
  YYSYMBOL_repeat_clause = 71,             /* repeat_clause  */
  YYSYMBOL_until_clause = 72,              /* until_clause  */
  YYSYMBOL_for_clause = 73,                /* for_clause  */
  YYSYMBOL_switch_clause = 74,             /* switch_clause  */
  YYSYMBOL_case_clause = 75,               /* case_clause  */
  YYSYMBOL_default_clause = 76             /* default_clause  */
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
#define YYLAST   479

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  78
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  164

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   296


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
      42,    43,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    44,     2,    45,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    86,    86,    87,    90,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     113,   115,   118,   119,   122,   123,   128,   129,   130,   143,
     148,   149,   153,   161,   162,   166,   174,   175,   179,   180,
     185,   186,   187,   188,   189,   190,   191,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   206,   207,   208,   209,
     210,   211,   215,   216,   217,   218,   219,   223,   227,   230,
     233,   236,   239,   242,   245,   248,   251,   254,   257
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
  "COLON", "IF", "ELIF", "ELSE", "FOR", "WHILE", "REPEAT", "UNTIL",
  "SWITCH", "CASE", "DEFAULT", "END", "TYPE_INT", "TYPE_CHAR",
  "TYPE_CONST", "TYPE_BOOL", "TYPE_DOUBLE", "TYPE_STRING", "INT_VALUE",
  "DOUBLE_VALUE", "FALSE_VALUE", "TRUE_VALUE", "CHAR_VALUE",
  "STRING_VALUE", "'('", "')'", "'{'", "'}'", "$accept", "program",
  "block_code", "statement", "for_inital", "for_condition", "for_inc",
  "switch_block", "case_statement", "case_statement_extended",
  "case_block", "if_block", "elif_block", "elif_block_extended",
  "block_statements", "expr", "logic_expr", "const_val", "typing",
  "Constant_type", "colon", "if_clause", "elif_clause", "else_clause",
  "while_clause", "repeat_clause", "until_clause", "for_clause",
  "switch_clause", "case_clause", "default_clause", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-96)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-23)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -96,    71,   -96,     4,   -96,   -96,   -96,   -96,   -96,   -96,
     -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,
     -96,   369,   252,   -96,   -96,   408,   -96,   -96,   -14,    30,
     -34,   -29,   -28,   -23,   -22,   369,   -96,   118,   -96,   -96,
     279,   369,   369,   369,   369,   369,   369,   369,   369,   369,
     369,   369,   369,   -96,     0,    19,   369,   369,   306,    13,
      24,   369,   422,   -96,   -96,   -96,    55,    55,    55,    55,
      55,    55,    55,    55,   -96,   -96,   -96,   -96,   369,   -96,
       1,   139,   158,   -96,   333,   -96,     2,    40,    28,   179,
     -96,   436,   369,   -96,    37,    37,   -96,   369,   369,   369,
      18,   -96,   450,   -96,   -28,   -28,   198,   464,    37,   464,
      38,   -16,   -96,   -15,   -96,    37,    41,   -96,   -96,    29,
     -16,    12,   360,   -96,   -96,   -96,    54,    34,   -28,   -96,
      77,    39,   -96,   -96,    37,   360,   -96,   -28,   369,    52,
     369,   -28,   360,   360,   -96,    56,   219,   -96,   464,   -96,
     -96,   -96,   -96,    37,   -28,    64,   -96,    44,   369,   238,
      37,   -28,    64,   -96
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     1,    41,    69,    75,    72,    73,    76,    62,
      65,    67,    64,    63,    66,    59,    58,    56,    57,    60,
      61,     0,     0,     2,     4,     0,    46,    40,     0,     0,
       0,     0,     0,     0,     0,     0,    41,     0,    19,    38,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     5,     0,     0,     0,     0,     0,     0,
      21,     0,     0,    55,    18,    39,    49,    50,    47,    48,
      51,    52,    53,    54,    42,    43,    44,    45,     0,     6,
       0,     0,     0,    34,     0,    74,     0,     0,     0,     0,
      10,     0,     0,     7,     0,     0,    33,     0,     0,    23,
       0,     9,     0,    68,     0,     0,     0,    20,     0,     0,
      46,     0,     8,     0,    14,     0,    25,    77,    78,     0,
       0,     0,    28,    70,    71,    11,     0,     0,     0,    15,
       0,     0,    17,    26,     0,    31,    27,     0,     0,     0,
       0,     0,     0,    31,    29,     0,     0,    12,    24,    16,
      32,    30,    13,     0,     0,    37,    35,     0,     0,     0,
       0,     0,    37,    36
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -96,   -96,   -96,    -1,   -96,   -96,   -96,   -32,   -53,   -52,
     -96,   -95,   -96,   -66,    42,   -20,    15,    -5,    69,   -96,
     -61,   -96,     6,    -9,   -96,   -96,   -96,   -96,   -96,   -96,
     -96
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,    23,    39,    88,   108,   131,   119,   136,   144,
     120,    59,   126,   156,    40,    25,    26,    27,    28,    29,
     104,    30,   157,   128,    31,    32,    86,    33,    34,   121,
     122
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      24,    37,    54,    78,    92,   123,   124,    35,    56,   113,
     114,   117,   118,    57,   125,    62,    58,    79,    93,    60,
      61,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,   139,   105,    80,    81,    82,    85,    65,
      87,    89,   145,    98,    97,    99,   149,   116,    15,    16,
      17,    18,    19,    20,   129,   103,   -22,   130,    91,   155,
       9,    10,   111,    12,    13,    14,   162,    49,    50,    51,
      52,     2,   102,   142,   132,   124,   138,   106,   107,   109,
     140,   147,   141,    65,   123,   152,   158,     3,   133,   150,
       4,   151,   154,     5,     6,     7,   163,     8,    55,   161,
      84,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,   110,    22,   134,   137,   146,   127,
     148,   135,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,   143,     0,     0,     0,   159,     0,
       0,   135,   143,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,     0,     0,     0,     0,     0,
       0,    63,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,     0,     0,     0,     0,     0,     0,
       0,     0,    94,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,     0,     0,     0,     0,     0,
       0,    95,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,     0,     0,     0,     0,     0,     0,
       0,     0,   100,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,     0,     0,     0,     0,     0,
       0,   115,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,     0,     0,     0,     0,     0,     0,
       0,     0,   153,     0,     0,     0,     0,     0,     3,     0,
       0,     4,     0,     0,     5,     6,     7,     0,     8,     0,
       0,   160,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,     3,    22,    38,     4,     0,
       0,     5,     6,     7,     0,     8,     0,     0,     0,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,     3,    22,    64,     4,     0,     0,     5,     6,
       7,     0,     8,     0,     0,     0,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,     3,
      22,    83,     4,     0,     0,     5,     6,     7,     0,     8,
       0,     0,     0,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,     3,    22,    96,     4,
       0,     0,     5,     6,     7,    36,     8,     0,     0,     0,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,     0,    22,    15,    16,    17,    18,    19,
      20,    21,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,     0,    53,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,     0,    90,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,     0,   101,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,     0,   112,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52
};

static const yytype_int16 yycheck[] =
{
       1,    21,    16,     3,     3,    20,    21,     3,    42,   104,
     105,    27,    28,    42,    29,    35,    44,    17,    17,    42,
      42,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,   128,    95,    16,    56,    57,    25,    40,
      16,    61,   137,     3,    42,    17,   141,   108,    36,    37,
      38,    39,    40,    41,   115,    18,    18,    16,    78,   154,
      30,    31,    44,    33,    34,    35,   161,    12,    13,    14,
      15,     0,    92,   134,    45,    21,    42,    97,    98,    99,
       3,    29,    43,    84,    20,    29,    42,    16,   120,   142,
      19,   143,   153,    22,    23,    24,   162,    26,    29,   160,
      58,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    99,    44,   121,   126,   138,   113,
     140,   122,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,   135,    -1,    -1,    -1,   158,    -1,
      -1,   142,   143,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    43,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    43,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    43,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    -1,    -1,    -1,    -1,    -1,    16,    -1,
      -1,    19,    -1,    -1,    22,    23,    24,    -1,    26,    -1,
      -1,    43,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    16,    44,    45,    19,    -1,
      -1,    22,    23,    24,    -1,    26,    -1,    -1,    -1,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    16,    44,    45,    19,    -1,    -1,    22,    23,
      24,    -1,    26,    -1,    -1,    -1,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    16,
      44,    45,    19,    -1,    -1,    22,    23,    24,    -1,    26,
      -1,    -1,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    16,    44,    45,    19,
      -1,    -1,    22,    23,    24,    16,    26,    -1,    -1,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    -1,    44,    36,    37,    38,    39,    40,
      41,    42,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    -1,    17,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    -1,    17,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    -1,    17,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    -1,    17,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    47,     0,    16,    19,    22,    23,    24,    26,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    44,    48,    49,    61,    62,    63,    64,    65,
      67,    70,    71,    73,    74,     3,    16,    61,    45,    49,
      60,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    17,    16,    64,    42,    42,    44,    57,
      42,    42,    61,    43,    45,    49,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,     3,    17,
      16,    61,    61,    45,    60,    25,    72,    16,    50,    61,
      17,    61,     3,    17,    43,    43,    45,    42,     3,    17,
      43,    17,    61,    18,    66,    66,    61,    61,    51,    61,
      62,    44,    17,    57,    57,    43,    66,    27,    28,    53,
      56,    75,    76,    20,    21,    29,    58,    68,    69,    66,
      16,    52,    45,    53,    63,    49,    54,    69,    42,    57,
       3,    43,    66,    49,    55,    57,    61,    29,    61,    57,
      54,    55,    29,    43,    66,    57,    59,    68,    42,    61,
      43,    66,    57,    59
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    47,    48,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
      50,    50,    51,    51,    52,    52,    53,    53,    53,    54,
      55,    55,    56,    57,    57,    58,    59,    59,    60,    60,
      61,    61,    61,    61,    61,    61,    61,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    63,    63,    63,    63,
      63,    63,    64,    64,    64,    64,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     1,     2,     3,     4,     6,     5,
       4,     7,     9,    10,     6,     7,     9,     7,     3,     2,
       3,     0,     1,     0,     3,     0,     2,     2,     1,     2,
       2,     0,     4,     3,     2,     7,     7,     0,     1,     2,
       1,     1,     3,     3,     3,     3,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1
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
#line 86 "./rules/parser.y"
                           {if(debug)printf("matched okay");}
#line 1365 "parser.tab.c"
    break;

  case 6: /* statement: typing VAR ENDL  */
#line 94 "./rules/parser.y"
                          { if(debug){printf("%d typing VAR \n", i++);print_symbol_table();}symbol_table_insert((yyvsp[-2].token),(yyvsp[-1].token),false,false,"");  }
#line 1371 "parser.tab.c"
    break;

  case 7: /* statement: Constant_type typing VAR ENDL  */
#line 95 "./rules/parser.y"
                                        {if(debug){printf("%d const typing VAR \n", i++);print_symbol_table();} symbol_table_insert((yyvsp[-2].token),(yyvsp[-1].token),true,false,"");}
#line 1377 "parser.tab.c"
    break;

  case 8: /* statement: Constant_type typing VAR EQUAL expr ENDL  */
#line 96 "./rules/parser.y"
                                                   {if(debug){printf("%d const typing VAR '=' const_val \n", i++);print_symbol_table();} symbol_table_insert((yyvsp[-4].token),(yyvsp[-3].token),true,true,(yyvsp[-1].token)); quadruple_insert("=","t#","NULL",(yyvsp[-3].token),false);  }
#line 1383 "parser.tab.c"
    break;

  case 9: /* statement: typing VAR EQUAL expr ENDL  */
#line 97 "./rules/parser.y"
                                     {if(debug){printf("%d typing VAR '=' const_val \n", i++);print_symbol_table();} symbol_table_insert((yyvsp[-4].token),(yyvsp[-3].token),false,true,(yyvsp[-1].token)); quadruple_insert("=","t#","NULL",(yyvsp[-3].token),false); }
#line 1389 "parser.tab.c"
    break;

  case 10: /* statement: VAR EQUAL expr ENDL  */
#line 98 "./rules/parser.y"
                              {if(debug){printf("%d VAR EQUAL expr  \n", i++);print_symbol_table();}initialize_variable((yyvsp[-3].token),(yyvsp[-1].token));quadruple_insert("=","t#","NULL",(yyvsp[-3].token),false); }
#line 1395 "parser.tab.c"
    break;

  case 11: /* statement: if_clause '(' expr ')' colon if_block END  */
#line 99 "./rules/parser.y"
                                                   {if(debug){printf("%d if (expr) do expr  \n", i++);} add_label(); }
#line 1401 "parser.tab.c"
    break;

  case 12: /* statement: if_clause '(' expr ')' colon if_block else_clause if_block END  */
#line 100 "./rules/parser.y"
                                                                       {if(debug){printf("%d if  (expr) else  do expr  \n", i++);} add_label(); }
#line 1407 "parser.tab.c"
    break;

  case 13: /* statement: if_clause '(' expr ')' colon if_block elif_block else_clause if_block END  */
#line 101 "./rules/parser.y"
                                                                                  {if (debug){printf("%d if ELIF ELSE expr  \n", i++);}flag_last_case = 1;add_label();flag_last_case = 0; }
#line 1413 "parser.tab.c"
    break;

  case 14: /* statement: while_clause '(' expr ')' colon if_block  */
#line 102 "./rules/parser.y"
                                                  {if(debug){printf("%d WHILE  expr  \n", i++); }jump(false,-1); add_label(); }
#line 1419 "parser.tab.c"
    break;

  case 15: /* statement: repeat_clause if_block until_clause '(' expr ')' colon  */
#line 103 "./rules/parser.y"
                                                                {if(debug){printf("%d Repeat Until  \n", i++);}}
#line 1425 "parser.tab.c"
    break;

  case 16: /* statement: for_clause '(' for_inital ENDL for_condition colon for_inc ')' if_block  */
#line 104 "./rules/parser.y"
                                                                                   { if(debug){printf("%d for loop  expr  \n", i++);} apply_defer();jump(false,-1);add_label();}
#line 1431 "parser.tab.c"
    break;

  case 17: /* statement: switch_clause '(' expr ')' '{' switch_block '}'  */
#line 105 "./rules/parser.y"
                                                          {if(debug){printf("%dswitch  expr  \n", i++);}}
#line 1437 "parser.tab.c"
    break;

  case 18: /* statement: '{' block_statements '}'  */
#line 106 "./rules/parser.y"
                                   { if(debug){printf("%d {  } \n", i++);} }
#line 1443 "parser.tab.c"
    break;

  case 20: /* for_inital: VAR EQUAL expr  */
#line 113 "./rules/parser.y"
                       {if(debug){printf("%d For Initial: VAR EQUAL expr  \n", i++);print_symbol_table();}initialize_variable((yyvsp[-2].token),(yyvsp[0].token));quadruple_insert("=","t#","NULL",(yyvsp[-2].token),false); }
#line 1449 "parser.tab.c"
    break;

  case 24: /* for_inc: VAR EQUAL expr  */
#line 122 "./rules/parser.y"
                       {if(debug){printf("%d For Initial: VAR EQUAL expr  \n", i++);print_symbol_table();}initialize_variable((yyvsp[-2].token),(yyvsp[0].token));quadruple_insert("=","t#","NULL",(yyvsp[-2].token),true); }
#line 1455 "parser.tab.c"
    break;

  case 26: /* switch_block: case_block switch_block  */
#line 128 "./rules/parser.y"
                                        { if(debug){printf("%d {  } \n", i++);} }
#line 1461 "parser.tab.c"
    break;

  case 27: /* switch_block: default_clause case_statement  */
#line 129 "./rules/parser.y"
                                                 { if(debug){printf("%d {  } \n", i++);} flag_case=0; flag_last_case = 1;add_label();flag_last_case = 0; }
#line 1467 "parser.tab.c"
    break;

  case 28: /* switch_block: default_clause  */
#line 130 "./rules/parser.y"
                                 { if(debug){printf("%d {  } \n", i++);} flag_case=0; flag_last_case = 1;add_label();flag_last_case = 0; }
#line 1473 "parser.tab.c"
    break;

  case 32: /* case_block: case_clause const_val colon case_statement  */
#line 153 "./rules/parser.y"
                                                   {  if(debug){printf("%dcase_block statement break;\n", i++);} }
#line 1479 "parser.tab.c"
    break;

  case 38: /* block_statements: statement  */
#line 179 "./rules/parser.y"
                  {}
#line 1485 "parser.tab.c"
    break;

  case 39: /* block_statements: block_statements statement  */
#line 180 "./rules/parser.y"
                                     {}
#line 1491 "parser.tab.c"
    break;

  case 41: /* expr: VAR  */
#line 186 "./rules/parser.y"
                {if(debug){printf("%d VAR \n", i++);}if(symbol_table_contains((yyvsp[0].token))){quadruple_insert("=",(yyvsp[0].token),"NULL","t#",false);set_var_used((yyvsp[0].token));}else{char err[100];sprintf(err,"varaible %s is not declared\n", (yyvsp[0].token));semantic_error_with_msg(err);}}
#line 1497 "parser.tab.c"
    break;

  case 42: /* expr: expr PLUS expr  */
#line 187 "./rules/parser.y"
                         {if(debug){printf("%d expr + expr  \n", i++);} if(check_type_match((yyvsp[-2].token),(yyvsp[0].token),0)  || check_type_match((yyvsp[-2].token),(yyvsp[0].token),1)) {(yyval.token) = ALU('+',(yyvsp[-2].token),(yyvsp[0].token));quadruple_insert("+",(yyvsp[-2].token),(yyvsp[0].token),"t#",false);}else{char err[100];sprintf(err,"two operands are of different types %s and %s\n", (yyvsp[-2].token),(yyvsp[0].token));semantic_error_with_msg(err);}}
#line 1503 "parser.tab.c"
    break;

  case 43: /* expr: expr MINUS expr  */
#line 188 "./rules/parser.y"
                          {if(debug){printf("%d expr - expr \n", i++);}  if(check_type_match((yyvsp[-2].token),(yyvsp[0].token),0) || check_type_match((yyvsp[-2].token),(yyvsp[0].token),1)){ (yyval.token) = ALU('-',(yyvsp[-2].token),(yyvsp[0].token));quadruple_insert("-",(yyvsp[-2].token),(yyvsp[0].token),"t#",false);} else{char err[100];sprintf(err,"two operands are of different types %s and %s\n", (yyvsp[-2].token),(yyvsp[0].token));semantic_error_with_msg(err);}}
#line 1509 "parser.tab.c"
    break;

  case 44: /* expr: expr MULT expr  */
#line 189 "./rules/parser.y"
                         { if(debug){printf("%d expr * expr \n", i++);}  if(check_type_match((yyvsp[-2].token),(yyvsp[0].token),0) || check_type_match((yyvsp[-2].token),(yyvsp[0].token),1)){ (yyval.token) = ALU('*',(yyvsp[-2].token),(yyvsp[0].token));quadruple_insert("*",(yyvsp[-2].token),(yyvsp[0].token),"t#",false);} else{char err[100];sprintf(err,"two operands are of different types %s and %s\n", (yyvsp[-2].token),(yyvsp[0].token));semantic_error_with_msg(err);}}
#line 1515 "parser.tab.c"
    break;

  case 45: /* expr: expr DIV expr  */
#line 190 "./rules/parser.y"
                        {if(debug){printf("%d  expr / expr  \n", i++);}  if(check_type_match((yyvsp[-2].token),(yyvsp[0].token),0) || check_type_match((yyvsp[-2].token),(yyvsp[0].token),1)){ (yyval.token) = ALU('/',(yyvsp[-2].token),(yyvsp[0].token));quadruple_insert("/",(yyvsp[-2].token),(yyvsp[0].token),"t#",false);} else{char err[100];sprintf(err,"two operands are of different types %s and %s\n", (yyvsp[-2].token),(yyvsp[0].token));semantic_error_with_msg(err);}}
#line 1521 "parser.tab.c"
    break;

  case 47: /* logic_expr: expr LOGIC_EQ expr  */
#line 194 "./rules/parser.y"
                                        {if(check_type_match((yyvsp[-2].token),(yyvsp[0].token),-1)){(yyval.token)="true";quadruple_insert("==",(yyvsp[-2].token),(yyvsp[0].token),"t#",false);} else{char err[100];sprintf(err,"two operands are of different types %s and %s\n", (yyvsp[-2].token),(yyvsp[0].token));semantic_error_with_msg(err);}}
#line 1527 "parser.tab.c"
    break;

  case 48: /* logic_expr: expr LOGIC_NEQ expr  */
#line 195 "./rules/parser.y"
                                {if(check_type_match((yyvsp[-2].token),(yyvsp[0].token),-1)){(yyval.token)="true";quadruple_insert("!=",(yyvsp[-2].token),(yyvsp[0].token),"t#",false);} else{char err[100];sprintf(err,"two operands are of different types %s and %s\n", (yyvsp[-2].token),(yyvsp[0].token));semantic_error_with_msg(err);}}
#line 1533 "parser.tab.c"
    break;

  case 49: /* logic_expr: expr LOGIC_OR expr  */
#line 196 "./rules/parser.y"
                                {if(check_type_match((yyvsp[-2].token),(yyvsp[0].token),2)){(yyval.token)="true";quadruple_insert("||",(yyvsp[-2].token),(yyvsp[0].token),"t#",false);} else{char err[100];sprintf(err,"two operands must be boolean types %s and %s\n", (yyvsp[-2].token),(yyvsp[0].token));semantic_error_with_msg(err);}}
#line 1539 "parser.tab.c"
    break;

  case 50: /* logic_expr: expr LOGIC_AND expr  */
#line 197 "./rules/parser.y"
                                {if(check_type_match((yyvsp[-2].token),(yyvsp[0].token),2)){(yyval.token)="true";quadruple_insert("&&",(yyvsp[-2].token),(yyvsp[0].token),"t#",false);} else{char err[100];sprintf(err,"two operands must be boolean types %s and %s\n", (yyvsp[-2].token),(yyvsp[0].token));semantic_error_with_msg(err);}}
#line 1545 "parser.tab.c"
    break;

  case 51: /* logic_expr: expr LOGIC_LT expr  */
#line 198 "./rules/parser.y"
                                {if(check_type_match((yyvsp[-2].token),(yyvsp[0].token),0) || check_type_match((yyvsp[-2].token),(yyvsp[0].token),1)){(yyval.token)="true";quadruple_insert("<",(yyvsp[-2].token),(yyvsp[0].token),"t#",false);}else{char err[100];sprintf(err,"two operands must be both int or double %s and %s\n", (yyvsp[-2].token),(yyvsp[0].token));semantic_error_with_msg(err);}}
#line 1551 "parser.tab.c"
    break;

  case 52: /* logic_expr: expr LOGIC_LEQ expr  */
#line 199 "./rules/parser.y"
                                {if(check_type_match((yyvsp[-2].token),(yyvsp[0].token),0) || check_type_match((yyvsp[-2].token),(yyvsp[0].token),1)){(yyval.token)="true";quadruple_insert("<=",(yyvsp[-2].token),(yyvsp[0].token),"t#",false);}else{char err[100];sprintf(err,"two operands must be both int or double %s and %s\n", (yyvsp[-2].token),(yyvsp[0].token));semantic_error_with_msg(err);}}
#line 1557 "parser.tab.c"
    break;

  case 53: /* logic_expr: expr LOGIC_GT expr  */
#line 200 "./rules/parser.y"
                                {if(check_type_match((yyvsp[-2].token),(yyvsp[0].token),0) || check_type_match((yyvsp[-2].token),(yyvsp[0].token),1)){(yyval.token)="true";quadruple_insert(">",(yyvsp[-2].token),(yyvsp[0].token),"t#",false);}else{char err[100];sprintf(err,"two operands must be both int or double %s and %s\n", (yyvsp[-2].token),(yyvsp[0].token));semantic_error_with_msg(err);}}
#line 1563 "parser.tab.c"
    break;

  case 54: /* logic_expr: expr LOGIC_GEQ expr  */
#line 201 "./rules/parser.y"
                                {if(check_type_match((yyvsp[-2].token),(yyvsp[0].token),0) || check_type_match((yyvsp[-2].token),(yyvsp[0].token),1)){(yyval.token)="true";quadruple_insert(">=",(yyvsp[-2].token),(yyvsp[0].token),"t#",false);}else{char err[100];sprintf(err,"two operands must be both int or double %s and %s\n", (yyvsp[-2].token),(yyvsp[0].token));semantic_error_with_msg(err);}}
#line 1569 "parser.tab.c"
    break;

  case 55: /* logic_expr: '(' expr ')'  */
#line 202 "./rules/parser.y"
                       {if(debug){printf("%d (expr) \n", i++);}  }
#line 1575 "parser.tab.c"
    break;

  case 56: /* const_val: FALSE_VALUE  */
#line 206 "./rules/parser.y"
                        {if(debug){printf("%d const_val \n", i++);}quadruple_insert("=",(yyvsp[0].token),"NULL","t#",false);}
#line 1581 "parser.tab.c"
    break;

  case 57: /* const_val: TRUE_VALUE  */
#line 207 "./rules/parser.y"
                        {if(debug){printf("%d const_val \n", i++);}quadruple_insert("=",(yyvsp[0].token),"NULL","t#",false);}
#line 1587 "parser.tab.c"
    break;

  case 58: /* const_val: DOUBLE_VALUE  */
#line 208 "./rules/parser.y"
                        {if(debug){printf("%d const_val \n", i++);}quadruple_insert("=",(yyvsp[0].token),"NULL","t#",false);}
#line 1593 "parser.tab.c"
    break;

  case 59: /* const_val: INT_VALUE  */
#line 209 "./rules/parser.y"
                                {if(debug){printf("%d const_val \n", i++);}quadruple_insert("=",(yyvsp[0].token),"NULL","t#",false);}
#line 1599 "parser.tab.c"
    break;

  case 60: /* const_val: CHAR_VALUE  */
#line 210 "./rules/parser.y"
                        {if(debug){printf("%d const_val \n", i++);}quadruple_insert("=",(yyvsp[0].token),"NULL","t#",false);}
#line 1605 "parser.tab.c"
    break;

  case 61: /* const_val: STRING_VALUE  */
#line 211 "./rules/parser.y"
                        {if(debug){printf("%d const_val \n", i++);}quadruple_insert("=",(yyvsp[0].token),"NULL","t#",false);}
#line 1611 "parser.tab.c"
    break;

  case 62: /* typing: TYPE_INT  */
#line 215 "./rules/parser.y"
                                {if(debug){printf("Type INT recieved\n");}}
#line 1617 "parser.tab.c"
    break;

  case 63: /* typing: TYPE_DOUBLE  */
#line 216 "./rules/parser.y"
                        {if(debug){printf("Type Double recieved\n");}}
#line 1623 "parser.tab.c"
    break;

  case 64: /* typing: TYPE_BOOL  */
#line 217 "./rules/parser.y"
                        {if(debug){printf("Type BOOL recieved\n");}}
#line 1629 "parser.tab.c"
    break;

  case 65: /* typing: TYPE_CHAR  */
#line 218 "./rules/parser.y"
                        {if(debug){printf("Type CHAR recieved\n");}}
#line 1635 "parser.tab.c"
    break;

  case 66: /* typing: TYPE_STRING  */
#line 219 "./rules/parser.y"
                        {if(debug){printf("Type STRING recieved\n");}}
#line 1641 "parser.tab.c"
    break;

  case 67: /* Constant_type: TYPE_CONST  */
#line 223 "./rules/parser.y"
                                {if(debug){printf("Type CONST recieved\n");}}
#line 1647 "parser.tab.c"
    break;

  case 68: /* colon: COLON  */
#line 227 "./rules/parser.y"
                                {if(debug){printf("Type COLON recieved\n");} manage_colon();}
#line 1653 "parser.tab.c"
    break;

  case 69: /* if_clause: IF  */
#line 230 "./rules/parser.y"
                                {if(debug){printf("Type IF recieved\n");}}
#line 1659 "parser.tab.c"
    break;

  case 70: /* elif_clause: ELIF  */
#line 233 "./rules/parser.y"
                                {if(debug){printf("Type ELIF recieved\n");} jump(true,+1); add_label();}
#line 1665 "parser.tab.c"
    break;

  case 71: /* else_clause: ELSE  */
#line 236 "./rules/parser.y"
                                {if(debug){printf("Type ELSE recieved\n");} jump(true,+1); add_label();}
#line 1671 "parser.tab.c"
    break;

  case 72: /* while_clause: WHILE  */
#line 239 "./rules/parser.y"
                                {if(debug){printf("Type WHILE recieved\n");} add_label();}
#line 1677 "parser.tab.c"
    break;

  case 73: /* repeat_clause: REPEAT  */
#line 242 "./rules/parser.y"
                                {if(debug){printf("Type REPEAT recieved\n");}add_label();}
#line 1683 "parser.tab.c"
    break;

  case 74: /* until_clause: UNTIL  */
#line 245 "./rules/parser.y"
                                {if(debug){printf("Type UNTIL recieved\n");} flag_until=1;}
#line 1689 "parser.tab.c"
    break;

  case 75: /* for_clause: FOR  */
#line 248 "./rules/parser.y"
                                {if(debug){printf("Type FOR recieved\n");}add_label();}
#line 1695 "parser.tab.c"
    break;

  case 76: /* switch_clause: SWITCH  */
#line 251 "./rules/parser.y"
                                {if(debug){printf("Type SWITCH recieved\n");}}
#line 1701 "parser.tab.c"
    break;

  case 77: /* case_clause: CASE  */
#line 254 "./rules/parser.y"
                                {if(debug){printf("Type Case recieved\n");} if(!flag_case){t_reg=t-1;flag_case=1;}else{jump(true,+1); add_label();}}
#line 1707 "parser.tab.c"
    break;

  case 78: /* default_clause: DEFAULT  */
#line 257 "./rules/parser.y"
                                {if(debug){printf("Type Default recieved\n");} jump(true,+1); add_label();}
#line 1713 "parser.tab.c"
    break;


#line 1717 "parser.tab.c"

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

#line 261 "./rules/parser.y"


struct symbol_table symbol_table_elements[500];
/* struct symbol_table symbol_table_elements_scoped[200]; */
int symbol_table_idx = 0;
/* int symbol_table_scope_idx = 0; */

struct Quadruple quadruples[200];
struct Quadruple defer_quadruples[5];
int quadruple_idx = 0;

// Symbol table functions

bool symbol_table_contains(char* var_name) {//symbol_table_contains
	for(int i = 0; i < symbol_table_idx; i++) {
		if(!strcmp(var_name, symbol_table_elements[i].name))
			return true;
	}

	return false;
}

int symbol_table_get_varType(char* var_name){
	for(int i = 0; i < symbol_table_idx; i++) {
		if(!strcmp(var_name, symbol_table_elements[i].name))
			return symbol_table_elements[i].type;
	}
}

bool is_var_initialized(char* var_name){
	for(int i = 0; i < symbol_table_idx; i++) {
		if(!strcmp(var_name, symbol_table_elements[i].name))
			return symbol_table_elements[i].initialized;
	}
	return false;
}

bool is_var_constant(char* var_name){
	for(int i = 0; i < symbol_table_idx; i++) {
		if(!strcmp(var_name, symbol_table_elements[i].name))
			return symbol_table_elements[i].constant;
	}
	return false;
}

void symbol_table_insert(char* var_type, char* var_name, bool is_const, bool is_initial, char* var_value){
	// check if already found
	if(symbol_table_contains(var_name)) { 
		char err[100];
		sprintf(err,"Redeclaration of already declared variable %s\n", var_name);
		semantic_error_with_msg(err); return; 
	}
	// check for type
	int dtype = convert_name_type(var_type);
	if(dtype == -1){
		char err[100];
		sprintf(err,"Unknown type for variable %s\n", var_name);
		semantic_error_with_msg(err); return; 
	}
	// check if const and not initialized
	if(is_const && !is_initial){
		char err[100];
		sprintf(err,"type Const variable must be initialized immediately %s\n", var_name);
		semantic_error_with_msg(err); return; 
	}

	struct symbol_table new_element;
	new_element.type = dtype;
	new_element.initialized = is_initial;
	new_element.constant = is_const;
	new_element.used = false;
	new_element.line_num = lineno;
	
	strcpy(new_element.name, var_name);
	
	// insert a non-initialized element
	if(!is_initial){
		symbol_table_elements[symbol_table_idx++] = new_element;
		return;
	}

	int val_type = check_val_type(var_value);
	if(val_type != 5){
		if(new_element.type != val_type){ 
			char err[100];
			sprintf(err,"(Type Mismatch): %s and %s are of different types\n", var_name, var_value);
			semantic_error_with_msg(err); return;
		}
	}
	// assign var to var
	else{
		if(!symbol_table_contains(var_value)) { 
			char err[100];
			sprintf(err,"you assign %s to a not declared variable: %s\n",var_name, var_value);
			semantic_error_with_msg(err); 
			return; 
		}
		
		int v_type_int = symbol_table_get_varType(var_value);

		if(v_type_int != new_element.type){ 
			char err[100];
			sprintf(err,"(Type Mismatch): %s and %s are of different types\n", var_name, var_value);
			semantic_error_with_msg(err); return; 
		}

		if(!is_var_initialized(var_value)) { 
			char err[100];
			sprintf(err,"warning: you assign %s to a not initialized variable: %s\n", var_name, var_value);
			semantic_error_with_msg(err);
		}

		set_var_used(var_value);
	}
	// insert an initialized element
	new_element.initialized = true;
	symbol_table_elements[symbol_table_idx++] = new_element;
}

void set_var_initialized(char* var_name){

	for(int i = 0; i < symbol_table_idx; i++) {
		if(!strcmp(var_name, symbol_table_elements[i].name))
		{
			symbol_table_elements[i].initialized = true;
			return;
		}
	}
}

void set_var_used(char* var_name){

	for(int i = 0; i < symbol_table_idx; i++) {
		if(!strcmp(var_name, symbol_table_elements[i].name))
		{
			symbol_table_elements[i].used = true;
			return;
		}
	}
}

bool check_type_match(char* x, char* y, int specified){
	int x_type = check_val_type(x),y_type = check_val_type(y);
	if(x_type == 5){
		x_type = symbol_table_get_varType(x);
	}
	if(y_type == 5){
		y_type = symbol_table_get_varType(y);
	}
	if (specified == -1) specified = x_type;
	return (x_type == specified && specified == y_type);
}

int check_val_type(char* val){
	// int or double
	if(val[0] >= '0' && val[0] <= '9'){
		if(strchr(val,'.') == NULL){ //int
			return 0;
		}
		else{ //double
			return 1;
		}
	}
	//bool
	if(!strcmp(val,"false") || !strcmp(val,"true") || !strcmp(val,"truepassed") ){
		return 2;
	}
	//char
	if(val[0] == '\''){
		return 3;
	}
	//string
	if(val[0] == '"'){
		return 4;
	}
	return 5;
}

int convert_name_type(char * var_type){
	if(!strcmp(var_type, "int")){
		return 0;
	}
	if(!strcmp(var_type, "double")){
		return 1;
	}
	if(!strcmp(var_type, "bool")){
		return 2;
	}
	if(!strcmp(var_type, "char")){
		return 3;
	}
	if(!strcmp(var_type, "string")){
		return 4;
	}
	return -1;
}

void initialize_variable(char * var_name, char * value){
	
	if(!symbol_table_contains(var_name)) { 
		char err[100];
		sprintf(err,"%s not declared\n", var_name);
		semantic_error_with_msg(err); 
		return; 
	}

	if(is_var_constant(var_name)){
		char err[100];
		sprintf(err,"Constant var can't be re-initialized %s\n", var_name);
		semantic_error_with_msg(err); return; 
	}
	
	if(is_var_initialized(var_name)){
		set_var_used(var_name);
	}

	int var_type_int = symbol_table_get_varType(var_name);
	int val_type = check_val_type(value);
	if(val_type != 5){
		if(var_type_int != val_type){ 
			char err[100];
			sprintf(err,"(Type Mismatch) %s and %s are of different types\n", var_name, value);
			semantic_error_with_msg(err); return;
		}
		set_var_initialized(var_name);
	}
	// assign var to var
	else{
		if(!symbol_table_contains(value)) { 
			char err[100];
			sprintf(err,"you assign %s to a not declared variable %s\n",var_name ,value);
			semantic_error_with_msg(err); 
			return; 
		}

		int v_type_int = symbol_table_get_varType(value);

		if(v_type_int != var_type_int){ 
			char err[100];
			sprintf(err,"%s and %s are of different types\n", var_name, value);
			semantic_error_with_msg(err); return; 
		}
		
		if(!is_var_initialized(value)) { 
			char err[100];
			sprintf(err,"warning: you assign %s to a not initialized variable %s\n",var_name ,value);
			semantic_error_with_msg(err);
		}
		set_var_initialized(var_name);
	}
}


void print_symbol_table() {
	for(int s = 0; s < symbol_table_idx; s++) {
		printf("[%d] type: %s\tname: %s\tconst: %s\tinitialized: %s\tused: %s\tline#: %d\n", s+1, arr_type[symbol_table_elements[s].type], symbol_table_elements[s].name, symbol_table_elements[s].constant ? "true" : "false", symbol_table_elements[s].initialized? "true" : "false",symbol_table_elements[s].used? "true" : "false",symbol_table_elements[s].line_num);
	}
}

char* reverse_type_value(int ty){
	switch(ty){
		case 0:
			return "1passed";
		case 1:
			return "1.1passed";
		case 2:
			return "truepassed";
		case 3:
			return "'c'";
		case 4:
			return "\"str\"";
	}
}

char* ALU(char op,char* x,char* y){
	int y_type = check_val_type(y);
	if(y_type == 5){
		y_type = symbol_table_get_varType(y);
	}else if( op == '/' && atoi(y) == 0){
		char err[100];
		sprintf(err,"Warning: you might be dividing by zero\n");
		semantic_error_with_msg(err);
	}
	return reverse_type_value(y_type);
}

void quadruple_insert(char* op, char* src1_passed, char* src2_passed, char* dst_passed, bool defer){
	if(debug)printf("Quadruples: operator: %s, src1: %s, src2: %s, dst: %s\n",op,src1_passed,src2_passed,dst_passed);
	char str_num[5];
	char src1[10], src2[10], dst[10];
	strcpy(src1, src1_passed);
	strcpy(src2, src2_passed);
	strcpy(dst, dst_passed);
	if (strcmp(src1_passed,"t#") == 0 || strstr(src1_passed, "passed") != NULL){
		strcpy(src1, "t");
		sprintf(str_num, "%d", t-1);
		strcat(src1,str_num);
	}
	if (strcmp(src2_passed,"NULL") == 0){
		strcpy(src2, "");
	}
	if (strcmp(dst_passed,"t#") == 0){
		strcpy(dst, "t");
		sprintf(str_num, "%d", t++);
		strcat(dst,str_num);
	}
	struct Quadruple new_element;

	/* new_element.line_num = lineno; */
	strcpy(new_element.dst, dst);
	strcpy(new_element.src1, src1);
	strcpy(new_element.src2, src2);
	strcpy(new_element.op, op);

	if (defer){
		defer_quadruples[0] = new_element;
	}
	else{
		quadruples[quadruple_idx++] = new_element;
	}
}

void manage_colon(){
	char str_num[5];
	struct Quadruple new_element;
	// operation
	strcpy(new_element.op, "JNE");

	// first argument
	if(flag_case){
		strcpy(new_element.src1, "t");
		sprintf(str_num, "%d", t-1);
		strcat(new_element.src1,str_num);	
	}
	else{
		strcpy(new_element.src1, "true");
	}
	// t# at second argument
	strcpy(new_element.src2, "t");
	if(flag_case){
		sprintf(str_num, "%d", t_reg);
		strcat(new_element.src2,str_num);	
	}
	else{
		sprintf(str_num, "%d", t-1);
		strcat(new_element.src2,str_num);
	}
	// label at dst
	strcpy(new_element.dst, "label");
	if(flag_until == 1){
		sprintf(str_num, "%d", label-1);
		flag_until = 0;
	}else if(flag_case){
		sprintf(str_num, "%d", label++);
	}
	else{
		sprintf(str_num, "%d", label);
	}
	strcat(new_element.dst,str_num);
	quadruples[quadruple_idx++] = new_element;
}

void jump(bool switch_case, int to){
	char str_num[5];
	struct Quadruple new_element;
	strcpy(new_element.src1, "");
	strcpy(new_element.src2, "");
	strcpy(new_element.op, "jmp");
	if(switch_case){
		strcpy(new_element.dst, "lbl");
		sprintf(str_num, "%d", label_switch_case);
	}else{
		strcpy(new_element.dst, "label");
		sprintf(str_num, "%d", label+to);
	}
	strcat(new_element.dst,str_num);
	quadruples[quadruple_idx++] = new_element;
}

void add_label(){
	char str_num[5];
	struct Quadruple new_element;
	strcpy(new_element.src1, "");
	strcpy(new_element.src2, "");
	strcpy(new_element.op, "");
	if(flag_last_case){
		strcpy(new_element.dst, "lbl");
		sprintf(str_num, "%d", label_switch_case++);
	}
	else if(flag_case){
		strcpy(new_element.dst, "label");
		sprintf(str_num, "%d", label-1);
	}else{
		strcpy(new_element.dst, "label");
		sprintf(str_num, "%d", label++);
	}
	strcat(new_element.dst,str_num);
	quadruples[quadruple_idx++] = new_element;
}

void apply_defer(){
	quadruples[quadruple_idx++] = defer_quadruples[0];
}

void print_quadruples(){
	printf("\n-------------------------printttttttttt Quadruples-------------------------\n");
	for(int q = 0; q < quadruple_idx; q++){
		//printf("\nline: %d\n", quadruples[q].line_num);
		printf("arg1: %s\t", quadruples[q].src1);
		printf("operation: %s\t", quadruples[q].op);
		printf("arg2: %s\t", quadruples[q].src2);
		printf("result: %s\n", quadruples[q].dst);
	}
	printf("-------------------------End printttttttttt Quadruples-------------------------\n");
}

void print_warning(){
	for(int i = 0; i < symbol_table_idx; i++){
		if(!symbol_table_elements[i].initialized && symbol_table_elements[i].used)
			printf("Warning! variable %s at line %d used without being initialized, contain garbage(Rubbish)\n",symbol_table_elements[i].name,symbol_table_elements[i].line_num);
		if(!symbol_table_elements[i].used)
			printf("Warning! variable %s at line %d is not used, please take care of your memory\n",symbol_table_elements[i].name,symbol_table_elements[i].line_num);
	}
}


void semantic_error_with_msg(char * err){
	semantic_error_found = true;
	fprintf(stderr, "Semantic error at line %d | %s\n", lineno, err);
}

void yyerror(char*s){
	fprintf(stderr, "syntax error at line %d\n", lineno);
	exit(1);
}

int main(int argc,char* argv[])
{
	int syntax_err_found;
	yyin = fopen(argv[1], "r");
	syntax_err_found = yyparse();
	fclose(yyin);
	
	if(!syntax_err_found && !semantic_error_found) print_quadruples();
	print_symbol_table();
	print_warning();
	printf("end of parser\n");
	return 0;
}

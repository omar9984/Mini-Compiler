/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    EQUAL = 258,                   /* EQUAL  */
    LOGIC_OR = 259,                /* LOGIC_OR  */
    LOGIC_AND = 260,               /* LOGIC_AND  */
    LOGIC_EQ = 261,                /* LOGIC_EQ  */
    LOGIC_NEQ = 262,               /* LOGIC_NEQ  */
    LOGIC_LT = 263,                /* LOGIC_LT  */
    LOGIC_LEQ = 264,               /* LOGIC_LEQ  */
    LOGIC_GT = 265,                /* LOGIC_GT  */
    LOGIC_GEQ = 266,               /* LOGIC_GEQ  */
    PLUS = 267,                    /* PLUS  */
    MINUS = 268,                   /* MINUS  */
    MULT = 269,                    /* MULT  */
    DIV = 270,                     /* DIV  */
    VAR = 271,                     /* VAR  */
    ENDL = 272,                    /* ENDL  */
    COLON = 273,                   /* COLON  */
    IF = 274,                      /* IF  */
    ELIF = 275,                    /* ELIF  */
    ELSE = 276,                    /* ELSE  */
    FOR = 277,                     /* FOR  */
    WHILE = 278,                   /* WHILE  */
    REPEAT = 279,                  /* REPEAT  */
    UNTIL = 280,                   /* UNTIL  */
    SWITCH = 281,                  /* SWITCH  */
    CASE = 282,                    /* CASE  */
    DEFAULT = 283,                 /* DEFAULT  */
    END = 284,                     /* END  */
    TYPE_INT = 285,                /* TYPE_INT  */
    TYPE_CHAR = 286,               /* TYPE_CHAR  */
    TYPE_CONST = 287,              /* TYPE_CONST  */
    TYPE_BOOL = 288,               /* TYPE_BOOL  */
    TYPE_DOUBLE = 289,             /* TYPE_DOUBLE  */
    TYPE_STRING = 290,             /* TYPE_STRING  */
    INT_VALUE = 291,               /* INT_VALUE  */
    DOUBLE_VALUE = 292,            /* DOUBLE_VALUE  */
    FALSE_VALUE = 293,             /* FALSE_VALUE  */
    TRUE_VALUE = 294,              /* TRUE_VALUE  */
    CHAR_VALUE = 295,              /* CHAR_VALUE  */
    STRING_VALUE = 296             /* STRING_VALUE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 60 "./rules/parser.y"

	char* token;

#line 109 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

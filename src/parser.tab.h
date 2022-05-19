/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
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
    EQUAL = 258,
    LOGIC_OR = 259,
    LOGIC_AND = 260,
    LOGIC_EQ = 261,
    LOGIC_NEQ = 262,
    LOGIC_LT = 263,
    LOGIC_LEQ = 264,
    LOGIC_GT = 265,
    LOGIC_GEQ = 266,
    PLUS = 267,
    MINUS = 268,
    MULT = 269,
    DIV = 270,
    VAR = 271,
    ENDL = 272,
    IF = 273,
    ELIF = 274,
    ELSE = 275,
    FOR = 276,
    WHILE = 277,
    REPEAT = 278,
    UNTIL = 279,
    SWITCH = 280,
    CASE = 281,
    BREAK = 282,
    DEFAULT = 283,
    TYPE_INT = 284,
    TYPE_CHAR = 285,
    TYPE_CONST = 286,
    TYPE_BOOL = 287,
    TYPE_DOUBLE = 288,
    INT_VALUE = 289,
    DOUBLE_VALUE = 290,
    FALSE_VALUE = 291,
    TRUE_VALUE = 292
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

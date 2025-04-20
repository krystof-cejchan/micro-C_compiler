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
/* "%code requires" blocks.  */
#line 1 "parser.y"

    typedef struct Uzel Uzel;

#line 53 "parser.tab.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    CISLO = 258,                   /* CISLO  */
    PROMENNA = 259,                /* PROMENNA  */
    RETEZ = 260,                   /* RETEZ  */
    PRINT = 261,                   /* PRINT  */
    SCAN = 262,                    /* SCAN  */
    IF = 263,                      /* IF  */
    ELSE = 264,                    /* ELSE  */
    FOR = 265,                     /* FOR  */
    WHILE = 266,                   /* WHILE  */
    DO = 267,                      /* DO  */
    SHL = 268,                     /* SHL  */
    SHR = 269,                     /* SHR  */
    MOD = 270,                     /* MOD  */
    AND = 271,                     /* AND  */
    OR = 272,                      /* OR  */
    NOT = 273,                     /* NOT  */
    BIT_NOT = 274,                 /* BIT_NOT  */
    POROVNANI = 275,               /* POROVNANI  */
    NENIROVNO = 276,               /* NENIROVNO  */
    MENSIROVNO = 277,              /* MENSIROVNO  */
    VETSIROVNO = 278,              /* VETSIROVNO  */
    ADD_ASSIGN = 279,              /* ADD_ASSIGN  */
    SUB_ASSIGN = 280,              /* SUB_ASSIGN  */
    MUL_ASSIGN = 281,              /* MUL_ASSIGN  */
    DIV_ASSIGN = 282,              /* DIV_ASSIGN  */
    MOD_ASSIGN = 283,              /* MOD_ASSIGN  */
    SHL_ASSIGN = 284,              /* SHL_ASSIGN  */
    SHR_ASSIGN = 285,              /* SHR_ASSIGN  */
    AND_ASSIGN = 286,              /* AND_ASSIGN  */
    XOR_ASSIGN = 287,              /* XOR_ASSIGN  */
    OR_ASSIGN = 288,               /* OR_ASSIGN  */
    BIT_AND = 289,                 /* BIT_AND  */
    BIT_OR = 290,                  /* BIT_OR  */
    BIT_XOR = 291,                 /* BIT_XOR  */
    COMMA = 292,                   /* COMMA  */
    TERNARY_QUEST = 293,           /* TERNARY_QUEST  */
    TERNARY_COLON = 294,           /* TERNARY_COLON  */
    INKREM = 295,                  /* INKREM  */
    DEKREM = 296,                  /* DEKREM  */
    UMINUS = 297                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 14 "parser.y"
 Uzel *u; 

#line 115 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

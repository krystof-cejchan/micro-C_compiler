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

#include "microC.h"
#ifndef YY_YY_MIKROC_TAB_HPP_INCLUDED
# define YY_YY_MIKROC_TAB_HPP_INCLUDED
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
    CISLO = 258,                   /* CISLO  */
    RETEZ = 259,                   /* RETEZ  */
    PROMENNA = 260,                /* PROMENNA  */
    IF = 261,                      /* IF  */
    ELSE = 262,                    /* ELSE  */
    FOR = 263,                     /* FOR  */
    WHILE = 264,                   /* WHILE  */
    DO = 265,                      /* DO  */
    PRINT = 266,                   /* PRINT  */
    SCAN = 267,                    /* SCAN  */
    P_NASOB = 268,                 /* P_NASOB  */
    P_DELEN = 269,                 /* P_DELEN  */
    P_MODUL = 270,                 /* P_MODUL  */
    P_PRICT = 271,                 /* P_PRICT  */
    P_ODECT = 272,                 /* P_ODECT  */
    P_POSUNVLEVO = 273,            /* P_POSUNVLEVO  */
    P_POSUNVPRAVO = 274,           /* P_POSUNVPRAVO  */
    P_AND = 275,                   /* P_AND  */
    P_XOR = 276,                   /* P_XOR  */
    P_OR = 277,                    /* P_OR  */
    OR = 278,                      /* OR  */
    AND = 279,                     /* AND  */
    ROVNO = 280,                   /* ROVNO  */
    NENIROVNO = 281,               /* NENIROVNO  */
    MENSIROVNO = 282,              /* MENSIROVNO  */
    VETSIROVNO = 283,              /* VETSIROVNO  */
    POSUNVLEVO = 284,              /* POSUNVLEVO  */
    POSUNVPRAVO = 285,             /* POSUNVPRAVO  */
    INKREM = 286,                  /* INKREM  */
    DEKREM = 287,                  /* DEKREM  */
    NOT = 288,                     /* NOT  */
    MINUS = 289,                   /* MINUS  */
    PLUS = 290                     /* PLUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_MIKROC_TAB_HPP_INCLUDED  */

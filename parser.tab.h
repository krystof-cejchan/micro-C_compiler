
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     CISLO = 258,
     PROMENNA = 259,
     RETEZ = 260,
     PRINT = 261,
     SCAN = 262,
     IF = 263,
     ELSE = 264,
     FOR = 265,
     WHILE = 266,
     DO = 267,
     INKREM = 268,
     DEKREM = 269,
     SHL = 270,
     SHR = 271,
     MOD = 272,
     AND = 273,
     OR = 274,
     NOT = 275,
     BIT_NOT = 276,
     POROVNANI = 277,
     NENIROVNO = 278,
     MENSIROVNO = 279,
     VETSIROVNO = 280,
     ADD_ASSIGN = 281,
     SUB_ASSIGN = 282,
     MUL_ASSIGN = 283,
     DIV_ASSIGN = 284,
     MOD_ASSIGN = 285,
     SHL_ASSIGN = 286,
     SHR_ASSIGN = 287,
     AND_ASSIGN = 288,
     XOR_ASSIGN = 289,
     OR_ASSIGN = 290,
     BIT_AND = 291,
     BIT_OR = 292,
     BIT_XOR = 293,
     COMMA = 294,
     TERNARY_QUEST = 295,
     TERNARY_COLON = 296,
     UMINUS = 297
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 10 "parser.y"
 Uzel *u; 


/* Line 1676 of yacc.c  */
#line 98 "parser.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;



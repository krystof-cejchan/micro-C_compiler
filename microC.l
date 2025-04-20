%{
#include "parser.tab.h"
#include <stdio.h>
#include <ctype.h>

extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yycolumn = 1;

#define YY_USER_ACTION \
    yylloc.first_line = yylineno; \
    yylloc.first_column = yycolumn; \
    yylloc.last_line = yylineno; \
    yylloc.last_column = yycolumn + yyleng - 1; \
    yycolumn += yyleng;

%}

%option yylineno
%option noyywrap

DIGIT       [0-9]
HEX         [0-9a-fA-F]
BIN         [01]
ID          [a-zA-Z_][a-zA-Z0-9_]*
WHITESPACE  [ \t\r]
COMMENT     "/*"([^*]|"*"[^/])*"*/"|"//".*

%%

\n          { yycolumn = 1; yylineno++; }

{WHITESPACE}   { /* Ignore */ }
{COMMENT}      { /* Ignore */ }

"if"          { return IF; }
"else"        { return ELSE; }
"for"         { return FOR; }
"while"       { return WHILE; }
"do"          { return DO; }
"print"       { return PRINT; }
"scan"        { return SCAN; }
"true"        { yylval.num = 1; return CONST; }
"false"       { yylval.num = 0; return CONST; }
"not"         { return NOT; }
"and"         { return AND; }
"or"          { return OR; }

"++"          { return INC; }
"--"          { return DEC; }
"+"           { return '+'; }
"-"           { return '-'; }
"*"           { return '*'; }
"/"           { return '/'; }
"%"           { return '%'; }
"<<"          { return LSHIFT; }
">>"          { return RSHIFT; }
"=="          { return EQ; }
"!="          { return NEQ; }
"<="          { return LE; }
">="          { return GE; }
"<"           { return '<'; }
">"           { return '>'; }
"&"           { return '&'; }
"^"           { return '^'; }
"|"           { return '|'; }
"="           { return '='; }

0[bB]{BIN}+   { yylval.num = strtol(yytext + 2, NULL, 2); return CONST; }
0[xX]{HEX}+   { yylval.num = strtol(yytext + 2, NULL, 16); return CONST; }
{DIGIT}+      { yylval.num = strtol(yytext, NULL, 10); return CONST; }
{ID}          { yylval.str = strdup(yytext); return ID; }
\"(\\.|[^\"])*\" { yylval.str = strdup(yytext); return STRING; }

.             { return yytext[0]; }

%%
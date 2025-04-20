%{
#include "ast.h"
#include "parser.tab.h"
extern YYSTYPE yylval;
extern unsigned Radek, Sloupec;
%}

%option yylineno
%option noyywrap

BIN         (0b)[01]+
HEX         \$[0-9a-fA-F]+
CISLO       [0-9]+
ID          [a-zA-Z_][a-zA-Z0-9_]*
MEZERY      [ \t]
RADEK       \n
KOMENTAR    "/*"([^*]|"*"+[^*/])*"*/"|"//".*

%%

{MEZERY}    { Sloupec++; }
{RADEK}     { Radek++; Sloupec=1; }
{KOMENTAR}  /* Ignorovat */

"++"        { return INKREM; }
"--"        { return DEKREM; }
"<<="       { return SHL_ASSIGN; }
">>="       { return SHR_ASSIGN; }
"+="        { return ADD_ASSIGN; }
"-="        { return SUB_ASSIGN; }
"*="        { return MUL_ASSIGN; }
"/="        { return DIV_ASSIGN; }
"%="        { return MOD_ASSIGN; }
"&="        { return AND_ASSIGN; }
"^="        { return XOR_ASSIGN; }
"|="        { return OR_ASSIGN; }
"<<"        { return SHL; }
">>"        { return SHR; }
"=="        { return POROVNANI; }
"!="        { return NENIROVNO; }
"<="        { return MENSIROVNO; }
">="        { return VETSIROVNO; }
"&&"|"and"  { return AND; }
"||"|"or"   { return OR; }
"!"|"not"   { return NOT; }
"~"         { return BIT_NOT; }
"="         { return '='; }
"+"         { return '+'; }
"-"         { return '-'; }
"*"         { return '*'; }
"/"         { return '/'; }
"%"         { return MOD; }
"<"         { return '<'; }
">"         { return '>'; }
"&"         { return BIT_AND; }
"|"         { return BIT_OR; }
"^"         { return BIT_XOR; }
"?"         { return TERNARY_QUEST; }
":"         { return TERNARY_COLON; }
","         { return COMMA; }

"print"     { return PRINT; }
"scan"      { return SCAN; }
"if"        { return IF; }
"else"      { return ELSE; }
"for"       { return FOR; }
"while"     { return WHILE; }
"do"        { return DO; }

{BIN}       { yylval.u = GenCislo(strtol(yytext+2, NULL, 2)); return CISLO; }
{HEX}       { yylval.u = GenCislo(strtol(yytext+1, NULL, 16)); return CISLO; }
{CISLO}     { yylval.u = GenCislo(atoi(yytext)); return CISLO; }
{ID}        { yylval.u = GenPromen(yytext); return PROMENNA; }

\"(\\.|[^"\\])*\" { yylval.u = GenRetez(strdup(yytext)); return RETEZ; }

.           { return yytext[0]; }
%%
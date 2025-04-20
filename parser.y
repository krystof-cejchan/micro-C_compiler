%code requires {
    typedef struct Uzel Uzel;  // Forward declaration for Bison
}

%{
#include "ast.h"
#include <stdio.h>
extern Uzel *Koren;
extern unsigned Radek, Sloupec;
extern bool Chyby;
void yyerror(const char *s);
%}

%union { Uzel *u; }

%token <u> CISLO PROMENNA RETEZ
%token PRINT SCAN IF ELSE FOR WHILE DO
%token SHL SHR MOD AND OR NOT BIT_NOT
%token POROVNANI NENIROVNO MENSIROVNO VETSIROVNO
%token ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN
%token SHL_ASSIGN SHR_ASSIGN AND_ASSIGN XOR_ASSIGN OR_ASSIGN
%token BIT_AND BIT_OR BIT_XOR COMMA TERNARY_QUEST TERNARY_COLON
%token INKREM DEKREM

%right '=' ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN
%right SHL_ASSIGN SHR_ASSIGN AND_ASSIGN XOR_ASSIGN OR_ASSIGN
%left OR AND
%left BIT_OR BIT_XOR
%left BIT_AND
%left '<' '>' MENSIROVNO VETSIROVNO POROVNANI NENIROVNO
%left '+' '-'
%left '*' '/' MOD
%right SHL SHR
%right INKREM DEKREM NOT BIT_NOT UMINUS
%right TERNARY_QUEST TERNARY_COLON
%left COMMA

%type <u> program prikaz vyraz prikaz_list

%start program

%%

program: prikaz { Koren = $1; }

prikaz:
    /* empty */                     { $$ = NULL; }
  | prikaz                         { $$ = $1; }  // Povolit jednotlivý příkaz
  | prikaz prikaz_list             { $$ = GenUzel(0, $1, $2, NULL, NULL); }
  | PRINT '(' RETEZ ')' ';'         { $$ = GenUzel(PRINT, $3, NULL, NULL, NULL); }  // New rule for strings without arguments
  | PRINT '(' RETEZ ',' vyraz ')' ';' { $$ = GenUzel(PRINT, $3, $5, NULL, NULL); }  // Existing formatted print
  | PRINT '(' vyraz ')' ';'         { $$ = GenUzel(PRINT, $3, NULL, NULL, NULL); }  // For numbers/variables
  | SCAN '(' PROMENNA ')' ';'       { $$ = GenUzel(SCAN, $3, NULL, NULL, NULL); }
  | '{' prikaz_list '}'             { $$ = $2; }
  | IF '(' vyraz ')' prikaz         %prec IF { $$ = GenUzel(IF, $3, $5, NULL, NULL); }
  | IF '(' vyraz ')' prikaz ELSE prikaz { $$ = GenUzel(IF, $3, $5, $7, NULL); }
  | FOR '(' vyraz ';' vyraz ';' vyraz ')' prikaz { $$ = GenUzel(FOR, $3, $5, $7, $9); }
  | WHILE '(' vyraz ')' prikaz      { $$ = GenUzel(WHILE, $3, $5, NULL, NULL); }
  | DO prikaz WHILE '(' vyraz ')' ';' { $$ = GenUzel(DO, $2, $5, NULL, NULL); }
  | ';'                            { $$ = NULL; }  // Prázdný příkaz

  ;

prikaz_list:
    /* empty */                     { $$ = NULL; }
  | prikaz prikaz_list              { $$ = GenUzel(0, $1, $2, NULL, NULL); }
  ;

vyraz:
    CISLO                           { $$ = $1; }
  | PROMENNA                        { $$ = $1; }
  | vyraz '=' vyraz                 { $$ = GenUzel('=', $1, $3, NULL, NULL); }
  | vyraz ADD_ASSIGN vyraz          { $$ = GenUzel(ADD_ASSIGN, $1, $3, NULL, NULL); }
  | vyraz SUB_ASSIGN vyraz          { $$ = GenUzel(SUB_ASSIGN, $1, $3, NULL, NULL); }
  | vyraz MUL_ASSIGN vyraz          { $$ = GenUzel(MUL_ASSIGN, $1, $3, NULL, NULL); }
  | vyraz DIV_ASSIGN vyraz          { $$ = GenUzel(DIV_ASSIGN, $1, $3, NULL, NULL); }
  | vyraz MOD_ASSIGN vyraz          { $$ = GenUzel(MOD_ASSIGN, $1, $3, NULL, NULL); }
  | vyraz SHL_ASSIGN vyraz          { $$ = GenUzel(SHL_ASSIGN, $1, $3, NULL, NULL); }
  | vyraz SHR_ASSIGN vyraz          { $$ = GenUzel(SHR_ASSIGN, $1, $3, NULL, NULL); }
  | vyraz AND_ASSIGN vyraz          { $$ = GenUzel(AND_ASSIGN, $1, $3, NULL, NULL); }
  | vyraz XOR_ASSIGN vyraz          { $$ = GenUzel(XOR_ASSIGN, $1, $3, NULL, NULL); }
  | vyraz OR_ASSIGN vyraz           { $$ = GenUzel(OR_ASSIGN, $1, $3, NULL, NULL); }
  | vyraz '+' vyraz                 { $$ = GenUzel('+', $1, $3, NULL, NULL); }
  | vyraz '-' vyraz                 { $$ = GenUzel('-', $1, $3, NULL, NULL); }
  | vyraz '*' vyraz                 { $$ = GenUzel('*', $1, $3, NULL, NULL); }
  | vyraz '/' vyraz                 { $$ = GenUzel('/', $1, $3, NULL, NULL); }
  | vyraz MOD vyraz                 { $$ = GenUzel(MOD, $1, $3, NULL, NULL); }
  | vyraz SHL vyraz                 { $$ = GenUzel(SHL, $1, $3, NULL, NULL); }
  | vyraz SHR vyraz                 { $$ = GenUzel(SHR, $1, $3, NULL, NULL); }
  | vyraz BIT_AND vyraz             { $$ = GenUzel(BIT_AND, $1, $3, NULL, NULL); }
  | vyraz BIT_OR vyraz              { $$ = GenUzel(BIT_OR, $1, $3, NULL, NULL); }
  | vyraz BIT_XOR vyraz             { $$ = GenUzel(BIT_XOR, $1, $3, NULL, NULL); }
  | vyraz AND vyraz                 { $$ = GenUzel(AND, $1, $3, NULL, NULL); }
  | vyraz OR vyraz                  { $$ = GenUzel(OR, $1, $3, NULL, NULL); }
  | '<' vyraz                       { $$ = GenUzel('<', $2, NULL, NULL, NULL); }
  | '>' vyraz                       { $$ = GenUzel('>', $2, NULL, NULL, NULL); }
  | POROVNANI vyraz                 { $$ = GenUzel(POROVNANI, $2, NULL, NULL, NULL); }
  | NENIROVNO vyraz                 { $$ = GenUzel(NENIROVNO, $2, NULL, NULL, NULL); }
  | MENSIROVNO vyraz                { $$ = GenUzel(MENSIROVNO, $2, NULL, NULL, NULL); }
  | VETSIROVNO vyraz                { $$ = GenUzel(VETSIROVNO, $2, NULL, NULL, NULL); }
  | '-' vyraz %prec UMINUS          { $$ = GenUzel(UMINUS, $2, NULL, NULL, NULL); }
  | BIT_NOT vyraz                   { $$ = GenUzel(BIT_NOT, $2, NULL, NULL, NULL); }
  | INKREM PROMENNA                 { $$ = GenUzel(INKREM, $2, NULL, NULL, NULL); }
  | PROMENNA INKREM                 { $$ = GenUzel(INKREM, NULL, $1, NULL, NULL); }
  | PROMENNA DEKREM                 { $$ = GenUzel(DEKREM, NULL, $1, NULL, NULL); }
  | '(' vyraz ')'                   { $$ = $2; }
 // | vyraz TERNARY_QUEST vyraz TERNARY_COLON vyraz { $$ = GenUzel(TERNARY, $1, $3, $5, NULL); }
  | vyraz COMMA vyraz               { $$ = GenUzel(COMMA, $1, $3, NULL, NULL); }
  ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Chyba (Řádek %d, Sloupec %d): %s\n", Radek, Sloupec, s);
    Chyby = true;
}
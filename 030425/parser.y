%{
#include "ast.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

extern FILE *yyin;
%}

%define api.pure full
%define parse.error verbose
%locations
%expect 1

%union {
    int num;
    char *str;
    struct Uzel *node;
}

%code requires {
    // Declare YYSTYPE/YYLTYPE early
    typedef union YYSTYPE YYSTYPE;
    typedef struct YYLTYPE YYLTYPE;
    extern int yylex(YYSTYPE*, YYLTYPE*);
}

%token <num> CONST
%token <str> ID STRING
%token IF ELSE FOR WHILE DO PRINT SCAN INC DEC NOT AND OR
%token LSHIFT RSHIFT EQ NEQ LE GE

%type <node> program prikaz vyraz blok prikazy

%code provides {
    void yyerror(YYLTYPE *loc, const char *s);
}

%precedence '='
%right OR
%left AND
%left '|'
%left '^'
%left '&'
%left EQ NEQ
%left '<' '>' LE GE
%left LSHIFT RSHIFT
%left '+' '-'
%left '*' '/' '%'
%right NOT INC DEC

%start program

%%

program: prikaz { $$ = $1; };

prikaz:
    vyraz ';'          { $$ = $1; }
  | blok               { $$ = $1; }
  | IF '(' vyraz ')' prikaz          { $$ = GenUzel(IF_NODE, $3, $5, NULL, NULL); }
  | IF '(' vyraz ')' prikaz ELSE prikaz { $$ = GenUzel(IF_ELSE_NODE, $3, $5, $7, NULL); }
  | FOR '(' vyraz ';' vyraz ';' vyraz ')' prikaz { $$ = GenUzel(FOR_NODE, $3, $5, $7, $9); }
  | WHILE '(' vyraz ')' prikaz       { $$ = GenUzel(WHILE_NODE, $3, $5, NULL, NULL); }
  | DO prikaz WHILE '(' vyraz ')' ';' { $$ = GenUzel(DO_WHILE_NODE, $2, $5, NULL, NULL); }
  | PRINT '(' STRING ')' ';'         { $$ = GenRetez($3); }
  | PRINT '(' STRING ',' vyraz ')' ';' { $$ = GenUzel(PRINT_FORMAT_NODE, GenRetez($3), $5, NULL, NULL); }
  | PRINT '(' vyraz ')' ';'         { $$ = GenUzel(PRINT_NODE, $3, NULL, NULL, NULL); }
  | SCAN '(' ID ')' ';'             { $$ = GenPromen($3); }
  ;

blok:
    '{' prikazy '}'    { $$ = $2; }
  ;

prikazy:
    prikazy prikaz     { $$ = GenUzel(BLOCK_NODE, $1, $2, NULL, NULL); }
  | prikaz             { $$ = $1; }
  ;

vyraz:
    ID '=' vyraz       { $$ = GenUzel(ASSIGN_NODE, GenPromen($1), $3, NULL, NULL); }
  | vyraz '+' vyraz    { $$ = GenUzel(ADD_NODE, $1, $3, NULL, NULL); }
  | vyraz '*' vyraz    { $$ = GenUzel(MUL_NODE, $1, $3, NULL, NULL); }
  | INC ID             { $$ = GenUzel(PRE_INC_NODE, GenPromen($2), NULL, NULL, NULL); }
  | ID INC             { $$ = GenUzel(POST_INC_NODE, GenPromen($1), NULL, NULL, NULL); }
  | CONST              { $$ = GenCislo($1); }
  | ID                 { $$ = GenPromen($1); }
  ;

%%

void yyerror(YYLTYPE *loc, const char *s) {
    fprintf(stderr, "%d.%d: error: %s\n", loc->first_line, loc->first_column, s);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        return 1;
    }
    yyin = fopen(argv[1], "r");
    if (!yyin) {
        perror("Failed to open input file");
        return 1;
    }
    yyparse();
    fclose(yyin);
    return 0;
}
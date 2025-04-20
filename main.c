#include "ast.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

Uzel *Koren = NULL;
unsigned Radek = 1, Sloupec = 1;
bool Chyby = false;
extern FILE *yyin;

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Použití: %s <vstupni_soubor>\n", argv[0]);
        return 1;
    }

    yyin = fopen(argv[1], "r");
    if (!yyin) {
        perror("Chyba při otevírání souboru");
        return 1;
    }

    yyparse();
    fclose(yyin);

    if (!Chyby && Koren) Interpr(Koren);
    return 0;
}
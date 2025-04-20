#ifndef AST_H
#define AST_H

#include <stdbool.h>
#include "parser.tab.h"

typedef struct Uzel {
    int Typ;
    union {
        struct { struct Uzel *prvni, *druhy, *treti, *ctvrty; } z;
        int Cislo;
        char *Retez;
        int *Adresa;
    };
} Uzel;

Uzel *GenUzel(int typ, Uzel *p1, Uzel *p2, Uzel *p3, Uzel *p4);
Uzel *GenCislo(int hodnota);
Uzel *GenRetez(const char *retez);
Uzel *GenPromen(const char *jmeno);

#endif
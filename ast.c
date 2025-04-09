#include "ast.h"
#include <stdlib.h>
#include <string.h>

Uzel* GenUzel(NodeType typ, Uzel *p1, Uzel *p2, Uzel *p3, Uzel *p4) {
    Uzel *node = (Uzel*)malloc(sizeof(Uzel));
    node->Typ = typ;
    node->prvni = p1;
    node->druhy = p2;
    node->treti = p3;
    node->ctvrty = p4;
    return node;
}

Uzel* GenCislo(int hodnota) {
    Uzel *node = (Uzel*)malloc(sizeof(Uzel));
    node->Typ = CONST_NODE;
    node->Cislo = hodnota;
    return node;
}

Uzel* GenRetez(const char *retez) {
    Uzel *node = (Uzel*)malloc(sizeof(Uzel));
    node->Typ = PRINT_NODE;
    node->Retez = strdup(retez);
    return node;
}

Uzel* GenPromen(const char *jmeno) {
    Uzel *node = (Uzel*)malloc(sizeof(Uzel));
    node->Typ = VAR_NODE;
    node->Promen = strdup(jmeno);
    return node;
}
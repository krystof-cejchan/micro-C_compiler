#include "ast.h"
#include <stdlib.h>
#include <string.h>
#include "uthash.h"


typedef struct {
    char *jmeno;
    int *adresa;
    UT_hash_handle hh;
} Promenna;

static Promenna *promenne = NULL;

Uzel *GenUzel(int typ, Uzel *p1, Uzel *p2, Uzel *p3, Uzel *p4) {
    Uzel *u = malloc(sizeof(Uzel));
    u->Typ = typ;
    u->z.prvni = p1;
    u->z.druhy = p2;
    u->z.treti = p3;
    u->z.ctvrty = p4;
    return u;
}

Uzel *GenCislo(int hodnota) {
    Uzel *u = malloc(sizeof(Uzel));
    u->Typ = CISLO;
    u->Cislo = hodnota;
    return u;
}

Uzel *GenRetez(const char *retez) {
    Uzel *u = malloc(sizeof(Uzel));
    u->Typ = RETEZ;
    u->Retez = strdup(retez);
    return u;
}

Uzel *GenPromen(const char *jmeno) {
    Promenna *p;
    HASH_FIND_STR(promenne, jmeno, p);
    if (!p) {
        p = malloc(sizeof(Promenna));
        p->jmeno = strdup(jmeno);
        p->adresa = malloc(sizeof(int));
        *p->adresa = 0;
        HASH_ADD_KEYPTR(hh, promenne, p->jmeno, strlen(p->jmeno), p);
    }
    Uzel *u = malloc(sizeof(Uzel));
    u->Typ = PROMENNA;
    u->Adresa = p->adresa;
    return u;
}
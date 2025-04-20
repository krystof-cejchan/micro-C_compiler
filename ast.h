#ifndef AST_H
#define AST_H

typedef struct Uzel {
    int Typ;
    union {
        struct { struct Uzel *prvni, *druhy, *treti, *ctvrty; } z;
        int Cislo;
        char *Retez;
        int *Adresa;
    };
} Uzel;

// Tokeny
#define PRINT 1000
#define SCAN 1001
#define IF 1002
#define ELSE 1003
#define FOR 1004
#define WHILE 1005
#define DO 1006
#define MOD 1007
#define AND 1008
#define OR 1009
#define NOT 1010
#define SHL 1011
#define SHR 1012
#define POROVNANI 1013
#define NENIROVNO 1014
#define MENSIROVNO 1015
#define VETSIROVNO 1016
#define BIT_AND 1017
#define BIT_OR 1018
#define BIT_XOR 1019
#define INKREM 1020
#define DEKREM 1021
#define TERNARY 1022
#define COMMA 1023
#define UMINUS 1024

Uzel *GenUzel(int typ, Uzel *p1, Uzel *p2, Uzel *p3, Uzel *p4);
Uzel *GenCislo(int hodnota);
Uzel *GenRetez(const char *retez);
Uzel *GenPromen(const char *jmeno);

#endif
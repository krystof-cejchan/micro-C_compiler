#ifndef MikroC_h
#define MikroC_h

typedef struct Uzel {
    int Typ;
    union {
        struct {
            struct Uzel *prvni, *druhy, *treti, *ctvrty;
        } z_uzel;  // Přejmenováno z "z"
        int Cislo;
        const char *Retez;
        int *Adresa;
    } z;
} Uzel;

typedef enum Pozice { BEZPOZICE, RADEK, SLOUPEC } Pozice;

// Deklarace funkcí s parametry
Uzel *GenUzel(int typ, Uzel *p1, Uzel *p2, Uzel *p3, Uzel *p4);
Uzel *GenCislo(int hodnota);
Uzel *GenRetez(const char *text);
Uzel *GenPromen(const char *nazev);

#define TABSIZE 4

typedef union YYSTYPE {
    int c;
    const char *r;
    Uzel *u;
} YYSTYPE;

#define YYSTYPE_IS_DECLARED

void Chyba(const char *msg, Pozice poz);
void LexInit();
void Flush();

#include "MikroC.tab.hpp"

#endif
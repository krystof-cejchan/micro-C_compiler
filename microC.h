#ifndef  microC_h
#define  microC_h

struct Uzel { int Typ;
              union { struct { Uzel *prvni,*druhy,*treti,*ctvrty; } z;
                      int Cislo;
                      const char *Retez;
                      int *Adresa; } z; };

Uzel *GenUzel(int,Uzel * =0,Uzel * =0,Uzel * =0,Uzel * =0);
Uzel *GenCislo(int);
Uzel *GenRetez(const char *);
Uzel *GenPromen(const char *);

#define  TABSIZE  4

union YYSTYPE { int c; const char *r; Uzel *u; };

#define  YYSTYPE_IS_DECLARED

enum Pozice { BEZPOZICE,RADEK,SLOUPEC };

void Chyba(const char *, Pozice=SLOUPEC);

void LexInit();

void Flush();

#include "microC.tab.h"

#endif
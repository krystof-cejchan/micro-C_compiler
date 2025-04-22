#include <stdio.h>
#include <stdlib.h>
#include "MikroC.h"

void Abort() {
    printf("\nChyba během interpretace!\n");
    exit(1);
}

int Interpr(Uzel *u) {
    if (!u) return 0;

    // Makra pro přístup k dětem
    #define prvni  u->z.z_uzel.prvni  // Opraveno na z_uzel
    #define druhy  u->z.z_uzel.druhy
    #define treti  u->z.z_uzel.treti
    #define ctvrty u->z.z_uzel.ctvrty

    switch (u->Typ) {
        case '=': return *prvni->z.Adresa = Interpr(druhy);
        case P_PRICT: return *prvni->z.Adresa += Interpr(druhy);
        case P_ODECT: return *prvni->z.Adresa -= Interpr(druhy);
        case P_NASOB: return *prvni->z.Adresa *= Interpr(druhy);
        case P_DELEN: {
            int d = Interpr(druhy);
            if (d == 0) Abort();
            return *prvni->z.Adresa /= d;
        }
        case P_MODUL: return *prvni->z.Adresa %= Interpr(druhy);
        case P_POSUNVLEVO: return *prvni->z.Adresa <<= Interpr(druhy);
        case P_POSUNVPRAVO: return *prvni->z.Adresa >>= Interpr(druhy);
        case P_AND: return *prvni->z.Adresa &= Interpr(druhy);
        case P_XOR: return *prvni->z.Adresa ^= Interpr(druhy);
        case P_OR: return *prvni->z.Adresa |= Interpr(druhy);
        case PLUS: return Interpr(prvni) + Interpr(druhy);
        case MINUS: return druhy ? Interpr(prvni) - Interpr(druhy) : -Interpr(prvni);
        case '*': return Interpr(prvni) * Interpr(druhy);
        case '/': {
            int d = Interpr(druhy);
            if (d == 0) Abort();
            return Interpr(prvni) / d;
        }
        case POSUNVLEVO: return Interpr(prvni) << Interpr(druhy);
        case POSUNVPRAVO: return Interpr(prvni) >> Interpr(druhy);
        case '&': return Interpr(prvni) & Interpr(druhy);
        case '|': return Interpr(prvni) | Interpr(druhy);
        case '^': return Interpr(prvni) ^ Interpr(druhy);
        case '~': return ~Interpr(prvni);
        case AND: return Interpr(prvni) && Interpr(druhy);
        case OR: return Interpr(prvni) || Interpr(druhy);
        case NOT: return !Interpr(prvni);
        case '<': return Interpr(prvni) < Interpr(druhy);
        case '>': return Interpr(prvni) > Interpr(druhy);
        case ROVNO: return Interpr(prvni) == Interpr(druhy);
        case NENIROVNO: return Interpr(prvni) != Interpr(druhy);
        case MENSIROVNO: return Interpr(prvni) <= Interpr(druhy);
        case VETSIROVNO: return Interpr(prvni) >= Interpr(druhy);
        case PRINT:
            if (prvni->Typ == RETEZ) printf("%s", prvni->z.Retez);
            else printf("%d", Interpr(prvni));
            return 0;
        case SCAN:
            scanf("%d", prvni->z.Adresa);
            return 0;
        case IF:
            if (Interpr(prvni)) Interpr(druhy);
            else if (treti) Interpr(treti);
            return 0;
        case FOR:
            Interpr(prvni);
            while (Interpr(druhy)) {
                Interpr(ctvrty);
                Interpr(treti);
            }
            return 0;
        case WHILE:
            while (Interpr(prvni)) Interpr(druhy);
            return 0;
        case DO:
            do { Interpr(prvni); } while (Interpr(druhy));
            return 0;
        case INKREM:
            return (prvni) ? ++(*prvni->z.Adresa) : (*druhy->z.Adresa)++;
        case DEKREM:
            return (prvni) ? --(*prvni->z.Adresa) : (*druhy->z.Adresa)--;
        case CISLO: return u->z.Cislo;  // Opraveno na z.Cislo
        case PROMENNA: return *u->z.Adresa;  // Opraveno na z.Adresa
        case 0:
            Interpr(prvni); Interpr(druhy); Interpr(treti); Interpr(ctvrty);
            return 0;
        default:
            printf("Neznámý uzel: %d\n", u->Typ);
            Abort();
            return 0;
    }
}
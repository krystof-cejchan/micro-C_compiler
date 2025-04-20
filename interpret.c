#include "ast.h"
#include <stdio.h>
#include <stdlib.h>

void Abort() {
    printf("\nChyba během interpretace!\n");
    exit(1);
}

int Interpr(Uzel *u) {
    if (!u) return 0;

    #define prvni u->z.z.prvni
    #define druhy u->z.z.druhy
    #define treti u->z.z.treti
    #define ctvrty u->z.z.ctvrty

    switch (u->Typ) {
        case '=': return *prvni->Adresa = Interpr(druhy);
        case ADD_ASSIGN: return *prvni->Adresa += Interpr(druhy);
        case SUB_ASSIGN: return *prvni->Adresa -= Interpr(druhy);
        case MUL_ASSIGN: return *prvni->Adresa *= Interpr(druhy);
        case DIV_ASSIGN: {
            int d = Interpr(druhy);
            if (d == 0) Abort();
            return *prvni->Adresa /= d;
        }
        case MOD_ASSIGN: return *prvni->Adresa %= Interpr(druhy);
        case SHL_ASSIGN: return *prvni->Adresa <<= Interpr(druhy);
        case SHR_ASSIGN: return *prvni->Adresa >>= Interpr(druhy);
        case AND_ASSIGN: return *prvni->Adresa &= Interpr(druhy);
        case XOR_ASSIGN: return *prvni->Adresa ^= Interpr(druhy);
        case OR_ASSIGN: return *prvni->Adresa |= Interpr(druhy);
        case '+': return Interpr(prvni) + Interpr(druhy);
        case '-': return druhy ? Interpr(prvni) - Interpr(druhy) : -Interpr(prvni);
        case '*': return Interpr(prvni) * Interpr(druhy);
        case '/': {
            int d = Interpr(druhy);
            if (d == 0) Abort();
            return Interpr(prvni) / d;
        }
        case MOD: return Interpr(prvni) % Interpr(druhy);
        case SHL: return Interpr(prvni) << Interpr(druhy);
        case SHR: return Interpr(prvni) >> Interpr(druhy);
        case BIT_AND: return Interpr(prvni) & Interpr(druhy);
        case BIT_OR: return Interpr(prvni) | Interpr(druhy);
        case BIT_XOR: return Interpr(prvni) ^ Interpr(druhy);
        case BIT_NOT: return ~Interpr(prvni);
        case AND: return Interpr(prvni) && Interpr(druhy);
        case OR: return Interpr(prvni) || Interpr(druhy);
        case NOT: return !Interpr(prvni);
        case '<': return Interpr(prvni) < Interpr(druhy);
        case '>': return Interpr(prvni) > Interpr(druhy);
        case POROVNANI: return Interpr(prvni) == Interpr(druhy);
        case NENIROVNO: return Interpr(prvni) != Interpr(druhy);
        case MENSIROVNO: return Interpr(prvni) <= Interpr(druhy);
        case VETSIROVNO: return Interpr(prvni) >= Interpr(druhy);
        case PRINT:
            if (prvni->Typ == RETEZ) printf("%s", prvni->Retez);
            else printf("%d", Interpr(prvni));
            return 0;
        case SCAN:
            scanf("%d", prvni->Adresa);
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
            return (prvni) ? ++(*prvni->Adresa) : (*druhy->Adresa)++;
        case TERNARY:
            return Interpr(Interpr(prvni) ? druhy : treti);
        case COMMA:
            Interpr(prvni);
            return Interpr(druhy);
        case CISLO: return u->Cislo;
        case PROMENNA: return *u->Adresa;
        case 0:
            Interpr(prvni); Interpr(druhy); Interpr(treti); Interpr(ctvrty);
            return 0;
        default:
            printf("Neznámý uzel: %d\n", u->Typ);
            Abort();
            return 0;
    }
}
#ifndef MIKROC_H
#define MIKROC_H

typedef enum {
    CONST_NODE, VAR_NODE, ADD_NODE, MUL_NODE, ASSIGN_NODE,
    IF_NODE, IF_ELSE_NODE, FOR_NODE, WHILE_NODE, DO_WHILE_NODE,
    PRINT_NODE, PRINT_FORMAT_NODE, PRE_INC_NODE, POST_INC_NODE,
    BLOCK_NODE
} NodeType;

typedef struct Uzel {
    NodeType Typ;
    union {
        struct { struct Uzel *prvni, *druhy, *treti, *ctvrty; };
        int Cislo;
        char *Retez;
        char *Promen;
    };
} Uzel;

Uzel* GenUzel(NodeType typ, Uzel *p1, Uzel *p2, Uzel *p3, Uzel *p4);
Uzel* GenCislo(int hodnota);
Uzel* GenRetez(const char *retez);
Uzel* GenPromen(const char *jmeno);

#endif
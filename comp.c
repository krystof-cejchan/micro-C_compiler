#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* -------------------- DATOVÉ STRUKTURY -------------------- */

/* Tokeny */
typedef enum {
    T_INT, T_RETURN, T_IF, T_ELSE, T_WHILE, T_READ, T_WRITE,
    T_ID, T_NUM,
    T_EQ, T_NEQ,
    T_LT, T_GT, T_LE, T_GE,
    T_ASSIGN, // '='
    T_PLUS, T_MINUS, T_STAR,
    T_LPAREN, T_RPAREN,
    T_LBRACE, T_RBRACE,
    T_SEMI,    // ';'
    T_MAIN,
    T_EOF,
    // Speciální token pro chybu
    T_ERR
} TokenType;

/* Struktura tokenu */
typedef struct {
    TokenType type;
    char text[256];  // pro ID nebo číslo
    int value;       // pokud je to T_NUM, můžeme si ukládat číselnou hodnotu
    int line;
} Token;

/* Seznam proměnných v lokální tabulce */
typedef struct Var {
    char name[256];
    int offset;            // posun na zásobníku (v bajtech) - záporná hodnota oproti EBP
    struct Var *next;
} Var;

/* AST uzly: Pro jednoduchost máme jeden typ uzlu s unionem pro detaily */
typedef enum {
    ND_BLOCK,
    ND_DECL,
    ND_ASSIGN,
    ND_IF,
    ND_WHILE,
    ND_READ,
    ND_WRITE,
    ND_RETURN,
    ND_BINOP,   // +, -, *, ==, !=, <, <=, >, >=
    ND_VAR,
    ND_NUM
} NodeType;

typedef struct AST {
    NodeType nodetype;
    struct AST *left;
    struct AST *right;
    struct AST *extra;     // Např. else větev pro if, atd.
    
    char varname[256];
    int  value;            // pro ND_NUM
    // typ binární operace (např. T_PLUS, T_MINUS...)
    TokenType op;
    
    // Pro ND_BLOCK:
    //   uložíme jednosměrně propojený list příkazů
    struct AST *nextstmt;
} AST;

/* -------------------- GLOBÁLNÍ PROMĚNNÉ PRO SCANNER -------------------- */

static FILE *f;           // soubor se vstupním kódem
static int   currentLine = 1;
static Token currentToken;

/* Pro jednoduchost budeme držet znak v paměti */
int peekChar = -1;

/* -------------------- LEXIKÁLNÍ ANALYZÁTOR -------------------- */

int nextChar() {
    if(peekChar != -1) {
        int c = peekChar;
        peekChar = -1;
        return c;
    }
    return fgetc(f);
}

void ungetChar(int c) {
    peekChar = c;
}

/* Pomocná funkce pro rozpoznání klíčového slova */
TokenType checkKeyword(const char *text) {
    if(strcmp(text, "int")   == 0) return T_INT;
    if(strcmp(text, "return")== 0) return T_RETURN;
    if(strcmp(text, "if")    == 0) return T_IF;
    if(strcmp(text, "else")  == 0) return T_ELSE;
    if(strcmp(text, "while") == 0) return T_WHILE;
    if(strcmp(text, "read")  == 0) return T_READ;
    if(strcmp(text, "write") == 0) return T_WRITE;
    if(strcmp(text, "main")  == 0) return T_MAIN;
    return T_ID;
}

Token getToken() {
    Token t;
    t.type = T_ERR;
    t.text[0] = '\0';
    t.value = 0;
    t.line  = currentLine;
    
    int c;

    // Přeskoč mezery a komentáře
    while(1) {
        c = nextChar();
        if(c == ' ' || c == '\t' || c == '\r') {
            continue;
        } else if(c == '\n') {
            currentLine++;
        } else if(c == '/') {
            // Může jít o komentář typu //...
            int nxt = nextChar();
            if(nxt == '/') {
                // komentář do konce řádku
                while((c = nextChar()) != '\n' && c != EOF && c != -1) {}
                if(c == '\n') currentLine++;
                continue; // a zkusit znovu
            } else {
                // není to komentář, vrátíme nxt
                ungetChar(nxt);
                // vrátíme lomítko jako T_STAR? Ne, v naší subset gramatice
                // s lomítkem nepočítáme, ale pro rozšíření by se tu dalo řešit dělení.
                t.type = T_ERR; 
                strcpy(t.text, "/ (není podporováno)");
                return t;
            }
        } else {
            break;
        }
    }

    // Konec souboru?
    if(c == EOF || c == -1) {
        t.type = T_EOF;
        strcpy(t.text, "EOF");
        return t;
    }

    // Identifikátor nebo klíčové slovo
    if(isalpha(c) || c == '_') {
        int i = 0;
        t.text[i++] = c;
        while(1) {
            c = nextChar();
            if(isalnum(c) || c == '_') {
                if(i < 255) {
                    t.text[i++] = c;
                }
            } else {
                ungetChar(c);
                break;
            }
        }
        t.text[i] = '\0';
        t.type = checkKeyword(t.text);
        return t;
    }

    // Číslo
    if(isdigit(c)) {
        int i = 0;
        int val = (c - '0');
        while(1) {
            c = nextChar();
            if(isdigit(c)) {
                val = val * 10 + (c - '0');
            } else {
                ungetChar(c);
                break;
            }
        }
        t.type  = T_NUM;
        t.value = val;
        sprintf(t.text, "%d", val);
        return t;
    }

    // Speciální znaky a operátory
    switch(c) {
        case '=': {
            int nxt = nextChar();
            if(nxt == '=') {
                t.type = T_EQ;
                strcpy(t.text, "==");
            } else {
                ungetChar(nxt);
                t.type = T_ASSIGN;
                strcpy(t.text, "=");
            }
            return t;
        }
        case '!': {
            int nxt = nextChar();
            if(nxt == '=') {
                t.type = T_NEQ;
                strcpy(t.text, "!=");
                return t;
            } else {
                // v jazyce C by to byl logický operátor !, ale tady ho nepodporujeme
                ungetChar(nxt);
                t.type = T_ERR;
                strcpy(t.text, "!");
                return t;
            }
        }
        case '<': {
            int nxt = nextChar();
            if(nxt == '=') {
                t.type = T_LE;
                strcpy(t.text, "<=");
            } else {
                ungetChar(nxt);
                t.type = T_LT;
                strcpy(t.text, "<");
            }
            return t;
        }
        case '>': {
            int nxt = nextChar();
            if(nxt == '=') {
                t.type = T_GE;
                strcpy(t.text, ">=");
            } else {
                ungetChar(nxt);
                t.type = T_GT;
                strcpy(t.text, ">");
            }
            return t;
        }
        case '+':
            t.type = T_PLUS; strcpy(t.text, "+"); return t;
        case '-':
            t.type = T_MINUS; strcpy(t.text, "-"); return t;
        case '*':
            t.type = T_STAR; strcpy(t.text, "*"); return t;
        case '(':
            t.type = T_LPAREN; strcpy(t.text, "("); return t;
        case ')':
            t.type = T_RPAREN; strcpy(t.text, ")"); return t;
        case '{':
            t.type = T_LBRACE; strcpy(t.text, "{"); return t;
        case '}':
            t.type = T_RBRACE; strcpy(t.text, "}"); return t;
        case ';':
            t.type = T_SEMI; strcpy(t.text, ";"); return t;
        default:
            t.type = T_ERR;
            sprintf(t.text, "Neocekavany znak '%c'", c);
            return t;
    }
}

/* F-ce pro načtení dalšího tokenu a uložení do currentToken */
void nextToken() {
    currentToken = getToken();
}

/* -------------------- POMOCNÉ FUNKCE PARSERU -------------------- */

void error(const char *msg) {
    fprintf(stderr, "CHYBA na radku %d: %s (token: %s)\n",
            currentToken.line, msg, currentToken.text);
    exit(1);
}

void match(TokenType expected) {
    if(currentToken.type == expected) {
        nextToken();
    } else {
        char buf[256];
        sprintf(buf, "Ocekavan token '%d', nalezen '%s'", expected, currentToken.text);
        error(buf);
    }
}

/* -------------------- PARSER: FORWARD DECLARACE -------------------- */

AST* parseProgram();
AST* parseBlock();
AST* parseDeclOrStmt();
AST* parseStatement();
AST* parseDeclaration();
AST* parseAssignment();
AST* parseIf();
AST* parseWhile();
AST* parseRead();
AST* parseWrite();
AST* parseReturn();
AST* parseExpr();
AST* parseEqualityExpr();
AST* parseComparisonExpr();
AST* parseTerm();
AST* parseFactor();
AST* parseFactor2();

/* Vytvoření uzlu AST */
AST* newAST(NodeType nt) {
    AST* node = (AST*)calloc(1, sizeof(AST));
    node->nodetype = nt;
    node->left = NULL;
    node->right = NULL;
    node->extra = NULL;
    node->nextstmt = NULL;
    node->varname[0] = '\0';
    node->value = 0;
    node->op = T_ERR;
    return node;
}

/* -------------------- PARSER: IMPLEMENTACE -------------------- */

/* program -> "int" "main" "(" ")" "{" decls statements "}" */
AST* parseProgram() {
    match(T_INT);
    match(T_MAIN);
    match(T_LPAREN);
    match(T_RPAREN);
    match(T_LBRACE);

    // Deklarace
    AST *firstDecl = NULL;
    AST *lastDecl  = NULL;

    while(currentToken.type == T_INT) {
        AST *decl = parseDeclaration();
        if(!firstDecl) {
            firstDecl = decl;
            lastDecl  = decl;
        } else {
            lastDecl->nextstmt = decl;
            lastDecl = decl;
        }
    }

    // Tělo
    AST *firstStmt = NULL;
    AST *lastStmt  = NULL;

    while(currentToken.type != T_RBRACE && currentToken.type != T_EOF) {
        AST *st = parseStatement();
        if(!firstStmt) {
            firstStmt = st;
            lastStmt  = st;
        } else {
            lastStmt->nextstmt = st;
            lastStmt = st;
        }
    }
    match(T_RBRACE);

    // Vytvoříme blok, kde je seznam deklarací a příkazů
    AST* block = newAST(ND_BLOCK);
    // Uložíme deklarace do block->left, příkazy do block->right
    block->left = firstDecl;
    block->right = firstStmt;

    return block;
}

/* declaration -> "int" ID ";" */
AST* parseDeclaration() {
    match(T_INT);
    if(currentToken.type != T_ID) {
        error("Ocekavan identifikator v deklaraci");
    }
    AST* decl = newAST(ND_DECL);
    strcpy(decl->varname, currentToken.text);
    nextToken();
    match(T_SEMI);
    return decl;
}

/* statement -> assignment | ifStatement | whileStatement
               | readStatement | writeStatement | returnStatement
               | blockStatement
*/
AST* parseStatement() {
    switch(currentToken.type) {
        case T_ID:
            return parseAssignment();
        case T_IF:
            return parseIf();
        case T_WHILE:
            return parseWhile();
        case T_READ:
            return parseRead();
        case T_WRITE:
            return parseWrite();
        case T_RETURN:
            return parseReturn();
        case T_LBRACE: {
            // blok
            AST *b = newAST(ND_BLOCK);
            match(T_LBRACE);

            AST *firstStmt = NULL;
            AST *lastStmt = NULL;
            // parse statements until '}'
            while(currentToken.type != T_RBRACE && currentToken.type != T_EOF) {
                AST *st = parseStatement();
                if(!firstStmt) {
                    firstStmt = st;
                    lastStmt  = st;
                } else {
                    lastStmt->nextstmt = st;
                    lastStmt = st;
                }
            }
            match(T_RBRACE);
            b->right = firstStmt; 
            return b;
        }
        default:
            error("Neznamy statement");
            return NULL; // unreachable
    }
}

/* assignment -> ID "=" expr ";" */
AST* parseAssignment() {
    AST* node = newAST(ND_ASSIGN);
    strcpy(node->varname, currentToken.text);
    match(T_ID);
    match(T_ASSIGN);
    node->left = parseExpr();
    match(T_SEMI);
    return node;
}

/* ifStatement -> "if" "(" expr ")" statement [ "else" statement ] */
AST* parseIf() {
    AST* node = newAST(ND_IF);
    match(T_IF);
    match(T_LPAREN);
    node->left = parseExpr(); // podmínka
    match(T_RPAREN);
    node->right = parseStatement(); // if větev
    if(currentToken.type == T_ELSE) {
        match(T_ELSE);
        node->extra = parseStatement(); // else větev
    }
    return node;
}

/* whileStatement -> "while" "(" expr ")" statement */
AST* parseWhile() {
    AST* node = newAST(ND_WHILE);
    match(T_WHILE);
    match(T_LPAREN);
    node->left = parseExpr(); // podmínka
    match(T_RPAREN);
    node->right = parseStatement(); // tělo
    return node;
}

/* readStatement -> "read" ID ";" */
AST* parseRead() {
    AST* node = newAST(ND_READ);
    match(T_READ);
    if(currentToken.type != T_ID) {
        error("Ocekavan identifikator po 'read'");
    }
    strcpy(node->varname, currentToken.text);
    nextToken();
    match(T_SEMI);
    return node;
}

/* writeStatement -> "write" expr ";" */
AST* parseWrite() {
    AST* node = newAST(ND_WRITE);
    match(T_WRITE);
    node->left = parseExpr();
    match(T_SEMI);
    return node;
}

/* returnStatement -> "return" expr ";" */
AST* parseReturn() {
    AST* node = newAST(ND_RETURN);
    match(T_RETURN);
    node->left = parseExpr();
    match(T_SEMI);
    return node;
}

/* expr -> equalityExpr */
AST* parseExpr() {
    return parseEqualityExpr();
}

/* equalityExpr -> comparisonExpr ( ( "==" | "!=" ) comparisonExpr )? */
AST* parseEqualityExpr() {
    AST* left = parseComparisonExpr();
    while(currentToken.type == T_EQ || currentToken.type == T_NEQ) {
        AST* node = newAST(ND_BINOP);
        node->op = currentToken.type;
        match(currentToken.type);
        node->left = left;
        node->right = parseComparisonExpr();
        left = node;
    }
    return left;
}

/* comparisonExpr -> term ( ( "<" | ">" | "<=" | ">=" ) term )? */
AST* parseComparisonExpr() {
    AST* left = parseTerm();
    while(currentToken.type == T_LT || currentToken.type == T_GT
       || currentToken.type == T_LE || currentToken.type == T_GE) {
        AST* node = newAST(ND_BINOP);
        node->op = currentToken.type;
        match(currentToken.type);
        node->left = left;
        node->right = parseTerm();
        left = node;
    }
    return left;
}

/* term -> factor ( ( "+" | "-" ) factor )* */
AST* parseTerm() {
    AST* left = parseFactor();
    while(currentToken.type == T_PLUS || currentToken.type == T_MINUS) {
        AST* node = newAST(ND_BINOP);
        node->op = currentToken.type;
        match(currentToken.type);
        node->left = left;
        node->right = parseFactor();
        left = node;
    }
    return left;
}

/* factor -> factor2 ( "*" factor2 )* */
AST* parseFactor() {
    AST* left = parseFactor2();
    while(currentToken.type == T_STAR) {
        AST* node = newAST(ND_BINOP);
        node->op = currentToken.type;
        match(T_STAR);
        node->left = left;
        node->right = parseFactor2();
        left = node;
    }
    return left;
}

/* factor2 -> NUMBER | ID | "(" expr ")" */
AST* parseFactor2() {
    AST* node = NULL;
    if(currentToken.type == T_NUM) {
        node = newAST(ND_NUM);
        node->value = currentToken.value;
        nextToken();
    } else if(currentToken.type == T_ID) {
        node = newAST(ND_VAR);
        strcpy(node->varname, currentToken.text);
        nextToken();
    } else if(currentToken.type == T_LPAREN) {
        match(T_LPAREN);
        node = parseExpr();
        match(T_RPAREN);
    } else {
        error("Ocekavan vyraz");
    }
    return node;
}

/* -------------------- TABULKA PROMĚNNÝCH -------------------- */
Var *varList = NULL;
int stackOffset = 0; // záporný offset od EBP

/* Najde proměnnou v tabulce (nebo NULL pokud není) */
Var* findVar(const char* name) {
    Var* v = varList;
    while(v) {
        if(strcmp(v->name, name)==0) return v;
        v = v->next;
    }
    return NULL;
}

/* Vloží novou proměnnou s daným jménem, vrátí ukazatel na Var */
Var* addVar(const char* name) {
    // už existuje?
    Var *existing = findVar(name);
    if(existing) {
        // v reálném C by to nemusela být chyba, ale pro ukázku to zakážeme
        fprintf(stderr, "Chyba: opakovaná deklarace proměnné '%s'\n", name);
        exit(1);
    }
    Var* v = (Var*)calloc(1,sizeof(Var));
    strcpy(v->name, name);
    // posuneme stack offset o 4 bajty
    stackOffset -= 4;
    v->offset = stackOffset;
    v->next = varList;
    varList = v;
    return v;
}

/* -------------------- GENEROVÁNÍ KÓDU DO x86 -------------------- */

FILE *out; // výstupní .s soubor

/* Vygeneruje kód pro vyhodnocení výrazu a uloží výsledek do zásobníku */
void genExpr(AST* node);

/* Vygeneruje kód pro blok deklarací + příkazů */
void genBlock(AST* block);

void genStatement(AST* st) {
    switch(st->nodetype) {
        case ND_BLOCK:
            genBlock(st);
            break;
        case ND_DECL: {
            // přidání do tabulky proměnných
            addVar(st->varname);
        } break;
        case ND_ASSIGN: {
            // vygenerujeme kód pro vyraz -> stack
            genExpr(st->left);
            // uložíme do proměnné
            Var* v = findVar(st->varname);
            if(!v) {
                fprintf(stderr, "Promenna '%s' neni deklarovana.\n", st->varname);
                exit(1);
            }
            fprintf(out, "\tpopl %%eax\n");
            // movl %eax, offset(%ebp)
            fprintf(out, "\tmovl %%eax, %d(%%ebp)\n", v->offset);
        } break;
        case ND_IF: {
            static int labelId = 1;
            int myId = labelId++;
            // vygenerujeme podmínku
            genExpr(st->left); // condition -> top of stack
            fprintf(out, "\tpopl %%eax\n");
            // testl %eax, %eax
            fprintf(out, "\ttestl %%eax, %%eax\n");
            // je-li 0, skok na else
            fprintf(out, "\tje .Lelse%d\n", myId);
            // if-větev
            genStatement(st->right);
            // skok za else
            fprintf(out, "\tjmp .Lend%d\n", myId);
            // else větev
            fprintf(out, ".Lelse%d:\n", myId);
            if(st->extra) {
                genStatement(st->extra);
            }
            fprintf(out, ".Lend%d:\n", myId);
        } break;
        case ND_WHILE: {
            static int labelId = 1;
            int myId = labelId++;
            // label začátku smyčky
            fprintf(out, ".Lbegin%d:\n", myId);
            // vyhodnotíme podmínku
            genExpr(st->left);
            fprintf(out, "\tpopl %%eax\n");
            fprintf(out, "\ttestl %%eax, %%eax\n");
            // pokud 0 -> konec
            fprintf(out, "\tje .Lend%d\n", myId);
            // tělo
            genStatement(st->right);
            // skok na začátek
            fprintf(out, "\tjmp .Lbegin%d\n", myId);
            fprintf(out, ".Lend%d:\n", myId);
        } break;
        case ND_READ: {
            // zavoláme funkci scanf("%d", &var)
            Var* v = findVar(st->varname);
            if(!v) {
                fprintf(stderr, "Promenna '%s' neni deklarovana.\n", st->varname);
                exit(1);
            }
            // movl $format, (%esp)
            // lea var, %eax
            // push %eax
            fprintf(out, "\tlea %d(%%ebp), %%eax\n", v->offset);
            fprintf(out, "\tpushl %%eax\n");
            fprintf(out, "\tpushl $intFmt\n"); 
            fprintf(out, "\tcall scanf\n");
            fprintf(out, "\taddl $8, %%esp\n"); 
        } break;
        case ND_WRITE: {
            // vygenerujeme výraz
            genExpr(st->left);
            // top of stack -> %eax
            fprintf(out, "\tpopl %%eax\n");
            // push %eax, push $format, call printf
            fprintf(out, "\tpushl %%eax\n");
            fprintf(out, "\tpushl $intFmt\n");
            fprintf(out, "\tcall printf\n");
            fprintf(out, "\taddl $8, %%esp\n");
        } break;
        case ND_RETURN: {
            // vyhodnotíme výraz -> top of stack
            genExpr(st->left);
            fprintf(out, "\tpopl %%eax\n"); // výsledek do EAX
            // epilog
            fprintf(out, "\tjmp .Lreturn\n");
        } break;
        default:
            fprintf(stderr, "Neznamy statement typ %d\n", st->nodetype);
            exit(1);
    }
}

/* projde spojený seznam deklarací a příkazů */
void genBlock(AST* block) {
    // block->left = první deklarace, block->right = první statement
    // v deklaracích se pokračuje nextstmt, v příkazech také
    // Napřed zpracuj deklarace:
    AST* d = block->left;
    while(d) {
        genStatement(d);
        d = d->nextstmt;
    }
    // Pak příkazy:
    AST* s = block->right;
    while(s) {
        genStatement(s);
        s = s->nextstmt;
    }
}

/* vygeneruje kód pro výraz a výslednou hodnotu dá na stack (push) */
void genExpr(AST* node) {
    switch(node->nodetype) {
        case ND_NUM:
            // push immediate
            fprintf(out, "\tpushl $%d\n", node->value);
            break;
        case ND_VAR: {
            Var* v = findVar(node->varname);
            if(!v) {
                fprintf(stderr, "Promenna '%s' neni deklarovana.\n", node->varname);
                exit(1);
            }
            // movl offset(%ebp), %eax
            // pushl %eax
            fprintf(out, "\tmovl %d(%%ebp), %%eax\n", v->offset);
            fprintf(out, "\tpushl %%eax\n");
        } break;
        case ND_BINOP: {
            // vyhodnotíme levý a pravý operand
            genExpr(node->left);
            genExpr(node->right);
            // pop pravý do %ebx, levý do %eax
            fprintf(out, "\tpopl %%ebx\n");
            fprintf(out, "\tpopl %%eax\n");
            switch(node->op) {
                case T_PLUS:
                    fprintf(out, "\taddl %%ebx, %%eax\n");
                    break;
                case T_MINUS:
                    fprintf(out, "\tsubl %%ebx, %%eax\n");
                    break;
                case T_STAR:
                    fprintf(out, "\timull %%ebx, %%eax\n");
                    break;
                case T_EQ:
                    // cmp eax, ebx -> sete
                    fprintf(out, "\tcmpl %%ebx, %%eax\n");
                    // nastavíme eax = (eax == ebx ? 1 : 0)
                    fprintf(out, "\tsete %%al\n");
                    fprintf(out, "\tmovzbl %%al, %%eax\n");
                    break;
                case T_NEQ:
                    fprintf(out, "\tcmpl %%ebx, %%eax\n");
                    fprintf(out, "\tsetne %%al\n");
                    fprintf(out, "\tmovzbl %%al, %%eax\n");
                    break;
                case T_LT:
                    fprintf(out, "\tcmpl %%ebx, %%eax\n");
                    fprintf(out, "\tsetl %%al\n");
                    fprintf(out, "\tmovzbl %%al, %%eax\n");
                    break;
                case T_LE:
                    fprintf(out, "\tcmpl %%ebx, %%eax\n");
                    fprintf(out, "\tsetle %%al\n");
                    fprintf(out, "\tmovzbl %%al, %%eax\n");
                    break;
                case T_GT:
                    fprintf(out, "\tcmpl %%ebx, %%eax\n");
                    fprintf(out, "\tsetg %%al\n");
                    fprintf(out, "\tmovzbl %%al, %%eax\n");
                    break;
                case T_GE:
                    fprintf(out, "\tcmpl %%ebx, %%eax\n");
                    fprintf(out, "\tsetge %%al\n");
                    fprintf(out, "\tmovzbl %%al, %%eax\n");
                    break;
                default:
                    fprintf(stderr, "Nepodporovany binop %d\n", node->op);
                    exit(1);
            }
            // výsledek push
            fprintf(out, "\tpushl %%eax\n");
        } break;
        default:
            fprintf(stderr, "Neznamy nodetype ve vyrazu %d\n", node->nodetype);
            exit(1);
    }
}

/* -------------------- HLAVNÍ FUNKCE -------------------- */

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("Pouziti: %s <soubor.microc> [vystup.s]\n", argv[0]);
        return 1;
    }
    f = fopen(argv[1], "r");
    if(!f) {
        perror("Nelze otevrit vstupni soubor");
        return 1;
    }

    if(argc >= 3) {
        out = fopen(argv[2], "w");
        if(!out) {
            perror("Nelze otevrit vystupni soubor");
            return 1;
        }
    } else {
        out = fopen("out.s","w");
        if(!out) {
            perror("Nelze otevrit out.s pro zapis");
            return 1;
        }
    }

    // Inicializuj skener
    peekChar = -1;
    nextToken(); // načti první token

    // Parsuj program (jedinou funkci main)
    AST* root = parseProgram();

    // Vygeneruj úvod asm
    fprintf(out, "\t.text\n");
    fprintf(out, "\t.globl main\n");
    fprintf(out, "intFmt: .asciz \"%%d\"\n");
    fprintf(out, "\nmain:\n");
    // Prolog
    fprintf(out, "\tpushl %%ebp\n");
    fprintf(out, "\tmovl %%esp, %%ebp\n");

    // Rezerva na lokální proměnné: neznáme zatím kolik jich bude,
    // vyřešíme na konci. Uděláme to tak, že si necháme "díru" a pak
    // ji přepíšeme. Aby to fungovalo, museli bychom soubor raději
    // uložit do paměti apod. Tady pro jednoduchost budeme
    // generovat až poté, co si vybudujeme tabulku. -> Musíme
    // napřed projít AST a definovat proměnné, pak generovat.
    // Jednoduše to uděláme tak, že zavoláme genBlock dvakrát:
    // 1) jen kvůli deklaracím (aby se naplnil varList, stackOffset)
    // 2) znovu kvůli generování kódu
    // Ale pro to by bylo potřeba genBlock lehce modifikovat.
    // Tady to uděláme "špinavě" tak, že projdeme "ručně" deklarace.
    
    // Projdeme deklarace a vyplníme tabulku varList
    // (protože parseProgram je ND_BLOCK, block->left = firstDecl, block->right = firstStmt)
    AST* d = root->left;
    while(d) {
        if(d->nodetype == ND_DECL) {
            addVar(d->varname);
        }
        d = d->nextstmt;
    }

    // Teď můžeme vygenerovat "sub esp, velikost"
    // stackOffset je záporný - kolik místa bylo spotřebováno
    int locSize = -stackOffset; 
    fprintf(out, "\tsubl $%d, %%esp\n", locSize);

    // Vygeneruj tělo programu (deklarace + statements)
    genBlock(root);

    // Vložíme label .Lreturn, abychom mohli odskocit z return
    fprintf(out, ".Lreturn:\n");
    // Epilog
    fprintf(out, "\tleave\n"); // movl %ebp, %esp; popl %ebp
    fprintf(out, "\tret\n");

    fclose(out);
    fclose(f);
    return 0;
}

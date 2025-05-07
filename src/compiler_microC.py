import sys

from lib.ply import lex, yacc
from lib.utils import find_column

errors = []# Seznam chyb z lexingu/parsing, na konci se vypíší a ukončí program


# =====================
# Lexer
# =====================

# rezervovaná slova jazyka mikroC a jejich tokeny
reserved = {
    "if": "IF",
    "else": "ELSE",
    "while": "WHILE",
    "do": "DO",
    "for": "FOR",
    "print": "PRINT",
    "scan": "SCAN",
}

# Seznam ostatních tokenů včetně čísel, identifikátorů a operátorů
tokens = [
    "NUMBER",
    "ID",
    "STRING",
    "PLUSPLUS",     # ++
    "MINUSMINUS",   # --
    "EQ",           # ==
    "NE",           # !=
    "LE",           # <=
    "GE",           # >=
    "AND",          # &&
    "OR",           # ||
    "LSHIFT",       # <<
    "RSHIFT",       # >>
    # Složené přiřazovací operátory (+=, -=, ...)
    "PLUSEQ",
    "MINUSEQ",
    "TIMESEQ",
    "DIVEQ",
    "MODEQ",
    "LSHIFTEQ",
    "RSHIFTEQ",
    "ANDEQ",
    "XOREQ",
    "OREQ",
] + list(reserved.values())

# literály, které jsou samy o sobě tokeny
literals = [
    "=",
    "+",
    "-",
    "*",
    "/",
    "%",
    "<",
    ">",
    "!",
    "~",
    "&",
    "^",
    "|",
    "(",
    ")",
    "{",
    "}",
    ";",
    ",",
]

t_ignore = " \t\r"# bílé znaky, které se ignorují - mezery, tabulátory...

# ---------------------
# Definice regulárních výrazů pro lexér
# ---------------------

def t_COMMENT(t):
    r"//.*|/\*(.|\n)*?\*/"
    pass


def t_TRUE(t):
    r"\b(true|false)\b"
    t.type = "NUMBER"
    t.value = 1 if t.value == "true" else 0    # true/false => 1/0
    return t


def t_ID(t):
    r"[a-zA-Z_][a-zA-Z_0-9]*"
    t.type = reserved.get(t.value, "ID")
    return t


def t_NUMBER(t):
    r"0b[01]+|0x[0-9A-Fa-f]+|[0-9]+"
    s = t.value.lower()
    if s.startswith("0b"):
        t.value = int(s[2:], 2)
    elif s.startswith("0x"):
        t.value = int(s[2:], 16)
    else:
        t.value = int(s)
    return t


def t_CHAR(t):
    r"'([^\\\n]|\\.)'"
    t.type = "NUMBER"
    t.value = ord(t.value[1])
    return t


def t_UNCLOSED_STRING(t):
    r'"([^\\n]|\.)*$'
    col = find_column(t.lexer.lexdata, t.lexpos)
    errors.append(f'{t.lineno}.{col} Chybi znak " na konci retezce')
    t.lexer.skip(len(t.value))


def t_STRING(t):
    r"\"([^\\\n]|\\.)*?\" "
    t.value = t.value[1:-1]
    return t


# slovník pro složené přiřazovací operátory
assign_map = {
    "+=": "PLUSEQ",
    "-=": "MINUSEQ",
    "*=": "TIMESEQ",
    "/=": "DIVEQ",
    "%=": "MODEQ",
    "<<=": "LSHIFTEQ",
    ">>=": "RSHIFTEQ",
    "&=": "ANDEQ",
    "^=": "XOREQ",
    "|=": "OREQ",
}


def t_ASSIGN_OP(t):
    r"\+=|-=|\*=|/=|%=|<<=|>>=|&=|\^=|\|="
    t.type = assign_map[t.value]
    return t


op_map = {
    "++": "PLUSPLUS",
    "--": "MINUSMINUS",
    "==": "EQ",
    "!=": "NE",
    "<=": "LE",
    ">=": "GE",
    "&&": "AND",
    "||": "OR",
    "<<": "LSHIFT",
    ">>": "RSHIFT",
}


def t_OP_MULTI(t):
    r"\+\+|--|==|!=|<=|>=|&&|\|\||<<|>>"
    t.type = op_map[t.value]
    return t


def t_newline(t):
    r"\n+"
    t.lexer.lineno += len(t.value)


def t_error(t):
    col = find_column(t.lexer.lexdata, t.lexpos)
    errors.append(f"{t.lineno}.{col} Illegal character '{t.value[0]}'")
    t.lexer.skip(1)


lexer = lex.lex()


# =====================
# Definice AST (Abstract Syntax Tree) uzlů
# Každá třída reprezentuje typ uzlu v syntaktickém stromu
# =====================
class Node:
    pass


class Number(Node):
    def __init__(self, value):
        self.value = value


class String(Node):
    def __init__(self, value):
        self.value = value


class Var(Node):
    def __init__(self, name):
        self.name = name


class BinOp(Node):
    def __init__(self, op, left, right):
        self.op = op
        self.left = left
        self.right = right


class UnOp(Node):
    def __init__(self, op, expr):
        self.op = op
        self.expr = expr


class Assign(Node):
    def __init__(self, target, op, expr):
        self.target = target
        self.op = op
        self.expr = expr


class Print(Node):
    def __init__(self, fmt, expr=None):
        self.fmt = fmt
        self.expr = expr


class Scan(Node):
    def __init__(self, var):
        self.var = var


class Compound(Node):
    def __init__(self, stmt_list):
        self.stmt_list = stmt_list


class If(Node):
    def __init__(self, cond, then, otherwise=None):
        self.cond = cond
        self.then = then
        self.otherwise = otherwise


class While(Node):
    def __init__(self, cond, body):
        self.cond = cond
        self.body = body


class DoWhile(Node):
    def __init__(self, body, cond):
        self.body = body
        self.cond = cond


class For(Node):
    def __init__(self, init, cond, incr, body):
        self.init = init
        self.cond = cond
        self.incr = incr
        self.body = body


class PreInc(Node):
    def __init__(self, var):
        self.var = var


# =====================
# Parser - definice gramatiky mikroC pomocí PLY/yacc
# =====================

# Priorita operátorů pro správné parsování výrazu
precedence = (
    (
        "right",
        "=",
        "PLUSEQ",
        "MINUSEQ",
        "TIMESEQ",
        "DIVEQ",
        "MODEQ",
        "LSHIFTEQ",
        "RSHIFTEQ",
        "ANDEQ",
        "XOREQ",
        "OREQ",
    ),
    ("left", "OR"),  # logical ||
    ("left", "AND"),  # logical &&
    ("left", "EQ", "NE"),  # ==, !=
    ("left", "<", ">", "LE", "GE"),
    ("left", "LSHIFT", "RSHIFT"),
    ("left", "+", "-"),
    ("left", "*", "/", "%"),
    ("left", "|"),  # bitwise OR
    ("left", "^"),  # bitwise XOR
    ("left", "&"),  # bitwise AND
    ("right", "UPLUS", "UMINUS"),
)


def p_program(p):
    "program : compound_statement"
    p[0] = p[1]


def p_compound(p):
    'compound_statement : "{" stmt_list "}"'
    p[0] = Compound(p[2])


def p_stmt_list(p):
    "stmt_list : stmt_list statement"
    p[0] = p[1] + [p[2]]


def p_stmt_list_empty(p):
    "stmt_list :"
    p[0] = []


def p_statement_expr(p):
    'statement : expression ";"'
    p[0] = p[1]


def p_statement_compound(p):
    "statement : compound_statement"
    p[0] = p[1]


def p_statement_if(p):
    'statement : IF "(" expression ")" statement'
    p[0] = If(p[3], p[5])


def p_statement_if_else(p):
    'statement : IF "(" expression ")" statement ELSE statement'
    p[0] = If(p[3], p[5], p[7])


def p_statement_while(p):
    'statement : WHILE "(" expression ")" statement'
    p[0] = While(p[3], p[5])


def p_statement_do(p):
    'statement : DO statement WHILE "(" expression ")" ";"'
    p[0] = DoWhile(p[2], p[5])


def p_statement_for(p):
    'statement : FOR "(" opt_expr ";" opt_expr ";" opt_expr ")" statement'
    p[0] = For(p[3], p[5], p[7], p[9])


def p_opt_expr(p):
    "opt_expr : expression"
    p[0] = p[1]


def p_opt_expr_empty(p):
    "opt_expr :"
    p[0] = None



def p_statement_print(p):
    'statement : PRINT "(" print_args ")" ";"'
    p[0] = Print(*p[3])


def p_print_args_fmt(p):
    'print_args : STRING "," expression'
    p[0] = (p[1], p[3])


def p_print_args_str(p):
    "print_args : STRING"
    p[0] = (p[1], None)


def p_statement_scan(p):
    'statement : SCAN "(" ID ")" ";"'
    p[0] = Scan(p[3])


for tok in [
    "=",
    "PLUSEQ",
    "MINUSEQ",
    "TIMESEQ",
    "DIVEQ",
    "MODEQ",
    "LSHIFTEQ",
    "RSHIFTEQ",
    "ANDEQ",
    "XOREQ",
    "OREQ",
]:
    pass


def p_assign_op_eq(p):
    'assign_op : "="'
    p[0] = p[1]


def p_assign_op_pluseq(p):
    "assign_op : PLUSEQ"
    p[0] = p[1]


def p_assign_op_minuseq(p):
    "assign_op : MINUSEQ"
    p[0] = p[1]


def p_assign_op_timeseq(p):
    "assign_op : TIMESEQ"
    p[0] = p[1]


def p_assign_op_diveq(p):
    "assign_op : DIVEQ"
    p[0] = p[1]


def p_assign_op_modeq(p):
    "assign_op : MODEQ"
    p[0] = p[1]


def p_assign_op_lshifteq(p):
    "assign_op : LSHIFTEQ"
    p[0] = p[1]


def p_assign_op_rshifteq(p):
    "assign_op : RSHIFTEQ"
    p[0] = p[1]


def p_assign_op_andeq(p):
    "assign_op : ANDEQ"
    p[0] = p[1]


def p_assign_op_xoreq(p):
    "assign_op : XOREQ"
    p[0] = p[1]


def p_assign_op_oreq(p):
    "assign_op : OREQ"
    p[0] = p[1]


def p_expression_assign(p):
    "expression : ID assign_op expression"
    p[0] = Assign(Var(p[1]), p[2], p[3])


def p_expression_arith(p):
    """expression : expression '+' expression
    | expression '-' expression
    | expression '*' expression
    | expression '/' expression
    | expression '%' expression"""
    p[0] = BinOp(p[2], p[1], p[3])


def p_expression_cmp(p):
    """expression : expression '<' expression
    | expression '>' expression
    | expression LE expression
    | expression GE expression"""
    p[0] = BinOp(p[2], p[1], p[3])


def p_expression_eq(p):
    """expression : expression EQ expression
    | expression NE expression"""
    p[0] = BinOp(p[2], p[1], p[3])


def p_expression_logic(p):
    """expression : expression AND expression
    | expression OR expression"""
    p[0] = BinOp(p[2], p[1], p[3])


def p_expression_bitor(p):
    'expression : expression "|" expression'
    p[0] = BinOp("|", p[1], p[3])


def p_expression_unop_plus(p):
    "expression : '+' expression %prec UPLUS"
    p[0] = UnOp("+", p[2])


def p_expression_unop_minus(p):
    "expression : '-' expression %prec UMINUS"
    p[0] = UnOp("-", p[2])


def p_expression_unop_bitwise_not(p):
    "expression : '~' expression"
    p[0] = UnOp("~", p[2])


def p_expression_unop_logic_not(p):
    "expression : '!' expression"
    p[0] = UnOp("!", p[2])


def p_expression_bitor(p):
    'expression : expression "|" expression'
    p[0] = BinOp("|", p[1], p[3])


def p_expression_bitxor(p):
    "expression : expression '^' expression"
    p[0] = BinOp("^", p[1], p[3])


def p_expression_bitand(p):
    "expression : expression '&' expression"
    p[0] = BinOp("&", p[1], p[3])


def p_expression_unop_inc(p):
    "expression : PLUSPLUS ID"
    p[0] = PreInc(Var(p[2]))


def p_expression_unop_dec(p):
    "expression : MINUSMINUS ID"
    p[0] = PreInc(Var(p[2]))


def p_expression_group(p):
    'expression : "(" expression ")"'
    p[0] = p[2]


def p_expression_number(p):
    "expression : NUMBER"
    p[0] = Number(p[1])


def p_expression_string(p):
    "expression : STRING"
    p[0] = String(p[1])


def p_expression_var(p):
    "expression : ID"
    p[0] = Var(p[1])


def p_error(p):
    if p:
        col = find_column(p.lexer.lexdata, p.lexpos)
        errors.append(f"{p.lineno}.{col} syntax error, unexpected {p.type}")
        parser.errok()
    else:
        errors.append("Syntax error at EOF")


parser = yacc.yacc()


# =====================
# Code generation
# =====================
class CodeGen:
    def __init__(self):
        self.indent = 0
        self.lines = []

    def emit(self, line):
        self.lines.append("    " * self.indent + line)

    def get_code(self):
        return "\n".join(self.lines)

    def gen(self, node):
        if isinstance(node, Compound):
            for stmt in node.stmt_list:
                self.gen(stmt)
        elif isinstance(node, Number):
            self.emit(str(node.value))
        elif isinstance(node, Var):
            self.emit(node.name)
        elif isinstance(node, Assign):
            if node.op == "=" and isinstance(node.expr, Assign):            # m = (r = 0)
                inner = node.expr
                self.emit(f"{inner.target.name} = {self.expr(inner.expr)}")
                self.emit(f"{node.target.name} = {inner.target.name}")
            else:
                expr_code = self.expr(node.expr)
                if node.op == "=":
                    self.emit(f"{node.target.name} = {expr_code}")
                else:
                    op = node.op
                    pyop = "//=" if op == "/=" else op
                    self.emit(f"{node.target.name} {pyop} {expr_code}")
        elif isinstance(node, PreInc):
            var = node.var.name
            self.emit(f"{var} += 1")
        elif isinstance(node, BinOp):
            self.emit(self.expr(node))
        elif isinstance(node, UnOp):
            self.emit(self.expr(node))
        elif isinstance(node, Print):
            if node.expr is not None:
                self.emit(f'print(f"{node.fmt}" % ({self.expr(node.expr)}), end="")')
            else:
                self.emit(f'print(f"{node.fmt}", end="")')
        elif isinstance(node, String):
            self.emit(f'print({repr(node.value)}, end="")')
        elif isinstance(node, Scan):
            self.emit(f"{node.var} = int(input())")
        elif isinstance(node, If):
            self.emit(f"if {self.expr(node.cond)}:")
            self.indent += 1
            self.gen(node.then)
            self.indent -= 1
            if node.otherwise:
                self.emit("else:")
                self.indent += 1
                self.gen(node.otherwise)
                self.indent -= 1
        elif isinstance(node, While):
            self.emit(f"while {self.expr(node.cond)}:")
            self.indent += 1
            self.gen(node.body)
            self.indent -= 1
        elif isinstance(node, DoWhile):
            self.emit("while True:")            # do while cykly
            self.indent += 1
            self.gen(node.body)
            cond = node.cond
            if isinstance(cond, Assign):
                var = cond.target.name
                expr_code = self.expr(cond.expr)
                if cond.op == "<<=":
                    self.emit(f"{var} = (({var} << {expr_code}) & 0xFFFFFFFF)")
                elif cond.op == ">>=":
                    self.emit(f"{var} = ({var} >> {expr_code})")
                else:
                    pyop = "//=" if cond.op == "/=" else cond.op
                    self.emit(f"{var} {pyop} {expr_code}")
                self.emit(f"if not {var}: break")
            elif isinstance(cond, BinOp) and isinstance(cond.left, Assign):
                assign = cond.left
                var = assign.target.name
                expr_code = self.expr(assign.expr)
                pyop = "//=" if assign.op == "/=" else assign.op
                self.emit(f"{var} {pyop} {expr_code}")
                self.emit(f"if not ({var} {cond.op} {self.expr(cond.right)}): break")
            elif isinstance(cond, BinOp) and isinstance(cond.left, PreInc):
                var = cond.left.var.name
                self.emit(f"{var} += 1")
                self.emit(f"if not ({var} {cond.op} {self.expr(cond.right)}): break")
            elif isinstance(cond, PreInc):
                var = cond.var.name
                self.emit(f"{var} += 1")
                self.emit(f"if not {var}: break")
            else:
                self.emit(f"if not {self.expr(cond)}: break")
            self.indent -= 1
        elif isinstance(node, For):
            if node.init:
                self.gen(node.init)
            self.emit(f"while {self.expr(node.cond) if node.cond else 'True'}:")
            self.indent += 1
            self.gen(node.body)
            incr = node.incr
            if isinstance(incr, PreInc):
                self.emit(f"{incr.var.name} += 1")
            elif isinstance(incr, Assign):
                var = incr.target.name
                expr_code = self.expr(incr.expr)
                pyop = "//=" if incr.op == "/=" else incr.op
                self.emit(f"{var} {pyop} {expr_code}")
            else:
                self.emit(self.expr(incr))
            self.indent -= 1
        else:
            raise Exception(f"Unrecognized node type: {type(node)}")

    def expr(self, node):
        if isinstance(node, Number):
            return str(node.value)
        if isinstance(node, Var):
            return node.name
        if isinstance(node, PreInc):
            return node.var.name
        if isinstance(node, BinOp):
            op = node.op
            if op == "&&":
                pyop = "and"
            elif op == "||":
                pyop = "or"
            elif op == "/":
                pyop = "//"
            else:
                pyop = op
            return f"({self.expr(node.left)} {pyop} {self.expr(node.right)})"
        if isinstance(node, UnOp):
            return f"({node.op}{self.expr(node.expr)})"
        if isinstance(node, Assign):
            op = node.op
            pyop = "//=" if op == "/=" else op
            return f"({node.target.name} {pyop} {self.expr(node.expr)})"
        raise Exception(f"nenadefinovaný výraz: {type(node)}")


def main(testPath=None):
    if testPath is None and len(sys.argv) < 2:
        print("použijte:\tpython compiler_microC.py <zdroj_kod.mC>\nnebo\t\tpython3 compiler_microC.py <zdroj_kod.mC>")
        sys.exit(1)
    path = testPath if testPath else sys.argv[1]
    data = open(path).read()  # načtení mC souboru
    lexer.input(data)  # lexer
    parser = yacc.yacc()  # parser
    ast = parser.parse(data, lexer=lexer)  # ast

    # výpis chyb a ukončení programu
    if errors:
        for e in errors:
            print(e)
        sys.exit(1)

    # vygenerování python kódu
    codegen = CodeGen()
    codegen.emit("def __mikroc_main():")
    codegen.indent += 1
    codegen.gen(ast)
    codegen.emit(
        "pass"
    )  # pokud by byl přeložený soubor prázdný (třeba kvůli tomu, že mC soubor obsahuje jenom komentáře), tak se do main metody vloží pass
    codegen.indent -= 1
    codegen.emit("")
    codegen.emit("if __name__ == '__main__':")
    codegen.indent += 1
    codegen.emit("__mikroc_main()")
    python_code = codegen.get_code()

    # přeložený soubor se zapíše do souboru
    with open("../program.py", "w+") as output_file:
        # ..pouze pro debugování; není třeba přeložený kód ukládat do souboru
        output_file.write(python_code)

    # přeložený kod se spustí
    exec(python_code, globals(), globals())


if __name__ == "__main__":
    main()

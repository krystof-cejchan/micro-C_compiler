from abstract_syntax_tree import *
from utils import find_column
import ply.yacc as yacc
from lexer import *

errors = []

reserved = {
    "if": "IF",
    "else": "ELSE",
    "while": "WHILE",
    "do": "DO",
    "for": "FOR",
    "print": "PRINT",
    "scan": "SCAN",
}

tokens = [
    "NUMBER",
    "ID",
    "STRING",
    "PLUSPLUS",
    "MINUSMINUS",
    "EQ",
    "NE",
    "LE",
    "GE",
    "AND",
    "OR",
    "LSHIFT",
    "RSHIFT",
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

t_ignore = " \t\r"


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


# print/scan


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


# assign operators
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


# bitwise XOR
def p_expression_bitxor(p):
    "expression : expression '^' expression"
    p[0] = BinOp("^", p[1], p[3])


# bitwise AND
def p_expression_bitand(p):
    "expression : expression '&' expression"
    p[0] = BinOp("&", p[1], p[3])


# prefix increment/decrement
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
        # skip this token
        parser.errok()
    else:
        errors.append("Syntax error at EOF")


# build the parser
parser = yacc.yacc()

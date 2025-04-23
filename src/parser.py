import ply.yacc as yacc
from lexer import tokens, lexer
from classes.ast_node import *

precedence = (
    ('right', '=', 'PLUSEQ', 'MINUSEQ', 'TIMESEQ', 'DIVEQ', 'MODEQ', 'LSHIFTEQ', 'RSHIFTEQ', 'ANDEQ', 'XOREQ', 'OREQ'),
    ('left', 'EQ', 'NE'),
    ('left', 'OR'),
    ('left', 'AND'),
    ('left', 'BITOR'),
    ('left', '^'),
    ('left', '&'),
    ('left', 'LSHIFT', 'RSHIFT'),
    ('left', '+', '-'),
    ('left', '*', '/', '%'),
    ('right', 'UPLUS', 'UMINUS', 'PLUSPLUS', 'MINUSMINUS')
)

def p_program(p):
    'program : compound_statement'
    p[0] = p[1]

def p_compound(p):
    'compound_statement : "{" stmt_list "}"'
    p[0] = Compound(p[2])

def p_stmt_list(p):
    'stmt_list : stmt_list statement'
    p[0] = p[1] + [p[2]]

def p_stmt_list_empty(p):
    'stmt_list : '
    p[0] = []

# Statements

def p_statement_expr(p):
    'statement : expression ";"'
    p[0] = p[1]

def p_statement_compound(p):
    'statement : compound_statement'
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
    'opt_expr : expression'
    p[0] = p[1]

def p_opt_expr_empty(p):
    'opt_expr : '
    p[0] = None

# print/scan

def p_statement_print(p):
    'statement : PRINT "(" print_args ")" ";"'
    p[0] = Print(*p[3])

def p_print_args_fmt(p):
    'print_args : STRING "," expression'
    p[0] = (p[1], p[3])

def p_print_args_str(p):
    'print_args : STRING'
    p[0] = (p[1], None)

def p_statement_scan(p):
    'statement : SCAN "(" ID ")" ";"'
    p[0] = Scan(p[3])

# Assign operator alternatives
def p_assign_op(p):
    """
    assign_op : '='
              | PLUSEQ
              | MINUSEQ
              | TIMESEQ
              | DIVEQ
              | MODEQ
              | LSHIFTEQ
              | RSHIFTEQ
              | ANDEQ
              | XOREQ
              | OREQ
    """
    p[0] = p[1]

# Expression assignment
def p_expression_assign(p):
    'expression : ID assign_op expression'
    p[0] = Assign(Var(p[1]), p[2], p[3])

# Binary operation names
def p_binop(p):
    """
    binop : '+'
          | '-'
          | '*'
          | '/'
          | '%'
          | LSHIFT
          | RSHIFT
          | BITOR
          | '&'
          | '^'
          | AND
          | OR
          | EQ
          | NE
          | '<'
          | '>'
          | LE
          | GE
    """
    p[0] = p[1]

def p_expression_binop(p):
    'expression : expression binop expression'
    p[0] = BinOp(p[2], p[1], p[3])

# Unary operations
def p_expression_unop_plus(p):
    'expression : "+" expression %prec UPLUS'
    p[0] = UnOp('+', p[2])

def p_expression_unop_minus(p):
    'expression : "-" expression %prec UMINUS'
    p[0] = UnOp('-', p[2])

def p_expression_unop_bitwise_not(p):
    'expression : "~" expression'
    p[0] = UnOp('~', p[2])

def p_expression_unop_logic_not(p):
    'expression : "!" expression'
    p[0] = UnOp('!', p[2])

def p_expression_unop_inc(p):
    'expression : PLUSPLUS ID'
    var = Var(p[2])
    p[0] = Assign(var, '++', BinOp('+', var, Number(1)))

def p_expression_unop_dec(p):
    'expression : MINUSMINUS ID'
    var = Var(p[2])
    p[0] = Assign(var, '--', BinOp('+', var, Number(1)))

# Grouping, literals, variables
def p_expression_group(p):
    'expression : "(" expression ")"'
    p[0] = p[2]

def p_expression_number(p):
    'expression : NUMBER'
    p[0] = Number(p[1])

def p_expression_string(p):
    'expression : STRING'
    p[0] = String(p[1])

def p_expression_var(p):
    'expression : ID'
    p[0] = Var(p[1])

# Error handling
def p_error(p):
    if p:
        print(f"Syntax error at '{p.value}' (line {p.lineno})")
    else:
        print("Syntax error at EOF")

# Build the parser
parser = yacc.yacc()
import ply.lex as lex

reserved = {
    'if': 'IF', 'else': 'ELSE', 'while': 'WHILE', 'do': 'DO', 'for': 'FOR',
    'print': 'PRINT', 'scan': 'SCAN'
}

tokens = [
    'NUMBER', 'ID', 'STRING',
    'PLUSPLUS', 'MINUSMINUS',
    'EQ', 'NE', 'LE', 'GE', 'AND', 'OR',
    'LSHIFT', 'RSHIFT', 'BITOR',
    'PLUSEQ', 'MINUSEQ', 'TIMESEQ', 'DIVEQ', 'MODEQ',
    'LSHIFTEQ', 'RSHIFTEQ', 'ANDEQ', 'XOREQ', 'OREQ'
] + list(reserved.values())

literals = ['=', '+', '-', '*', '/', '%', '<', '>', '!', '~', '&', '^', '|',
            '(', ')', '{', '}', ';', ',']

t_ignore = ' \t\r'

def t_COMMENT(t):
    r"//.*|/\*(.|\n)*?\*/"
    pass

def t_TRUE(t):
    r"\b(true|false)\b"
    t.type = 'NUMBER'
    t.value = 1 if t.value == 'true' else 0
    return t

def t_ID(t):
    r"[a-zA-Z_][a-zA-Z_0-9]*"
    t.type = reserved.get(t.value, 'ID')
    return t

def t_NUMBER(t):
    r"0b[01]+|0x[0-9A-Fa-f]+|[0-9]+"
    s = t.value.lower()
    if s.startswith('0b'):
        t.value = int(s[2:], 2)
    elif s.startswith('0x'):
        t.value = int(s[2:], 16)
    else:
        t.value = int(s)
    return t

def t_STRING(t):
    r"\"([^\\\n]|(\\.)*?)*?\""
    t.value = t.value[1:-1]
    return t

assign_map = {
    '+=': 'PLUSEQ', '-=': 'MINUSEQ', '*=': 'TIMESEQ',
    '/=': 'DIVEQ', '%=': 'MODEQ', '<<=': 'LSHIFTEQ',
    '>>=': 'RSHIFTEQ', '&=': 'ANDEQ', '^=': 'XOREQ', '|=': 'OREQ'
}

def t_ASSIGN_OP(t):
    r"\+=|-=|\*=|/=|%=|<<=|>>=|&=|\^=|\|="
    t.type = assign_map[t.value]
    return t

op_map = {
    '++': 'PLUSPLUS', '--': 'MINUSMINUS',
    '==': 'EQ', '!=': 'NE', '<=': 'LE', '>=': 'GE',
    '&&': 'AND', '||': 'OR', '<<': 'LSHIFT', '>>': 'RSHIFT'
}

def t_OP_MULTI(t):
    r"\+\+|--|==|!=|<=|>=|&&|\|\||<<|>>"
    t.type = op_map[t.value]
    return t

def t_newline(t):
    r"\n+"
    t.lexer.lineno += len(t.value)

def t_error(t):
    print(f"Illegal character '{t.value[0]}' at line {t.lineno}")
    t.lexer.skip(1)

lexer = lex.lex()
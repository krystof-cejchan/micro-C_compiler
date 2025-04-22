import sys

from uPascal_lex import uP_lexer
from uPascal_par import *
from uzel import *


def interpret(node: Uzel):
    if not node:
        return 0
        
    typ = node.typ
    if typ == 0:
        interpret(node.prvni())
        interpret(node.druhy())
        interpret(node.treti())
        interpret(node.ctvrty())
        return 0
    else:
        raise TypeError(f"Unknown typ: {typ}")


if __name__ == "__main__":
    test_file = sys.argv[1]

    with open(test_file, "r") as f:
        code = f.read()

    AST = parser.parse(code, lexer=uP_lexer)

    try:
        interpret(AST)
    except Exception as e:
        print(e, file=sys.stderr)
        raise e

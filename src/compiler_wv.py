import sys

from code_gen import CodeGen
from lexer import lexer as lex
from parser import *


def main(testPath=None):
    if testPath is None and len(sys.argv) < 2:
        print("Usage: python compiler_wv.py <source.mC>")
        sys.exit(1)
    path = testPath if testPath else sys.argv[1]
    data = open(path).read()  # načtení mC souboru
    lex.input(data)  # lexer
    parser = yacc.yacc()  # parser
    ast = parser.parse(data, lexer=lex)  # absract syntax tree

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

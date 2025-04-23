# main.py
import sys
from lexer import lexer
from parser import parser
from classes.code_gen import CodeGen

def main():
    if len(sys.argv) < 2:
        print("Usage: python main.py <source.mC>")
        sys.exit(1)

    data = open(sys.argv[1]).read()
    # tell parser to use our lexer
    ast = parser.parse(data, lexer=lexer)

    codegen = CodeGen()
    codegen.emit("def __mikroc_main():")
    codegen.indent += 1
    codegen.gen(ast)
    codegen.indent -= 1
    codegen.emit("")
    codegen.emit("if __name__ == '__main__':")
    codegen.indent += 1
    codegen.emit("__mikroc_main()")

    python_code = codegen.get_code()
    compiled    = compile(python_code, '<mikroC-generated>', 'exec')
    exec(compiled, {})

if __name__ == '__main__':
    main()

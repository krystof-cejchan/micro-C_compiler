from classes.ast_node import *

class CodeGen:
    def __init__(self):
        self.indent = 0
        self.lines = []
    def emit(self, line): print('    '*self.indent + line)
    def get_code(self):
        return "\n".join(self.lines)
    def gen(self, node):
        if isinstance(node, Compound):
            self.emit('')
            for s in node.stmt_list: self.gen(s)
        elif isinstance(node, Number): self.emit(str(node.value))
        elif isinstance(node, String): self.emit(f'print({repr(node.value)}, end="")')
        elif isinstance(node, Var): self.emit(node.name)
        elif isinstance(node, Assign):
            self.emit(f"{node.target.name} = {self.expr(node.expr)}")
        elif isinstance(node, BinOp): self.emit(self.expr(node))
        elif isinstance(node, UnOp): self.emit(self.expr(node))
        elif isinstance(node, Print):
            if node.expr is not None:
                self.emit(f"print(f\"{node.fmt}\" % ({self.expr(node.expr)}))")
            else:
                self.emit(f"print(\"{node.fmt}\")")
        elif isinstance(node, Scan): self.emit(f"{node.var} = int(input())")
        elif isinstance(node, If):
            self.emit(f"if {self.expr(node.cond)}:")
            self.indent+=1; self.gen(node.then); self.indent-=1
            if node.otherwise:
                self.emit("else:")
                self.indent+=1; self.gen(node.otherwise); self.indent-=1
        elif isinstance(node, While):
            self.emit(f"while {self.expr(node.cond)}:")
            self.indent+=1; self.gen(node.body); self.indent-=1
        elif isinstance(node, DoWhile):
            self.emit("while True:")
            self.indent+=1; self.gen(node.body)
            self.emit(f"if not {self.expr(node.cond)}: break")
            self.indent-=1
        elif isinstance(node, For):
            if node.init: self.gen(node.init)
            self.emit(f"while {self.expr(node.cond) if node.cond else 'True'}:")
            self.indent+=1; self.gen(node.body)
            if node.incr: self.emit(self.expr(node.incr))
            self.indent-=1
        else:
            raise Exception(f"Unrecognized node type: {type(node)}")
    def expr(self, node):
        if isinstance(node, Number): return str(node.value)
        if isinstance(node, Var): return node.name
        if isinstance(node, BinOp): return f"({self.expr(node.left)} {node.op} {self.expr(node.right)})"
        if isinstance(node, UnOp): return f"({node.op}{self.expr(node.expr)})"
        if isinstance(node, Assign): return f"({node.target.name} {node.op} {self.expr(node.expr)})"
        raise Exception(f"Unrecognized expr: {type(node)}")
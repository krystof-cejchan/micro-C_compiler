from abstract_syntax_tree import *


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
            # Emit each statement in a compound block
            for stmt in node.stmt_list:
                self.gen(stmt)
        elif isinstance(node, Number):
            self.emit(str(node.value))
        elif isinstance(node, Var):
            self.emit(node.name)
        elif isinstance(node, Assign):
            # Handle nested assignments: m = (r = 0)
            if node.op == "=" and isinstance(node.expr, Assign):
                inner = node.expr
                # Inner assignment first
                self.emit(f"{inner.target.name} = {self.expr(inner.expr)}")
                self.emit(f"{node.target.name} = {inner.target.name}")
            else:
                expr_code = self.expr(node.expr)
                if node.op == "=":
                    self.emit(f"{node.target.name} = {expr_code}")
                else:
                    # Compound assignment, map '/=' to '//='
                    op = node.op
                    pyop = "//=" if op == "/=" else op
                    self.emit(f"{node.target.name} {pyop} {expr_code}")
        elif isinstance(node, PreInc):
            # Prefix increment
            var = node.var.name
            self.emit(f"{var} += 1")
        elif isinstance(node, BinOp):
            self.emit(self.expr(node))
        elif isinstance(node, UnOp):
            self.emit(self.expr(node))
        elif isinstance(node, Print):
            # C-style print, suppress newline
            if node.expr is not None:
                self.emit(f'print(f"{node.fmt}" % ({self.expr(node.expr)}), end="")')
            else:
                self.emit(f'print(f"{node.fmt}", end="")')
        elif isinstance(node, String):
            # Standalone string literal
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
            # emulating do-while loops
            self.emit("while True:")
            self.indent += 1
            # body of loop
            self.gen(node.body)
            cond = node.cond
            # direct compound assignment as loop condition (e.g., b <<= 1)
            if isinstance(cond, Assign):
                var = cond.target.name
                expr_code = self.expr(cond.expr)
                # for left-shift, mask to 32 bits so it eventually zeros out
                if cond.op == "<<=":
                    self.emit(f"{var} = (({var} << {expr_code}) & 0xFFFFFFFF)")
                elif cond.op == ">>=":
                    self.emit(f"{var} = ({var} >> {expr_code})")
                else:
                    pyop = "//=" if cond.op == "/=" else cond.op
                    self.emit(f"{var} {pyop} {expr_code}")
                # test the updated variable
                self.emit(f"if not {var}: break")
            # comparison with embedded assignment, e.g., (x += n) < limit
            elif isinstance(cond, BinOp) and isinstance(cond.left, Assign):
                assign = cond.left
                var = assign.target.name
                expr_code = self.expr(assign.expr)
                pyop = "//=" if assign.op == "/=" else assign.op
                self.emit(f"{var} {pyop} {expr_code}")
                self.emit(f"if not ({var} {cond.op} {self.expr(cond.right)}): break")
            # prefix increment in comparison, e.g., ++n < limit
            elif isinstance(cond, BinOp) and isinstance(cond.left, PreInc):
                var = cond.left.var.name
                self.emit(f"{var} += 1")
                self.emit(f"if not ({var} {cond.op} {self.expr(cond.right)}): break")
            # standalone prefix increment condition, e.g., while(++n)
            elif isinstance(cond, PreInc):
                var = cond.var.name
                self.emit(f"{var} += 1")
                self.emit(f"if not {var}: break")
            # plain boolean condition
            else:
                self.emit(f"if not {self.expr(cond)}: break")
            self.indent -= 1
        elif isinstance(node, For):
            # for(init; cond; incr)
            if node.init:
                self.gen(node.init)
            self.emit(f"while {self.expr(node.cond) if node.cond else 'True'}:")
            self.indent += 1
            self.gen(node.body)
            # increment step
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

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

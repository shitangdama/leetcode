def calculate(s):
    num, op, stack = 0, '+', [0]
    ops = {'+':lambda x, y: y, '-':lambda x, y: -y, '*':lambda x, y: x*y, '/':lambda x, y: (int)(float(x)/float(y))}
    for i, c in enumerate(s):
        if c.isdigit():
            num = num * 10 + int(c)
        if not c.isdigit() and c != ' ' or i == len(s)-1:
            prev = 0 if op in '+-' else stack.pop()
            stack.append(ops[op](prev, num))
            num, op = 0, c
    return sum(stack)

class Solution:
    # @param {string} s
    # @return {integer}
    def calculate(self, s):
        operands, operators = [], []
        operand = ""
        for i in reversed(xrange(len(s))):
            if s[i].isdigit():
                operand += s[i]
                if i == 0  or not s[i-1].isdigit():
                    operands.append(int(operand[::-1]))
                    operand = ""
            elif s[i] == ')' or s[i] == '*' or s[i] == '/':
                operators.append(s[i])
            elif s[i] == '+' or s[i] == '-':
                while operators and \
                      (operators[-1] == '*' or operators[-1] == '/'):
                    self.compute(operands, operators)
                operators.append(s[i])
            elif s[i] == '(':
                while operators[-1] != ')':
                    self.compute(operands, operators)
                operators.pop()
                
        while operators:
            self.compute(operands, operators)
            
        return operands[-1]

    def compute(self, operands, operators):
        left, right = operands.pop(), operands.pop()
        op = operators.pop()
        if op == '+':
            operands.append(left + right)
        elif op == '-':
            operands.append(left - right)
        elif op == '*':
            operands.append(left * right)
        elif op == '/':
            operands.append(left / right)


def calculate(s):
    l=list(s)
    if len(l) == 0: return 0;
    num=0
    sign='+'
    stack = []
    for idx,i in enumerate(l):
        if i.isdigit():
            num=num*10+int(i)
        # when the signs occurs,time to calculate your number
        if (i in ('+','-','*','/')) or idx==len(l)-1:
            if sign=='+':
                stack.append(num)
            if sign=='*':
                stack.append(int(stack.pop()) * num)
            if sign=='-':
                stack.append(-num)
            if sign=='/':
                top = int(stack.pop())
                if top >= 0:
                    stack.append( top / num)
                else:
                    stack.append(-( abs(top) / num  ))
            sign = i 
            num=0
    return sum(stack)

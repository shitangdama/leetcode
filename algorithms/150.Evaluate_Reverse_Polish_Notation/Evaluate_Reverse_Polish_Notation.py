class Solution:
    # @param tokens, a list of string
    # @return an integer
    def evalRPN(self, tokens):
        stack = []
        for str in tokens:
            if str not in '+-*/':
                tmp = int(str)
                stack.append(tmp)
            else:
                a = stack.pop()
                b = stack.pop()
                if str == '+': stack.append(b + a)
                elif str == '-': stack.append(b - a)
                elif str == '*': stack.append(b * a)
                elif str == '/': stack.append(int(b * 1.0 / a))
                print b, str, a, stack[-1]
        return stack[0]

s = Solution()
print s.evalRPN(["10","6","9","3","+","-11","*","/","*","17","+","5","+"]) # 22

import operator

class Solution:
    # @param tokens, a list of string
    # @return an integer
    def evalRPN(self, tokens):
        numerals, operators = [], {"+": operator.add, "-": operator.sub, "*": operator.mul, "/": operator.div}
        for token in tokens:
            if token not in operators:
                numerals.append(int(token))
            else:
                y, x = numerals.pop(), numerals.pop()
                numerals.append(int(operators[token](x * 1.0, y)))
        return numerals.pop()
    
if __name__ == "__main__":
    print Solution().evalRPN(["2", "1", "+", "3", "*"])
    print Solution().evalRPN(["4", "13", "5", "/", "+"])
    print Solution().evalRPN(["10","6","9","3","+","-11","*","/","*","17","+","5","+"])

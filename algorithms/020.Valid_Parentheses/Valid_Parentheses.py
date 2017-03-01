class Solution:
    # @return a boolean
    def isValid(self, s):
        stack, lookup = [], {"(": ")", "{": "}", "[": "]"}
        for parenthese in s:
            if parenthese in lookup:
                stack.append(parenthese)
            elif len(stack) == 0 or lookup[stack.pop()] != parenthese:
                return False
        return len(stack) == 0
# 1. 使用栈来保存'('

# 2. tmp 表示当前计算的一套完整的括号集的长度。完整的指的是消耗掉栈中所有的'('.

# 3. sum 表示数个完整的括号集的总长。

# 例子：

# 有一套完整的括号集，可以加到前面的一整套括号集上
#                      () (()())
#                       1    2  第二套括号集可以加过来

# 4. 不完整的括号集：

# 这种情况也是需要计算的。也可能是一个未完成的括号集，比如：

#       () (()()  在这里 ()() 是一个未完成的括号集，可以独立出来计算，作为
# 阶段性的结果

# 5. 栈为空时，出现一个')'，可以将sum置0.
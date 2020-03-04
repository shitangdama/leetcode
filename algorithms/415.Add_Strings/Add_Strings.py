

class Solution:

    def addStrings(self, num1: str, num2: str) -> str:

        result, carry = [], 0

        list1, list2 = list(num1), list(num2)
        while len(list1) > 0 or len(list2) > 0:
            val = carry
            if len(list1) > 0:
                val = val + int(list1.pop())
            if len(list2) > 0:
                val = val + int(list2.pop())

            result.append(val % 10)
            carry = val // 10

        if carry == 1:
            result.append(1)
        return "".join([str(num) for num in result[::-1]])
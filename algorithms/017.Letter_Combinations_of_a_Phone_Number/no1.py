# 全概率问题
# 迭代算法
class Solution:
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        lookup, result = ["", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"], []
        tmp = []
        for digit in digits:
            if len(result) == 0:
#                 将元素都放入
                if digit != 0 and digit != 1:
                    for c in lookup[int(digit)]:
                        result.append(c)
            else:
                tmp = result
                result = []
                for prefix in tmp:
                    for c in lookup[int(digit)]:
                        result.append(prefix+c)
        return result
                

s = Solution()
a = s.letterCombinations(2)
print(a)
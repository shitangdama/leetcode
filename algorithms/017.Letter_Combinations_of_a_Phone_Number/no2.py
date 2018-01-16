# 研究下dfs模板
# dfs
class Solution:
    def letterCombinations(self, digits):
        if not digits:
            return []
        lookup, result = ["", "", "abc", "def", "ghi", "jkl", "mno", \
                          "pqrs", "tuv", "wxyz"], []

        self.dfs(result, digits, 0, "", lookup)
        return result
# 控制元素在一起，这里的控制元素是digits和digits_len
# 返回元素result
# 返回元素比较重要，需要考察

    def dfs(self, result, digits, digits_len, cur, lookup):
        # 到底了
        if len(digits) == digits_len:
            result.append(cur)
        else:
            # 没到底
            for choice in lookup[int(digits[digits_len])]:
                self.dfs(result, digits, digits_len+1, cur+choice, lookup)

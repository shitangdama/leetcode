class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:

        result = []

        self.dfs(sorted(nums), [], result)
        return result


    def dfs(self, rest, pick, result):
        if not rest:
            result.append(pick)

        for i in range(len(rest)):
            if i > 0 and rest[i-1] == rest[i]:
                continue
            self.dfs(rest[:i]+rest[i+1:], pick+[rest[i]], result)

s = Solution()
print(s.permute([1,2,3]))

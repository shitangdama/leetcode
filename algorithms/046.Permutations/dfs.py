class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:

        result = []

        self.dfs(nums, [], result)
        return result


    def dfs(self, rest, pick, result):
        if not rest:
            result.append(pick)

        for i in range(len(rest)):
            self.dfs(rest[:i]+rest[i+1:], pick+[rest[i]], result)

s = Solution()
print(s.permute([1,2,3]))

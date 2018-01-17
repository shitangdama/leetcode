class Solution:
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        # 状态转移是
        # 1直接加上当前数字有解或者无解
        # 2当前目标减去当前数字的结果，该结果有解或者无解。
        candidates.sort()
        result = []
        dp = []
        for i in range(1, target):
            dp[i] = []
            # 这时候目标是i
            for num in candidates:
                if num > i:
                    # 不选取
                elif num <= i:
                    # 判断是否有解
                    # 有解的两种方式
                    # 第一种是
                    if num == i:
                        dp[i][num] = [num]
                    if 
        
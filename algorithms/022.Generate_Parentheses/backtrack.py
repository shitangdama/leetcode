class Solution:
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        ans = []
        def backtrick(s="", left=0, right=0):

            if len(s) == 2 * n:
                ans.append(s)
                return
            if left < n:
                backtrick(s+"(", left+1, right)
            if right < left:
                backtrick(s+")", left, right+1)
            
        backtrick()
        return ans
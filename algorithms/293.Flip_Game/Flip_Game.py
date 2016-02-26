class Solution(object):
    def generatePossibleNextMoves(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        result = []
        if not s:
            return result
        for i in range(len(s)-1):
            if s[i] == '+' and s[i+1] == '+':
                result += s[:i]+'--'+s[i+2:],
        return result

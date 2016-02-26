class Solution(object):
    def canWinNim(self, n):
        """
        :type n: int
        :rtype: bool
        """
        # basically check if the number can be divided by 4
        return n&3 != 0

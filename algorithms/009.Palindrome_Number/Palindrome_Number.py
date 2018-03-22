class Solution:
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x<0 and x%10 == 0 and x ==0:
            return false
        
        copy, reverse = x, 0
        while copy:
            reverse = reverse*10 + copy%10
            copy = int(copy/10)
            
        return reverse == x


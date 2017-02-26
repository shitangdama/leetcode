<<<<<<< HEAD
class Solution(object):
    def canPermutePalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        d = {}
        for c in s:
            if c in d:
                d[c] += 1
            else:
                d[c] = 1
        
        odd_count = 0
        for c in d:
            if d[c] & 1:
                odd_count += 1
        if odd_count > 1:
            return False
        return True
            
=======
class Solution(object):
    def canPermutePalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        d = {}
        for c in s:
            if c in d:
                d[c] += 1
            else:
                d[c] = 1
        
        odd_count = 0
        for c in d:
            if d[c] & 1:
                odd_count += 1
        if odd_count > 1:
            return False
        return True
            
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74

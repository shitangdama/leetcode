# Manacher's Algorithm

class Solution:
    def longestPalindrome(self, s):
        string = self.preProcess(s)
        palindrome = [0] * len(string) 
        center, right = 0, 0
        for i in range(1, len(string) - 1):
            i_mirror = 2 * center - i
            if right > i:
                palindrome[i] = min(right - i, palindrome[i_mirror])
            else:
                palindrome[i] = 0

            while string[i + 1 + palindrome[i]] == string[i - 1 - palindrome[i]]:
                palindrome[i] += 1

            if i + palindrome[i] > right:
                center, right = i, i + palindrome[i]       
        
        max_len, max_center = 0, 0
        for i in range(1, len(string) - 1):
            if palindrome[i] > max_len:
                max_len = palindrome[i]
                max_center = i
        start = (max_center - 1 - max_len) / 2
        return s[start : start + max_len]
    # ^开头$结尾
    def preProcess(self, s):
        if not s:
            return "^$"
        string = "^"
        for i in s:
            string +=  "#" + i
        string += "#$"
        return string

class Solution:
    def longestCommonPrefix(self, strs):
        if not strs:
            return ""
        longest = strs[0]
        for string in strs[1:]:
            i = 0
            while i < len(string) and i < len(longest) and string[i] == longest[i]:
                i += 1
            longest = longest[:i]
        return longest
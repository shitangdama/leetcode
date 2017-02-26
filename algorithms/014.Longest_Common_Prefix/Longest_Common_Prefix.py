# 有四种方式水平，垂直
class Solution:
    # @return a string
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

class Solution1(object):
    def longestCommonPrefix(self, strs):
        if not strs:
            return ""
        longest = strs[0]
        for i in range(len(strs[0])):
            char = strs[0][i]
            for string in strs[1:]:
                if len(string) == i or string[i] != char:
                    return strs[0][0:i]
                
        return longest
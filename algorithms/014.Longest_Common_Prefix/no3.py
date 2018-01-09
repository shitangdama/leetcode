class Solution:
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if not strs:
            return ""
        return self.find_Prefix(strs, 0, len(strs) - 1)
    
    def find_Prefix(self, strs, l, r):
        if l == r:
            return strs[l]
        else:
            mid = int((l + r)/2)
            left_string = self.find_Prefix(strs, r, mid)
            right_string = self.find_Prefix(strs, mid + 1, l)
            return self.common_prefix(left_string, right_string)
        
    def common_prefix(self, l_str, r_str):
        min_len = min(len(l_str), len(r_str))
        for i in range(min_len):
            if l_str[i] != r_str[i]:
                return l_str[0:i]
            
        return l_str[0:min_len]
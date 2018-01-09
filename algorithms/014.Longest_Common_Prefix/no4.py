class Solution:
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if not strs:
            return ""
        # 球最小长度
        min_len = 1111111
        for str in strs:
            min_len = min(len(str), min_len)
#             这里第一个str作为固定的str
# 为什么初始化要为1
        low = 1
        high = min_len
#         拿第一个长度
        while low <= high:
            mid = int((low + high)/2)
#             如果成功就上调，失败就下调
            if self.is_common_prefix(strs, mid):
                low = low + 1
            else:
                high = high - 1
        
        return strs[0][0:min(low, high)]
#         这里是判断范围，0-len时候是满足某长度
    def is_common_prefix(self, strs, len_str):
        for str in strs:
            if strs[0][0:len_str] != str[0:len_str]:
                return False
        return True


s = Solution()
a = s.longestCommonPrefix(["a","b"])
print(a)
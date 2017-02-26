class Solution:
    # @param s, a string
    # @return a list of strings
    def restoreIpAddresses(self, s):
        ret = []
        isValid = lambda x : str(int(x)) == x and int(x) < 256
        for i in range(1, 4):
            for j in range(1, 4):
                for k in range(1, 4):
                    sub = [s[0: i], s[i: i + j], s[i + j: i + j + k], s[i + j + k:]]
                    if '' not in sub and False not in map(isValid, sub):
                        ret.append('.'.join(sub))
        return ret

# debug
s = Solution()
print s.restoreIpAddresses('25525511134')

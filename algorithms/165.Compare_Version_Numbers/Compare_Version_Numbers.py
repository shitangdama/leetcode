# Time:  O(n)
# Space: O(n), this could be enhanced to O(1) by better but trivial string parsing
class Solution:
    # @param a, a string
    # @param b, a string
    # @return a boolean
    def compareVersion(self, version1, version2):
        v1, v2 = version1.split("."), version2.split(".")
        
        if len(v1) > len(v2):
            v2 += ['0' for _ in xrange(len(v1) - len(v2))]
        elif len(v1) < len(v2):
            v1 += ['0' for _ in xrange(len(v2) - len(v1))]
        
        i = 0
        while i < len(v1):
            if int(v1[i]) > int(v2[i]):
                return 1
            elif int(v1[i]) < int(v2[i]):
                return -1
            else:
                i += 1
        
        return 0

if __name__ == "__main__":
    print Solution().compareVersion("21.0", "121.1.0")
    print Solution().compareVersion("01", "1")
    print Solution().compareVersion("1", "1.0")


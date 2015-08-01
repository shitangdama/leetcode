# Time:  O(n)
# Space: O(1)


class Solution:
    # @return a string
    def convert(self, s, nRows):
        step, zigzag = 2 * nRows - 2, ""
        if s == None or len(s) == 0 or nRows <= 0:
            return ""
        if nRows == 1:
            return s
        for i in xrange(nRows):
            for j in xrange(i, len(s), step):
                zigzag += s[j]
                if i > 0 and i < nRows - 1 and j + step - 2 * i < len(s):
                    zigzag += s[j + step - 2 * i]
        return zigzag

if __name__ == "__main__":
    print Solution().convert("PAYPALISHIRING", 3)

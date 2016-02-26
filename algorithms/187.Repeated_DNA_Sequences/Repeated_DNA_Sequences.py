class Solution:
    # @param s, a string
    # @return a list of strings
    def findRepeatedDnaSequences(self, s):
        value = {'A': 0, 'C': 1, 'G': 2, 'T': 3}
        appeared = set()
        used = set()
        ans = []

        if len(s) <= 10:
            return ans

        hash = 0
        for i in range(10):
            hash = (hash << 2) | value[s[i]]
        appeared.add(hash)

        for i in range(10, len(s)):
            hash = ((hash << 2) | value[s[i]]) & ((1<<20) - 1)
            if hash in used:
                continue
            if hash in appeared:
                ans.append(s[i - 9: i + 1])
                used.add(hash)
            else:
                appeared.add(hash)
        return ans

# debug
s = Solution()
print s.findRepeatedDnaSequences('AAAAAAAAAAAA')

class Solution:
    # @param s, a list of 1 length strings, e.g., s = ['h','e','l','l','o']
    # @return nothing
    def reverseWords(self, s):
        self.reverse(s, 0, len(s))
        
        i = 0
        for j in xrange(len(s) + 1):
            if j == len(s) or s[j] == ' ':
                self.reverse(s, i, j)
                i = j + 1
    
    def reverse(self, s, begin, end):
        for i in xrange((end - begin) / 2):
            s[begin + i], s[end - 1 - i] = s[end - 1 - i], s[begin + i]

if __name__ == '__main__':
    s = ['h','e','l','l','o', ' ', 'w', 'o', 'r', 'l', 'd']
    Solution().reverseWords(s)
    print s

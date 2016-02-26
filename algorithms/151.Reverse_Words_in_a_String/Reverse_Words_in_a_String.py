class Solution:
    # @param s, a string
    # @return a string
    def reverseWords(self, s):
        return ' '.join(list(reversed(s.split())))

if __name__ == '__main__':
    print Solution().reverseWords('hello world')

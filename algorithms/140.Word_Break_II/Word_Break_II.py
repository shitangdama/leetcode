class Solution:
    # @param s, a string
    # @param dict, a set of string
    # @return a list of strings
    def wordBreak(self, s, dict):
        n = len(s)
        possible = [False for _ in xrange(n)]
        valid = [[False] * n for _ in xrange(n)]
        for i in xrange(n):
            if s[:i+1] in dict:
                possible[i] = True
                valid[0][i] = True
            for j in xrange(i):
                if possible[j] and s[j+1:i+1] in dict:
                    valid[j+1][i] = True
                    possible[i] = True
        result = []
        if possible[n-1]:
            self.genPath(s, valid, 0, [], result)
        return result
    
    def genPath(self, s, valid, start, path, result):
        if start == len(s):
            result.append(" ".join(path))
            return
        for i in xrange(start, len(s)):
            if valid[start][i]:
                path += [s[start:i+1]]
                self.genPath(s, valid, i + 1, path, result)
                path.pop()

if __name__ == "__main__":
    print Solution().wordBreak("catsanddog", ["cat", "cats", "and", "sand", "dog"])

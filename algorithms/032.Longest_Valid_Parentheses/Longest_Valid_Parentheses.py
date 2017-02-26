# Time:  O(n)
# Space: O(1)

class Solution:
    # @param s, a string
    # @return an integer
    def longestValidParentheses(self, s):
        longest = 0
        
        start, depth = -1, 0
        for i in xrange(len(s)):
            if s[i] == "(":
                depth += 1
            else:
                depth -= 1
                if depth < 0:
                    start, depth = i, 0
                elif depth == 0:
                    longest = max(longest, i - start)
        
        start, depth = len(s), 0
        for i in reversed(xrange(len(s))):
            if s[i] == ")":
                depth += 1
            else:
                depth -= 1
                if depth < 0:
                    start, depth = i, 0
                elif depth == 0:
                    longest = max(longest, start - i)
        
        return longest

# Time:  O(n)
# Space: O(n)
class Solution2:
    # @param s, a string
    # @return an integer
    def longestValidParentheses(self, s):
        longest, last, indices = 0, -1, []
        for i in xrange(len(s)):
            if s[i] == '(':
                indices.append(i)
            elif not indices:
                last = i
            else:
                indices.pop()
                if not indices:
                    longest = max(longest, i - last)
                else:
                    longest = max(longest, i - indices[-1])
        return longest

if __name__ == "__main__":
    print Solution().longestValidParentheses("()")
    print Solution().longestValidParentheses(")()())")

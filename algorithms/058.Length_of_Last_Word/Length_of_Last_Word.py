<<<<<<< HEAD
# Time:  O(n)
# Space: O(1)

class Solution:
    # @param s, a string
    # @return an integer
    def lengthOfLastWord(self, s):
        length = 0
        for i in reversed(s):
            if i == ' ':
                if length:
                    break
            else:
                length += 1
        return length

# Time:  O(n)
# Space: O(n)
class Solution2:
    # @param s, a string
    # @return an integer
    def lengthOfLastWord(self, s):
        return len(s.strip().split(" ")[-1])

if __name__ == "__main__":
    print Solution().lengthOfLastWord("Hello World")
    print Solution2().lengthOfLastWord("")
=======
# Time:  O(n)
# Space: O(1)

class Solution:
    # @param s, a string
    # @return an integer
    def lengthOfLastWord(self, s):
        length = 0
        for i in reversed(s):
            if i == ' ':
                if length:
                    break
            else:
                length += 1
        return length

# Time:  O(n)
# Space: O(n)
class Solution2:
    # @param s, a string
    # @return an integer
    def lengthOfLastWord(self, s):
        return len(s.strip().split(" ")[-1])

if __name__ == "__main__":
    print Solution().lengthOfLastWord("Hello World")
    print Solution2().lengthOfLastWord("")
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74

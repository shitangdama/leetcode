<<<<<<< HEAD
# Time:  O(n)
# Space: O(n)

class Solution:
    # @param num, a list of integer
    # @return an integer
    def longestConsecutive(self, num):
        result, lengths = 1, {key: 0 for key in num}
        for i in num:
            if lengths[i] == 0:
                lengths[i] = 1
                left, right = lengths.get(i - 1, 0), lengths.get(i + 1, 0)
                length = 1 + left + right
                result, lengths[i - left], lengths[i + right] = max(result, length), length, length
        return result

if __name__ == "__main__":
    print Solution().longestConsecutive([100, 4, 200, 1, 3, 2])
=======
# Time:  O(n)
# Space: O(n)

class Solution:
    # @param num, a list of integer
    # @return an integer
    def longestConsecutive(self, num):
        result, lengths = 1, {key: 0 for key in num}
        for i in num:
            if lengths[i] == 0:
                lengths[i] = 1
                left, right = lengths.get(i - 1, 0), lengths.get(i + 1, 0)
                length = 1 + left + right
                result, lengths[i - left], lengths[i + right] = max(result, length), length, length
        return result

if __name__ == "__main__":
    print Solution().longestConsecutive([100, 4, 200, 1, 3, 2])
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74

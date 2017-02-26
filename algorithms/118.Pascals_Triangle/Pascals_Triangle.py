<<<<<<< HEAD
# Time:  O(n^2)
# Space: O(n)

class Solution:
    # @return a list of lists of integers
    def generate(self, numRows):
        result = []
        for i in xrange(numRows):
            result.append([])
            for j in xrange(i + 1):
                if j in (0, i):
                    result[i].append(1)
                else:
                    result[i].append(result[i - 1][j - 1] + result[i - 1][j])
        return result

if __name__ == "__main__":
    print Solution().generate(5)

=======
# Time:  O(n^2)
# Space: O(n)

class Solution:
    # @return a list of lists of integers
    def generate(self, numRows):
        result = []
        for i in xrange(numRows):
            result.append([])
            for j in xrange(i + 1):
                if j in (0, i):
                    result[i].append(1)
                else:
                    result[i].append(result[i - 1][j - 1] + result[i - 1][j])
        return result

if __name__ == "__main__":
    print Solution().generate(5)

>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74

# Time: O(n)
# Space: O(1)
class Solution:
    # @param {integer[]} numbers
    # @param {integer} target
    # @return {integer[]}
    def twoSum(self, numbers, target):
        start, end = 0, len(numbers) - 1

        while start != end:
            sum = numbers[start] + numbers[end]
            if sum > target:
                end -= 1
            elif sum < target:
                start += 1
            else:
                return [start + 1, end + 1]

if __name__ == "__main__":
    print Solution().twoSum([2, 7, 11, 15], 9)

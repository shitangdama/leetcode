# Time:  O(n)
# Space: O(1)

class Solution:
    # @param {integer[]} nums
    # @return {void} Do not return anything, modify nums in-place instead.
    def nextPermutation(self, num):
        k, l = -1, 0
        for i in xrange(len(num) - 1):
            if num[i] < num[i + 1]:
                k = i

        if k == -1:
            num.reverse()
            return

        for i in xrange(len(num)):
            if num[i] > num[k]:
                l = i

        num[k], num[l] = num[l], num[k]
        num[k + 1:] = num[:k:-1]

if __name__ == "__main__":
    num = [1, 4, 3, 2]
    Solution().nextPermutation(num)
    print num
    Solution().nextPermutation(num)
    print num
    Solution().nextPermutation(num)
    print num

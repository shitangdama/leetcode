from collections import deque

class Solution:
    # @param {integer[]} nums
    # @param {integer} k
    # @return {integer[]}
    def maxSlidingWindow(self, nums, k):
        q = deque()
        max_numbers = []

        for i in xrange(k):
            while q and nums[i] >= nums[q[-1]]:
                q.pop()
            q.append(i)

        for i in xrange(k, len(nums)):
            max_numbers.append(nums[q[0]])

            while q and nums[i] >= nums[q[-1]]:
                q.pop()

            while q and q[0] <= i - k:
                q.popleft()

            q.append(i)

        if q:
            max_numbers.append(nums[q[0]])

        return max_numbers


from collections import deque
class Solution(object):
    def maxSlidingWindow(self, nums, k):
        if not nums: return []
        res = []
        dq = deque()  # store index
        for i in xrange(len(nums)):
            if dq and dq[0]<i-k+1:  # out of the window
                dq.popleft()
            while dq and nums[dq[-1]]<nums[i]:  # remove impossible candidate
                dq.pop()
            dq.append(i)
            if i>k-2:
                res.append(nums[dq[0]])
        return res

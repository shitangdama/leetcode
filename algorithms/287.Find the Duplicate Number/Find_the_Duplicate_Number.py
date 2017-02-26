class Solution(Thread):
def findDuplicate(self, nums):
    """
    :type nums: List[int]
    :rtype: int
    """

    slow = nums[0]
    fast = nums[nums[0]]
    while (slow != fast):
        slow = nums[slow]
        fast = nums[nums[fast]]

    fast = 0;
    while (fast != slow):
        fast = nums[fast]
        slow = nums[slow]

    return slow

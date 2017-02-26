<<<<<<< HEAD
# Time:  O(n)
# Space: O(logn)

# Definition for a  binary tree node
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    # @param num, a list of integers
    # @return a tree node
    def sortedArrayToBST(self, num):
        return self.sortedArrayToBSTRecu(num, 0, len(num))
    
    def sortedArrayToBSTRecu(self, num, start, end):
        if start == end:
            return None
        mid = start + (end - start) / 2
        node = TreeNode(num[mid])
        node.left = self.sortedArrayToBSTRecu(num, start, mid)
        node.right = self.sortedArrayToBSTRecu(num, mid + 1, end)
        return node
    
if __name__ == "__main__":
    num = [1, 2, 3]
    result = Solution().sortedArrayToBST(num)
    print result.val
    print result.left.val
    print result.right.val
=======
# Time:  O(n)
# Space: O(logn)

# Definition for a  binary tree node
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    # @param num, a list of integers
    # @return a tree node
    def sortedArrayToBST(self, num):
        return self.sortedArrayToBSTRecu(num, 0, len(num))
    
    def sortedArrayToBSTRecu(self, num, start, end):
        if start == end:
            return None
        mid = start + (end - start) / 2
        node = TreeNode(num[mid])
        node.left = self.sortedArrayToBSTRecu(num, start, mid)
        node.right = self.sortedArrayToBSTRecu(num, mid + 1, end)
        return node
    
if __name__ == "__main__":
    num = [1, 2, 3]
    result = Solution().sortedArrayToBST(num)
    print result.val
    print result.left.val
    print result.right.val
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74

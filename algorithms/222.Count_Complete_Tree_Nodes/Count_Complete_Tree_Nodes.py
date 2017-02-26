# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param {TreeNode} root
    # @return {integer}
    def countNodes(self, root):
        if root is None:
            return 0
        
        node, level = root, 0
        while node.left is not None:
            node = node.left
            level += 1
        
        # Binary search.
        left, right = 2 ** level, 2 ** (level + 1)
        while left < right:
            mid = left + (right - left) / 2
            if not self.exist(root, mid):
                right = mid
            else:
                left = mid + 1
                
        return left - 1
    
    # Check if the nth node exist.
    def exist(self, root, n):
        k = 1
        while k <= n:
            k <<= 1
        k >>= 2
        
        node = root
        while k > 0:
            if (n & k) == 0:
                node = node.left
            else:
                node = node.right
            k >>= 1
        return node is not None

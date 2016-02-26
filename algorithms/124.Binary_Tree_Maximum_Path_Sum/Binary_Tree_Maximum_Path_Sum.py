# Definition for a  binary tree node
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def dfs(self, root):
        if root is None:
            return 0
        left = max(0, self.dfs(root.left))
        right = max(0, self.dfs(root.right))
        self.ret = max(self.ret, left + right + root.val)
        return max(left, right) + root.val

    # @param root, a tree node
    # @return an integer
    def maxPathSum(self, root):
        self.ret = -(1<<31)

        self.dfs(root)
        return self.ret

# Definition for a  binary tree node
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    maxSum = float("-inf")
    # @param root, a tree node
    # @return an integer
    def maxPathSum(self, root):
        self.maxPathSumRecu(root)
        return self.maxSum
    
    def maxPathSumRecu(self, root):
        if root is None:
            return 0
        left = max(0, self.maxPathSumRecu(root.left))
        right = max(0, self.maxPathSumRecu(root.right))
        self.maxSum = max(self.maxSum, root.val + left + right)
        return root.val + max(left, right)
    
if __name__ == "__main__":
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    result = Solution().maxPathSum(root)
    print result

    Status API Training Shop Blog About Help 

    © 2015 GitHub, Inc. Terms Privacy Security Contact 
    
# debug
s = Solution()
x = TreeNode(0)
print s.maxPathSum(x)

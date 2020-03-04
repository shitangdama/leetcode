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

if __name__ == "__main__":
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    result = Solution().maxPathSum(root)


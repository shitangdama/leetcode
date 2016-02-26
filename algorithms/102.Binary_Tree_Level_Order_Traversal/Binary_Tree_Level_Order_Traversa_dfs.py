# Definition for a  binary tree node
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    # @param root, a tree node
    # @return a list of lists of integers
    def levelOrder(self, root):
        ret = []
        def dfs(root, level):
            if root:
                if level >= len(ret):
                    ret.append([])
                ret[level].append(root.val)
                dfs(root.left, level + 1)
                dfs(root.right, level + 1)

        dfs(root, 0)
        return ret


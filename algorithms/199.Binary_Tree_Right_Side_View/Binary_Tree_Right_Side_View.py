# Definition for a  binary tree node
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    # @param root, a tree node
    # @return a list of integers
    def rightSideView(self, root):
        result = []
        self.rightSideViewDFS(root, 1, result)
        return result
    
    def rightSideViewDFS(self, node, depth, result):
        if not node:
            return
        
        if depth > len(result):
            result.append(node.val)
        
        self.rightSideViewDFS(node.right, depth+1, result)
        self.rightSideViewDFS(node.left, depth+1, result)

# BFS solution
# Time:  O(n)
# Space: O(n)        
class Solution2:
    # @param root, a tree node
    # @return a list of integers
    def rightSideView(self, root):
        if root is None:
            return []
            
        result, current = [], [root]
        while current:
            next_level = []
            for i, node in enumerate(current):
                if node.left:
                    next_level.append(node.left)
                if node.right:
                    next_level.append(node.right)
                if i == len(current) - 1:
                    result.append(node.val)
            current = next_level
            
        return result

if __name__ == "__main__":
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.right = TreeNode(5)
    root.right.right = TreeNode(4)
    result = Solution().rightSideView(root)
    print result

# Definition for a binary tree node
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    # @param root, a tree node
    # @return a list of integers
    def rightSideView(self, root):
        ret = []
        def dfs(root, deep):
            if root:
                if len(ret) <= deep:
                    ret.append(root.val)
                else:
                    ret[deep] = root.val
                dfs(root.left, deep + 1)
                dfs(root.right, deep + 1)
        dfs(root, 0)
        return ret

# debug
s = Solution()
r = TreeNode(2)
print s.rightSideView(r)

# Definition for a  binary tree node
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def dfs(self, root, sum):
        if root == None:
            return
        self.path.append(root.val)
        sum -= root.val
        if root.left == None and root.right == None:
            if sum == 0:
                self.res.append(self.path[:])
        else:
            if root.left:
                self.dfs(root.left, sum)
            if root.right:
                self.dfs(root.right, sum)
        self.path.pop()

    # @param root, a tree node
    # @param sum, an integer
    # @return a list of lists of integers
    def pathSum(self, root, sum):
        self.res = []
        self.path = []
        self.dfs(root, sum)
        return self.res

class Solution:
    # @param root, a tree node
    # @param sum, an integer
    # @return a list of lists of integers
    def pathSum(self, root, sum):
        return self.pathSumRecu([], [], root, sum)

    
    def pathSumRecu(self, result, cur, root, sum):
        if root is None:
            return result
        
        if root.left is None and root.right is None and root.val == sum:
            result.append(cur + [root.val])
            return result
        
        cur.append(root.val)
        self.pathSumRecu(result, cur, root.left, sum - root.val)
        self.pathSumRecu(result, cur,root.right, sum - root.val)
        cur.pop()
        return result
    
if __name__ == "__main__":
    root = TreeNode(5)

    print Solution().pathSum(root, 5)

# debug
root = TreeNode(1)
sum = 1
s  = Solution()
print s.pathSum(root, sum)

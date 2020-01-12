# Definition for a  binary tree node
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    # @param root, a tree node
    # @param sum, an integer
    # @return a list of lists of integers
    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
        return self.dfs([], [], root, sum)


    def dfs(self, result, cur, root, sum):
        if root is None:
            return result

        if root.left is None and root.right is None and sum == root.val:
            result.append(cur + [root.val])
            return result

        cur.append(root.val)
        self.dfs(result, cur, root.left, sum - root.val)
        self.dfs(result, cur,root.right, sum - root.val)
        cur.pop()
        return result

if __name__ == "__main__":
    root = TreeNode(5)

    print Solution().pathSum(root, 5)

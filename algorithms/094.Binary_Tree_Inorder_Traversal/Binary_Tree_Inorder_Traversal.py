"""
Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        this.val = val
        this.left, this.right = None, None
"""
# 先把迭代到最左边的叶子节点，把所有途中的root放进stack，当左边走不通了，开始往res里面存数，并往右边走。
class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:

        res, stack = [], []
        while stack or root:
            if root:
                stack.append(root)
                root = root.left
            else:
                node = stack.pop()
                res.append(node.val)
                root = node.right
        return res
# Time:  O(n)
# Space: O(1)
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

# # Morris Traversal Solution
# class Solution:
#     # @param root, a tree node
#     # @return a list of integers
#     def postorderTraversal(self, root):
#         dummy = TreeNode(0)
#         dummy.left = root
#         result, cur = [], dummy
#         while cur:
#             if cur.left is None:
#                 cur = cur.right
#             else:
#                 node = cur.left
#                 while node.right and node.right != cur:
#                     node = node.right

#                 if node.right is None:
#                     node.right = cur
#                     cur = cur.left
#                 else:
#                     result += self.traceBack(cur.left, node)
#                     node.right = None
#                     cur = cur.right

#         return result

#     def traceBack(self, frm, to):
#         result, cur = [], frm
#         while cur is not to:
#             result.append(cur.val)
#             cur = cur.right
#         result.append(to.val)
#         result.reverse()
#         return result

class Solution2(object):
    def inorderTraversal(self, root):
        self.res = []
        self.dfs(root)
        return self.res

    def dfs(self, root):
        if not root:
            return
        self.dfs(root.left)
        self.res.append(root.val)
        self.dfs(root.right)
if __name__ == "__main__":
    root = TreeNode(1)
    root.right = TreeNode(2)
    root.right.left = TreeNode(3)
    result = Solution().postorderTraversal(root)
    print result

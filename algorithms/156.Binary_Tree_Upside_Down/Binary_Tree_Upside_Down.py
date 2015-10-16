# Definition for a  binary tree node
class TreeNode:
     def __init__(self, x):
         self.val = x
         self.left = None
         self.right = None

class Solution:
    # @param root, a tree node
    # @return root of the upside down tree
    def upsideDownBinaryTree(self, root):
        if root is None:
            return root
        p,parent,parentright = root,None,None
        while p:
            left = p.left
            p.left = parentright
            parentright = p.right
            p.right = parent
            parent = p
            p = left
        return parent

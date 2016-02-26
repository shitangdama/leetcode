# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def closestValue(self, root, target):
        """
        :type root: TreeNode
        :type target: float
        :rtype: int
        """
        # basically in-order travesal and find the closest
        prev = 0x7fffffffffffffff
        result = 0x7fffffffffffffff
        path = [root]
        while path:
            cur = path[-1]
            if cur:
                path.append(cur.left)
            else:
                path.pop(-1)
                if path:
                    cur = path.pop(-1)
                    curdist = abs(cur.val - target)
                    if curdist > prev:
                        return result
                    else:
                        result = cur.val
                        prev = curdist
                    path.append(cur.right)
        return result
        

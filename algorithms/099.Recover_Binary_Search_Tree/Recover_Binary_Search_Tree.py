<<<<<<< HEAD
# Time:  O(n)
# Space: O(1)
# Definition for a  binary tree node
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None    
    
    def __repr__(self):
        if self:
            serial = []
            queue = [self]

            while queue:
                cur = queue[0]
                
                if cur:
                    serial.append(cur.val)
                    queue.append(cur.left)
                    queue.append(cur.right)
                else:
                    serial.append("#")
                
                queue = queue[1:]
                
            while serial[-1] == "#":
                serial.pop()
                
            return repr(serial)
                
        else:
            return None

class Solution:
    # @param root, a tree node
    # @return a tree node
    def recoverTree(self, root):
        return self.MorrisTraversal(root)
    
    def MorrisTraversal(self, root):
        if root is None:
            return
        broken = [None, None]
        pre, cur = None, root
        
        while cur:
            if cur.left is None:
                self.detectBroken(broken, pre, cur)
                pre = cur
                cur = cur.right
            else:
                node = cur.left
                while node.right and node.right != cur:
                    node = node.right
                    
                if node.right is None:
                    node.right =cur
                    cur = cur.left
                else:
                    self.detectBroken(broken, pre, cur)
                    node.right = None
                    pre = cur
                    cur = cur.right
        
        broken[0].val, broken[1].val = broken[1].val, broken[0].val
        
        return root
    
    def detectBroken(self, broken, pre, cur):
        if pre and pre.val > cur.val:
            if broken[0] is None:
                broken[0] = pre
            broken[1] = cur
            
if __name__ == "__main__":
    root = TreeNode(0)
    root.left = TreeNode(1)
    print root
    print Solution().recoverTree(root)
=======
# Time:  O(n)
# Space: O(1)
# Definition for a  binary tree node
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None    
    
    def __repr__(self):
        if self:
            serial = []
            queue = [self]

            while queue:
                cur = queue[0]
                
                if cur:
                    serial.append(cur.val)
                    queue.append(cur.left)
                    queue.append(cur.right)
                else:
                    serial.append("#")
                
                queue = queue[1:]
                
            while serial[-1] == "#":
                serial.pop()
                
            return repr(serial)
                
        else:
            return None

class Solution:
    # @param root, a tree node
    # @return a tree node
    def recoverTree(self, root):
        return self.MorrisTraversal(root)
    
    def MorrisTraversal(self, root):
        if root is None:
            return
        broken = [None, None]
        pre, cur = None, root
        
        while cur:
            if cur.left is None:
                self.detectBroken(broken, pre, cur)
                pre = cur
                cur = cur.right
            else:
                node = cur.left
                while node.right and node.right != cur:
                    node = node.right
                    
                if node.right is None:
                    node.right =cur
                    cur = cur.left
                else:
                    self.detectBroken(broken, pre, cur)
                    node.right = None
                    pre = cur
                    cur = cur.right
        
        broken[0].val, broken[1].val = broken[1].val, broken[0].val
        
        return root
    
    def detectBroken(self, broken, pre, cur):
        if pre and pre.val > cur.val:
            if broken[0] is None:
                broken[0] = pre
            broken[1] = cur
            
if __name__ == "__main__":
    root = TreeNode(0)
    root.left = TreeNode(1)
    print root
    print Solution().recoverTree(root)
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74

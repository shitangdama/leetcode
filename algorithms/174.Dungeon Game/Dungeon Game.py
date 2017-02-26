
# Definition for a  binary tree node
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class BSTIterator:
    # @param root, a binary search tree's root node
    def __init__(self, root):
        self.stack = []
        while root:
            self.stack.append(root)
            root = root.left

    # @return a boolean, whether we have a next smallest number
    def hasNext(self):
        return len(self.stack) != 0

    # @return an integer, the next smallest number
    def next(self):
        top = self.stack.pop()
        right = top.right
        while right:
            self.stack.append(right)
            right = right.left
        return top.val
# Definition for a  binary tree node
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class BSTIterator:
    # @param root, a binary search tree's root node
    def __init__(self, root):
        self.stack = []
        self.cur = root

    # @return a boolean, whether we have a next smallest number
    def hasNext(self):
        return self.stack or self.cur

    # @return an integer, the next smallest number
    def next(self):
        while self.cur:
            self.stack.append(self.cur)
            self.cur = self.cur.left
        
        self.cur = self.stack.pop()
        node = self.cur
        self.cur = self.cur.right
        
        return node.val
        
if __name__ == "__main__":
    root = TreeNode(2)
    root.left = TreeNode(1)
    
    # Your BSTIterator will be called like this:
    i, v = BSTIterator(root), []
    while i.hasNext(): v.append(i.next())
    
    print v

# debug
root = TreeNode(0)
i, v = BSTIterator(root), []
while i.hasNext(): v.append(i.next())

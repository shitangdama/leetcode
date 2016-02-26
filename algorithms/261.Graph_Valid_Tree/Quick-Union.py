class Solution(object):
    def validTree(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: bool
        """
        root = [i for i in range(n)]
        for i in edges:
            root1 = self.find(root, i[0])
            root2 = self.find(root, i[1])
            if root1 == root2:
                return False
            else:
                root[root1] = root2
        return len(edges) == n - 1
        
    def find(self, root, e):
        if root[e] == e:
            return e
        else:
            return self.find(root, root[e])

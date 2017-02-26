class Solution(object):
    def validTree(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: bool
        """
        if n == 1:
            return True
            
        if len(edges) == 0 or len(edges) < n - 1:
            return False    
        s = set()
        s.add(edges[0][0])
        s.add(edges[0][1])
        l = [s]
        for i in range(1, len(edges)):
            first = self.find(edges[i][0], l)
            second = self.find(edges[i][1], l)
            if first == -1 and second == -1:
                l.append(set([edges[i][0], edges[i][1]]))
            elif first == second:
                return False
            elif first != -1 and second != -1:
                if first > second:
                    temp = l[first]
                    del l[first]
                    l[second] = l[second] | temp
                else:
                    temp = l[second]
                    del l[second]
                    l[first] = l[first] | temp
            else:
                if first != -1:
                    l[first].add(edges[i][1])
                else:
                    l[second].add(edges[i][0])
            
        if len(l) == 1:
            return True
        else:
            return False
            
    def find(self, e, l):
        for i in range(len(l)):
            if e in l[i]:
                return i
        return -1

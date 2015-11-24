class ZigzagIterator(object):

    def __init__(self, v1, v2):
        """
        Initialize your data structure here.
        :type v1: List[int]
        :type v2: List[int]
        """
        self.v = []
        i = 0
        j = 0
        while i < len(v1) or j < len(v2):
            if i < len(v1):
                self.v.append(v1[i])
                i += 1
            if j < len(v2):
                self.v.append(v2[j])
                j += 1
        self.i = 0
        

    def next(self):
        """
        :rtype: int
        """
        self.i += 1
        return self.v[self.i-1]

    def hasNext(self):
        """
        :rtype: bool
        """
        return self.i < len(self.v)

# Your ZigzagIterator object will be instantiated and called as such:
# i, v = ZigzagIterator(v1, v2), []
# while i.hasNext(): v.append(i.next())

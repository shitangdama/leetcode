class Solution(object):
    def wordPattern(self, pattern, str):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """
        # can be solved by two dictionaries
        a = list(pattern)
        b = str.split()
        if len(a) != len(b):
            return False
        d1 = {}
        d2 = {}
        for i in zip(a,b):
            d1[i[0]]=i[1]
            d2[i[1]]=i[0]
        return len(d1) == len(d2)

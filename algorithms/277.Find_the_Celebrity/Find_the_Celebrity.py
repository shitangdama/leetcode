class Solution(object):
    def findCelebrity(self, n):
    # a better way leverage the fact that there is only one possible candidate
        candidate = 0
        for i in xrange(1,n):
            if knows(candidate, i):
                candidate = i
        for i in range(n):
            if i != candidate and knows(candidate, i) or not knows(i, candidate):
                return -1
        return candidate

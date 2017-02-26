<<<<<<< HEAD
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
=======
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
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74

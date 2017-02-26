<<<<<<< HEAD
class Solution(object):
    def hIndex(self, citations):
        """
        :type citations: List[int]
        :rtype: int
        """
        citations.sort(reverse=True)
        for i in range(len(citations)):
            if citations[i] < i+1:
                return i
        return len(citations)
=======
class Solution(object):
    def hIndex(self, citations):
        """
        :type citations: List[int]
        :rtype: int
        """
        citations.sort(reverse=True)
        for i in range(len(citations)):
            if citations[i] < i+1:
                return i
        return len(citations)
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74

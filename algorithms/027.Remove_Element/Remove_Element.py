<<<<<<< HEAD
# Time:  O(n)
# Space: O(1)

class Solution:
    # @param    A       a list of integers
    # @param    elem    an integer, value need to be removed
    # @return an integer
    def removeElement(self, A, elem):
        i, last = 0, len(A) - 1
        while i <= last:
            if A[i] == elem:
                A[i], A[last] = A[last], A[i]
                last -= 1
            else:
                i += 1
        return last + 1
    
if __name__ == "__main__":
    print Solution().removeElement([1, 2, 3, 4, 5, 2, 2], 2)
=======
# Time:  O(n)
# Space: O(1)

class Solution:
    # @param    A       a list of integers
    # @param    elem    an integer, value need to be removed
    # @return an integer
    def removeElement(self, A, elem):
        i, last = 0, len(A) - 1
        while i <= last:
            if A[i] == elem:
                A[i], A[last] = A[last], A[i]
                last -= 1
            else:
                i += 1
        return last + 1
    
if __name__ == "__main__":
    print Solution().removeElement([1, 2, 3, 4, 5, 2, 2], 2)
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74

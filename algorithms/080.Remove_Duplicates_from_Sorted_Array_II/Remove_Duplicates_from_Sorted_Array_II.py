<<<<<<< HEAD
# Time:  O(n)
# Space: O(1)

class Solution:
    # @param a list of integers
    # @return an integer
    def removeDuplicates(self, A):
        if not A:
            return 0
        
        last, i, same = 0, 1, False
        while i < len(A):
            if A[last] != A[i] or not same:
                same = A[last] == A[i]
                last += 1
                A[last] = A[i]
            i += 1
            
        return last + 1

if __name__ == "__main__":
    print Solution().removeDuplicates([1, 1, 1, 2, 2, 3])
=======
# Time:  O(n)
# Space: O(1)

class Solution:
    # @param a list of integers
    # @return an integer
    def removeDuplicates(self, A):
        if not A:
            return 0
        
        last, i, same = 0, 1, False
        while i < len(A):
            if A[last] != A[i] or not same:
                same = A[last] == A[i]
                last += 1
                A[last] = A[i]
            i += 1
            
        return last + 1

if __name__ == "__main__":
    print Solution().removeDuplicates([1, 1, 1, 2, 2, 3])
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74

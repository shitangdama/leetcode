<<<<<<< HEAD
class Solution:
    def sort(self, A, flag, index):
        start, end = index, len(A) - 1
        while start <= end:
            while start <= end and A[start] == flag:
                start += 1
            while start <= end and A[end] != flag:
                end -= 1
            if start <= end:
                A[start], A[end] = A[end], A[start]
                start += 1
                end -= 1
        return start
    
    # @param A a list of integers
    # @return nothing, sort in place
    def sortColors(self, A):
        self.sort(A, 1, self.sort(A, 0, 0))

# Time:  O(n)
# Space: O(1)
class Solution:
    # @param A a list of integers
    # @return nothing, sort in place
    def sortColors(self, A):
        i, last_zero, first_two = 0, -1, len(A)
        
        while i < first_two:
            if A[i] == 0:
                last_zero += 1
                A[last_zero], A[i] = A[i], A[last_zero]
            elif A[i] == 2:
                first_two -= 1
                A[first_two], A[i] = A[i], A[first_two]
                i -= 1
            i += 1

if __name__ == "__main__":
    A = [2, 1, 1, 0, 0, 2]
    Solution().sortColors(A)
    print A
=======
class Solution:
    def sort(self, A, flag, index):
        start, end = index, len(A) - 1
        while start <= end:
            while start <= end and A[start] == flag:
                start += 1
            while start <= end and A[end] != flag:
                end -= 1
            if start <= end:
                A[start], A[end] = A[end], A[start]
                start += 1
                end -= 1
        return start
    
    # @param A a list of integers
    # @return nothing, sort in place
    def sortColors(self, A):
        self.sort(A, 1, self.sort(A, 0, 0))

# Time:  O(n)
# Space: O(1)
class Solution:
    # @param A a list of integers
    # @return nothing, sort in place
    def sortColors(self, A):
        i, last_zero, first_two = 0, -1, len(A)
        
        while i < first_two:
            if A[i] == 0:
                last_zero += 1
                A[last_zero], A[i] = A[i], A[last_zero]
            elif A[i] == 2:
                first_two -= 1
                A[first_two], A[i] = A[i], A[first_two]
                i -= 1
            i += 1

if __name__ == "__main__":
    A = [2, 1, 1, 0, 0, 2]
    Solution().sortColors(A)
    print A
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74

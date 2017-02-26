<<<<<<< HEAD
class Solution:
    #@param A: sorted integer array A which has m elements, 
    #          but size of A is m+n
    #@param B: sorted integer array B which has n elements
    #@return: void
    def mergeSortedArray(self, A, m, B, n):
        for i in range(n):
            A[i+m] = B[i]
        A.sort()

=======
class Solution:
    #@param A: sorted integer array A which has m elements, 
    #          but size of A is m+n
    #@param B: sorted integer array B which has n elements
    #@return: void
    def mergeSortedArray(self, A, m, B, n):
        for i in range(n):
            A[i+m] = B[i]
        A.sort()

>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74

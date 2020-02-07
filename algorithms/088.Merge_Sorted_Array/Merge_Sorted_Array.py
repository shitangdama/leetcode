class Solution:
    #@param A: sorted integer array A which has m elements,
    #          but size of A is m+n
    #@param B: sorted integer array B which has n elements
    #@return: void
    def merge(self, nums1, m, nums2, n):
        # for i in range(n):
        #     A[i+m] = B[i]
        # A.sort()

    # def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        i, j, k = m-1, n-1, m+n-1
        while i >= 0 and j >=0:
            if nums1[i] > nums2[j]:
                nums1[k] = nums1[i]
                k = k-1
                i = i-1
            else:
                nums1[k] = nums2[j]
                k = k-1
                j = j-1
        if j > 0:
            nums1[:n] = nums2[:n]


a = [1,2,3,0,0,0]
m = 3
b = [2,5,6]
n = 3

Solution().merge(a, m, b, n)

print(a)
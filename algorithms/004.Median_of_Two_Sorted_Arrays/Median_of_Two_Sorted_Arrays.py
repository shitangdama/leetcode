# 1. 我们借用findKthNumber的思想。先实现findKthNumber，如果是偶数个，则把中间2个加起来平均，奇数就用中间的。

# 2. 为了达到LOG级的复杂度，我们可以这样：

# 每次在A，B取前k/2个元素。有以下这些情况：

# 1).  A的元素不够k/2. 则我们可以丢弃B前k/2. 反之亦然
# 2). A[mid] < B[mid] (mid是k/2 -1索引处的元素）。
# using list slicing (O(k)) may be slower than solution1
class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        
        all_len = len(nums1)+len(nums2)
        if all_len%2 ==1:
            return self.find_k_num(nums1, nums2, int(all_len/2)+1)
        else:
            return (self.find_k_num(nums1, nums2, int(all_len/2)) + self.find_k_num(nums1, nums2, int(all_len/2)+1)) * 0.5

    def find_k_num(self, nums1, nums2 , k):
        lenA, lenB = len(nums1), len(nums2)
        
        if lenB > lenA:
            return self.find_k_num(nums2, nums1, k)
        
        if lenB == 0:
            return nums1[k - 1]
        
        if k == 1:
            return min(nums1[0],nums2[0])
          
        pb = min(lenB, int(k/2))
        pa = k - pb
        
        if nums1[pa - 1] > nums2[pb -1]:
            return self.find_k_num(nums1, nums2[pb:], k-pb)
        elif nums1[pa - 1] < nums2[pb -1]:
            return self.find_k_num(nums1[pa:], nums2, k-pa)
        else:
            return nums1[pa - 1]
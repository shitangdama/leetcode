import heapq

# Definition for singly-linked list.
# 将每个链表的表头元素取出来，建立一个小顶堆，因为k个链表中都排好序了，因此每次取堆顶的元素就是k个链表中的最小值，可以将其合并到合并链表中，再将这个元素的指针指向的下一个元素也加入到堆中，再调整堆，取出堆顶，合并链表。。。。以此类推，直到堆为空时，链表合并完毕。
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None
    
    def __repr__(self):
        if self:
            return "{} -> {}".format(self.val, repr(self.next))

class Solution:
    # @param a list of ListNode
    # @return a ListNode
    def mergeKLists(self, lists):
        dummy = ListNode(0)
        current = dummy
        
        heap = []
        for sorted_list in lists:
            if sorted_list:
                heapq.heappush(heap, (sorted_list.val, sorted_list))
                
        while heap:
            smallest = heapq.heappop(heap)[1]
            current.next = smallest
            current = current.next
            if smallest.next:
                heapq.heappush(heap, (smallest.next.val, smallest.next))
                
        return dummy.next

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @param head, a ListNode
    # @param x, an integer
    # @return a ListNode
    def partition(self, head, x):
        dump = ListNode(0)
        dump.next = head
        cur = dump
        while cur.next and cur.next.val < x:
            cur = cur.next
        par = cur
        rec = cur.next
        while cur.next:
            if cur.next.val < x:
                par.next = cur.next
                par = par.next
                cur.next = cur.next.next
                par.next = rec
            else:
                cur = cur.next
        return dump.next

# debug
s = Solution()

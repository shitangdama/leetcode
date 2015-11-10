# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @param {ListNode} head
    # @param {integer} val
    # @return {ListNode}
    def removeElements(self, head, val):
        dummy = ListNode(0)
        dummy.next = head
        cur = dummy
        while cur.next:
            if cur.next.val == val:
                cur.next = cur.next.next
            else:
                cur = cur.next
        return dummy.next
class Solution:
    # @param {ListNode} head
    # @param {integer} val
    # @return {ListNode}
    def removeElements(self, head, val):
        dummy = ListNode(float("-inf"))
        dummy.next = head
        prev, curr = dummy, dummy.next
        
        while curr:
            if curr.val == val:
                prev.next = curr.next
            else:
                prev = curr
            
            curr = curr.next
        
        return dummy.next

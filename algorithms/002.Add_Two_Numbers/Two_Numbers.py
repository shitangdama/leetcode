# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def addTwoNumbers(self, l1, l2):
        dummy = ListNode(0)
        current, carry = dummy, 0
        
        while l1 is not None or l2 is not None:
            val = carry
            if l1 is not None:
                val = val + l1.val
                l1 = l1.next
            if l2 is not None:
                val = val + l2.val
                l2 = l2.next
            
            carry, val = int(val/10), val%10
            current.next = ListNode(val)
            current = current.next
            
        if carry == 1:
            current.next = ListNode(1)
        return dummy.next

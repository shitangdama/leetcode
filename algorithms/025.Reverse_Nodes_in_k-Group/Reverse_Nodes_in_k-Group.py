<<<<<<< HEAD
# Time:  O(n)
# Space: O(1)

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None    
    
    def __repr__(self):
        if self:
            return "{} -> {}".format(self.val, repr(self.next))

class Solution:
    # @param head, a ListNode
    # @param k, an integer
    # @return a ListNode
    def reverseKGroup(self, head, k):
        dummy = ListNode(-1)
        dummy.next = head
        
        cur, cur_dummy = head, dummy
        length = 0
        
        while cur:
            next_cur = cur.next
            length = (length + 1) % k
            
            if length == 0:
                next_dummy = cur_dummy.next
                self.reverse(cur_dummy, cur.next)
                cur_dummy = next_dummy
                
            cur = next_cur
            
        return dummy.next
    
    def reverse(self, begin, end):
            first = begin.next
            cur = first.next
            
            while cur != end:
                first.next = cur.next
                cur.next = begin.next
                begin.next = cur
                cur = first.next

if __name__ == "__main__":
    head = ListNode(1)
    head.next = ListNode(2)
    head.next.next = ListNode(3)
    head.next.next.next = ListNode(4)
    head.next.next.next.next = ListNode(5)
    print Solution().reverseKGroup(head, 2)
=======
# Time:  O(n)
# Space: O(1)

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None    
    
    def __repr__(self):
        if self:
            return "{} -> {}".format(self.val, repr(self.next))

class Solution:
    # @param head, a ListNode
    # @param k, an integer
    # @return a ListNode
    def reverseKGroup(self, head, k):
        dummy = ListNode(-1)
        dummy.next = head
        
        cur, cur_dummy = head, dummy
        length = 0
        
        while cur:
            next_cur = cur.next
            length = (length + 1) % k
            
            if length == 0:
                next_dummy = cur_dummy.next
                self.reverse(cur_dummy, cur.next)
                cur_dummy = next_dummy
                
            cur = next_cur
            
        return dummy.next
    
    def reverse(self, begin, end):
            first = begin.next
            cur = first.next
            
            while cur != end:
                first.next = cur.next
                cur.next = begin.next
                begin.next = cur
                cur = first.next

if __name__ == "__main__":
    head = ListNode(1)
    head.next = ListNode(2)
    head.next.next = ListNode(3)
    head.next.next.next = ListNode(4)
    head.next.next.next.next = ListNode(5)
    print Solution().reverseKGroup(head, 2)
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74

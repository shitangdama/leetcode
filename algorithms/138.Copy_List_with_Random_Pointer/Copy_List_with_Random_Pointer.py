import collections
# Definition for singly-linked list with a random pointer.
class RandomListNode:
    def __init__(self, x):
        self.label = x
        self.next = None
        self.random = None

class Solution:
    # @param head, a RandomListNode
    # @return a RandomListNode
    def copyRandomList(self, head):
        d = collections.defaultdict(lambda: RandomListNode(0))
        if head is None:
            return None
        cur = head
        while cur:
            d[cur].label = cur.label
            d[cur].next = d[cur.label]
            d[cur].random = d[cur.random]
            cur = cur.next
        return d[head]

# Definition for singly-linked list with a random pointer.
class RandomListNode:
    def __init__(self, x):
        self.label = x
        self.next = None
        self.random = None

class Solution:
    # @param head, a RandomListNode
    # @return a RandomListNode
    def copyRandomList(self, head):
        # copy and combine copied list with original list
        current = head
        while current:
            copied = RandomListNode(current.label)
            copied.next = current.next
            current.next = copied
            current = copied.next
        
        # update random node in copied list
        current = head
        while current:
            if current.random:
                current.next.random = current.random.next
            current = current.next.next
        
        # split copied list from combined one
        dummy = RandomListNode(0)
        copied_current, current = dummy, head
        while current:
            copied_current.next = current.next
            current.next = current.next.next
            copied_current, current = copied_current.next, current.next
        return dummy.next

# Time:  O(n)
# Space: O(n)
class Solution2:
    # @param head, a RandomListNode
    # @return a RandomListNode
    def copyRandomList(self, head):
        dummy = RandomListNode(0)
        current, prev, copies = head, dummy, {}
        
        while current:
            copied = RandomListNode(current.label)
            copies[current] = copied
            prev.next = copied
            prev, current = prev.next, current.next
        
        current = head
        while current:
            if current.random:
                copies[current].random = copies[current.random]
            current = current.next
        
        return dummy.next


if __name__ == "__main__":
    head = RandomListNode(1)
    head.next = RandomListNode(2)
    head.random = head.next
    result = Solution().copyRandomList(head)
    print result.label
    print result.next.label
    print result.random.label

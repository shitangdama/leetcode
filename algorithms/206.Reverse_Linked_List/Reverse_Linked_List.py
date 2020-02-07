class Solution:
    def reverse(self, head):
        curt = None
        while head != None:
            temp = head.next
            head.next = curt
            curt = head
            head = temp
        return curt

public class Solution {
    private int getLength(ListNode head) {
        int length = 0;
        while (head != null) {
            length ++;
            head = head.next;
        }
        return length;
    }
    
    public ListNode rotateRight(ListNode head, int n) {
        if (head == null) {
            return null;
        }
        
        int length = getLength(head);
        n = n % length;
        
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        head = dummy;
        
        ListNode tail = dummy;
        for (int i = 0; i < n; i++) {
            head = head.next;
        }
        
        while (head.next != null) {
            tail = tail.next;
            head = head.next;
        }
        
        head.next = dummy.next;
        dummy.next = tail.next;
        tail.next = null;
        return dummy.next;
    }
}
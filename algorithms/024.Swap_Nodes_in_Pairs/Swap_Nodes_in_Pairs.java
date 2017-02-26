<<<<<<< HEAD
public class Solution {
    public ListNode swapPairs(ListNode head) {
        if(head == null || head.next == null) {
            return head;
        }
        ListNode point = new ListNode(0);
        point.next = head;
        head = point;
        while(point.next != null && point.next.next != null) {
            ListNode tmp = point.next.next.next;
            point.next.next.next = point.next;
            point.next = point.next.next;
            point.next.next.next = tmp;
            point = point.next.next;
        }
        return head.next;
    }
=======
public class Solution {
    public ListNode swapPairs(ListNode head) {
        if(head == null || head.next == null) {
            return head;
        }
        ListNode point = new ListNode(0);
        point.next = head;
        head = point;
        while(point.next != null && point.next.next != null) {
            ListNode tmp = point.next.next.next;
            point.next.next.next = point.next;
            point.next = point.next.next;
            point.next.next.next = tmp;
            point = point.next.next;
        }
        return head.next;
    }
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
}
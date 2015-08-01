/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int carry = 0;
        ListNode res = new ListNode(0);
        ListNode cur1 = l1, cur2 = l2, head = res;
        while (cur1 != null || cur2 != null) {
            if (cur1 != null) {
                carry += cur1.val;
                cur1 = cur1.next;
            }
            if (cur2 != null) {
                carry += cur2.val;
                cur2 = cur2.next;
            }
            head.next = new ListNode(carry % 10);
            head = head.next;
            carry /= 10;
        }
        if (carry == 1)
            head.next = new ListNode(1);
        return res.next;
    }
}
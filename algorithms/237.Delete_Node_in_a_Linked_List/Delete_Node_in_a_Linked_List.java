<<<<<<< HEAD
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public void deleteNode(ListNode node) {
    node.val = node.next.val;
    node.next = node.next.next;
}
}
=======
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public void deleteNode(ListNode node) {
    node.val = node.next.val;
    node.next = node.next.next;
}
}
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74

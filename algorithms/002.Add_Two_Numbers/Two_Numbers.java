/*
  Definition for singly-linked list.
  public class ListNode {
      int val;
      ListNode next;
      ListNode(int x) {
         val = x;
          next = null;
      }
  }
 */
public class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        return helper(l1, l2, 0);
    }

    private ListNode helper(ListNode l1, ListNode l2, int carry) {
        if (l1 == null && l2 == null) {
            if (carry == 0) {
                return null;
            } else {
                return new ListNode(1);
            }
        } else if (l1 == null) {
            return helper(new ListNode(0), l2, carry);
        } else if (l2 == null) {
            return helper(l1, new ListNode(0), carry);
        } else {
            // both l1 and l2 have value
            int sum = l1.val + l2.val + carry;
            int resultNumber = sum % 10;
            int newCarry = sum / 10;
            ListNode ans = new ListNode(resultNumber);
            ans.next = helper(l1.next, l2.next, newCarry);
            return ans;
        }
    }
}
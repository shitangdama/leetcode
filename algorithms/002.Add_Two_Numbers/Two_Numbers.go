package problem0002

// ListNode xx
type ListNode struct {
	Val  int
	Next *ListNode
}

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	dummy := &ListNode{}
	carry := 0
	current := dummy

	for l1 != nil || l2 != nil || carry > 0 {
		val := carry

		if l1 != nil {
			val = val + l1.Val
			l1 = l1.Next
		}

		if l2 != nil {
			val = val + l2.Val
			l2 = l2.Next
		}

		carry = val / 10

		current.Next = &ListNode{Val: val % 10}
		current = current.Next
	}

	return dummy.Next
}

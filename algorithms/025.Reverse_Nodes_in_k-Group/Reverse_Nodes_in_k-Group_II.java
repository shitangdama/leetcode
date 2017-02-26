<<<<<<< HEAD
// version 2
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // p1->p1next->...->p2->p2next
    //      |____________|
    //   reverse this part to:
    // p1->p2->.......->p1next->p2next;
    // return p1next;
    ListNode *reverse(ListNode *p1, ListNode *p2) {
        ListNode *p1next = p1->next;
        ListNode *p2next = p2->next;
        ListNode *prev = p2next;
        ListNode *p = p1next; 
        
        while (p != p2next) {
            ListNode *temp = p ->next;
            p->next = prev;
            prev = p;
            p = temp;
        }
        p1->next = p2;
        return p1next;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) {
            return head;
        }
        
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode *p1 = dummy, *p2 = dummy;
        
        for (int i = 0; i < k; i++) {
            if (p2 == NULL) {
                break;
            }
            p2 = p2->next;
        }
        if (p2 == NULL) {
            return head;
        }
        
        while (p2 != NULL) {
            p2 = reverse(p1, p2);
            for (int i = 0; i < k; i++) {
                if (p2 == NULL) {
                    break;
                }
                p1 = p1->next;
                p2 = p2->next;
            }
        }
        
        return dummy->next;
    }
=======
// version 2
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // p1->p1next->...->p2->p2next
    //      |____________|
    //   reverse this part to:
    // p1->p2->.......->p1next->p2next;
    // return p1next;
    ListNode *reverse(ListNode *p1, ListNode *p2) {
        ListNode *p1next = p1->next;
        ListNode *p2next = p2->next;
        ListNode *prev = p2next;
        ListNode *p = p1next; 
        
        while (p != p2next) {
            ListNode *temp = p ->next;
            p->next = prev;
            prev = p;
            p = temp;
        }
        p1->next = p2;
        return p1next;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) {
            return head;
        }
        
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode *p1 = dummy, *p2 = dummy;
        
        for (int i = 0; i < k; i++) {
            if (p2 == NULL) {
                break;
            }
            p2 = p2->next;
        }
        if (p2 == NULL) {
            return head;
        }
        
        while (p2 != NULL) {
            p2 = reverse(p1, p2);
            for (int i = 0; i < k; i++) {
                if (p2 == NULL) {
                    break;
                }
                p1 = p1->next;
                p2 = p2->next;
            }
        }
        
        return dummy->next;
    }
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
};
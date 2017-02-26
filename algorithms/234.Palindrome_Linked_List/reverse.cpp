#include <bits/stdc++.h>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        int sz = get_length(head);
        if (sz < 2)
            return true;

        // reverse half
        ListNode *new_head = reverseBetween(head, 1, sz / 2);

        ListNode *head1 = new_head, *head2;
        // now the head is point to (sz/2)th node
        if (sz % 2 == 1) {
            head2 = head->next->next;
        } else {
            head2 = head->next;
        }
        bool ok = true;
        for (int i = 0; i < sz / 2; ++i) {
            if (head1->val != head2->val) {
                ok = false;
                break;
            }
            head1 = head1->next;
            head2 = head2->next;
        }

        // reverse half again
        reverseBetween(new_head, 1, sz / 2);
        return ok;
    }

private:
    int get_length(ListNode* head) {
        int sz = 0;
        while (head) {
            ++sz;
            head = head->next;
        }
        return sz;
    }

    // these codes are the same as https://github.com/illuz/leetcode/blob/master/solutions/092.Reverse_Linked_List_II/AC_simulate_n.cpp
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *mhead = new ListNode(0), *prev, *cur;
        mhead->next = head;    // because m will be 0
        for (int i = 0; i < m - 1; i++) {
            mhead = mhead->next;
        }

        prev = mhead->next;
        cur = prev->next;
        for (int i = m; i < n; i++) {
            prev->next = cur->next;
            cur->next = mhead->next;
            mhead->next = cur;
            cur = prev->next;
        }
        return m == 1 ? mhead->next : head;
    }
};
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return true;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL&&fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next=reverseList(slow->next);
        slow=slow->next;
        while(slow!=NULL){
            if(head->val!=slow->val)
                return false;
            head=head->next;
            slow=slow->next;
        }
        return true;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* pre=NULL;
        ListNode* next=NULL;
        while(head!=NULL){
            next=head->next;
            head->next=pre;
            pre=head;
            head=next;
        }
        return pre;
    }
};

int main() {
    Solution s;
    ListNode l1(1);
    ListNode l2(2);
    ListNode l3(2);class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) return true;
        ListNode *slow(head), *fast(head);
        // find the middle element or end of first half segment
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        //move one step further
        slow = slow->next;
        //reverse second half segment
        ListNode *newhead = reverseList(slow);
        //compare second half with first half
        while (newhead) {
            if (newhead->val != head->val) return false;
            head = head->next;
            newhead = newhead->next;
        }
        return true;
    }
    ListNode* reverseList(ListNode *head) {
        ListNode *curr(head), *next(head->next), *nextnext(NULL);
        while (next) {
            nextnext = next->next;
            next->next = curr;
            curr = next;
            next = nextnext;
        }
        head->next = NULL; //need to seet tail as NULL!
        return curr;
    }
};
    ListNode l4(1);
    ListNode l5(2);
    ListNode l6(1);
    cout << s.isPalindrome(&l1) << endl;
    l1.next = &l2;
    cout << s.isPalindrome(&l1) << endl;
    l2.next = &l3;
    cout << s.isPalindrome(&l1) << endl;
    l3.next = &l4;
    cout << s.isPalindrome(&l1) << endl;
    l4.next = &l5;
    cout << s.isPalindrome(&l1) << endl;
    l5.next = &l6;
    cout << s.isPalindrome(&l1) << endl;
    return 0;
}


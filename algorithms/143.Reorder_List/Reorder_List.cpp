#include <bits/stdc++.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode *head) {
        if (!head || !head->next || !head->next->next)
            return;

        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // reserve
        ListNode *mhead = slow, *pre = mhead->next;
        if (pre) {
            ListNode *cur = pre->next;
            while (cur) {
                pre->next = cur->next;
                cur->next = mhead->next;
                mhead->next = cur;
                cur = pre->next;
            }
        }

        // merge
        mhead = slow->next;
        slow->next = NULL;
        while (head && mhead) {
            ListNode *tmp = head->next;
            head->next = mhead;
            mhead = mhead->next;
            head->next->next = tmp;
            head = tmp;
        }
    }
};// LeetCode, Reorder List
// 时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    void reorderList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return;

        ListNode *slow = head, *fast = head, *prev = nullptr;
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = nullptr; // cut at middle

        slow = reverse(slow);

        // merge two lists
        ListNode *curr = head;
        while (curr->next) {
            ListNode *tmp = curr->next;
            curr->next = slow;
            slow = slow->next;
            curr->next->next = tmp;
            curr = tmp;
        }
        curr->next = slow;
    }

    ListNode* reverse(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode *prev = head;
        for (ListNode *curr = head->next, *next = curr->next; curr;
            prev = curr, curr = next, next = next ? next->next : nullptr) {
                curr->next = prev;
        }
        head->next = nullptr;
        return prev;
    }
};


int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    Solution s;
    s.reorderList(head);
    return 0;
}


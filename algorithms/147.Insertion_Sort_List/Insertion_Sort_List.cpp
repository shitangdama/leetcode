#include <bits/stdc++.h>
/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: The head of linked list.
     */
    ListNode *insertionSortList(ListNode *head) {
        ListNode *dummy = new ListNode(0);
        
        while (head != NULL) {
            ListNode *temp = dummy;
            ListNode *next = head->next;
            while (temp->next != NULL && temp->next->val < head->val) {
                temp = temp->next;
            }
            head->next = temp->next;
            temp->next = head;
            head = next;
        }
        
        return dummy->next;
    }
};

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if (!head || !head->next)
            return head;
        ListNode *prev = head,
                 *cur = head->next,
                 *next = cur->next,
                 *tmp;
        while (cur) {
            if (cur->val <= head->val) {
                // insert to head
                if (prev == head) {
                    head->next = next;
                    cur->next = head;
                    head = cur;
                } else {
                    cur->next = head;
                    head = cur;
                    prev->next = next;
                }
            } else {
                // find and insert
                tmp = head;
                while (tmp->next->val < cur->val) {
                    tmp = tmp->next;
                }
                if (tmp->next != cur) {
                    cur->next = tmp->next;
                    tmp->next = cur;
                    prev->next = next;
                } else
                    prev = cur;
            }
            cur = next;
            if (next)
                next = next->next;
        }
        return head;
    }
};
// LeetCode, Insertion Sort List
// 时间复杂度O(n^2)，空间复杂度O(1)
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        ListNode dummy(INT_MIN);
        //dummy.next = head;

        for (ListNode *cur = head; cur != nullptr;) {
            auto pos = findInsertPos(&dummy, cur->val);
            ListNode *tmp = cur->next;
            cur->next = pos->next;
            pos->next = cur;
            cur = tmp;
        }
        return dummy.next;
    }

    ListNode* findInsertPos(ListNode *head, int x) {
        ListNode *pre = nullptr;
        for (ListNode *cur = head; cur != nullptr && cur->val <= x;
            pre = cur, cur = cur->next)
            ;
        return pre;
    }
};
int main() {
    ListNode *head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);
    Solution s;
    head = s.insertionSortList(head);
    return 0;
}


#include <bits/stdc++.h>


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
    int count_size(ListNode *node) {
        int sz = 0;
        while (node != NULL) {
            node = node->next;
            ++sz;
        }
        return sz;
    }

public:
    ListNode *sortList(ListNode *head) {
        // add dummy
        ListNode dummy(0);
        dummy.next = head;

        int sz = count_size(head);
        int block_size = 1;
        int last_index(0);
        int alen(0), blen(0);

        ListNode *prev(NULL), *cur(NULL);
        ListNode *A(NULL), *B(NULL);    // the compare groups iter
        ListNode *tmp(NULL);

        while (block_size < sz) {
            last_index = 0;     // the index of solved last
            prev = &dummy;
            cur = dummy.next;   // because the head will change

            // solve
            while (last_index < sz) {
                // get length of block A and B.
                alen = min(sz - last_index, block_size);
                blen = min(sz - last_index - alen, block_size);
                if (blen == 0)
                    break;

                // get the block A and B
                A = cur;

                for (int i = 0; i < alen - 1; ++i)
                    cur = cur->next;
                B = cur->next;
                cur->next = NULL;    // cut A-B
                cur = B;

                for (int i = 0; i < blen - 1; ++i)
                    cur = cur->next;
                tmp = cur->next;
                cur->next = NULL;    // cut B-[tmp]
                cur = tmp;

                // merge A and B
                while (A != NULL || B != NULL) {
                    if (B == NULL || (A != NULL && A->val <= B->val)) {
                        prev->next = A;
                        prev = prev->next;
                        A = A->next;
                    } else {
                        prev->next = B;
                        prev = prev->next;
                        B = B->next;
                    }
                }

                prev->next = cur;
                last_index += alen + blen;
            }
            block_size <<= 1;
        }
        return dummy.next;
    }
};
// LeetCode, Sort List
// 归并排序，时间复杂度O(nlogn)，空间复杂度O(1)
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if (head == NULL || head->next == NULL)return head;

        // 快慢指针找到中间节点
        ListNode *fast = head, *slow = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        // 断开
        fast = slow;
        slow = slow->next;
        fast->next = NULL;

        ListNode *l1 = sortList(head);  // 前半段排序
        ListNode *l2 = sortList(slow);  // 后半段排序
        return mergeTwoLists(l1, l2);
    }

    // Merge Two Sorted Lists
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode dummy(-1);
        for (ListNode* p = &dummy; l1 != nullptr || l2 != nullptr; p = p->next) {
            int val1 = l1 == nullptr ? INT_MAX : l1->val;
            int val2 = l2 == nullptr ? INT_MAX : l2->val;
            if (val1 <= val2) {
                p->next = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            }
        }
        return dummy.next;
    }
};

int main() {
    ListNode *head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(4);
    Solution s;
    head = s.sortList(head);
    cout << head->val;
    cout << head->next->val;
    cout << head->next->next->val;
    return 0;
}


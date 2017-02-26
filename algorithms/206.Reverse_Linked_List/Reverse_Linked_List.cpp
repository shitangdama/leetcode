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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode dummy(0);
        dummy.next = head;

        ListNode *prev = head, *cur = head->next;

        while (cur) {
            prev->next = cur->next;
            cur->next = dummy.next;
            dummy.next = cur;
            cur = prev->next;
        }
        return dummy.next;
    }
};
class Solution {
public:
ListNode* reverseList(ListNode* head) {
    if(!head) return head;

    ListNode* prev = NULL;
    ListNode* cur = head;
    ListNode* next = NULL;

    while(cur) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    return prev;
 }
};
int main() {

    return 0;
}


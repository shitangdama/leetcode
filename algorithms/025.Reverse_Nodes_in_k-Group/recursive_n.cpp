#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (!head || !(head->next) || k < 2)
            return head;

        // count k nodes
        ListNode *nextgp = head;
        for (int i = 0; i < k; i++)
            if (nextgp)
                nextgp = nextgp->next;
            else
                return head;

        // reverse
        ListNode *prev = NULL, *cur = head, *next = NULL;
        while (cur != nextgp) {
            next = cur->next;
            if (prev)
                cur->next = prev;
            else
                cur->next = reverseKGroup(nextgp, k);
            prev = cur;
            cur = next;
        }
        return prev;
    }
};

int main() {

    return 0;
}


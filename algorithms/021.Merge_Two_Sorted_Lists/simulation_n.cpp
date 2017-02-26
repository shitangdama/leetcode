#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;

        ListNode *start, *cur;

        if (l1->val < l2->val) {
            cur = start = l1;
            l1 = l1->next;
        } else {
            cur = start = l2;
            l2 = l2->next;
        }
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                cur->next = l1;
                cur = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                cur = l2;
                l2 = l2->next;
            }
        }
        if (l1 != NULL)
            cur->next = l1;
        else if (l1 != NULL)
            cur->next = l2;
        return start;
    }
};

ListNode *l1, *l2, *ll1, *ll2;
int main() {
    int n1, n2;
    Solution s;
    cin >> n1;
    ll1 = l1 = new ListNode(0);
    for (int i = 0; i < n1; i++) {
        l1->next = new ListNode(0);
        l1 = l1->next;
        scanf("%d", &(l1->val));
    }
    cin >> n2;
    ll2 = l2 = new ListNode(0);
    for (int i = 0; i < n2; i++) {
        l2->next = new ListNode(0);
        l2 = l2->next;
        scanf("%d", &(l2->val));
    }
    ListNode *res = s.mergeTwoLists(ll1->next, ll2->next);
    while (res != NULL) {
        cout << res->val << ' ';
        res = res->next;
    }

    return 0;
}


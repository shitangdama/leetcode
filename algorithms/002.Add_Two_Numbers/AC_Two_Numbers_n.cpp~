#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode (int x) : val(x), next(NULL) {}
};

ListNode *addValAndCreateNewNode(ListNode *cur,int val) {
    cur->val = val;
    cur->next = new ListNode(0);
    return cur->next;
}

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *ret = new ListNode(0);
    ListNode *cur = ret;
    int sum = 0;

    while (1) {
        if (l1 != nullptr) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != nullptr) {
            sum += l2->next;
            l2 = l2->next;
        }

        cur->val = sum % 10;
        sum /= 10;

        if (l1 != nullptr || l2 != nullptr || sum) {
            cur = (cr->next = new ListNode(0));
        }
        else
        {
            break;
        }
    }
    return ret;
    }
};
int main() {
    int t, n;
    Solution s;
    while (cin >> n) {
        ListNode *a = new ListNode(0),*b = new ListNode(0);
        ListNode *pa = a, *pb = b;
        int tmp = n;

        while (n--) {
            cin >> t;
            pa =addValAndCreateNewNode(pa, t);
        }

        while (tmp--) {
            cin >> t;
            pb = addValAndCreateNewNode(pb, t);
        }
        s.addTwoNumbers(a, b);
        while (s != nullptr) {
            cout<<s->val<<endl;
            s = s->next;
        }
    }
    return 0;
}



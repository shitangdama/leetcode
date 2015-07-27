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
    int tmp = 0;
    ListNode rs(0), *r = &rs, *p = l1, *q = l2;
    while (p != NULL || q != NULL || tmp)
      {
	tmp = tmp + (p == NULL ? 0 : p->val) + (q == NULL ? 0 : q->val);
	r->next = new ListNode(tmp % 10);
	r = r->next;
	p = (p == NULL ? p : p->next);
	q = (q == NULL ? q : q->next);
	tmp = tmp / 10;
      }
    return rs.next;
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

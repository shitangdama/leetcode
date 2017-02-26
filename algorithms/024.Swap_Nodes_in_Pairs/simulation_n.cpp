#include <bits/stdc++.h>

<<<<<<< HEAD
using namespace std;
=======
using namespace std;
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        ListNode *newHead = new ListNode(0);
        newHead->next = head;
        ListNode *preNode = newHead, *curNode = head;
        int cnt = 1;
        while (curNode != NULL && curNode->next != NULL) {
            // swap curNode and curNode->next
            preNode->next = curNode->next;
            curNode->next = preNode->next->next;
            preNode->next->next = curNode;

            // go over two nodes
            preNode = curNode;
            curNode = curNode->next;
        }
        head = newHead->next;
        delete newHead;
        return head;
    }
};

int main() {
    ListNode *h = new ListNode(1);
    h->next = new ListNode(2);
    Solution s;
    cout << s.swapPairs(h) << endl;
    return 0;
}


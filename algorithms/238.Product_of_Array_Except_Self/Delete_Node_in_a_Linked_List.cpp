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
    void deleteNode(ListNode* node) {
        ListNode *next = node->next;
        *node = *next;
        // this statement is equivalent to
        // node->val = next->val;
        // node->next = next->next;
        delete next;
    }
};
class Solution {
public:
   void deleteNode(ListNode* node) {
    auto next = node->next;
    *node = *next;
    delete next;
}
};

int main() {

    return 0;
}


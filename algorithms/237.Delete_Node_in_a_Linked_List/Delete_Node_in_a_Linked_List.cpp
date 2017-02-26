<<<<<<< HEAD
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

=======
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

>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74

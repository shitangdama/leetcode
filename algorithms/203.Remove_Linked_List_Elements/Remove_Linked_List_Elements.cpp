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
  ListNode* removeElements(ListNode* head, int val) {
    ListNode *it = head, *prev = NULL;
    while(it) {
      if(it->val == val) {
        if(prev) {
          prev->next = it->next;
        } else {
          head = it->next;
        }
        ListNode *tmp = it;
        it = it->next;
        delete tmp;
      } else {
        prev = it;
        it = it->next;
      }
    }
    return head;
  }
};
class Solution {
public:
ListNode* removeElements(ListNode* head, int val) {
    if(!head) return NULL;

    ListNode* newHead = new ListNode(INT_MIN);
    newHead->next = head;

    ListNode* cur = head;
    ListNode* prev = newHead;
    while(cur)
    {
        if(cur->val == val)
        {
            ListNode* t = cur;
            prev->next = cur->next;
            cur = cur->next;
            delete t;
            continue;
        }

        prev = cur;
        cur = cur->next;
    }

    ListNode* t = newHead->next;
    delete newHead;
    return t;
  }
};
int main() {

    return 0;
}


#include <bits/stdc++.h>

using namespace std;

//1. 直接模拟，先算出节点数，再找到节点删除  
//2. 用两个指针，一个先走 N 步，然后再一起走。  
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (n == 0)
            return head;
        // count the node number
        int num = 0;
        ListNode *cur = head;
        while (cur != NULL) {
            cur = cur->next;
            num++;
        }
        if (num == n) {
            // remove first node
            ListNode *ret = head->next;
            delete head;
            return ret;
        } else {
            // remove (cnt-n)th node
            int m = num - n - 1;
            cur = head;
            while (m--)
                cur = cur->next;
            ListNode *rem = cur->next;
            cur->next = cur->next->next;
            delete rem;
            return head;
        }
    }
};

int main() {

    return 0;
}


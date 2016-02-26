#include <bits/stdc++.h>

using namespace std;

// Definition for singly-linked list with a random pointer.
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
private:
    RandomListNode *dfscopy(RandomListNode *head,
            unordered_map<int, RandomListNode*> &nodeTable) {
        if (!head)
            return head;
        if (nodeTable.count(head->label))
            return nodeTable[head->label];
        RandomListNode *dup = new RandomListNode(head->label);
        nodeTable[head->label] = dup;
        dup->next = dfscopy(head->next, nodeTable);
        dup->random = dfscopy(head->random, nodeTable);
        return dup;
    }

public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_map<int, RandomListNode*> nodeTable;
        return dfscopy(head, nodeTable);
    }
};// LeetCode, Copy List with Random Pointer
// 两遍扫描，时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        for (RandomListNode* cur = head; cur != nullptr; ) {
            RandomListNode* node = new RandomListNode(cur->label);
            node->next = cur->next;
            cur->next = node;
            cur = node->next;
        }

        for (RandomListNode* cur = head; cur != nullptr; ) {
            if (cur->random != NULL)
                cur->next->random = cur->random->next;
            cur = cur->next->next;
        }

        // 分拆两个单链表
        RandomListNode dummy(-1);
        for (RandomListNode* cur = head, *new_cur = &dummy;
                cur != nullptr; ) {
            new_cur->next = cur->next;
            new_cur = new_cur->next;
            cur->next = cur->next->next;
            cur = cur->next;
        }
        return dummy.next;
    }
};


int main() {

    return 0;
}


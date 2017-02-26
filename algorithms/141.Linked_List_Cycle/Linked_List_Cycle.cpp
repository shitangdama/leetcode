<<<<<<< HEAD
#include <bits/stdc++.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *p1 = head, *p2 = head;
        while (1) {
            if (p1) p1 = p1->next;
            else return false;
            if (p2) p2 = p2->next;
            else return false;
            if (p2) p2 = p2->next;
            else return false;

            if (p1 == p2)
                return true;
        }
    }
};
//LeetCode, Linked List Cycle
// ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(1)
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // ��������ָ�룬һ����һ����
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }
};

int main() {

    return 0;
}

=======
#include <bits/stdc++.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *p1 = head, *p2 = head;
        while (1) {
            if (p1) p1 = p1->next;
            else return false;
            if (p2) p2 = p2->next;
            else return false;
            if (p2) p2 = p2->next;
            else return false;

            if (p1 == p2)
                return true;
        }
    }
};
//LeetCode, Linked List Cycle
// ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(1)
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // ��������ָ�룬һ����һ����
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }
};

int main() {

    return 0;
}

>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74

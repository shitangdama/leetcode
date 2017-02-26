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
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *ret = new ListNode(head->val - 1);
        ListNode *cur = ret, *tmp;
        bool ifDel = false;    // if the cur->next should be deleted

        // add addition to the link
        ret->next = head;

        while (cur->next != NULL && cur->next->next != NULL) {
            if (cur->next->val == cur->next->next->val) {
                tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
                ifDel = true;
            } else if (ifDel) {
                tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
                ifDel = false;
            } else {
                cur = cur->next;
            }
        }

        if (ifDel) {
            tmp = cur->next;
            cur->next = cur->next->next;
            delete tmp;
        }

        // delete the addition head
        tmp = ret;
        ret = ret->next;
        delete tmp;

        return ret;
    }
};

class Solution2{
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* Mid = head, *Pre = new ListNode(0), *Newhead = Pre;
        int Number;

        Pre->next = head;
        while (Mid && Mid->next) {
            if (Mid->val == Mid->next->val) {
                Number = Mid->val;
                Mid = Mid->next->next; // this line saves 13 ms lol~!
                while (Mid && Mid->val == Number) Mid = Mid->next;
                Pre->next = Mid;
            }
            else {
                Pre = Mid;
                Mid = Mid->next;
            }
        }
        return Newhead->next;
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
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *ret = new ListNode(head->val - 1);
        ListNode *cur = ret, *tmp;
        bool ifDel = false;    // if the cur->next should be deleted

        // add addition to the link
        ret->next = head;

        while (cur->next != NULL && cur->next->next != NULL) {
            if (cur->next->val == cur->next->next->val) {
                tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
                ifDel = true;
            } else if (ifDel) {
                tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
                ifDel = false;
            } else {
                cur = cur->next;
            }
        }

        if (ifDel) {
            tmp = cur->next;
            cur->next = cur->next->next;
            delete tmp;
        }

        // delete the addition head
        tmp = ret;
        ret = ret->next;
        delete tmp;

        return ret;
    }
};

class Solution2{
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* Mid = head, *Pre = new ListNode(0), *Newhead = Pre;
        int Number;

        Pre->next = head;
        while (Mid && Mid->next) {
            if (Mid->val == Mid->next->val) {
                Number = Mid->val;
                Mid = Mid->next->next; // this line saves 13 ms lol~!
                while (Mid && Mid->val == Number) Mid = Mid->next;
                Pre->next = Mid;
            }
            else {
                Pre = Mid;
                Mid = Mid->next;
            }
        }
        return Newhead->next;
    }
};
int main() {

    return 0;
}

>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74

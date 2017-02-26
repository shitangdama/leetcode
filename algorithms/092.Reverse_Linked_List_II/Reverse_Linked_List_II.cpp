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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *mhead = new ListNode(0), *prev, *cur;
        mhead->next = head;    // because m will be 0
        for (int i = 0; i < m - 1; i++) {
            mhead = mhead->next;
        }

        prev = mhead->next;
        cur = prev->next;
        for (int i = m; i < n; i++) {
            prev->next = cur->next;
            cur->next = mhead->next;
            mhead->next = cur;
            cur = prev->next;
        }
        return m == 1 ? mhead->next : head;
    }
};
class Solution2 {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode **p=&head;
        for(int i=1;i<m;i++)
            p=&(*p)->next;
        ListNode **pos=&(*p);
        for(int i=m;i<n;i++){
            ListNode *t=(*p)->next;
            (*p)->next=t->next;
            t->next=*pos;
            *pos=t;
            if(i==m)
                p=&(*p)->next;
        }
        return head;
    }
};
class Solution3 {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        //make a head by myself
        ListNode *newHead=new ListNode(0);
        newHead->next=head;
        ListNode *p0=newHead;
        ListNode *p1=nullptr,*p2=nullptr;
        int i;
        //find position of p0
        for(i=1;i<m;i++)
            p0=p0->next;
        p1=p0->next;
        //reverse one by one
        while(i<n)
        {
            p2=p1->next;
            p1->next=p2->next;
            p2->next=p0->next;
            p0->next=p2;
            i++;
        }

        // p is the true head

        ListNode *p=newHead->next;
        delete newHead;
        return p;
    }
};

int main() {

    return 0;
}


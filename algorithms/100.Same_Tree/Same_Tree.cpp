#include <bits/stdc++.h>

using namespace std;

// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (p == NULL)
            return q == NULL;
        if (q == NULL)
            return p == NULL;
        if (p->val != q->val)
            return false;
        return isSameTree(p->left, q->left) &&
            isSameTree(p->right, q->right);
    }
};
// LeetCode, Same Tree
// �����棬ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(logn)
class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        stack<TreeNode*> s;
        s.push(p);
        s.push(q);

        while(!s.empty()) {
            p = s.top(); s.pop();
            q = s.top(); s.pop();

            if (!p && !q) continue;
            if (!p || !q) return false;
            if (p->val != q->val) return false;

            s.push(p->left);
            s.push(q->left);

            s.push(p->right);
            s.push(q->right);
        }
        return true;
    }
};

// LeetCode, Same Tree
// �ݹ�棬ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(logn)
class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (!p && !q) return true;   // ��ֹ����
        if (!p || !q) return false;  // ��֦
        return p->val == q->val      // �����ϲ�
                && isSameTree(p->left, q->left)
                && isSameTree(p->right, q->right);
    }
};

int main() {

    return 0;
}


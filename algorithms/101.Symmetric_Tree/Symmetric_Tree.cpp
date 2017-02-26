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
private:
    bool isSymmetric(TreeNode *p, TreeNode *q) {
        if (p == NULL)
            return q == NULL;
        if (q == NULL)
            return p == NULL;
        if (p->val != q->val)
            return false;
        return isSymmetric(p->left, q->right) &&
            isSymmetric(p->right, q->left);
    }
public:
    bool isSymmetric(TreeNode *root) {
        if (root == NULL)
            return true;
        return isSymmetric(root->left, root->right);
    }
};
// LeetCode, Symmetric Tree
// �����棬ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(logn)
class Solution2 {
public:
    bool isSymmetric (TreeNode* root) {
        if (!root) return true;

        stack<TreeNode*> s;
        s.push(root->left);
        s.push(root->right);

        while (!s.empty ()) {
            auto p = s.top (); s.pop();
            auto q = s.top (); s.pop();

            if (!p && !q) continue;
            if (!p || !q) return false;
            if (p->val != q->val) return false;

            s.push(p->left);
            s.push(q->right);

            s.push(p->right);
            s.push(q->left);
        }

        return true;
    }
};
// LeetCode, Symmetric Tree
// �ݹ�棬ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(logn)
class Solution3 {
public:
    bool isSymmetric(TreeNode *root) {
        return root ? isSymmetric(root->left, root->right) : true;
    }
    bool isSymmetric(TreeNode *left, TreeNode *right) {
        if (!left && !right) return true;   // ��ֹ����
        if (!left || !right) return false;  // ��ֹ����
        return left->val == right->val      // �����ϲ�
                && isSymmetric(left->left, right->right)
                && isSymmetric(left->right, right->left);
    }
};
int main() {

    return 0;
}


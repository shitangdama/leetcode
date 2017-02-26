#include <bits/stdc++.h>

// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    void orderHelper(vector<int> &res, TreeNode *cur) {
        if (!cur)
            return;
        res.push_back(cur->val);
        if (cur->left)
            orderHelper(res, cur->left);
        if (cur->right)
            orderHelper(res, cur->right);
    }
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        orderHelper(res, root);
        return res;
    }
};
// LeetCode, Binary Tree Preorder Traversal
// ʹ��ջ��ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(n)
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        const TreeNode *p;
        stack<const TreeNode *> s;

        p = root;
        if (p != nullptr) s.push(p);

        while (!s.empty()) {
            p = s.top();
            s.pop();
            result.push_back(p->val);

            if (p->right != nullptr) s.push(p->right);
            if (p->left != nullptr) s.push(p->left);
        }
        return result;
    }
};
// LeetCode, Binary Tree Preorder Traversal
// Morris���������ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(1)
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        TreeNode *cur, *prev;

        cur = root;
        while (cur != nullptr) {
            if (cur->left == nullptr) {
                result.push_back(cur->val);
                prev = cur; /* cur�ոձ����ʹ� */
                cur = cur->right;
            } else {
                /* ����ǰ�� */
                TreeNode *node = cur->left;
                while (node->right != nullptr && node->right != cur)
                    node = node->right;

                if (node->right == nullptr) { /* ��û���������������� */
                    result.push_back(cur->val); /* ����һ�е�λ��������ͬ */
                    node->right = cur;
                    prev = cur; /* cur�ոձ����ʹ� */
                    cur = cur->left;
                } else {    /* �Ѿ�����������ɾ������  */
                    node->right = nullptr;
                    /* prev = cur; ��������䣬cur�Ѿ������� */
                    cur = cur->right;
                }
            }
        }
        return result;
    }
};
int main() {

    return 0;
}


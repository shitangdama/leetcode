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
        if (cur->left)
            orderHelper(res, cur->left);
        if (cur->right)
            orderHelper(res, cur->right);
        res.push_back(cur->val);
    }
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        orderHelper(res, root);
        return res;
    }
};
// LeetCode, Binary Tree Postorder Traversal
// Morris���������ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(1)
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        TreeNode dummy(-1);
        TreeNode *cur, *prev = nullptr;
        std::function < void(const TreeNode*)> visit = 
            [&result](const TreeNode *node){
            result.push_back(node->val); 
        };

        dummy.left = root;
        cur = &dummy;
        while (cur != nullptr) {
            if (cur->left == nullptr) {
                prev = cur; /* ����Ҫ�� */
                cur = cur->right;
            } else {
                TreeNode *node = cur->left;
                while (node->right != nullptr && node->right != cur)
                    node = node->right;

                if (node->right == nullptr) { /* ��û���������������� */
                    node->right = cur;
                    prev = cur; /* ����Ҫ�� */
                    cur = cur->left;
                } else { /* �Ѿ�������������ʽڵ㣬��ɾ������  */
                    visit_reverse(cur->left, prev, visit);
                    prev->right = nullptr;
                    prev = cur; /* ����Ҫ�� */
                    cur = cur->right;
                }
            }
        }
        return result;
    }
private:
    // ��ת·��
    static void reverse(TreeNode *from, TreeNode *to) {
        TreeNode *x = from, *y = from->right, *z;
        if (from == to) return;

        while (x != to) {
            z = y->right;
            y->right = x;
            x = y;
            y = z;
        }
    }

    // ������ת���·���ϵ����н��
    static void visit_reverse(TreeNode* from, TreeNode *to, 
                     std::function< void(const TreeNode*) >& visit) {
        TreeNode *p = to;
        reverse(from, to);

        while (true) {
            visit(p);
            if (p == from)
                break;
            p = p->right;
        }

        reverse(to, from);
    }
};
// LeetCode, Binary Tree Postorder Traversal
// ʹ��ջ��ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(n)
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        /* p�����ڷ��ʵĽ�㣬q���ոշ��ʹ��Ľ��*/
        const TreeNode *p, *q;
        stack<const TreeNode *> s;

        p = root;

        do {
            while (p != nullptr) { /* ��������*/
                s.push(p);
                p = p->left;
            }
            q = nullptr;
            while (!s.empty()) {
                p = s.top();
                s.pop();
                /* �Һ��Ӳ����ڻ��ѱ����ʣ�����֮*/
                if (p->right == q) {
                    result.push_back(p->val);
                    q = p; /* ����շ��ʹ��Ľ��*/
                } else {
                    /* ��ǰ��㲻�ܷ��ʣ���ڶ��ν�ջ*/
                    s.push(p);
                    /* �ȴ���������*/
                    p = p->right;
                    break;
                }
            }
        } while (!s.empty());

        return result;
    }
};
int main() {

    return 0;
}


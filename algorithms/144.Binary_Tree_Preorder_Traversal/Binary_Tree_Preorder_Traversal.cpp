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
// 使用栈，时间复杂度O(n)，空间复杂度O(n)
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
// Morris先序遍历，时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        TreeNode *cur, *prev;

        cur = root;
        while (cur != nullptr) {
            if (cur->left == nullptr) {
                result.push_back(cur->val);
                prev = cur; /* cur刚刚被访问过 */
                cur = cur->right;
            } else {
                /* 查找前驱 */
                TreeNode *node = cur->left;
                while (node->right != nullptr && node->right != cur)
                    node = node->right;

                if (node->right == nullptr) { /* 还没线索化，则建立线索 */
                    result.push_back(cur->val); /* 仅这一行的位置与中序不同 */
                    node->right = cur;
                    prev = cur; /* cur刚刚被访问过 */
                    cur = cur->left;
                } else {    /* 已经线索化，则删除线索  */
                    node->right = nullptr;
                    /* prev = cur; 不能有这句，cur已经被访问 */
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


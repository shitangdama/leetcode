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
// Morris后序遍历，时间复杂度O(n)，空间复杂度O(1)
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
                prev = cur; /* 必须要有 */
                cur = cur->right;
            } else {
                TreeNode *node = cur->left;
                while (node->right != nullptr && node->right != cur)
                    node = node->right;

                if (node->right == nullptr) { /* 还没线索化，则建立线索 */
                    node->right = cur;
                    prev = cur; /* 必须要有 */
                    cur = cur->left;
                } else { /* 已经线索化，则访问节点，并删除线索  */
                    visit_reverse(cur->left, prev, visit);
                    prev->right = nullptr;
                    prev = cur; /* 必须要有 */
                    cur = cur->right;
                }
            }
        }
        return result;
    }
private:
    // 逆转路径
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

    // 访问逆转后的路径上的所有结点
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
// 使用栈，时间复杂度O(n)，空间复杂度O(n)
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        /* p，正在访问的结点，q，刚刚访问过的结点*/
        const TreeNode *p, *q;
        stack<const TreeNode *> s;

        p = root;

        do {
            while (p != nullptr) { /* 往左下走*/
                s.push(p);
                p = p->left;
            }
            q = nullptr;
            while (!s.empty()) {
                p = s.top();
                s.pop();
                /* 右孩子不存在或已被访问，访问之*/
                if (p->right == q) {
                    result.push_back(p->val);
                    q = p; /* 保存刚访问过的结点*/
                } else {
                    /* 当前结点不能访问，需第二次进栈*/
                    s.push(p);
                    /* 先处理右子树*/
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


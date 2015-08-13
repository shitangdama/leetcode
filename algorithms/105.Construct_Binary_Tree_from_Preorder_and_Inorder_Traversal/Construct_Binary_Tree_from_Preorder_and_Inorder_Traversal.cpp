#include <bits/stdc++.h>

using namespace std;
const int N = 0;

// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    TreeNode *dfs(vector<int> &preorder, vector<int> &inorder, int ps, int is, int len) {
        if (len <= 0)
            return NULL;
        TreeNode *root = new TreeNode(preorder[ps]);
        for (int i = 0; i < len; ++i) {
            if (inorder[is + i] == root->val) {
                root->left = dfs(preorder, inorder, ps + 1, is, i);
                root->right = dfs(preorder, inorder, ps + i + 1, is + i + 1, len - i - 1);
                break;
            }
        }
        return root;
    }
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return dfs(preorder, inorder, 0, 0, preorder.size());
    }
};

// LeetCode, Construct Binary Tree from Preorder and Inorder Traversal
// 递归，时间复杂度O(n)，空间复杂度O(\logn)
class Solution2 {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(begin(preorder), end(preorder),
                begin(inorder), end(inorder));
    }

    template<typename InputIterator>
    TreeNode* buildTree(InputIterator pre_first, InputIterator pre_last,
            InputIterator in_first, InputIterator in_last) {
        if (pre_first == pre_last) return nullptr;
        if (in_first == in_last) return nullptr;

        auto root = new TreeNode(*pre_first);

        auto inRootPos = find(in_first, in_last, *pre_first);
        auto leftSize = distance(in_first, inRootPos);

        root->left = buildTree(next(pre_first), next(pre_first,
                leftSize + 1), in_first, next(in_first, leftSize));
        root->right = buildTree(next(pre_first, leftSize + 1), pre_last,
                next(inRootPos), in_last);

        return root;
    }
};

int main() {
    vector<int> p = {1, 2, 3};
    vector<int> i = {1, 2, 3};
    Solution s;
    s.buildTree(p, i);
    return 0;
}


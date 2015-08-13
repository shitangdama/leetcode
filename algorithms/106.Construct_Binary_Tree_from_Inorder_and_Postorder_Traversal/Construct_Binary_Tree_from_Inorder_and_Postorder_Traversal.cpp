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
    TreeNode *dfs(vector<int> &inorder, vector<int> &postorder, int is, int ps, int len) {
        if (len <= 0)
            return 0;
        TreeNode *root = new TreeNode(postorder[ps]);
        for (int i = 0; i < len; ++i) {
            if (inorder[is - i] == root->val) {
                root->right = dfs(inorder, postorder, is, ps - 1, i);
                root->left = dfs(inorder, postorder, is - i - 1, ps - i - 1, len - i - 1);
                break;
            }
        }
        return root;
    }
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return dfs(inorder, postorder, inorder.size() - 1, postorder.size() - 1, inorder.size());
    }
};
// LeetCode, Construct Binary Tree from Inorder and Postorder Traversal
// 递归，时间复杂度O(n)，空间复杂度O(\logn)
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(begin(inorder), end(inorder),
                begin(postorder), end(postorder));
    }

    template<typename BidiIt>
    TreeNode* buildTree(BidiIt in_first, BidiIt in_last,
            BidiIt post_first, BidiIt post_last) {
        if (in_first ==in_last) return nullptr;
        if (post_first == post_last) return nullptr;

        const auto val = *prev(post_last);
        TreeNode* root = new TreeNode(val);

        auto in_root_pos = find(in_first, in_last, val);
        auto left_size = distance(in_first, in_root_pos);
        auto post_left_last = next(post_first, left_size);

        root->left = buildTree(in_first, in_root_pos, post_first, post_left_last);
        root->right = buildTree(next(in_root_pos), in_last, post_left_last,
                prev(post_last));

        return root;
    }
};

int main() {

    return 0;
}


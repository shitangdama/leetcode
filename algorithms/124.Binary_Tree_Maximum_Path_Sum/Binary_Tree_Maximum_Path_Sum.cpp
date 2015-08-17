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
    int ret;
    int dfs(TreeNode *root) {
        if (root == NULL)
            return 0;
        int left_sum = max(0, dfs(root->left));
        int right_sum = max(0, dfs(root->right));
        ret = max(ret, left_sum + right_sum + root->val);
        return max(left_sum, right_sum) + root->val;
    }

public:
    int maxPathSum(TreeNode *root) {
        ret = INT_MIN;
        dfs(root);
        return ret;
    }
};
// LeetCode, Binary Tree Maximum Path Sum
// 时间复杂度O(n)，空间复杂度O(logn)
class Solution {
public:
    int maxPathSum(TreeNode *root) {
        max_sum = INT_MIN;
        dfs(root);
        return max_sum;
    }
private:
    int max_sum;
    int dfs(const TreeNode *root) {
        if (root == nullptr) return 0;
        int l = dfs(root->left);
        int r = dfs(root->right);
        int sum = root->val;
        if (l > 0) sum += l;
        if (r > 0) sum += r;
        max_sum = max(max_sum, sum);
        return max(r, l) > 0 ? max(r, l) + root->val : root->val;
    }
};

int main() {

    return 0;
}


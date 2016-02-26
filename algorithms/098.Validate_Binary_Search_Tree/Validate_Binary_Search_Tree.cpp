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
    bool dfs(TreeNode *root, long long minval, long long maxval) {
        if (root == NULL)
            return true;
        return root->val > minval &&
            root->val < maxval &&
            dfs(root->left, minval, root->val) &&
            dfs(root->right, root->val, maxval);
    }

public:
    bool isValidBST(TreeNode *root) {
        return dfs(root, (long long)INT_MIN - 1, (long long)INT_MAX + 1);
    }
};

int main() {

    return 0;
}


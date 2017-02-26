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
    int sum;
    void dfs(TreeNode *cur, int num) {
        num = num * 10 + cur->val;
        if (!cur->left && !cur->right) {
            sum += num;
            return;
        }
        if (cur->left)
            dfs(cur->left, num);
        if (cur->right)
            dfs(cur->right, num);
    }
public:
    int sumNumbers(TreeNode *root) {
        if (!root)
            return 0;
        sum = 0;
        dfs(root, 0);
        return sum;
    }
};

// LeetCode, Decode Ways
// 时间复杂度O(n)，空间复杂度O(logn)
class Solution {
public:
    int sumNumbers(TreeNode *root) {
        return dfs(root, 0);
    }
private:
    int dfs(TreeNode *root, int sum) {
        if (root == nullptr) return 0;
        if (root->left == nullptr && root->right == nullptr)
            return sum * 10 + root->val;

        return dfs(root->left, sum * 10 + root->val) +
                dfs(root->right, sum * 10 + root->val);
    }
};

int main() {

    return 0;
}


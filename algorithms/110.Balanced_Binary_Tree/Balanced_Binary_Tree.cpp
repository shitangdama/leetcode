<<<<<<< HEAD
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
    bool balanceFlag;
    int getTreeDepth(TreeNode *root) {
        if (!root || !balanceFlag)
            return 0;
        int sz1 = getTreeDepth(root->left);
        int sz2 = getTreeDepth(root->right);
        if (abs(sz1 - sz2) > 1)
            balanceFlag = false;
        return max(sz1, sz2) + 1;
    }
public:
    bool isBalanced(TreeNode *root) {
        balanceFlag = true;
        getTreeDepth(root);
        return balanceFlag;
    }
};
// LeetCode, Balanced Binary Tree
// 时间复杂度O(n)，空间复杂度O(logn)
class Solution {
public:
    bool isBalanced (TreeNode* root) {
        return balancedHeight (root) >= 0;
    }

    /**
     * Returns the height of `root` if `root` is a balanced tree,
     * otherwise, returns `-1`.
     */
    int balancedHeight (TreeNode* root) {
        if (root == nullptr) return 0;  // 终止条件

        int left = balancedHeight (root->left);
        int right = balancedHeight (root->right);

        if (left < 0 || right < 0 || abs(left - right) > 1) return -1;  // 剪枝

        return max(left, right) + 1; // 三方合并
    }
};

int main() {

    return 0;
}

=======
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
    bool balanceFlag;
    int getTreeDepth(TreeNode *root) {
        if (!root || !balanceFlag)
            return 0;
        int sz1 = getTreeDepth(root->left);
        int sz2 = getTreeDepth(root->right);
        if (abs(sz1 - sz2) > 1)
            balanceFlag = false;
        return max(sz1, sz2) + 1;
    }
public:
    bool isBalanced(TreeNode *root) {
        balanceFlag = true;
        getTreeDepth(root);
        return balanceFlag;
    }
};
// LeetCode, Balanced Binary Tree
// 时间复杂度O(n)，空间复杂度O(logn)
class Solution {
public:
    bool isBalanced (TreeNode* root) {
        return balancedHeight (root) >= 0;
    }

    /**
     * Returns the height of `root` if `root` is a balanced tree,
     * otherwise, returns `-1`.
     */
    int balancedHeight (TreeNode* root) {
        if (root == nullptr) return 0;  // 终止条件

        int left = balancedHeight (root->left);
        int right = balancedHeight (root->right);

        if (left < 0 || right < 0 || abs(left - right) > 1) return -1;  // 剪枝

        return max(left, right) + 1; // 三方合并
    }
};

int main() {

    return 0;
}

>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74

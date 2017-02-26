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
    TreeNode *dfs(vector<int> &num, int left, int right) {
        if (left > right)
            return NULL;

        int mid = (left + right) / 2;
        TreeNode *root = new TreeNode(num[mid]);
        root->left = dfs(num, left, mid - 1);
        root->right = dfs(num, mid + 1, right);
    }
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return dfs(num, 0, num.size() - 1);
    }
};
// LeetCode, Convert Sorted Array to Binary Search Tree
// 分治法，时间复杂度O(n)，空间复杂度O(logn)
class Solution2 {
public:
    TreeNode* sortedArrayToBST (vector<int>& num) {
        return sortedArrayToBST(num.begin(), num.end());
    }

    template<typename RandomAccessIterator>
    TreeNode* sortedArrayToBST (RandomAccessIterator first,
            RandomAccessIterator last) {
        const auto length = distance(first, last);

        if (length <= 0) return nullptr;  // 终止条件

        // 三方合并
        auto mid = first + length / 2;
        TreeNode* root = new TreeNode (*mid);
        root->left = sortedArrayToBST(first, mid);
        root->right = sortedArrayToBST(mid + 1, last);

        return root;
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
    TreeNode *dfs(vector<int> &num, int left, int right) {
        if (left > right)
            return NULL;

        int mid = (left + right) / 2;
        TreeNode *root = new TreeNode(num[mid]);
        root->left = dfs(num, left, mid - 1);
        root->right = dfs(num, mid + 1, right);
    }
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return dfs(num, 0, num.size() - 1);
    }
};
// LeetCode, Convert Sorted Array to Binary Search Tree
// 分治法，时间复杂度O(n)，空间复杂度O(logn)
class Solution2 {
public:
    TreeNode* sortedArrayToBST (vector<int>& num) {
        return sortedArrayToBST(num.begin(), num.end());
    }

    template<typename RandomAccessIterator>
    TreeNode* sortedArrayToBST (RandomAccessIterator first,
            RandomAccessIterator last) {
        const auto length = distance(first, last);

        if (length <= 0) return nullptr;  // 终止条件

        // 三方合并
        auto mid = first + length / 2;
        TreeNode* root = new TreeNode (*mid);
        root->left = sortedArrayToBST(first, mid);
        root->right = sortedArrayToBST(mid + 1, last);

        return root;
    }
};

int main() {

    return 0;
}

>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74

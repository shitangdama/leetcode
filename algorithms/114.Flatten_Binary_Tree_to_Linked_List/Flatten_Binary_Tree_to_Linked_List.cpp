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
public:
    void flatten(TreeNode *root) {
        if (!root)
            return;

        TreeNode *left = root->left, *right = root->right;

        // recursive
        flatten(left);
        flatten(right);
        
        // combind
        root->left = NULL;
        root->right = left;
        while (root->right)
            root = root->right;
        root->right = right;
    }
};
class Solution {
public:
    void flatten(TreeNode *root) {
        if (!root)
            return;

        TreeNode *left = root->left, *right = root->right;

        // recursive
        flatten(left);
        flatten(right);
        
        // combind
        root->left = NULL;
        root->right = left;
        while (root->right)
            root = root->right;
        root->right = right;
    }
};

int main() {

    return 0;
}


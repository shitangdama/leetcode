#include <bits/stdc++.h>

class Solution {
public:
    TreeNode *upsideDownBinaryTree(TreeNode *root) {
        if(!root || (!root->left && !root->right)) 
            return root;
        TreeNode * parent = upsideDownBinaryTree(root->left);
        root->left->left = root->right;//because parameter could be NULL, so parent->left does not make sense.
        root->left->right = root; 
        root->left = NULL;
        root->right = NULL;
        return parent;
    }
};

class Solution {
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (!root) return NULL;
        TreeNode* p = root, *parent = NULL, *parentRight = NULL;
        while (p) {
            TreeNode* left = p->left;
            p->left = parentRight;
            parentRight = p->right;
            p->right = parent;
            parent = p;
            p = left;
        }
        return parent;
    }
};
int main() {
    return 0;
}


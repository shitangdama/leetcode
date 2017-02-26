<<<<<<< HEAD
// Inorder Successor in BST
class Solution {
public:
  TreeNode* inorderSuccessor(TreeNode* x, TreeNode* p) {
    TreeNode *r = NULL;
    while (x) {
      if (p->val < x->val) {
        r = x;
        x = x->left;
      } else
        x = x->right;
    }
    return r;
  }
=======
// Inorder Successor in BST
class Solution {
public:
  TreeNode* inorderSuccessor(TreeNode* x, TreeNode* p) {
    TreeNode *r = NULL;
    while (x) {
      if (p->val < x->val) {
        r = x;
        x = x->left;
      } else
        x = x->right;
    }
    return r;
  }
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
};
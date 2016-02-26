class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        TreeNode* node = root;
        int res = node->val;
        while(node) {
            if(abs(target - node->val) < abs(target - res)) {
                res = node->val;
            }

            if(target < node->val) {
                node = node->left;
            } else {
                node = node->right;
            }
        }
        
        return res;
    }
};
// Closest Binary Search Tree Value
class Solution {
public:
  int closestValue(TreeNode *x, double target) {
    int opt;
    double optd = numeric_limits<double>::max();
    while (x) {
      double d = fabs(target-x->val);
      if (d < optd)
        optd = d, opt = x->val;
      x = target < x->val ? x->left : x->right;
    }
    return opt;
  }
};
#include <bits/stdc++.h>

using namespace std;

class Solution { 
public:
    int kthSmallest(TreeNode* root, int k) {
        return smallest(root, k);
    } 
private:
    int smallest(TreeNode* node, int& k) {
        if (!node) return -1;
        int val = smallest(node -> left, k);
        if (!k) return val;
        if (!--k) return node -> val; 
        return smallest(node -> right, k);
    }
};

//int kthSmallest(TreeNode* root, int& k) {
//    if (root) {
//        int x = kthSmallest(root->left, k);
//        return !k ? x : !--k ? root->val : kthSmallest(root->right, k);
 //   }
//}
class Solution {
public:
  int kthSmallest(TreeNode *x, int k) {
    vector<TreeNode *> s(k);
    int i = 0, j = k;
    for(;;) {
      while (x) {
        s[i++%k] = x;
        x = x->left;
      }
      x = s[--i%k];
      if (! --j)
        return x->val;
      x = x->right;
    }
  }
};
int main() {

    return 0;
}


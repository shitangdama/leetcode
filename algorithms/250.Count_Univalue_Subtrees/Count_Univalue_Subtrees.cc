/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {

 public:
  bool bt(TreeNode *root, int & cnt) {
    if(root == NULL) return true;
    if(root->left == NULL && root->right == NULL) { cnt ++; return true; }
    int lflag = bt(root->left, cnt);
    int rflag = bt(root->right, cnt);
    if(lflag && rflag) {
      int lv = root->left ? root->left->val : root->val;
      int rv = root->right ? root->right->val : root->val;
      if(root->val == lv && root->val == rv) {
        cnt += 1;
        return true;
      }
      return false;
    } else {
      return false;
    }
  }

  int countUnivalSubtrees(TreeNode* root) {
    if(root == NULL) return 0;
    int cnt = 0;
    bt(root, cnt);
    return cnt;
  }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL) return 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    
    bool isUnivalSubtrees(TreeNode* root) {
        if(root == NULL) return true;
        if(root->left == NULL && root->right == NULL) return true;
        if(root->left == NULL && root->right != NULL) {
            if(root->val == root->right->val && isUnivalSubtrees(root->right)) {
                return true;
            }
            return false;
        }
        
        if(root->left != NULL && root->right == NULL) {
            if(root->val == root->left->val && isUnivalSubtrees(root->left)) {
                return true;
            }
            return false;
        }
        
        if(root->val == root->left->val && root->val == root->right->val && isUnivalSubtrees(root->left) && isUnivalSubtrees(root->right)) {
            return true;
        }
        
        return false;
    }

public:
    int countUnivalSubtrees(TreeNode* root) {
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL) return 1;
        if(isUnivalSubtrees(root)) {
            return countNodes(root);
        } else {
            int res = 0;
            if(root->left) {
                res += countUnivalSubtrees(root->left);
            }
            if(root->right) {
                res += countUnivalSubtrees(root->right);
            }
            return res;
        }
    }
};
// Count Univalue Subtrees

/// recursive

class Solution {
  bool f(TreeNode *x, int &r) {
    if (! x) return true;
    auto fl = f(x->left, r),
         fr = f(x->right, r);
    if (fl && fr && (! x->left || x->left->val == x->val) &&
        (! x->right || x->right->val == x->val))
      return r++, true;
    return false;
  }
public:
  int countUnivalSubtrees(TreeNode *x) {
    int r = 0;
    f(x, r);
    return r;
  }
};

/// post-order traversal with stack

class Solution {
public:
  int countUnivalSubtrees(TreeNode *x) {
    int r = 0;
    stack<pair<TreeNode*, bool>> s;
    for(;;) {
      for (; x; x = x->left)
        s.push({x, true});
      while (! s.empty() && s.top().first->right == x) {
        bool f = s.top().second;
        x = s.top().first;
        s.pop();
        r += f;
        if (! s.empty())
          s.top().second &= f && s.top().first->val == x->val;
      }
      if (s.empty())
        break;
      x = s.top().first->right;
    }
    return r;
  }
};

/// Morris-like post-order traversal

class Solution {
  void reverse_right_chain(TreeNode *x, TreeNode *y) {
    TreeNode *z = x->right, *t;
    while (x != y) {
      t = z->right;
      z->right = x;
      x = z;
      z = t;
    }
  }
public:
  int countUnivalSubtrees(TreeNode *x) {
    TreeNode aux(0), *y, *z, *t;
    aux.left = x;
    x = &aux;
    int r = 0;
    while (x) {
      y = x->left;
      if (y) {
        while (y->right && y->right != x)
          y = y->right;
        if (y->right == x) {
          reverse_right_chain(x->left, y);
          t = NULL;
          for (z = y; ; t = z, z = z->right) {
            if (z->left && z->left->val != z->val || t && t->val != z->val)
              z->val = INT_MIN;
            else
              r++;
            if (z == x->left) break;
          }
          reverse_right_chain(y, x->left);
          y->right = NULL;
        } else {
          y->right = x;
          x = x->left;
          continue;
        }
      }
      x = x->right;
    }
    return r;
  }
};
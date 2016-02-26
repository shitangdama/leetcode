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
    vector<int> rightSideView(TreeNode *root) {
        queue<TreeNode *> pre;
        vector<int> ret;

        if (!root) return ret;

        pre.push(root);
        while (!pre.empty()) {
            ret.push_back(pre.front()->val);
            queue<TreeNode *> cur;
            while (!pre.empty()) {
                if (pre.front()->right)
                    cur.push(pre.front()->right);
                if (pre.front()->left)
                    cur.push(pre.front()->left);
                pre.pop();
            }
            swap(pre, cur);
        }
        
        return ret;
    }
};
class Solution {
 public:
  vector<int> rightSideView(TreeNode* root) {
    vector<int> nodes;
    if(root == NULL) return nodes;
    vector<vector<int>> tmp;
    queue<pair<TreeNode *, int>> q;
    q.push(make_pair(root, 0));
    while(!q.empty()) {
      auto pr = q.front(); q.pop();
      auto node = pr.first;
      int level = pr.second;
      if(level >= tmp.size()) tmp.resize(level+1);
      tmp[level].push_back(node->val);
      if(node->left) q.push(make_pair(node->left, level + 1));
      if(node->right) q.push(make_pair(node->right, level + 1));
    }
    for(int i = 0; i < tmp.size(); ++i) { 
      nodes.push_back(tmp[i].back()); 
    }
    return nodes;
  }
};
class Solution {
public:
    void recursion(TreeNode *root, int level, vector<int> &res)
    {
        if(root==NULL) return ;
        if(res.size()<level) res.push_back(root->val);
        recursion(root->right, level+1, res);
        recursion(root->left, level+1, res);
    }

    vector<int> rightSideView(TreeNode *root) {
        vector<int> res;
        recursion(root, 1, res);
        return res;
    }
};
int main() {

    return 0;
}


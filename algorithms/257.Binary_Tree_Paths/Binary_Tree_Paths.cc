 class Solution {
    public:

            vector<string> binaryTreePaths(TreeNode* root) {
                vector<string> v;
                if(root)
                    preorder(v,root,"");
                return v;
            }
            void preorder(vector<string>& v,TreeNode* r,string t){
                if(!r)
                    return;
                if(!t.empty())
                    t+=("->"+to_string(r->val));
                else t+=to_string(r->val);
                if(r->left||r->right){
                    preorder(v,r->left,t);
                    preorder(v,r->right,t);
                }else{
                    v.push_back(t);
                }
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
public:
    void binaryTreePaths(vector<string>& result, TreeNode* root, string t) {
    if(!root->left && !root->right) {
        result.push_back(t);
        return;
    }

    if(root->left) binaryTreePaths(result, root->left, t + "->" + to_string(root->left->val));
    if(root->right) binaryTreePaths(result, root->right, t + "->" + to_string(root->right->val));
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> result;
    if(!root) return result;

    binaryTreePaths(result, root, to_string(root->val));
    return result;
}
};
// Binary Tree Paths
class Solution {
  vector<string> r;
  void f(TreeNode *x, string s) {
    if (! x) return;
    s = s.empty() ? to_string(x->val) : s+"->"+to_string(x->val);
    f(x->left, s);
    f(x->right, s);
    if (! x->left && ! x->right)
      r.push_back(s);
  }
public:
  vector<string> binaryTreePaths(TreeNode *root) {
    f(root, "");
    return r;
  }
};
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
    vector<TreeNode *> generate(int op, int ed) {
        vector<TreeNode *> ret;
        if (op > ed) {
            ret.push_back(NULL);
            return ret;
        }

        vector<TreeNode *> left, right;
        for (int k = op; k <= ed; ++k) {
            left = generate(op, k - 1);
            right = generate(k + 1, ed);

            for (auto &i : left)
                for (auto &j : right) {
                    TreeNode *root = new TreeNode(k);
                    root->left = i;
                    root->right = j;
                    ret.push_back(root);
                }
        }

        return ret;
    }
public:
    vector<TreeNode *> generateTrees(int n) {
        return generate(1, n);
    }
};
class Solution2 {
public:
    vector<TreeNode *> generateTrees(int n) {
       return createTree(1,n);
    }
    
    vector<TreeNode *> createTree(int start, int end)
    {
        vector<TreeNode *> results;
        if(start>end)
        {
            results.push_back(NULL);
            return results;
        }
        
        for(int k=start;k<=end;k++)
        {
            vector<TreeNode *> left = createTree(start,k-1);
            vector<TreeNode *> right = createTree(k+1,end);
            for(int i=0;i<left.size();i++)
            {
                for(int j=0;j<right.size();j++)
                {
                    TreeNode * root = new TreeNode(k);
                    root->left = left[i];
                    root->right = right[j];
                    results.push_back(root);
                }
            }
        }
        return results;
    }
};

int main() {

    return 0;
}


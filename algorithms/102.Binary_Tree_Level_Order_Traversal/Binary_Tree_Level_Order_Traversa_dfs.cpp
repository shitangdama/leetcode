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
    vector<vector<int> >ans;
public:
    void DFS(TreeNode *curNode, int depth) {
        if (!curNode)
            return;
        // push back
        if (depth >= ans.size())
            ans.push_back(vector<int>(0));
        ans[depth].push_back(curNode->val);

        // recursive
        if (curNode->left)
            DFS(curNode->left, depth + 1);
        if (curNode->right)
            DFS(curNode->right, depth + 1);
    }

    vector<vector<int> > levelOrder(TreeNode *root) {
        ans.clear();
        DFS(root, 0);
        return ans;
    }
};

int main() {

    return 0;
}


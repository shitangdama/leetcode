<<<<<<< HEAD
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
    vector<vector<int> > levelOrder(TreeNode *root) {
        queue<TreeNode *> q;
        vector<vector<int> > res;
        vector<int> tmpv;
        TreeNode *front;
        
        if (root == NULL)
            return res;

        // bfs
        q.push(root);
        q.push(NULL);    // NULL is the seperator of levels
        while (!q.empty()) {
            front = q.front();
            q.pop();
            if (front) {
                tmpv.push_back(front->val);
                if (front->left)
                    q.push(front->left);
                if (front->right)
                    q.push(front->right);
            } else if (!tmpv.empty()) {
                res.push_back(tmpv);
                tmpv.clear();
                q.push(NULL);
            }
        }
        return res;
    }
};

int main() {
    TreeNode *p = new TreeNode(1);
    Solution s;
    s.levelOrder(p);
    return 0;
}

=======
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
    vector<vector<int> > levelOrder(TreeNode *root) {
        queue<TreeNode *> q;
        vector<vector<int> > res;
        vector<int> tmpv;
        TreeNode *front;
        
        if (root == NULL)
            return res;

        // bfs
        q.push(root);
        q.push(NULL);    // NULL is the seperator of levels
        while (!q.empty()) {
            front = q.front();
            q.pop();
            if (front) {
                tmpv.push_back(front->val);
                if (front->left)
                    q.push(front->left);
                if (front->right)
                    q.push(front->right);
            } else if (!tmpv.empty()) {
                res.push_back(tmpv);
                tmpv.clear();
                q.push(NULL);
            }
        }
        return res;
    }
};

int main() {
    TreeNode *p = new TreeNode(1);
    Solution s;
    s.levelOrder(p);
    return 0;
}

>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74

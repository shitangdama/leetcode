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

class BSTIterator {
private:
    queue<int> in_res;
    void inorder(TreeNode *root) {
        if (root != NULL) {
            inorder(root->left);
            in_res.push(root->val);
            inorder(root->right);
        }
    }

public:
    BSTIterator(TreeNode *root) {
        // generate the inorder list
        while (!in_res.empty())
            in_res.pop();
        inorder(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return in_res.size() != 0;
    }

    /** @return the next smallest number */
    int next() {
        int front = in_res.front();
        in_res.pop();
        return front;
    }
};
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    stack<TreeNode *> s;
    BSTIterator(TreeNode *root) {
        pushLeft(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* top = s.top();
        s.pop();
        pushLeft(top->right);
        return top->val;
    }
    
    void pushLeft(TreeNode* root)
    {
        if(root != NULL)
        {
            s.push(root);
            TreeNode* cur = root;
            while(cur->left)
            {
                s.push(cur->left);
                cur = cur->left;
            }
        }
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
class BSTIterator {
    private:
        vector<int> v; 
        int pos;
    public:
        //Travse the Tree in-order and covert it to an array
        BSTIterator(TreeNode *root) {
            pos = 0;
            vector<TreeNode*> stack;
            while(stack.size()>0 || root !=NULL) {
                if (root){
                    stack.push_back(root);
                    root = root->left;
                }else{
                    root = stack.back();
                    stack.pop_back();
                    v.push_back(root->val);
                    root = root->right;
                }
            }
        }

        /** @return whether we have a next smallest number */
        bool hasNext() {
            return pos < v.size();
        }

        /** @return the next smallest number */
        int next() {
            return v[pos++];
        }
};
class BSTIterator {
 public:
  BSTIterator(TreeNode *root) {
    while(root) {
      stk.push(root);
      root = root->left;
    }
  }

  /** @return whether we have a next smallest number */
  bool hasNext() { return !stk.empty(); }

  /** @return the next smallest number */
  int next() {
    auto node = stk.top();
    stk.pop();
    int v = node->val;
    node = node->right;
    while(node) {
      stk.push(node);
      node = node->left;
    }
    return v;
  }

 private:
  stack<TreeNode *> stk;
};
int main() {
    BSTIterator i = BSTIterator(root);
    while (i.hasNext()) cout << i.next();
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

class BSTIterator {
private:
    queue<int> in_res;
    void inorder(TreeNode *root) {
        if (root != NULL) {
            inorder(root->left);
            in_res.push(root->val);
            inorder(root->right);
        }
    }

public:
    BSTIterator(TreeNode *root) {
        // generate the inorder list
        while (!in_res.empty())
            in_res.pop();
        inorder(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return in_res.size() != 0;
    }

    /** @return the next smallest number */
    int next() {
        int front = in_res.front();
        in_res.pop();
        return front;
    }
};
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    stack<TreeNode *> s;
    BSTIterator(TreeNode *root) {
        pushLeft(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* top = s.top();
        s.pop();
        pushLeft(top->right);
        return top->val;
    }
    
    void pushLeft(TreeNode* root)
    {
        if(root != NULL)
        {
            s.push(root);
            TreeNode* cur = root;
            while(cur->left)
            {
                s.push(cur->left);
                cur = cur->left;
            }
        }
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
class BSTIterator {
    private:
        vector<int> v; 
        int pos;
    public:
        //Travse the Tree in-order and covert it to an array
        BSTIterator(TreeNode *root) {
            pos = 0;
            vector<TreeNode*> stack;
            while(stack.size()>0 || root !=NULL) {
                if (root){
                    stack.push_back(root);
                    root = root->left;
                }else{
                    root = stack.back();
                    stack.pop_back();
                    v.push_back(root->val);
                    root = root->right;
                }
            }
        }

        /** @return whether we have a next smallest number */
        bool hasNext() {
            return pos < v.size();
        }

        /** @return the next smallest number */
        int next() {
            return v[pos++];
        }
};
class BSTIterator {
 public:
  BSTIterator(TreeNode *root) {
    while(root) {
      stk.push(root);
      root = root->left;
    }
  }

  /** @return whether we have a next smallest number */
  bool hasNext() { return !stk.empty(); }

  /** @return the next smallest number */
  int next() {
    auto node = stk.top();
    stk.pop();
    int v = node->val;
    node = node->right;
    while(node) {
      stk.push(node);
      node = node->left;
    }
    return v;
  }

 private:
  stack<TreeNode *> stk;
};
int main() {
    BSTIterator i = BSTIterator(root);
    while (i.hasNext()) cout << i.next();
    return 0;
}


>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74

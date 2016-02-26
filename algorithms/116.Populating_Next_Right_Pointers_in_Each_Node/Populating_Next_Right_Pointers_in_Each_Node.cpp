#include <bits/stdc++.h>

using namespace std;

// Definition for binary tree with next pointer.
struct TreeLinkNode {
 int val;
 TreeLinkNode *left, *right, *next;
 TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode header(0);
        header.next = root;
        TreeLinkNode *cur, *prev;
        while (header.next) {
            // current header's link is already populated
            // following will make a new children-link to header
            cur = header.next;
            prev = &header;
            header.next = nullptr;
            for (; cur; cur = cur->next) {
                if (cur->left != nullptr) {
                    prev->next = cur->left;
                    prev = prev->next;
                }
                if (cur->right != nullptr) {
                    prev->next = cur->right;
                    prev = prev->next;
                }
            }
        }
    }
};
// LeetCode, Populating Next Right Pointers in Each Node
// 时间复杂度O(n)，空间复杂度O(logn)
class Solution {
public:
    void connect(TreeLinkNode *root) {
        connect(root, NULL);
    }
private:
    void connect(TreeLinkNode *root, TreeLinkNode *sibling) {
        if (root == nullptr)
            return;
        else
            root->next = sibling;

        connect(root->left, root->right);
        if (sibling)
            connect(root->right, sibling->left);
        else
            connect(root->right, nullptr);
    }
};

int main() {
    TreeLinkNode root(1);
    Solution s;
    s.connect(&root);
    return 0;
}


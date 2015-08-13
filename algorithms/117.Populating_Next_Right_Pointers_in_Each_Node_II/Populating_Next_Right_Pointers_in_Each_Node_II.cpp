#include <bits/stdc++.h>

using namespace std;

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

int main() {

    return 0;
}


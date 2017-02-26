class Solution {
    typedef pair<int, unsigned> Rec; // last val - length
    unsigned ret;
    void go(TreeNode *p, Rec r)
    {
        if(!p) return;
        
        Rec nr(p->val, 1);
        if(r.second && p->val == (r.first + 1))
        {
            nr = Rec(p->val, r.second + 1);
        }
        ret = max(ret, nr.second);
        
        go(p->left, nr);
        go(p->right, nr);
    }
public:
    int longestConsecutive(TreeNode* root) {
        ret = 0;
        go(root, Rec(0, 0));
        return ret;
    }
};

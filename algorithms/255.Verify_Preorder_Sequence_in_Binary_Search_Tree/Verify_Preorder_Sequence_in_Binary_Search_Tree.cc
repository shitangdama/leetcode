// Verify Preorder Sequence in Binary Search Tree
class Solution {
public:
  bool verifyPreorder(vector<int>& preorder) {
    int p = INT_MIN;
    stack<int> s;
    for (auto x: preorder) {
      if (x < p)
        return false;
      while (! s.empty() && s.top() < x) {
        p = s.top();
        s.pop();
      }
      s.push(x);
    }
    return true;
  }
};
class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        int low = INT_MIN;
        int i = -1;
        for(int j = 0; j < preorder.size(); j++) {
            if(preorder[j] < low) {
                return false;
            }

            while(i >= 0 && preorder[i] < preorder[j]) {
                low = preorder[i];
                i--;
            }

            i++;
            preorder[i] = preorder[j];
        }
        return true;
    }
};
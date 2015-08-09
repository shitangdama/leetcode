#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int> > res;
        do {
            res.push_back(num);
        } while (next_permutation(num.begin(), num.end()));
        return res;
    }
};

int main() {

    return 0;
}


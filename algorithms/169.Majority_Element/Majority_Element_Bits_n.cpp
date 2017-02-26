
#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int majorityElement(vector<int> &num) {
        int bitcnt[32] = {0};
        // swap the follow two 'for', it can work without bitcnt[]
        for (auto &i : num) {
            for (int j = 0; j < 32; ++j)
                if (i & (1<<j))
                    ++bitcnt[j];
        }
        int ans = 0;
        for (int i = 0; i < 32; ++i)
            if (bitcnt[i] > num.size() / 2)
                ans |= (1<<i);
        return ans;
    }
};

int main() {
    vector<int> num{-1, 1, 1};
    Solution s;
    cout << s.majorityElement(num) << endl;
    return 0;
}


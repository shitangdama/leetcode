#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int> > res;
        do {
            res.push_back(num);
        } while (next_permutation(num.begin(), num.end()));
        return res;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> num(n);
    for (auto &i : num)
        cin >> i;
    Solution s;
    vector<vector<int> > ans = s.permuteUnique(num);
    for (auto &i : ans) {
        for (auto &j : i)
            cout << j << ' ';
        cout << endl;
    }
    return 0;
}


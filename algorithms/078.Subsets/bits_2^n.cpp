

#include <bits/stdc++.h>

using namespace std;
const int N = 0;

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        long long upper = 1LL << S.size();
        vector<vector<int> > res;
        sort(S.begin(), S.end());
        for (long long i = 0; i < upper; ++i) {
            vector<int> single;
            for (int j = 0; j < S.size(); ++j)
                if ((1LL<<j) & i)
                    single.push_back(S[j]);
            res.push_back(single);
        }
        return res;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> S(n);
    for (auto &i : S)
        cin >> i;
    Solution s;
    vector<vector<int> > res = s.subsets(S);
    for (auto &i : res) {
        for (auto &j : i)
            cout << j << ' ';
        cout << endl;
    }
    return 0;
}


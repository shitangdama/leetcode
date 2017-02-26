#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    void dfs(vector<vector<int> > &ans, vector<int> &single,
            vector<int> &candi, int cur, int rest) {
        int sz = candi.size();
        if (sz <= cur || rest < 0)
            return;
        if (rest == 0) {
            ans.push_back(single);
            return;
        }
        // choose cur
        single.push_back(candi[cur]);
        dfs(ans, single, candi, cur, rest - candi[cur]);
        single.pop_back();
        // don't choose cur
        dfs(ans, single, candi, cur + 1, rest);
    }
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > ans;
        vector<int> single;
        sort(candidates.begin(), candidates.end());
        dfs(ans, single, candidates, 0, target);
        return ans;
    }
};

int main() {
    int tar;
    int n;
    Solution s;
    cin >> n >> tar;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<vector<int> > res = s.combinationSum(v, tar);
    for (auto &i : res) {
        for (auto &j : i)
            cout << j << ' ';
        puts("");
    }
    return 0;
}


<<<<<<< HEAD
#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    void dfs(int dep, const vector<vector<int> > &newS, vector<int> &cur,
            vector<vector<int> > &res) {
        if (dep == newS.size()) {
            res.push_back(cur);
        } else {
            // not choose
            dfs(dep + 1, newS, cur, res);
            // choose
            for (int i = 0; i < newS[dep].size(); ++i) {
                cur.push_back(newS[dep][i]);
                dfs(dep + 1, newS, cur, res);
            }
            for (int i = 0; i < newS[dep].size(); ++i)
                cur.pop_back();
        }
    }
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > res;
        if (S.empty()) return res;
        vector<vector<int> > newS;
        vector<int> cur;
        sort(S.begin(), S.end());
        newS.push_back(vector<int> {S[0]});
        for (int i = 1; i < S.size(); ++i) {
            if (S[i] == S[i - 1])
                newS[newS.size() - 1].push_back(S[i]);
            else
                newS.push_back(vector<int> {S[i]} );
        }
        dfs(0, newS, cur, res);
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
    vector<vector<int> > res = s.subsetsWithDup(S);
    for (auto &i : res) {
        for (auto &j : i)
            cout << j << ' ';
        cout << endl;
    }
    return 0;
}

=======
#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    void dfs(int dep, const vector<vector<int> > &newS, vector<int> &cur,
            vector<vector<int> > &res) {
        if (dep == newS.size()) {
            res.push_back(cur);
        } else {
            // not choose
            dfs(dep + 1, newS, cur, res);
            // choose
            for (int i = 0; i < newS[dep].size(); ++i) {
                cur.push_back(newS[dep][i]);
                dfs(dep + 1, newS, cur, res);
            }
            for (int i = 0; i < newS[dep].size(); ++i)
                cur.pop_back();
        }
    }
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > res;
        if (S.empty()) return res;
        vector<vector<int> > newS;
        vector<int> cur;
        sort(S.begin(), S.end());
        newS.push_back(vector<int> {S[0]});
        for (int i = 1; i < S.size(); ++i) {
            if (S[i] == S[i - 1])
                newS[newS.size() - 1].push_back(S[i]);
            else
                newS.push_back(vector<int> {S[i]} );
        }
        dfs(0, newS, cur, res);
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
    vector<vector<int> > res = s.subsetsWithDup(S);
    for (auto &i : res) {
        for (auto &j : i)
            cout << j << ' ';
        cout << endl;
    }
    return 0;
}

>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74

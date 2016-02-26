#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    void dfs(vector<vector<int> > &res, vector<int> &v,
            int cur, int rest, int n) {
        if (rest == 0) {
            res.push_back(v);
            return;
        }
        v.push_back(0);
        int len = v.size();
        for (int i = cur; i <= n - rest + 1; i++) {
            v[len - 1] = i;
            dfs(res, v, i + 1, rest - 1, n);
        }
        v.pop_back();
    }
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > res;
        if (n < k || !n || !k)
            return res;
        vector<int> v;
        dfs(res, v, 1, k, n);
        return res;
    }
};

class Solution2 {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> > result;
        vector<int> array;
        int number = pow(2, n);
        for (int i = 0; i < number; ++i) {
            if (isNum(i, k)) {
                int bit = i;
                int j = 0;
                while (bit) {
                    if (bit & 1)
                        array.push_back(j+1);
                    bit = bit >> 1;
                    j++;
                }
                result.push_back(array);
                array.clear();
            }
        }
        return result;
    }
    bool isNum(int i, int k) {
        int num = 0;
        while (i) {
            ++num;
            i &= (i-1);
        }
        return num == k;
    }
};
class Solution3 {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > res;

        int comb =  (1<<k) -1;
        while (comb < 1<<n){
            vector<int> ans;
            for (int i = 0; i < n; i++){
                if (comb>>i &1)  ans.push_back(i+1);
            }
            res.push_back(ans);

            //generate the next comb
            int x = comb & -comb;
            int y = comb + x;
            comb = ((comb & ~y)/x >>1) | y;
        }
        return res;
    }
};

int main() {
    int n, k;
    Solution s;
    while (cin >> n >> k) {
        vector<vector<int> > res = s.combine(n, k);
        for (auto &i : res) {
            for (auto &j : i)
                cout << j << ' ';
            cout << endl;
        }
    }
    return 0;
}


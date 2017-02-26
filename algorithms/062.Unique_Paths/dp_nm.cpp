#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        // way 1
        // vector<vector<int> > tab(2, vector<int>(n + 1, 1));
        // for (int i = 1; i < m; i++)
        //     for (int j = 1; j < n; j++)
        //         tab[i&1][j] = tab[!(i&1)][j] + tab[i&1][j - 1];
        // return tab[(m-1)&1][n - 1];
        
        vector<int> tab(n, 1);
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                tab[j] += tab[j - 1];
        return tab[n - 1];
    }
};

int main() {
    int n, m;
    Solution s;
    while (cin >> n >> m) {
        cout << s.uniquePaths(n, m);
    }
    return 0;
}


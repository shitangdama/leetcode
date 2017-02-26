#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        m = board.size() - 1;
        n = board[0].size() - 1;
        for (int i = 0; i <= m; i++)
            for (int j = 0; j <= n; j++)
                if (board[i][j] == word[0])
                    if (dfs(board, i, j, word.c_str() + 1))
                        return true;
        return false;
    }
private:
    int m, n;
    bool dfs(vector<vector<char> > &board, int i, int j, const char *w) {
        if (*w == 0)
            return true;
        board[i][j] ^= 0x80;
        for (int k = -(i != 0); k <= (i < m); k++)
            for (int l = -(j != 0); l <= (j < n); l++)
                if ((k ^ l) & 1 && board[i + k][j + l] == *w)
                    if (dfs(board, i + k, j + l, w + 1))
                        return true;
        board[i][j] ^= 0x80;
        return false;
    }
};
int main() {
    int n, m;
    string w;
    Solution s;
    cin >> n >> m;
    vector<vector<char> > b(n, vector<char>(m));
    for (auto &i : b)
        for (auto &j : i)
            cin >> j;
    while (cin >> w)
        cout << s.exist(b, w) << endl;
    return 0;
}


#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int row[9], col[9], sqr[3][3];
    bool check(int x, int y, int val) {
        return !((row[x]>>val)&1) && !((col[y]>>val)&1) && !((sqr[x/3][y/3]>>val)&1);
    }
    void mark(int x, int y, int val) {
        row[x] |= (1<<val);
        col[y] |= (1<<val);
        sqr[x/3][y/3] |= (1<<val);
    }
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        memset(sqr, 0, sizeof(sqr));
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[i].size(); j++)
                if (board[i][j] != '.') {
                    if (!check(i, j, board[i][j] - '1'))
                        return false;
                    mark(i, j, board[i][j] - '1');
                }
        return true;
        // return dfs(0, board);
    }
};

int main() {
    vector<vector<char> > v;
    Solution s;
    char ch[10];
    for (int i = 0; i < 9; i++) {
        vector<char> v2;
        scanf("%s", ch);
        for (int j = 0; j < 9; j++) {
            v2.push_back(ch[j]);
        }
        v.push_back(v2);
    }
    cout << s.isValidSudoku(v) << endl;
    return 0;
}


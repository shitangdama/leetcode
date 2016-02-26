#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    const int dx[4] = {0, 0, 1, -1};
    const int dy[4] = {1, -1, 0, 0};
    void bfs(int x, int y, vector<vector<char> > &board) {
        int n = board.size(), m = board[0].size();
        queue<pair<int, int> > q;
        q.push(make_pair(x, y));
        board[x][y] = '+';

        while (!q.empty()) {
            x = q.front().first;
            y = q.front().second;
            q.pop();
            // go to 4 directions
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && board[nx][ny] == 'O') {
                    board[nx][ny] = '+';
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }

public:
    void solve(vector<vector<char>> &board) {
        if (board.empty() || board[0].empty())
            return;

        int n = board.size(), m = board[0].size();
        if (n <= 2 || m <= 2)
            return;

        // find side O
        for (int i = 0; i < n; ++i) {
            if (board[i][0] == 'O')
                bfs(i, 0, board);
            if (board[i][m - 1] == 'O')
                bfs(i, m - 1, board);
        }
        for (int j = 0; j < m; ++j) {
            if (board[0][j] == 'O')
                bfs(0, j, board);
            if (board[n - 1][j] == 'O')
                bfs(n - 1, j, board);
        }

        // change board
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (board[i][j] == '+')
                    board[i][j] = 'O';
                else if (board[i][j] == 'O')
                    board[i][j] = 'X';

    }
};
// LeetCode, Surrounded Regions
// BFS，时间复杂度O(n)，空间复杂度O(n)
class Solution {
public:
    void solve(vector<vector<char>> &board) {
        if (board.empty()) return;

        const int m = board.size();
        const int n = board[0].size();
        for (int i = 0; i < n; i++) {
            bfs(board, 0, i);
            bfs(board, m - 1, i);
        }
        for (int j = 1; j < m - 1; j++) {
            bfs(board, j, 0);
            bfs(board, j, n - 1);
        }
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '+')
                    board[i][j] = 'O';
    }
private:
    void bfs(vector<vector<char>> &board, int i, int j) {
        typedef pair<int, int> state_t;
        queue<state_t> q;
        const int m = board.size();
        const int n = board[0].size();

        auto is_valid = [&](const state_t &s) {
            const int x = s.first;
            const int y = s.second;
            if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] != 'O')
                return false;
            return true;
        };

        auto state_extend = [&](const state_t &s) {
            vector<state_t> result;
            const int x = s.first;
            const int y = s.second;
            // 上下左右
            const state_t new_states[4] = {{x-1,y}, {x+1,y},
                    {x,y-1}, {x,y+1}};
            for (int k = 0; k < 4;  ++k) {
                if (is_valid(new_states[k])) {
                    // 既有标记功能又有去重功能
                    board[new_states[k].first][new_states[k].second] = '+';
                    result.push_back(new_states[k]);
                }
            }

            return result;
        };

        state_t start = { i, j };
        if (is_valid(start)) {
            board[i][j] = '+';
            q.push(start);
        }
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            auto new_states = state_extend(cur);
            for (auto s : new_states) q.push(s);
        }
    }
};

int main() {
    int n;
    cin >> n;
    vector<vector<char> > inp(n);
    for (auto &i : inp) {
        string str;
        cin >> str;
        for (auto & j : str)
            i.push_back(j);
    }
    Solution s;
    s.solve(inp);
    return 0;
}


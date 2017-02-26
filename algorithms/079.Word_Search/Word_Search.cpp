<<<<<<< HEAD
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool exist(std::vector<std::vector<char> > &board, std::string word) {
        rows = static_cast<int>(board.size()), cols = static_cast<int>(board[0].size());
        for (int row = 0; row != rows; ++row)
            for (int col = 0; col != cols; ++col)
                if (exist(board, word, row, col, 0))
                    return true;
        return false;
    }
private:
    int rows, cols;
    bool exist(std::vector<std::vector<char> > &board, std::string &word, int row, int col, int k) {
        if (board[row][col] != word[k] || board[row][col] == ' ')
            return false;
        else if (k == word.size() - 1)
            return true;
        char c = board[row][col];
        board[row][col] = ' ';
        if ((row > 0 && exist(board, word, row - 1, col, k + 1)) ||
            (row < rows - 1 && exist(board, word, row + 1, col, k + 1)) ||
            (col > 0 && exist(board, word, row, col - 1, k + 1)) ||
            (col < cols - 1 && exist(board, word, row, col + 1, k + 1))) {
            board[row][col] = c;
            return true;
        }
        board[row][col] = c;
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

=======
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool exist(std::vector<std::vector<char> > &board, std::string word) {
        rows = static_cast<int>(board.size()), cols = static_cast<int>(board[0].size());
        for (int row = 0; row != rows; ++row)
            for (int col = 0; col != cols; ++col)
                if (exist(board, word, row, col, 0))
                    return true;
        return false;
    }
private:
    int rows, cols;
    bool exist(std::vector<std::vector<char> > &board, std::string &word, int row, int col, int k) {
        if (board[row][col] != word[k] || board[row][col] == ' ')
            return false;
        else if (k == word.size() - 1)
            return true;
        char c = board[row][col];
        board[row][col] = ' ';
        if ((row > 0 && exist(board, word, row - 1, col, k + 1)) ||
            (row < rows - 1 && exist(board, word, row + 1, col, k + 1)) ||
            (col > 0 && exist(board, word, row, col - 1, k + 1)) ||
            (col < cols - 1 && exist(board, word, row, col + 1, k + 1))) {
            board[row][col] = c;
            return true;
        }
        board[row][col] = c;
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

>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74

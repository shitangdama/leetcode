<<<<<<< HEAD
#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    // shared variable
    vector<vector<string> > result;
    vector<string> cur;    // current
    vector<int> col;    // columns placed queens
    vector<int> m_diag;    // main diag placed queens
    vector<int> a_diag;    // anti main diag placed queens
    int N;

    void dfs(int row) {
        if (row == N) {
            result.push_back(cur);
            return;
        }
        for (int i = 0; i < N; ++i) {
            if (col[i] || m_diag[row + i] || a_diag[row - i + N])
                continue;
            col[i] = m_diag[row + i] = a_diag[row - i + N] =  1;
            cur[row][i] = 'Q';
            dfs(row + 1);
            cur[row][i] = '.';
            col[i] = m_diag[row + i] = a_diag[row - i + N] =  0;
        }
    }

public:
    vector<vector<string> > solveNQueens(int n) {
        result.clear();
        cur = vector<string>(n, string(n, '.'));
        col = vector<int>(n, 0);
        m_diag = vector<int>(n << 1, 0);
        a_diag = vector<int>(n << 1, 0);
        N = n;

        dfs(0);
        return result;
    }
};

// LeetCode, N-Queens
// 深搜+剪枝
// 时间复杂度O(n!)，空间复杂度O(n)
class Solution2 {
public:
    vector<vector<string> > solveNQueens(int n) {
        this->columns = vector<int>(n, 0);
        this->main_diag = vector<int>(2 * n, 0);
        this->anti_diag = vector<int>(2 * n, 0);

        vector<vector<string> > result;
        vector<int> C(n, 0);  // C[i]表示第i行皇后所在的列编号
        dfs(C, result, 0);
        return result;
    }
private:
    // 这三个变量用于剪枝
    vector<int> columns;  // 表示已经放置的皇后占据了哪些列
    vector<int> main_diag;  // 占据了哪些主对角线
    vector<int> anti_diag;  // 占据了哪些副对角线

    void dfs(vector<int> &C, vector<vector<string> > &result, int row) {
        const int N = C.size();
        if (row == N) { // 终止条件，也是收敛条件，意味着找到了一个可行解
            vector<string> solution;
            for (int i = 0; i < N; ++i) {
                string s(N, '.');
                for (int j = 0; j < N; ++j) {
                    if (j == C[i]) s[j] = 'Q';
                }
                solution.push_back(s);
            }
            result.push_back(solution);
            return;
        }

        for (int j = 0; j < N; ++j) {  // 扩展状态，一列一列的试
            const bool ok = columns[j] == 0 && main_diag[row + j] == 0 &&
                    anti_diag[row - j + N] == 0;
            if (！ok) continue;  // 剪枝：如果合法，继续递归
            // 执行扩展动作
            C[row] = j;
            columns[j] = main_diag[row + j] = anti_diag[row - j + N] = 1;
            dfs(C, result, row + 1);
            // 撤销动作
            // C[row] = 0;
            columns[j] = main_diag[row + j] = anti_diag[row - j + N] = 0;
        }
    }
};

int main() {
    int n;
    Solution s;
    cin >> n;
    vector<vector<string> > ans = s.solveNQueens(n);
    for (auto &i : ans) {
        for (auto &j : i)
            cout << j << endl;
        cout << endl;
    }
    return 0;
}

=======
#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    // shared variable
    vector<vector<string> > result;
    vector<string> cur;    // current
    vector<int> col;    // columns placed queens
    vector<int> m_diag;    // main diag placed queens
    vector<int> a_diag;    // anti main diag placed queens
    int N;

    void dfs(int row) {
        if (row == N) {
            result.push_back(cur);
            return;
        }
        for (int i = 0; i < N; ++i) {
            if (col[i] || m_diag[row + i] || a_diag[row - i + N])
                continue;
            col[i] = m_diag[row + i] = a_diag[row - i + N] =  1;
            cur[row][i] = 'Q';
            dfs(row + 1);
            cur[row][i] = '.';
            col[i] = m_diag[row + i] = a_diag[row - i + N] =  0;
        }
    }

public:
    vector<vector<string> > solveNQueens(int n) {
        result.clear();
        cur = vector<string>(n, string(n, '.'));
        col = vector<int>(n, 0);
        m_diag = vector<int>(n << 1, 0);
        a_diag = vector<int>(n << 1, 0);
        N = n;

        dfs(0);
        return result;
    }
};

// LeetCode, N-Queens
// 深搜+剪枝
// 时间复杂度O(n!)，空间复杂度O(n)
class Solution2 {
public:
    vector<vector<string> > solveNQueens(int n) {
        this->columns = vector<int>(n, 0);
        this->main_diag = vector<int>(2 * n, 0);
        this->anti_diag = vector<int>(2 * n, 0);

        vector<vector<string> > result;
        vector<int> C(n, 0);  // C[i]表示第i行皇后所在的列编号
        dfs(C, result, 0);
        return result;
    }
private:
    // 这三个变量用于剪枝
    vector<int> columns;  // 表示已经放置的皇后占据了哪些列
    vector<int> main_diag;  // 占据了哪些主对角线
    vector<int> anti_diag;  // 占据了哪些副对角线

    void dfs(vector<int> &C, vector<vector<string> > &result, int row) {
        const int N = C.size();
        if (row == N) { // 终止条件，也是收敛条件，意味着找到了一个可行解
            vector<string> solution;
            for (int i = 0; i < N; ++i) {
                string s(N, '.');
                for (int j = 0; j < N; ++j) {
                    if (j == C[i]) s[j] = 'Q';
                }
                solution.push_back(s);
            }
            result.push_back(solution);
            return;
        }

        for (int j = 0; j < N; ++j) {  // 扩展状态，一列一列的试
            const bool ok = columns[j] == 0 && main_diag[row + j] == 0 &&
                    anti_diag[row - j + N] == 0;
            if (！ok) continue;  // 剪枝：如果合法，继续递归
            // 执行扩展动作
            C[row] = j;
            columns[j] = main_diag[row + j] = anti_diag[row - j + N] = 1;
            dfs(C, result, row + 1);
            // 撤销动作
            // C[row] = 0;
            columns[j] = main_diag[row + j] = anti_diag[row - j + N] = 0;
        }
    }
};

int main() {
    int n;
    Solution s;
    cin >> n;
    vector<vector<string> > ans = s.solveNQueens(n);
    for (auto &i : ans) {
        for (auto &j : i)
            cout << j << endl;
        cout << endl;
    }
    return 0;
}

>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74

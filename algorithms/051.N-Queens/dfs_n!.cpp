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
// ����+��֦
// ʱ�临�Ӷ�O(n!)���ռ临�Ӷ�O(n)
class Solution2 {
public:
    vector<vector<string> > solveNQueens(int n) {
        this->columns = vector<int>(n, 0);
        this->main_diag = vector<int>(2 * n, 0);
        this->anti_diag = vector<int>(2 * n, 0);

        vector<vector<string> > result;
        vector<int> C(n, 0);  // C[i]��ʾ��i�лʺ����ڵ��б��
        dfs(C, result, 0);
        return result;
    }
private:
    // �������������ڼ�֦
    vector<int> columns;  // ��ʾ�Ѿ����õĻʺ�ռ������Щ��
    vector<int> main_diag;  // ռ������Щ���Խ���
    vector<int> anti_diag;  // ռ������Щ���Խ���

    void dfs(vector<int> &C, vector<vector<string> > &result, int row) {
        const int N = C.size();
        if (row == N) { // ��ֹ������Ҳ��������������ζ���ҵ���һ�����н�
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

        for (int j = 0; j < N; ++j) {  // ��չ״̬��һ��һ�е���
            const bool ok = columns[j] == 0 && main_diag[row + j] == 0 &&
                    anti_diag[row - j + N] == 0;
            if (��ok) continue;  // ��֦������Ϸ��������ݹ�
            // ִ����չ����
            C[row] = j;
            columns[j] = main_diag[row + j] = anti_diag[row - j + N] = 1;
            dfs(C, result, row + 1);
            // ��������
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
// ����+��֦
// ʱ�临�Ӷ�O(n!)���ռ临�Ӷ�O(n)
class Solution2 {
public:
    vector<vector<string> > solveNQueens(int n) {
        this->columns = vector<int>(n, 0);
        this->main_diag = vector<int>(2 * n, 0);
        this->anti_diag = vector<int>(2 * n, 0);

        vector<vector<string> > result;
        vector<int> C(n, 0);  // C[i]��ʾ��i�лʺ����ڵ��б��
        dfs(C, result, 0);
        return result;
    }
private:
    // �������������ڼ�֦
    vector<int> columns;  // ��ʾ�Ѿ����õĻʺ�ռ������Щ��
    vector<int> main_diag;  // ռ������Щ���Խ���
    vector<int> anti_diag;  // ռ������Щ���Խ���

    void dfs(vector<int> &C, vector<vector<string> > &result, int row) {
        const int N = C.size();
        if (row == N) { // ��ֹ������Ҳ��������������ζ���ҵ���һ�����н�
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

        for (int j = 0; j < N; ++j) {  // ��չ״̬��һ��һ�е���
            const bool ok = columns[j] == 0 && main_diag[row + j] == 0 &&
                    anti_diag[row - j + N] == 0;
            if (��ok) continue;  // ��֦������Ϸ��������ݹ�
            // ִ����չ����
            C[row] = j;
            columns[j] = main_diag[row + j] = anti_diag[row - j + N] = 1;
            dfs(C, result, row + 1);
            // ��������
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

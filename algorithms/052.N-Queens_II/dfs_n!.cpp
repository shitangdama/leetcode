#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    // shared variable
    int count;
    vector<int> col;    // columns placed queens
    vector<int> m_diag;    // main diag placed queens
    vector<int> a_diag;    // anti main diag placed queens
    int N;

    void dfs(int row) {
        if (row == N) {
            count++;
            return;
        }
        for (int i = 0; i < N; ++i) {
            if (col[i] || m_diag[row + i] || a_diag[row - i + N])
                continue;
            col[i] = m_diag[row + i] = a_diag[row - i + N] =  1;
            dfs(row + 1);
            col[i] = m_diag[row + i] = a_diag[row - i + N] =  0;
        }
    }

public:
    int totalNQueens(int n) {
        count = 0;
        col = vector<int>(n, 0);
        m_diag = vector<int>(n << 1, 0);
        a_diag = vector<int>(n << 1, 0);
        N = n;

        dfs(0);
        return count;
    }
};

class Solution2 {
public:
    int sum;
    
    bool canPut(int row, int col, vector<int> &cols) {
        for (int i = 0; i < row; i++) {
            if (cols[i] - i == col - row) {
                return false;
            }
            if (cols[i] + i == col + row) {
                return false;
            }
            if (cols[i] == col) {
                return false;
            }
        }
        return true;
    }
    
    void dfs(int n, int k, vector<int> &cols) {
        if (k == n) {
            sum++;
            return;
        }
        
        for (int i = 0; i < n; i++) {
            if (!canPut(k, i, cols)) {
                continue;
            }
            cols[k] = i;
            dfs(n, k + 1, cols);
        }
    }
    
    int totalNQueens(int n) {
        vector<int> cols(n);
        
        sum = 0;
        dfs(n, 0, cols);
        return sum;
    }
};

int main() {
    int n;
    Solution s;
    cin >> n;
    int ans = s.totalNQueens(n);
    cout << ans << endl;
    return 0;
}


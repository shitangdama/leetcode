#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        if (matrix.empty() || matrix[0].empty())
            return;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> row(n);
        vector<int> col(m);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (!matrix[i][j]) {
                    row[i] = 1;
                    col[j] = 1;
                }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (row[i] || col[j])
                    matrix[i][j] = 0;
    }
};

int main() {

    return 0;
}


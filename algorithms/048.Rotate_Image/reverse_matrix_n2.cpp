#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                swap(matrix[i][j], matrix[j][i]);
        for (int i = 0; i < n; i++)
            reverse(matrix[i].begin(), matrix[i].end());
    }
};

int main() {
    int n;
    Solution s;
    while (cin >> n) {
        vector< vector<int> > m;
        for (int i = 0; i < n; i++) {
            m.push_back(vector<int>(n));
            for (int j = 0; j < n; j++)
                scanf("%d", &m[i][j]);
        }
        s.rotate(m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << m[i][j] << ' ';
            cout << endl;
        }
    }
    return 0;
}


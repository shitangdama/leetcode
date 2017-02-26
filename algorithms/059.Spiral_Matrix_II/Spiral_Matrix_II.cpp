#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
            int num = 1;
    int size = n;
    int depth = 0;
    int total = n*n+1;
    while ( num < total )
    {
        // write the values clock-wise direction.
        for ( int i = 0; i < size; i ++ )
            matrix[depth][depth+i] = num++;
        for ( int i = 1; i < size; i ++ )
            matrix[depth+i][depth+size-1] = num++;
        for ( int i = 1; i < size; i ++ )
            matrix[depth+size-1][depth+size-1-i] = num++;
        for ( int i = 1; i < size-1; i ++ )
            matrix[depth+size-1-i][depth] = num++;

        size -= 2;
        depth ++;
    }

    return matrix;

    }
};
int main() {
    int n;
    Solution s;
    while (cin >> n) {
        vector<vector<int> > ans = s.generateMatrix(n);
        for (auto &i : ans) {
            for (auto &j : i)
                cout << j << ' ';
            cout << endl;
        }
    }
    return 0;
}


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0].empty())
            return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> tab(n);
        // init the first line
        for (int i = 0; i < n && !obstacleGrid[0][i]; i++)
            tab[i] = 1;
        // dp
        for (int i = 1; i < m; i++) {
            if (obstacleGrid[i][0])
                tab[0] = 0;
            for (int j = 1; j < n; j++)
                if (obstacleGrid[i][j])
                    tab[j] = 0;
                else
                    tab[j] += tab[j - 1];
        }
        return tab[n - 1];
    }
};

int main() {

    return 0;
}


<<<<<<< HEAD
// Paint House
#define REP(i, n) FOR(i, 0, n)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)

class Solution {
public:
  int minCost(vector<vector<int>>& costs) {
    int n = costs.size();
    if (! n) return 0;
    FOR(i, 1, n)
      REP(j, 3)
        costs[i][j] += min(costs[i-1][(j+1)%3], costs[i-1][(j+2)%3]);
    return *min_element(costs[n-1].begin(), costs[n-1].end());
  }
};
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        if(n == 0) return 0;
        int dp[n][3];

        dp[0][0] = costs[0][0];
        dp[0][1] = costs[0][1];
        dp[0][2] = costs[0][2];

        for(int i = 0; i < n - 1; i++) {
            dp[i + 1][0] = costs[i + 1][0] + min(dp[i][1], dp[i][2]);
            dp[i + 1][1] = costs[i + 1][1] + min(dp[i][0], dp[i][2]);
            dp[i + 1][2] = costs[i + 1][2] + min(dp[i][0], dp[i][1]);
        }
        
        return min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2]));
    }
=======
// Paint House
#define REP(i, n) FOR(i, 0, n)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)

class Solution {
public:
  int minCost(vector<vector<int>>& costs) {
    int n = costs.size();
    if (! n) return 0;
    FOR(i, 1, n)
      REP(j, 3)
        costs[i][j] += min(costs[i-1][(j+1)%3], costs[i-1][(j+2)%3]);
    return *min_element(costs[n-1].begin(), costs[n-1].end());
  }
};
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        if(n == 0) return 0;
        int dp[n][3];

        dp[0][0] = costs[0][0];
        dp[0][1] = costs[0][1];
        dp[0][2] = costs[0][2];

        for(int i = 0; i < n - 1; i++) {
            dp[i + 1][0] = costs[i + 1][0] + min(dp[i][1], dp[i][2]);
            dp[i + 1][1] = costs[i + 1][1] + min(dp[i][0], dp[i][2]);
            dp[i + 1][2] = costs[i + 1][2] + min(dp[i][0], dp[i][1]);
        }
        
        return min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2]));
    }
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
};
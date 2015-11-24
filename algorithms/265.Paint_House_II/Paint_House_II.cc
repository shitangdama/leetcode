/*
 * There are a row of n houses, each house can be painted with one of the k colors.
 * The cost of painting each house with a certain color is different. 
 * You have to paint all the houses such that no two adjacent houses have the same color.
 */
class Solution {
  public:
    int minCostII(vector<vector<int>>& costs) {
      int n = costs.size();
      if(!n) return 0;
      int k = costs[0].size();
      vector<vector<int>> dp(n, vector<int>(k, 0));
      for(int i = 0; i < n; i++){
	for(int j = 0; j < k; j++) {
	  if(i == 0) {
	    dp[i][j] = costs[i][j];
	    continue;
	  }
	  int temp = INT_MAX;
	  for(int l = 0; l < k; l++){
	    if(l != j) temp = min(temp, dp[i - 1][l]);
	  }
	  dp[i][j] = temp + costs[i][j];
	}
      }
      int result = INT_MAX;
      for(int i = 0; i < k; i++){
	result = min(result, dp[n - 1][i]);
      }
      return result;
    }
};

// Paint House II
class Solution {
public:
    // res[i][j] = (res[i-1][j] == min ? 2ndmin(res[i-1][j]) : min(res[i-1][j])) + costs[i][j];
    // track minIndex, minVal, minVal2
    int minCostII(vector<vector<int>>& costs) {
        if(costs.empty()) return 0;
        int minIndex = -1, minVal = 0, minVal2 = 0;
        const int n = costs.size();
        const int k = costs[0].size();
        for(int i = 0; i < n; i++){
            int temp, tempVal = INT_MAX, tempVal2 = INT_MAX;
            for(int j = 0; j < k; j++){
                if(j == minIndex) costs[i][j] += minVal2;
                else costs[i][j] += minVal;
                if(costs[i][j] < tempVal){
                    tempVal2 = tempVal;
                    tempVal = costs[i][j];
                    temp = j;
                }
                else if(costs[i][j] < tempVal2)
                    tempVal2 = costs[i][j];
            }
            minIndex = temp;
            minVal = tempVal;
            minVal2 = tempVal2;
        }
        return minVal;
    }
};
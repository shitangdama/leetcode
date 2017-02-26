<<<<<<< HEAD
public class Solution {
    /**
     * @param matrix: a matrix of 0 and 1
     * @return: an integer
     */
    public int maxSquare(int[][] matrix) {
        // write your code here
        int ans = 0;
        int n = matrix.length;
        int m;
        if(n > 0)
            m = matrix[0].length;
        else 
            return ans;
        int [][]res = new int [n][m];
        for(int i = 0; i < n; i++){
            res[i][0] = matrix[i][0];
            ans = Math.max(res[i][0] , ans);
            for(int j = 1; j < m; j++) {
                if(i > 0) {
                    if(matrix[i][j] > 0) {
                        res[i][j] = Math.min(res[i - 1][j],Math.min(res[i][j-1], res[i-1][j-1])) + 1;
                    } else {
                        res[i][j] = 0;
                    }
                    
                }
                else {
                    res[i][j] = matrix[i][j];
                }
                ans = Math.max(res[i][j], ans);
            }
        }
        return ans*ans;
    }
    
    public int maxSquare(int[][] matrix) {
        // write your code here
        int ans = 0;
        int n = matrix.length;
        int m;
        if(n > 0)
            m = matrix[0].length;
        else 
            return ans;
        int [][]res = new int [2][m];
        for(int i = 0; i < n; i++){
            res[i%2][0] = matrix[i][0];
            ans = Math.max(res[i%2][0] , ans);
            for(int j = 1; j < m; j++) {
                if(i > 0) {
                    if(matrix[i][j] > 0) {
                        res[i%2][j] = Math.min(res[(i - 1)%2][j],Math.min(res[i%2][j-1], res[(i-1)%2][j-1])) + 1;
                    } else {
                        res[i%2][j] = 0;
                    }
                    
                }
                else {
                    res[i%2][j] = matrix[i%2][j];
                }
                ans = Math.max(res[i%2][j], ans);
            }
        }
        return ans*ans;
    }
}
public class Solution {
  public int maximalSquare(char[][] matrix) {
    if (matrix == null || matrix.length == 0 || matrix[0].length == 0) {
      return 0;
    }

    int[][] dp = new int[matrix.length][matrix[0].length];
    int max = 0;
    for (int i = 0; i < matrix.length; i++) {
      if (matrix[i][0] == '1') {
        dp[i][0] = 1;
        max = 1;
      }
    }

    for (int j = 0; j < matrix[0].length; j++) {
      if (matrix[0][j] == '1') {
        dp[0][j] = 1;
        max = 1;
      }
    }

    for (int i = 1; i < matrix.length; i++) {
      for (int j = 1; j < matrix[0].length; j++) {
        if (matrix[i][j] == '1') {
          dp[i][j] = 1 + Math.min(
              dp[i - 1][j - 1], Math.min(dp[i - 1][j], dp[i][j - 1])
          );
          max = Math.max(max, dp[i][j]);
        }
      }
    }

    return max * max;
  }
=======
public class Solution {
    /**
     * @param matrix: a matrix of 0 and 1
     * @return: an integer
     */
    public int maxSquare(int[][] matrix) {
        // write your code here
        int ans = 0;
        int n = matrix.length;
        int m;
        if(n > 0)
            m = matrix[0].length;
        else 
            return ans;
        int [][]res = new int [n][m];
        for(int i = 0; i < n; i++){
            res[i][0] = matrix[i][0];
            ans = Math.max(res[i][0] , ans);
            for(int j = 1; j < m; j++) {
                if(i > 0) {
                    if(matrix[i][j] > 0) {
                        res[i][j] = Math.min(res[i - 1][j],Math.min(res[i][j-1], res[i-1][j-1])) + 1;
                    } else {
                        res[i][j] = 0;
                    }
                    
                }
                else {
                    res[i][j] = matrix[i][j];
                }
                ans = Math.max(res[i][j], ans);
            }
        }
        return ans*ans;
    }
    
    public int maxSquare(int[][] matrix) {
        // write your code here
        int ans = 0;
        int n = matrix.length;
        int m;
        if(n > 0)
            m = matrix[0].length;
        else 
            return ans;
        int [][]res = new int [2][m];
        for(int i = 0; i < n; i++){
            res[i%2][0] = matrix[i][0];
            ans = Math.max(res[i%2][0] , ans);
            for(int j = 1; j < m; j++) {
                if(i > 0) {
                    if(matrix[i][j] > 0) {
                        res[i%2][j] = Math.min(res[(i - 1)%2][j],Math.min(res[i%2][j-1], res[(i-1)%2][j-1])) + 1;
                    } else {
                        res[i%2][j] = 0;
                    }
                    
                }
                else {
                    res[i%2][j] = matrix[i%2][j];
                }
                ans = Math.max(res[i%2][j], ans);
            }
        }
        return ans*ans;
    }
}
public class Solution {
  public int maximalSquare(char[][] matrix) {
    if (matrix == null || matrix.length == 0 || matrix[0].length == 0) {
      return 0;
    }

    int[][] dp = new int[matrix.length][matrix[0].length];
    int max = 0;
    for (int i = 0; i < matrix.length; i++) {
      if (matrix[i][0] == '1') {
        dp[i][0] = 1;
        max = 1;
      }
    }

    for (int j = 0; j < matrix[0].length; j++) {
      if (matrix[0][j] == '1') {
        dp[0][j] = 1;
        max = 1;
      }
    }

    for (int i = 1; i < matrix.length; i++) {
      for (int j = 1; j < matrix[0].length; j++) {
        if (matrix[i][j] == '1') {
          dp[i][j] = 1 + Math.min(
              dp[i - 1][j - 1], Math.min(dp[i - 1][j], dp[i][j - 1])
          );
          max = Math.max(max, dp[i][j]);
        }
      }
    }

    return max * max;
  }
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
}
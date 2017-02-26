public class Solution {
    public int numTrees(int n) {
        int dp[] = new int[n+1];
        dp[0] = dp[1] = 1;
        for(int i=2; i<=n; i++){
            for(int k=1; k<=i; k++){
                dp[i] += dp[k-1] * dp[i-k];
            }
        }
        return dp[n];
    }
}
public class Solution {
/*
The case for 3 elements example
Count[3] = Count[0]*Count[2]  (1 as root)
              + Count[1]*Count[1]  (2 as root)
              + Count[2]*Count[0]  (3 as root)

Therefore, we can get the equation:
Count[i] = ¡Æ Count[0...k] * [ k+1....i]     0<=k<i-1  

*/
    public int numTrees(int n) {
        int[] count = new int[n+2];
        count[0] = 1;
        count[1] = 1;
        
        for(int i=2;  i<= n; i++){
            for(int j=0; j<i; j++){
                count[i] += count[j] * count[i - j - 1];
            }
        }
        return count[n];
    }
}
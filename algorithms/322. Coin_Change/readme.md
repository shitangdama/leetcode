# 硬币问题
dp[i][j]的含义是：在可以任意使用arr[0..i]货币的情况下，组成j所需要的最小张数。

对于剩下的任意dp[i][j]，我们依次从左到右，从上到下计算，dp[i][j]的值可能来自下面：
完全不使用当前货币arr[i]的情况下的最少张数，即dp[i-1][j]的值
只使用1张当前货币arr[i]的情况下的最少张数，即dp[i-1][j-arr[i]]+1
只使用2张当前货币arr[i]的情况下的最少张数，即dp[i-1][j-2*arr[i]]+2
只使用3张当前货币arr[i]的情况下的最少张数，即dp[i-1][j-3*arr[i]]+3

以上所有情况中，最终取张数最小的，即dp[i][j] = min( dp[i-1][j-k*arr[i]]+k )( k>=0 )

=>dp[i][j] = min{ dp[i-1][j], min{ dp[i-1][j-x*arr[i]]+x (1<=x) } }    
令x = y+1 至少有一张arr[i]
=>dp[i][j] = min{ dp[i-1][j], min{ dp[i-1][j-arr[i]-y*arr[i]+y+1 (0<=y) ] } } 

又有 min{ dp[i-1][j-arr[i]-y*arr[i]+y (0<=y) ] } => dp[i][ j-arr[i] ] 
所以，最终有：dp[i][j] = min{ dp[i-1][j], dp[i][j-arr[i]]+1 }。如果j-arr[i] < 0，即发生了越界，说明arr[i]太大了，用一张都会超过钱数j，此时dp[i][j] = dp[i-1][j]。
#完全背包问题

dp[i] = min(dp[i - coin] + 1)
这里最后总结是
dp[i][j] = min{ dp[i-1][j], dp[i][j-arr[i]]+1 }
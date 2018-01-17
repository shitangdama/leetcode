dp思想
主要是状态转移方程
上一时刻的状态和下一时刻的状态
<!-- # maxSubArray(A, i) = maxSubArray(A, i - 1) > 0 ? maxSubArray(A, i - 1) : 0 + A[i]; 
# 第i位的状态是
# 前i-1未状态大于0，或者，只有i状态 -->
关于背包问题
记录背包问题九讲
#普通背包

给定n种物品和一个容量为C的背包，物品i的重量是wi，其价值为vi

关于状态表
列是当可选物品，同时i代表这这一状态准备网里面放入，横向代表背包容量
物品需要一个一个网里面加。
关于m[i][j]表示在面对第i件物品，且背包容量为j时所能获得的最大价值，
分析收益
-1 
    j<w[i] 这时候背包容量不足以放下第i件物品，只能选择不拿
    m[i][j] = m[i-1][j]
    当前状态价值等于前一状态价值
-2 
    j>=w[i] 的情况，这时候先去减去第i件商品的体积，在求在没有第i件物品时候，在背包体积为j-v[i]时候的最大值。
    m[i][j]=m[i-1][j-w[i]]+v[i]
    是一种倒推的思路，在满足当前状态情况下，减去当前这件物品，之前状态的最优

if(j>=w[i])  
    m[i][j]=max(m[i-1][j],m[i-1][j-w[i]]+v[i]);  
else  
    m[i][j]=m[i-1][j];  

#完全背包
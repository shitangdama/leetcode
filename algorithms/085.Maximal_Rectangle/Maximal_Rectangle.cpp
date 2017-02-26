<<<<<<< HEAD
class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        int row = matrix.size();
        if(row == 0)return 0;
        int column = matrix[0].size();
        int dp[row][column], res = 0;
        memset(dp, 0, sizeof(dp));
        //求出所有的dp值
        for(int i = 0; i < row; i++)
            dp[i][column-1] = (matrix[i][column-1] == '1');
        for(int i = 0; i < row; i++)
            for(int j = column - 2; j >= 0; j--)
                if(matrix[i][j] == '1')
                    dp[i][j] = 1 + dp[i][j + 1];
        //以每个点作为矩形的左上角计算所得的最大矩形面积
        for(int i = 0; i < row; i++)
        {
             
            for(int j = 0; j < column; j++)
            {
                //剪枝，column-j是最大宽度，row-i是最大高度
                if((column - j) * (row - i) <= res)break;
                int width = dp[i][j];
                for(int k = i; k < row && width > 0; k++)
                {
                    //剪枝,row-i是以点(i,j)为左上角的矩形的最大高度
                    if(width * (row - i) <= res)break;
                    //计算以(i.j)为左上角，上下边缘是第i行和第k行的矩形面积
                    if(width > dp[k][j])width = dp[k][j];//矩形宽度要取从第i行到第k行宽度的最小值
                    res = max(res, width * (k - i + 1));
                }
            }
        }
        return res;
    }
=======
class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        int row = matrix.size();
        if(row == 0)return 0;
        int column = matrix[0].size();
        int dp[row][column], res = 0;
        memset(dp, 0, sizeof(dp));
        //求出所有的dp值
        for(int i = 0; i < row; i++)
            dp[i][column-1] = (matrix[i][column-1] == '1');
        for(int i = 0; i < row; i++)
            for(int j = column - 2; j >= 0; j--)
                if(matrix[i][j] == '1')
                    dp[i][j] = 1 + dp[i][j + 1];
        //以每个点作为矩形的左上角计算所得的最大矩形面积
        for(int i = 0; i < row; i++)
        {
             
            for(int j = 0; j < column; j++)
            {
                //剪枝，column-j是最大宽度，row-i是最大高度
                if((column - j) * (row - i) <= res)break;
                int width = dp[i][j];
                for(int k = i; k < row && width > 0; k++)
                {
                    //剪枝,row-i是以点(i,j)为左上角的矩形的最大高度
                    if(width * (row - i) <= res)break;
                    //计算以(i.j)为左上角，上下边缘是第i行和第k行的矩形面积
                    if(width > dp[k][j])width = dp[k][j];//矩形宽度要取从第i行到第k行宽度的最小值
                    res = max(res, width * (k - i + 1));
                }
            }
        }
        return res;
    }
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
};
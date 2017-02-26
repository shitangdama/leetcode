<<<<<<< HEAD
class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        int row = matrix.size();
        if(row == 0)return 0;
        int column = matrix[0].size();
        int dp[row][column], res = 0;
        memset(dp, 0, sizeof(dp));
        //������е�dpֵ
        for(int i = 0; i < row; i++)
            dp[i][column-1] = (matrix[i][column-1] == '1');
        for(int i = 0; i < row; i++)
            for(int j = column - 2; j >= 0; j--)
                if(matrix[i][j] == '1')
                    dp[i][j] = 1 + dp[i][j + 1];
        //��ÿ������Ϊ���ε����ϽǼ������õ����������
        for(int i = 0; i < row; i++)
        {
             
            for(int j = 0; j < column; j++)
            {
                //��֦��column-j������ȣ�row-i�����߶�
                if((column - j) * (row - i) <= res)break;
                int width = dp[i][j];
                for(int k = i; k < row && width > 0; k++)
                {
                    //��֦,row-i���Ե�(i,j)Ϊ���Ͻǵľ��ε����߶�
                    if(width * (row - i) <= res)break;
                    //������(i.j)Ϊ���Ͻǣ����±�Ե�ǵ�i�к͵�k�еľ������
                    if(width > dp[k][j])width = dp[k][j];//���ο��Ҫȡ�ӵ�i�е���k�п�ȵ���Сֵ
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
        //������е�dpֵ
        for(int i = 0; i < row; i++)
            dp[i][column-1] = (matrix[i][column-1] == '1');
        for(int i = 0; i < row; i++)
            for(int j = column - 2; j >= 0; j--)
                if(matrix[i][j] == '1')
                    dp[i][j] = 1 + dp[i][j + 1];
        //��ÿ������Ϊ���ε����ϽǼ������õ����������
        for(int i = 0; i < row; i++)
        {
             
            for(int j = 0; j < column; j++)
            {
                //��֦��column-j������ȣ�row-i�����߶�
                if((column - j) * (row - i) <= res)break;
                int width = dp[i][j];
                for(int k = i; k < row && width > 0; k++)
                {
                    //��֦,row-i���Ե�(i,j)Ϊ���Ͻǵľ��ε����߶�
                    if(width * (row - i) <= res)break;
                    //������(i.j)Ϊ���Ͻǣ����±�Ե�ǵ�i�к͵�k�еľ������
                    if(width > dp[k][j])width = dp[k][j];//���ο��Ҫȡ�ӵ�i�е���k�п�ȵ���Сֵ
                    res = max(res, width * (k - i + 1));
                }
            }
        }
        return res;
    }
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
};
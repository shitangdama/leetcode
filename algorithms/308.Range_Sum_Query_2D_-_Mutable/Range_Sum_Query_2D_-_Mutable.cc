<<<<<<< HEAD
class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) {
        if(matrix.size() == 0)
            return ;
        mtx.resize(matrix.size() + 1);
        sumMtx.resize(matrix.size() + 1);
        for(int i = 0; i <= matrix.size(); ++ i){
            vector<int> tmp(matrix[0].size() + 1), sumTmp(matrix[0].size() + 1);
            mtx[i] = tmp;
            sumMtx[i] = sumTmp;
        }
        for(int i = 0; i < matrix.size(); ++ i){
            for(int j = 0; j < matrix[0].size(); ++ j){
                mtx[i][j] = matrix[i][j];
                add(i + 1, j + 1, matrix.size(), matrix[0].size(), mtx[i][j]);
            }
        }
    }

    void update(int row, int col, int val) {
        if(mtx.size() == 0)
            return ;
        if(mtx[row][col] == val)
            return ;
        int delta = val - mtx[row][col];
        add(row + 1, col + 1, mtx.size() - 1, mtx[0].size(), delta);
        mtx[row][col] = val;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if(mtx.size() == 0)
            return 0;
        if(!row1 && !col1)
            return sum(row2, col2, mtx[0].size());
        else if(!row1)
            return sum(row2, col2, mtx[0].size()) - sum(row2, col1 - 1, mtx[0].size());
        else if(!col1)
            return sum(row2, col2, mtx[0].size()) - sum(row1 - 1, col2, mtx[0].size());
        else
            return sum(row2, col2, mtx[0].size()) - sum(row2, col1 - 1, mtx[0].size()) - sum(row1 - 1, col2, mtx[0].size()) + sum(row1 - 1, col1 - 1, mtx[0].size());
    }
private:
    void add(int startRow, int startCol, int endRow, int endCol, int val){
        for(int i = startRow; i <= endRow; i += lowbit(i)){
            sumMtx[i][startCol] += val;
        }
    /*    for(int i = startCol; i <= endCol; i += lowbit(i)){
            sum[endRow][i] += val;
        } */
    }

    int sum(int endRow, int endCol, int n){
        int res = 0;
        vector<int> tmpsum(n + 1);
        ++ endCol;
        ++ endRow;
        for(int i = 1; i <= endCol; ++ i){
            int val = 0;
            for(int j = endRow; j > 0; j -= lowbit(j)){
                val += sumMtx[j][i];
            }
            for(int j = i; j <= n; j += lowbit(j))
                tmpsum[j] += val;
        }
        for(int i = endCol; i > 0; i -= lowbit(i)){
            res += tmpsum[i];
        }
        return res;
    }

    int lowbit(int x){
        return x&-x;
    }
private:
vector<vector<int>> mtx;
vector<vector<int>> sumMtx;
=======
class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) {
        if(matrix.size() == 0)
            return ;
        mtx.resize(matrix.size() + 1);
        sumMtx.resize(matrix.size() + 1);
        for(int i = 0; i <= matrix.size(); ++ i){
            vector<int> tmp(matrix[0].size() + 1), sumTmp(matrix[0].size() + 1);
            mtx[i] = tmp;
            sumMtx[i] = sumTmp;
        }
        for(int i = 0; i < matrix.size(); ++ i){
            for(int j = 0; j < matrix[0].size(); ++ j){
                mtx[i][j] = matrix[i][j];
                add(i + 1, j + 1, matrix.size(), matrix[0].size(), mtx[i][j]);
            }
        }
    }

    void update(int row, int col, int val) {
        if(mtx.size() == 0)
            return ;
        if(mtx[row][col] == val)
            return ;
        int delta = val - mtx[row][col];
        add(row + 1, col + 1, mtx.size() - 1, mtx[0].size(), delta);
        mtx[row][col] = val;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if(mtx.size() == 0)
            return 0;
        if(!row1 && !col1)
            return sum(row2, col2, mtx[0].size());
        else if(!row1)
            return sum(row2, col2, mtx[0].size()) - sum(row2, col1 - 1, mtx[0].size());
        else if(!col1)
            return sum(row2, col2, mtx[0].size()) - sum(row1 - 1, col2, mtx[0].size());
        else
            return sum(row2, col2, mtx[0].size()) - sum(row2, col1 - 1, mtx[0].size()) - sum(row1 - 1, col2, mtx[0].size()) + sum(row1 - 1, col1 - 1, mtx[0].size());
    }
private:
    void add(int startRow, int startCol, int endRow, int endCol, int val){
        for(int i = startRow; i <= endRow; i += lowbit(i)){
            sumMtx[i][startCol] += val;
        }
    /*    for(int i = startCol; i <= endCol; i += lowbit(i)){
            sum[endRow][i] += val;
        } */
    }

    int sum(int endRow, int endCol, int n){
        int res = 0;
        vector<int> tmpsum(n + 1);
        ++ endCol;
        ++ endRow;
        for(int i = 1; i <= endCol; ++ i){
            int val = 0;
            for(int j = endRow; j > 0; j -= lowbit(j)){
                val += sumMtx[j][i];
            }
            for(int j = i; j <= n; j += lowbit(j))
                tmpsum[j] += val;
        }
        for(int i = endCol; i > 0; i -= lowbit(i)){
            res += tmpsum[i];
        }
        return res;
    }

    int lowbit(int x){
        return x&-x;
    }
private:
vector<vector<int>> mtx;
vector<vector<int>> sumMtx;
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
};
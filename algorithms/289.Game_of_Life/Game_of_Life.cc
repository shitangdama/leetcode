class Solution {
private:
    int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
    int dy[8] = {1, 0, -1, 1, -1, 1, 0, -1};
    
    bool inBound(int x, int y, int n, int m) {
        return (x >= 0) && (x < n) && (y >= 0) && (y < m);
    }

public:
    void gameOfLife(vector<vector<int>>& board) {
        if(board.empty() || board[0].empty()) return;
        int n = board.size();
        int m = board[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int t = 0;
                for(int k = 0; k < 8; k++) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if(inBound(x, y, n, m)) {
                        t += (board[x][y] & 1);
                    }
                }
                if(board[i][j] + t == 3 || t == 3) {
                    board[i][j] |= 2;
                }
            }
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                board[i][j] >>= 1;
            }
        }
        
        return;
    }
};
void gameOfLife(vector<vector<int>>& board) {
    int m = board.size(), n = m ? board[0].size() : 0;
    for (int i=0; i<m; ++i) {
        for (int j=0; j<n; ++j) {
            int count = 0;
            for (int I=max(i-1, 0); I<min(i+2, m); ++I)
                for (int J=max(j-1, 0); J<min(j+2, n); ++J)
                    count += board[I][J] & 1;
            if (count == 3 || count - board[i][j] == 3)
                board[i][j] |= 2;
        }
    }
    for (int i=0; i<m; ++i)
        for (int j=0; j<n; ++j)
            board[i][j] >>= 1;
}
// State transitions
//  0 : dead to dead
//  1 : live to live
//  2 : live to dead
//  3 : dead to live
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = m ? board[0].size() : 0;
        int di[8] = {-1, -1, -1,  0, 0,  1, 1, 1};
        int dj[8] = {-1,  0,  1, -1, 1, -1, 0, 1};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int live = 0;
                for (int k = 0; k < 8; k++) {
                    int ii = i + di[k], jj = j + dj[k];
                    if (ii < 0 || ii >= m || jj < 0 || jj >= n) continue;
                    if (board[ii][jj] == 1 || board[ii][jj] == 2) live++;
                }
                if (board[i][j] == 1 && (live < 2 || live > 3)) board[i][j] = 2;
                else if (!board[i][j] && live == 3) board[i][j] = 3;
            }
        }
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) 
                board[i][j] %= 2;
    }
};
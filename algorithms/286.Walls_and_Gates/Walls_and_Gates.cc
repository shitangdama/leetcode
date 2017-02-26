<<<<<<< HEAD
class Solution {
private:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    bool inBound(int x, int y, int n, int m) {
        return ((x >= 0) && (y >= 0) && (x < n) && (y < m));
    }

    void refresh(vector<vector<int>>& rooms, int row, int col) {
        int n = rooms.size();
        int m = rooms[0].size();
        queue<pair<int, int>> q;
        q.push(make_pair(row, col));
        while(!q.empty()) {
            pair<int, int> p = q.front();
            int x = p.first;
            int y = p.second;
            for(int i = 0; i < 4; i++) {
                int tx = x + dx[i];
                int ty = y + dy[i];
                if(!inBound(tx, ty, n, m)) {
                    continue;
                }
                if(rooms[tx][ty] == -1) {
                    continue;
                }
                if(rooms[x][y] + 1 < rooms[tx][ty]) {
                    rooms[tx][ty] = rooms[x][y] + 1;
                    q.push(make_pair(tx, ty));
                }
            }
            q.pop();
        }
    }

public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if(rooms.empty() || rooms[0].empty()) return;
        int n = rooms.size();
        int m = rooms[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(rooms[i][j] == 0) {
                    refresh(rooms, i, j);
                }
            }
        }
        
        return;
    }
};
// Walls and Gates
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if(rooms.empty()) return;
        const int m = rooms.size();
        const int n = rooms[0].size();
        vector<pair<int,int>> table;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(rooms[i][j] == 0) table.push_back(make_pair(i,j));
        while(!table.empty()){
            vector<pair<int,int>> temp;
            for(auto index : table){
                int i = index.first;
                int j = index.second;
                if( j + 1 < n && rooms[i][j+1] > rooms[i][j] + 1){
                    rooms[i][j+1] = rooms[i][j] + 1;
                    temp.push_back(make_pair(i,j+1));
                }
                if( j - 1 >= 0 && rooms[i][j-1] > rooms[i][j] + 1){
                    rooms[i][j-1] = rooms[i][j] + 1;
                    temp.push_back(make_pair(i,j-1));
                }
                if( i + 1 < m && rooms[i+1][j] > rooms[i][j] + 1){
                    rooms[i+1][j] = rooms[i][j] + 1;
                    temp.push_back(make_pair(i+1,j));
                }
                if( i - 1 >= 0 && rooms[i-1][j] > rooms[i][j] + 1){
                    rooms[i-1][j] = rooms[i][j] + 1;
                    temp.push_back(make_pair(i-1,j));
                }                
            }
            table = temp;
        }
    }
};
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size();
        if(!m) return;
        int n = rooms[0].size();
        if(!n) return;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(rooms[i][j] == 0) set(rooms, i, j, m, n, 1);
            }
        }
    }
private:
    void set(vector<vector<int>>& rooms, int i, int j, int m, int n, int dis){
        if(i > 0 && rooms[i - 1][j] > dis){
            rooms[i - 1][j] = dis;
            set(rooms, i - 1, j, m, n, dis + 1);
        }
        if(i < m - 1 && rooms[i + 1][j] > dis){
            rooms[i + 1][j] = dis;
            set(rooms, i + 1, j, m, n, dis + 1);
        }
        if(j > 0 && rooms[i][j - 1] > dis){
            rooms[i][j - 1] = dis;
            set(rooms, i, j - 1, m, n, dis + 1);
        }
        if(j < n - 1 && rooms[i][j + 1] > dis){
            rooms[i][j + 1] = dis;
            set(rooms, i, j + 1, m, n, dis + 1);
        }
    }
=======
class Solution {
private:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    bool inBound(int x, int y, int n, int m) {
        return ((x >= 0) && (y >= 0) && (x < n) && (y < m));
    }

    void refresh(vector<vector<int>>& rooms, int row, int col) {
        int n = rooms.size();
        int m = rooms[0].size();
        queue<pair<int, int>> q;
        q.push(make_pair(row, col));
        while(!q.empty()) {
            pair<int, int> p = q.front();
            int x = p.first;
            int y = p.second;
            for(int i = 0; i < 4; i++) {
                int tx = x + dx[i];
                int ty = y + dy[i];
                if(!inBound(tx, ty, n, m)) {
                    continue;
                }
                if(rooms[tx][ty] == -1) {
                    continue;
                }
                if(rooms[x][y] + 1 < rooms[tx][ty]) {
                    rooms[tx][ty] = rooms[x][y] + 1;
                    q.push(make_pair(tx, ty));
                }
            }
            q.pop();
        }
    }

public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if(rooms.empty() || rooms[0].empty()) return;
        int n = rooms.size();
        int m = rooms[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(rooms[i][j] == 0) {
                    refresh(rooms, i, j);
                }
            }
        }
        
        return;
    }
};
// Walls and Gates
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if(rooms.empty()) return;
        const int m = rooms.size();
        const int n = rooms[0].size();
        vector<pair<int,int>> table;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(rooms[i][j] == 0) table.push_back(make_pair(i,j));
        while(!table.empty()){
            vector<pair<int,int>> temp;
            for(auto index : table){
                int i = index.first;
                int j = index.second;
                if( j + 1 < n && rooms[i][j+1] > rooms[i][j] + 1){
                    rooms[i][j+1] = rooms[i][j] + 1;
                    temp.push_back(make_pair(i,j+1));
                }
                if( j - 1 >= 0 && rooms[i][j-1] > rooms[i][j] + 1){
                    rooms[i][j-1] = rooms[i][j] + 1;
                    temp.push_back(make_pair(i,j-1));
                }
                if( i + 1 < m && rooms[i+1][j] > rooms[i][j] + 1){
                    rooms[i+1][j] = rooms[i][j] + 1;
                    temp.push_back(make_pair(i+1,j));
                }
                if( i - 1 >= 0 && rooms[i-1][j] > rooms[i][j] + 1){
                    rooms[i-1][j] = rooms[i][j] + 1;
                    temp.push_back(make_pair(i-1,j));
                }                
            }
            table = temp;
        }
    }
};
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size();
        if(!m) return;
        int n = rooms[0].size();
        if(!n) return;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(rooms[i][j] == 0) set(rooms, i, j, m, n, 1);
            }
        }
    }
private:
    void set(vector<vector<int>>& rooms, int i, int j, int m, int n, int dis){
        if(i > 0 && rooms[i - 1][j] > dis){
            rooms[i - 1][j] = dis;
            set(rooms, i - 1, j, m, n, dis + 1);
        }
        if(i < m - 1 && rooms[i + 1][j] > dis){
            rooms[i + 1][j] = dis;
            set(rooms, i + 1, j, m, n, dis + 1);
        }
        if(j > 0 && rooms[i][j - 1] > dis){
            rooms[i][j - 1] = dis;
            set(rooms, i, j - 1, m, n, dis + 1);
        }
        if(j < n - 1 && rooms[i][j + 1] > dis){
            rooms[i][j + 1] = dis;
            set(rooms, i, j + 1, m, n, dis + 1);
        }
    }
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
};
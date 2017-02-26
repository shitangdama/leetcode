<<<<<<< HEAD
class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<vector<int>> grid(m, vector<int>(n));
        map<int, set<pair<int,int>>> islands;
        int islandID = 0;
        vector<int> result;
        for(auto && land : positions) {
            if(grid[land.first][land.second] != 0) continue;
            ++islandID;
            islands[islandID] = set<pair<int,int>>({land});
            vector<int> toBeComBined;
            if(land.first > 0 && grid[land.first -1][land.second])
                toBeComBined.push_back(grid[land.first -1][land.second]);
            if(land.second > 0 && grid[land.first][land.second - 1])
                toBeComBined.push_back(grid[land.first][land.second - 1]);
            if(land.first < m - 1 && grid[land.first + 1][land.second])
                toBeComBined.push_back(grid[land.first+1][land.second]);
            if(land.second < n - 1 && grid[land.first][land.second + 1])
                toBeComBined.push_back(grid[land.first][land.second + 1]);
            for(int i = 0; i < toBeComBined.size(); i++){
                islands[islandID].insert(islands[toBeComBined[i]].begin(), islands[toBeComBined[i]].end());
                islands.erase(toBeComBined[i]);
            }
            for(auto &&cordinate : islands[islandID]){
                grid[cordinate.first][cordinate.second] = islandID;
            }
            result.push_back((int)islands.size());
        }
        return result;
    }
};
=======
class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<vector<int>> grid(m, vector<int>(n));
        map<int, set<pair<int,int>>> islands;
        int islandID = 0;
        vector<int> result;
        for(auto && land : positions) {
            if(grid[land.first][land.second] != 0) continue;
            ++islandID;
            islands[islandID] = set<pair<int,int>>({land});
            vector<int> toBeComBined;
            if(land.first > 0 && grid[land.first -1][land.second])
                toBeComBined.push_back(grid[land.first -1][land.second]);
            if(land.second > 0 && grid[land.first][land.second - 1])
                toBeComBined.push_back(grid[land.first][land.second - 1]);
            if(land.first < m - 1 && grid[land.first + 1][land.second])
                toBeComBined.push_back(grid[land.first+1][land.second]);
            if(land.second < n - 1 && grid[land.first][land.second + 1])
                toBeComBined.push_back(grid[land.first][land.second + 1]);
            for(int i = 0; i < toBeComBined.size(); i++){
                islands[islandID].insert(islands[toBeComBined[i]].begin(), islands[toBeComBined[i]].end());
                islands.erase(toBeComBined[i]);
            }
            for(auto &&cordinate : islands[islandID]){
                grid[cordinate.first][cordinate.second] = islandID;
            }
            result.push_back((int)islands.size());
        }
        return result;
    }
};
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74

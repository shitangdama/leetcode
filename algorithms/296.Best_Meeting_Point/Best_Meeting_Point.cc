
class Solution {
public:
	int minTotalDistance(vector<vector<int>>& grid) {
    vector<int> row;
    vector<int> col;

    for(int i = 0; i<grid.size(); i++) {
        for(int j = 0; j<grid[i].size(); j++) {
            if(grid[i][j] == 1) {
                row.push_back(i);
                col.push_back(j);
            }
        }
    }

    sort(row.begin(), row.end());
    sort(col.begin(), col.end());

    int mid_row = row.size()%2? row[row.size()/2]: (row[row.size()/2 - 1] + row[row.size()/2]) / 2;
    int mid_col = col.size()%2? col[col.size()/2]: (col[col.size()/2 - 1] + col[col.size()/2]) / 2;

    int dist = 0;
    for(int i = 0; i<row.size(); i++) 
        dist += abs(mid_row - row[i]);
    for(int i = 0; i<col.size(); i++) 
        dist += abs(mid_col - col[i]);

    return dist;
}
};

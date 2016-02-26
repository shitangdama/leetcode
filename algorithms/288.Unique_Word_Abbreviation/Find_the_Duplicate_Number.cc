// Time Complexity: O(m * n)
// Space Complexity: O(m + n)

class Solution {
    public:
        int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
            const int m = obstacleGrid.size();
            const int n = obstacleGrid[0].size();
            vector<int> v(n, 0);

            v[0] = 1;
            for(int i = 0; i < m; ++i) {
                if(obstacleGrid[i][0] != 0)
                    v[0] = 0;
                for(int j = 1; j < n; ++j) {
                    if(obstacleGrid[i][j] == 0)
                        v[j] += v[j - 1];
                    else
                        v[j] = 0;
                }
            }

            return v[n - 1];
        }
};
// Unique Word Abbreviation
class ValidWordAbbr {
  string f(const string &w) const {
    return w.size() <= 2 ? w : w[0]+to_string(w.size()-2)+w.back();
  }
  map<string, string> m;
public:
  ValidWordAbbr(vector<string> &dictionary) {
    for (auto word: dictionary) {
      string w = f(word);
      m[w] = m.count(w) ? "" : word;
    }
  }

  bool isUnique(string word) {
    string w = f(word);
    return ! m.count(w) || m[w] == word;
  }
};
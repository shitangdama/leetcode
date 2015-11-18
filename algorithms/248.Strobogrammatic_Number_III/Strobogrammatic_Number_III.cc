class Solution {
public:
    int shortest(vector<string> &words, string word) {
        int pre = -1, res = INT_MAX;
        int n = words.size();
        for (int i = 0; i < n; ++i) {
            if (words[i] == word) {
                if (pre != -1) res = min(res, i - pre);
                pre = i;
            }
        }
        return res;
    }
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        if (word1 == word2) return shortest(words, word1);
        int idx1 = -1, idx2 = -1, res = INT_MAX;
        int n = words.size();
        for (int i = 0; i < n; ++i) {
            if (words[i] == word1) {
                idx1 = i;
                if (idx2 != -1) res = min(res, idx1 - idx2);
            } else if (words[i] == word2) {
                idx2 = i;
                if (idx1 != -1) res = min(res, idx2 - idx1);
            }
        }
        return res;
    }
};
// Shortest Word Distance III
class Solution {
public:
  int shortestWordDistance(vector<string>& words, string word1, string word2) {
    bool f = word1 == word2;
    int n = words.size(), p = -n, q = -n, r = n;
    for (int i = 0; i < n; i++)
      if (words[i] == word1) {
        r = min(r, f ? i-p : i-q);
        p = i;
      } else if (words[i] == word2)
        q = i, r = min(r, q-p);
    return r;
  }
};
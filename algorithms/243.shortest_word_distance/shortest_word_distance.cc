<<<<<<< HEAD
class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int idx1 = -1, idx2 = -1, res = words.size();
        for (int i = 0; i < words.size(); ++i) {
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
// Shortest Word Distance
class Solution {
public:
  int shortestDistance(vector<string>& words, string word1, string word2) {
    int n = words.size(), p = -n, q = -n, r = n;
    for (int i = 0; i < n; i++)
      if (words[i] == word1)
        p = i, r = min(r, p-q);
      else if (words[i] == word2)
        q = i, r = min(r, q-p);
    return r;
  }
=======
class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int idx1 = -1, idx2 = -1, res = words.size();
        for (int i = 0; i < words.size(); ++i) {
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
// Shortest Word Distance
class Solution {
public:
  int shortestDistance(vector<string>& words, string word1, string word2) {
    int n = words.size(), p = -n, q = -n, r = n;
    for (int i = 0; i < n; i++)
      if (words[i] == word1)
        p = i, r = min(r, p-q);
      else if (words[i] == word2)
        q = i, r = min(r, q-p);
    return r;
  }
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
};
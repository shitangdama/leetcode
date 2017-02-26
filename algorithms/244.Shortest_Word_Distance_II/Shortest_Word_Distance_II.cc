<<<<<<< HEAD
class WordDistance {
private:
    unordered_map<string, vector<int>> wordidx;
public:
    WordDistance(vector<string>& words) {
        int n = words.size();
        for (int i = 0; i < n; ++i) wordidx[words[i]].push_back(i);
    }

    int shortest(string word1, string word2) {
        vector<int> &idx1 = wordidx[word1];
        vector<int> &idx2 = wordidx[word2];
        int m = idx1.size(), n = idx2.size();
        int res = INT_MAX, i = 0, j = 0;
        while (i < m && j < n) {
            res = min(res, abs(idx1[i] - idx2[j]));
            if (idx1[i] > idx2[j]) ++j;
            else ++i;
        }
        return res;
    }
};


// Your WordDistance object will be instantiated and called as such:
// WordDistance wordDistance(words);
// wordDistance.shortest("word1", "word2");
// wordDistance.shortest("anotherWord1", "anotherWord2");
// Shortest Word Distance II
class WordDistance {
  map<string, vector<int>> a;
public:
  WordDistance(vector<string>& words) {
    for (int i = 0; i < words.size(); i++)
      a[words[i]].push_back(i);
  }

  int shortest(string word1, string word2) {
    vector<int> &b = a[word1], &c = a[word2];
    auto i = b.begin(), j = c.begin();
    int r = INT_MAX;
    while (i != b.end() && j != c.end()) {
      r = min(r, abs(*i-*j));
      if (*i < *j)
        i++;
      else
        j++;
    }
    return r;
  }
=======
class WordDistance {
private:
    unordered_map<string, vector<int>> wordidx;
public:
    WordDistance(vector<string>& words) {
        int n = words.size();
        for (int i = 0; i < n; ++i) wordidx[words[i]].push_back(i);
    }

    int shortest(string word1, string word2) {
        vector<int> &idx1 = wordidx[word1];
        vector<int> &idx2 = wordidx[word2];
        int m = idx1.size(), n = idx2.size();
        int res = INT_MAX, i = 0, j = 0;
        while (i < m && j < n) {
            res = min(res, abs(idx1[i] - idx2[j]));
            if (idx1[i] > idx2[j]) ++j;
            else ++i;
        }
        return res;
    }
};


// Your WordDistance object will be instantiated and called as such:
// WordDistance wordDistance(words);
// wordDistance.shortest("word1", "word2");
// wordDistance.shortest("anotherWord1", "anotherWord2");
// Shortest Word Distance II
class WordDistance {
  map<string, vector<int>> a;
public:
  WordDistance(vector<string>& words) {
    for (int i = 0; i < words.size(); i++)
      a[words[i]].push_back(i);
  }

  int shortest(string word1, string word2) {
    vector<int> &b = a[word1], &c = a[word2];
    auto i = b.begin(), j = c.begin();
    int r = INT_MAX;
    while (i != b.end() && j != c.end()) {
      r = min(r, abs(*i-*j));
      if (*i < *j)
        i++;
      else
        j++;
    }
    return r;
  }
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
};
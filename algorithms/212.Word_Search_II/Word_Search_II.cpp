class TrieNode {
 public:
  vector<TrieNode*> next;
  bool isLeaf;
  TrieNode() {
    isLeaf = false;
    next.resize(26, NULL);
  }
};

class Trie {
 public:
  Trie() { root = new TrieNode(); }

  void insert(string word) {
    TrieNode *it = root;
    for(auto & ch : word) {
      if(it->next[ch-'a'] == NULL) { it->next[ch-'a'] = new TrieNode(); }
      it = it->next[ch-'a'];
    }
    it->isLeaf = true;
  }

  TrieNode *getRoot() { return root; }

 public:
  TrieNode *root;
};

class Solution {

 public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    for(auto & word : words) trie.insert(word);
    TrieNode *root = trie.getRoot();
    vector<string> result; if(board.size() == 0) return result;
    string tmp;
    unordered_set<string> resultSet;
    for(int i = 0; i < board.size(); ++i) {
      for(int j = 0; j < board[0].size(); ++j) {
        bt(board, root, i, j, tmp, resultSet);
      }
    }
    for(auto & word : resultSet) result.push_back(word);
    return result;
  }

  void bt(vector<vector<char>>& board, TrieNode *root, int x, int y, string tmp, unordered_set<string> & S) {
    int m = board.size(), n = board[0].size();
    if(x < 0 || x >= m || y < 0 || y >= n || board[x][y] == '*') return;
    char ch = board[x][y];
    if(root->next[ch-'a'] != NULL) {
      root = root->next[ch-'a'];
      if(root->isLeaf) {
        S.insert(tmp + ch);
        //root->isLeaf = false;
      }
      board[x][y] = '*';
      bt(board, root, x + 1, y, tmp + ch, S);
      bt(board, root, x - 1, y, tmp + ch, S);
      bt(board, root, x, y + 1, tmp + ch, S);
      bt(board, root, x, y - 1, tmp + ch, S);
      board[x][y] = ch;
    }
  }

 private:
  Trie trie;
};
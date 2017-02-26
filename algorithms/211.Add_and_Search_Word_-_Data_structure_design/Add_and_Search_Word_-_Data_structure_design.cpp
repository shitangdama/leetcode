<<<<<<< HEAD
class TrieNode {

 public:
  // Initialize your data structure here.
  TrieNode() :val(0) { next.resize(26, NULL); }
  TrieNode(int v) : val(v) { next.resize(26, NULL); }
  vector<TrieNode*> next;
  int val;
};

class WordDictionary {
 public:
  WordDictionary() {
    root = new TrieNode();
  }

  // Adds a word into the data structure.
  void addWord(string word) {
    TrieNode *it = root;
    for(auto & ch : word) {
      if(it->next[ch-'a'] == NULL) {
        it->next[ch-'a'] = new TrieNode();
      }
      it = it->next[ch-'a'];
    }
    it->val = 1;
  }

  // Returns if the word is in the data structure. A word could
  // contain the dot character '.' to represent any one letter.
  bool search(string word) {
    return query(word, root);
  }

 private:
  TrieNode *root = NULL;

 private:
  bool query(string word, TrieNode *x) {
    TrieNode *it = x;
    for(int i = 0; i < word.size(); ++i) {
      if(it != NULL && word[i] != '.') {
        it = it->next[word[i]-'a'];
      } else if(it != NULL && word[i] == '.') {
        for(char ch = 'a'; ch <= 'z'; ++ch) {
          TrieNode *tmp = it->next[ch-'a'];
          if(query(word.substr(i + 1, word.size() - i - 1), tmp)) {
            return true;
          }
        }
        return false;
      } else {
        break;
      }
    }
    return it && (it->val == 1);
  }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
=======
class TrieNode {

 public:
  // Initialize your data structure here.
  TrieNode() :val(0) { next.resize(26, NULL); }
  TrieNode(int v) : val(v) { next.resize(26, NULL); }
  vector<TrieNode*> next;
  int val;
};

class WordDictionary {
 public:
  WordDictionary() {
    root = new TrieNode();
  }

  // Adds a word into the data structure.
  void addWord(string word) {
    TrieNode *it = root;
    for(auto & ch : word) {
      if(it->next[ch-'a'] == NULL) {
        it->next[ch-'a'] = new TrieNode();
      }
      it = it->next[ch-'a'];
    }
    it->val = 1;
  }

  // Returns if the word is in the data structure. A word could
  // contain the dot character '.' to represent any one letter.
  bool search(string word) {
    return query(word, root);
  }

 private:
  TrieNode *root = NULL;

 private:
  bool query(string word, TrieNode *x) {
    TrieNode *it = x;
    for(int i = 0; i < word.size(); ++i) {
      if(it != NULL && word[i] != '.') {
        it = it->next[word[i]-'a'];
      } else if(it != NULL && word[i] == '.') {
        for(char ch = 'a'; ch <= 'z'; ++ch) {
          TrieNode *tmp = it->next[ch-'a'];
          if(query(word.substr(i + 1, word.size() - i - 1), tmp)) {
            return true;
          }
        }
        return false;
      } else {
        break;
      }
    }
    return it && (it->val == 1);
  }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
// wordDictionary.search("pattern");
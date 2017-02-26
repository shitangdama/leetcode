<<<<<<< HEAD
class TrieNode {

 public:
  // Initialize your data structure here.
  TrieNode() :val(0) { next.resize(26, NULL); }
  TrieNode(int v) : val(v) { next.resize(26, NULL); }
  vector<TrieNode*> next;
  int val;
};

class Trie {
 public:
  Trie() { root = new TrieNode(); }
  
  // Inserts a word into the trie.
  void insert(string word) { root = put(root, word, 1, 0); }

  // Returns if the word is in the trie.
  bool search(string word) {
    TrieNode *x = get(root, word, 0);
    if(x == NULL) return false;
    if(x->val != 1) return false;
    return true;
  }

  // Returns if there is any word in the trie
  // that starts with the given prefix.
  bool startsWith(string prefix) {
    TrieNode *x = get(root, prefix, 0);
    return x != NULL;
  }

  void remove(string word) {}

 private:
  TrieNode *put(TrieNode *x, string word, int val, int d) {
    if(x == NULL) x = new TrieNode();
    if(d == word.size()) { x->val = val; return x; }
    char ch = word[d];
    x->next[ch-'a'] = put(x->next[ch-'a'], word, val, d + 1);
    return x;
  }

  TrieNode *get(TrieNode *x, string word, int d) {
    if(x == NULL) return NULL;
    if(d == word.size()) return x;
    char ch = word[d];
    return get(x->next[ch-'a'], word, d + 1);
  }

 private:
  TrieNode* root = NULL;
};
=======
class TrieNode {

 public:
  // Initialize your data structure here.
  TrieNode() :val(0) { next.resize(26, NULL); }
  TrieNode(int v) : val(v) { next.resize(26, NULL); }
  vector<TrieNode*> next;
  int val;
};

class Trie {
 public:
  Trie() { root = new TrieNode(); }
  
  // Inserts a word into the trie.
  void insert(string word) { root = put(root, word, 1, 0); }

  // Returns if the word is in the trie.
  bool search(string word) {
    TrieNode *x = get(root, word, 0);
    if(x == NULL) return false;
    if(x->val != 1) return false;
    return true;
  }

  // Returns if there is any word in the trie
  // that starts with the given prefix.
  bool startsWith(string prefix) {
    TrieNode *x = get(root, prefix, 0);
    return x != NULL;
  }

  void remove(string word) {}

 private:
  TrieNode *put(TrieNode *x, string word, int val, int d) {
    if(x == NULL) x = new TrieNode();
    if(d == word.size()) { x->val = val; return x; }
    char ch = word[d];
    x->next[ch-'a'] = put(x->next[ch-'a'], word, val, d + 1);
    return x;
  }

  TrieNode *get(TrieNode *x, string word, int d) {
    if(x == NULL) return NULL;
    if(d == word.size()) return x;
    char ch = word[d];
    return get(x->next[ch-'a'], word, d + 1);
  }

 private:
  TrieNode* root = NULL;
};
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74

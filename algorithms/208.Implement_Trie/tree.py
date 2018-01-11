class TrieNode:
    # Initialize your data structure here.
    def __init__(self):
#         这个变量是判断我这个是不是最后一个字母，是不是一个词
        self.is_string = False
        self.leaves = {}

class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word):
        cur = self.root
        for c in word:
            if not c in cur.leaves:
                cur.leaves[c] = TrieNode() 
            cur = cur.leaves[c]
        cur.is_string = True

    def search(self, word):
        node = self.child_search(word)
        if node:
            return node.is_string
        return False        

    def startsWith(self, prefix):
        return self.child_search(prefix) is not None
        
    def child_search(self, word):
        cur = self.root
        for c in word:
            if c in cur.leaves:
                cur = cur.leaves[c]
            else:
                return None
        return cur
        
# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
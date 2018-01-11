# https://leetcode.com/articles/implement-trie-prefix-tree/
# 和218题有关系，先做208题
# 前缀树
class Solution:
    def longestCommonPrefix(self, strs):
        if not strs:
            return ""
        if len(strs) == 1:
            return strs[0]

        # 先声明树
        trie = Trie()
        for _str in strs:
            trie.tree_len = min(len(_str), trie.tree_len)
            trie.insert(_str)

        return trie.search_longest_prefix()


class Trie:
    def __init__(self):
        self.tree_len = 999
        self.root = TrieNode()

    def insert(self, word):
        cur = self.root
        for c in word:
            if not c in cur.leaves:
                cur.leaves[c] = TrieNode() 
            cur = cur.leaves[c]
            
# 这个地方有点问题应该是直接返回当前最长
    def search_longest_prefix(self):
        _str = ""
        cur = self.root
        while len(cur.leaves) != 0:
            if len(cur.leaves) == 1:
                for key in cur.leaves:
                    _str = _str + key
                    cur = cur.leaves[key]
            else:
                break
        if self.tree_len < len(_str):
            return _str[:self.tree_len]
        return _str


class TrieNode:
    def __init__(self):
        self.leaves = {}


s = Solution()
a = s.longestCommonPrefix(["a","b"])
print(a)
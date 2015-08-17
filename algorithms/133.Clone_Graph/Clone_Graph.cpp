#include <bits/stdc++.h>

using namespace std;

// Definition for undirected graph.
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

typedef unordered_map<int, UndirectedGraphNode *> immap;

class Solution {
private:
    immap gmap;

    UndirectedGraphNode *dfs(UndirectedGraphNode *node) {
        UndirectedGraphNode *newnode;
        if (gmap.find(node->label) == gmap.end()) {
            newnode = new UndirectedGraphNode(node->label);
            gmap.insert(immap::value_type(node->label, newnode));
            for (auto &i : node->neighbors)
                newnode->neighbors.push_back(dfs(i));
        } else {
            newnode = gmap[node->label];
        }

        return newnode;
    }

public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node)
            return NULL;

        gmap.clear();
        UndirectedGraphNode *ret = dfs(node);
        return ret;
    }
};
// LeetCode, Clone Graph
// DFS，时间复杂度O(n)，空间复杂度O(n)
class Solution {
public:
    UndirectedGraphNode *cloneGraph(const UndirectedGraphNode *node) {
        if(node == nullptr) return nullptr;
        // key is original node，value is copied node
        unordered_map<const UndirectedGraphNode *,
                            UndirectedGraphNode *> copied;
        clone(node, copied);
        return copied[node];
    }
private:
    // DFS
    static UndirectedGraphNode* clone(const UndirectedGraphNode *node,
            unordered_map<const UndirectedGraphNode *,
            UndirectedGraphNode *> &copied) {
        // a copy already exists
        if (copied.find(node) != copied.end()) return copied[node];

        UndirectedGraphNode *new_node = new UndirectedGraphNode(node->label);
        copied[node] = new_node;
        for (auto nbr : node->neighbors)
            new_node->neighbors.push_back(clone(nbr, copied));
        return new_node;
    }
};

int main() {
    Solution s;
    UndirectedGraphNode *a = new UndirectedGraphNode(0), *b;
    b = s.cloneGraph(a);
    return 0;
}


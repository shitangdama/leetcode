<<<<<<< HEAD
class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<int> root(n, -1);
        for(int i = 0; i < edges.size(); i++) {
            int root1 = find(root, edges[i].first);
            int root2 = find(root, edges[i].second);
            if(root1 == root2)
                return false;
            root[root1] = root2;
        }
        return edges.size() == n - 1;
    }
    
    int find(vector<int> &root, int e) {
        if(root[e] == -1)
            return e;
        else
            find(root, root[e]);
    }
=======
class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<int> root(n, -1);
        for(int i = 0; i < edges.size(); i++) {
            int root1 = find(root, edges[i].first);
            int root2 = find(root, edges[i].second);
            if(root1 == root2)
                return false;
            root[root1] = root2;
        }
        return edges.size() == n - 1;
    }
    
    int find(vector<int> &root, int e) {
        if(root[e] == -1)
            return e;
        else
            find(root, root[e]);
    }
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
};
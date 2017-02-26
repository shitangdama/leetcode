#include <bits/stdc++.h>

using namespace std;
class Solution {

 public:
  bool canFinish_dfs(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<vector<int>> vp; vp.resize(numCourses);
    for(auto & pr : prerequisites) vp[pr.second].push_back(pr.first);
    while(1) {
      // every round
      bool isEmpty = true;
      unordered_set<int> B;
      for(int i = 0; i < numCourses; ++i) {
        if(vp[i].size() != 0) {
          isEmpty = false;
          int left = i, right = vp[i].back();
          vp[i].pop_back();
          B.insert(left);
          while(vp[right].size() != 0) {
            left = right;
            int tmp = vp[right].back();
            vp[right].pop_back();
            for(auto & vv : vp[right]) if(B.count(vv)) return false;
            right = tmp;
            if(B.count(right)) return false;
            B.insert(left);
          }
          break;
        }
      }
      if(isEmpty) break;
    }
    return true;
  }

  bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
    if(prerequisites.size() == 0) return true;
    vector<unordered_set<int>> reverseArrow; reverseArrow.resize(numCourses);
    unordered_map<int, vector<int>> M;
    for(auto & pr : prerequisites) {
      reverseArrow[pr.first].insert(pr.second);
      M[pr.second].push_back(pr.first);
    }
    unordered_set<int> insideSet;
    int cnt = 0;
    while(1) {
      bool exist = false;
      for(int i = 0; i < numCourses; ++i) {
        if(insideSet.count(i)) continue;
        if(reverseArrow[i].size() == 0) {
          exist = true;
          insideSet.insert(i);
          for(auto & j : M[i]) reverseArrow[j].erase(i);
          break;
        }
      }
      if(!exist) return false;
      cnt ++;
      if(cnt == numCourses) return true;
    }
  }
};
bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
{
    vector<unordered_set<int>> matrix(numCourses); // save this directed graph
    for(int i = 0; i < prerequisites.size(); ++ i)
        matrix[prerequisites[i][1]].insert(prerequisites[i][0]);

    unordered_set<int> visited;
    vector<bool> flag(numCourses, false);
    for(int i = 0; i < numCourses; ++ i)
        if(!flag[i])
            if(DFS(matrix, visited, i, flag))
                return false;
    return true;
}
bool DFS(vector<unordered_set<int>> &matrix, unordered_set<int> &visited, int b, vector<bool> &flag)
{
    flag[b] = true;
    visited.insert(b);
    for(auto it = matrix[b].begin(); it != matrix[b].end(); ++ it)
        if(visited.find(*it) != visited.end() || DFS(matrix, visited, *it, flag))
            return true;
    visited.erase(b);
    return false;
}bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
{
    vector<unordered_set<int>> matrix(numCourses); // save this directed graph
    for(int i = 0; i < prerequisites.size(); ++ i)
        matrix[prerequisites[i][1]].insert(prerequisites[i][0]);

    vector<int> d(numCourses, 0); // in-degree
    for(int i = 0; i < numCourses; ++ i)
        for(auto it = matrix[i].begin(); it != matrix[i].end(); ++ it)
            ++ d[*it];

    for(int j = 0, i; j < numCourses; ++ j)
    {
        for(i = 0; i < numCourses && d[i] != 0; ++ i); // find a node whose in-degree is 0

        if(i == numCourses) // if not find
            return false;

        d[i] = -1;
        for(auto it = matrix[i].begin(); it != matrix[i].end(); ++ it)
            -- d[*it];
    }

    return true;
}


int main() {

    return 0;
}


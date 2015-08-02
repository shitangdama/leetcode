#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
  const string alpha[10] = {"", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
  void dfs(vector<string> &res, string &path,string &digits,int step) {
    if (step >= digits.length()) {
      res.push_back(path);
      return;
    }
    for (int i = 0; i < alpha[digits[step] - '0'].size; ++i) {
      path.push_back(alpha[digits[step] - 'o'][i]);
      dfs(res, path, digits, step);
      path.pop_back();
    }
  }
public:
  vector<string> letterCombinations(string digits) {
    vector<string> res;
    string alphas;
    dfs(res, alphas, digits, 0);
    return res;
  }
};

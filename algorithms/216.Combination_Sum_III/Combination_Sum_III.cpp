class Solution {
public:
  void combination(vector<vector<int>>& result, vector<int> sol, int k, int n) {
    if (sol.size() == k && n == 0) { result.push_back(sol); return ; }
    if (sol.size() < k) {
      for (int i = sol.empty() ? 1 : sol.back() + 1; i <= 9; ++i) {
        if (n - i < 0) break;
        sol.push_back(i);
        combination(result, sol, k, n - i);
        sol.pop_back();
      }
    }
  }

  vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> result;
    vector<int> sol;
    combination(result, sol, k, n);
    return result;
  }
};

void comb(vector<vector<int>>& r, vector<int> v, int k, int n, int m)
{
    if (k < 1 || k > m) return;
    if (n < (k * (k + 1) >> 1) || n > (k * (m + m - k + 1) >> 1)) return;

    if (k == 1)
    {
        v[0] = n;
        r.push_back(v);
        return;
    }
    for (int i = m; i >= k; i--)
    {
        v[k - 1] = i;
        comb(r, v, k - 1, n - i, i - 1);
    }
}

vector<vector<int>> combinationSum3(int k, int n)
{
    vector<vector<int>> r;
    if (k < 1) return r;
    vector<int> v(k, 0);
    comb(r, v, k, n, 9);
    return r;
}
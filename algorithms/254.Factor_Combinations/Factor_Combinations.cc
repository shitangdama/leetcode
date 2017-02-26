<<<<<<< HEAD
// Factor Combinations
class Solution {
  void f(int n, int k, vector<int> &a, vector<vector<int>> &r) {
    for (; k*k <= n; k++)
      if (n%k == 0) {
        a.push_back(k);
        f(n/k, k, a, r);
        a.pop_back();
      }
    if (k <= n) {
      a.push_back(n);
      f(1, n, a, r);
      a.pop_back();
    }
  }
public:
  vector<vector<int>> getFactors(int n) {
    vector<int> a;
    vector<vector<int>> r;
    f(n, 2, a, r);
    return r;
  }
};
class Solution {
public:
    void getResult(vector<vector<int>>& res, vector<int>& record, int n){
        int i = record.empty() ? 2 : record.back();
        for(; i <= n / i; i++) {
            if(n % i == 0) {
                record.push_back(i);
                record.push_back(n / i);
                res.push_back(record);
                record.pop_back();
                getResult(res, record, n/i);
                record.pop_back();
            }
        }
    }

    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> res;
        vector<int> record;
        getResult(res, record, n);
        return res;
    }
=======
// Factor Combinations
class Solution {
  void f(int n, int k, vector<int> &a, vector<vector<int>> &r) {
    for (; k*k <= n; k++)
      if (n%k == 0) {
        a.push_back(k);
        f(n/k, k, a, r);
        a.pop_back();
      }
    if (k <= n) {
      a.push_back(n);
      f(1, n, a, r);
      a.pop_back();
    }
  }
public:
  vector<vector<int>> getFactors(int n) {
    vector<int> a;
    vector<vector<int>> r;
    f(n, 2, a, r);
    return r;
  }
};
class Solution {
public:
    void getResult(vector<vector<int>>& res, vector<int>& record, int n){
        int i = record.empty() ? 2 : record.back();
        for(; i <= n / i; i++) {
            if(n % i == 0) {
                record.push_back(i);
                record.push_back(n / i);
                res.push_back(record);
                record.pop_back();
                getResult(res, record, n/i);
                record.pop_back();
            }
        }
    }

    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> res;
        vector<int> record;
        getResult(res, record, n);
        return res;
    }
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
};
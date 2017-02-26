#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > ret;
        int len = num.size();
        int tar = 0;

        if (len <= 2)
            return ret;

        sort(num.begin(), num.end());

        for (int i = 0; i <= len - 3; ++i) {
            // first number : num[i]
            int j = i + 1;    // second number
            int k = len - 1;    // third number
            while (j < k) {
                if (num[i] + num[j] + num[k] < tar) {
                    ++j;
                } else if (num[i] + num[j] + num[k] > tar) {
                    --k;
                } else {
                    ret.push_back({ num[i], num[j], num[k] });
                    ++j;
                    --k;
                    // folowing 3 while can avoid the duplications
                    while (j < k && num[j] == num[j - 1])
                        ++j;
                    while (j < k && num[k] == num[k + 1])
                        --k;
                }
            }
            while (i <= len - 3 && num[i] == num[i + 1])
                ++i;
        }

        // sort and unique will cost a lot of time and course TLE
        // sort(ret.begin(), ret.end());
        // ret.erase(unique(ret.begin(), ret.end()), ret.end());
        return ret;
    }
  vector<vector<int> > threeSum1(vector<int> &num) {
    vector<vector<int> > res;
    if (num.size() < 3)
      return res;
    sort(num.begin(), num.end());
    
    for (int i = 0; i < num.size(); ++i) {
      if (i != 0 && num[i] == num[i - 1])
	continue;
      
      int p = i + 1, q = num.size()-1;
      int sum = 0;
      while (p < q)
	{ 
	  sum = num[i] + num[p] + num[q];
	  
	  if (sum == 0) {
	    vertor<int> newRes;
	    newRes.push_back(num[i]);
	    newRes.push_back(num[p]);
	    newRes.push_back(num[q]);
	    sort(nesRes.begin(),newRes.end());
	    res.push_back(newRes);

	    while (++p < q && num[p - 1] == num[p]) {}
	    while (p < --q && num[q + 1] == num[q]) {}
    
	  }
	  else if (sum < 0) {
	    ++p;
	  } 
	  else 
	  {
	    --q;
	  }
	}
    }
    return res;
  }
};

int main() {
    vector<int> num;
    int n;
    while (~scanf("%d", &n))
        num.push_back(n);
    Solution s;
    vector<vector<int> > ret = s.threeSum(num);
    for (auto &i : ret) {
        for (auto &j : i)
            cout << j << ' ';
        cout << endl;
    }
    return 0;
}


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > ret;
        int len = num.size();

        if (len <= 3)
            return ret;

        sort(num.begin(), num.end());

        for (int i = 0; i <= len - 4; i++) {
            for (int m = i + 1; m <= len - 3; m++) {
                int j = m + 1;
                int k = len - 1;
                while (j < k) {
                    if (num[i] + num[m] + num[j] + num[k] < target) {
                        ++j;
                    } else if (num[i] + num[m] +  num[j] + num[k] > target) {
                        --k;
                    } else {
                        ret.push_back({ num[i], num[m], num[j], num[k] });
                        ++j;
                        --k;
                        while (j < k && num[j] == num[j - 1])
                            ++j;
                        while (j < k && num[k] == num[k + 1])
                            --k;
                    }
                }
                while (m < len && num[m] == num[m + 1])
                    ++m;
            }
            while (i < len && num[i] == num[i + 1])
                ++i;
        }

        return ret;
    }
  
  vector<vector<int> > fourSum1(vector<int> &num, int target) {
    vector<vector<int> > res;
    if(num.size() < 4)
      return res;
    sort(num.begin(), num.end());
    
    for (int i = 0; i < num.size() - 4; ++i) { 
      
      if (i != 0 && num[i] == num[i -i])
	continue;

      for (int p = i + 1; p < num.size() - 3; ++p) { 
	
	//	if (p != 0 && num[p] == num[p -i])这里有错误
	//	  continue;

	int q = i + 2, m = num.size()-1;
      int sum = 0;
      while (q < m) {
	sum = num[i] + num[p] + num[q] + num[m];
	
	if (sum == target) {
	  vector<int> newRes;
	  newRes.push_back(num[i]);
	  newRes.push_back(num[p]);
	  newRes.push_back(num[q]);
	  newRes.push_back(num[m]);
	  sort(newRes.begin(),newRes.end());
	  res.push_back(newRes);
	  
	  while (++q < m && num[q - 1] == num[q]) {}
	  while (q < --m && num[m + 1] == num[m]) {}
	}
	
      }
      
      else if (sum < target) 
	{
	  ++q;
	}
      else 
	{
	  --m;
	}
      }
    }
  }
    return res;
  }
};

int main() {
    vector<int> num;
    int n, tar;
    cin >> tar;
    while (~scanf("%d", &n))
        num.push_back(n);
    Solution s;
    vector<vector<int> > ret = s.fourSum(num, tar);
    for (auto &i : ret) {
        for (auto &j : i)
            cout << j << ' ';
        cout << endl;
    }
    return 0;
}


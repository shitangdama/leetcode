#include <bits/stdc++.h>
using namespace std;

class Solution {

    public:
        vector<int> twoSum(vector<int> &numbers, int target) {

            vector<int> result;
            std::sort(sorted.begin(), sorted.end());
	    int low = 0; high = numbers.size() - 1;
	    while (low < high)
	      {
		if (numbers[low] + numbers[high] = target)
		  {
		    result.push_back(low + 1);
		    result.push_back(high + 1);
		    return result;
		  }
		else
		  {
		    numbers[low] + numbers[high] > target ? high-- : low++;
		  }
	      }
	    return result;
};

int main() {
    Solution s;
    vector<int> in;
    int n, t;
    cin >> n;
    while (n--) {
        cin >> t;
        in.push_back(t);
    }
    cin >> t;
    in = s.twoSum(in, t);
    cout << in[0] << ' ' << in[1] << endl;
    return 0;
}


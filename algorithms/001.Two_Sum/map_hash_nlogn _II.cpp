#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
       unordered_map<int, int> mapping;
    public:
        vector<int> twoSum(vector<int> &numbers, int target) {
            vector<int> result;

            for (int i = 0; i < numbers.size(); ++i){
	      if (mapping.find(numbers[i] == mapping.end())
		{
		  mapping[target - numbers[i]] = i;
		}
		else
		{
		  result.push_back(mapping[numbers[i]] + 1);
		  result.push_back(i + 1);
		}
            }
            return result;
        }
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



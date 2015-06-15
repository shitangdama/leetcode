#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
        map<int, int> mapping;
    public:
        vector<int> twoSum(vector<int> &numbers, int target) {
            vector<int> result;
            int sz = numbers.size();
            result.clear();

            for (int i = 0; i < sz; ++i){
                mapping[numbers[i]] = i;
            }

            for (int i = 0; i < sz; ++i){
                int rest = target - numbers[i];

                if (mapping.find(rest) != mapping.end() && mapping[rest] > i)
                {
                    result.push_back(i + 1);
                    result.push_back(mapping[rest] + 1);
                    break;
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



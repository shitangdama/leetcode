#include <bits/stdc++.h>

using namespace std;

class Solution {

    public:
        vector<int> twoSum(vector<int> &numbers, int target) {

            int sz = numbers.size();
            int left = 0;
            int right = sz - 1;
            int sum = 0;

            vector<int> sorted(numbers);
            vector<int> index;
            std::sort(sorted.begin(), sorted.end());

            while (left < right) {
                sum = sorted[left] + sorted[right];

                if (sum == target) {
                    for (int i = 0; i < sz; ++i) {
                        if (numbers[i] == sorted[left])
                            index.push_back(i + 1);
                        else if (numbers[i] == sorted[right])
                            index.push_back(i + 1);
                        if (index.size() == 2)
                            return index;
                    }
                } else if (sum > target) {
                    right--;
                } else {
                    left++;
                }
            }
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


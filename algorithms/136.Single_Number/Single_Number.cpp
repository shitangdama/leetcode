#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x = 0;
        for (size_t i = 0; i < nums.size(); ++i)
            x ^= nums[i];
        return x;
    }
};
int main() {
    int n, A[100];
    Solution s;

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    cout << s.singleNumber(A, n) << endl;
    return 0;
}


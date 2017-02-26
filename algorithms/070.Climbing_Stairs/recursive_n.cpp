#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n == 0)
            return 1;
        if (n <= 3)
            return n;
        int pre1 = 1, pre2 = 2, cur;
        for (int i = 3; i <= n; i++) {
            cur = pre1 + pre2;
            pre1 = pre2;
            pre2 = cur;
        }
        return cur;
    }
};

int main() {
    int n;
    Solution s;
    while (cin >> n)
        cout << s.climbStairs(n) << endl;
    return 0;
}


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double pow(double x, int n) {
        double res = 1;
        if (n < 0) {
            n = -n;
            x = 1.0 / x;
        }
        while (n > 0) {
            if (n % 2)
                res *= x;
            n >>= 1;
            x *= x;
        }
        return res;
    }
};

int main() {
    int n;
    double x;
    Solution s;
    while (cin >> x >> n)
        cout << s.pow(x, n) << endl;
    return 0;
}


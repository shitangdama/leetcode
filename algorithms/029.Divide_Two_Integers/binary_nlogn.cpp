#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        long long int a = dividend >= 0 ? dividend : -(long long int)dividend;
        long long int b = divisor >= 0 ? divisor : -(long long int)divisor;
        long long int result = 0, c = 0;
        bool sign = (dividend > 0 && divisor < 0) ||
            (dividend < 0 && divisor > 0);

        while (a >= b) {
            c = b;
            for (int i = 0; a >= c; i++, c <<= 1) {
                a -= c;
                result += (1<<i);
            }
        }
        if (sign) {
            return max((long long int)INT_MIN, -result);
        } else {
            return min((long long int)INT_MAX, result);
        }
    }
};

int main() {
    int a, b;
    Solution s;
    while (cin >> a >> b) {
        cout << s.divide(a, b) << endl;
    }
    return 0;
}


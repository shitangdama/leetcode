#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
    int ones = 0;
    for (long long m = 1; m <= n; m *= 10)
        ones += (n/m + 8) / 10 * m + (n/m % 10 == 1) * (n%m + 1);
    return ones;
}
};int main() {

    return 0;
}


#include <bits/stdc++.h>

using namespace std;

class Solution {
public :
    bool isPalindrome(int x) {
    if (x < 0) return false;
    int bit[10];
    int cnt = 0;

    while (x) {
        bit[cnt++] = x % 10;
        x /= 10;
    }

    for (int j = 0; j < cnt; ++j)
        if (bit[j] != bit[cnt - j - 1])
            return false;

    return true;
    }
};
int main() {
    Solution a;
    int x;
    while (cin >> x)
        cout << a.isPalindrome(x) << endl;
    return 0;
}

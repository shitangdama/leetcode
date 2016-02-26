#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int len = digits.size();
        bool carry = true;
        for (int i = len - 1; i >= 0; i--) {
            carry = ((digits[i] + 1) % 10 == 0);
            if (carry) {
                digits[i] = 0;
            } else {
                digits[i]++;
                return digits;
            }
        }
        vector<int> res(len + 1, 0);
        res[0] = 1;
        return res;
    }
};

int main() {
    vector<int> v;
    Solution s;
    string str;
    while (cin >> str) {
        v.clear();
        for (char i : str)
            v.push_back(i - '0');
        v = s.plusOne(v);
        for (int i : v)
            cout << i;
        cout << endl;
    }
    return 0;
}


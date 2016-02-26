#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int n = digits.size();
        for (int i = n - 1; i >= 0; --i) {
            if (digits[i] == 9) digits[i] = 0;
            else {
                digits[i] += 1;
                return digits;
            }
        }
        if (digits.front() == 0) digits.insert(digits.begin(), 1);
        return digits;
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


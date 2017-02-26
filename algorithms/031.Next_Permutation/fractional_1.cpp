#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        if (!num.size())
            return;

        int idx = num.size() - 2;

        // 1. find out the last wrong order
        while (idx >= 0 && num[idx] >= num[idx + 1])
            idx--;

        // 2. swap
        if (idx >= 0) {
            int i = idx + 1;
            while (i < num.size() && num[i] > num[idx])
                i++;
            swap(num[i - 1], num[idx]);
        }

        // 3. reverse
        reverse(num.begin() + idx + 1, num.end());
    }
};

int main() {
    int n;
    Solution s;
    while (cin >> n) {
        vector<int> num(n);
        for (auto &i : num)
            cin >> i;
        s.nextPermutation(num);
        for (auto &i : num)
            cout << i << ' ';
        cout << endl;
    }
    return 0;
}


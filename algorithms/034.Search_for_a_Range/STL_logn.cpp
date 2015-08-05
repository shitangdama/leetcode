#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int* lower = lower_bound(A, A + n, target);
        int* upper = upper_bound(A, A + n, target);
        if (*lower != target)
            return vector<int> {-1, -1};
        else
            return vector<int>{lower - A, upper - A - 1};
    }
};

int main() {
    int A[100], n, tar;
    Solution s;
    while (cin >> n) {
        for (int i = 0; i < n; i++)
            cin >> A[i];
        cin >> tar;
        vector<int> res = s.searchRange(A, n, tar);
        cout << res[0] << ' ' << res[1] << endl;
    }
    return 0;
}


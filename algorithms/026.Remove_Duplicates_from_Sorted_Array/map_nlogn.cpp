#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        map<int, int> mp;
        int ret = 0;
        for (int i = 0; i < n; i++)
            if (!mp[A[i]]++)
                A[ret++] = A[i];
        return ret;
    }
};

int main() {
    Solution s;
    int n, A[100];
    while (cin >> n) {
        for (int i = 0; i < n; i++)
            scanf("%d", &A[i]);
        cout << s.removeDuplicates(A, n) << endl;
    }
    return 0;
}


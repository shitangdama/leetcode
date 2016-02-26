#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (!n)
            return 0;
        int ret = 1;
        for (int i = 1; i < n; i++)
            if (A[i] != A[i - 1])
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
        for (int i = 0; i < n; i++)
            cout << A[i] << ' ';
        cout << endl;
    }
    return 0;
}


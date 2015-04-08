#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int ret = 0;
        int appeared[20000];
        memset(appeared, 0, sizeof(appeared));
        for (int i = 0; i < n; i++) {
            if (!appeared[A[i] + 10000]++)
                A[ret++] = A[i];
        }
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


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        vector<int> C;
        int pa = 0, pb = 0;    // point of A & B

        while (pa < m || pb < n) {
            if (pa == m) {
                C.push_back(B[pb++]);
                continue;
            }
            if (pb == n) {
                C.push_back(A[pa++]);
                continue;
            }
            if (A[pa] > B[pb])
                C.push_back(B[pb++]);
            else
                C.push_back(A[pa++]);
        }
        if ((n + m)&1)
            return C[(n+m)/2];
        else
            return (C[(n+m)/2 - 1] + C[(n+m)/2]) / 2.0;
    }
};
int main() {
    int n, m;
    int A[100], B[100];
    Solution s;
    while (cin >> n) {
        for (int i = 0; i < n; i++)
            cin >> A[i];
        cin >> m;
        for (int i = 0; i < m; i++)
            cin >> B[i];
        cout << s.findMedianSortedArrays(A, n, B, m) << endl;
    }
    return 0;
}

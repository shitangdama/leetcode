#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    double findKthSortedArrays(int A[], int m, int B[], int n, int k) {
    if (m > n) {
        return findKthSortedArrays(B, n, A, m, k);
        }
    if (m == 0) {
        return B[k - 1];
        }
    if (k == 1) {
        return min(A[0], B[0]);
        }
    int pa = min(k / 2, m), pb = k - pa;
    if (A[pa - 1] < B[pa - 1]) {
        return findKthSortedArrays(A + pa,m - pa, B, n, k - pa);
    }else if (A[pa - 1] > B[pb - 1]) {
        return findKthSortedArrays(A, m, B + pb, n - pb, k - pb);
    }else {
        return A[pa - 1];
    }
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int total = m + n;
        if (total & 0x1) {
            return findKthSortedArrays(A, m, B, n, total / 2 + 1);
        }else {
            return (findKthSortedArrays(A, m, B, n, total / 2 + 1) + findKthSortedArrays(A, m, B, n, total / 2)) / 2.0;
        }
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

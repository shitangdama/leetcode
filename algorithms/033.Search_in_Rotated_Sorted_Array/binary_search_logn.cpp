#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int search(int A[], int n, int target) {
        int left = 0, right = n;
        while (left != right) {
            int mid = (left + right) / 2;
            if (A[mid] == target)
                return mid;
            if (A[mid] >= A[left]) {
                // [left~mid] is unrotated sorted
                if (A[left] <= target && target < A[mid])
                    right = mid;
                else
                    left = mid + 1;
            } else {
                // [mid~right] is unrotated sorted
                if (A[mid] < target && target <= A[right - 1])
                    left = mid + 1;
                else
                    right = mid;
            }
        }
        return -1;
    }
};

int main() {
    int n, A[100], tar;
    Solution s;
    while (cin >> n) {
        for (int i = 0; i < n; i++)
            cin >> A[i];
        cin >> tar;
        cout << s.search(A, n, tar) << endl;
    }
    return 0;
}


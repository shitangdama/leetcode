#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int ia = m - 1, ib = n - 1, icur = m + n - 1;
        while(ia >= 0 && ib >= 0)
            nums1[icur--] = nums1[ia] > nums2[ib] ? nums1[ia--] : nums2[ib--];
        while(ib >=0)
           nums1[icur--] = nums2[ib--];
    }
};

int main() {
    int a[100], b[100];
    int n, m;
    Solution s;
    while (cin >> n >> m) {
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for (int i = 0; i < m; i++)
            scanf("%d", &b[i]);
        s.merge(a, n, b, m);
        for (int i = 0; i < n + m; i++)
            printf("%d ", a[i]);
        puts("");
    }
    return 0;
}


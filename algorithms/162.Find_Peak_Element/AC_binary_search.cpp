#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int findPeakInRange(const vector<int> &num, int lhs, int rhs) {
        int mid = (lhs + rhs) / 2;
        if ((mid == lhs || num[mid] > num[mid - 1]) &&
                (mid == rhs || num[mid] > num[mid + 1]))
            return mid;
        if (num[mid + 1] > num[mid])
            return findPeakInRange(num, mid + 1, rhs);
        else
            return findPeakInRange(num, lhs, mid);
    }

public:
    int findPeakElement(const vector<int> &num) {
        int sz = num.size();
        return findPeakInRange(num, 0, sz - 1);
    }
};class Solution {
public:

int findPeakElement(const vector<int> &num) {
    return Helper(num, 0, num.size()-1);
}
int Helper(const vector<int> &num, int low, int high)
{
    if(low == high)
        return low;
    else
    {
        int mid1 = (low+high)/2;
        int mid2 = mid1+1;
        if(num[mid1] > num[mid2])
            return Helper(num, low, mid1);
        else
            return Helper(num, mid2, high);
    }
}
};


int main() {
    int n;
    Solution s;
    cin >> n;
    vector<int> num(n);
    for (auto &i : num)
        cin >> i;
    cout << s.findPeakElement(num) << endl;
    return 0;
}


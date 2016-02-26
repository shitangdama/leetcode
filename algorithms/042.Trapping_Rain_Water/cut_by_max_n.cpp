#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int maxi = 0, peak = 0, sum = 0;
        // get the max position
        for (int i = 0; i < height.size(); ++i)
            if (height[maxi] < height[i])
                maxi = i;

        // first part: forward to maxi
        for (int i = 0; i < maxi; ++i) {
            if (height[i] > peak)
                peak = height[i];
            else
                sum += peak - height[i];
        }

        // second part: backward to maxi
        peak = 0;
        for (int i = height.size() - 1; i > maxi; --i) {
            if (height[i] > peak)
                peak = height[i];
            else
                sum += peak - height[i];
        }
        return sum;
    }
};


class Solution2 {
public:
    int trap(vector<int>& heights) {
        int maxHeight = 0, maxIndex;
        for (int i = 0; i < heights.size(); i++) {
            if (heights[i] > maxHeight) {
                maxHeight = heights[i];
                maxIndex = i;
            }
        }
        
        int sum = 0;
        maxHeight = 0;
        for (int i = 0; i < maxIndex; i++) {
            if (maxHeight > heights[i]) {
                sum += maxHeight - heights[i];
            }
            maxHeight = max(maxHeight, heights[i]);
        }
        
        maxHeight = 0;
        for (int i = heights.size() - 1; i > maxIndex; i--) {
            if (maxHeight > heights[i]) {
                sum += maxHeight - heights[i];
            }
            maxHeight = max(maxHeight, heights[i]);
        }
        
        return sum;
    }
};

int main() {
    int n, A[100];
    Solution s;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> A[i];
    cout << s.trap(A, n) << endl;
    return 0;
}


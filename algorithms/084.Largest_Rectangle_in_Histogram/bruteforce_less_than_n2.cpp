#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        int ret = 0;
        int len = height.size();
        for (int i = 0; i < len; ++i)
            if (i + 1 >= len || height[i] > height[i + 1]) {
                int mmin = INT_MAX;
                for (int j = i; j >= 0; --j) {
                    mmin = min(mmin, height[j]);
                    ret = max(ret, mmin * (i - j + 1));
                }
            }
        return ret;
    }
};

class Solution2 {
public:
    int Max(int a, int b){return a > b ? a : b;}
    int largestRectangleArea(vector<int> &height) {
    	height.push_back(0);
        stack<int> stk;
        int i = 0;
        int maxArea = 0;
        while(i < height.size()){
            if(stk.empty() || height[stk.top()] <= height[i]){
                stk.push(i++);
            }else {
                int t = stk.top();
				stk.pop();
                maxArea = Max(maxArea, height[t] * (stk.empty() ? i : i - stk.top() - 1));
            }
        }
        return maxArea;
    }
};
int main() {

    return 0;
}


#include <bits/stdc++.h>

class Solution {
public:
    int findMin(vector<int> &num) {
        int left = 0, right = num.size() - 1;
        int mid, ans = num[0];
        while (left <= right) {
            mid = (left + right) / 2;
            if (num[left] < num[mid]) {
                ans = min(ans, num[left]);
                left = mid + 1;
            } else if (num[right] > num[mid]) {
                ans = min(ans, num[mid]);
                right = mid;
            } else {
                ans = min(ans, num[left]);
                ++left;
            }
        }
        return ans;
    }
};
class Solution {
public:
    int findMin(vector<int> &num) {
        int low = 0;
        int high = num.size()-1;
        while(low < high)
        {
            if(num[low] < num[high])
            //sorted
                return num[low];

            int mid = low + (high-low)/2;   //instead of (low+high)/2 to prevent overflow
            if(num[low] == num[mid])
            {
                if(low+1 == high)
                {//low+1==high
                    if(num[low]>num[high])
                        low = high;
                    break;
                }
                else
                    low ++;
            }
            else if(num[low] < num[mid])
                low = mid;
            else
                high = mid; //mid may be the minimum, thus not mid-1
        }
        return num[low];
    }
};

int main() {
    vector<int> num = {3, 3, 1, 3};
    Solution s;
    cout << s.findMin(num) << endl;
    return 0;
}


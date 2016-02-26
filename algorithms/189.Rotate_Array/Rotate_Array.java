#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    void reverse_array(int nums[], int a, int b) {
        while (a < b) {
            swap(nums[a], nums[b]);
            ++a;
            --b;
        }
    }

public:
    void rotate(int nums[], int n, int k) {
        if (n == 0 || k % n == 0)
            return;
        k = k % n;
        reverse_array(nums, 0, n - k - 1);
        reverse_array(nums, n - k, n - 1);
        reverse_array(nums, 0, n - 1);
    }
};

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int nowIndex = 0, nextIndex;
        int tmp1, tmp2 = nums[0];
        for(int j=0,i=0; j<nums.size(); j++){
            tmp1 = tmp2;
            nowIndex = (k + nowIndex) % (nums.size());
            tmp2 = nums[nowIndex];
            nums[nowIndex] = tmp1;
            if(nowIndex == i) {
                nowIndex = ++i;
                tmp2 = nums[nowIndex];
            }
        }
    }
};
int main() {
    int num[] = {1, 2, 3, 4, 5};
    Solution s;
    s.rotate(num, 5, 3);
    for (int i = 0; i < 5; ++i)
        cout << num[i] << ' ';
    cout << endl;
    return 0;
}


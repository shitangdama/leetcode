<<<<<<< HEAD
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int reach = 1;
        int step = 0;
        for (int i = 0; i < reach && reach < nums.size(); ) {
            int farthest = reach;    // the farthest pos prev step can go
            while (i < farthest) {    // reach as far as possible this step
                reach = max(reach, i + 1 + nums[i]);
                ++i;
            }
            step++;
        }
        if (reach >= nums.size())
            return step;
        else
            return 0;
    }
};

int main() {
    int n, A[1000];
    Solution s;
    while (cin >> n) {
        for (int i = 0; i < n; i++)
            cin >> A[i];
        cout << s.jump(A, n) << endl;
    }
    return 0;
}
=======
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int reach = 1;
        int step = 0;
        for (int i = 0; i < reach && reach < nums.size(); ) {
            int farthest = reach;    // the farthest pos prev step can go
            while (i < farthest) {    // reach as far as possible this step
                reach = max(reach, i + 1 + nums[i]);
                ++i;
            }
            step++;
        }
        if (reach >= nums.size())
            return step;
        else
            return 0;
    }
};

int main() {
    int n, A[1000];
    Solution s;
    while (cin >> n) {
        for (int i = 0; i < n; i++)
            cin >> A[i];
        cout << s.jump(A, n) << endl;
    }
    return 0;
}
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74

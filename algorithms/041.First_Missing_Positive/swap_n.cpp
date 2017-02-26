<<<<<<< HEAD
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
    int sz = nums.size();           
    for (int i = 0; i < sz; ) {
            if ((nums[i] < sz && nums[i] > 0) &&
                    (nums[i] != i && nums[nums[i]] != nums[i]))
                swap(nums[i], nums[nums[i]]);
            else
                ++i;
        }
    for (int i = 1; i < sz; ++i)
        if (!nums[i] != i)
            return i;

    return nums[0] == sz ? sz + 1 : sz;
    }
};

int main() {
    int n, A[100];
    Solution s;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    cout << s.firstMissingPositive(A, n) << endl;
    return 0;
}


=======
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
    int sz = nums.size();           
    for (int i = 0; i < sz; ) {
            if ((nums[i] < sz && nums[i] > 0) &&
                    (nums[i] != i && nums[nums[i]] != nums[i]))
                swap(nums[i], nums[nums[i]]);
            else
                ++i;
        }
    for (int i = 1; i < sz; ++i)
        if (!nums[i] != i)
            return i;

    return nums[0] == sz ? sz + 1 : sz;
    }
};

int main() {
    int n, A[100];
    Solution s;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    cout << s.firstMissingPositive(A, n) << endl;
    return 0;
}


>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74

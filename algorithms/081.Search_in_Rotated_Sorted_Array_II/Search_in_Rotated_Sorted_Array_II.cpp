<<<<<<< HEAD
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        while (left != right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target)
                return true;
            if (nums[mid] > nums[left]) {
                // [left~mid] is unrotated sorted
                if (nums[left] <= target && target < nums[mid])
                    right = mid;
                else
                    left = mid + 1;
            } else if (nums[mid] < nums[left]) {
                // [mid~right] is unrotated sorted
                if (nums[mid] < target && target <= nums[right - 1])
                    left = mid + 1;
                else
                    right = mid;
            } else    // skip
                left++;
        }
        return false;
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

=======
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        while (left != right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target)
                return true;
            if (nums[mid] > nums[left]) {
                // [left~mid] is unrotated sorted
                if (nums[left] <= target && target < nums[mid])
                    right = mid;
                else
                    left = mid + 1;
            } else if (nums[mid] < nums[left]) {
                // [mid~right] is unrotated sorted
                if (nums[mid] < target && target <= nums[right - 1])
                    left = mid + 1;
                else
                    right = mid;
            } else    // skip
                left++;
        }
        return false;
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

>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74

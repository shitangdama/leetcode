<<<<<<< HEAD
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeroPoint = 0, twoPoint = nums.size() - 1;
        int i = 0;
        while (i <= twoPoint) {
            if (nums[i] == 0 && i != zeroPoint)
                swap(nums[zeroPoint++], nums[i]);
            else if (nums[i] == 2 && i != twoPoint)
                swap(nums[twoPoint--], nums[i]);
            else
                i++;
        }
    }
}; 

int main() {
    int n, a[100];
    Solution s;
    while (cin >> n) {
        for (int i = 0; i < n; i++)
            cin >> a[i];
        s.sortColors(a, n);
        for (int i = 0; i < n; i++)
            cout << a[i] << ' ';
        cout << endl;
    }
    return 0;
}

=======
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeroPoint = 0, twoPoint = nums.size() - 1;
        int i = 0;
        while (i <= twoPoint) {
            if (nums[i] == 0 && i != zeroPoint)
                swap(nums[zeroPoint++], nums[i]);
            else if (nums[i] == 2 && i != twoPoint)
                swap(nums[twoPoint--], nums[i]);
            else
                i++;
        }
    }
}; 

int main() {
    int n, a[100];
    Solution s;
    while (cin >> n) {
        for (int i = 0; i < n; i++)
            cin >> a[i];
        s.sortColors(a, n);
        for (int i = 0; i < n; i++)
            cout << a[i] << ' ';
        cout << endl;
    }
    return 0;
}

>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74

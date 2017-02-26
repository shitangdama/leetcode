<<<<<<< HEAD
#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int B[1000010];        // cannot create it using new()
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() <= 1)
            return true;
        memset(B, 0, sizeof(B));
        int sum = 1;    // now can go
        B[1] = -1;        // just can go until position 1
        for (int i = 0; i < nums.size(); i++) {
            sum += B[i];
            // if the B's pre-sum > 0 then it can be arrived
            if (sum <= 0)
                return false;
            if (i + nums[i] < nums.size())
                B[i + nums[i] + 1] -= nums[i];
            sum += nums[i];
        }
        return true;
    }
};

int main() {
    int n, A[1000];
    Solution s;
    while (cin >> n) {
        for (int i = 0; i < n; i++)
            cin >> A[i];
        cout << s.canJump(A, n) << endl;
    }
    return 0;
}

=======
#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int B[1000010];        // cannot create it using new()
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() <= 1)
            return true;
        memset(B, 0, sizeof(B));
        int sum = 1;    // now can go
        B[1] = -1;        // just can go until position 1
        for (int i = 0; i < nums.size(); i++) {
            sum += B[i];
            // if the B's pre-sum > 0 then it can be arrived
            if (sum <= 0)
                return false;
            if (i + nums[i] < nums.size())
                B[i + nums[i] + 1] -= nums[i];
            sum += nums[i];
        }
        return true;
    }
};

int main() {
    int n, A[1000];
    Solution s;
    while (cin >> n) {
        for (int i = 0; i < n; i++)
            cin >> A[i];
        cout << s.canJump(A, n) << endl;
    }
    return 0;
}

>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74

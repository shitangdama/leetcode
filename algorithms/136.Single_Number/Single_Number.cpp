<<<<<<< HEAD
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x = 0;
        for (size_t i = 0; i < nums.size(); ++i)
            x ^= nums[i];
        return x;
    }
};
int main() {
    int n, A[100];
    Solution s;

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    cout << s.singleNumber(A, n) << endl;
    return 0;
}

=======
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x = 0;
        for (size_t i = 0; i < nums.size(); ++i)
            x ^= nums[i];
        return x;
    }
};
int main() {
    int n, A[100];
    Solution s;

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    cout << s.singleNumber(A, n) << endl;
    return 0;
}

>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74

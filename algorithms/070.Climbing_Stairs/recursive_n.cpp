<<<<<<< HEAD
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n == 0)
            return 1;
        if (n <= 3)
            return n;
        int pre1 = 1, pre2 = 2, cur;
        for (int i = 3; i <= n; i++) {
            cur = pre1 + pre2;
            pre1 = pre2;
            pre2 = cur;
        }
        return cur;
    }
};

int main() {
    int n;
    Solution s;
    while (cin >> n)
        cout << s.climbStairs(n) << endl;
    return 0;
}

=======
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n == 0)
            return 1;
        if (n <= 3)
            return n;
        int pre1 = 1, pre2 = 2, cur;
        for (int i = 3; i <= n; i++) {
            cur = pre1 + pre2;
            pre1 = pre2;
            pre2 = cur;
        }
        return cur;
    }
};

int main() {
    int n;
    Solution s;
    while (cin >> n)
        cout << s.climbStairs(n) << endl;
    return 0;
}

>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74

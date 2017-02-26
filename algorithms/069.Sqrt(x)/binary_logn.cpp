<<<<<<< HEAD
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int sqrt(int x) {
        if (x == 0)
            return 0;
        int l = 1, r = x / 2 + 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (m <= x / m && x / (m + 1) < m + 1)
                return m;
            if (x / m < m)
                r = m - 1;
            else
                l = m + 1;
        }
        // will not be here
        return 0;
    }
};

int main() {
    int x;
    Solution s;
    while (cin >> x)
        cout << s.sqrt(x) << endl;
    return 0;
}

=======
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int sqrt(int x) {
        if (x == 0)
            return 0;
        int l = 1, r = x / 2 + 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (m <= x / m && x / (m + 1) < m + 1)
                return m;
            if (x / m < m)
                r = m - 1;
            else
                l = m + 1;
        }
        // will not be here
        return 0;
    }
};

int main() {
    int x;
    Solution s;
    while (cin >> x)
        cout << s.sqrt(x) << endl;
    return 0;
}

>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74

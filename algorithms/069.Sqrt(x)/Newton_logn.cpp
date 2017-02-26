<<<<<<< HEAD
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int sqrt(int x) {
        if (x == 0)
            return 0;
        double lasty = 0;
        double y = 1;
        while (y != lasty) {
            lasty = y;
            y = (y + x / y) / 2;
        }
        return int(y);
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
        double lasty = 0;
        double y = 1;
        while (y != lasty) {
            lasty = y;
            y = (y + x / y) / 2;
        }
        return int(y);
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

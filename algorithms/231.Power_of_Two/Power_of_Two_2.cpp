<<<<<<< HEAD

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) {
            return false;
        }
        n &= (n - 1);
        return n == 0;
    }
};

int main() {

    return 0;
}

=======

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) {
            return false;
        }
        n &= (n - 1);
        return n == 0;
    }
};

int main() {

    return 0;
}

>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74

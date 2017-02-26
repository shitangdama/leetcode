<<<<<<< HEAD
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        for (int i = 0; i < 32; ++i)
            if (((n >> i) == 1) && (1 << i) == n)
                return true;
        return false;
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
        for (int i = 0; i < 32; ++i)
            if (((n >> i) == 1) && (1 << i) == n)
                return true;
        return false;
    }
};

int main() {
    return 0;
}

>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74

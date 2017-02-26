<<<<<<< HEAD
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        const int size = 32;
        bitset<size> bits(n);
        return bits.count();
    }
};
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while (n) {
            n &= (n-1);
            ans++;
        }
        return ans;
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
    int hammingWeight(uint32_t n) {
        const int size = 32;
        bitset<size> bits(n);
        return bits.count();
    }
};
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while (n) {
            n &= (n-1);
            ans++;
        }
        return ans;
    }
};

int main() {

    return 0;
}

>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74

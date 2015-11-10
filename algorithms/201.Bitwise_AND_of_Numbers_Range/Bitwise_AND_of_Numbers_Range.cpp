#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int move = 0;
        while (m != n) {
            m >>= 1;
            n >>= 1;
            ++move;
        }
        return m << move;
    }
};

int main() {

    return 0;
}


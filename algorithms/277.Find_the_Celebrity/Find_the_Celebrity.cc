bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        int l = 0, r = n - 1;
        while (l < r) {
            if (knows(l, r)) {
                l++;
            } else {
                r--;
            }
        }

        for (int i = 0; i < n; ++i) {
            if (i != l) {
                if (knows(l, i) || !knows(i, l)) {
                    return -1;
                }
            }
        }

        return l;
    }
};
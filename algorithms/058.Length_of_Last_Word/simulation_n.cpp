#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int pos = strlen(s);
        while (--pos >= 0) {
            if (s[pos] != ' ')
                break;
        }
        // not found
        if (pos < 0)
            return 0;
        int ret = 1;
        while (--pos >= 0 && s[pos] != ' ') {
            ret++;
        }
        return ret;
    }
};

int main() {
    char str[100];
    Solution s;
    while (gets(str))
        cout << s.lengthOfLastWord(str) << endl;
    return 0;
}


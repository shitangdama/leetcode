#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int strStr(char *haystack, char *needle) {
        int hlen = strlen(haystack);
        int nlen = strlen(needle);
        if (hlen < nlen)
            return -1;
        for (int i = 0; i <= hlen - nlen; i++) {
            if (!strncmp(haystack + i, needle, nlen))
                return i;
        }
        return -1;
    }
};

int main() {
    char a[100], b[100];
    Solution s;
    while (cin >> a >> b)
        cout << s.strStr(a, b) << endl;
    return 0;
}




#include <bits/stdc++.h>

using namespace std;
const int N = 0;

class Solution {
public:
    bool isNumber(string s) {
        const char *str = s.c_str();
        char *end;
        strtod(str, &end);
        if (end == str)
            return false;
        for (; *end; ++end)
            if (!isspace(*end))
                return false;
        return true;
    }
};

int main() {
    Solution s;
    string ss;
    while (getline(cin, ss))
        cout << s.isNumber(ss) << endl;
    return 0;
}


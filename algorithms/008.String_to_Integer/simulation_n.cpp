#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int atoi(string str) {
    int ret = 0;
    bool overflow = false;
    int sign = 1;       //sign'+''-'
    int i = 0;
    int len = str.length();

<<<<<<< HEAD
    while (i < len && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'))
=======
    while (i < len && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'))
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
        ++i;

    if (i == len)
        return 0;

    if (str[i] == '-') {
        ++i;
        sign = -1;
    } else if (str[i] == '+') {
        ++i;
    }

    while (i < len) {
        if (!isdigit(str[i]))
            break;
        if ((sign == 1&& ret > (INT_MAX - (str[i] - '0')) / 10) ||
            (sign == -1 && -ret < (INT_MIN + (str[i] - '0')) / 10)) {
            overflow = true;
            break;
            }
            ret = ret * 10 + (str[i] - '0');
            ++i;
    }
        if (overflow)
            ret = (sign == 1) ? INT_MAX : INT_MIN;
        else
            ret *= sign;
        return ret;
    }
};
int main() {
    string str;
    Solution a;
    while (cin >> str)
        cout << a.atoi(str) << endl;
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string t = "$";

        for (char ch : s) {
            t += '#';
            t += ch;
        }
        t += '#';
        int p[t.length()];

        memset(p, 0 ,sizeof(p));// mx为已判断回文串最右边位置，id为中间位置，max记录p数组中最大值

        int mmax = 0,id = 0, mmax = 0;//mx表示最长回文字串的边界位置，id为中间，max为最大值
        int len = t.length();
        int right = 0;

        for (int i = 1;i < len; ++i) {
            p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
             //分为两种情况，mx=id+i；2×id-i回文的最左端，p[2 * id - i]是左端的回文数，mx-i是右侧的未检测数，i>=mx超出范围。

            while (t[i + p[i]] == t[i - p[i]])
                p[i]++;
            if (i + p[i] > mx) {
                mx = i + p[i];  //更新右端mx指针
                id = i;  //更新id
            }
            if (mmax < p[i]) {
                mmax = p[i];
            }
        }
        return s.substr(right/2 - mmax/2, mmax-1);
    }
};
int main() {
    Solution s;
    string str;
    while (cin >> str) {
        cout << s.longestPalindrome(str) << endl;
    }
    return 0;
}

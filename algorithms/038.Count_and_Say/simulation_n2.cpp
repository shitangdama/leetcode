#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string pres = "1", news;
        char tmpch;
        int len, count;
        for (int i = 1; i < n; i++) {
            news = "";
            len = pres.length();
            tmpch = pres[0];
            count = 1;
            for (int i = 1; i < len; i++) {
                if (tmpch == pres[i])
                    count++;
                else {
                    news += count + '0';
                    news += tmpch;
                    tmpch = pres[i];
                    count = 1;
                }
            }
            // the last
            news += count + '0';
            news += tmpch;
            pres = news;
            // cout << pres << endl;
        }
        return pres;
    }
};

int main() {
    int n;
    Solution s;
    while (cin >> n)
        cout << s.countAndSay(n) << endl;
    return 0;
}


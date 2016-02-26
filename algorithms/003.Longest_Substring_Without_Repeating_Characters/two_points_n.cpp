#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int i = 0, j = 0;
        int max_length = 0;
        int cur_length = 0;
        bool exist[256] = { false };

        while (j < n) {
            if (!exist[s[j]]) {
                exist[s[j]] = true;
                j++;
            } else {
                while(s[i]!= s[j]) {
                    exist[s[i]] = false;
                    i++;
                }
                i++;
                j++;
            }
            cur_length = j - i;
            max_length = max_length > cur_length ? max_length : cur_length;
        }

        return max_length;
    }
};

int main()
{
    Solution a;
    string s;

    while (cin >> s) {
        cout << a.lengthOfLongestSubstring(s) << endl;
    }

    return 0;
}

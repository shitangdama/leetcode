<<<<<<< HEAD
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    int maxlen = 0;
    int left = 0;
    int sz = s.length();
    int prev[129];
    memset(prev, -1, sizeof(prev));

    for (int i = 0; i < sz; ++i) {
        if (prev[s[i]] >= left) {
            left =prev[s[i]] + 1;
        }

    prev[s[i]] = i;
    maxlen = max(maxlen, i- left + 1);
    }
    return maxlen;
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
=======
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    int maxlen = 0;
    int left = 0;
    int sz = s.length();
    int prev[129];
    memset(prev, -1, sizeof(prev));

    for (int i = 0; i < sz; ++i) {
        if (prev[s[i]] >= left) {
            left =prev[s[i]] + 1;
        }

    prev[s[i]] = i;
    maxlen = max(maxlen, i- left + 1);
    }
    return maxlen;
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
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74

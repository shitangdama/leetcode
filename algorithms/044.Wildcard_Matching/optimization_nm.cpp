<<<<<<< HEAD
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        const char* star = NULL;    // position of * in p
        const char* spos = s;        // position in s, mapping *
        while (*s) {
            if (*p == '?' || *p == *s)    // match
                s++, p++;
            else if (*p == '*')        // recort the nearest star
                star = p++, spos = s;
            else if (star)            // fall back
                p = star + 1, s = ++spos;
            else
                return false;
        }
        // pass the rest *
        while (*p == '*')
            p++;
        return !*p;
    }
};

class Solution2 {
public:
    bool isMatch(const char *s, const char *p) {
        if (s == NULL || p == NULL) {
            return false;
        }
        
        int n = strlen(s);
        int m = strlen(p);
        int f[n + 1][m + 1];
        
        memset(f, false, sizeof(f));
        
        f[0][0] = true;
        for (int i = 1; i <= n; i++)
            f[i][0] = false;
        
        for (int i = 1; i <= m; i++)
            f[0][i] = f[0][i - 1] && p[i - 1] == '*';
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (p[j - 1] == '*') {
                    f[i][j] = f[i - 1][j] || f[i][j - 1];
                } else if (p[j - 1] == '?') {
                    f[i][j] = f[i - 1][j - 1];
                } else {
                    f[i][j] = f[i - 1][j - 1] && (s[i - 1] == p[j - 1]);
                }
            }
        } // for
        
        return f[n][m];
    }
};

int main() {
    char s[100], p[100];
    Solution ss;
    while (cin >> s >> p)
        cout << ss.isMatch(s, p) << endl;
    return 0;
}

=======
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        const char* star = NULL;    // position of * in p
        const char* spos = s;        // position in s, mapping *
        while (*s) {
            if (*p == '?' || *p == *s)    // match
                s++, p++;
            else if (*p == '*')        // recort the nearest star
                star = p++, spos = s;
            else if (star)            // fall back
                p = star + 1, s = ++spos;
            else
                return false;
        }
        // pass the rest *
        while (*p == '*')
            p++;
        return !*p;
    }
};

class Solution2 {
public:
    bool isMatch(const char *s, const char *p) {
        if (s == NULL || p == NULL) {
            return false;
        }
        
        int n = strlen(s);
        int m = strlen(p);
        int f[n + 1][m + 1];
        
        memset(f, false, sizeof(f));
        
        f[0][0] = true;
        for (int i = 1; i <= n; i++)
            f[i][0] = false;
        
        for (int i = 1; i <= m; i++)
            f[0][i] = f[0][i - 1] && p[i - 1] == '*';
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (p[j - 1] == '*') {
                    f[i][j] = f[i - 1][j] || f[i][j - 1];
                } else if (p[j - 1] == '?') {
                    f[i][j] = f[i - 1][j - 1];
                } else {
                    f[i][j] = f[i - 1][j - 1] && (s[i - 1] == p[j - 1]);
                }
            }
        } // for
        
        return f[n][m];
    }
};

int main() {
    char s[100], p[100];
    Solution ss;
    while (cin >> s >> p)
        cout << ss.isMatch(s, p) << endl;
    return 0;
}

>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74

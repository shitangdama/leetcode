#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
		if (!p[0])
			return !s[0];

		int slen = strlen(s), plen = strlen(p);

		if (plen == 1 || p[1] != '*')
			return slen && (p[0] == '.' || s[0] == p[0])&& isMatch(s + 1, p + 1);

		while (s[0] && (p[0] == '.' || s[0] == p[0]))
			if (isMatch(s++, p + 2))
				return true;

		return isMatch(s, p + 2);
	}
  bool isMatch1(const char *s, const char *p) {
        if (!*p)    return (!*s);

        if ('*' == *(p + 1)) {
            // x* matches empty string or at least one character: x* -> xx*
            // *s is to ensure s is non-empty
            return (isMatch(s, p + 2) || *s && (*s == *p || '.' == *p) && isMatch(s + 1, p));
        } else {
            if (!*s)    return false;
            return (*s == *p || '.' == *p) ? isMatch(s + 1, p + 1) : false;
        }
    }
bool isMatch2(const char *s, const char *p) {
        int i, j;
        int m = strlen(s);
        int n = strlen(p);

        /**
         * b[i + 1][j + 1]: if s[0..i] matches p[0..j]
         * if p[j] != '*'
         * b[i + 1][j + 1] = b[i][j] && s[i] == p[j]
         * if p[j] == '*', denote p[j - 1] with x,
         * then b[i + 1][j + 1] is true iff any of the following is true
         * 1) "x*" repeats 0 time and matches empty: b[i + 1][j -1]
         * 2) "x*" repeats 1 time and matches x: b[i + 1][j]
         * 3) "x*" repeats >= 2 times and matches "x*x": s[i] == x && b[i][j + 1]
         * '.' matches any single character
         */
        bool b[m + 1][n + 1];
        b[0][0] = true;
        for (i = 0; i < m; i++) {
            b[i + 1][0] = false;
        }
        // p[0..j - 2, j - 1, j] matches empty iff p[j] is '*' and p[0..j - 2] matches empty
        for (j = 0; j < n; j++) {
            b[0][j + 1] = j > 0 && '*' == p[j] && b[0][j - 1];
        }

        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (p[j] != '*') {
                    b[i + 1][j + 1] = b[i][j] && ('.' == p[j] || s[i] == p[j]);
                } else {
                    b[i + 1][j + 1] = b[i + 1][j - 1] && j > 0 || b[i + 1][j] ||
                                b[i][j + 1] && j > 0 && ('.' == p[j - 1] || s[i] == p[j - 1]);
                }
            }
        }
        return b[m][n];
    }
};

int main ()
{
    Solution s;
    char a[100], b[100];

    while (cin >> a >> b)
        cout << s.isMatch(a, b) << endl;

    return 0;
}


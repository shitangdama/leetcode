<<<<<<< HEAD
#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<vector<string>> ret;
    vector<string> single;

    void find_partition(string s) {
        for (int i = 1; i <= s.size(); ++i) {
            int left = 0, right = i - 1;
            // find recursive position
            while (left <= right && s[left] == s[right]) {
                ++left;
                --right;
            }
            // found then recursive
            if (left > right) {
                single.push_back(s.substr(0, i));
                if (i == s.size())
                    ret.push_back(single);
                find_partition(s.substr(i));
                single.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        find_partition(s);
        return ret;
    }
};
// LeetCode, Palindrome Partitioning
// ���棬ʱ�临�Ӷ�O(n^2)���ռ临�Ӷ�O(1)
class Solution {
public:
    vector<vector<string> > partition(string s) {
        const int n = s.size();
        bool p[n][n]; // whether s[i,j] is palindrome
        fill_n(&p[0][0], n * n, false);
        for (int i = n - 1; i >= 0; --i)
            for (int j = i; j < n; ++j)
                p[i][j] = s[i] == s[j] && ((j - i < 2) || p[i + 1][j - 1]);

        vector<vector<string> > sub_palins[n]; // sub palindromes of s[0,i]
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j)
                if (p[i][j]) {
                    const string palindrome = s.substr(i, j - i + 1);
                    if (j + 1 < n) {
                        for (auto v : sub_palins[j + 1]) {
                            v.insert(v.begin(), palindrome);
                            sub_palins[i].push_back(v);
                        }
                    } else {
                        sub_palins[i].push_back(vector<string> { palindrome });
                    }
                }
        }
        return sub_palins[0];
    }
};
//LeetCode, Palindrome Partitioning
// ʱ�临�Ӷ�O(2^n)���ռ临�Ӷ�O(n)
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path;  // һ��partition����
        DFS(s, path, result, 0);
        return result;
    }
    // ����������s[start]��ͷ��partition����
    void DFS(string &s, vector<string>& path,
            vector<vector<string>> &result, int start) {
        if (start == s.size()) {
            result.push_back(path);
            return;
        }
        for (int i = start; i < s.size(); i++) {
            if (isPalindrome(s, start, i)) { // ��iλ�ÿ�һ��
                path.push_back(s.substr(start, i - start + 1));
                DFS(s, path, result, i + 1);  // �������¿�
                path.pop_back(); // ����������
            }
        }
    }
    bool isPalindrome(const string &s, int start, int end) {
        while (start < end && s[start] == s[end]) {
            ++start;
            --end;
        }
        return start >= end;
    }
};
//LeetCode, Palindrome Partitioning
// ʱ�临�Ӷ�O(2^n)���ռ临�Ӷ�O(n)
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path;  // һ��partition����
        dfs(s, path, result, 0, 1);
        return result;
    }

    // s[0, prev-1]֮���Ѿ�������֤�ǻ��Ĵ�
    // prev ��ʾs[prev-1]��s[prev]֮��Ŀ�϶λ�ã�startͬ��
    void dfs(string &s, vector<string>& path,
            vector<vector<string>> &result, size_t prev, size_t start) {
        if (start == s.size()) { // ���һ������
            if (isPalindrome(s, prev, start - 1)) { // ����ʹ��
                path.push_back(s.substr(prev, start - prev));
                result.push_back(path);
                path.pop_back();
            }
            return;
        }
        // ���Ͽ�
        dfs(s, path, result, prev, start + 1);
        // ���[prev, start-1] �ǻ��ģ�����ԶϿ���Ҳ���Բ��Ͽ�����һ���Ѿ����ˣ�
        if (isPalindrome(s, prev, start - 1)) {
            // �Ͽ�
            path.push_back(s.substr(prev, start - prev));
            dfs(s, path, result, start, start + 1);
            path.pop_back();
        }
    }

    bool isPalindrome(const string &s, int start, int end) {
        while (start < end && s[start] == s[end]) {
            ++start;
            --end;
        }
        return start >= end;
    }
};
int main() {
    string str;
    Solution s;
    cin >> str;
    vector<vector<string>> res = s.partition(str);
    for (auto &x : res) {
        for (auto &y : x)
            cout << y << ' ';
        cout << endl;
    }
    return 0;
}

=======
#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<vector<string>> ret;
    vector<string> single;

    void find_partition(string s) {
        for (int i = 1; i <= s.size(); ++i) {
            int left = 0, right = i - 1;
            // find recursive position
            while (left <= right && s[left] == s[right]) {
                ++left;
                --right;
            }
            // found then recursive
            if (left > right) {
                single.push_back(s.substr(0, i));
                if (i == s.size())
                    ret.push_back(single);
                find_partition(s.substr(i));
                single.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        find_partition(s);
        return ret;
    }
};
// LeetCode, Palindrome Partitioning
// ���棬ʱ�临�Ӷ�O(n^2)���ռ临�Ӷ�O(1)
class Solution {
public:
    vector<vector<string> > partition(string s) {
        const int n = s.size();
        bool p[n][n]; // whether s[i,j] is palindrome
        fill_n(&p[0][0], n * n, false);
        for (int i = n - 1; i >= 0; --i)
            for (int j = i; j < n; ++j)
                p[i][j] = s[i] == s[j] && ((j - i < 2) || p[i + 1][j - 1]);

        vector<vector<string> > sub_palins[n]; // sub palindromes of s[0,i]
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j)
                if (p[i][j]) {
                    const string palindrome = s.substr(i, j - i + 1);
                    if (j + 1 < n) {
                        for (auto v : sub_palins[j + 1]) {
                            v.insert(v.begin(), palindrome);
                            sub_palins[i].push_back(v);
                        }
                    } else {
                        sub_palins[i].push_back(vector<string> { palindrome });
                    }
                }
        }
        return sub_palins[0];
    }
};
//LeetCode, Palindrome Partitioning
// ʱ�临�Ӷ�O(2^n)���ռ临�Ӷ�O(n)
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path;  // һ��partition����
        DFS(s, path, result, 0);
        return result;
    }
    // ����������s[start]��ͷ��partition����
    void DFS(string &s, vector<string>& path,
            vector<vector<string>> &result, int start) {
        if (start == s.size()) {
            result.push_back(path);
            return;
        }
        for (int i = start; i < s.size(); i++) {
            if (isPalindrome(s, start, i)) { // ��iλ�ÿ�һ��
                path.push_back(s.substr(start, i - start + 1));
                DFS(s, path, result, i + 1);  // �������¿�
                path.pop_back(); // ����������
            }
        }
    }
    bool isPalindrome(const string &s, int start, int end) {
        while (start < end && s[start] == s[end]) {
            ++start;
            --end;
        }
        return start >= end;
    }
};
//LeetCode, Palindrome Partitioning
// ʱ�临�Ӷ�O(2^n)���ռ临�Ӷ�O(n)
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path;  // һ��partition����
        dfs(s, path, result, 0, 1);
        return result;
    }

    // s[0, prev-1]֮���Ѿ�������֤�ǻ��Ĵ�
    // prev ��ʾs[prev-1]��s[prev]֮��Ŀ�϶λ�ã�startͬ��
    void dfs(string &s, vector<string>& path,
            vector<vector<string>> &result, size_t prev, size_t start) {
        if (start == s.size()) { // ���һ������
            if (isPalindrome(s, prev, start - 1)) { // ����ʹ��
                path.push_back(s.substr(prev, start - prev));
                result.push_back(path);
                path.pop_back();
            }
            return;
        }
        // ���Ͽ�
        dfs(s, path, result, prev, start + 1);
        // ���[prev, start-1] �ǻ��ģ�����ԶϿ���Ҳ���Բ��Ͽ�����һ���Ѿ����ˣ�
        if (isPalindrome(s, prev, start - 1)) {
            // �Ͽ�
            path.push_back(s.substr(prev, start - prev));
            dfs(s, path, result, start, start + 1);
            path.pop_back();
        }
    }

    bool isPalindrome(const string &s, int start, int end) {
        while (start < end && s[start] == s[end]) {
            ++start;
            --end;
        }
        return start >= end;
    }
};
int main() {
    string str;
    Solution s;
    cin >> str;
    vector<vector<string>> res = s.partition(str);
    for (auto &x : res) {
        for (auto &y : x)
            cout << y << ' ';
        cout << endl;
    }
    return 0;
}

>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74

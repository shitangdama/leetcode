#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    const string alpha[10] = {
        " ",
        "1", "abc", "def",
        "ghi", "jkl", "mno",
        "pqrs", "tuv", "wxyz"
    };
    void dfs(vector<string> &res, string &ab, string &digits, int cur) {
        if (cur >= digits.length()) {
            res.push_back(ab);
            return;
        }
        for (auto &a : alpha[digits[cur] - '0']) {
	  //使用了智能指针，不符合google编程规范
	    ab.push_back(a);
            dfs(res, ab, digits, cur + 1);
            ab.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string alphas;
        dfs(res, alphas, digits, 0);
        return res;
    }
};

int main() {
    string d;
    Solution s;
    while (cin >> d) {
        vector<string> res = s.letterCombinations(d);
        for (auto &i : res) {
            for (auto &j : i)
                cout << j;
            cout << ' ';
        }
        cout << endl;
    }
    return 0;
}


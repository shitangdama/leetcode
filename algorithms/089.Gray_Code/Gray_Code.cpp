<<<<<<< HEAD
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        const size_t sz = 1<<n;
        vector<int> res(sz);
        for (size_t i = 0; i < sz; ++i)
            res[i] = (i ^ (i>>1));
        return res;
    }
};

int main() {
    int n;
    Solution s;
    while (cin >> n) {
        vector<int> res = s.grayCode(n);
        for (auto &i : res)
            cout << i << ' ';
        cout << endl;
    }
    return 0;
}

=======
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        const size_t sz = 1<<n;
        vector<int> res(sz);
        for (size_t i = 0; i < sz; ++i)
            res[i] = (i ^ (i>>1));
        return res;
    }
};

int main() {
    int n;
    Solution s;
    while (cin >> n) {
        vector<int> res = s.grayCode(n);
        for (auto &i : res)
            cout << i << ' ';
        cout << endl;
    }
    return 0;
}

>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74

<<<<<<< HEAD
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string ret = "";
        --n;
        while (n >= 0) {
            ret += (char)('A' + n % 26);
            n /= 26;
            --n;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

class Solution {
 public:
  string convertToTitle(int n) {
    string result;
    while(n >= 1) {
      result.push_back((n - 1) % 26 + 'A');
      n = (n - 1) / 26;
    }
    reverse(result.begin(), result.end());
    return result;
  }
};
class Solution {
 public:
  string convertToTitle(int n) {
    string result;
    while(n >= 1) {
      result.push_back((n - 1) % 26 + 'A');
      n = (n - 1) / 26;
    }
    reverse(result.begin(), result.end());
    return result;
  }
};
int main() {
    int n;
    Solution s;
    while (cin >> n)
        cout << s.convertToTitle(n) << endl;
    return 0;
}

=======
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string ret = "";
        --n;
        while (n >= 0) {
            ret += (char)('A' + n % 26);
            n /= 26;
            --n;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

class Solution {
 public:
  string convertToTitle(int n) {
    string result;
    while(n >= 1) {
      result.push_back((n - 1) % 26 + 'A');
      n = (n - 1) / 26;
    }
    reverse(result.begin(), result.end());
    return result;
  }
};
class Solution {
 public:
  string convertToTitle(int n) {
    string result;
    while(n >= 1) {
      result.push_back((n - 1) % 26 + 'A');
      n = (n - 1) / 26;
    }
    reverse(result.begin(), result.end());
    return result;
  }
};
int main() {
    int n;
    Solution s;
    while (cin >> n)
        cout << s.convertToTitle(n) << endl;
    return 0;
}

>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74

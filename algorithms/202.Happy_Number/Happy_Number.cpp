#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> vis;

        while (vis.find(n) == vis.end()) {
            vis.insert(n);
            int tmp = 0;
            while (n) {
                tmp += (n%10) * (n%10);
                n /= 10;
            }
            n = tmp;
            if (n == 1)
                return true;
        }

        return false;
    }
};
class Solution {
 public:
  int sum(int n) {
    int r = 0;
    while(n) {
      int digit = n % 10;
      r += digit * digit;
      n /= 10;
    }
    return r;
  }
  bool isHappy(int n) {
    unordered_set<int> S;
    while(n != 1) {
      int v = sum(n);
      if(S.count(v)) return false;
      S.insert(v);
      n = v;
    }
    return true;
  }
};
class Solution {
public:
   int digitSquareSum(int n) {
    int sum = 0, tmp;
    while (n) {
        tmp = n % 10;
        sum += tmp * tmp;
        n /= 10;
    }
    return sum;
}

bool isHappy(int n) {
    int slow, fast;
    slow = fast = n;
    do {
        slow = digitSquareSum(slow);
        fast = digitSquareSum(fast);
        fast = digitSquareSum(fast);
    } while(slow != fast);
    if (slow == 1) return 1;
    else return 0;
}
};
int main() {
    Solution s;
    int n;
    for (n = 0; n < 10000; ++n) {
        if (s.isHappy(n))
            cout << n << ", ";
    }
    return 0;
}


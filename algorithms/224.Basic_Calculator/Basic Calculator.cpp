#include <bits/stdc++.h>

using namespace std;
 
class Solution {
 public:
  int cal(int a, int b, char op) {
    if(op == '-') return a - b;
    return a + b;
  }
  int calculate(string s) {
    stack<int> num_stk;
    stack<char> op_stk;
    int value = 0;
    char op = '+';
    for(size_t i = 0; i < s.size(); ++i) {
      if(isdigit(s[i])) {
        string tmp;
        while(isdigit(s[i])) {
          tmp += s[i];
          i += 1;
        }
        i -= 1;
        value = cal(value, stoi(tmp), op);
      } else if(s[i] == '+' || s[i] == '-') {
        op = s[i];

      } else if(s[i] == '(') {
        num_stk.push(value);
        op_stk.push(op);
        value = 0;
        op = '+';
      } else if(s[i] == ')') {
        op = op_stk.top();
        op_stk.pop();
        value = cal(num_stk.top(), value, op);
        num_stk.pop();
      } else {
        // bad input case
      }
    }
    return value;
  }

};
class Solution {
public:
    int calculate(string s) {
        // the given expression is always valid!!!
        // only + and - !!!
        // every + and - can be flipped base on it's depth in ().
        stack<int> signs;
        int sign = 1;
        int num = 0;
        int ans = 0;

        // always transform s into ( s )
        signs.push(1);

        for (auto c : s) {
            if (c >= '0' && c <= '9') {
                num = 10 * num + c - '0';
            } else if (c == '+' || c == '-') {
                ans = ans + signs.top() * sign * num;
                num = 0;
                sign = (c == '+' ? 1 : -1);
            } else if (c == '(') {
                signs.push(sign * signs.top());
                sign = 1;
            } else if (c == ')') {
                ans = ans + signs.top() * sign * num;
                num = 0;
                signs.pop();
                sign = 1;
            }
        }

        if (num) {
            ans = ans + signs.top() * sign * num;
        }

        return ans;
    }
};
class Solution {
public:
    int calculate(string s) {
        stack <int> nums, ops;
        int num = 0;
        int rst = 0;
        int sign = 1;
        for (char c : s) { 
            if (isdigit(c)) {
                num = num * 10 + c - '0';
            }
            else {
                rst += sign * num;
                num = 0;
                if (c == '+') sign = 1;
                if (c == '-') sign = -1;
                if (c == '(') {
                    nums.push(rst);
                    ops.push(sign);
                    rst = 0;
                    sign = 1;
                }
                if (c == ')' && ops.size()) {
                    rst = ops.top() * rst + nums.top();
                    ops.pop(); nums.pop();
                }
            }
        }
        rst += sign * num;
        return rst;
    }
};
int calculate(string s) {
    int total = 0;
    vector<int> signs(2, 1);
    for (int i=0; i<s.size(); i++) {
        char c = s[i];
        if (c >= '0') {
            int number = 0;
            while (i < s.size()  &&  s[i] >= '0')
                number = 10 * number + s[i++] - '0';
            total += signs.back() * number;
            signs.pop_back();
            i--;
        }
        else if (c == ')')
            signs.pop_back();
        else if (c != ' ')
            signs.push_back(signs.back() * (c == '-' ? -1 : 1));
    }
    return total;
}
int main() {

    return 0;
}


/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        AC_stack_n.cpp
*  Create Date: 2015-03-15 15:53:45
*  Descripton:  Using stack && atoi
*/

#include <bits/stdc++.h>

using namespace std;
const int N = 0;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> stk;
        string op = "+-*/";
        for (auto str : tokens) {
            auto pos = op.find(str);
            if (pos == string::npos) {
                stk.push(atoi(str.c_str()));
            } else {
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                if (pos == 0)
                    stk.push(b + a);
                else if (pos == 1)
                    stk.push(b - a);
                else if (pos == 2)
                    stk.push(b * a);
                else if (pos == 3)
                    stk.push(b / a);
            }
        }
        return stk.top();
    }
};
// LeetCode, Evaluate Reverse Polish Notation
// 递归，时间复杂度O(n)，空间复杂度O(logn)
class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        int x, y;
        auto token = tokens.back();  tokens.pop_back();
        if (is_operator(token))  {
            y = evalRPN(tokens);
            x = evalRPN(tokens);
            if (token[0] == '+')       x += y;
            else if (token[0] == '-')  x -= y;
            else if (token[0] == '*')  x *= y;
            else                       x /= y;
        } else  {
            size_t i;
            x = stoi(token, &i);
        }
        return x;
    }
private:
    bool is_operator(const string &op) {
        return op.size() == 1 && string("+-*/").find(op) != string::npos;
    }
};
// LeetCode, Max Points on a Line
// 迭代，时间复杂度O(n)，空间复杂度O(logn)
class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<string> s;
        for (auto token : tokens) {
            if (!is_operator(token)) {
                s.push(token);
            } else {
                int y = stoi(s.top());
                s.pop();
                int x = stoi(s.top());
                s.pop();
                if (token[0] == '+')       x += y;
                else if (token[0] == '-')  x -= y;
                else if (token[0] == '*')  x *= y;
                else                       x /= y;
                s.push(to_string(x));
            }
        }
        return stoi(s.top());
    }
private:
    bool is_operator(const string &op) {
        return op.size() == 1 && string("+-*/").find(op) != string::npos;
    }
};

int main() {

    return 0;
}


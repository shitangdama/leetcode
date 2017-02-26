#include <bits/stdc++.h>

class MinStack {
private:
    stack<int> stk;
    stack<int> mstk;
public:
    void push(int x) {
        if (mstk.empty() || x <= mstk.top())
            mstk.push(x);
        stk.push(x);
    }

    void pop() {
        if (stk.top() == mstk.top())
            mstk.pop();
        stk.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return mstk.top();
    }
};

class MinStack {
public:
    stack<int> stk, minstk;

    void push(int number) {
        stk.push(number);
        if (minstk.empty() or number <= minstk.top()) {
            minstk.push(number);
        }
    }

    int pop() {
        int top = stk.top();
        stk.pop();
        if (top == minstk.top()) {
            minstk.pop();
        }
        return top;
    }

    int min() {
        return minstk.top();
    }
};

int main() {

    return 0;
}


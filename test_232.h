//
// Created by zhaobo on 2022/2/8.
//

#ifndef LEETCODE_TEST_232_H
#define LEETCODE_TEST_232_H
#include <stack>
#include <iostream>

using namespace std;

class MyQueue {
public:
    MyQueue() = default;

    ~MyQueue() = default;

    void push(int x) {
        stk_a.push(x);
    }

    int pop() {
        if (stk_b.empty()) {
            while (!stk_a.empty()) {
                stk_b.push(stk_a.top());
                stk_a.pop();
            }
        }
        int ret = stk_b.top();
        stk_b.pop();
        return ret;
    }

    int peek() {
        if (stk_b.empty()) {
            while (!stk_a.empty()) {
                stk_b.push(stk_a.top());
                stk_a.pop();
            }
        }
        return stk_b.top();
    }

    bool empty() {
        return stk_a.empty() && stk_b.empty();
    }

    stack<int> stk_a;
    stack<int> stk_b;
};

#endif //LEETCODE_TEST_232_H

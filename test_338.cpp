//
// Created by zhaobo on 2022/2/24.
//
#include <vector>
#include <iostream>
using namespace std;

/*
 1、如果 i 为偶数，那么f(i) = f(i/2) ,因为 i/2 本质上是i的二进制左移一位，低位补零，所以1的数量不变。
 2、如果 i 为奇数，那么f(i) = f(i - 1) + 1， 因为如果i为奇数，那么 i - 1必定为偶数，而偶数的二进制最低位一定是0，
    那么该偶数 +1 后最低位变为1且不会进位，所以奇数比它上一个偶数bit上多一个1，即 f(i) = f(i - 1) + 1。
*/

vector<int> countBits(int n) {
    int i = 1;
    vector<int> ans(n+1);
    for (size_t i = 0; i <= n; ++i) {
        if (i % 2 == 0) {
            ans[i] = ans[i/2];
        } else {
            ans[i] = ans[i-1] + 1;
        }
    }
    return ans;
}

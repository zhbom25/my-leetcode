//
// Created by zhaobo on 2022/3/7.
//
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    /*
    // 方法一：动态规划
    int uniquePaths(int m, int n) {
        if (m ==0 || n == 0) {
            return 0;
        }
        if (m == 1 && n == 1) {
            return 1;
        }
        vector<vector<int>> vec(m, vector<int>(n, 0));
        for (int i = 1; i < m; i++) {
            vec[i][0] = 1;
        }
        for (int i = 1; i < n; i++) {
            vec[0][i] = 1;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                vec[i][j] = vec[i-1][j] + vec[i][j-1];
            }
        }
        return vec[m-1][n-1];
    }
    */
    // 方法二：递归，超时
    /*
    int uniquePaths(int m, int n) {
        if (m == 0 && n == 0) {
            return 0;
        }
        if (m == 1 && n == 1) {
            return 1;
        }
        if (m > 1 && n > 1) {
            return uniquePaths(m-1, n) + uniquePaths(m, n-1);
        } else if (m > 1) {
            return uniquePaths(m-1, 1);
        } else if (n > 1) {
            return uniquePaths(1, n-1);
        }
        return 0;
    }
    */
    // 方法三：数学
    // 机器人一定会走 m+n-2步，即从m+n-2中挑m-1步向下走，即 C((m+n-2), (m-1))
    // 直接计算分子、分母乘积，会溢出
    int uniquePaths(int m, int n) {
        long long numerator = 1;    // 分子
        int denominator = m-1;      // 分母
        int count = m-1;
        int t = m + n - 2;
        while (count--) {
            numerator *= (t--);
            while (denominator != 0 && numerator % denominator == 0) {
                numerator /= denominator;
                denominator--;
            }
        }
        return numerator;
    }
};

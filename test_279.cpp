//
// Created by zhaobo on 2022/3/6.
//
#include <cmath>
class Solution {
public:
    // 待调试
    /*
    int numSquares(int n) {
        if (_isSquare(n)) return 1;
        int min = n;
        for (int i = 1; i <= n/2; i++) {
            int _f = i, _e = n-i;
            int num = numSquares(_f) + numSquares(_e);
            if (num < min) {
                min = num;
            }
        }
        return min;
    }

    bool _isSquare(int n) {
        if (n == 0) return true;
        int i = 1;
        while (n >= 0) {
            n -= i;
            i += 2;
        }
        if (n == 0) return true;
        else return false;
    }
    */
    // 版本一 动态规划
    /*
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i <= n; i++) { // 遍历背包
            for (int j = 1; j * j <= i; j++) { // 遍历物品
                dp[i] = min(dp[i - j * j] + 1, dp[i]);
            }
        }
        return dp[n];
    }
    */
    // 方法二：数学定理
    /*
     1. 任何正整数都可以拆分成不超过4个数的平方和 ---> 答案只可能是1,2,3,4
     2. 如果一个数最少可以拆成4个数的平方和，则这个数还满足 n = (4^a)*(8b+7)
        ---> 因此可以先看这个数是否满足上述公式，如果不满足，答案就是1,2,3了
     3. 如果这个数本来就是某个数的平方，那么答案就是1，否则答案就只剩2,3了
     4. 如果答案是2，即n=a^2+b^2，那么我们可以枚举a，来验证，如果验证通过则答案是2
     5. 只能是3
     */
    int numSquares(int n) {
        //先根据上面提到的公式来缩小n
        while(n % 4 == 0) {
            n /= 4;
        }
        //如果满足公式 则返回4
        if(n % 8 == 7) {
            return 4;
        }
        //在判断缩小后的数是否可以由一个数的平方或者两个数平方的和组成
        int a = 0;
        while ((a * a) <= n) {
            int b = sqrt((n - a * a));
            if(a * a + b * b == n) {
                //如果可以 在这里返回
                if(a != 0 && b != 0) {
                    return 2;
                } else{
                    return 1;
                }
            }
            a++;
        }
        //如果不行 返回3
        return 3;
    }
};

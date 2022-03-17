//
// Created by zhaobo on 2022/3/4.
//
#include "TreeNode.h"

class Solution {
public:
    /*
    // 待优化
    // 动态规划：f(n) = min(f(n-c1), f(n-c2), ... f(n-cn)) + 1
    int coinChange(vector<int>& coins, int amount) {
        int ret = _coinChange(coins, amount);
        if (ret == INT_MAX) return -1;
        return ret;
    }

    int _coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        vector<int> dp(coins.size(), INT_MAX);
        for (size_t i = 0; i < coins.size(); i++) {
            if (amount == coins[i]) {
                dp[i] = 0;
            } else if (amount > coins[i]) {
                dp[i] = _coinChange(coins, amount-coins[i]);
            }
        }
        int min = dp[0];
        for (auto val : dp) {
            min = (val < min) ? val : min;
        }
        if (min == INT_MAX) {
            return INT_MAX;
        } else {
            return min + 1;
        }
    }
     */
    int coinChange(vector<int> coins, int amount)
    {
        if (coins.empty()) {
            return -1;
        }
        vector<int> dp(amount+1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < coins.size(); i++) {
            for (int j = coins[i]; j <= amount; j++) {
                if (dp[j - coins[i]] != INT_MAX) {
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
                }
            }
        }
        if (dp[amount] != INT_MAX) {
            return dp[amount];
        }
        return -1;
    }
};

// [1,2,5] 11
int main(int argc, char** argv) {
    vector<int> vec = {1, 2, 5};
    Solution *solution = new Solution();
    int ret = solution->coinChange(vec, 100);
    cout << "ret : " << ret << endl;
    return 0;
}

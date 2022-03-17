//
// Created by zhaobo on 2022/3/4.
//
#include "TreeNode.h"

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1);
        dp[0] = 1;
        for (int coin : coins) {
            for (int j = coin; j <= amount; j++) {
                dp[j] = dp[j] + dp[j-coin];
            }
        }
        return dp[amount];
    }
};

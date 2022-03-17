//
// Created by zhaobo on 2022/3/2.
//
#include "TreeNode.h"

// 获取二叉树最小高度
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        int l_d = minDepth(root->left);
        int r_d = minDepth(root->right);
        if (l_d > 0 && r_d > 0) {
            return (l_d < r_d) ? (1 + l_d) : (1 + r_d);
        } else {
            return 1 + l_d + r_d;
        }
    }
};

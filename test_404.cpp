//
// Created by zhaobo on 2022/3/2.
//
#include "TreeNode.h"

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) return 0;
        int res = 0;
        // 判断节点是否为左叶子节点
        if (root->left != nullptr && root->left->left == nullptr && root->left->right == null) {
            res += root->left->val;
        }
        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right) + res;
    }
};

//
// Created by zhaobo on 2022/3/2.
//
#include "TreeNode.h"

// 获取二叉树最大高度
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return getMax(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
private:
    template <typename T>
    int getMax(const T& a, const T& b)
    {
        return a > b ? a : b;
    }
};

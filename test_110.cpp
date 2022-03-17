//
// Created by zhaobo on 2022/3/2.
//
#include "TreeNode.h"

// 判断二叉树是否是平衡二叉树
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return _geHeight(root) >= 0;
    }

    int _geHeight(TreeNode* root)
    {
        if (root == nullptr) {
            return 0;
        }
        int l_h = _geHeight(root->left);
        int r_h = _geHeight(root->right);
        if (l_h >= 0 && r_h >= 0 && abs(l_h - r_h) <= 1) {
            return (l_h > r_h) ? (l_h + 1) : (r_h + 1);
        } else {
            return -1;
        }
    }
};

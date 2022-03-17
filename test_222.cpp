//
// Created by zhaobo on 2022/3/2.
//

#include "TreeNode.h"

/*
// 方法一：递归遍历
int countNodes(TreeNode* root)
{
    if (root == nullptr) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}
 */

int getDepth(TreeNode* node);

// 方法二：根据满二叉树性质求取
int countNodes(TreeNode* root)
{
    if (root == nullptr) {
        return 0;
    }
    int left_h = getDepth(root->left);
    int right_h = getDepth(root->right);
    if (left_h == right_h) {
        return (1<<left_h) + countNodes(root->right);  // ( 2^n-1 + 1 (根节点) + 右子树节点总数)
    } else {
        return (1<<right_h) + countNodes(root->left);
    }
}

int getDepth(TreeNode* node)
{
    int depth = 0;
    while (node != nullptr) {
        depth++;
        node = node->left;
    }
    return depth;
}

//
// Created by zhaobo on 2022/3/3.
//
#include "TreeNode.h"

class Solution {
public:
    /*
    // 方法一：任意二叉树均可满足
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q) {
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left == nullptr && right == nullptr) {
            return nullptr;
        } else if (left != nullptr && right != nullptr) {
            return root;
        } else if (left != nullptr){
            return left;
        } else {
            return right;
        }
    }
    */

    // 方法二：利用二叉搜索树性质
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val < root->val && q->val < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        if (p->val > root->val && q->val > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }
};

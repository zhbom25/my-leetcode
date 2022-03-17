//
// Created by zhaobo on 2022/3/2.
//
#include "TreeNode.h"

class Solution {
public:
    /*
     // 方法一：先求得左右子树高度，取较高的继续求最左节点
    int findBottomLeftValue(TreeNode* root) {
        if (root == nullptr) return 0;
        if (root->left == nullptr && root->right == nullptr) {
            return root->val;
        }
        int l_d = _getDepth(root->left);
        int r_d = _getDepth(root->right);
        if (l_d >= r_d) {
            return findBottomLeftValue(root->left);
        } else {
            return findBottomLeftValue(root->right);
        }
    }

    int _getDepth(TreeNode* node)
    {
        if (node == nullptr) return 0;
        if (node->left == nullptr && node->right == nullptr) return 1;
        int l_d = _getDepth(node->left);
        int r_d = _getDepth(node->right);
        return (l_d > r_d) ? l_d+1 : r_d+1;
    }
    */

    // 方法二：深度优先遍历
    int max = -1;
    int res = 0;
    int findBottomLeftValue(TreeNode* root) {
        dfs(root, 0);
        return res;
    }

    void dfs(TreeNode* root, int depth) {
        if (root != nullptr) {
            if (root->left == nullptr && root->right == nullptr) {
                if (max < depth) {
                    max = depth;
                    res = root->val;
                }
            }
            dfs(root->left, depth+1);
            dfs(root->right, depth+1);
        }
    }
};

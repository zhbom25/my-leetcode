//
// Created by zhaobo on 2022/3/2.
//

#include "TreeNode.h"

// 备注：平衡树删除节点，极为经典
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return nullptr;
        if (key < root->val) {
            // 待删除节点在左子树中
            root->left = deleteNode(root->left, key);
            return root;
        } else if (key > root->val) {
            // 待删除节点在右子树中
            root->right = deleteNode(root->right, key);
            return root;
        } else {
            // key == root->val, root为待删除节点
            if (root->left == nullptr) {
                return root->right;
            } else if (root->right == nullptr) {
                return root->left;
            } else {
                // 左右子树都存在，返回后继节点（右子树最左叶子）作为新的根
                TreeNode* successor = min(root->right);
                root->val = successor->val;
                root->right = deleteMin(root->right);
                return root;
            }
        }
    }

    TreeNode* min(TreeNode* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    // 递归删除左子树最左边叶子节点
    TreeNode* deleteMin(TreeNode* node) {
        if (node->left == nullptr) {
            return node->right;
        }
        node->left = deleteMin(node->left);
        return node;
    }
};

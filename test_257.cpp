//
// Created by zhaobo on 2022/3/2.
//
#include "TreeNode.h"

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret;
        if (root == nullptr) return ret;
        if (root->left == nullptr && root->right == nullptr) {
            ret.push_back(to_string(root->val));
        }
        if (root->left != nullptr) {
            vector<string> vec_l = binaryTreePaths(root->left);
            for (auto val : vec_l) {
                ret.push_back(to_string(root->val) + "->" + val);
            }
        }
        if (root->right != nullptr) {
            vector<string> vec_r = binaryTreePaths(root->right);
            for (auto val : vec_r) {
                ret.push_back(to_string(root->val) + "->" + val);
            }
        }
        return ret;
    }
};

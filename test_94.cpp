//
// Created by zhaobo on 2022/2/25.
//
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    /* 方法一：递归
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret_vec;
        _inorderTra(root, ret_vec);
        return ret_vec;
    }

    void _inorderTra(TreeNode* root, vector<int>& ret) {
        if (root != nullptr) {
            if (root->left != nullptr) {
                _inorderTra(root->left, ret);
            }
            ret.push_back(root->val);
            if (root->right != nullptr) {
                _inorderTra(root->right, ret);
            }
        }
    }
    */
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> ret_vec;
        TreeNode* cur = root;
        while (cur != nullptr || !stk.empty()) {
            if (cur != nullptr) {
                stk.push(cur);
                cur = cur->left;
            } else {
                cur = stk.top();
                stk.pop();
                ret_vec.push_back(cur->val);
                cur = cur->right;
            }
        }
        return ret_vec;
    }
};

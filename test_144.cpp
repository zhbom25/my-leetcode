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
    val val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    /*
     * 递归方法
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret_vec;
        _pre_tra(root, ret_vec);
        return ret_vec;
    }

    void _pre_tra(TreeNode* root, vector<int>& ret) {
        if (root != nullptr) {
            ret.push_back(root->val);
        } else {
            return;
        }
        if (root->left != nullptr) {
            _pre_tra(root->left, ret);
        }
        if (root->right != nullptr) {
            _pre_tra(root->right, ret);
        }
    }
    */
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode* r = s.top();
            s.pop();
            if (r == nullptr) continue;
            ans.push_back(r->val);
            s.push(r->right);
            s.push(r->left);
        }
        return ans;
    }
};

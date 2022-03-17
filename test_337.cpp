//
// Created by zhaobo on 2022/3/7.
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

#include "TreeNode.h"
#include <vector>

using namespace std;

struct RetVal {
    int first;
    int second;
    RetVal() : first(0), second(0) {}
};

class Solution {
public:
    int rob(TreeNode* root) {
        RetVal cur = _rob(root);
        return max(cur.first, cur.second);
    }

    RetVal _rob(TreeNode* root) {
        RetVal retVal;
        if (root == nullptr) {
            return retVal;
        }
        RetVal left = _rob(root->left);
        RetVal right = _rob(root->right);
        RetVal cur;
        cur.first = root->val + left.second + right.second;
        cur.second = max(left.first, left.second) + max(right.first, right.second);
        return cur;
    }
    /*
    int rob(TreeNode* root) {
        pair<int, int> _pair = _rob(root);
        return max(_pair.first, _pair.second);
    }

    pair<int,int> _rob(TreeNode* root) {
        if (root == nullptr) {
            return make_pair(0, 0);
        }
        pair<int, int> cur, left, right;
        left = _rob(root->left);
        right = _rob(root->right);
        cur.first = max(left.first, left.second) + max(right.first, right.second);
        cur.second = root->val + left.first + right.first;
        return cur;
    }
    */
};

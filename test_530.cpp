//
// Created by zhaobo on 2022/3/3.
//
#include "TreeNode.h"

class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr) {
            return INT_MAX;
        } else if (root->left != nullptr && root->right == nullptr) {
            int left_max = _getMaxVal(root->left);
            int l_d = root->val - left_max;
            int min_left = getMinimumDifference(root->left);
            /*
            cout << "left_max: " << left_max << endl;
            cout << "l_d: " << l_d << endl;
            cout << "min_left: " << min_left << endl;
             */
            return _min(l_d, min_left);
        } else if (root->left == nullptr && root->right != nullptr) {
            int right_min = _getMinVal(root->right);
            int r_d = right_min - root->val;
            int min_right = getMinimumDifference(root->right);
            return _min(r_d, min_right);
        } else {
            int left_max = _getMaxVal(root->left);
            int right_min = _getMinVal(root->right);
            int l_d = root->val - left_max;
            int r_d = right_min - root->val;
            int min = _min(l_d, r_d);
            int min_left = getMinimumDifference(root->left);
            int min_right = getMinimumDifference(root->right);
            /*
            cout << "min: " << min << endl;
            cout << "min_left: " << min_left << endl;
            cout << "min_right: " << min_right << endl;
             */
            return _min(min, min_left, min_right);
        }
        return INT_MAX;
    }

private:
    int _getMaxVal(TreeNode* node) {
        while (node->right != nullptr) {
            node = node->right;
        }
        return node->val;
    }

    int _getMinVal(TreeNode* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node->val;
    }

    int _min(int a, int b) {
        return (a > b) ? b : a;
    }

    int _min(int a, int b, int c) {
        return _min(_min(a, b), c);
    }
};

// [1564,1434,3048,1,null,null,3184]
int main(int argc, char** argv)
{
    /*
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(3);
    TreeNode* node3 = new TreeNode(2);
    node1->right = node2;
    node2->left = node3;
     */
    TreeNode* node1 = new TreeNode(1564);
    TreeNode* node2 = new TreeNode(1434);
    TreeNode* node3 = new TreeNode(3048);
    TreeNode* node4 = new TreeNode(1);
    TreeNode* node5 = new TreeNode(3184);
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node3->right = node5;
    Solution* solution = new Solution();
    int _min = solution->getMinimumDifference(node1);
    cout << "min : " << _min << endl;
    return 0;
}

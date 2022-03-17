//
// Created by zhaobo on 2022/3/2.
//
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int _val) : val(_val), left(nullptr), right(nullptr) {}
    TreeNode(int _val, TreeNode* _left, TreeNode* _right) : val(_val),
    left(_left), right(_right) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == nullptr) return;
        flatten(root->left);
        TreeNode* right = root->right;
        root->right = root->left;
        root->left = nullptr;
        while (root->right != nullptr) {
            root = root->right;
        }
        root->right = right;
        flatten(root->right);
    }
};

void print_v(TreeNode* root)
{
    while (root != nullptr) {
        cout << root->val << endl;
        root = root->right;
    }
    return;
}

int main(int argc, char** argv)
{
    TreeNode* treeNode1 = new TreeNode(1);
    TreeNode* treeNode2 = new TreeNode(2);
    TreeNode* treeNode3 = new TreeNode(3);
    TreeNode* treeNode4 = new TreeNode(4);
    TreeNode* treeNode5 = new TreeNode(5);
    TreeNode* treeNode6 = new TreeNode(6);
    TreeNode* treeNode7 = new TreeNode(7);
    TreeNode* treeNode8 = new TreeNode(8);
    treeNode1->left = treeNode2;
    treeNode1->right = treeNode3;
    treeNode2->left = treeNode4;
    treeNode2->right = treeNode5;
    treeNode3->left = treeNode6;
    treeNode3->right = treeNode7;
    treeNode4->left = treeNode8;
    Solution* solution = new Solution();
    solution->flatten(treeNode1);
    print_v(treeNode1);
    return 0;
}

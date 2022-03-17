//
// Created by zhaobo on 2022/3/2.
//
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
    int num = 0;
    TreeNode* convertBST(TreeNode* root) {
        if (root != nullptr) {
            convertBST(root->right);
            root->val = root->val + num;
            num = root->val;
            convertBST(root->left);
            return root;
        }
        return nullptr;
    }
};

#include <vector>
#include <queue>
#include <iostream>

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
    vector<int> rightSideView(TreeNode *root) {
        vector<vector<int>> tmp = levelOrder(root);
        vector<int> ret;
        for (auto val : tmp) {
            ret.push_back(val.back());
        }
        return ret;
    }

    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> vec_ret;
        vector<int> a;
        queue<TreeNode *> que;
        if (root == nullptr) {
            return vec_ret;
        }
        que.push(root);
        while (!que.empty()) {
            TreeNode *cur;
            queue<TreeNode *> nextLevel;
            while (!que.empty()) {
                cur = que.front();
                que.pop();
                a.push_back(cur->val);
                if (cur->left != nullptr) {
                    nextLevel.push(cur->left);
                }
                if (cur->right != nullptr) {
                    nextLevel.push(cur->right);
                }
            }
            vec_ret.push_back(a);
            que = nextLevel;
            a.clear();
        }
        return vec_ret;
    }
};

template<typename T>
void print_v(const T& container) {
    for (auto val : container) {
        cout << "val : " << val << endl;
    }
}

int main(int argc, char** argv)
{
    TreeNode* root = new TreeNode(1);
    TreeNode* node1 = new TreeNode(2);
    TreeNode* node2 = new TreeNode(3);
    TreeNode* node3 = new TreeNode(5);
    TreeNode* node4 = new TreeNode(4);
    root->left = node1;
    root->right = node2;
    node1->right = node3;
    node2->right = node4;
    Solution* solution = new Solution();
    vector<int> ret = solution->rightSideView(root);
    print_v(ret);
    return 0;
}

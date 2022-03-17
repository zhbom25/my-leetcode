//
// Created by zhaobo on 2022/2/25.
//
// 前中后遍历统一版迭代写法（只用移动左中右的顺序即可）
// 在node节点入栈后加入一个nullptr
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

// 前序遍历
vector<int> preorderTraversal(TreeNode* root) {
    if(!root) return {};
    vector<int> result;
    stack<TreeNode*> stk;
    stk.push(root);
    while(!stk.empty()){
        TreeNode* node = stk.top();
        stk.pop();
        if(node){
            if(node -> right){
                stk.push(node -> right);
            }
            if(node -> left){
                stk.push(node -> left);
            }
            stk.push(node);
            stk.push(nullptr);
        }else{
            result.push_back(stk.top()->val);
            stk.pop();
        }
    }
    return result;
}

// 中序遍历
vector<int> inorderTraversal(TreeNode* root) {
    if(!root) return {};
    vector<int> result;
    stack<TreeNode*> stk;
    stk.push(root);
    while(!stk.empty()){
        TreeNode* node = stk.top();
        stk.pop();
        if(node){
            if(node -> right){
                stk.push(node -> right);
            }
            stk.push(node);
            stk.push(nullptr);
            if(node -> left){
                stk.push(node -> left);
            }
        }else{
            result.push_back(stk.top()->val);
            stk.pop();
        }
    }
    return result;
}

// 后序遍历
vector<int> postorderTraversal(TreeNode* root) {
    if(!root) return {};
    vector<int> result;
    stack<TreeNode*> stk;
    stk.push(root);
    while(!stk.empty()){
        TreeNode* node = stk.top();
        stk.pop();
        if(node){
            stk.push(node);
            stk.push(nullptr);
            if(node -> right){
                stk.push(node -> right);
            }
            if(node -> left){
                stk.push(node -> left);
            }
        }else{
            result.push_back(stk.top()->val);
            stk.pop();
        }
    }
    return result;
}

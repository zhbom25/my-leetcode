//
// Created by zhaobo on 2022/3/2.
//
#include "TreeNode.h"

// 二叉树的序列化以及反序列化
// 利用层序遍历实现

void _trim(string &s);
vector<string> _split(string &str, const string &pattern);

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ret_str;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            root = que.front();
            que.pop();
            if (root != nullptr) {
                ret_str += to_string(root->val);
                que.push(root->left);
                que.push(root->right);
            } else {
                ret_str += "n";
            }
            ret_str += " ";
        }
        return ret_str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        _trim(data);
        vector<string> vec = _split(data, " ");
        /*for (auto v : vec) {
            cout << "val : " << v << endl;
        }*/
        if (vec.empty() || vec[0] == "n") {
            return nullptr;
        }
        TreeNode* root = new TreeNode(atoi(vec[0].c_str()));
        queue<TreeNode*> que;
        que.push(root);
        int i = 1;
        while (!que.empty()) {
            TreeNode* cur = que.front();
            que.pop();
            if (cur == nullptr) {
                continue;
            }
            if (vec[i] != "n") {
                cur->left = new TreeNode(atoi(vec[i].c_str()));
            } else {
                cur->left = nullptr;
            }
            if (vec[i+1] != "n") {
                cur->right = new TreeNode(atoi(vec[i+1].c_str()));
            } else {
                cur->right = nullptr;
            }
            i += 2;
            que.push(cur->left);
            que.push(cur->right);
        }
        return root;
    }
};

void _trim(string &s)
{
    if (s.empty()) {
        return;
    }
    s.erase(0, s.find_first_not_of(" "));
    s.erase(s.find_last_not_of(" ") + 1);
}

vector<string> _split(string &str, const string &pattern)
{
    string::size_type pos;
    vector<string> result;
    str += pattern;
    int size = str.size();
    for (int i = 0; i < size; i++)
    {
        pos = str.find(pattern, i);
        if (pos < size)
        {
            string s = str.substr(i, pos - i);
            result.push_back(s);
            i = pos + pattern.size() - 1;
        }
    }
    return result;
}

int main() {
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(3);
    TreeNode *node4 = new TreeNode(4);
    TreeNode *node5 = new TreeNode(5);
    TreeNode *node6 = new TreeNode(6);
    TreeNode *node7 = new TreeNode(7);
    TreeNode *node8 = new TreeNode(8);
    TreeNode *node9 = new TreeNode(9);
    node1->left = node2;
    node1->right = node3;
    node3->left = node4;
    node3->right = node5;
    node4->left = node6;
    node5->left = node7;
    node5->right = node8;
    node8->left = node9;
    Codec *codec = new Codec();
    string str1 = codec->serialize(node1);
    cout << str1 << endl;
    TreeNode* root = codec->deserialize(str1);
    string str2 = codec->serialize(root);
    cout << str2 << endl;
    return 0;
}

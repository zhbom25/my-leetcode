//
// Created by zhaobo on 2022/3/2.
//

#ifndef LEETCODE_TREENODE_H
#define LEETCODE_TREENODE_H

#include <vector>
#include <string>
#include <list>
#include <deque>
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

#endif //LEETCODE_TREENODE_H

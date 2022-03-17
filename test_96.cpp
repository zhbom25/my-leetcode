//
// Created by zhaobo on 2022/3/7.
//
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    /* 二叉树，非二叉搜索树
    // n个节点的二叉树，叶子节点各位为，n+1
    // n个节点的二叉树，每个节点拥有的父节点数为，n
    // 故，f(n) = f(n-1) + n + (n+1)
    // f(1) = 1
    // 可以求得 f(n) = n^2
    int numTrees(int n) {
        return n*n;
    }
    */

    // 假设n个节点存在二叉排序树的个数是G(n)，1为根节点，2为根节点，...，n为根节点，
    // 当1为根节点时，其左子树节点个数为0，右子树节点个数为n-1，同理当2为根节点时，
    // 其左子树节点个数为1，右子树节点为n-2，
    // 所以可得G(n) = G(0)*G(n-1)+G(1)*G(n-2)+...+G(n-1)*G(0)
    int numTrees(int n) {
        vector<int> vec(n+1, 0);
        vec[0] = 1;
        vec[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                vec[i] += vec[j] * vec[i-j-1];
            }
        }
        return vec[n];
    }
};

//
// Created by zhaobo on 2022/3/3.
//
#include "TreeNode.h"

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return _createTree(nums, 0, nums.size()-1);
    }

    TreeNode* _createTree(vector<int>& nums, int start, int end) {
        if (start > end) {
            cout << "ok" << endl;
            return nullptr;
        }
        pair<int, int> _max = _getMax(nums, start, end);
        cout << "max_index : " << _max.first << " max_value : " << _max.second << endl;
        TreeNode* node = new TreeNode(_max.second);
        cout << "create node succ" << endl;
        cout << "start : " << start << endl;
        cout << "end : " << _max.first - 1 << endl;
        node->left = _createTree(nums, start, _max.first-1);
        cout << "create left succ" << endl;
        node->right = _createTree(nums, _max.first+1, end);
        cout << "create right succ" << endl;
        return node;
    }

    pair<int, int> _getMax(vector<int>& nums, int start, int end) {
        int index = start;
        int max = nums[start++];
        while (start <= end) {
            if (nums[start] > max) {
                max = nums[start];
                index = start;
            }
            start++;
        }
        return make_pair(index, max);
    }

};

int main(int argc, char** argv)
{
    vector<int> vec = {3,2,1,6,0,5};
    Solution* solution = new Solution();
    TreeNode* root = solution->constructMaximumBinaryTree(vec);
    return 0;
}


//
// Created by zhaobo on 2022/3/7.
//
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    /*
    // 方法一，递归求解，超时
    int rob(vector<int>& nums) {
        return _rob(nums, 0);
    }

    int _rob(vector<int>& nums, int cur)
    {
        if (nums.empty()) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }
        if (cur == nums.size()-1) {
            return nums[cur];
        }
        if (cur > nums.size()-1) {
            return 0;
        }
        return max((nums[cur] + _rob(nums, cur+2)), (nums[cur+1] + +_rob(nums, cur+3)));
    }
    */

    // 方法二：动态规划
    int rob(vector<int>& nums) {
        int _size = nums.size();
        if (_size == 0) return 0;
        if (_size == 1) return nums[0];
        if (_size == 2) {
            return max(nums[0], nums[1]);
        }
        nums[2] += nums[0];
        for (int i = 3; i < _size; i++) {
            nums[i] += max(nums[i-2], nums[i-3]);
        }
        return max(nums[_size-1], nums[_size-2]);
    }
};

int main(int argc, char** argv)
{
    vector<int> vec = {1,2,3,1};
    Solution* solution = new Solution();
    int ret = solution->rob(vec);
    cout << "ret : " << ret << endl;
    return 0;
}

//
// Created by zhaobo on 2022/2/8.
//
#include <vector>
#include <iostream>

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ret;
    int max = nums[0];
    int pos = 0;
    for (size_t i = 0; i < k; i++) {
        if (nums[i] >= max) {
            max = nums[i];
            pos = i;
        }
    }
    ret.push_back(max);
    for (size_t cur = k; cur < nums.size(); cur++) {
        if (nums[cur] >= max) {
            max = nums[cur];
            pos = cur;
            ret.push_back(max);
        } else if (pos == cur-3) {
            max = nums[cur];
            pos = cur;
            for (size_t n = cur-2; n < cur; n++) {
                if (nums[n] >= max) {
                    max = nums[n];
                    pos = n;
                }
            }
            ret.push_back(max);
        } else {
            ret.push_back(max);
        }
    }
    return ret;
}

int main(int argc, char** argv)
{
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    vector<int> ret = maxSlidingWindow(nums, 3);
    for (auto iter = ret.begin(); iter != ret.end(); iter++) {
        cout << "max : " << *iter << endl;
    }
    return 0;
}

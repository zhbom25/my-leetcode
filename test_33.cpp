//
// Created by zhaobo on 2022/2/23.
//
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        return _search(nums, 0, nums.size()-1, target);
    }

    int binary_search(const vector<int>& nums, const int& start, const int& end, const int target) {
        if (end == 0) {
            return 0;
        }
        if (start == nums.size()-1) {
            return nums.size();
        }
        int _pos = (start + end) / 2;
        if (nums[_pos] == target) {
            return _pos;
        } else if (nums[_pos] > target) {
            if (_pos > start) {
                if (nums[_pos - 1] < target) {
                    return _pos;
                }
            }
            return binary_search(nums, start, _pos - 1, target);
        } else if (nums[_pos] < target) {
            if (_pos < end - 1) {
                if (nums[_pos + 1] > target) {
                    return _pos + 1;
                }
            }
            return binary_search(nums, _pos + 1, end, target);
        }
        return -1;
    }

    int _search(const vector<int>& nums, const int& start, const int& end, const int target) {
        if (start == end) {
            if (nums[start] == target) {
                return start;
            } else {
                return -1;
            }
        }
        if (end-start <= 2) {
            if (nums[start] == target) {
                return start;
            } else if (nums[(start+end)/2] == target) {
                return (start+end)/2;
            } else if (nums[end] == target) {
                return end;
            } else {
                return -1;
            }
        }
        int _pos = (start + end) / 2;
        if (nums[_pos] >= nums[start]) {
            int i = binary_search(nums, start, _pos, target);
            if (i != -1) {
                return i;
            }
            int j = _search(nums, _pos+1, end, target);
            if (j != -1) {
                return j;
            }
            return -1;
        } else {
            int i = binary_search(nums, _pos+1, end, target);
            if (i != -1) {
                return i;
            }
            int j = _search(nums, start, _pos, target);
            if (j != -1) {
                return j;
            }
            return -1;
        }
        return -1;
    }
};

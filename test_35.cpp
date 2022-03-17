//
// Created by zhaobo on 2022/2/23.
//
#include <vector>
#include <iostream>

using namespace std;

int _search(const vector<int>& nums, const int& start, const int& end, const int target);
int searchInsert(vector<int>& nums, int target);

int searchInsert(vector<int>& nums, int target) {
    return _search(nums, 0, nums.size()-1, target);
}

int main(int argc, char** argv)
{
    vector<int> vec1 = {1,3,5,6};
    int target1 = 5;
    cout << searchInsert(vec1, 5) << endl;  // output 2
    vector<int> vec2 = {1,3,5,6};
    int target2 = 2;
    cout << searchInsert(vec2, 2) << endl;  // output 1
    vector<int> vec3 = {1,3,5,6};
    int target3 = 7;
    cout << searchInsert(vec3, 7) << endl;  // output 4
    vector<int> vec4 = {1,3,5,6};
    int target4 = 0;
    cout << searchInsert(vec4, target4) << endl;  // output 0
    vector<int> vec5 = {1};
    int target5 = 0;
    cout << searchInsert(vec5, target5) << endl;  // output 0
    return 0;
}

int _search(const vector<int>& nums, const int& start, const int& end, const int target) {
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
        return _search(nums, start, _pos - 1, target);
    } else if (nums[_pos] < target) {
        if (_pos < end - 1) {
            if (nums[_pos + 1] > target) {
                return _pos + 1;
            }
        }
        return _search(nums, _pos + 1, end, target);
    }
    return -1;
}

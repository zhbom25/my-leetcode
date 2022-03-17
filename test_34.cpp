//
// Created by zhaobo on 2022/2/23.
//
#include <vector>
#include <iostream>
using namespace std;

// 数组需要极其注意越界问题

vector<int> _search(const vector<int>& nums, const int& start, const int& end, const int target);
vector<int> searchRange(vector<int>& nums, int target);

ostream& operator<<(ostream&os, const vector<int>& vec)
{
    for (auto iter = vec.begin(); iter != vec.end(); ++iter) {
        os << *iter << " ";
    }
    os << endl;
    return os;
}

int main(int argc, char** argv)
{
    vector<int> vec = {0,0,1,1,1,4,5,5};
    int target = 2;
    cout << searchRange(vec, target) << endl;
}

vector<int> searchRange(vector<int>& nums, int target) {
    if (nums.empty()) {
        return {-1,-1};
    }
    return _search(nums, 0, nums.size()-1, target);
}

vector<int> _search(const vector<int>& nums, const int& start, const int& end, const int target) {
    int pos_s = start;
    int pos_e = end;
    int _pos = (start + end) / 2;
    if (start > end) {
        return vector<int>{-1, -1};
    }
    if (end == 0 || start == nums.size()-1) {
        if (nums[start] == target) {
            return vector<int>{start, start};
        } else {
            return vector<int>{-1, -1};
        }
    }
    if (nums[_pos] == target) {
        int tmp1,tmp2;
        tmp1 = tmp2 = _pos;
        while (tmp1 >= 0) {
            if (nums[tmp1] != target) {
                pos_s = tmp1+1;
                break;
            } else {
                pos_s = tmp1--;
            }
        }
        while (tmp2 <= nums.size()-1) {
            if (nums[tmp2] != target) {
                pos_e = tmp2 - 1;
                break;
            } else {
                pos_e = tmp2++;
            }
        }
        return vector<int>{pos_s, pos_e};
    } else if (nums[_pos] > target && _pos >= 1) {
        return _search(nums, start, _pos-1, target);
    } else if (nums[_pos] < target && _pos < nums.size()-1) {
        return _search(nums, _pos+1, end, target);
    }
    return vector<int>{-1, -1};
}

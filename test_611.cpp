//
// Created by zhaobo on 2022/2/24.
//
#include <vector>
#include <iostream>
#include <string>
#include <functional>

using namespace std;

template <typename T>
struct comp {
    bool operator() (const T& a, const T& b){
        return a < b;
    }
};

int main(int argc, char** argv)
{
    vector<int> vec = {3,1,3,7,6,4,9,10,2};
    sort(vec.begin(), vec.end(), less<int>());
    for (auto iter = vec.begin(); iter != vec.end(); ++iter) {
        cout << *iter << endl;
    }
    return 0;
}

int triangleNumber(vector<int>& nums) {
    if (nums.size() < 3) {
        return 0;
    }
    sort(nums.begin(), nums.end(), less<int>());
    int _result = 0;
    for (size_t i = nums.size()-1; i >= 2; --i) {
        size_t left = 0;
        size_t right = i-1;
        while (left < right) {
            if (nums[left] + nums[right] > nums[i]) {
                _result += right - left;
                right--;
            } else {
                left++;
            }
        }
    }
    return _result;
}

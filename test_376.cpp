//
// Created by zhaobo on 2022/2/10.
//
#include <vector>
#include <iostream>

using namespace std;

int wiggleMaxLength(vector<int>& nums);
int _maxLen(vector<int>& nums, int start, int end);
bool isSwingSeq(vector<int>& nums, int start, int end);

int main(int argc, char** argv)
{
    vector<int> a = {1,17,5,10,13,15,10,5,16,8};
    cout << wiggleMaxLength(a) << endl;
}

int wiggleMaxLength(vector<int>& nums) {
    return _maxLen(nums, 0, nums.size()-1);
}

int _maxLen(vector<int>& nums, int start, int end) {
    if (isSwingSeq(nums, start, end)) {
        return end-start+1;
    }
    return max(_maxLen(nums, start+1, end), _maxLen(nums, start, end-1));
}

bool isSwingSeq(vector<int>& nums, int start, int end) {
    if (end-start <= 1) return true;
    if (nums[start+1] - nums[start] <= 0) return false;
    int true_cnt = 0;
    int false_cnt = 0;
    for (size_t i = start+1; i <= end; i++) {
        int dvalue = nums[i] - nums[i-1];
        if (dvalue > 0 && true_cnt == false_cnt) {
            true_cnt++;
        } else if (dvalue < 0 && true_cnt == false_cnt+1) {
            false_cnt++;
        } else {
            return false;
        }
    }
    return true;
}

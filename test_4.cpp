//
// Created by zhaobo on 2022/2/24.
//
#include <vector>
//#include <iostream>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret_vec;
        auto iter1 = nums1.begin();
        auto iter2 = nums2.begin();
        while (iter1 != nums1.end() && iter2 != nums2.end()) {
            if (*iter1 <= *iter2) {
                ret_vec.push_back(*iter1);
                ++iter1;
            } else {
                ret_vec.push_back(*iter2);
                ++iter2;
            }
        }
        while (iter1 != nums1.end()) {
            ret_vec.push_back(*iter1);
            ++iter1;
        }
        while (iter2 != nums2.end()) {
            ret_vec.push_back(*iter2);
            ++iter2;
        }
        int _len = ret_vec.size();
        if (_len % 2 == 1) {
            return (double)ret_vec[_len/2];
        } else {
            return (double)((ret_vec[_len/2] + ret_vec[_len/2-1])) / 2;
        }
    }
};

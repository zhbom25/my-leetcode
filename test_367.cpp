//
// Created by zhaobo on 2022/2/24.
//
class Solution {
public:
    bool isPerfectSquare(int num) {
        int i = 1;
        while (num > -1) {
            if (num == 0) {
                return true;
            }
            num -= i;
            i += 2;
        }
        return false;
    }
};

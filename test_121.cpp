//
// Created by zhaobo on 2022/3/6.
//
#include <vector>
#include <iostream>

using namespace std;

/*
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        int ret = 0;
        for (int i = 0; i < prices.size()-1; ) {
            if (prices[i+1] > prices[i]) {
                cout << "price[i] : " << prices[i] << endl;
                cout << "price[i+1] : " << prices[i+1] << endl;
                ret += prices[i+1] - prices[i];
                i += 2;
            } else {
                i++;
            }
        }
        return ret;
    }
};
*/
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() <= 1) {
            return 0;
        }
        int _min = prices[0], _max = 0;
        for (int i = 1; i < prices.size(); i++) {
            _max = max(_max, prices[i] - _min);
            _min = min(_min, prices[i]);
        }
        return _max;
    }
};

int main(int argc, char** argv)
{
    vector<int> vec = {7,1,5,3,6,4};
    Solution* solution = new Solution();
    int ret = solution->maxProfit(vec);
    cout << "max : " << ret << endl;
    return 0;
}

//
// Created by zhaobo on 2022/3/6.
//
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) {
            return 0;
        }
        int _max = 0;
        for (size_t i = 0; i < prices.size(); i++) {
            int _max_f = _maxProfit(prices, 0, i);
            int _max_e = _maxProfit(prices, i+1, prices.size()-1);
            if (_max_f + _max_e > _max) {
                _max = _max_f + _max_e;
            }
        }
        return _max;
    }

    int _maxProfit(vector<int>& prices, int start, int end)
    {
        if (end <= start) return 0;
        int _min = prices[start], _max = 0;
        for (int i = start+1; i <= end; i++) {
            _max = max(_max, prices[i] - _min);
            _min = min(_min, prices[i]);
        }
        return _max;
    }
};

int main(int argc, char** argv)
{
    Solution* solution = new Solution();
    vector<int> vec = {3,3,5,0,0,3,1,4};
    int ret = solution->maxProfit(vec);
    cout << "ret : " << ret << endl;
    return 0;
}

//
// Created by zhaobo on 2022/2/10.
//
#include <vector>
#include <iostream>

using namespace std;

int _max(vector<int>& prices, int start);
int maxProfit(vector<int>& prices);

int main(int argc, char** argv)
{
    vector<int> a = {1,2,3,4,5};
    int ret = _max(a, 0);
    cout << "ret : " << ret << endl;
    return 0;
}

int maxProfit(vector<int>& prices) {
    return _max(prices, 0);
}

int _max(vector<int>& prices, int start)
{
    cout << "size : " << prices.size() << endl;
    if (start >= prices.size()-1) {
        return 0;
    }
    int low = -1;
    int high = -1;
    int i = start;
    int end = prices.size() - 1;
    for (; i < end; i++) {
        cout << "low i : " << i << endl;
        if (prices[i+1] >= prices[i]) {
            low = i;
            cout << "low val : " << low << endl;
            break;
        }
    }
    for (; i < end; i++) {
        cout << "high i : " << i << endl;
        if (prices[i] >= prices[i-1] && prices[i] >= prices[i+1]) {
            high = i;
            cout << "high val : " << high << endl;
            break;
        }
    }
    if (i == end && prices[i] > prices[i-1]) {
        high = end;
    }
    if (high > low) {
        return (prices[high] - prices[low]) + _max(prices, high+1);
    }
    return 0;
}

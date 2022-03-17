//
// Created by zhaobo on 2022/2/9.
//
#include <vector>
#include <iostream>

using namespace std;

int maxArea(vector<int>& height);

int main(int argc, char** argv)
{
    vector<int> vec = {1,8,6,2,5,4,8,3,7};
    cout << "maxArea : " << maxArea(vec) << endl;
}

int maxArea(vector<int>& height) {
    int max_high = 0;
    for (size_t i = 0; i < height.size(); i++) {
        max_high = height[i] >= max_high ? height[i] : max_high;
    }
    int max_area = 0;
    for (int k = max_high; k >= 1; k--) {
        int n1 = 0;
        int n2 = height.size() - 1;
        while (n1 <= n2) {
            if (height[n1] >= k)
                break;
            n1++;
        }
        while (n2 >= n1) {
            if (height[n2] >= k)
                break;
            n2--;
        }
        cout << "k : " << k << endl;
        cout << "n1 : " << n1 << endl;
        cout << "n2 : " << n2 << endl;
        max_area = k * (n2-n1) > max_area ? k * (n2-n1) : max_area;
    }
    return max_area;
}


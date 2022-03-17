//
// Created by zhaobo on 2022/2/24.
//
#include <vector>
#include <iostream>
using namespace std;

bool isPowerOfTwo(int n);

int main(int argc, char** argv)
{
    cout << isPowerOfTwo(16) << endl;
    return 0;
}

bool isPowerOfTwo(int n)
{
    if (n <= 0) return false;
    if ((n & (n-1)) == 0) {
        return true;
    } else {
        return false;
    }
}

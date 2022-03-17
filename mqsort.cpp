//
// Created by zhaobo on 2022/2/10.
//
#include <vector>
#include <string>
#include <iostream>

using namespace std;

void mqsort(int a[], int low, int high)
{
    if (high <= low) {
        return;
    }
    int key = a[low];
    int i = low;
    int j = high+1;
    while (true) {
        while (a[++i] < key) {
            if (i == high) break;
        }
        while (a[--j] > key) {
            if (j == low) break;
        }
        if (i >= j) break;
        int tmp = a[j];
        a[j] = a[i];
        a[i] = tmp;
    }
    a[low] = a[j];
    a[j] = key;
    mqsort(a, low, j-1);
    mqsort(a, j+1, high);
}

//
// Created by zhaobo on 2022/2/9.
//
#include <iostream>

using namespace std;

void qsort(int a[], int low, int high);

int main(int argc, char** argv)
{
    int a[] = {12,32,44,90,18,31,32,88,67,45,9};
    qsort(a, 0, sizeof (a) / sizeof (a[0]) - 1);
    for (size_t i = 0; i < sizeof (a) / sizeof (a[0]); i++) {
        cout << i << " val : " << a[i] << endl;
    }
    return 0;
}

void qsort(int arr[], int low, int high){
    if (high <= low) return;
    int i = low;
    int j = high + 1;
    int key = arr[low];
    while (true)
    {
        /*从左向右找比key大的值*/
        while (arr[++i] < key)
        {
            if (i == high){
                break;
            }
        }
        /*从右向左找比key小的值*/
        while (arr[--j] > key)
        {
            if (j == low){
                break;
            }
        }
        if (i >= j) break;
        /*交换i,j对应的值*/
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    /*中枢值与j对应值交换*/
    arr[low] = arr[j];
    arr[j] = key;
    qsort(arr, low, j - 1);
    qsort(arr, j + 1, high);
}

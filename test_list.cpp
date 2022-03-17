//
// Created by zhaobo on 2022/3/14.
//
//
// Created by zhaobo on 2022/3/14.
//
#include <list>
#include <map>
#include <vector>
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    map<int, list<int>> freq;
    freq.insert(make_pair<int, list<int>>(1, {2,3,4}));
    list<int> a;
    a.swap(freq[1]);
    //a.push_back(2);
    //freq[1] = a;
    cout << "output freq[1]" << endl;
    auto bg = freq[1].begin();
    while (bg != freq[1].end()) {
        cout << "val : " << *bg << endl;
        bg++;
    }
    a.push_back(2);
    cout << "output a" << endl;
    auto bg1 = a.begin();
    while (bg1 != a.end()) {
        cout << "val : " << *bg1 << endl;
        bg1++;
    }
    //a.push_back(2);
    freq[1].swap(a);
    auto bg2 = freq[1].begin();
    while (bg2 != freq[1].end()) {
        cout << "val : " << *bg2 << endl;
        bg2++;
    }
    return 0;
}

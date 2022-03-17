//
// Created by zhaobo on 2022/2/10.
//
#include <list>
#include <iostream>

using namespace std;

void remove_(string &num, int k);
string  removeKdigits(string num, int k);

int main(int argc, char** argv)
{
    string str = "10";
    int k = 2;
    string ret = removeKdigits(str, k);
    cout << "ret : " << ret << endl;
    return 0;
}

string removeKdigits(string num, int k) {
    remove_(num, k);
    if (num.empty()) return "0";
    num.erase(0, num.find_first_not_of("0"));
    if (num.empty()) return "0";
    return num;
}

void remove_(string &num, int k) {
    if (k == 0 || num.empty()) {
        return;
    }
    if (num.size() == 1) {
        num = "";
        return;
    }
    int start = num[0] - '0';
    int pos = 0;
    for (size_t i = 1; i < num.size(); i++) {
        int cur = num[i] - '0';
        if (cur >= start) {
            if (i == num.size()- 1) {
                num.erase(num.size()-k, k);
                return;
            }
            start = cur;
            pos++;
        } else {
            num.erase(pos, 1);
            remove_(num, k-1);
            return;
        }
    }
    return;
}

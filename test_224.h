#ifndef _TEST_224_H_
#define _TEST_224_H_

#include <vector>
#include <string>
#include <list>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
    enum OPT_VAL {
        ADD_OPT = -10000001,
        SUB_OPT = -20000001,
        MUL_OPT = -30000001,
        DIV_OPT = -40000001,
        LEFT_B  = -50000001,
        RIGHT_B = -60000001
    };

    const string ADD_STR   = " -10000001 ";
    const string SUB_STR   = " -20000001 ";
    const string MUL_STR   = " -30000001 ";
    const string DIV_STR   = " -40000001 ";
    const string LEFT_STR  = " -50000001 ";
    const string RIGHT_STR = " -60000001 ";
    const string EMPTY_STR = "";
    const string SPLIT_STR = " ";

public:
    Solution() = default;

    int calculate(string s);

private:
    int _cal_a(vector<int> &vec, int start = 0);
    int _cal_d(vector<int> &vec, int start, int end);
    void _trim(string &s);
    vector<string> _split(string &str, const string &pattern);
    void _replace(string &str, const string &s1, const string &s2);
};

#endif


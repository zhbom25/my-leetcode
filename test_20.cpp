#include <vector>
#include <string>
#include <stack>
#include <list>
#include <iostream>

using namespace std;

bool isValid(string s) {
    stack<char> stk;
    for (size_t i=0; i<s.length(); i++) {
        switch (s[i]) {
            case '(' :
                stk.push(')');
                break;
            case '{' :
                stk.push('}');
                break;
            case '[' :
                stk.push(']');
                break;
            case ')' :
            case '}' :
            case ']' :
                if (stk.empty())
                    return false;
                char c = stk.top();
                stk.pop();
                if (c != s[i])
                    return false;
                break;
        }
    }
    if (stk.empty()) {
        return true;
    } else {
        return false;
    }
}

int main(int argc, char** argv)
{
    string s = "()";
    bool ret = isValid(s);
    cout << "ret : " << ret << endl;
    return 0;
}


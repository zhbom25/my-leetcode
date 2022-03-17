//
// Created by zhaobo on 2022/2/8.
//

#include "test_232.h"

int main(int argc, char** argv)
{
    MyQueue* obj = new MyQueue();
    obj->push(1);
    obj->push(2);
    cout << "peek : " << obj->peek() << endl;
    cout << "pop : " << obj->pop() << endl;
    cout << "bool : " << obj->empty() << endl;
    return 0;
}

#include <vector>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* p) : val(x), next(p) {}
};

class MinStack {
public:
    MinStack() : _min(INT_MAX) {
        head = new ListNode(0);
    }

    ~MinStack() {
        while (head != nullptr) {
            ListNode* tmp = head->next;
            delete(head);
            head = tmp;
        }
    }
    
    void push(int val) {
        _min = (val <= _min) ? val : _min;
        ListNode* p = new ListNode(val);
        p->next = head->next;
        head->next = p;
    }
    
    void pop() {
        if (head->next != nullptr) {
            ListNode* p = head->next->next;
            if (head->next->val == _min) {
                _min = INT_MAX;
                while (p != nullptr) {
                    _min = (p->val <= _min) ? p->val : _min;
                    p = p->next;
                }
            }
            p = head->next->next;
            delete(head->next);
            head->next = p;
        }
    }
    
    int top() {
        if (head->next != nullptr) {
            return head->next->val;
        }
        return 0;
    }
    
    int getMin() {
        return _min;
    }

private:
    int _min;
    ListNode* head;
};

int main(int argc, char** argv)
{
    MinStack* minStk = new MinStack();
    minStk->push(-2);
    minStk->push(0);
    minStk->push(-3);
    /*
    cout << "top : " << minStk->top() << endl;
    minStk->pop();
    cout << "top : " << minStk->top() << endl;
    minStk->pop();
    cout << "top : " << minStk->top() << endl;
    minStk->pop();
    */
    cout << "min : " << minStk->getMin() << endl;
    minStk->pop();
    cout << "top : " << minStk->top() << endl;
    cout << "min : " << minStk->getMin() << endl;
    return 0;
}


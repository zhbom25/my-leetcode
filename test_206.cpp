#include <vector>
#include <deque>
#include <list>
#include <string>
#include <stack>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    shared_ptr<ListNode> next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, shared_ptr<ListNode> next) : val(x), next(next) {}
};

shared_ptr<ListNode> reverseList(shared_ptr<ListNode> head) {
    if (head == nullptr) {
        return nullptr;
    }
    stack<int> stack;
    while (head != nullptr) {
        stack.push(head->val);
        head = head->next;
    }
    shared_ptr<ListNode> nhead = make_shared<ListNode>();
    nhead->val = stack.top();
    stack.pop();
    shared_ptr<ListNode> node1 = make_shared<ListNode>();
    node1->val = stack.top();
    stack.pop();
    nhead->next = node1;
    while (!stack.empty()) {
        shared_ptr<ListNode> tmp = make_shared<ListNode>();
        tmp->val = stack.top();
        tmp->next = nullptr;
        stack.pop();
        node1->next = tmp;
        node1 = node1->next;
    }
    return nhead;
}

int main(int argc, char** argv)
{
    vector<int> vec = {1,2,3,4,5};
    auto iter = vec.cbegin();
    //ListNode *head = new ListNode();
    //ListNode *node1;
    shared_ptr<ListNode> head = make_shared<ListNode>();
    shared_ptr<ListNode> node1 = head;
    //node1 = head;
    head->val = *iter;
    head->next = nullptr;
    node1 = head;
    iter++;
    while (iter != vec.cend()) {
        //ListNode *node2 = new ListNode();
        shared_ptr<ListNode> node2 = make_shared<ListNode>();
        node2->val = *iter;
        node2->next = nullptr;
        node1->next = node2;
        node1 = node2;
        iter++;
    }
    cout << "head val" << endl;
    shared_ptr<ListNode> tmp = head;
    while (tmp != nullptr) {
        cout << "val : " << tmp->val << endl;
        tmp = tmp->next;
    }
    shared_ptr<ListNode> rhead = reverseList(head);
    cout << "rhead val" << endl;
    while (rhead != nullptr) {
        cout << "rval : " << rhead->val << endl;
        rhead = rhead->next;
    }
    //shared_ptr<ListNode> testp = make_shared<ListNode>();
    ListNode* lp = new ListNode(10);
    shared_ptr<ListNode> testp(lp);
    //delete lp;
    return 0;
}

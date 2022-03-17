//
// Created by zhaobo on 2022/2/8.
//
#include <iostream>
#include <vector>
#include <string>
#include <list>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* oddEvenList(ListNode* head);
// [1,2,3,4,5]
int main(int argc, char** argv)
{
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(4);
    ListNode *node5 = new ListNode(5);
    ListNode *node6 = new ListNode(6);
    node5->next = node6;
    node4->next = node5;
    node3->next = node4;
    node2->next = node3;
    node1->next = node2;
    ListNode* p = oddEvenList(node1);
    while (p != nullptr) {
        cout << "val : " << p->val << endl;
        p = p->next;
    }
}

ListNode* oddEvenList(ListNode* head) {
    if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
        return head;
    }
    // 奇数列
    ListNode* odd_end = head;
    // 偶数列
    ListNode* even_start = head->next;
    ListNode* even_end = head->next;
    // 方法一
    ListNode* p = head->next->next;
    int cur = 3;
    while (p != nullptr) {
        if (cur % 2 == 0) {
            even_end->next = p;
            even_end = even_end->next;
        } else {
            odd_end->next = p;
            odd_end = odd_end->next;
        }
        p = p->next;
        cur++;
    }
    // 必不可少
    even_end->next = nullptr;

    // 方法二
    /*
    while (odd_end->next != nullptr && even_end->next != nullptr) {
        odd_end->next = even_end->next;
        odd_end = odd_end->next;
        even_end->next = odd_end->next;
        even_end = even_end->next;
    }
    */
    odd_end->next = even_start;
    return head;
}
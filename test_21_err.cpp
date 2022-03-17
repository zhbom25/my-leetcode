#include <vector>
#include <iostream>
#include <list>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            if (list1 == nullptr)
                return list2;
            if (list2 == nullptr)
                return list1;
            ListNode* head = (list1->val <= list2->val) ? list1 : list2;
            ListNode* cur1 = list1;
            ListNode* cur2 = list2;
            while (cur1 != nullptr && cur2 != nullptr) {
                if (cur1->val <= cur2->val) {
                    if (cur1->next != nullptr) {
                        if (cur1->next->val <= cur2->val) {
                            cur1 = cur1->next;
                        } else {
                            ListNode* tmp = cur1->next;
                            cur1->next = cur2;
                            cur2 = tmp;
                        }
                    } else {
                        cur1->next = cur2;
                        return head;
                    }
                } else {
                    if (cur2->next != nullptr) {
                        if (cur2->next->val <= cur1->val) {
                            cur2 = cur2->next;
                        } else {
                            ListNode* tmp = cur2->next;
                            cur2->next = cur1;
                            cur1 = tmp;
                        }
                    } else {
                        cur2->next = cur1;
                        return head;
                    }
                }
            }
            return head;
        }
};

int main(int argc, char** argv)
{
    ListNode* list1 = new ListNode(1);
    ListNode* list1_2 = new ListNode(2);
    ListNode* list1_3 = new ListNode(4);
    ListNode* list1_4 = new ListNode(4);
    ListNode* list1_5 = new ListNode(5);
    list1->next = list1_2;
    list1_2->next = list1_3;
    list1_3->next = list1_4;
    list1_4->next = list1_5;
    ListNode* list2 = new ListNode(1);
    ListNode* list2_2 = new ListNode(3);
    ListNode* list2_3 = new ListNode(4);
    ListNode* list2_4 = new ListNode(4);
    ListNode* list2_5 = new ListNode(4);
    list2->next = list2_2;
    list2_2->next = list2_3;
    list2_3->next = list2_4;
    list2_4->next = list2_5;
    ListNode* retp;
    Solution solution;
    retp = solution.mergeTwoLists(list1, list2);
    while (retp != nullptr) {
        cout << "val : " << retp->val << endl;
        retp = retp->next;
    }
    return 0;
}

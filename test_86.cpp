/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *cur1,*cur2,*cur3;
        cur1 = head;
        cur2 = head;
        cur3 = head;
        int cnt = 0;
        while (cur1 != nullptr) {
            if (cur1->val < x) {
                cnt++;
            }
            cur1 = cur1->next;
        }
        while (cnt != 0) {
            cur2 = cur2->next;
            cnt--;
        }
        while (cur2 != nullptr) {
            if (cur3->val < x) {
                cur3 = cur3->next;
            } else {
                if (cur2->val < x) {
                    int tmp = cur2->val;
                    cur2->val = cur3->val;
                    cur3->val = tmp;
                    cur2 = cur2->next;
                    cur3 = cur3->next;
                } else {
                    cur2 = cur2->next;
                }
            }
        }
        return head;
    }
};


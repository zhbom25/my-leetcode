/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }
        bool has_ring = false;
        ListNode* cur1 = head->next;
        ListNode* cur2 = head->next->next;
        ListNode* cur3 = head;
        while (cur2 != nullptr && cur2->next != nullptr) {
            if (cur1 == cur2) {
                has_ring = true;
                break;
            }
            cur1 = cur1->next;
            cur2 = cur2->next->next;
        }
        if (has_ring == true) {
            while (cur3 != cur1) {
                cur3 = cur3->next;
                cur1 = cur1->next;
            }
            return cur3;
        }
        return nullptr;
    }
};


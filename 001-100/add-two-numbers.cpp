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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int val = 0;
        if (l1 != nullptr) val += l1->val;
        if (l2 != nullptr) val += l2->val;
        int rem = val / 10;
        val = val % 10;
        if (l1 == nullptr && l2 == nullptr && val == 0 && rem == 0) {
             return nullptr;
        }
        ListNode* next;
        if (rem == 0) {
            if (l1 == nullptr && l2 == nullptr) {
                next = nullptr;
            } else if (l1 == nullptr) {
                next = addTwoNumbers(nullptr, l2->next);
            } else if (l2 == nullptr) {
                next = addTwoNumbers(l1->next, nullptr);
            } else {
                next = addTwoNumbers(l1->next, l2->next);
            }
        } else {
            if (l1 == nullptr && l2 == nullptr) {
                next = addTwoNumbers(new ListNode(rem), nullptr);
            } else if (l1 == nullptr) {
                next = addTwoNumbers(new ListNode(rem), l2->next);
            } else if (l2 == nullptr) {
                next = addTwoNumbers(l1->next, new ListNode(rem));
            } else {
                l1->next = addTwoNumbers(new ListNode(rem), l1->next);
                next = addTwoNumbers(l1->next, l2->next);
            }
        }
        
        ListNode* ans = new ListNode(val, next);
        return ans;
    }
};
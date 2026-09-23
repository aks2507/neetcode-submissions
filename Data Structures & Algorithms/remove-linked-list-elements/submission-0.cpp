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
    ListNode* removeElements(ListNode* head, int val) {
        if (!head || (!head->next && head->val == val)) {
            return nullptr;
        }

        if (!head->next && head->val != val) {
            return head;
        }

        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = head->next;
        ListNode* final = head;

        while(curr) {
            if (curr->val == val) {
                if (!prev) {
                    final = next;
                    curr->next = nullptr;
                } else {
                    prev->next = next;
                    curr->next = nullptr;
                }
                curr = next;
                next = next->next;
            } else {
                prev = curr;
                curr = next;
                next = next->next;
            }
        }

        return final;
    }
};
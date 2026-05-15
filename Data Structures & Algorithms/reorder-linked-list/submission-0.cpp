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
    void reorderList(ListNode* head) {
        // Find the mid-point and thus the later half of the LL that has to be reversed
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the second half of the list
        ListNode* second = slow->next;
        ListNode* prev = nullptr;
        slow->next = nullptr;
        while(second != nullptr) {
            ListNode* tmp = second->next;
            second->next = prev;
            prev = second;
            second = tmp;
        }

        // Now make the reordering one by one. Remember after reversal, prev is the starting point of the reversed second half
        ListNode* first = head;
        second = prev;
        while (second != nullptr) {
            // Save the links that will be destroyed by the pointer manipulation
            ListNode* leftnext = first ->next;
            ListNode* rightnext = second ->next;

            // Now the actual pointer manipulation
            first->next = second;
            second->next = leftnext;
            second = rightnext;
            first = leftnext;
        } 
    }
};

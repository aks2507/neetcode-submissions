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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* newList = new ListNode(-1);

        ListNode* curr1 = list1, *curr2 = list2, *final = newList;

        while (curr1 || curr2) {
            final->next = new ListNode();
            if (curr1 && curr2) {
                if (curr1->val <= curr2->val) {
                    final->next->val = curr1->val;
                    curr1 = curr1->next;
                } else {
                    final->next->val = curr2->val;
                    curr2 = curr2->next;
                }
            } else if (curr1 && !curr2) {
                final->next->val = curr1->val;
                curr1 = curr1->next;
            } else if (curr2 && !curr1) {
                final->next->val = curr2->val;
                curr2 = curr2->next;
            }

            final = final->next;
        }

        return newList->next;
    }
};

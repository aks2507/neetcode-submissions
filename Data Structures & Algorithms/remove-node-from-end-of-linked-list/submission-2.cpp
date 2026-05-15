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
    // ListNode* removeNthFromEnd(ListNode* head, int n) {
    //     return recursiveRemoveNthFromEnd(head, n);
    // }

    // Recusive approach
    ListNode* recursiveRemoveNthFromEnd(ListNode* head, int& n) {
        if (!head) {
            return nullptr;
        }

        head->next = recursiveRemoveNthFromEnd(head->next, n);
        n--;

        if (n == 0) {
            // We are at node to remove. We simply return the next of the pointer instead of the pointer itself, so that its return in the rebuild is skipped
            return head->next;
        }

        // for all other values of n, simply return the node where the recusrion is at
        return head;
    }

    // Two pointer approach
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) {
            return nullptr;
        }

        ListNode* dummy = new ListNode(0, head);
        ListNode* l = dummy;
        ListNode* r = head;

        while (n > 0) {
            r = r->next;
            n--;
        }

        while (r != nullptr) {
            r = r->next;
            l = l->next;
        }

        l->next = l->next->next;

        return dummy->next;
    }
};

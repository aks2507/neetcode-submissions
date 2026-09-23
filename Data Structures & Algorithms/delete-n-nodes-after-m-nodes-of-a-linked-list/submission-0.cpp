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
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        int keep = m, remove = n;
        ListNode* curr = head;
        while(curr) {
            while(keep > 1) {
                if (!curr) break;
                curr = curr->next;
                keep--;
            }
            keep = m;

            if (!curr) break;

            ListNode* prev = curr;
            curr = curr->next;
            while(remove--) {
                if (!curr) break;
                curr = curr->next;
            }
            prev->next = curr;
            remove = n;
        }

        return head;
    }
};

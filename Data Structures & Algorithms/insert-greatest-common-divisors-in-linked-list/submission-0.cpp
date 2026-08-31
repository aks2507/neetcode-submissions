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
private:
    int gcd(int a, int b) {
        if (a < b) {
            swap(a, b);
        }
        if (a % b == 0) {
            return b;
        }

        return gcd(b, a % b);
    }
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        // ListNode* dummy = new ListNode(0, head);
        ListNode* prev = head;
        ListNode* curr = head->next;
        if (!curr) {
            return head;
        }
        while (curr) {
            ListNode* gcdNode = new ListNode(gcd(prev->val, curr->val), curr);
            prev->next = gcdNode;
            prev = curr;
            curr = curr->next;
        }
        return head;
    }
};
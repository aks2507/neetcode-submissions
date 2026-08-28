/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
private:
    int maxLen = 0;
    int rec(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int left = rec(root->left);
        int right = rec(root->right);

        int longest = 1;

        if (root->left && root->left->val - root->val == 1) {
            longest = max(longest, left + 1);
        }

        if (root->right && root->right->val - root->val == 1) {
            longest = max(longest, right + 1);
        }

        maxLen = max(maxLen, longest);

        return longest;
    }
public:
    int longestConsecutive(TreeNode* root) {
        maxLen = 0;
        rec(root);
        return maxLen;
    }
};

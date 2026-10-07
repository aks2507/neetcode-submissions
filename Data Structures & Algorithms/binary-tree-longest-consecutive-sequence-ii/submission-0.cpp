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
typedef pair<int, int> pp;
class Solution {
    int maxLen = 0;
    pp rec(TreeNode* root) {
        if (!root) {
            return {0, 0};
        }

        int inc = 1, dec = 1;
        pp left = rec(root->left);
        pp right = rec(root->right);

        if (root->left) {
            if (root->val == root->left->val + 1) {
                dec = left.second + 1;
            } else if (root->val == root->left->val - 1) {
                inc = left.first + 1; 
            }
        }

        if (root->right) {
            if (root->val == root->right->val + 1) {
                dec = right.second + 1;
            } else if (root->val == root->right->val - 1) {
                inc = right.first + 1;
            }
        }

        maxLen = max(maxLen, inc + dec - 1);

        return {inc, dec};
    }   
public:
    int longestConsecutive(TreeNode* root) {
        rec(root);

        return maxLen;
    }
};

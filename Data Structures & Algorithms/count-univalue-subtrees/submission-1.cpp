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
    // int uniValue = 0;
    bool rec(TreeNode* root, int& count) {
        if (!root) {
            return true;
        }

        bool leftUniValue = rec(root->left, count);
        bool rightUniValue = rec(root->right, count);

        if (!leftUniValue || !rightUniValue) {
            return false;
        }

        if (root->left && root->left->val != root->val) {
            return false;
        }

        if (root->right && root->right->val != root->val) {
            return false;
        }

        count++;

        return true;
    }
public:
    int countUnivalSubtrees(TreeNode* root) {
        int count = 0;
        rec(root, count);
        return count;
    }
};

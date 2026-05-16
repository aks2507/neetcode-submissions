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
    bool recIsValidBST(TreeNode* root, int min, int max) {
        if(!root) {
            return true;
        }

        if (root->val <= min || root->val >= max) {
            return false;
        }

        return recIsValidBST(root->left, min, root->val) && recIsValidBST(root->right, root->val, max);
    }

public:
    bool isValidBST(TreeNode* root) {
        return recIsValidBST(root, -1111, 1111);
    }
};

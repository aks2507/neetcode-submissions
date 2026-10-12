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
    unordered_map<TreeNode*, int> dp;

    int rec(TreeNode* root) {
        if (!root) {
            return 0;
        }

        if (dp.count(root)) {
            return dp[root];
        }

        int sum = 0;
        int exclude = rec(root->left) + rec(root->right);
        int include = root->val;
        int right = 0, left = 0;
        if (root->right) right = rec(root->right->left) + rec(root->right->right);
        if (root->left) left = rec(root->left->left) + rec(root->left->right);

        include += left + right;

        dp[root] = max(include, exclude);
        return dp[root];
    }
public:
    int rob(TreeNode* root) {
        return rec(root);
    }
};
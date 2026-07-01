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
    int dfs(TreeNode* root, int& maxSum) {
        if(!root) {
            return 0;
        }

        int leftMax = dfs(root->left, maxSum);
        int rightMax = dfs(root->right, maxSum);

        leftMax = max(leftMax, 0);
        rightMax = max(rightMax, 0);

        // with split
        int sumWithSplit = root->val + leftMax + rightMax;
        maxSum = max(maxSum, sumWithSplit);

        return root->val + max(leftMax, rightMax);
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = root->val;
        dfs(root, maxSum);

        return maxSum;
    }
};

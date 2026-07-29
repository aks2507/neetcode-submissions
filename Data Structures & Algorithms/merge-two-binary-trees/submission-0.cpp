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
    TreeNode* dfs(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) {
            return nullptr;
        } 

        TreeNode* newRoot;
        if (root1 && !root2) {
            newRoot = new TreeNode(root1->val, dfs(root1->left, nullptr), dfs(root1->right, nullptr));
        } else if (!root1 && root2) {
            newRoot = new TreeNode(root2->val, dfs(nullptr, root2->left), dfs(nullptr, root2->right));
        } else {
            newRoot = new TreeNode((root1->val + root2->val), dfs(root1->left, root2->left), dfs(root1->right, root2->right));
        }

        return newRoot;
    }
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return dfs(root1, root2);
    }
};
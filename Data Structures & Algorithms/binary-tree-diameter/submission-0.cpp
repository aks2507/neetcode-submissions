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
public:
    int recHeight(TreeNode* root, int& n) {
        if (!root) {
            return 0;
        }
        int left_height = recHeight(root->left, n);
        int right_height = recHeight(root->right, n);
        n = max(n, left_height + right_height);
        return 1 + max(left_height, right_height);

    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        recHeight(root, res);
        return res;
    }
};

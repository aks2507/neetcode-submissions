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
    vector<vector<int>> res;
    int rec(TreeNode* root) {
        if (!root) {
            return -1;
        }

        int leftHeight = rec(root->left);
        int rightHeight = rec(root->right);

        int currHeight = max(leftHeight, rightHeight) + 1;

        if (res.size() == currHeight) {
            res.push_back({});
        }

        res[currHeight].push_back(root->val);

        return currHeight;
    }
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        res.clear();
        rec(root);
        return res;
    }
};

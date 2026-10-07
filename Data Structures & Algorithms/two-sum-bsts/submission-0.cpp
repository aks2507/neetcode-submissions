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
    void dfs(TreeNode* root, vector<int>& v) {
        if (!root) return;
        dfs(root->left, v);
        v.push_back(root->val);
        dfs(root->right, v);
    }
public:
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        vector<int> l1, l2;

        dfs(root1, l1);
        dfs(root2, l2);

        int i = 0, j = l2.size() - 1;

        while (i < l1.size() && j >= 0) {
            if (l1[i] + l2[j] == target) {
                return true;
            } else if (l1[i] + l2[j] < target) {
                i++;
            } else {
                j--;
            }
        }

        return false;
    }
};

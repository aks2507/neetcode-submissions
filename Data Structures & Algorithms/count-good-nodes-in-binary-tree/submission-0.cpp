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
    int recGoodNodes(TreeNode* root, int maxTillNow) {
        if (!root) {
            return 0;
        }

        int res = 0;
        if (root->val >= maxTillNow) {
            res = 1;
        }

        maxTillNow = max(maxTillNow, root->val);
        res += recGoodNodes(root->left, maxTillNow);
        res += recGoodNodes(root->right, maxTillNow);

        return res;
    }

    int goodNodes(TreeNode* root) {
        return recGoodNodes(root, root->val);
    }
};

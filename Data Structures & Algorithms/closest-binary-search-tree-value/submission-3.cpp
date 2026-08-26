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
    int closestValue(TreeNode* root, double target) {
        TreeNode* curr = root;
        double currClosest = (double) root->val;
        while (curr) {
            double currVal = (double) curr->val;
            double diff = abs(currVal - target) - abs(currClosest - target);
            if (diff < 0 || (diff == 0 && currVal < currClosest)) {
                currClosest = currVal;
            }

            if (target < curr->val) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }

        return (int) currClosest;
    }
};

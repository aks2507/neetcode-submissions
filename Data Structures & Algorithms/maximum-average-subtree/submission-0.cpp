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
typedef pair<int, int> pp;
class Solution {
    double maxAvg = INT_MIN;

    pp rec(TreeNode* root) {
        if (!root) {
            return {0, 0};
        }

        pp left = rec(root->left);
        pp right = rec(root->right);

        int nodes = 1 + left.second + right.second;
        int sum = root->val + left.first + right.first;

        double avg = (double) sum / nodes;

        maxAvg = max(maxAvg, avg);

        return {sum, nodes};
    }
public:
    double maximumAverageSubtree(TreeNode* root) {
        rec(root);

        return maxAvg;
    }
};

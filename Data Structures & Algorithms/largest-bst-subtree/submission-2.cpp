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
typedef pair<int, bool> pp;
typedef long long ll;
class Solution {
    pp rec(TreeNode* root, ll& mn, ll& mx) {
        if (!root) {
            mn = LLONG_MAX;
            mx = LLONG_MIN;
            return {0, true};
        }

        ll leftMin, leftMax, rightMin, rightMax;

        pp left = rec(root->left, leftMin, leftMax);
        pp right = rec(root->right, rightMin, rightMax);

        if (left.second && right.second && root->val > leftMax && root->val < rightMin) {
            mn = min(leftMin, (ll) root->val);
            mx = max(rightMax, (ll) root->val);

            return {1 + left.first + right.first, true};
        }

        mn = LLONG_MIN;
        mx = LLONG_MAX;

        return {max(left.first, right.first), false};
    }
public:
    int largestBSTSubtree(TreeNode* root) {
        ll mn, mx;
        pp res = rec(root, mn, mx);
        return res.first;
    }
};

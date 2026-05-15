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
    int recBalanced(TreeNode* root, bool&bal) {
        if(!root) {
            return 0;
        }

        int left = recBalanced(root->left, bal);
        int right = recBalanced(root->right, bal);

        cout << "left = " << left << " and right = " << right << endl;
        cout << "Balanced = " << bal << endl;
        
        if (abs(left - right) > 1) {
            bal = false;
        }

        return 1 + max(left, right);
    }
    
    bool isBalanced(TreeNode* root) {
        if (!root) {
            return true;
        }    

        bool res = true;
        recBalanced(root, res);
        return res;
    }
};

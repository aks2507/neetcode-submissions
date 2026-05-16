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
    void inorder(TreeNode* root, vector<int>& a) {
        if(!root) {
            return;
        }

        inorder(root->left, a);
        a.push_back(root->val);
        inorder(root->right, a);
    }

    void inorderInPlace(TreeNode* root, int& kth, int& count) {
        if (!root) return;

        inorderInPlace(root->left, kth, count);

        if (count == 0) {
            return;
        }
        count--;
        if (count == 0) {
            kth = root->val;
            return;
        }

        inorderInPlace(root->right, kth, count);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        // Inorder traversal storing values in array
        // vector<int> a;
        // inorder(root, a);
        // return a[k - 1];

        // Inplace inorder traversal
        int kth = -1;
        int count = k;
        inorderInPlace(root, kth, count);
        return kth;
    }
};

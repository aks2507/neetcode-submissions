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
    unordered_map<int, int> idxmap;
    int preidx = 0;

    TreeNode* recBuildTree(vector<int>& preorder, int left, int right) {
        if (left > right) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[preidx]);
        int inorder_idx = idxmap[preorder[preidx]];
        preidx++;

        root->left = recBuildTree(preorder, left, inorder_idx - 1);
        root->right = recBuildTree(preorder, inorder_idx + 1, right);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            idxmap[inorder[i]] = i;
        }

        return recBuildTree(preorder, 0, inorder.size() - 1);
    }
};

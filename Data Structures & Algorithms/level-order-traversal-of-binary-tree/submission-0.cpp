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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> bfs;
        if (root) bfs.push(root);
        while(!bfs.empty()) {
            vector<int> level;
            
            for(int i = bfs.size(); i > 0; i--) {
                TreeNode* t = bfs.front();
                bfs.pop();
                if (t) {
                    level.push_back(t->val);
                    bfs.push(t->left);
                    bfs.push(t->right);
                }
            }

            if(!level.empty()) {
                res.push_back(level);
            }
        }

        return res;
    }
};

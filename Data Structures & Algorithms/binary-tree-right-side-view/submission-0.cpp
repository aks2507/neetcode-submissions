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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> bfs;

        if (root) {
            bfs.push(root);
        }
        while(!bfs.empty()) {
            int qsize = bfs.size();

            for(int i = 0; i < qsize; i++) {
                TreeNode* t = bfs.front();
                bfs.pop();
                if(t) {
                    if (i == qsize - 1) {
                        res.push_back(t->val);
                    }
                    if(t->left) bfs.push(t->left);
                    if(t->right) bfs.push(t->right);
                } 
            }
        }

        return res;
    }
};

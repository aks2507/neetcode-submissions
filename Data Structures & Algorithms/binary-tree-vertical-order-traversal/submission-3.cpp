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
    map<int, vector<int>> levels;
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (!root) {
            return {};
        }
        vector<vector<int>> res;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty()) {
            auto [curr, level] = q.front();
            q.pop();
            levels[level].push_back(curr->val);
            
            if (curr->left) {
                q.push({curr->left, level - 1});
            }

            if (curr->right) {
                q.push({curr->right, level + 1});
            }
        }

        for (const auto& [k, v] : levels) {
            res.push_back(v);
        }
        return res;
    }
};
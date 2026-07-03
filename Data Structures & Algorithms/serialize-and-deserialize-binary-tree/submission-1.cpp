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

class Codec {
private:
    void dfsSerialize(TreeNode* root, vector<string>& vec) {
        if(!root) {
            vec.push_back("N");
            return;
        }

        vec.push_back(to_string(root->val));
        dfsSerialize(root->left, vec);
        dfsSerialize(root->right, vec);

        return;
    }

    TreeNode* dfsDeserialize(int& i, vector<string>& vec) {
        if (i >= vec.size() || vec[i] == "N") {
            i++;
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(vec[i]));
        i++;
        root->left = dfsDeserialize(i, vec);
        root->right = dfsDeserialize(i, vec);

        return root;
    }

    vector<string> split(const string &s, char delim) {
        vector<string> elems;
        stringstream ss(s);
        string item;
        while (getline(ss, item, delim)) {
            elems.push_back(item);
        }
        return elems;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<string> vec;
        dfsSerialize(root, vec);
        string res = "";
        for(string c : vec) {
            res = res + c + ',';
        }

        // cout<<res<<endl;
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i = 0;
        vector<string> vec = split(data, ',');
        TreeNode* root = dfsDeserialize(i, vec);

        return root;
    }
};

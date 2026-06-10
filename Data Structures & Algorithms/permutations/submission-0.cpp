class Solution {
public:
    void rec(vector<int>& nums, vector<vector<int>>& res, vector<bool>& seen, vector<int>& perm) {
        if(perm.size() == nums.size()) {
            res.push_back(perm);
            return;
        }

        for(int i = 0; i < nums.size(); i++) {
            if(seen[i]) {
                continue;
            } else {
                perm.push_back(nums[i]);
                seen[i] = true;
                rec(nums, res, seen, perm);
                perm.pop_back();
                seen[i] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res; 
        vector<bool> seen(nums.size(), false); 
        vector<int> perm;

        rec(nums, res, seen, perm);

        return res;
    }
};

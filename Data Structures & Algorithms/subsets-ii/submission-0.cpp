class Solution {
public:
    void rec(int idx, vector<vector<int>>& res, vector<int>& subset, vector<int>& nums) {
        int n = nums.size();
        if(idx == n) {
            res.push_back(subset);
            return;
        }
        
        subset.push_back(nums[idx]);
        rec(idx + 1, res, subset, nums);
        subset.pop_back();

        while (idx + 1 < n && nums[idx] == nums[idx + 1]) {
            idx++;
        }
        rec(idx + 1, res, subset, nums);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        vector<int> subset;

        rec(0, res, subset, nums);

        return res;
    }
};

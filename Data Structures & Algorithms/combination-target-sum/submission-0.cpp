class Solution {
public:
    void rec(int idx, vector<vector<int>>& res, vector<int>& sums, vector<int>& nums, int target) {
        int n = nums.size();
        if (target == 0) {
            res.push_back(sums);
            return;
        }

        if (target < 0 || idx >= n) {
            return;
        }

        // Include this number and move on
        if (nums[idx] <= target) {
            sums.push_back(nums[idx]);
            rec(idx, res, sums, nums, target - nums[idx]);
            sums.pop_back();
        }

        // Do not include this number
        rec(idx + 1, res, sums, nums, target);
    }
    
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res; 
        vector<int> sums;

        rec(0, res, sums, nums, target);

        return res;
    }
};

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

        sums.push_back(nums[idx]);
        rec(idx + 1, res, sums, nums, target - nums[idx]);
        sums.pop_back();

        while (idx + 1 < n && nums[idx] == nums[idx + 1]) {
            idx++;
        }
        rec(idx + 1, res, sums, nums, target);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res; 
        vector<int> sums;
        sort(candidates.begin(), candidates.end());

        rec(0, res, sums, candidates, target);

        return res;
    }
};

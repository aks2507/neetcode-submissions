class Solution {
public:
    int sum(vector<int>& nums, unordered_map<string, int>& dp, int idx, int curr, int target) {
        int n = nums.size();
        if (idx == n) {
            return curr == target ? 1 : 0;
        }

        string key = to_string(curr) + "," + to_string(idx);
        if (dp.find(key) != dp.end()) {
            return dp[key];
        }

        int res = sum(nums, dp, idx + 1, curr + nums[idx], target) + sum(nums, dp, idx + 1, curr - nums[idx], target);

        dp[key] = res;

        return dp[key];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        unordered_map<string, int> dp;

        return sum(nums, dp, 0, 0, target);
    }
};

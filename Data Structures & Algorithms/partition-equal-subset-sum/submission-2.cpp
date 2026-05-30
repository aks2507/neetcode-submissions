class Solution {
public:
    bool rec(vector<int>& nums, int s1, int tot, int idx, vector<vector<int>>& dp) {
        if (idx == nums.size() && s1 == tot / 2) {
            return true;
        } 

        if (idx >= nums.size()) {
            return false;
        }

        if (dp[idx][s1] != -1) {
            return dp[idx][s1];
        }

        // cout << "s1 = " << s1 << " & s2 = " << s2 << endl;
        bool res = false;
        res = res || rec(nums, s1 + nums[idx], tot, idx + 1, dp) || rec(nums, s1, tot, idx + 1, dp);
        dp[idx][s1] = res;

        return dp[idx][s1];
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int s = 0;
        for(int i = 0; i < n; i++) {
            s += nums[i];
        }
        if (s % 2 != 0) {
            return false;
        }
        vector<vector<int>> dp(n ,vector<int>(s + 1, -1));
        bool res = rec(nums, 0, s, 0, dp);
        return res;
    }
};

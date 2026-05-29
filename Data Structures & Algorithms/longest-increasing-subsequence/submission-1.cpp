class Solution {
public:
    // int rec(vector<int>& nums, vector<int>& dp, int i, int prev) {
    //     int n = nums.size();

    //     if (i == n) {
    //         return 0;
    //     }
        
        
    //     int skip = rec(nums, dp, i + 1, prev);
    //     int include = INT_MIN;
    //     if(prev == -1 || nums[i] > nums[prev]) {
    //         include = 1 + rec(nums, dp, i + 1, i);
    //     }

    //     int res = max(skip, include);

    //     return res;
    // }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, 1);
        int res = 1;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }

            res = max(res, dp[i]);
        }

        return res;
    }
};

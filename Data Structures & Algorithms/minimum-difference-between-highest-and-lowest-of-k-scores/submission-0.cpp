class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l = 0, r = k - 1, n = nums.size();
        int minDiff = INT_MAX;
        while (r < n) {
            int diff = nums[r] - nums[l];
            minDiff = min(minDiff, diff);
            r++;
            l++;
        }

        return minDiff;
    }
};
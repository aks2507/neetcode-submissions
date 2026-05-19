class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int res = nums[0];

        int currMax = 1, currMin = 1;

        for (int i = 0; i < n; i++) {
            int tmp = currMax * nums[i];

            currMax = max(nums[i], max(nums[i] * currMax, nums[i] * currMin));
            currMin = min(nums[i], min(tmp, nums[i] * currMin));
            res = max(res, currMax);
        }

        return res;
    }
};

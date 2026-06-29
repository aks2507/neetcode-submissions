class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr = 0, maxSubSum = nums[0];
        
        for(auto& n: nums) {
            if (curr < 0) {
                curr = 0;
            }

            curr += n;
            maxSubSum = max(maxSubSum, curr);
        }

        return maxSubSum;
    }
};

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), i = 0, j = 0;
        int maxLen = INT_MAX, sum = 0;
        while(j < n) {
            sum += nums[j];

            while (sum >= target) {
                maxLen = min(maxLen, j - i + 1);
                sum -= nums[i++];
            }

            j++;
        }

        return maxLen == INT_MAX ? 0 : maxLen;
    }
};
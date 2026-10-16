class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int count = 1, maxIncCount = INT_MIN, maxDecCount = INT_MIN;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                count++;
            } else {
                maxIncCount = max(maxIncCount, count);
                count = 1;
            }
        }
        maxIncCount = max(maxIncCount, count);
        // cout << maxIncCount << endl;
        count = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1]) {
                count++;
            } else {
                maxDecCount = max(maxDecCount, count);
                count = 1;
            }
        }
        maxDecCount = max(maxDecCount, count);
        // cout << maxDecCount << endl;

        return max(maxDecCount, maxIncCount);
    }
};
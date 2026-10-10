class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int l = 0, r = 0, n = nums.size();
        int sum = 0, maxSum = INT_MIN;
        while (r < n) {
            if (r + 1 < n && nums[r] < nums[r + 1]) {
                sum += nums[r];
            } else {
                sum += nums[r];
                maxSum = max(maxSum, sum);
                sum = 0;
            }
            // cout << r << " -> " << sum << endl;
            r++;
        }

        return maxSum;
    }
};
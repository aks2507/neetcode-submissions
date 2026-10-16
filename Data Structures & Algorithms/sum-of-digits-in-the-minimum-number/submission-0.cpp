class Solution {
public:
    int sumOfDigits(vector<int>& nums) {
        int n = nums.size(), minm = INT_MAX;

        for (int i = 0; i < n; i++) {
            minm = min(minm, nums[i]);
        }
        
        int sum = 0;
        while (minm) {
            sum += minm % 10;
            minm /= 10;
        }

        return sum % 2 == 0;
    }
};
